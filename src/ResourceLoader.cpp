#include "ResourceLoader.h"
#include <fstream>
#include <iostream>

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