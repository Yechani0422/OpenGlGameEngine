#pragma once
#include "FileManager.h"

class KeyInput
{
public:

	void computeMatricesFromInputs();
	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;

	glm::mat4 getViewMatrix() {
		return ViewMatrix;
	}
	glm::mat4 getProjectionMatrix() {
		return ProjectionMatrix;
	}

	// Initial position : on +Z
	glm::vec3 position = glm::vec3(0, 0, 5);
	// Initial horizontal angle : toward -Z
	float horizontalAngle = 3.14f;
	// Initial vertical angle : none
	float verticalAngle = 0.0f;
	// Initial Field of View
	float initialFoV = 45.0f;

	float speed = 3.0f; // 3 units / second
	float mouseSpeed = 0.005f;
};

