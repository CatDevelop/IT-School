    #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void Drawing(int FirstLineX1, int FirstLineX2, int FirstLineY, int SecondLineX1, int SecondLineX2, int SecondLineY, char* NumberOfLines);
    bool PressSpace();
    bool PressArrow();

    int main()
    {
        txCreateWindow(1400, 800);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        int FirstLineX1;
        int FirstLineX2;
        int FirstLineY;

        int SecondLineX1;
        int SecondLineX2;
        int SecondLineX2Start;
        int SecondLineY;

        bool Start = false;

        char NumberOfLines[2] = "1";

        bool Space;
        bool Arrow;

        txSetColor(RGB(255, 255, 255));
        txClear();

        srand(time(NULL));
        while(TRUE)
        {
            Sleep(0.001);

            Space = PressSpace();
            Arrow = PressArrow();

            if(Space)
            {
                NumberOfLines[0] = NumberOfLines[0];
                FirstLineX1 = 10;
                FirstLineX2 = rand()%800+200;
                FirstLineY = 266;

        
                SecondLineX1 = 10;
                SecondLineX2Start = rand()%199+20;
                SecondLineX2 = SecondLineX2Start;
                SecondLineY = 533;

                while(SecondLineX2>FirstLineX2)
                {
                    FirstLineX2+1;
                    Sleep(0.001);
                }

                Start = true;
                Sleep(250);
            }

            if(Arrow)
            {
                if(SecondLineX2<FirstLineX2)
                {
                    SecondLineX2 = SecondLineX2+SecondLineX2Start-10+((SecondLineX2Start/100)*10);
                    NumberOfLines[0] = NumberOfLines[0]+1;
                    Sleep(250);
                }
            }
            
            if(Start)
            {
                Drawing(FirstLineX1, FirstLineX2, FirstLineY, SecondLineX1, SecondLineX2, SecondLineY, NumberOfLines);
            }
        }
        txSetFillColor(TX_WHITE);
        txClear();
    }

    void Drawing(int FirstLineX1, int FirstLineX2, int FirstLineY, int SecondLineX1, int SecondLineX2, int SecondLineY, char* NumberOfLines)
    {
        txBegin();
        txSetColor(RGB(255, 255, 255));
        txClear();

        txSetColor(RGB(0, 0, 0), 3);
        txLine(FirstLineX1, FirstLineY, FirstLineX2, FirstLineY);
        txLine(SecondLineX1, SecondLineY, SecondLineX2, SecondLineY);

        txSetColor(RGB(0, 0, 0));
        txSelectFont("Arial", 60, 0, FW_BOLD);
        txDrawText(0, 0, 60, 60, &NumberOfLines[0]);

        txEnd();
    }

    bool PressSpace()
    {
        if(GetAsyncKeyState(VK_SPACE))
        {
            return 1;
        }else{
            return 0;
        }
    }

    bool PressArrow()
    {
        if(GetAsyncKeyState(VK_RIGHT))
        {
            return 1;
        }else{
            return 0;
        }
    }
