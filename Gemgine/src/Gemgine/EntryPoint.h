#pragma once

#ifdef GG_PLATFORM_WINDOWS

extern Gemgine::Application* Gemgine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Gemgine::CreateApplication();
	app->Run();
	delete app;
}

#endif