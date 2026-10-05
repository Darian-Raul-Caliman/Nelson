#pragma once

#include "Core.h"

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




