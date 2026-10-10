#include "Application.h"
#include  "Nelson/Events/Event.h"
#include  "Nelson/Events/ApplicationEvent.h"
#include "Nelson/Log.h"

namespace Nelson {

	Application::Application() {

	}
	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryInput)) {
			NS_TRACE(e);
		}
		NS_TRACE(e);

		while (true) {

		}
	}

}
