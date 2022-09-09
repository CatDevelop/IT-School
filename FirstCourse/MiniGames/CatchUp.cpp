    #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void keyboardControls(int *PlayerX, int *PlayerY);
    void Drawing(HDC Background, int PlayerX, int PlayerY, int FirstBallX, int FirstBallY, int SecondBallX, int SecondBallY);
    bool CheckCollision ();

    int main()
    {
        txCreateWindow(1400, 800);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        HDC Background = txLoadImage("Resources\\ThirdProject\\Background.bmp");

        int PlayerX = 720;
        int PlayerY = 336;

        srand(time(NULL));
        int FirstBallX = rand()%1376+24;
        int FirstBallY = rand()%776+24;

        int SecondBallX = 700;
        int SecondBallY = 400;

        int FirstBallDirection = rand()%4+1;
        int SecondBallDirection = 4;

        bool FirstBallMove = true;
        bool SecondBallMove = true;

        srand(time(NULL));
        while(true)
        {
            if(FirstBallMove == false and SecondBallMove == false)
            {
                txDeleteDC(Background);
                return 0;
            }

            if ((PlayerX > FirstBallX-24 and PlayerX < FirstBallX+24 and PlayerY > FirstBallY-24 and PlayerY < FirstBallY+24) or (PlayerX+60 > FirstBallX-24 and PlayerX+60 < FirstBallX+24 and PlayerY > FirstBallY-24 and PlayerY < FirstBallY+24) or (PlayerX+60 > FirstBallX-24 and PlayerX+60 < FirstBallX+24 and PlayerY+60 > FirstBallY+24 and PlayerY+60 < FirstBallY+24) or (PlayerX > FirstBallX-24 and PlayerX < FirstBallX+24 and PlayerY+60 > FirstBallY+24 and PlayerY+60 < FirstBallY+24))
            {
                FirstBallMove = false;
            }

            if ((PlayerX > SecondBallX-24 and PlayerX < SecondBallX+24 and PlayerY > SecondBallY-24 and PlayerY < SecondBallY+24) or (PlayerX+60 > SecondBallX-24 and PlayerX+60 < SecondBallX+24 and PlayerY > SecondBallY-24 and PlayerY < SecondBallY+24) or (PlayerX+60 > SecondBallX-24 and PlayerX+60 < SecondBallX+24 and PlayerY+60 > SecondBallY+24 and PlayerY+60 < SecondBallY+24) or (PlayerX > SecondBallX-24 and PlayerX < SecondBallX+24 and PlayerY+60 > SecondBallY+24 and PlayerY+60 < SecondBallY+24))
            {
                SecondBallMove = false;
            }

            if (FirstBallMove)
            {
                if (FirstBallDirection == 1)
                {
                    FirstBallX = FirstBallX-2;
                    FirstBallY = FirstBallY-5;
                }
                if (FirstBallDirection == 2)
                {
                    FirstBallX = FirstBallX+5;
                    FirstBallY = FirstBallY-1;
                }
                if (FirstBallDirection == 3)
                {
                    FirstBallX = FirstBallX+1;
                    FirstBallY = FirstBallY+5;
                }
                if (FirstBallDirection == 4)
                {
                    FirstBallX = FirstBallX-5;
                    FirstBallY = FirstBallY-2;
                }

                //������� ��� ������
                if (FirstBallX<36)
                {
                    FirstBallX++;
                    FirstBallDirection = 2;
                }
                if (FirstBallX>1365)
                {
                    FirstBallX = FirstBallX-1;
                    FirstBallDirection = 1;
                }
                if (FirstBallY<24)
                {
                    FirstBallY++;
                    FirstBallDirection = 3;
                }
                if (FirstBallY>765)
                {
                    FirstBallY = FirstBallY-1;
                    FirstBallDirection = 4;
                }
            }

            if (SecondBallMove)
            {
                if (SecondBallDirection == 1)
                {
                    SecondBallX = SecondBallX-2;
                    SecondBallY = SecondBallY-5;
                }
                if (SecondBallDirection == 2)
                {
                    SecondBallX = SecondBallX+5;
                    SecondBallY = SecondBallY-1;
                }
                if (SecondBallDirection == 3)
                {
                    SecondBallX = SecondBallX+1;
                    SecondBallY = SecondBallY+5;
                }
                if (SecondBallDirection == 4)
                {
                    SecondBallX = SecondBallX-5;
                    SecondBallY = SecondBallY-2;
                }

                //������� ��� ������
                if (SecondBallX<36)
                {
                    SecondBallX++;
                    SecondBallDirection = 2;
                }
                if (SecondBallX>1365)
                {
                    SecondBallX = SecondBallX-1;
                    SecondBallDirection = 1;
                }
                if (SecondBallY<24)
                {
                    SecondBallY++;
                    SecondBallDirection = 3;
                }
                if (SecondBallY>765)
                {
                    SecondBallY = SecondBallY-1;
                    SecondBallDirection = 4;
                }
            }
            keyboardControls(&PlayerX, &PlayerY);
            txBegin();
            Drawing(Background, PlayerX, PlayerY, FirstBallX, FirstBallY, SecondBallX, SecondBallY);
            txEnd();
        }
    }

    void keyboardControls(int *PlayerX, int *PlayerY)
    {
        bool CollisionMove = true;
        int PlayerDirection;

        if (GetAsyncKeyState('W'))
        {
            if (*PlayerY > 0)
            {
                *PlayerY = *PlayerY-5;
            }
        }

        if (GetAsyncKeyState('S'))
        {
            if (*PlayerY+60 < 800)
            {
                *PlayerY = *PlayerY+5;
            }
        }

        if (GetAsyncKeyState('A'))
        {
            if (*PlayerX > 0)
            {
                *PlayerX = *PlayerX-5;
            }
        }

        if (GetAsyncKeyState('D'))
        {
            if (*PlayerX+60 < 1400)
            {
             *PlayerX = *PlayerX+5;
            }
        }
    }

    void Drawing(HDC Background, int PlayerX, int PlayerY, int FirstBallX, int FirstBallY, int SecondBallX, int SecondBallY)
    {
        Sleep(0.001);
        txSetFillColor(TX_WHITE);
        txClear();

        txBitBlt(txDC(), 0, 0, 1400, 800, Background, 0, 0);

        POINT Player [4] = {{PlayerX, PlayerY}, {PlayerX+60, PlayerY}, {PlayerX+60, PlayerY+60}, {PlayerX, PlayerY+60}};
        txSetColor(RGB(0, 0, 0));
        txSetFillColor (RGB(0, 0, 0));
        txPolygon(Player, 4);

        txSetFillColor (RGB(255, 0, 0));
        txCircle(FirstBallX, FirstBallY, 24);
        txSetFillColor (RGB(0, 0, 0));
        txCircle(SecondBallX, SecondBallY, 24);
    }
