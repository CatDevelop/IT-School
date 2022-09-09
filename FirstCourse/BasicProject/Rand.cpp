    #include "TXLib.h"

    void drawSmile(int x, int y);

    int main()
        {
            txCreateWindow (1280, 720);

            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);

            int x = 535;
            int y = 360;
            int direction = 1;

            txBegin();
            while(true)
            {
                drawSmile(x, y);

                txSleep(10);
                txSetFillColor(TX_WHITE);
                txClear();

                if (direction == 1)
                {
                    x = x-5;
                }
                if (direction == 2)
                {
                    x = x+5;
                }

                if (x<36)
                {
                    direction = 2;
                }
                if (x>1245)
                {
                    direction = 1;
                }
        }
        return 0;
    }

    void drawSmile(int x, int y)
    {
        txSetColour(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txCircle(x, y, 35);
    }

