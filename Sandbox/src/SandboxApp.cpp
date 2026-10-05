#include <Nelson.h>

class Sandbox : public Nelson::Application {


public:
	Sandbox() {
	}
	~Sandbox() {
	}
};

Nelson::Application* Nelson::CreateApplication() {
	return new Sandbox();
}