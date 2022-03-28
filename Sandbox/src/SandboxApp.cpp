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

//Creates Application
Gemgine::Application* Gemgine::CreateApplication()
{
	return new Sandbox();
}