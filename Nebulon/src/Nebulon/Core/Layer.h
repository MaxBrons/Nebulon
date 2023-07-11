#pragma once
#include "../Event/Event.h"

#include <string>

namespace Nebulon
{
	class Layer
	{
	public:
		Layer(const std::string& name = "")
			: m_Name(name)
		{
		};
		virtual ~Layer() = default;

		virtual void OnStart() {}
		virtual void OnUpdate(float deltaTime) {}
		virtual void OnDestroy() {}
		virtual void OnEvent(Event& e) {}
		virtual void OnImGuiRender() {}

		const std::string& GetName() const { return m_Name; }

	private:
		std::string m_Name;
	};
}
