#include "ResourceLoader.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <Vertex.h>

#include <ImageLoader.h>
#include <glm\gtc\type_ptr.hpp>



std::string ResourceLoader::loadShader(std::string file)
{
	std::string out;
	std::string line;
	std::ifstream myfile ("./res/shader/" + file);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			out.append(line).append("\n");
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file: " << "./res/shader/" << file << std::endl;
	}
	return out;
}

void ResourceLoader::loadMesh(std::string file, Mesh& mesh)
{
	//Mesh mesh;
	std::string out;
	std::string line;
	std::ifstream myfile ("./res/mesh/" + file);
	if (myfile.is_open())
	{
		std::vector<Vertex> vertices;
		std::vector<int> indices;
		while ( getline (myfile,line) )
		{
			if (line[0] == 'v')
			{
				std::istringstream iss(line);		
				std::string type;
				float x;
				float y;
				float z;
				iss >> type;
				iss >> x;
				iss >> y;
				iss >> z;
				glm::vec3 vec(x, y, z);
				Vertex v(vec, glm::vec2(glm::abs(x), glm::abs(y)));
				vertices.push_back(v);
				//std::cout << "textCord: " << v.getTextCord().x << ", " << v.getTextCord().y << std::endl;
				
			}
			if (line[0] == 'f')
			{
				std::istringstream iss(line);
				std::string type;
				iss >> type;
				int x;
				int y;
				int z;
				iss >> x;
				iss >> y;
				iss >> z;
				x--; y--; z--;
				indices.push_back(x);
				indices.push_back(y);
				indices.push_back(z);
				//std::cout << "indices: " << x << ", " << y << ", " << z << std::endl;
			}
		}
		myfile.close();
		mesh.addVertices(vertices, indices, true);
	}
	else
	{
		std::cout << "Unable to open file: " << "./res/mesh/" << file << std::endl;
	}
}


void ResourceLoader::loadTexture(std::string filename, Texture& texture)
{
	Image* image = loadBMP(("./res/texture/" + filename).c_str());

	GLuint textureID;			// Create a texture ID as a GLuint

	// Generate a new texture
	glGenTextures(1, &textureID);
 
	// Bind the texture to a name
	glBindTexture(GL_TEXTURE_2D, textureID);
 
	// Set texture clamping method
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
 
	// Set texture interpolation method to use linear interpolation (no MIPMAPS)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);


	// Specify the texture specification
	glTexImage2D(GL_TEXTURE_2D, 				// Type of texture
				 0,				// Pyramid level (for mip-mapping) - 0 is the top level
				 GL_RGBA,	// Internal pixel format to use. Can be a generic type like GL_RGB or GL_RGBA, or a sized typew
				 image->width,	// Image width
				 image->height,	// Image height
				 0,				// Border width in pixels (can either be 1 or 0)
				 GL_RGB,	// Format of image pixel data
				 GL_UNSIGNED_BYTE,		// Image data type
				 image->pixels);			// The actual image data itself
	texture.setID(textureID);
	//return textureID; // Return the GLuint to the texture so you can use it!
}
	

void ResourceLoader::generateWhiteTexture(Texture& texture)
{
	GLuint textureID;			// Create a texture ID as a GLuint

	// Generate a new texture
	glGenTextures(1, &textureID);
 
	// Bind the texture to a name
	glBindTexture(GL_TEXTURE_2D, textureID);
 
	// Set texture clamping method
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
 
	// Set texture interpolation method to use linear interpolation (no MIPMAPS)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	unsigned char data[3] = {1,1,1};
	// Specify the texture specification
	glTexImage2D(GL_TEXTURE_2D, 				// Type of texture
				 0,				// Pyramid level (for mip-mapping) - 0 is the top level
				 GL_RGB,	// Internal pixel format to use. Can be a generic type like GL_RGB or GL_RGBA, or a sized typew
				 1,	// Image width
				 1,	// Image height
				 0,				// Border width in pixels (can either be 1 or 0)
				 GL_RGB,	// Format of image pixel data
				 GL_UNSIGNED_BYTE,		// Image data type
				 &data);			// The actual image data itself
	texture.setID(textureID);
}