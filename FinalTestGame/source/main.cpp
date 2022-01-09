#include "Renderer.h"
#include "Time.h"

#include "../include/Mario.h"
#include "../include/Dung.h"
#include "../include/Restart.h"
#include "../include/Bg.h"

#include "testNonRenderObj.h"

#include "CompositeObj.h"

//bool CheckCollision(CompositeObj* one, CompositeObj* two) // AABB - AABB collision
//{
//	// collision x-axis?
//	bool collisionX = one->position.x + one->scaleVec.x >= two->position.x &&
//		two->position.x + two->scaleVec.x >= one->position.x;
//	// collision y-axis?
//	bool collisionY = one->position.y + one->scaleVec.y >= two->position.y &&
//		two->position.y + two->scaleVec.y >= one->position.y;
//	// collision only if on both axes
//	return collisionX && collisionY;
//}

bool CheckCollision(CompositeObj* one, CompositeObj* two) // AABB - AABB collision
{
	// collision x-axis?
	bool collisionX = one->position.x + 1.5 >= (two->position.x)/2 &&
		(two->position.x)/2 + 1 >= one->position.x;
	// collision y-axis?
	bool collisionY = one->position.y + 1.5 >= (two->position.y)/2 &&
		(two->position.y)/2 + 1 >= one->position.y;
	// collision only if on both axes
	return collisionX && collisionY;
}

int main(void)
{
	Mario* mario = new Mario();
	Bg* bg = new Bg();
	Restart* restart = new Restart();
	testNonRenderObj* testNonRender = new testNonRenderObj();

	vector<Dung*>* dung = new vector<Dung*>();

	for (int i = 0; i < 10; i++)
	{
		dung->push_back(new Dung());
	}	
	
	  
	Renderer::GetInstance()->init();	
	
	mario->setScale(0.2f, 0.2f, 0.2f);

	bg->setScale(0.17f, 0.125f, 0.1f);

	for (
		vector<Dung*>::const_iterator it = dung->begin();
		it != dung->end();
		++it
		)
	{
		(*it)->setScale(0.1f, 0.1f, 0.1f);
	}

	while (glfwGetKey(Renderer::GetInstance()->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(Renderer::GetInstance()->window) == 0)
	{
		Renderer::GetInstance()->renderUp();

		if (Time::GetInstance()->IsFixedRendering())
		{
			Renderer::GetInstance()->update();
		}

		Renderer::GetInstance()->render();

		for (
			vector<Dung*>::const_iterator it = dung->begin();
			it != dung->end();
			++it
			)
		{
			if (CheckCollision(mario, (*it)))
			{
				mario->setPos(-20.0f, 0, 0);
				mario->setIsLive(false);
				restart->setGameOver(false);
			}
		}

		if (restart->getGameOver()&&mario->getIsLive()==false)
		{
			mario->init();

			for (
				vector<Dung*>::const_iterator it = dung->begin();
				it != dung->end();
				++it
				)
			{
				(*it)->init();
			}
			
		}

		Renderer::GetInstance()->renderDown();
	}


	Renderer::GetInstance()->shutDown();

	for (
		vector<Dung*>::const_iterator it = dung->begin();
		it != dung->end();
		++it
		)
	{
		delete (*it);
	}
	delete dung;
	delete mario;
	delete bg;
	delete testNonRender;

	return 0;
}


