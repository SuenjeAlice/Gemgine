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

#define BIT(x) (1 << x)