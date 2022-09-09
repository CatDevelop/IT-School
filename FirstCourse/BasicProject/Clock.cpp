#include "TXlib.h"
#include <math.h>

double searchX(double x1, double x0, double y1, double y0, double ugol);
double searchY(double x1, double x0, double y1, double y0, double ugol);
void drawClock(double x0, double y0, double y1, int clockScale);

int main(){
    txCreateWindow(1400, 700);
    txSetFillColor(TX_WHITE);
    txClear();
    int clockScale = 2;
    double x0 = 700;
    double x1 = 700;
    double y0 = 350;
    double y1 = y0+(-67*clockScale)+5;
    double angle0 = 0;
    double angle1 = 0;
    double angle2 = 0;
    int i = 1;
    while(1==1){
        txSetFillColor(TX_WHITE);
        txClear();
        drawClock(x0, y0, y1, clockScale);
        txSetColour(TX_WHITE, 1*clockScale);
        txLine(x0, y0, searchX(x1, x0, y1+(5*clockScale), y0, angle0), searchY(x1, x0, y1+(5*clockScale), y0, angle0));
        txSetColour(TX_WHITE, 2*clockScale);
        txLine(x0, y0, searchX(x1, x0, y1+(15*clockScale), y0, angle1), searchY(x1, x0, y1+(15*clockScale), y0, angle1));
        txSetColour(TX_WHITE, 3*clockScale);
        txLine(x0, y0, searchX(x1, x0, y1+(30*clockScale), y0, angle2), searchY(x1, x0, y1+(30*clockScale), y0, angle2));

        if(i%60==0){
            angle1=angle1+6;
        }

        if(i%3600==0){
            angle2=angle2+6;
        }

        i++;
        angle0 = angle0+6;
        txSleep(1000);
        txClear();

    }



}

