#pragma once
#include "RenderableObject.h"
class Sphere:public RenderableObject
{
private:
	bool _IsMoveCheck;
public:
	Sphere();
	virtual void shutDown() override;
    virtual	void setPos(float x, float y, float z) override;

	virtual void setMoving(bool IsCheck);
	virtual bool getMoving();
};

