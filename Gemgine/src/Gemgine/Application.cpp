#include "ggpch.h"
#include "Application.h"

#include "Gemgine/Events/ApplicationEvent.h"
#include "Gemgine/Log.h"

namespace Gemgine {
	
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		GG_TRACE(e);

		while (true);
	}
}
