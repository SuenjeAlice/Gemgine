#pragma once

#ifdef GG_PLATFORM_WINDOWS

extern Gemgine::Application* Gemgine::CreateApplication();

int main(int argc, char** argv)
{
	//Log Init
	Gemgine::Log::Init();
	GG_CORE_WARN("Initialized Log!");
	int a = 5;
	GG_INFO("Hello! Var={0}", a);

	auto app = Gemgine::CreateApplication();
	app->Run();
	delete app;
}

#endif