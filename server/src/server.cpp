#include "Core/ConsoleApp.h"
#include "Core/Log.h"
#include "Core/EntryPoint.h"

namespace StatTracker {
    class TerminalLayer;

    Core::App* CreateApp(int argc, char** argv) {
        STATS_INFO("Starting console app");

        Core::ConsoleApp* app = new Core::ConsoleApp();
        app->PushLayer<TerminalLayer>();

        return app;
    }


    class TerminalLayer : public Core::Layer {
    public:
        void OnAttach() override {
            STATS_INFO("Attach Terminal Layer");
        }

        void OnUpdate() override {
        }

        void OnDetach() override {
            STATS_INFO("Detach Terminal Layer");
        }
    };
}
