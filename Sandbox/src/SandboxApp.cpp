#include <Gemgine.h>

class Sandbox : public Gemgine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Gemgine::Application* Gemgine::CreateApplication()
{
	return new Sandbox();
}