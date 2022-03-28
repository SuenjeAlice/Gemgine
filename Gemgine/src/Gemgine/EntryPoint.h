#pragma once

//Entry Point

//if windows platform
#ifdef GG_PLATFORM_WINDOWS

//external linkage 
extern Gemgine::Application* Gemgine::CreateApplication();

int main(int argc, char** argv)
{
	//Log Init
	Gemgine::Log::Init();
	//Log messages
	GG_CORE_WARN("Initialized Log!");
	int a = 5;
	GG_INFO("Hello! Var={0}", a);

	//creates, runs and deletes app
	auto app = Gemgine::CreateApplication();
	app->Run();
	delete app;
}

#endif