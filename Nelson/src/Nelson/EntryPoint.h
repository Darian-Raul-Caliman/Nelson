#pragma once

#ifdef NS_PLATFORM_WINDOWS

extern Nelson::Application* Nelson::CreateApplication();

int main(int argc, char** argv) {
	Nelson::Log::Init();
	NS_CORE_WARN("Initialized Log!");
	NS_INFO("Hello! This is Nelson Engine!");


	auto app = Nelson::CreateApplication();
	app->Run();
	delete app;
}

#endif