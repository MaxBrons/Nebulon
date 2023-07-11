#pragma once
#include "Core.h"

#include <string>

namespace Nebulon
{
	struct WindowProperties
	{
	public:
		std::string Title;
		uint32_t Width, Height;
		bool VSync;

		WindowProperties(const std::string& title = "Nebulon", uint32_t width = 960, uint32_t height = 720, bool vsync = false)
			: Title(title), Width(width), Height(height), VSync(vsync)
		{
		}
	};

	class Window
	{
	public:
		Window() = default;
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		inline virtual uint32_t GetWidth() const = 0;
		inline virtual uint32_t GetHeight() const = 0;

		inline virtual bool GetVSync() const = 0;
		inline virtual void SetVSync(bool enabled) = 0;

		inline virtual void* GetNativeWindow() const = 0;
	public:
		static u_ptr<Window> Create(const WindowProperties& properties = WindowProperties());
	};
}
