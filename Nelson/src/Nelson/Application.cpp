#include "nspch.h"
#include "Application.h"


#include "Nelson/Log.h"

#include <GLFW/glfw3.h>

namespace Nelson {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application() {

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::onEvent));
	}
	Application::~Application() {

	}

	void Application::onEvent(Event& e) {

		EventDispatcher dispatcher(e);
		//NS_CORE_INFO("{0}", e); Logging events in the console
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		NS_CORE_TRACE("{0}", e);

	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {

		m_Running = false;
		return true;

	}

	void Application::Run() {
		

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}
