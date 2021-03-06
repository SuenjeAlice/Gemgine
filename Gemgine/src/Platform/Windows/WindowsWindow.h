#pragma once

#include "Gemgine/Window.h"

#include <GLFW/glfw3.h>

namespace Gemgine {

	//WindowsWindow inherits from Window
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		
		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	
		GLFWwindow* m_Window;
		
		//WindowData struct for Title, Width, Height, VSync & EventCallbackFn
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}