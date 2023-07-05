#pragma once
#include <iostream>
#include <string>
#include <wtypes.h>

namespace Nebulon
{
	enum Colors
	{
		green = 2,     //  2 = dark green textColor code
		red = 4,       //  4 = dark red textColor code
		yellow = 6,    //  6 = dark yellow textColor code
		default = 15   // 15 = white textColor code
	};

	class Logger
	{
	public:
		Logger(const std::string& origin)
			:m_Origin(origin)
		{
		}
		~Logger() = default;

		template<typename... Args>
		void Trace(const std::string& format, Args&&...args)
		{
			Log(Colors::default, m_Origin, format, args...);
		}

		template<typename... Args>
		void Info(const std::string& format, Args&&...args)
		{
			Log(Colors::green, m_Origin, format, args...);
		}

		template<typename... Args>
		void Warn(const std::string& format, Args&&...args)
		{
			Log(Colors::yellow, m_Origin, format, args...);
		}

		template<typename... Args>
		void Error(const std::string& format, Args&&...args)
		{
			Log(Colors::red, m_Origin, format, args...);
		}
	private:
		template<typename T>
		auto convert(T&& t)
		{
			if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<T>>, std::string>::value)
			{
				return std::forward<T>(t).c_str();
			}
			else
			{
				return std::forward<T>(t);
			}
		}

		template<typename... Args>
		std::string fmt_str_int(const std::string& format, Args&&... args)
		{
			const int size = std::snprintf(nullptr, 0, format.c_str(), std::forward<Args>(args)...) + 1;
			const u_ptr<char[]> buffer = MakeUnique<char[]>(size);

			std::snprintf(buffer.get(), size, format.c_str(), std::forward<Args>(args)...);
			return std::string(buffer.get(), buffer.get() + size - 1);
		}

		template<typename... Args>
		std::string fmt_str(const std::string& format, Args&&... args)
		{
			return fmt_str_int(format, convert(std::forward<Args>(args))...);
		}

		void SetColor(int textColor)
		{
			WORD consoleColor;
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
			{
				consoleColor = (csbi.wAttributes & 0xF0) + (textColor & 0x0F);
				SetConsoleTextAttribute(hStdOut, consoleColor);
			}
		}
		template<typename... Args>
		void Log(const Colors& color, const std::string& origin, const std::string& format, const Args&&...args)
		{
			SetColor(color);
			std::string fmt_str_t = fmt_str(format, args...);
			std::cout << "[" + origin + "] " + fmt_str_t << std::endl;
			SetColor(Colors::default);
		}
	private:
		std::string m_Origin;
	};

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
