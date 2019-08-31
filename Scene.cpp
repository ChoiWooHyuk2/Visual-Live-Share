#include "pch.h"
#include "Scene.h"
#include "SpendData.h"

Scene::Scene():sw(false)
{
	CreateBuffer();
}


Scene::~Scene()
{
}


void Scene::render()
{
	ClearBuffer();
	/*CreateMap(0.1,0.2);*/
	WriteBuffer(FWMAIN->PlayerPosx(), FWMAIN->PlayerPosy(), "■");
	FlipBuffer();
	

}

Scene* Scene::GetInstance()
{
	static Scene i;
	return &i;
}

void Scene::CreateBuffer()
{
	if (sw)
		return;
	CONSOLE_CURSOR_INFO cci;
	//화면 버퍼 2개를 만든다.
	screenBuff[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	screenBuff[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	backBuffIndex = 1;
	SetConsoleActiveScreenBuffer(screenBuff[0]);

	//커서 숨기기
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(screenBuff[0], &cci);
	SetConsoleCursorInfo(screenBuff[1], &cci);
	sw = true;
}

void Scene::ClearBuffer()
{
	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(screenBuff[backBuffIndex], ' ', SCREEN_SIZE_X * SCREEN_SIZE_Y, Coor, &dw);
}

void Scene::WriteBuffer(float x, float y,const char* string)
{                           
	DWORD dw;                                      
	COORD pos = { x, y };
	WriteConsoleOutputCharacter(screenBuff[backBuffIndex], string, lstrlen(string), pos, &dw);
	
}

void Scene::FlipBuffer()
{
	SetConsoleActiveScreenBuffer(screenBuff[backBuffIndex]);
	backBuffIndex = backBuffIndex ? 0 : 1;
}

void Scene::ReleaseBuffer()
{
	CloseHandle(screenBuff[0]);
	CloseHandle(screenBuff[1]);
}

void Scene::CreateMap(float x, float y)
{
	
	for (int i = 0; i < MAPYSIZE; i++)
	{
		for(int j = FWMAIN->PlayerPosx()-10; j< MAPXSIZE; j++)
		{
			if(MAP[i][j]== 0)
				WriteBuffer(j*2,i, "■");
				if(MAP[i][j]==1)
					WriteBuffer(j, i, "  ");
		}
	} 
}
