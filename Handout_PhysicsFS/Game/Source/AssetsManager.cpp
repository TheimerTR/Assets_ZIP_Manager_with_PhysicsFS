#include "App.h"
#include "AssetsManager.h"

#include "Defs.h"
#include "Log.h"

#include <iostream>
#include <sstream>

//Some links of utility
//https://icculus.org/physfs/
//https://icculus.org/physfs/docs/html/physfs_8h.html
//https://gist.github.com/Ybalrid/fb3453c997b4925d25dc9a1bf4f952b6
//https://gregfmartin.wordpress.com/2017/01/02/physicsfsphysfs-basic-tutorial/
//https://wiki.libsdl.org/SDL_RWops

AssetsManager::AssetsManager() : Module()
{
	name = ("assetsManager");

	//TODO 1: initialize physicsFS Library

	//This function create the default path to search, in this case the Output, that is the default program path too
	
}

AssetsManager::~AssetsManager()
{
	//TODO 1: Close all files opened by physicsFS

}

bool AssetsManager::Awake(pugi::xml_node& config)
{
	//TODO 2: Now add the path to search our Assets folder that now is .zip
	//HINT: The path is the same that we actually are: Output -> Assets.zip

	return true;
}

SDL_RWops* AssetsManager::Load(const char* path) const
{
	char* buffer; //The buffer is the memory space that we will need in order to access our file
	uint numbytes = LoadData(path, &buffer); //Here we get the size in memory of the data from our file in bytes

	if (numbytes > 0)
	{
		SDL_RWops* RWop = SDL_RWFromConstMem(buffer, numbytes); //With the number of bytes and the buffer extracts the info from our file

		return RWop;
	}
	else
	{
		return nullptr;
	}
}

uint AssetsManager::LoadData(const char* path, char** buffer) const
{
	uint ret = 0;
	
	////Uncoment all once
	////TODO 3: Here we will open the file in question 

	//if ( != nullptr)//Check if it has open the file correctly
	//{
	//	//TODO 4: Now we will read the data form the physFS file

	//	if () //Here we check if the two sizes are the same, theorically they have to be, but in case that not is an error
	//	{
	//		
	//	}
	//	else 
	//	{
	//		
	//	}
	//}

	return ret;
}

bool AssetsManager::CleanUp()
{
	return false;
}


