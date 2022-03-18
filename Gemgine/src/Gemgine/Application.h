#pragma once

#include "Core.h"

namespace Gemgine{

	class GEMGINE_API Application
	{
	public:
		Application();
		//Virtual Destructor because class gets inherited
		virtual ~Application();

		void Run();
	};

	//To be define in CLIENT
	Application* CreateApplication();

}