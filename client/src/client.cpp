#include "Core/Application.h"
#include "Core/Log.h"
#include "Core/EntryPoint.h"

namespace StatTracker {
	class TEMPNAME;

	Core::App* CreateApp(int argc, char** argv) {
		Core::AppSpecs specs;
		specs.Name = "Tracking Display";

		STATS_INFO("Starting Application");

		Core::Application* app = new Core::Application(specs);
		app->PushLayer<TEMPNAME>();

		return app;
	}

	class TEMPNAME : public Core::Layer {
	public:
		void OnAttach() override {
			STATS_INFO("Attach TEMPNAME layer");
		}

		void OnUpdate() override {
		}

		void OnDetach() override {
			STATS_INFO("Detach TEMPNAME layer");
		}
	};
}
