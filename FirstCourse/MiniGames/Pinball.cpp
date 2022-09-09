    #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void painting(HDC Background,  HDC FirstPlayer, HDC SecondPlayer, int BallX, int BallY, int FirstPlayerX, int FirstPlayerY, int SecondPlayerX, int SecondPlayerY, char* ScoreFirstPlayer, char* ScoreSecondPlayer);
    void keyboardControls(int *FirstPlayerY, int *SecondPlayerY);

    int main()
    {
        txCreateWindow(1400, 800);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        HDC Background = txLoadImage("Resources\\FirstProject\\Background.bmp");
        HDC FirstPlayer = txLoadImage("Resources\\FirstProject\\FirstPlayer.bmp");
        HDC SecondPlayer = txLoadImage("Resources\\FirstProject\\SecondPlayer.bmp");

        int BallX = 700;
        int BallY = 400;
        int BallDirection = 1;
        int FirstPlayerX = 30;
        int FirstPlayerY = 350; 
        int SecondPlayerX = 1345;  
        int SecondPlayerY = 350;
        int Win = 0;

        char ScoreFirstPlayer[2] = "0";
        char ScoreSecondPlayer[2] = "0";
          
        srand(time(NULL));
        while(TRUE)
        {
            Sleep(0.001);
            txClear();
            

            //Выигрыш
            if(ScoreFirstPlayer[0] == '9')
            {
                Win = 1;
            }
            if(ScoreSecondPlayer[0] == '9')
            {
                Win = 2;
            }
            if (Win != 0)
            {
                break;
            }


            //Движение мячика
            if (BallDirection == 1)
            {
                BallX = BallX-2;
                BallY = BallY-5;
            }
            if (BallDirection == 2)
            {
                BallX = BallX+5;
                BallY = BallY-1;
            }
            if (BallDirection == 3)
            {
                BallX = BallX+1;
                BallY = BallY+5;
            }
            if (BallDirection == 4)
            {
                BallX = BallX-5;
                BallY = BallY-2;
            }


            //Границы для шарика
            if (BallX<36)
            {
                BallX++;
                BallDirection = 2;
                ScoreSecondPlayer[0] = ScoreSecondPlayer[0]+1;
            }
            if (BallX>1365)
            {
                BallX = BallX-1;
                BallDirection = 1;
                ScoreFirstPlayer[0] = ScoreFirstPlayer[0]+1;
            }
            if (BallY<36)
            {
                BallY++;
                BallDirection = 3;
            }
            if (BallY>765)
            {
                BallY = BallY-1;
                BallDirection = 4;
            }


            //Отбивание мячика ракеткой
            if (BallX-35<55)
            {
                if (BallY+35>FirstPlayerY and BallY-35<FirstPlayerY+100)
                {
                    BallX++;
                    BallDirection = 2;
                }
            }
            if (BallX+35>SecondPlayerX)
            {
                if (BallY+35>SecondPlayerY and BallY-35<SecondPlayerY+100)
                {
                    BallX = BallX-1;
                    BallDirection = 1;
                }
            }

            txBegin();
            painting(Background, FirstPlayer, SecondPlayer, BallX, BallY, FirstPlayerX, FirstPlayerY, SecondPlayerX, SecondPlayerY, ScoreFirstPlayer, ScoreSecondPlayer);
            txEnd();

            keyboardControls(&FirstPlayerY, &SecondPlayerY);
        }
        txSetFillColor(TX_WHITE);
        txClear();

        txSetColor(RGB(0, 0, 0));
        txSelectFont("Arial", 100, 0, FW_BOLD);
        if (Win == 1)
        {
            txDrawText(0, 0, 1400, 800, "First player win!");
            txDeleteDC (Background);
            txDeleteDC (FirstPlayer);
            txDeleteDC (SecondPlayer);
        }
        if (Win == 2)
        {
            txDrawText(0, 0, 1400, 800, "Second player win!");
            txDeleteDC (Background);
            txDeleteDC (FirstPlayer);
            txDeleteDC (SecondPlayer);
        }     
    }

    void painting(HDC Background,  HDC FirstPlayer, HDC SecondPlayer, int BallX, int BallY, int FirstPlayerX, int FirstPlayerY, int SecondPlayerX, int SecondPlayerY, char* ScoreFirstPlayer, char* ScoreSecondPlayer)
    {
        txBitBlt(txDC(), 0, 0, 1400, 800, Background, 0, 0);
        txAlphaBlend(txDC(), FirstPlayerX, FirstPlayerY, 25, 100, FirstPlayer, 0, 0, 1);
        txAlphaBlend(txDC(), SecondPlayerX, SecondPlayerY, 25, 100, SecondPlayer, 0, 0, 1);

        txSetColor(RGB(205, 96, 196));
        txSetFillColor(RGB(205, 96, 196));
        txCircle(BallX, BallY, 35);

        txSetFillColor(RGB(0, 0, 0));
        txSetColor(RGB(255, 255, 255));
        txSelectFont("Arial", 60, 0, FW_BOLD);

        txDrawText(0, 0, 60, 60, &ScoreFirstPlayer[0]);
        txDrawText(1360, 0, 1400, 60, &ScoreSecondPlayer[0]);
    }

    void keyboardControls(int *FirstPlayerY, int *SecondPlayerY)
    {
        if (GetAsyncKeyState('W'))
        {
            if (*FirstPlayerY > 0)
            {
                *FirstPlayerY = *FirstPlayerY-10;  
            }         
        }

        if (GetAsyncKeyState('S'))
        {
            if (*FirstPlayerY < 700)
            {
             *FirstPlayerY = *FirstPlayerY+10;     
            }     
        }

        if (GetAsyncKeyState(VK_UP))
        {
            if (*SecondPlayerY > 0)
            {
                *SecondPlayerY = *SecondPlayerY-10;   
            }       
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            if (*SecondPlayerY < 700)
            {
                *SecondPlayerY = *SecondPlayerY+10; 
            }
        }
    }