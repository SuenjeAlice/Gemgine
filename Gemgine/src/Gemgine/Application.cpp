#include "ggpch.h"
#include "Application.h"


#include "Gemgine/Log.h"

#include <GLFW/glfw3.h>

namespace Gemgine {

//BIND_EVENT_FN Macro - binds a functions
#define  BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	Application::Application()
	{
		//Create Window and sets Event Callback
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	//OnEvent - dispatch events and trace them
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		GG_CORE_TRACE("{0}", e);
	}

	//Run function
	void Application::Run()
	{
		//while loop
		while (m_Running)
		{
			//Set Color to pink
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			m_Window->OnUpdate();
		}
	}

	//OnWindowClose, set m_Running to false (while loop is broken)
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}

