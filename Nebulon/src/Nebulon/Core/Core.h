#pragma once

#include <memory>

#ifdef NBL_DEBUG
	#ifdef NBL_PLATFORM_WINDOWS
		#define NBL_DEBUGBREAK() __debugbreak()
	#else
		#error "Platform doesn't support debugbreak yet."
	#endif
#else
	#define NBL_DEBUGBREAK()
#endif

namespace Nebulon
{
	template<typename T>
	using u_ptr = std::unique_ptr<T>;
	template<typename T, typename... Args>
	constexpr u_ptr<T> MakeUnique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using s_ptr = std::shared_ptr<T>;
	template<typename T, typename... Args>
	constexpr s_ptr<T> MakeShared(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}