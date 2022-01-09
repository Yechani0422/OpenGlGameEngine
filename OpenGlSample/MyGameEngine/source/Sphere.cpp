#include "../include/sphere.h"
#include "../include/FileManager.h"

Sphere::Sphere()
{
	programID = FileManager::GetInstance()->LoadShaders("20151687_vs.shader", "20151687_fs.shader");

	MatrixID = glGetUniformLocation(programID, "MVP");

	Texture = FileManager::GetInstance()->loadDDS("character.DDS");

	textureID = glGetUniformLocation(programID, "myTextureSampler");



	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);


	bool res = FileManager::GetInstance()->loadOBJ("sphere.obj", vertices, uvs, normals);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);


	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Sphere::setPos(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
}


void Sphere::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(MatrixID);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void Sphere::setMoving(bool IsCheck)
{
	_IsMoveCheck = IsCheck;
}

bool Sphere::getMoving()
{
	return _IsMoveCheck;
}