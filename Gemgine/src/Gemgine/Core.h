#pragma once

//Macro
#ifdef GG_PLATFORM_WINDOWS
	#ifdef GG_BUILD_DLL
		#define GEMGINE_API __declspec(dllexport)
	#else
		#define GEMGINE_API __declspec(dllimport)
	#endif
#else
	#error Gemgine only supports Windows!
#endif

#ifdef GG_ENABLE_ASSERTS
	#define GG_ASSERT(x, ...) {if(!(x)) {GG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debubreak(); }}
	#define GG_CORE_ASSERT(x, ...) {if(!(x)) {GG_CORE_ERROR("Assertion Failed: {0}", __VA_ARG__); __debugbreak(); } }
#else
	#define GG_ASSERT(x, ...)
	#define GG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)