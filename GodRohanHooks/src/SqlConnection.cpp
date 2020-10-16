#include "stdafx.h"
#include "SqlConnection.h"
#include <chrono>
#include <thread>
wchar_t * SqlConnection::connString;
void SqlConnection::ReadySQLConnect()
{
	if (!Connect())
	{
		std::cout << "Can't read db connection string, exiting in 5 seconds." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		exit(0);
	}
}
std::wstring  SqlConnection::readRegistryKey(wchar_t* szValueName, wchar_t* SubKeyName)
{
	wchar_t buffer[MAX_PATH];
	//wchar_t* szValueName;
	//wchar_t* SubKeyName;
	wchar_t* connectionString;
	HKEY hKey;
	DWORD dwBufLen;
	LONG lret;

	HRESULT hr = E_FAIL;
	DWORD* reservedNULL = NULL;
	DWORD reservedZero = 0;

	//zValueName = L"GameDB";
	//SubKeyName = L"SOFTWARE\\Wow6432Node\\Geomind\\Gamenet\\Db";
	lret = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		SubKeyName,
		reservedZero,
		KEY_READ,
		&hKey);
	if (lret == ERROR_SUCCESS)
	{
		dwBufLen = MAX_PATH;
		lret = RegQueryValueEx(hKey,
			szValueName,
			reservedNULL,
			NULL,
			(BYTE*)buffer,
			&dwBufLen);
		if (lret == ERROR_SUCCESS)
		{
			connectionString = buffer;
			hr = S_OK;
		}
		RegCloseKey(hKey);
	}
	std::wstring _wstring(buffer);
	return _wstring;
}
void print_error(unsigned int handletype, const SQLHANDLE& handle) {
	SQLWCHAR sqlstate[1024];
	SQLWCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
	{
		std::cout << "Message: " << message << "\nSQLSTATE: " << sqlstate << std::endl;
	}
}
void checkError(SQLHANDLE m_hStmt, SQLRETURN retcode)
{
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
	{
		SQLCHAR       SqlState[6], SQLStmt[100], Msg[SQL_MAX_MESSAGE_LENGTH];
		SQLINTEGER    NativeError;
		SQLSMALLINT   i, MsgLen;
		SQLRETURN     rc1, rc2;

		i = 1;
		while ((rc2 = SQLGetDiagRecA(SQL_HANDLE_STMT, m_hStmt, i, SqlState, &NativeError,
			Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA) {
			std::string s((char*)&Msg, MsgLen);
			std::cout << "RESULT: " << (int)retcode << "SQLSTATE:" << s.c_str() << std::endl;
			i++;
		}

	}
}
SqlConnection::SqlConnection()
{
	this->m_ColCount = -1;
	this->m_hConnection = NULL;
	this->m_hEnviroment = NULL;
	this->m_hStmt = NULL;

	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &this->m_hEnviroment);
	SQLSetEnvAttr(this->m_hEnviroment, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_NTS);
}
void SqlConnection::Disconnect()
{
	if (this->m_hStmt)
		SQLFreeHandle(SQL_HANDLE_STMT, this->m_hStmt);

	if (this->m_hConnection)
		SQLDisconnect(this->m_hConnection);

	if (this->m_hConnection)
		SQLFreeHandle(SQL_HANDLE_DBC, this->m_hConnection);

	this->m_hStmt = NULL;
	this->m_hConnection = NULL;
}
SqlConnection::~SqlConnection()
{
	if (this->m_hStmt != SQL_NULL_HANDLE)
		SQLFreeHandle(SQL_HANDLE_STMT, this->m_hStmt);

	if (this->m_hConnection != SQL_NULL_HANDLE)
		SQLFreeHandle(SQL_HANDLE_DBC, this->m_hConnection);

	if (this->m_hEnviroment != SQL_NULL_HANDLE)
		SQLFreeHandle(SQL_HANDLE_ENV, this->m_hEnviroment);
}


wchar_t * readRegistryKey2()
{
	wchar_t buffer[MAX_PATH];
	wchar_t* szValueName;
	wchar_t* SubKeyName;
	wchar_t* connectionString = new wchar_t;
	HKEY hKey;
	DWORD dwBufLen;
	LONG lret;

	HRESULT hr = E_FAIL;
	DWORD* reservedNULL = NULL;
	DWORD reservedZero = 0;

	szValueName = L"LoginDB";
	SubKeyName = L"SOFTWARE\\Wow6432Node\\Geomind\\Gamenet\\Db";
	lret = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		SubKeyName,
		reservedZero,
		KEY_READ,
		&hKey);
	if (lret == ERROR_SUCCESS)
	{
		dwBufLen = MAX_PATH;
		lret = RegQueryValueEx(hKey,
			szValueName,
			reservedNULL,
			NULL,
			(BYTE*)buffer,
			&dwBufLen);
		if (lret == ERROR_SUCCESS)
		{
			connectionString = buffer;
			hr = S_OK;
		}
		RegCloseKey(hKey);
	}
	return connectionString;
}
bool SqlConnection::Connect()
{
	SQLHANDLE rgbValue;
	SQLAllocHandle(SQL_HANDLE_DBC, this->m_hEnviroment, &this->m_hConnection);
	SQLSetConnectAttr(this->m_hConnection, SQL_LOGIN_TIMEOUT, &rgbValue, 0);

	SQLRETURN Result = SQLDriverConnectW(this->m_hConnection, NULL, readRegistryKey2(), SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);

	if (Result != SQL_SUCCESS && Result != SQL_SUCCESS_WITH_INFO)
	{
		SQLSMALLINT sRecord = 1, MsgLen;
		SQLWCHAR SqlState[6], SQLMsgError[SQL_MAX_MESSAGE_LENGTH];
		SQLINTEGER NativeError;

		if (SQLGetDiagRec(SQL_HANDLE_DBC, this->m_hConnection, sRecord, SqlState, &NativeError, SQLMsgError, sizeof(SQLMsgError), &MsgLen) != SQL_NO_DATA)
		{
			std::wstring s(SQLMsgError, strlen((const char*)SQLMsgError));
			std::wcout << "RESULT: " << (int)Result << "SQLSTATE:" << SqlState << std::endl;
		}
		return FALSE;
	}
	Result = SQLAllocHandle(SQL_HANDLE_STMT, this->m_hConnection, &this->m_hStmt);

	if (Result != SQL_SUCCESS && Result != SQL_SUCCESS_WITH_INFO)
		return FALSE;

	std::cout << "[SQL] Connected successfully" << std::endl;
	return TRUE;
}
void SqlConnection::Close()
{
	SQLCloseCursor(this->m_hStmt);
	SQLFreeStmt(this->m_hStmt, 2);
}
/*
std::vector<int> SqlConnection::GetVipUserList2()
{
	SDWORD cbData;
	SQLRETURN retcode;
	SQLRETURN rc;
	std::vector<int> vecIds;


	rc = SQLAllocStmt(this->m_hConnection, &this->m_hStmt);

	SQLCHAR * strCallSP = (SQLCHAR*) "SELECT user_id FROM TUser WHERE donation = 3 or grade = 250";
	retcode = SQLExecDirectA(this->m_hStmt, strCallSP, SQL_NTS);
	std::cout << retcode << std::endl;
	for (rc = SQLFetch(this->m_hStmt); rc == SQL_SUCCESS; rc = SQLFetch(this->m_hStmt))
	{
		int id;
		SQLGetData(this->m_hStmt, 0, SQL_C_LONG, &id, 4, &cbData);
		std::cout << id << std::endl;
		vecIds.push_back(id);
	}
	this->Close();
	return vecIds;
}*/
std::vector<int> SqlConnection::GetVipUserList()
{
	SDWORD cbData;
	SQLRETURN retcode;
	SQLRETURN rc;
	std::vector<int> vecIds;


	rc = SQLAllocStmt(this->m_hConnection, &this->m_hStmt);
	int returnFromDb;
	// Bind the output parameter to variable RetParam.
	retcode = SQLBindParameter(m_hStmt, 1, SQL_PARAM_OUTPUT, SQL_C_SSHORT,
		SQL_INTEGER, 0, 0, &returnFromDb, 0, 0);



	SQLCHAR * strCallSP = (SQLCHAR *)"{? = CALL [dbo].[ROHAN_GetVipUsersList]}";
	SQLExecDirectA(this->m_hStmt, strCallSP, SQL_NTS);
	for (rc = SQLFetch(this->m_hStmt); rc == SQL_SUCCESS; rc = SQLFetch(this->m_hStmt))
	{
		int title;
		SQLGetData(this->m_hStmt, 1, SQL_C_LONG, &title, 4, &cbData);
		vecIds.push_back(title);
	}
	this->Close();
	return vecIds;
}


