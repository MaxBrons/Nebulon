#pragma once
#include "Logger.h"

namespace Nebulon
{
	class Log
	{
	public:
		static void Init();

		static s_ptr<Logger>& GetCoreLogger() { return s_CoreLogger; }
		static s_ptr<Logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static s_ptr<Logger> s_CoreLogger;
		static s_ptr<Logger> s_ClientLogger;
	};

	// Core log macros
#define NBL_CORE_TRACE(...) ::Nebulon::Log::GetCoreLogger()->Trace(__VA_ARGS__)
#define NBL_CORE_INFO(...)  ::Nebulon::Log::GetCoreLogger()->Info(__VA_ARGS__)
#define NBL_CORE_WARN(...)  ::Nebulon::Log::GetCoreLogger()->Warn(__VA_ARGS__)
#define NBL_CORE_ERROR(...) ::Nebulon::Log::GetCoreLogger()->Error(__VA_ARGS__)

	// Client log macros
#define NBL_TRACE(...) ::Nebulon::Log::GetClientLogger()->Trace(__VA_ARGS__)
#define NBL_INFO(...)  ::Nebulon::Log::GetClientLogger()->Info(__VA_ARGS__)
#define NBL_WARN(...)  ::Nebulon::Log::GetClientLogger()->Warn(__VA_ARGS__)
#define NBL_ERROR(...) ::Nebulon::Log::GetClientLogger()->Error(__VA_ARGS__)
}
