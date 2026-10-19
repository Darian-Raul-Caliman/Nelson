#pragma once
#include "Nelson/Layer.h"

namespace Nelson {

	class ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event& event);
	private:

	};
}