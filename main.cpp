#include "pch.h"
#include "Scene.h"
#include "InputHandler.h"
#include "SpendData.h"
int main(void)
{
	while (true) {
		FWINPUT->handleInput();
		FWMAIN->OnUpdata();
		FWSCE->render();
		Sleep(1000 / 120);
	}
	FWSCE->ReleaseBuffer();//버퍼삭제
}