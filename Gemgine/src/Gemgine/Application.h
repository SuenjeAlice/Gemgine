#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Gemgine/Events/ApplicationEvent.h"
#include "Window.h"

namespace Gemgine{

	class GEMGINE_API Application
	{
	public:
		Application();
		//Virtual Destructor because class gets inherited
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}