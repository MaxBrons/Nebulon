#include "nblpch.h"
#include "Window.h"

#ifdef NBL_PLATFORM_WINDOWS
	#include "Platform/WindowsWindow.h"
#else 
	#include "Log.h"
#endif

namespace Nebulon
{
	u_ptr<Window> Window::Create(const WindowProperties& properties)
	{
#ifdef NBL_PLATFORM_WINDOWS
		return MakeUnique<WindowsWindow>(properties);
#else
		Debug::Error("Other platform windows are not yet supported");
		return nullptr;
#endif
	}
}