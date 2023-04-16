# PhysicsFS Personal Project

# Introduction

Hello, this is a little description to start with what is PhysicsFS, and why/how to use it. I hope you can find some interesting information here.

Firstly, we need to understand what an archive system is. In a simple way, it is a kind of organization by folders, where you can save information in it. Most OS (Operative systems) have this system implemented for the users. For the laptops or machines this type of organization takes time to access, and has to take some busy time to read or write on it. 

For that last point, optimization is a primary thing to take into consideration when you are making a game or application. And people find lots of techniques in order to reduce the load charge to our PC’s, well trying to reduce code or making programs to help with it. Here is where we introduce PhysicsFS and its advantages.

# What is PhysicsFS?

PhysicsFS is a program developed by Ryan C. Gordon, also known as Icculus. The first iteration of it was made in inspiration of Quake 3, which implemented an archive subsystem  that optimized the process of accessing information. 

An example of it is like, imagine that you have a folder on your computer where you store all the files of your game. Inside that folder there are other folders with images, sounds, maps and other things. There are also some compressed files like .ZIP or .7z that contain more files inside. PhysicsFS is a tool that helps you organize and access all those files in an easy and safe way. With PhysicsFS you can tell your game where it can save new things (like your saved games or your options) and where it can read things that already exist (like the images or the sounds). Also, you can use the compressed files as if they were normal folders, without having to decompress them first. This way you save space and time. To use PhysicsFS in your game, you have to tell it at the beginning what folder you want to use to save things and what folders or compressed files you want to use to read things. Then you can open any file you want using a simple name, no matter where it is actually or if it is compressed or not.

# Uses for it?
## Into the market?

There are no clear uses of it in a general market apart from the videogame industry. But some uses than can be interesting from using it will be:

- To make programs that can access to execute scripts or plugins, without necessarily extracting them from the original archive. 
- To create portable applications that can work from a USB without leaving a trace in the system. 
- To reduce the space that consumes a normal folder without making it a ZIP, and the time that takes to access the information from the buffer. 

## In videogames?

Some examples of the use of PhysFS (like the author of it call it) in videogames are: 

- Aquaria en Steam (steampowered.com)
- Battle for Wesnoth en Steam (steampowered.com).
- Cave Story+ en Steam (steampowered.com).
- Frozen Synapse en Steam (steampowered.com)
- Gish en Steam (steampowered.com)

And in relation with it, some graphic engines used it to like:

- LÖVE - Free 2D Game Engine (love2d.org)
- OGRE - Open Source 3D Graphics Engine

## Platform support

Here is a list from PhysicsFS (icculus.org) that shows the compatibility of that library:

- Support for .ZIP files (PkZip/Info-ZIP/WinZip compatible).
- Version 1.1+: support for .7z files (7zip/lzma).
- Version 3.0+: support for .iso files (CD-ROM image files).
- Version 3.0+: support for .vdf files (Gothic/Gothic II).
- Version 3.0+: support for .slb files (Independence War).
- Support for the Build Engine's GRP format.
- Support for Quake 1 and Quake 2's PAK file format.
- Support for Descent 1 and Descent 2's HOG file format.
- Support for Descent 1 and Descent 2's MVL file format.
- Support for Doom WAD files.
- Support for access to the native filesystem.
- Version 1.1+: Fully supports Unicode filenames.
- Compiles/runs on GNU/Linux (x86, PPC, MIPS, Sparc, Alpha, Itanium, and x86-64 tested; gcc).
- Compiles/runs on Windows XP and later (x86 and x64 tested; Visual Studio, Cygwin, and MinGW).
- Compiles/runs on WinRT, UWP, Windows Phone, Windows Store: (x86-64 and ARM tested; Visual Studio).
- Compiles/runs on macOS (x86, PPC, and x86-64 tested; gcc and clang).
- Compiles/runs on iOS (iPhone, iPad tested; xcode).
- Compiles/runs on OS/2, eComStation, ArcaOS (x86 tested; EMX and OpenWatcom).
- Compiles/runs on Haiku (x86 tested; gcc2 and gcc4)
- Compiles/runs on QNX 7 (x86, x86-64 and ARM tested).
- Compiles/runs on Android.
- Compiles/runs on the Nintendo Switch! (Contact Ryan for source code).
- Compiles/runs on Emscripten.
- Compiles/runs on generic Unix, like FreeBSD, OpenBSD, Solaris, etc (x86 and Alpha tested; gcc).
- Up to version 1.0: Compiles/runs on MacOS 8/9 (PPC tested; CodeWarrior 6).
- Up to version 2.0: Compiles/runs on Windows 95 and later (x86 and x64 tested; Visual Studio, Cygwin, and MinGW).
- Up to version 2.0: Compiles/runs on Microsoft PocketPC.
- Up to version 2.0: Compiles/runs on BeOS, YellowTab, Zeta, and Haiku (x86 tested; gcc).
- Third parties have reported easily porting PhysicsFS to PlayStation and Xbox consoles (Contact Ryan about lending him a devkit!).
- May compile and run elsewhere with little to no modification. Success stories and patches are welcome.

# Activity

## TODO:

**TODO 0:**

Put the need libraries to visual studio:

Properties → Vinculator → General → Additional working directories: 

Up box:
$(ProjectDir)Source\External\PhysFS\libx86

