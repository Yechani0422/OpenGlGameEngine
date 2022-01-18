#pragma once

#include <string>
#include <vector>
#include "../include/GL/glew.h"		
#include "../include/GLFW/glfw3.h" 
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/glm.hpp"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")


using namespace std;

class RenderableObject;
class FileManager
{
public:
	
	void loadingObj(RenderableObject* obj, const char* vertex_data, const char* texturename, const char* vs_shader, const char* fs_shader);
	
	GLuint loadDDS(const char* imagepath);
	bool loadOBJ(const char* path,
		std::vector<glm::vec3>& out_vertices,
		std::vector<glm::vec2>& out_uvs,
		std::vector<glm::vec3>& out_normals);
	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
	static FileManager* GetInstance()
	{
		if (instance == 0)
		{
			instance = new FileManager();
		}

		return instance;
	};

private:
	FileManager();
	~FileManager();

	static FileManager* instance;
	
};

