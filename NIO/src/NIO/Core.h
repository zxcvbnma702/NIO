#pragma once

//通过宏进行动态配置

#ifdef NIO_PLATFORM_WINDOWS

	#ifdef NIO_BUILD_DLL
		#define NIO_API __declspec(dllexport)
	#else
		#define NIO_API __declspec(dllimport)
	#endif // DEBUG
#else
	#error NIO only support Windows!
#endif // NIO_PLATFORM_WINDOWS
