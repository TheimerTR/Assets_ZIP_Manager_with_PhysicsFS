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
- $(ProjectDir)Source\External\PhysFS\libx86

Down box:
- C:\Users\???\???\PhysFS\Game\Source\External\PhysFS\libx86

Properties → Vinculator → Entrada → Additional dependencies:

Up box:
- physfs.lib

Mid box:
- physfs.lib

**TODO 1:**

Into the AssetManager.cpp will initialize the PhysicsFS Library API, destroy it and also mount the Assets. Here you have to make sure that everything is ok, and don’t give any errors. 

You will need this functions on the AssetsManager():

- PHYSFS_init(NULL)
- PHYSFS_mount(“Name of the asset folder.zip”, NULL, 1)
- PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode())

You will need this functions on the ~AssetsManager():

- PHYSFS_deinit();

Hint: 

Here at the same time of making the initialization you can check if there is any error. Kind of:

if(??? == 0)

{

LOG("Error message: %s\n", ???;

return false;

}

**TODO 2:**

Now we will add the path to search the Assets.zip, this will go into the Awake function, and you need:

- PHYSFS_addToSearchPath("...", 1)

Hint:

Remember the folder that you are at the moment, you are into Output already.

**TODO 3:**

Next we will open the read file in the LoadData(), to open you will need:

- PHYSFS_file* ... //This is to save the data from the read file

- PHYSFS_openRead(...) //This function is need to read the path file

Now it's open, will check if the data file is open correctly and no nullptr. If is not null, inside we will extract the file length in bytes, the tool to do it:

- unit ... //to save the number of bytes

- PHYSFS_fileLength(...) //to read the size of bytes of the data file.

Finally, we will allocate memory with the size of the file to the buffer, things needed:

- buffer //the actual buffer that the function gives

- new char[...] //the size of the file in a char style

**TODO 4:**

Now we will read the data with a physFS file, for this is needed:

- uint ... //to save into it the number of objects readed from the physFS file

- PHYSFS_read(..., ..., 1, ...) //the function that will read the file with PhysFS, return the number of objects readed

Next we will check if the size of the file is the same that the size of the file opened by PhysFS, in case that not, we will RELEASE the buffer, in case that yes, will return to the function the number of objects readed with PhysFS:

- ret = numReaded

And finally we close the PhysFS file with:

- PHYSFS_close(...)

**TODO 5:**

Now that we know how work our function, it's time to use them. Firstly, will create in the start function of the scene.cpp:

- char* buffer
- pugi::xml_document ...

And next, will call the LoadData() function of the AssetsManager.cpp, and save the bytes that return the PhysFS file:

- int ...

- app->assetsManager->LoadData("data.xml", &buffer) //That data.xml file, is a type of file that saves the things that are included inside the Assets folder in a .xml.

Now load the data from memory and save it, you will need:

- pugi::xml_parse_result ... //where you will save the data

- (...).load_buffer(buffer, ...) //the function that will charge the things from memory

Finally we will RELEASE the buffer (like: RELEASE_ARRAY(buffer)), and load all of the assets of our game:

- LoadTexFile(...);
- LoadFxFile(...);
- LoadMusFile(...);

**TODO 6:**

Now we will load some Images, music and fx, to do that we will charge them with the AssetsManager.cpp:

- **Images:**

  - Instead of using IMG_Load(...), will use IMG_LOAD_RW(app->assetsManager->Load(...), 1)

- **Audio:**

  **FX:**
  
  - Instead of using Mix_LoadWAV(...), will use Mix_LoadWAV_RW(app->assetsManager->Load(...), 1)
  
  **Music:**
  
  - Instead of using Mix_LoadMUS(...), will use Mix_LoadMUS_RW(app->assetsManager->Load(...), 1)

# Conclusion

 PhysFS is a library, that has not too much utility far from reducing the size of your proyect or making it safer. But, in general aspects, it's a great implementation for our projects, and maybe can make a difference in the final product.

# Found problems

  That library has two big problems:
  
  - There is no information on internet anywhere. The creator of PhysicsFS API, has not a truthly tutorial or setps to follow in order to set up a proyect. Or a little more detail in some of the description or uses of functions, making it harder to take a general aspect of what to do.
  - For begginers is kind of difficult to get into it, no tutorials on Youtube, no friendly info pages or a great range of webs to search in (in my search engine there where literally 9 pages of PhysFS webs in all the internet, where the half of them where questions about it).

# Documentation and references

<a href="https://github.com/TheGewehr/Assets-ZIP-Management-with-PhysFS">*GitHub - TheGewehr/Assets-ZIP-Management-with-PhysFS: This is the reseach that I made for Project 2, enjoi ;-)*</a>

<a href="https://thegewehr.github.io/Assets-ZIP-Management-with-PhysFS/">*Introducción | Activos-ZIP-Gestión-con-PhysFS (thegewehr.github.io)*</a>

<a href="https://aarongcprog.github.io/ZIPManagement_PhysFS/">*ZIPManagement_PhysFS | Personal research about how implement and use PhysFS, in your project (aarongcprog.github.io)*</a>

<a href="https://perezenric.github.io/Assets-Zip-Management-with-PhysFS/">*Assets Management with PhysFS | Assets-Zip-Management-with-PhysFS (perezenric.github.io)*</a>

<a href="https://www.icculus.org/physfs/">*PhysicsFS (icculus.org)*</a>

<a href="https://gist.github.com/Ybalrid/fb3453c997b4925d25dc9a1bf4f952b6">*Physicsfs tutorial (github.com)*</a>

<a href="https://gregfmartin.wordpress.com/2017/01/02/physicsfsphysfs-basic-tutorial/">*PhysicsFS/PhysFS++ Tutorial – Gregory F. Martin (wordpress.com)*</a>

<a href="https://github.com/Draquian/PhysFS_Roger_Salas/tree/1.0">*PhysFS_Roger_Salas (github.com)*</a>
