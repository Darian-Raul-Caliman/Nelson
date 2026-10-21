#pragma once
#include "Nelson/Layer.h"
#include "Nelson/Events/KeyEvent.h"
#include "Nelson/Events/MouseEvents.h"
#include "Nelson/Events/ApplicationEvent.h"
#include "../vendor/imGui/backends/imgui_impl_glfw.h"

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


		float m_Time = 0.0f;
	};
}