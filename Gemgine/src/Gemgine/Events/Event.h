#pragma once
#include "ggpch.h"
#include "Gemgine/Core.h"

namespace Gemgine {

	//Blocking Events -> event gets dispatched and dealt with immediately when it occurs
	//Buffer events might be better for the future

	//Describes Event types
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, 
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyReleased, 
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//categories to make filtering events possible
	//uses only enum instead of enum class because BIT function doesn't work with enum class
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput          = BIT(1),
		EventCatergoryKeyboard      = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)

	};

//define EVENT_CLASS_TYPE macro to easily assign the type of event 
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type;}\
                                virtual EventType GetEventType() const override { return GetStaticType(); }\
                                virtual const char* GetName() const override {return #type; }
//define EVENT_CLASS_CATEGORY macro to easily assign the category of event 
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category; }

	//Event class which is an abstract class that is inherited by ApplicationEvent, KeyEvent, MouseEvent
	class GEMGINE_API Event
	{
		//friend class EventDispatcher, can access protected and private members
		friend class EventDispatcher;
	public:
		//Interface - uses pure virtual functions
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected: 
		bool m_Handled = false;
	};

	//EventDispatcher class 
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) 
			: m_Event(event)
		{

		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}