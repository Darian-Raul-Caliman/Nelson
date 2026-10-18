#include "nspch.h"
#include "Application.h"
#include "Layer.h"

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

	void Application::PushLayer(Layer* layer) 
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer) 
	{
		m_LayerStack.PushOverlay(layer);
	}



	void Application::onEvent(Event& e) {

		EventDispatcher dispatcher(e);
		//NS_CORE_INFO("{0}", e); Logging events in the console
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		NS_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled())
			{
				break;
			}
		}

	}



	bool Application::OnWindowClose(WindowCloseEvent& e) {

		m_Running = false;
		return true;

	}

	void Application::Run() {
		

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

}