double searchX(double x1, double x0, double y1, double y0, double ugol){
    double x2 = (x1-x0)*cos(ugol*M_PI/180)-(y1-y0)*sin(ugol*M_PI/180)+x0;
    return x2;
}
double searchY(double x1, double x0, double y1, double y0, double ugol){
    double y2 = (x1-x0)*sin(ugol*M_PI/180)+(y1-y0)*cos(ugol*M_PI/180)+y0;
    return y2;
}
void drawClock(double x, double y, double y1, int clockScale)
{
    POINT clockBase [10] = {{x+(-77*clockScale), y+(-20*clockScale)}, {x+(-17*clockScale), y+(-67*clockScale)}, {x+(52*clockScale), y+(-67*clockScale)}, {x+(56*clockScale), y+(-62*clockScale)}, {x+(70*clockScale), y+(-6*clockScale)}, {x+(70*clockScale), y+(6*clockScale)}, {x+(40*clockScale), y+(58*clockScale)}, {x+(31*clockScale), y+(67*clockScale)}, {x+(-54*clockScale), y+(67*clockScale)}, {x+(-77*clockScale), y+(-12*clockScale)}, };
    txSetColor(RGB(54, 52, 53));
    txSetFillColor (RGB(54, 52, 53));
    txPolygon(clockBase, 10);

    POINT box1 [4] = {{x+(-182*clockScale), y+(15*clockScale)}, {x+(-155*clockScale), y+(-18*clockScale)}, {x+(-105*clockScale), y+(22*clockScale)}, {x+(-132*clockScale), y+(52*clockScale)}, };
    txSetColor(RGB(42, 42, 41));
    txSetFillColor (RGB(42, 42, 41));
    txPolygon(box1, 4);

    POINT box2 [4] = {{x+(-152*clockScale), y+(44*clockScale)}, {x+(-95*clockScale), y+(65*clockScale)}, {x+(-108*clockScale), y+(99*clockScale)}, {x+(-166*clockScale), y+(77*clockScale)}, };
    txSetColor(RGB(18, 20, 19));
    txSetFillColor (RGB(18, 20, 19));
    txPolygon(box2, 4);

    POINT box3 [4] = {{x+(-109*clockScale), y+(5*clockScale)}, {x+(-75*clockScale), y+(-4*clockScale)}, {x+(-57*clockScale), y+(58*clockScale)}, {x+(-95*clockScale), y+(65*clockScale)}, };
    txSetColor(RGB(61, 60, 58));
    txSetFillColor (RGB(61, 60, 58));
    txPolygon(box3, 4);

    POINT box4 [4] = {{x+(-68*clockScale), y+(69*clockScale)}, {x+(-23*clockScale), y+(110*clockScale)}, {x+(-45*clockScale), y+(138*clockScale)}, {x+(-91*clockScale), y+(97*clockScale)}};
    txSetColor(RGB(18, 20, 19));
    txSetFillColor (RGB(18, 20, 19));
    txPolygon(box4, 4);

    POINT box5 [4] = {{x+(-32*clockScale), y+(102*clockScale)}, {x+(31*clockScale), y+(102*clockScale)}, {x+(31*clockScale), y+(67*clockScale)}, {x+(-32*clockScale), y+(67*clockScale)}, };
    txSetColor(RGB(154, 153, 158));
    txSetFillColor (RGB(154, 153, 158));
    txPolygon(box5, 4);

    POINT box6 [4] = {{x+(40*clockScale), y+(58*clockScale)}, {x+(70*clockScale), y+(6*clockScale)}, {x+(99*clockScale), y+(22*clockScale)}, {x+(70*clockScale), y+(75*clockScale)}, };
    txSetColor(RGB(84, 82, 87));
    txSetFillColor (RGB(84, 82, 87));
    txPolygon(box6, 4);

    POINT box7 [4] = {{x+(70*clockScale), y+(-3*clockScale)}, {x+(104*clockScale), y+(-11*clockScale)}, {x+(90*clockScale), y+(-71*clockScale)}, {x+(56*clockScale), y+(-62*clockScale)}, };
    txSetColor(RGB(18, 20, 19));
    txSetFillColor (RGB(18, 20, 19));
    txPolygon(box7, 4);

    POINT box8 [4] = {{x+(90*clockScale), y+(-71*clockScale)}, {x+(104*clockScale), y+(-106*clockScale)}, {x+(163*clockScale), y+(-84*clockScale)}, {x+(149*clockScale), y+(-50*clockScale)}, };
    txSetColor(RGB(85, 83, 88));
    txSetFillColor (RGB(85, 83, 88));
    txPolygon(box8, 4);

    POINT box9 [4] = {{x+(127*clockScale), y+(-59*clockScale)}, {x+(101*clockScale), y+(-28*clockScale)}, {x+(152*clockScale), y+(11*clockScale)}, {x+(177*clockScale), y+(-18*clockScale)}, };
    txSetColor(RGB(60, 59, 57));
    txSetFillColor (RGB(60, 59, 57));
    txPolygon(box9, 4);

    POINT box10 [4] = {{x+(-12*clockScale), y+(-67*clockScale)}, {x+(-12*clockScale), y+(-104*clockScale)}, {x+(51*clockScale), y+(-104*clockScale)}, {x+(51*clockScale), y+(-67*clockScale)}, };
    txSetColor(RGB(18, 20, 19));
    txSetFillColor (RGB(18, 20, 19));
    txPolygon(box10, 4);

    POINT box11 [4] = {{x+(33*clockScale), y+(-104*clockScale)}, {x+(11*clockScale), y+(-134*clockScale)}, {x+(66*clockScale), y+(-169*clockScale)}, {x+(85*clockScale), y+(-139*clockScale)}, };
    txSetColor(RGB(111, 110, 116));
    txSetFillColor (RGB(111, 110, 116));
    txPolygon(box11, 4);

    POINT box12 [4] = {{x+(-11*clockScale), y+(-104*clockScale)}, {x+(-42*clockScale), y+(-127*clockScale)}, {x+(-3*clockScale), y+(-176*clockScale)}, {x+(25*clockScale), y+(-154*clockScale)}, };
    txSetColor(RGB(115, 114, 120));
    txSetFillColor (RGB(115, 114, 120));
    txPolygon(box12, 4);

    POINT box13 [4] = {{x+(-62*clockScale), y+(-74*clockScale)}, {x+(-97*clockScale), y+(-89*clockScale)}, {x+(-75*clockScale), y+(-148*clockScale)}, {x+(-40*clockScale), y+(-134*clockScale)}, };
    txSetColor(RGB(18, 20, 19));
    txSetFillColor (RGB(18, 20, 19));
    txPolygon(box13, 4);

    POINT box14 [4] = {{x+(-74*clockScale), y+(-20*clockScale)}, {x+(-96*clockScale), y+(-46*clockScale)}, {x+(-49*clockScale), y+(-84*clockScale)}, {x+(-27*clockScale), y+(-58*clockScale)}, };
    txSetColor(RGB(18, 20, 19));
    txSetFillColor (RGB(18, 20, 19));
    txPolygon(box14, 4);
}
