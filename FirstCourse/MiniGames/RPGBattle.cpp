    #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void keyboardControls(HDC FirstPlayer1, HDC FirstPlayer2, HDC FirstPlayer3, HDC SecondPlayer1, HDC SecondPlayer2, HDC SecondPlayer3, int *FirstPlayerAnimation, int *SecondPlayerAnimation, int *FirstPlayerHP, int *SecondPlayerHP, char *FirstPlayerHPText, char *SecondPlayerHPText);
    void Drawing(HDC FirstPlayer1, HDC FirstPlayer2, HDC FirstPlayer3, HDC SecondPlayer1, HDC SecondPlayer2, HDC SecondPlayer3, int FirstPlayerAnimation, int SecondPlayerAnimation, char *FirstPlayerHPText, char *SecondPlayerHPText);

    int main()
    {
        txCreateWindow(1400, 800);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        HDC FirstPlayer1 = txLoadImage("Resources\\FourthProject\\FirstPlayer1.bmp");
        HDC FirstPlayer2 = txLoadImage("Resources\\FourthProject\\FirstPlayer2.bmp");
        HDC FirstPlayer3 = txLoadImage("Resources\\FourthProject\\FirstPlayer3.bmp");

        HDC SecondPlayer1 = txLoadImage("Resources\\FourthProject\\SecondPlayer1.bmp");
        HDC SecondPlayer2 = txLoadImage("Resources\\FourthProject\\SecondPlayer2.bmp");
        HDC SecondPlayer3 = txLoadImage("Resources\\FourthProject\\SecondPlayer3.bmp");

        int FirstPlayerAnimation = 1;
        int SecondPlayerAnimation = 1;

        int FirstPlayerHP = 500;
        int SecondPlayerHP = 500;

        char FirstPlayerHPText[5];
        char SecondPlayerHPText[5];

        srand(time(NULL));
        while(true)
        {
            keyboardControls(FirstPlayer1, FirstPlayer2, FirstPlayer3, SecondPlayer1, SecondPlayer2, SecondPlayer3, &FirstPlayerAnimation, &SecondPlayerAnimation, &FirstPlayerHP, &SecondPlayerHP, FirstPlayerHPText, SecondPlayerHPText);

            itoa(FirstPlayerHP, FirstPlayerHPText, 10);
            itoa(SecondPlayerHP, SecondPlayerHPText, 10);
            txBegin();
            Drawing(FirstPlayer1, FirstPlayer2, FirstPlayer3, SecondPlayer1, SecondPlayer2, SecondPlayer3, FirstPlayerAnimation, SecondPlayerAnimation, FirstPlayerHPText, SecondPlayerHPText);
            txEnd();
        }
    }

    void Drawing(HDC FirstPlayer1, HDC FirstPlayer2, HDC FirstPlayer3, HDC SecondPlayer1, HDC SecondPlayer2, HDC SecondPlayer3, int FirstPlayerAnimation, int SecondPlayerAnimation, char *FirstPlayerHPText, char *SecondPlayerHPText)
    {
        txSetFillColor(TX_WHITE);
        txClear();

        if(FirstPlayerAnimation == 1)
        {
            txBitBlt(txDC(), 400, 250, 198, 279, FirstPlayer1, 0, 0);
        }

        if(FirstPlayerAnimation == 2)
        {
            txBitBlt(txDC(), 556, 250, 234, 270, FirstPlayer2, 0, 0);
        }

        if(FirstPlayerAnimation == 3)
        {
            txBitBlt(txDC(), 556, 250, 234, 270, FirstPlayer3, 0, 0);
        }

        if(SecondPlayerAnimation == 1)
        {
            txBitBlt(txDC(), 802, 250, 198, 270, SecondPlayer1, 0, 0);
        }

        if(SecondPlayerAnimation == 2)
        {
            txBitBlt(txDC(), 601, 250, 234, 252, SecondPlayer2, 0, 0);
        }

        if(SecondPlayerAnimation == 3)
        {
            txBitBlt(txDC(), 601, 250, 234, 252, SecondPlayer3, 0, 0);
        }

        txSetColor(RGB(255, 0, 0));
        txSelectFont("Arial", 60, 0, FW_BOLD);
        txTextOut(470, 170, &FirstPlayerHPText[0]);
        txTextOut(840, 170, &SecondPlayerHPText[0]);
    }

    void keyboardControls(HDC FirstPlayer1, HDC FirstPlayer2, HDC FirstPlayer3, HDC SecondPlayer1, HDC SecondPlayer2, HDC SecondPlayer3, int *FirstPlayerAnimation, int *SecondPlayerAnimation, int *FirstPlayerHP, int *SecondPlayerHP, char *FirstPlayerHPText, char *SecondPlayerHPText)
    {
        int MinusHP;
        char MinusHPText[5];
        if (GetAsyncKeyState(VK_LEFT))
        {
            if(rand()%6+1 == 20)
            {
                MinusHP = ((rand()%8+96)*(-1))*2;
                *SecondPlayerHP = *SecondPlayerHP + MinusHP;

                *FirstPlayerAnimation = 3;
                Drawing(FirstPlayer1, FirstPlayer2, FirstPlayer3, SecondPlayer1, SecondPlayer2, SecondPlayer3, *FirstPlayerAnimation, *SecondPlayerAnimation, FirstPlayerHPText, SecondPlayerHPText);

                txSetColor(RGB(255, 0, 0));
                txSelectFont("Arial", 60, 0, FW_BOLD);
                itoa(MinusHP, MinusHPText, 10);
                txTextOut(1200, 300, &MinusHPText[0]);
                Sleep(500);
                *FirstPlayerAnimation = 1;
            }else{
                MinusHP = (rand()%8+96)*(-1);
                *SecondPlayerHP = *SecondPlayerHP + MinusHP;

                *FirstPlayerAnimation = 2;
                Drawing(FirstPlayer1, FirstPlayer2, FirstPlayer3, SecondPlayer1, SecondPlayer2, SecondPlayer3, *FirstPlayerAnimation, *SecondPlayerAnimation, FirstPlayerHPText, SecondPlayerHPText);

                txSetColor(RGB(255, 0, 0));
                txSelectFont("Arial", 60, 0, FW_BOLD);
                itoa(MinusHP, MinusHPText, 10);
                txTextOut(1200, 300, &MinusHPText[0]);

                Sleep(500);
                *FirstPlayerAnimation = 1;
            }
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            if(rand()%21+1 == 20)
            {
                MinusHP = ((rand()%8+96)*(-1))*2;
                *FirstPlayerHP = *FirstPlayerHP + MinusHP;

                *SecondPlayerAnimation = 3;
                Drawing(FirstPlayer1, FirstPlayer2, FirstPlayer3, SecondPlayer1, SecondPlayer2, SecondPlayer3, *FirstPlayerAnimation, *SecondPlayerAnimation, FirstPlayerHPText, SecondPlayerHPText);

                txSetColor(RGB(255, 0, 0));
                txSelectFont("Arial", 60, 0, FW_BOLD);
                itoa(MinusHP, MinusHPText, 10);
                txTextOut(200, 300, &MinusHPText[0]);

                Sleep(500);
                *SecondPlayerAnimation = 1;
            }else{
                MinusHP = (rand()%8+96)*(-1);
                *FirstPlayerHP = *FirstPlayerHP + MinusHP;

                *SecondPlayerAnimation = 2;
                Drawing(FirstPlayer1, FirstPlayer2, FirstPlayer3, SecondPlayer1, SecondPlayer2, SecondPlayer3, *FirstPlayerAnimation, *SecondPlayerAnimation, FirstPlayerHPText, SecondPlayerHPText);

                txSetColor(RGB(255, 0, 0));
                txSelectFont("Arial", 60, 0, FW_BOLD);
                itoa(MinusHP, MinusHPText, 10);
                txTextOut(200, 300, &MinusHPText[0]);

                Sleep(500);
                *SecondPlayerAnimation = 1;
            }
        }
    }





