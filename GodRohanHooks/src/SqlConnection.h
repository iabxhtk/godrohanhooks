#pragma once
#include <sqltypes.h>  
#include <sqlext.h> 
#include <sql.h>
class SqlConnection
{
protected:
	SQLHANDLE m_hEnviroment;
	SQLHANDLE m_hConnection;
	SQLHANDLE m_hStmt;
	std::string m_szHost;
	std::string m_szUser;
	std::string m_szPassword;
	SQLINTEGER m_RowCount;
	SQLSMALLINT m_ColCount;
	
public:
	static wchar_t * connString;
	SqlConnection();
	~SqlConnection();
	void Disconnect();
	void ReadySQLConnect();

	std::wstring readRegistryKey(wchar_t * szValueName, wchar_t * SubKeyName);

	
	bool Connect();
	
	void Close();

	std::vector<int> GetVipUserList();

	void Drop();


	BOOL ExecQuery(TCHAR* lpszStatement, ...);

	static std::string connectionString;

};

