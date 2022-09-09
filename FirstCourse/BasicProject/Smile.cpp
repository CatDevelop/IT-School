    #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    using namespace std;

    void drawSmile(int x, int y, int r, int i, int i2, COLORREF color);
    int countSmile(int size, int r);

    int main()
        {
            int windowX, windowY;
            int size, r, countX, countY, r1, r2, r3;
            COLORREF color;
            cout<< "¬ведите ширину холста \n";
            cin>> windowX;
            cout<< "¬ведите высоту холста \n";
            cin>> windowY;
            cout<< "¬ведите радиус смайликов \n";
            cin>> r;


            txCreateWindow (windowX, windowY);

            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);

            countX = countSmile(windowX, r);
            countY = countSmile(windowY, r);

            for(int i=0; i<countY; i++)
            {

                for(int i2=0; i2<countX; i2++)
                {
                srand(time(NULL));
                r1=rand()%256;
                srand(time(NULL));
                r2=rand()%256;
                srand(time(NULL));
                r3=rand()%256;
                color = RGB(r1, r2, r3);

                    drawSmile(0, 0, r, i, i2, color);
                }
            }
            return 0;
        }
    void srand();
    int countSmile(int size, int r)
    {
        int c;
        c = size/((r*2)+(r/4));
        return c;
    }


    void drawSmile(int x, int y, int r, int i, int i2, COLORREF color)
    {
        txSetColour(TX_BLACK);
        txSetFillColor(color);
        txCircle(x+(r/4)+r+(i2*(r/4)+(r*i2*2)), y+(r/4)+r+(i*(r/4))+(r*2*i), r);
    }

