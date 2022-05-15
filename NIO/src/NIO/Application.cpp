#include "hcpch.h"
#include "Application.h"


#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace NIO 
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 820);
		NIO_TRACE(e);
		while (true);
	}
}

