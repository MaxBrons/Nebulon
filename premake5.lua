-- Nebulon-Assembly
workspace "Nebulon-Assembly"
	architecture "x64"
	startproject "Nebulon-Assembly"

	configurations
	{
		"Debug",
		"Release",
        "Distribution"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to Nebulon
IncludeDir = {}
IncludeDir["GLFW"] = "vendor/glfw/include"
IncludeDir["Glad"] = "vendor/glad/include"
IncludeDir["ImGui"] = "vendor/imgui"
IncludeDir["glm"] = "vendor/glm"
IncludeDir["stb_image"] = "vendor/stb_image"

-- Projects
group "Dependencies"
	include "Nebulon/vendor/premake5_glfw.lua"
	include "Nebulon/vendor/premake5_glad.lua"
	include "Nebulon/vendor/premake5_imgui.lua"
group ""

include "Nebulon"
include "Nebulon-Assembly"