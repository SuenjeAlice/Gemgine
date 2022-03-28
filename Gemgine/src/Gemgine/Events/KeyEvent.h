#pragma once

#include "Event.h"

namespace Gemgine {

	//KeyEvent inherits Event
	class GEMGINE_API KeyEvent : public Event
	{
	public:
		//GetKeyCode function returns keycode
		inline int GetKeyCode() const { return m_KeyCode; }

		//assign event category (type is assigne in KeyPressedEvent/KeyReleasedEvent)
		EVENT_CLASS_CATEGORY(EventCatergoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	//KeyPressedEvent inherits KeyEvent
	class GEMGINE_API KeyPressedEvent : public KeyEvent
	{
	public: 
		KeyPressedEvent( int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		//repeat count (0 for no repeat, 1 for repeats)
		inline int GetRepeatCount() const { return m_RepeatCount; }

		//ToString function overrides ToString function in event and returns keycode and repeatcount
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		//assign type (category was assigned in KeyEvent)
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	//KeyReleasedEvent inherits from KeyEvent
	class GEMGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		//ToString function overrides ToString function in event and returns keycode
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		//assign type (category was assigned in KeyEvent)
		EVENT_CLASS_TYPE(KeyReleased)
	};
}