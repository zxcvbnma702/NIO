#pragma once

#include "Core.h"

namespace NIO {

	class NIO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
