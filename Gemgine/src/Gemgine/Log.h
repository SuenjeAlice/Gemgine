#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Gemgine {

	class GEMGINE_API Log
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

//Core log macros
#define GG_CORE_TRACE(...)   ::Gemgine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GG_CORE_INFO(...)    ::Gemgine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GG_CORE_WARN(...)    ::Gemgine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GG_CORE_ERROR(...)   ::Gemgine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GG_CORE_FATAL(...)   ::Gemgine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define GG_TRACE(...)        ::Gemgine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GG_INFO(...)         ::Gemgine::Log::GetClientLogger()->info(__VA_ARGS__)
#define GG_WARN(...)         ::Gemgine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GG_ERROR(...)        ::Gemgine::Log::GetClientLogger()->error(__VA_ARGS__)
#define GG_FATAL(...)        ::Gemgine::Log::GetClientLogger()->fatal(__VA_ARGS__)