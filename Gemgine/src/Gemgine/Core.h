#pragma once

//Macro to check platform -> if windows define dllexport or dllimport, if not windows throw an error
#ifdef GG_PLATFORM_WINDOWS
	#ifdef GG_BUILD_DLL
		#define GEMGINE_API __declspec(dllexport)
	#else
		#define GEMGINE_API __declspec(dllimport)
	#endif
#else
	#error Gemgine only supports Windows!
#endif

//Macro to define asserts - checks if x is true or false, if false an error is thrown
#ifdef GG_ENABLE_ASSERTS
	#define GG_ASSERT(x, ...) {if(!(x)) {GG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debubreak(); }}
	#define GG_CORE_ASSERT(x, ...) {if(!(x)) {GG_CORE_ERROR("Assertion Failed: {0}", __VA_ARG__); __debugbreak(); } }
#else
	#define GG_ASSERT(x, ...)
	#define GG_CORE_ASSERT(x, ...)
#endif

//Macro to define BIT
#define BIT(x) (1 << x)