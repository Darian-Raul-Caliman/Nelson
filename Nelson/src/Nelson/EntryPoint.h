#pragma once

#ifdef NS_PLATFORM_WINDOWS

extern Nelson::Application* Nelson::CreateApplication();

int main(int argc, char** argv) {
	Nelson::Log::Init();
	Nelson::Log::GetCoreLogger()->warn("Initialized Log!");
	Nelson::Log::GetClientLogger()->info("Hello Log!");

	auto app = Nelson::CreateApplication();
	app->Run();
	delete app;
}

#endif