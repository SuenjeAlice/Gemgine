#pragma once

#include "Event.h"

namespace Gemgine {

	//WindowResizeEvent inherits from Event
	class GEMGINE_API WindowResizeEvent : public Event
	{
	public: 
		//Constructor takes width and height of window
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		//GetWidth and GetHeight function to get width and height (unsigned int because width/height can't be negative)
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		//ToString function overrides the ToString function in Event and returns the name, width and height as a string
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		//Assign a type and category
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		//Membervariables for width and height
		unsigned int m_Width, m_Height;
	};

	//WindowCloseEvent inherits from Event
	class GEMGINE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		//Assign a type and category
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class GEMGINE_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int xPos, int yPos)
			: m_XPos(xPos), m_YPos(yPos) 
		{
		}

		//get X and Y position of mouse
		inline int GetX() const { return m_XPos; }
		inline int GetY() const { return m_XPos; }

		//ToString function overrides the ToString function in Event and returns the name and postion as a string
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: " << m_XPos << ", " << m_XPos;
			return ss.str();
		}

		//Assign a type and category
		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		int m_XPos, m_YPos;
	};

	class GEMGINE_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent(int focus)
			: m_Focus(focus)
		{
		}

		//get X and Y position of mouse
		inline int GetFocus() const { return m_Focus; }

		//ToString function overrides the ToString function in Event and returns the name and focus as a string
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowFocusEvent: " << m_Focus;
			return ss.str();
		}

		//Assign a type and category
		EVENT_CLASS_TYPE(WindowFocus)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		int m_Focus;
	};

	//AppTickEvent inherits from Event
	class GEMGINE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		//Assign a type and category
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	//AppUpdateEvent inherits from Event
	class GEMGINE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		//Assign a type and category
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	//AppRenderEvent inherits from Event
	class GEMGINE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		//Assign a type and category
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}