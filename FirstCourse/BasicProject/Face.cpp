    #include "TXLib.h"

    void drawFace(bool eyes);
    void drawRightHand(int hand);
    void drawLeftHand(int leftHand);

    int main( )
        {
            txCreateWindow (1400, 800);

            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);

            bool eyes = FALSE;
            drawFace(eyes);

            int leftHand, rightHand;
            std::cin>>rightHand;
            drawRightHand(rightHand);

            std::cin>>leftHand;
            drawLeftHand(leftHand);


            return 0;
        }

    void drawFace(bool eyes)
    {
        txSetColor(TX_BLACK);
        txCircle(700, 400, 100);
        txLine(700, 380, 700, 420);
        txCircle(700, 450, 20);
        if (eyes)
        {
            txCircle(750, 350, 10);
            txCircle(650, 350, 10);
        }
        else {
            txLine(740, 350, 760, 350);
            txLine(640, 350, 660, 350);
        }

    }

    void drawRightHand(int hand)
    {
        if (hand == 1)
            {
                txLine(650, 500, 550, 400);
            }
        if (hand == 2)
            {
                txLine(650, 500, 550, 500);
            }
        if (hand == 3)
            {
                txLine(650, 500, 550, 600);
            }
    }

    void drawLeftHand(int hand)
    {
        if (hand == 1)
            {
                txLine(750, 500, 850, 400);
            }
        if (hand == 2)
            {
                txLine(750, 500, 850, 500);
            }
        if (hand == 3)
            {
                txLine(750, 500, 850, 600);
            }
    }
