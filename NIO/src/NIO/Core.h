#pragma once

//ͨ������ж�̬����

#ifdef NIO_PLATFORM_WINDOWS

	#ifdef NIO_BUILD_DLL
		#define NIO_API __declspec(dllexport)
	#else
		#define NIO_API __declspec(dllimport)
	#endif // DEBUG
#else
	#error NIO only support Windows!
#endif // NIO_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
