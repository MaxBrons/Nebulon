#pragma once
#include <stdio.h>
#include <wtypes.h>
#include <string>

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
			Log(Colors::default, format, args...);
		}

		template<typename... Args>
		void Info(const std::string& format, Args&&...args)
		{
			Log(Colors::green, format, args...);
		}

		template<typename... Args>
		void Warn(const std::string& format, Args&&...args)
		{
			Log(Colors::yellow, format, args...);
		}

		template<typename... Args>
		void Error(const std::string& format, Args&&...args)
		{
			Log(Colors::red, format, args...);
		}
	private:
		void SetColor(int textColor);


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

		template<typename... Args>
		void Log(const Colors& color, const std::string& format, Args&&...args)
		{
			SetColor(color);
			std::string formattedString = fmt_str(format, args...);
			std::cout << "[" + m_Origin + "] " + formattedString << std::endl;
			SetColor(Colors::default);
		}
	private:
		std::string m_Origin;
	};
}
