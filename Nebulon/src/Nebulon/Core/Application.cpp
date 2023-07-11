#include "nblpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Nebulon
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name, unsigned int width, unsigned int height)
	{
		NBL_CORE_ASSERT(!s_Instance, "Application already exists, there can only be one.");
		s_Instance = this;

		m_Window = Window::Create(WindowProperties(name, width, height));
	}

	Application::~Application()
	{
		for (Layer* layer : m_LayerStack.GetLayers())
		{
			layer->OnDestroy();
			delete layer;
		}
	}

	void Application::OnEvent(const Event& event)
	{
		NBL_CORE_WARN("Application::OnEvent: method not yet implemented");
	}

	void Application::Shutdown()
	{
		m_Running = false;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float elapsedTime = glfwGetTime();
			float deltaTime = elapsedTime - m_LastFrameTime;
			m_LastFrameTime = elapsedTime;

			for (Layer* layer : m_LayerStack.GetLayers())
			{
				layer->OnUpdate(deltaTime);
			}

			m_Window->OnUpdate();
		}
	}

}