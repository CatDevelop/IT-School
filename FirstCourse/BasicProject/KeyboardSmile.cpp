    #include "TXLib.h"

    void drawSmile(int x, int y, bool eyes);
    void interfaceKeyboard(int *x, int *y, bool *eyes);

    int main()
    {
        txCreateWindow (1400, 800);

        txSetFillColor (TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        int x = 700;
        int y = 400;
        bool eyes = true;

        while(true)
        {
            interfaceKeyboard(&x, &y, &eyes);

            txClear();
            drawSmile(x, y, eyes);

            Sleep(1);
        }
    }

    void interfaceKeyboard(int *x, int *y, bool *eyes)
    {
        if(GetAsyncKeyState(VK_UP))
        {
            *y = *y-5;
        }

        if(GetAsyncKeyState(VK_DOWN))
        {
            *y = *y+5;
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            *x = *x+5;
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
            *x = *x-5;
        }

        if(GetAsyncKeyState(VK_SPACE))
        {
            *eyes = !*eyes;
        }
    }

    void drawSmile(int x, int y, bool eyes)
    {
        txSetColour(TX_BLACK);
        txSetFillColor(TX_WHITE);
        txCircle(x, y, 50);
        if (eyes)
        {
            txCircle(x-10, y-5, 7);
            txCircle(x+10, y-5, 7);
        }else{
            txLine(x-10, y-5, x-5, y-5);
            txLine(x+10, y-5, x+5, y-5);
        }
    }
