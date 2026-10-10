#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Nelson/Events/Event.h"   // or "../Nelson/Events/Event.h" depending on layout

namespace Nelson {

	class NS_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();

}







