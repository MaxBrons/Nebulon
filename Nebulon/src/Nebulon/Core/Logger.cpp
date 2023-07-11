#include "nblpch.h"
#include "Logger.h"

namespace Nebulon
{
	void Logger::SetColor(int textColor)
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
}