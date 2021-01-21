project "PhysicsEngine"
	kind "StaticLib"
	staticruntime "on"
	language "C++"
		cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"src/**.h",
		"src/**.cpp",
		"external/glm/glm/**.hpp",
		"external/glm/glm/**.inl"
	}

	includedirs {
		"src",
		"external/glm"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
