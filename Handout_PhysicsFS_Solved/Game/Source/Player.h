#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
#include "Point.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class Player : public Entity
{
public:

	Player();
	
	virtual ~Player();

	bool Awake();

	bool Start();

	bool Update();

	bool CleanUp();

public:

	//L02: DONE 1: Declare player parameters
	SDL_Texture* texture;
	const char* texturePath;

private:

};

#endif // __PLAYER_H__