#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {
public: 
	void run() {
		initVulkan();
		mainLoop();
		cleanup();
}
private:
	void initVulkan() {

	}
	void mainLoop() {

	}
	void cleanup() {

	}
};
int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		//the standard error stream oriented to narrow characters (of type char)
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}