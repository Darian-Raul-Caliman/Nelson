#include "nspch.h"
#include "imGuiLayer.h"
#include <glad/glad.h>
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include <GLFW/glfw3.h>
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

		ImGui_ImplOpenGL3_NewFrame();

		ImGui_ImplGlfw_NewFrame();

		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		

	}
	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		ImGui_ImplGlfw_InitForOpenGL(window, true);

		ImGui_ImplOpenGL3_Init("#version 410");
	}


	void ImGuiLayer::OnDetach()
	{

		ImGui_ImplOpenGL3_Shutdown();

		
		ImGui_ImplGlfw_Shutdown();

		ImGui::DestroyContext();

	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);

	}


}
