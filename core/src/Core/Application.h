#pragma once

#include "Layer.h"
#include "App.h"

#include "imgui.h"
#include "vulkan/vulkan.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>

void check_vk_result(VkResult err);
struct GLFWwindow;

namespace StatTracker::Core {
	struct AppSpecs {
		std::string Name = "...";
		uint32_t Width = 1600;
		uint32_t Height = 900;
	};

	class Application : public App {
	public:
		Application(const AppSpecs& specs = AppSpecs());
		~Application();

	public:
		void Run() override;

		void SetMenubarCallback(const std::function<void()>& menubarCallback) {
			m_menubarCallback = menubarCallback;
		}
		
		void Close();

#if defined(STATS_WINDOWS) || defined(STATS_LINUX)
		static VkInstance GetInstance();
		static VkPhysicalDevice GetPhysicalDevice();
		static VkDevice GetDevice();

		static VkCommandBuffer GetCommandBuffer(bool begin);
		static void FlushCommandBuffer(VkCommandBuffer commandBuffer);
#elif defined(STATS_MACOS)
#endif

	private:
		void Init();
		void Shutdown();

	private:
		AppSpecs appSpecs;
		GLFWwindow* m_windowHandle = nullptr;
		std::function<void()> m_menubarCallback;
		bool isAppRunning = true;

	};

	App* CreateApp(int argc, char** argv);
}
