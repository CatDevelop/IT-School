    #include "TXLib.h"

    void drawCar(int x, int y, int scale);

    int main( )
        {
            txCreateWindow (1400, 800);

            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);

            int scale=1;
            int x=100;
            int y=250;


            drawCar(x, y, scale);

            return 0;
        }

    void drawCar(int x, int y, int scale)
    {
        txSetColour(TX_BLACK);
        txCircle(x+(63*scale), y*scale, 20*scale);
        txCircle(x+(187*scale), y*scale, 20*scale);
        txCircle(x+(125*scale), y-100, 40*scale);
        txRectangle(x, y-100, x+(250*scale), y*scale);
    }
