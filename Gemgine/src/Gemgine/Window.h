#pragma once

#include "ggpch.h"

#include "Gemgine/Core.h"
#include "Gemgine/Events/Event.h"

namespace Gemgine {

	//WindowProps struct with Title, Width and Height as well as a default for title, width and height
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Gemgine Engine",
			unsigned int width = 1200,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

//Interface representing a desktop system based Window
class GEMGINE_API Window
{
public:
	using EventCallbackFn = std::function<void(Event&)>;

	virtual ~Window() {}

	//abstract class - pure virtual functions
	virtual void OnUpdate() = 0;
	
	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	//Window attributes
	virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
	virtual void SetVSync(bool enabled) = 0;
	virtual bool IsVSync() const = 0;
	
	//Create function 
	static Window* Create(const WindowProps& props = WindowProps());
};

}