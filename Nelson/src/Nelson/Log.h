#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Nelson {

	class NS_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

#define NS_CORE_TRACE(...) ::Nelson::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NS_CORE_INFO(...)  ::Nelson::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NS_CORE_WARN(...)  ::Nelson::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NS_CORE_ERROR(...) ::Nelson::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NS_CORE_FATAL(...) ::Nelson::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define NS_TRACE(...)      ::Nelson::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NS_INFO(...)       ::Nelson::Log::GetClientLogger()->info(__VA_ARGS__)
#define NS_WARN(...)       ::Nelson::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NS_ERROR(...)      ::Nelson::Log::GetClientLogger()->error(__VA_ARGS__)
#define NS_FATAL(...)      ::Nelson::Log::GetClientLogger()->fatal(__VA_ARGS__)
