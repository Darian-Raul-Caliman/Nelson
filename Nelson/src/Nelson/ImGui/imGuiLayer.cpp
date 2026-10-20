#include "nspch.h"
#include "imGuiLayer.h"

#include "imgui.h"
#include "GLFW/glfw3.h"
#include "Nelson/Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "Nelson/Application.h"

namespace Nelson {

	ImGuiLayer::ImGuiLayer() :Layer("ImGuiLayer")
	{
		

	}
	ImGuiLayer::~ImGuiLayer()
	{

	}
	void ImGuiLayer::OnUpdate()
	{

		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(),app.GetWindow().GetHeight());

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);
		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		

	}
	void ImGuiLayer::OnEvent(Event& event)
	{

	}
	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		ImGui_ImplOpenGL3_Init("#version 410");
	}


	void ImGuiLayer::OnDetach()
	{

	}
}