void  SqlConnection::Drop()
{
	SDWORD cbData;
	SQLRETURN retcode;
	SQLLEN cbRetParam = SQL_NTS, cbOutParam = SQL_NTS;

	SQLCHAR * strCallSP = (SQLCHAR *)"{11RohanGame}";
	SQLCHAR * strCallSP2 = (SQLCHAR *)"{11RohanUser}";
	retcode = SQLAllocStmt(this->m_hConnection, &this->m_hStmt);



	// Allocate a statement handle
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, m_hConnection, &m_hStmt);



	retcode = SQLPrepareA(m_hStmt, strCallSP, SQL_NTS);

	retcode = SQLExecute(this->m_hStmt);
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
	{
		SQLCHAR       SqlState[6], SQLStmt[100], Msg[SQL_MAX_MESSAGE_LENGTH];
		SQLINTEGER    NativeError;
		SQLSMALLINT   i, MsgLen;
		SQLRETURN     rc1, rc2;

		i = 1;
		while ((rc2 = SQLGetDiagRecA(SQL_HANDLE_STMT, m_hStmt, i, SqlState, &NativeError,
			Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA) {
			std::string s((char*)&Msg, MsgLen);
			std::cout << "RESULT: " << (int)retcode << "SQLSTATE:" << s.c_str() << std::endl;
			i++;
		}

	}
	retcode = SQLPrepareA(m_hStmt, strCallSP2, SQL_NTS);

	retcode = SQLExecute(this->m_hStmt);
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
	{
		SQLCHAR       SqlState[6], SQLStmt[100], Msg[SQL_MAX_MESSAGE_LENGTH];
		SQLINTEGER    NativeError;
		SQLSMALLINT   i, MsgLen;
		SQLRETURN     rc1, rc2;

		i = 1;
		while ((rc2 = SQLGetDiagRecA(SQL_HANDLE_STMT, m_hStmt, i, SqlState, &NativeError,
			Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA) {
			std::string s((char*)&Msg, MsgLen);
			std::cout << "RESULT: " << (int)retcode << "SQLSTATE:" << s.c_str() << std::endl;
			i++;
		}

	}
	this->Close();


}