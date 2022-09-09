    #include "TXlib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    using namespace std;

    int main()
        {
            int windowX, windowY;
            cout<< "¬ведите ширину холста \n";
            cin>> windowX;
            cout<< "¬ведите высоту холста \n";
            cin>> windowY;

            if (windowX<255)
            {
                windowX = 255;
            } else {
            int tmp = windowX/255;
            windowX = 255*tmp;
            }

            txCreateWindow (windowX, windowY);

            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);

            int R = 0;
            int G = 0;
            int B = 0;
            int a = 0;
            int k = (windowX/255);

            cout<< k;

            for(int i = 0; i < windowX; i++)
            {
                txSetColor(RGB(R,G,B)) ;
                txLine(a, 0, a, windowY);
                a++;
                txSleep(0.5);

                if (i%(1*k)==0)
                {
                    R++;
                    G++;
                    B++;
                }
            }
            return 0;
        }

