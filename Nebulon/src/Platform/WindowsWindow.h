#pragma once
#include "Nebulon/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Nebulon
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties = WindowProperties());
		~WindowsWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Properties.Width; }
		inline uint32_t GetHeight() const override { return m_Properties.Height; }

		inline bool GetVSync() const override;
		inline void SetVSync(bool enabled) override;

		inline void* GetNativeWindow() const override { return m_NativeWindow; }
	private:
		void Init(const WindowProperties& properties);
		void Shutdown();
	private:
		GLFWwindow* m_NativeWindow = nullptr;
		WindowProperties m_Properties;
	};
}
