#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include  "Nelson/Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Nelson {

	class NS_API Application
	{
	public:
		Application();
		virtual ~Application();
		void onEvent(Event& e);
		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};
	Application* CreateApplication();

}







