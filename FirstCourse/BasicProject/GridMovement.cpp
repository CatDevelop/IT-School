    #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void keyboardControls(int *PlayerX, int *PlayerY);
    void Drawing(int PlayerX, int PlayerY, HDC BackgroundMap1);
    bool CheckCollision (int PlayerX, int PlayerY, int PlayerDirection);

    int main()
    {
        txCreateWindow(1440,720);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        int PlayerX = 720;
        int PlayerY = 336;

        HDC BackgroundMap1 = txLoadImage("Resources\\Map1.bmp");

        while(true)
        {
            keyboardControls(&PlayerX, &PlayerY);
            txBegin();
            Drawing(PlayerX, PlayerY, BackgroundMap1);
            txEnd();
        }
    }

    void keyboardControls(int *PlayerX, int *PlayerY)
    {
        bool CollisionMove = true;
        int PlayerDirection;

        if (GetAsyncKeyState('W') or GetAsyncKeyState(VK_UP))
        {
            if(!GetAsyncKeyState('A') and !GetAsyncKeyState(VK_LEFT) and !GetAsyncKeyState('S') and !GetAsyncKeyState(VK_DOWN) and !GetAsyncKeyState('D') and !GetAsyncKeyState(VK_RIGHT))
            {
                PlayerDirection = 1;
                CollisionMove = CheckCollision (*PlayerX, *PlayerY, PlayerDirection);
                if(CollisionMove)
                {
                    *PlayerY = *PlayerY-48;
                    Sleep(150);
                }
            }
        }

        if (GetAsyncKeyState('A') or GetAsyncKeyState(VK_LEFT))
        {
            if(!GetAsyncKeyState('W') and !GetAsyncKeyState(VK_UP) and !GetAsyncKeyState('S') and !GetAsyncKeyState(VK_DOWN) and !GetAsyncKeyState('D') and !GetAsyncKeyState(VK_RIGHT))
            {
                PlayerDirection = 4;
                CollisionMove = CheckCollision (*PlayerX, *PlayerY, PlayerDirection);
                if(CollisionMove)
                {
                    *PlayerX = *PlayerX-48;
                    Sleep(150);
                }
            }
        }

        if (GetAsyncKeyState('S') or GetAsyncKeyState(VK_DOWN))
        {
            if(!GetAsyncKeyState('W') and !GetAsyncKeyState(VK_UP) and !GetAsyncKeyState('A') and !GetAsyncKeyState(VK_LEFT) and !GetAsyncKeyState('D') and !GetAsyncKeyState(VK_RIGHT))
            {
                PlayerDirection = 3;
                CollisionMove = CheckCollision (*PlayerX, *PlayerY, PlayerDirection);
                if(CollisionMove)
                {
                    *PlayerY = *PlayerY+48;
                    Sleep(150);
                }
            }
        }

        if (GetAsyncKeyState('D') or GetAsyncKeyState(VK_RIGHT))
        {
            if(!GetAsyncKeyState('W') and !GetAsyncKeyState(VK_UP) and !GetAsyncKeyState('S') and !GetAsyncKeyState(VK_DOWN) and !GetAsyncKeyState('A') and !GetAsyncKeyState(VK_LEFT))
            {
                PlayerDirection = 2;
                CollisionMove = CheckCollision (*PlayerX, *PlayerY, PlayerDirection);
                if(CollisionMove)
                {
                    *PlayerX = *PlayerX+48;
                    Sleep(150);
                }
            }
        }
    }

    void Drawing(int PlayerX, int PlayerY, HDC BackgroundMap1)
    {
        Sleep(0.001);
        txSetFillColor(TX_WHITE);
        txClear();

        txBitBlt(txDC(), 0, 0, 1440, 720, BackgroundMap1, 0, 0);

        POINT Player [4] = {{PlayerX, PlayerY}, {PlayerX+47, PlayerY}, {PlayerX+47, PlayerY+47}, {PlayerX, PlayerY+47}};
        txSetColor(RGB(0, 0, 0));
        txSetFillColor (RGB(0, 0, 0));
        txPolygon(Player, 4);

        int CollisionX = 240;
        int CollisionY = 240;
        POINT Collision [4] = {{CollisionX, CollisionY}, {CollisionX+47, CollisionY}, {CollisionX+47, CollisionY+47}, {CollisionX, CollisionY+47}};
        txSetColor(RGB(255, 0, 0));
        txSetFillColor (RGB(255, 0, 0));
        txPolygon(Collision, 4);
        CollisionX = 480;
        CollisionY = 480;
        POINT Collision2 [4] = {{CollisionX, CollisionY}, {CollisionX+47, CollisionY}, {CollisionX+47, CollisionY+47}, {CollisionX, CollisionY+47}};
        txSetColor(RGB(255, 0, 0));
        txSetFillColor (RGB(255, 0, 0));
        txPolygon(Collision2, 4);
    }

    bool CheckCollision(int PlayerX, int PlayerY, int PlayerDirection)
    {
        int CollisionXCoordinateArray[100] = {240, 480, 0, 48, 96, 144, 192, 240, 288, 336, 384, 432, 480, 528, 576, 624, 672, 720, 768, 816, 864, 912, 960, 1008, 1056, 1104,  1152, 1200, 1248, 1296, 1344, 1392, 1440, 1488, 0, 48, 96, 144, 192, 240, 288, 336, 384, 432, 480, 528, 576, 624, 672, 720, 768, 816, 864, 912, 960, 1008, 1056, 1104,  1152, 1200, 1248, 1296, 1344, 1392, 1440, 1488, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440, 1440};
        int CollisionYCoordinateArray[100] = {240, 480, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, -48, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 720, 0, 48, 96, 144, 192, 240, 288, 336, 384, 432, 480, 528, 576, 624, 672, 720, 768, 0, 48, 96, 144, 192, 240, 288, 336, 384, 432, 480, 528, 576, 624, 672, 720, 768};
        int Check = 0;
        
        for(int i = 0; i<100; i++)
        {
            if(PlayerDirection == 1)
            {
                if(PlayerX == CollisionXCoordinateArray[i] and PlayerY-48 == CollisionYCoordinateArray[i])
                {
                    Check++;
                }
            }

            if(PlayerDirection == 2)
            {
                if(PlayerX+48 == CollisionXCoordinateArray[i] and PlayerY == CollisionYCoordinateArray[i])
                {
                    Check++;
                }
            }

            if(PlayerDirection == 3)
            {
                if(PlayerX == CollisionXCoordinateArray[i] and PlayerY+48 == CollisionYCoordinateArray[i])
                {
                    Check++;
                }
            }

            if(PlayerDirection == 4)
            {
                if(PlayerX-48 == CollisionXCoordinateArray[i] and PlayerY == CollisionYCoordinateArray[i])
                {
                    Check++;
                }
            }
        }

        if(Check == 0)
        {
            return true;
        }else{
            return false;
        }
    }
