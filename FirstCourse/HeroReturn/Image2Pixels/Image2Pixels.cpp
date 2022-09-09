    #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define LEN 200000

    int main()
    {
        txCreateWindow(1296, 720);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        HDC image = txLoadImage("InOutPut\\Image.bmp");
        txBitBlt(txDC(), 0, 0, 1296, 720, image, 0, 0);

        FILE *Arr;
        Arr = fopen("Saving.txt", "w+");

        COLORREF Array[1296][720];
        COLORREF Color;

        int R, G, B;
        char Text[LEN];
        char RText[LEN];
        char GText[LEN];
        char BText[LEN];

        for(int i = 0; i<721; i++)
        {
            for(int i2 = 0; i<1297; i++)
            {
                Color = txGetPixel(i2, i);
                R = GetRValue(Color);
                G = GetGValue(Color);
                B = GetBValue(Color);

                itoa(R, RText, 10);
                itoa(G, GText, 10);
                itoa(B, BText, 10);

                strcat(Text, "RGB(");
                strcat(Text, RText);
                strcat(Text, ", ");
                strcat(Text, GText);
                strcat(Text, ", ");
                strcat(Text, BText);
                strcat(Text, "), ");

                fputs(Text, Arr);
            }
        }
        fclose(Arr);
    }

