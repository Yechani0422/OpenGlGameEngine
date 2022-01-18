#include "../include/testNonRenderObj.h"
#include <iostream>

void testNonRenderObj::init()
{
	std::cout << "non init" << std::endl;
}

void testNonRenderObj::render()
{
	
}

void testNonRenderObj::update()
{
	//std::cout << "non update" << std::endl;
}

void testNonRenderObj::shutDown()
{
	std::cout << "non shutdown" << std::endl;
}
