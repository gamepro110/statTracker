#pragma once

#include "App.h"

namespace StatTracker::Core {
	class ConsoleApp : public App {
	public:
		ConsoleApp() = default;

	public:
		void Run() override {
			while (IsRunning) {
				for (const auto& layer : layerStack) {
					layer->OnUpdate();
				}
			}
		}
	};
}
