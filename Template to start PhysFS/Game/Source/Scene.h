#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Player.h"
#include "Item.h"

struct SDL_Texture;

class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	//load the texture
	void LoadTexFile(const pugi::xml_document& dataFile);

	//load the fx
	void LoadFxFile(const pugi::xml_document& dataFile);

	//load and play the music
	void LoadMusFile(const pugi::xml_document& dataFile);

public:

	//L02: DONE 3: Declare a Player attribute 
	Player* player;
	Item* item;

private:
	SDL_Texture* img;

	SDL_Texture* texture1 = nullptr;
	SDL_Texture* texture2 = nullptr;
	SDL_Texture* texture3 = nullptr;
	SDL_Texture* texture4 = nullptr;

};

#endif // __SCENE_H__