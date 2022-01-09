#pragma once
#include "RenderableObject.h"

class KeyInput;

class Mario :public RenderableObject
{
public:
	virtual void setPos(float x, float y, float z) override;
	virtual void setRot(float speed, float x, float y, float z)override;
	virtual void setScale(float x, float y, float z)override;
	virtual void setCameraPos(float x, float y, float z) override;
	virtual void init() override;
	virtual void render() override;
	virtual void update() override;
	virtual void shutDown() override;

	virtual void AddChild(CompositeObj* addObj)override;

	bool getIsLive();
	void setIsLive(bool _IsLive);
private:
	bool IsLive;
};

