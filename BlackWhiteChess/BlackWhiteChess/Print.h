#include <Windows.h>
#include <iostream>
#include <string>
#include <mmsystem.h>		
#pragma comment(lib, "winmm.lib")	
using namespace std;

void printBasic();

void goTo(int x, int y);

void printMenu();

void printExit();

void changePointTo(int startX,int endX, int y, int curIndex, int preIndex);