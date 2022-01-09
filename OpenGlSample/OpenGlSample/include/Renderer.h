#pragma once

#include "FileManager.h"
#include "ICleanUp.h"
#include "IUpdate.h"
#include <vector>

class RenderableObject;
class NonRenderableObject;

class Renderer:public ICleanUp
{
private:
	glm::vec3 cameraPos;	

	static Renderer* instance;

	std::vector< RenderableObject*> renderObjList;
	std::vector< NonRenderableObject*> nonrenderObjList;
public:
	static Renderer* GetInstance()
	{
		if (instance == 0)
		{
			instance = new Renderer();
		}

		return instance;
	};

	void addRenderObject(RenderableObject* obj);
	void addNonRenderObject(NonRenderableObject* obj);
	int init();
	void update();
	void render();	
	virtual void shutDown() override;

	void renderUp();
	void renderDown();

	GLFWwindow* window;
	
	
};

