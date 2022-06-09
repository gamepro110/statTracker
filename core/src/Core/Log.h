#pragma once

#include "base.h"

// this ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

#include <memory>

namespace StatTracker::Core {
	class Log {
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define STATS_Core_TRACE(...)		::StatTracker::Core::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define STATS_Core_INFO(...)		::StatTracker::Core::Log::GetCoreLogger()->info(__VA_ARGS__)
#define STATS_Core_WARN(...)		::StatTracker::Core::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define STATS_Core_ERROR(...)		::StatTracker::Core::Log::GetCoreLogger()->error(__VA_ARGS__)
#define STATS_Core_CRITICAL(...)	::StatTracker::Core::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define STATS_TRACE(...)			::StatTracker::Core::Log::GetClientLogger()->trace(__VA_ARGS__)
#define STATS_INFO(...)				::StatTracker::Core::Log::GetClientLogger()->info(__VA_ARGS__)
#define STATS_WARN(...)				::StatTracker::Core::Log::GetClientLogger()->warn(__VA_ARGS__)
#define STATS_ERROR(...)			::StatTracker::Core::Log::GetClientLogger()->error(__VA_ARGS__)
#define STATS_CRITICAL(...)			::StatTracker::Core::Log::GetClientLogger()->critical(__VA_ARGS__)
