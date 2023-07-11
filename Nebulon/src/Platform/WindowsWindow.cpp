#include "nblpch.h"
#include "WindowsWindow.h"

#include <glad/glad.h>

namespace Nebulon
{
	WindowsWindow::WindowsWindow(const WindowProperties& properties)
		: m_Properties(properties)
	{
		Init(properties);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
	}

	void WindowsWindow::Init(const WindowProperties& properties)
	{
		m_Properties = properties;

		int succes = glfwInit();
		NBL_CORE_ASSERT(succes, "GLFW could not be initialized.");

		m_NativeWindow = glfwCreateWindow((int)m_Properties.Width, (int)m_Properties.Height, m_Properties.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_NativeWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		NBL_CORE_ASSERT(status, "GLAD could not be initialized.");

		SetVSync(properties.VSync);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_NativeWindow);
	}

	bool WindowsWindow::GetVSync() const
	{
		return m_Properties.VSync;
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		m_Properties.VSync = enabled;
		glfwSwapInterval(enabled ? 1 : 0);
	}
}