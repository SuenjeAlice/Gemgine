#include "ggpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Gemgine {

	//Client and CoreLogger
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	//Initialises Log
	void Log::Init()
	{
		//Set pattern, color and level for Core and Client Logger
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("GEMGINE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
