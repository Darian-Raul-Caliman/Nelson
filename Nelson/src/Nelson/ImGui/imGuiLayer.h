#pragma once
#include "Nelson/Layer.h"
#include "Nelson/Events/KeyEvent.h"
#include "Nelson/Events/MouseEvents.h"

namespace Nelson {

	class NS_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event& event);
		void OnAttach();
		void OnDetach();

	private:
		void OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		void OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		void OnMouseScrollEvent(MouseScrolledEvent& e);
		void OnMouseMovedEvent(MouseMovedEvent& e);
		void OnKeyPressedEvent(KeyPressedEvent& e);
		void OnKeyReleasedEvent(KeyReleasedEvent& e);
		//void OnKeyTypedEvent(KeyTypedEvent& e);
		void OnWindowResizedEvent(WindowResizeEvent& e);

		float m_Time = 0.0f;
	};
}