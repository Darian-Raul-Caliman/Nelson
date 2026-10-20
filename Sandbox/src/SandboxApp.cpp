#include "Nelson/Nelson.h"


class ExampleLayer : public Nelson::Layer
{
public:
	ExampleLayer() : Layer("Example") {};

	void OnUpdate() override
	{
		NS_INFO("ExampleLayer::Updated");
	}

	void OnEvent(Nelson::Event& event) override
	{
		NS_TRACE("{0}", event);
	}

};


class Sandbox : public Nelson::Application {


public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Nelson::ImGuiLayer());
	}
	~Sandbox() {
	}
};

Nelson::Application* Nelson::CreateApplication() {
	return new Sandbox();
}