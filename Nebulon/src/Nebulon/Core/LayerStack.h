#pragma once
#include "Core.h"
#include "Layer.h"

#include <vector>

namespace Nebulon
{
	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void AddLayer(Layer* layer);
		void AddOverlay(Layer* overlay);
		void RemoveLayer(Layer* layer);
		void RemoveOverlay(Layer* overlay);

		std::vector<Layer*> GetLayers() const { return m_Layers; }
	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}