Down box:
C:\Users\???\???\PhysFS\Game\Source\External\PhysFS\libx86

Properties → Vinculator → Entrada → Additional dependencies:

Up box:
physfs.lib

Mid box:
physfs.lib

**TODO 1:**

Into the PhysicsFSAssetManager.cpp will initialize the PhysicsFS Library API and also mount the Assets. Here you have to make sure that everything is ok, and don’t give any errors. 

You will need this functions:

PHYSFS_init(NULL)
PHYSFS_mount(“Name of the asset folder.pak”, NULL, 1)
PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode())

Hint: 

Here at the same time of making the initialization you can check if there is any error. Kind of:

if(??? == 0)
{
LOG("Error message: %s\n", ???;
return false;
}

**TODO 2:**

 Now, we will do the loadAssets(const char* pathName) function. First, you need to know if the path that we gave to the function already exists. For that we will do the same of the last step but with that function:

PHYSFS_exists(pathName)

Hint:

In the error code you can also put the path that we already know:


LOG("Error message: %s\n", ?, ???;
return NULL;


**TODO 3:**

Then if there is no errors, can we open the path with:

PHYSFSRWOPS_openRead(pathName)

And save it with a type of:

SDL_RWops* name

Now check that the file name  is not == NULL with an error, if this is the case return NULL.

And finally return name to the function. 

**TODO 4:**

Repeat the process of the loadAssets(), but now with loadXML(const char* namePath, char** bufferInfo). 

But now you will need to use PHYSFS_exists(namePath), first check for errors, and then open the file with PHYSFS_openRead(namePath), with a type PHYSFS_file* fileName. Check if it is not equal to NULL, in case that is it, make a LOG error message. 

**TODO 5:**

Now see if the fileName has ended to read or not, in case of not, you will need to save inside the size in bytes. You will need PHYSFS_fileLength(fileName), and save it in a PHYSFS_sint64 sizeName.

With that sizeName, will now pass that info to the bufferInfo, bufferInfo now is the point of the read that the program is at the moment, and sizeName is the máximum size that can be read.

**TODO 6:**

With bufferInfo and sizeName, we will be capable of knowing the reading bytes that we have at the moment. Use the function of PHYSFS_readBytes(fileName, *bufferInfo, sizeName), and save it with PHYSFS_sint64 bytesReaded.

Check for errors, but in this case is not == NULL, is == -1.

**TODO 7:**

Now will check if the file has ended to be readed or not, in case of yes, the bytesReaded and sizeName had to be the same, inside see if the fileName is not closed with PHYSFS_close(fileName) == 0 (in case of yes make an error LOG), and return the actual size of bytes to the function with bytesReaded.

Else if the file hasn't ended to be readed, the file has to be closed with PHYSFS_close(fileName), release the buffer memory used with RELEASE_ARRAY(bufferInfo), and return 0 to the function.

**TODO 8:**

Now we have everything to use our functions working, try to load a texture in Texture.cpp Load(), first create an empty texture with SDL_Texture* textureName = NULL;

Now with app->PhysicsFSAssetManager->LoadAsset(pathName) that pathName is the path to the texture that the function gives us. Save that info into a SDL_RWops* rwName and use it like normal with a SDL_Surface* surfaceName = IMG_Load_RW(rwName, 0). To try it use that code:

if(surfaceName  == NULL)
{
LOG("Couldn’t load surface path: %s. IMG_Load: %s", pathName, IMG_GetError());
}
else
{
textureName = LoadSurface(surfaceName);
SDL_FreeSurface(surfaceName);
}

//Here remember to close de structure
SDL_RWclose(rwName);

return textureName ;

**TODO 9:**

First create a List<Mix_Chunk *> fxSound in Audio.h;

And repeat process of TODO 8 with Audio.cpp LoadFx():

SDL_RWops* audioName =  app->assetsManager->LoadAsset(pathName);
Mix_Chunk* FxName= Mix_LoadWAV_RW(audioName , 0);

if(FxName == NULL)
{
LOG("Couldn’t load music path: %s. Mix_GetError(): %s\n", pathName, Mix_GetError());
ret = false;
}
else
{
fxSound.Add(FxName);
ret = fxSound.Count();
}

//Here remember to close de structure
SDL_RWclose(audioName);

return ret;

Finally This is an optional TODO 9 if you want, already is an example with the key P.
To play it, call LoadFx(pathName) in scene.cpp and then play it with PlayFx(unsigned int id, int repeat) with any key input.
Conclusion
Final conclusion

# Found problems

# Documentation and references

<a href="https://github.com/TheGewehr/Assets-ZIP-Management-with-PhysFS">*GitHub - TheGewehr/Assets-ZIP-Management-with-PhysFS: This is the reseach that I made for Project 2, enjoi ;-)*</a>

*Introducción | Activos-ZIP-Gestión-con-PhysFS (thegewehr.github.io)*

*ZIPManagement_PhysFS | Personal research about how implement and use PhysFS, in your project (aarongcprog.github.io)*

*Assets Management with PhysFS | Assets-Zip-Management-with-PhysFS (perezenric.github.io)*

*PhysicsFS (icculus.org)*

*Physicsfs tutorial (github.com)*

*PhysicsFS/PhysFS++ Tutorial – Gregory F. Martin (wordpress.com)*
