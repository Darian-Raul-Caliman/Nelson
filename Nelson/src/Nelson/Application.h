#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Nelson/Events/Event.h"   // or "../Nelson/Events/Event.h" depending on layout
#include "Window.h"

namespace Nelson {

	class NS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	Application* CreateApplication();

}







