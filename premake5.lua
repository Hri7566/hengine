-- premake5 build file
-- https://premake.github.io/

---@diagnostic disable
-- stylua: ignore start

workspace "Hello"
	configurations { "Debug", "Release" }

project "HelloWorld"
	require "premake-ninja.ninja"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"
	links { "raylib" }

	files { "src/**.hpp", "src/**.cpp" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

-- stylua: ignore end
