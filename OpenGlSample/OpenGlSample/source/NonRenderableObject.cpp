#include "../include/NonRenderableObject.h"
#include "../include/Renderer.h"

NonRenderableObject::NonRenderableObject()
{
	Renderer::GetInstance()->addNonRenderObject(this);
}

void NonRenderableObject::init()
{

}

void NonRenderableObject::render()
{

}

void NonRenderableObject::update()
{

}

void NonRenderableObject::shutDown()
{

}
