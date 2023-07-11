#pragma once
#include "Window.h"
#include "Layer.h"
#include "LayerStack.h"
#include "../Event/Event.h"

#include <vector>

int main();

namespace Nebulon
{

	class Application
	{
	public:
		Application(const std::string& name = "New Application", unsigned int width = 720, unsigned int height = 360);
		virtual ~Application();

		void Shutdown();
		void OnEvent(const Event& event);

		void AddLayer(Layer* layer) { m_LayerStack.AddLayer(layer); }
		void RemoveLayer(Layer* layer) { m_LayerStack.RemoveLayer(layer); }
		void AddOverlay(Layer* layer) { m_LayerStack.AddOverlay(layer); }
		void RemoveOverlay(Layer* layer) { m_LayerStack.RemoveOverlay(layer); }

		inline Window& GetWindow() const { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		void Run();
	private:
		u_ptr<Window> m_Window = nullptr;
		LayerStack m_LayerStack;

		bool m_Running = true;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main();
	};
}
