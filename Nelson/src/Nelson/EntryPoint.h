#pragma once

#ifdef NS_PLATFORM_WINDOWS

extern Nelson::Application* Nelson::CreateApplication();

int main(int argc, char** argv) {
	auto app = Nelson::CreateApplication();
	app->Run();
	delete app;
}

#endif