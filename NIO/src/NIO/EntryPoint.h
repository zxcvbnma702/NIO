#pragma once
#include "Application.h"

#ifdef NIO_PLATFORM_WINDOWS

extern NIO::Application* NIO::CreateApplication();

int main() {
	auto app = NIO::CreateApplication();
	app->Run();
	delete app;
}

#endif // NIO_PLATFORM_WINDOWS