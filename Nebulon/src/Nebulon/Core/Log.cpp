#include "nblpch.h"
#include "Log.h"

namespace Nebulon
{
	s_ptr<Logger> Log::s_CoreLogger = MakeShared<Logger>("Nebulon");
	s_ptr<Logger> Log::s_ClientLogger = MakeShared<Logger>("Client");

	void Log::Init()
	{
		NBL_CORE_INFO("Log: Logger initialized.");
	}
}