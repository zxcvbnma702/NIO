workspace "NIO"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "NIO"
	location "NIO"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hcpch.h"
	pchsource "NIO/src/hcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NIO_PLATFORM_WINDOWS",
			"NIO_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Box")
		}

	filter "configurations:Debug"
		defines "NIO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NIO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NIO_DIST"
		optimize "On"

project "Box"
	location "Box"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"NIO/vendor/spdlog/include",
		"NIO/src"
	}

	links
	{
		"NIO"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NIO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NIO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NIO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NIO_DIST"
		optimize "On"