#pragma once

#include "Core.h"
#include "Events/Event.h"

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
