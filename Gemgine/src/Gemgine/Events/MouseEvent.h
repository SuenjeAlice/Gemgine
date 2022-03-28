#pragma once

#include "Event.h"

namespace Gemgine {
	
	//MouseMovedEvent inherits from Event
	class GEMGINE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		//get X and Y position of mouse
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		//ToString function overrides ToString function from Event and returns position of mouse
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		//assign type and category
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	//MouseScrolledEvent inherits from Event
	class GEMGINE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		//get X and Y offset
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		//ToString function overrides ToString function from Event and returns offset
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		//Assign type and category
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	//MouseButtonEvent inherits from Event
	class GEMGINE_API MouseButtonEvent : public Event
	{
	public:
		//Returns which button is used
		inline int GetMouseButton() const { return m_Button; }

		//Assign category (type is assigned in MouseButtonPressedEvent/MouseButtonReleasedEvent)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}
		int m_Button;
	};

	//MouseButtonPressedEvent inherits MouseButtonEvent
	class GEMGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		//ToString function overrides ToString function from Event and returns button pressed
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		//Asssign type (category was assigned in MouseButtonEvent)
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	//MouseButtonReleasedEvent inherits MouseButtonEvent
	class GEMGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}

		//ToString function overrides ToString function from Event and returns button released
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleaseEvent: " << m_Button;
			return ss.str();
		}
		//Assign type (category was assigned in MouseButtonEvent)
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}