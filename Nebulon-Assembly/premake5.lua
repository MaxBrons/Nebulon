project "Nebulon-Assembly"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"../Nebulon/src",
		"../Nebulon/vendor",
		"../Nebulon/%{IncludeDir.glm}",
		"../Nebulon/%{IncludeDir.Glad}",
		"../Nebulon/%{IncludeDir.ImGui}"
	}

	links
	{
		"Nebulon"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "NBL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NBL_RELEASE"
		runtime "Release"
        optimize "on"
