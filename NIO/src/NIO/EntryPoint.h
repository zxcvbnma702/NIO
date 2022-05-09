#pragma once
#include "Application.h"

#ifdef NIO_PLATFORM_WINDOWS

extern NIO::Application* NIO::CreateApplication();

int main() {

	NIO::Log::Init();

	NIO_CORE_WARN("Initialized Log!");
	int a = 5;
	NIO_INFO("Hello! Var={0}", a);

	auto app = NIO::CreateApplication();
	app->Run();
	delete app;
}

#endif // NIO_PLATFORM_WINDOWS