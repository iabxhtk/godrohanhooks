workspace "GodRohanHooks"
			architecture "x86"

			configurations
			{
				"Debug",
				"Release"
			}

			outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


newaction {
	trigger     = "clean",
	description = "clean build files",
	execute     = function ()
	   print("cleaning the build...")
	   os.rmdir("./GodRohanHooks/bin")
	   os.rmdir("./GodRohanHooks/bin-int")
	   os.remove("./GodRohanHooks/GodRohanHooks.*")
	   os.remove("GodRohanHooks.sln")
	   print("done.")
	end
 }

include "GodRohanHooks"
