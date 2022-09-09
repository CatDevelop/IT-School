    #include "Resources\\Libs\\TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <cmath>
    #define LEN 200000

    double radioWaves(double x);

    int main()
    {
        txCreateWindow(1280, 720);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);
        txTextCursor(FALSE);

        double a, b, c = 1;
        double scale = 2;

        double array[2580];

        for(int x = 0; x < 2580; x++)
        {
            //txSetPixel(x, 360-(radioWaves(x-640)), TX_BLACK);
            array[x]=360-radioWaves(x-640);
        }

        for(int x = 645; x < 1280; x++)
        {
            txSetColor(TX_BLACK, 2);
            txLine(x, array[x], x+1, array[x+1]);
        }
    }

    double radioWaves(double x)
    {
        return sin(x)/tan(x)*x*x/10*(x/2+x-(x/2));
    }