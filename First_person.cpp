#include <Windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
#include <string.h>
#include <math.h>

int nScreenWidth = 120, nScreenHeight = 40;
float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;

int nMapHeight = 16;
int nMapWeith = 16;

float fFov = 3.141/4.0;
float fDepth = 16.0f;

int main(){
    //create Screen Buffer
    wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    wstring map;
    map += L"#########.......";
	map += L"#...............";
	map += L"#.......########";
	map += L"#..............#";
	map += L"#......##......#";
	map += L"#......##......#";
	map += L"#..............#";
	map += L"###............#";
	map += L"##.............#";
	map += L"#......####..###";
	map += L"#......#.......#";
	map += L"#......#.......#";
	map += L"#..............#";
	map += L"#......#########";
	map += L"#..............#";
	map += L"################";

    while(1){
     //craete a screen and set it last element is \0

     for (int x = 0; x < nScreenWidth; x++)
     {
         //for each colume, calculate the projection ray angle into world space
         float fRayAngle = (fPlayerA - fFov/2.0f) + (float)x / (float)nScreenWidth * fFov;
         float fDistanceToWall = 0.0;
         bool HitWall = false;

         float fEyeX = sinf(fRayAngle);
         float fEyeY = cosf(fRayAngle);


         while (!HitWall && fDistanceToWall < fDepth){
             fDistanceToWall += 0.1f;

             int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
             int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

             if (nTestX < 0 || nTestX >= nMapWeith || nTestY < 0 || nTestY >= nMapHeight){
                 HitWall = true;
                 fDistanceToWall = fDepth;
             }
             else{
                 if (map[nTestY * nMapWeith + nTestX] == '#'){
                     HitWall = true;
                 }
             }
         }
         int nCelling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
         int nFloor = nScreenHeight - nCelling;

         for (int y = 0; y < nScreenHeight; y++)
         {
             if (y < nCelling){
                 screen[y * nScreenHeight + x] = ' ';
             }
             else if (y > nCelling &&y <= nFloor){
                 screen[y * nScreenHeight + x] = '#';
             }
             else{
                 screen[y * nScreenHeight + x] = ' ';
             }
         }
     }

     screen[nScreenWidth * nScreenHeight - 1] = '\0';
     WriteConsoleOutputCharacterA(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten); 
    }

    return 0;
}