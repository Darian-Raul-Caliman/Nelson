#pragma once

#ifdef NS_PLATFORM_WINDOWS
	#ifdef NS_BUILD_DLL
		#define NS_API __declspec(dllexport)
	#else
		#define NS_API __declspec(dllimport)
	#endif
#else
	#error Nelson Engine supports only Windows!
#endif