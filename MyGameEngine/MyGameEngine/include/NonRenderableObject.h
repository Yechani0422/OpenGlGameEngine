#pragma once
#include "CompositeObj.h"

class NonRenderableObject :public CompositeObj
{
public:
	NonRenderableObject();
	virtual void init() override;
	virtual void render() override;
	virtual void update() override;
	virtual void shutDown() override;	
};

