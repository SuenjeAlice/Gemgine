# Gemgine - Engine Architecture and Design Engine Project - Sünje Winteler ai21m038
Gemgine Engine was created using the Hazel Engine Tutorial by The Cherno.


## How To Run Gemgine

### Download Demo Version
Check out the demo version by going to the release tab on Github and downloading the latest version of Gemgine.dll and Sandbox.exe.
Make sure they are in the same folder. To run the demo simply double click Sandbox.exe.

### Use Gemgine Engine as you Game Engine
To use the Gemgine Engine as your Game Engine go to the release tab on Github and download the latest version of Gemgine.dll. You can write your own game. You have to bind the Gemgine.dll file into your own project.
Check out this simple example for our demo:

```
#include <Gemgine.h>

class Sandbox : public Gemgine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

//Creates Application
Gemgine::Application* Gemgine::CreateApplication()
{
	return new Sandbox();
}
```

### How to work on Gemgine Engine yourself
Download the source code from Github. Click the 'GenerateProject.bat' file to generate a project solution in Visual Studio 2022.
Alternatively, you can generate project solutions in a different IDE by typing the following code into your command window (be aware, you have to be in the same folder where the 'GenerateProject.bat' file sits):

```

call vendor\premake\premake5.exe IDE_HERE
PAUSE

```

Instead of IDE_HERE use the IDE you want:
- 'vs2022' for Visual Studio 2022
- 'vs2019' for Visual Studio 2019
- 'codelite' for CodeLite
- 'xcode4' for Apple Xcode 4

You can also create a Makefile, instead of IDE_HERE us:
- 'gmake' 
- 'gmake2'

## What can you do with the Gemgine Engine?