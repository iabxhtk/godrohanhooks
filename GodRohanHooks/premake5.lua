
project "GodRohanHooks"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir_path = "%{wks.location}/bin/" .. outputdir .. "/%{prj.name}"
    targetname("Hero4")
    targetdir (targetdir_path)
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")


    pchheader "stdafx.h"
    pchsource "GodRohanHooks/src/stdafx.cpp"

    
    files
    {
        "src/**.h",
        "src/**.cpp",
        "vendor/hooks/**.h",
        "vendor/hooks/**.cpp",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "src",
        "vendor/**/include",
    }	 

    libdirs 
    { 
        "vendor/**/lib/",
    }

    links
    {
        "detours",
        "winmm",
        "libxl",
    }

    filter "system:windows"
            cppdialect "C++17"
            systemversion "latest"


    filter "configurations:Debug"
            runtime "Debug"
            symbols "Off"

    filter "configurations:Release"
            runtime "Release"
            optimize "On"

postbuildcommands
{
    "{COPY} ./GodRohanHooks/vendor/curl/dll/libcurl.dll %{cfg.buildtarget.directory}"
}