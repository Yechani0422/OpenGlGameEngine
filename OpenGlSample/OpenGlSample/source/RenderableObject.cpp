#include "../include/RenderableObject.h"
#include "../include/Renderer.h"



RenderableObject::RenderableObject()
{
	//_IsMoveCheck = false;
	Renderer::GetInstance()->addRenderObject(this);
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotVec = glm::vec3(0.0f, 0.0f, 0.0f);
	scaleVec = glm::vec3(0.0f, 0.0f, 0.0f);
	Rot = glm::mat4(1.0f);
	Scale = glm::mat4(1.0f);
	rotSpeed = 0.0f;
}