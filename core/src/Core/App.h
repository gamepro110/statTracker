#pragma once

#include "Layer.h"

#include <vector>
#include <memory>

namespace StatTracker::Core {
	class App {
	public:
		virtual void Run() = 0;

	public:
		template<typename T>
		void PushLayer() {
			static_assert(std::is_base_of<Layer, T>::value, "Pushed Type is not Subclass of StatTracker::Layer!!");
			layerStack.emplace_back(std::make_shared<T>())->OnAttach();
		}

		void PushLayer(const std::shared_ptr<Layer>& layer) {
			layerStack.emplace_back(layer);
			layer->OnAttach();
		}

	public:
		static bool IsRunning;

	protected:
		std::vector<std::shared_ptr<Layer>> layerStack;
	};
}