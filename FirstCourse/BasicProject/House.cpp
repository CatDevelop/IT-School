    #include "TXLib.h"

    int main( )
    {
        txCreateWindow (1300, 600);
        txSetFillColor (RGB (20, 118, 255));
        txFloodFill(0, 0, FLOODFILLBORDER);

        POINT ground [4] = {{0, 595},{1300, 595},{1300, 600},{0, 600}};

        txSetColor(TX_GREEN);
        txSetFillColor (TX_GREEN);
        txPolygon(ground, 4);

        POINT Base1 [4] = {{10, 595},{10, 405},{50, 405},{50, 595}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base1, 4);

        POINT Base2 [4] = {{50, 405},{106, 415},{106, 600},{50, 595}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base2, 4);

        POINT Base3 [4] = {{106, 415},{290, 415},{290, 600},{106, 600}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base3, 4);

        POINT Base4 [4] = {{290, 415},{350, 405},{350, 595},{290, 600}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base4, 4);

        POINT Base5 [4] = {{350, 405}, {410, 405}, {410, 595}, {350, 595}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base5, 4);


        POINT Base6 [9] = {{410, 595}, {410, 330}, {440, 330}, {392, 330}, {510, 230}, {620, 330}, {580, 330}, {610, 330}, {610, 595}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base6, 9);

        POINT Base7 [9] = {{790, 595}, {790, 420}, {825, 420}, {775, 420}, {950, 265}, {1110, 420}, {1065, 420}, {1095, 420}, {1095, 595}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base7, 9);


        POINT Base8 [7] = {{610, 595}, {610, 430}, {760, 430}, {915, 280}, {950, 265}, {775, 420}, {775, 595}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base8, 7);

        POINT Base9 [4] = {{775, 595}, {775, 420}, {795, 420}, {795, 595}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base9, 4);

        txLine(775, 420, 760, 430);

        POINT Base10 [6] = {{1285, 595}, {1095, 595}, {1095, 420}, {1110, 420}, {1079, 390}, {1285, 390}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Base10, 6);

        POINT Roof1 [23] = {{0, 405}, {550, 125}, {700, 125}, {730, 150}, {780, 115}, {1295, 390}, {1079, 390}, {950, 265}, {915, 280}, {910, 290}, {760, 430}, {610, 430},  {610, 330},  {620, 330},  {510, 235},  {392, 330}, {410, 330},  {410, 405},  {350, 405},  {290, 415},  {105, 415},  {50, 405}, {0, 405}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Roof1, 23);

        txLine(220, 293, 50, 405);
        txLine(220, 293, 105, 415);
        txLine(220, 293, 290, 415);
        txLine(220, 293, 350, 405);

        POINT Tube [4] = {{385, 210}, {385, 110}, {445, 110}, {445, 179}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Tube, 4);

        POINT Roof2 [13] = {{610, 430}, {610, 330}, {620, 330}, {580, 296}, {580, 260}, {600, 260}, {555, 260}, {700, 145}, {835, 260}, {800, 260}, {820, 260}, {820, 373}, {760, 430}};

        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Roof2, 13);

        txLine(730, 150, 715, 160);
        txLine(910, 290, 820, 290);
        txLine(890, 290, 966, 214);

        POINT Roof3 [14] = {{966, 214}, {1185, 297}, {1160, 297}, {1160, 318}};
        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Roof3, 4);

        POINT Window1 [4] = {{60, 560}, {60, 435}, {90, 445}, {90, 565}};
        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Window1, 4);

        POINT Window2 [4] = {{140, 445}, {140, 565}, {255, 565}, {255, 445}};
        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Window2, 4);

        POINT Window3 [4] = {{300, 565}, {300, 445}, {335, 435}, {335, 560}};
        txSetColor(TX_BLACK);
        txSetFillColor (TX_WHITE);
        txPolygon(Window3, 4);

        txLine(60, 530, 90, 535);
        txLine(140, 535, 255, 535);
        txLine(300, 535, 335, 530);

        txRectangle(620, 440, 750, 560);
        txRectangle(650, 440, 720, 560);
        txLine(620, 465, 750, 465);
        txLine(620, 520, 750, 520);

        txRectangle(460, 595, 560, 355);
        txRectangle(460, 570, 560, 355);
        txRectangle(475, 465, 545, 570);
        txRectangle(460, 455, 560, 400);
        txRectangle(475, 465, 545, 480);
        txRectangle(490, 490, 505, 535);
        txRectangle(515, 490, 530, 535);

        txLine(660, 385, 745, 385);
        txRectangle(670, 386, 735, 300);
        txLine(670, 345, 735, 345);

        txRectangle(930, 330, 965, 370);
        txRectangle(910, 560, 980, 430);
        txLine(910, 520, 980, 520);
        txLine(910, 450, 980, 450);




        txSetFillColor (TX_YELLOW);
        txSetColor(TX_YELLOW);
        txCircle(1170, 70, 40);


        txSetColor(TX_BLACK);
        txLine(50, 180, 70, 200);
        txLine(70, 200, 80, 170);

        txLine(125, 170, 145, 190);
        txLine(145, 190, 160, 160);

        txLine(90, 135, 115, 165);
        txLine(115, 165, 135, 140);

        return 0;
    }


