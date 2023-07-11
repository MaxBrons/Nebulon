#include "nblpch.h"
#include "nblpch.h"
#include "LayerStack.h"

namespace Nebulon
{
	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			layer->OnDestroy();
			delete layer;
		}
	}

	void LayerStack::AddLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		layer->OnStart();
		m_LayerInsertIndex++;
	}

	void LayerStack::AddOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->OnStart();
	}

	void LayerStack::RemoveLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
		if (it != m_Layers.begin() + m_LayerInsertIndex)
		{
			layer->OnDestroy();
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::RemoveOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDestroy();
			m_Layers.erase(it);
		}
	}

}