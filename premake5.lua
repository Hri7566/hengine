-- premake5 build file
-- https://premake.github.io/

---@diagnostic disable
-- stylua: ignore start

require "premake-ninja.ninja"

workspace "Hengine"
	configurations { "Debug", "Release" }
	platforms { "Linux", "Win64" }

	project "Hengine"
		kind "StaticLib"
		language "C++"
		targetdir "bin/hengine%{cfg.buildcfg}"
		links { "raylib" }

		files { "src/hengine/**.hpp", "src/hengine/**.cpp" }

		filter "platforms:Linux"
			system "Linux"
			architecture "x86_64"

		filter "platforms:Win64"
			system "Windows"
			architecture "x86_64"

		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"

		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"

	project "HengineTest"
		kind "ConsoleApp"
		language "C++"
		targetdir "bin/test/%{cfg.buildcfg}"
		links { "Hengine", "raylib" }

		files { "src/hengine/**.hpp", "src/test/**.hpp", "src/test/**.cpp" }

		filter "platforms:Linux"
			system "Linux"
			architecture "x86_64"

		filter "platforms:Win64"
			system "Windows"
			architecture "x86_64"

		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"

		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"

-- stylua: ignore end
