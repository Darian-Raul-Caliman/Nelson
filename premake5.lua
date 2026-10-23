workspace "Nelson"
	architecture "x64"
	toolset "v145"


	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Nelson/vendor/GLFW/include"
IncludeDir["Glad"] = "Nelson/vendor/Glad/include"
IncludeDir["imGui"] = "Nelson/vendor/imGui"
	startproject "Sandbox"

include "Nelson/vendor/GLFW"
include "Nelson/vendor/Glad"
include "Nelson/vendor/imGui"



project "Nelson"
	location "Nelson"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/Sandbox")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	pchheader "nspch.h"
	pchsource "Nelson/src/nspch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imGui}"
	}

	links {
		"GLFW",
		"Glad",
		"imGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines {
			"NS_PLATFORM_WINDOWS",
			"NS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	postbuildcommands {
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
	}

	filter "configurations:Debug"
		defines "NS_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "NS_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NS_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/Sandbox")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Nelson/vendor/spdlog/include",
		"Nelson/src"
	}

	links {
		"Nelson"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines {
			"NS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NS_DEBUG"
		buildoptions "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "NS_RELEASE"
		buildoptions "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "NS_DIST"
		buildoptions "Release"
		optimize "On"