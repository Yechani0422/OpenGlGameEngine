#pragma once
#include "NonRenderableObject.h"

class testNonRenderObj:public NonRenderableObject
{
public:
	virtual void init() override;
	virtual void render() override;
	virtual void update() override;
	virtual void shutDown() override;
};

