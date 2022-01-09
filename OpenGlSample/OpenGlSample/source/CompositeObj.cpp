#include "../include/CompositeObj.h"
#include <iostream>

CompositeObj::CompositeObj()
{
	children = new vector<CompositeObj*>();
	Parent = nullptr;
	//movePos = glm::mat4(1.0f);
}

CompositeObj::~CompositeObj()
{
	for (
		vector<CompositeObj*>::const_iterator it = children->begin();
		it != children->end();
		++it
		)
	{
		delete (*it);
	}

	children->clear();

	delete children;
}


void CompositeObj::AddChild(CompositeObj* addObj)
{
	children->push_back(addObj);

	addObj->Parent = this;
}

void CompositeObj::update()
{
	if (Parent)
	{
		WorldTransform = Parent->WorldTransform * Transform;
	}
	else
	{
		WorldTransform = Transform;
	}
}
