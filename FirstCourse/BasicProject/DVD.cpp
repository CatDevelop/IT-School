        #include "TXLib.h"
        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>

    void drawSmile(int x, int y, COLORREF COLOR);

    int main()
        {
            txCreateWindow (1280, 720);

            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);

            COLORREF COLOR1, COLOR2, COLORTMP;
            int x1 = 675;
            int x2 = 535;
            int y1 = 360;
            int y2 = 360;
            int direction1 = 1;
            int direction2 = 4;
            int i = 1;

            txBegin();
            srand(time(NULL));
            while(true==true)
            {
                drawSmile(x1, y1, COLOR1);
                drawSmile(x2, y2, COLOR2);

                txSleep(1);
                txSetFillColor(TX_WHITE);
                txClear();


            //
                if (direction1 == 1)
                {
                    x1 = x1-2;
                    y1 = y1-5;
                }
                if (direction1 == 2)
                {
                    x1 = x1+5;
                    y1 = y1-1;
                }
                if (direction1 == 3)
                {
                    x1 = x1+1;
                    y1 = y1+5;
                }
                if (direction1 == 4)
                {
                    x1 = x1-5;
                    y1 = y1-2;
                }



            //
                if (direction2 == 1)
                {
                    x2 = x2-1;
                    y2 = y2-5;
                }
                if (direction2 == 2)
                {
                    x2 = x2+5;
                    y2 = y2+2;
                }
                if (direction2 == 3)
                {
                    x2 = x2+2;
                    y2 = y2+5;
                }
                if (direction2 == 4)
                {
                    x2 = x2-5;
                    y2 = y2-1;
                }



            //
                if (x1<36)
                {
                    x1++;
                    COLOR1 = RGB(rand(), rand(), rand());
                    direction1 = 2;
                    //srand(time(NULL));
                }
                if (x1>1245)
                {
                    x1 = x1-1;
                    COLOR1 = RGB(rand(), rand(), rand());
                    direction1 = 1;
                    //srand(time(NULL));
                }
                if (y1<36)
                {
                    y1++;
                    COLOR1 = RGB(rand(), rand(), rand());
                    direction1 = 3;
                    //srand(time(NULL));
                }
                if (y1>685)
                {
                    y1 = y1-1;
                    COLOR1 = RGB(rand(), rand(), rand());
                    direction1 = 4;
                    //srand(time(NULL));
                }



            //
                if (x2<36)
                {
                    x2++;
                    COLOR2 = RGB(rand(), rand(), rand());
                    direction2 = 3;
                   // srand(time(NULL));
                }
                if (x2>1245)
                {
                    x2 = x2-1;
                    COLOR2 = RGB(rand(), rand(), rand());
                    direction2 = 4;
                    //srand(time(NULL));
                }
                if (y2<36)
                {
                    y2++;
                    COLOR2 = RGB(rand(), rand(), rand());
                   // srand(time(NULL));
                    direction2 = 2;
                }
                if (y2>685)
                {
                    y2 = y2-1;
                    COLOR2 = RGB(rand(), rand(), rand());
                   // srand(time(NULL));
                    direction2 = 1;
                }



            //
                if (sqrt(pow((x2-x1), 2)+pow((y2-y1), 2))<70)
                {
                    COLORTMP = COLOR1;
                    COLOR1 = COLOR2;
                    COLOR2 = COLORTMP;

                    if(direction1 == 1)
                    {
                        direction1 = 3;
                    }
                    if(direction1 == 2)
                    {
                        direction1 = 4;
                    }
                    if(direction1 == 3)
                    {
                        direction1 = 1;
                    }
                    if(direction1 == 4)
                    {
                        direction1 = 2;
                    }



                //
                    if(direction2 == 1)
                    {
                        direction2 = 4;
                    }
                    if(direction2 == 2)
                    {
                        direction2 = 1;
                    }
                    if(direction2 == 3)
                    {
                        direction2 = 2;
                    }
                    if(direction2 == 4)
                    {
                        direction2 = 3;
                    }
                }
                i++;
            }
            txEnd();
            return 0;
        }

    void drawSmile(int x, int y, COLORREF COLOR)
    {
        txSetColour(TX_BLACK);
        txSetFillColor(COLOR);
        txCircle(x, y, 35);
    }

