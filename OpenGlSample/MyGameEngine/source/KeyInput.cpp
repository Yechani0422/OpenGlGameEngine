#include "../include/KeyInput.h"
#include "../include/Renderer.h"


void KeyInput::computeMatricesFromInputs() {

	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);


	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
	);

	// Up vector
	glm::vec3 up = glm::cross(right, direction);

	//// Move forward
	//if (glfwGetKey(Renderer::GetInstance()->window, GLFW_KEY_UP) == GLFW_PRESS) {
	//	position -= up * deltaTime * speed;
	//}
	//// Move backward
	//if (glfwGetKey(Renderer::GetInstance()->window, GLFW_KEY_DOWN) == GLFW_PRESS) {
	//	position += up * deltaTime * speed;
	//}

	// Strafe right
	if (glfwGetKey(Renderer::GetInstance()->window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		position -= right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(Renderer::GetInstance()->window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		
		position += right * deltaTime * speed;
	}

	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	// Projection matrix : 45¡Æ Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
	);

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}