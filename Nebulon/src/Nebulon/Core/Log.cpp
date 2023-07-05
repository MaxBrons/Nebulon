#include "nblpch.h"
#include "Log.h"
#include "Core.h"

namespace Nebulon
{
	s_ptr<Logger> Log::s_CoreLogger = MakeShared<Logger>("Nebulon");
	s_ptr<Logger> Log::s_ClientLogger = MakeShared<Logger>("Client");
}