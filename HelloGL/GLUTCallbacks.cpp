#include "GLUTCallbacks.h"
#include "HelloGL.h"

namespace GLUTCallbacks
{
	namespace
	{
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}

	void Display()
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
	}

	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		{
			glutTimerFunc(preferredRefresh, GLUTCallbacks::Timer, preferredRefresh);
		}
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		glutKeyboardFunc(GLUTCallbacks::Keyboard);
	}
}