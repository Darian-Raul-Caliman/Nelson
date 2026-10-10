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

#ifdef NS_ENABLE_ASSERTS
	#define NS_ASSERT(x, ...) { if(!(x)) { NS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NS_CORE_ASSERT(x, ...) { if(!(x)) { NS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NS_ASSERT(x, ...)
	#define NS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)