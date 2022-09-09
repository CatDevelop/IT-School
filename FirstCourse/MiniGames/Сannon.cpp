     #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void Painting(double GunX0, double GunX1, double GunY0, double GunY1, double GunAngle, double BallX, int BallY, bool Ball, int Strength, double TargetX, double TargetY);
    void KeyboardControls(double GunX0, double GunX1, double GunY0, double GunY1, double *GunAngle, double *BallX, int *BallY, double *BallAngle, double *Time, bool *Ball, int *Strength);
    void BallMovement(double *BallX, int *BallY, double BallAngle, double Time, double BallV0);

    double SearchX(double GunX1, double GunX0, double GunY1, double GunY0, double GunAngle);
    double SearchY(double GunX1, double GunX0, double GunY1, double GunY0, double GunAngle);

    int main()
    {
        txCreateWindow(1400, 800);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        double GunX0 = 140;
        double GunX1 = 140;
        double GunY0 = 800;
        double GunY1 = GunY0-180;
        double GunAngle = 0;

        int Strength = 1;

        double BallX;
        int BallY;
        double BallAngle = 0;
        double Time = 0;
        double BallV0 = 200;
        bool Ball = false;

        double TargetX = 1345;
        double TargetY = rand()%750+50;

        while(true)
        {
            //Сила удара
            if(Strength == 1)
            {
                BallV0 = 50;
            }
            if(Strength == 2)
            {
                BallV0 = 100;
            }
            if(Strength == 3)
            {
                BallV0 = 150;
            }
            if(Strength == 4)
            {
                BallV0 = 200;
            }

            //Удаление шарика, если он вылетел за границу
            if(BallX < 0 or BallX > 1400 or BallY > 800)
            {
                Ball = false;
            }

            //Попадание в мишень
            if(Ball == TRUE)
            {
                if(BallX > 1050 and BallX < 1410)
                {
                    if (725+BallY > TargetY-25 and 725+BallY < TargetY+25)
                    {
                        TargetY = rand()%750+50;
                        Ball = false;
                        Sleep(100);
                    }
                }
            }

            BallMovement(&BallX, &BallY, BallAngle, Time, BallV0);
            Time = Time+0.1;

            txBegin();
            Painting(GunX0, GunX1, GunY0, GunY1, GunAngle, BallX+SearchX(GunX1, GunX0, GunY1, GunY0, GunAngle), BallY+SearchY(GunX1, GunX0, GunY1, GunY0, GunAngle), Ball, Strength, TargetX, TargetY);
            txEnd();
            KeyboardControls(GunX0, GunX1, GunY0, GunY1, &GunAngle, &BallX, &BallY, &BallAngle, &Time, &Ball, &Strength);
        }
    }

    void Painting(double GunX0, double GunX1, double GunY0, double GunY1, double GunAngle, double BallX, int BallY, bool Ball, int Strength, double TargetX, double TargetY)
    {
        txSetFillColor(TX_WHITE);
        txClear();

        txSetColor(RGB(0, 0, 0));
        txSetFillColor(RGB(255, 255, 255));
        txCircle(TargetX, TargetY, 50);
        txCircle(TargetX, TargetY, 25);
        txCircle(TargetX, TargetY, 10);

        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txCircle(140, 800, 125);
        txSetColor(TX_BLACK, 15);
        txLine(140, 800, SearchX(GunX1, GunX0, GunY1, GunY0, GunAngle), SearchY(GunX1, GunX0, GunY1, GunY0, GunAngle));

        int StrengthBarX = 80;
        int StrengthBarY = 720;
        POINT StrengthBar[4] = {{StrengthBarX, StrengthBarY}, {StrengthBarX+120, StrengthBarY}, {StrengthBarX+120, StrengthBarY+50}, {StrengthBarX, StrengthBarY+50}};

        txSetColor(TX_WHITE);
        txSetFillColor (TX_WHITE);
        txPolygon(StrengthBar, 4);

        if(Ball)
        {
            txSetColor(TX_RED);
            txSetFillColor(TX_RED);
            txCircle(BallX, BallY, 10);
        }

        if(Strength == 1)
        {
            POINT FirstStageStrengthBar[4] = {{StrengthBarX, StrengthBarY}, {StrengthBarX+30, StrengthBarY}, {StrengthBarX+30, StrengthBarY+50}, {StrengthBarX, StrengthBarY+50}};

            txSetColor(RGB(255, 0, 0));
            txSetFillColor(RGB(255, 0, 0));
            txPolygon(FirstStageStrengthBar, 4);
        }
        if(Strength == 2)
        {
            POINT SecondStageStrengthBar[4] = {{StrengthBarX, StrengthBarY}, {StrengthBarX+60, StrengthBarY}, {StrengthBarX+60, StrengthBarY+50}, {StrengthBarX, StrengthBarY+50}};

            txSetColor(RGB(255, 165, 0));
            txSetFillColor(RGB(255, 165, 0));
            txPolygon(SecondStageStrengthBar, 4);
        }
        if(Strength == 3)
        {
            POINT ThirdStageStrengthBar[4] = {{StrengthBarX, StrengthBarY}, {StrengthBarX+90, StrengthBarY}, {StrengthBarX+90, StrengthBarY+50}, {StrengthBarX, StrengthBarY+50}};

            txSetColor(RGB(255, 255, 0));
            txSetFillColor(RGB(255, 255, 0));
            txPolygon(ThirdStageStrengthBar, 4);
        }
        if(Strength == 4)
        {
            POINT FouthStageStrengthBar[4] = {{StrengthBarX, StrengthBarY}, {StrengthBarX+120, StrengthBarY}, {StrengthBarX+120, StrengthBarY+50}, {StrengthBarX, StrengthBarY+50}};

            txSetColor(RGB(0, 255, 0));
            txSetFillColor(RGB(0, 255, 0));
            txPolygon(FouthStageStrengthBar, 4);
        }
    }

    void KeyboardControls(double GunX0, double GunX1, double GunY0, double GunY1, double *GunAngle, double *BallX, int *BallY, double *BallAngle, double *Time, bool *Ball, int *Strength)
    {
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if(*Ball == false)
            {
                if(*GunAngle < 85)
                {
                    *GunAngle = *GunAngle+1;
                }
            }
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            if(*Ball == false)
            {
                if(*GunAngle > 0) // *Ball != true
                {
                    *GunAngle = *GunAngle-1;
                }
            }
        }

        if (GetAsyncKeyState(VK_UP))
        {
            if(*Ball == false)
            {
                if(*Strength < 4)
                {
                    *Strength = *Strength + 1;
                    Sleep(100);
                }
            }
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            if(*Ball == false)
            {
                if(*Strength > 1)
                {
                    *Strength = *Strength - 1;
                    Sleep(100);
                }
            }
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            if(*Ball == false)
            {
                *Ball = true;
                *Time = 0;
                *BallAngle = *GunAngle;
            }
        }
    }

    void BallMovement(double *BallX, int *BallY, double BallAngle, double Time, double BallV0)
    {
        *BallX = BallV0*cos((BallAngle-90)*M_PI/180)*Time;
        *BallY = ((-1)*BallV0*sin((BallAngle+90)*M_PI/180)*Time+(9.8*Time*Time)/2);
    }

    double SearchX(double GunX1, double GunX0, double GunY1, double GunY0, double GunAngle)
    {
        double x2 = (GunX1-GunX0)*cos(GunAngle*M_PI/180)-(GunY1-GunY0)*sin(GunAngle*M_PI/180)+GunX0;
        return x2;
    }

    double SearchY(double GunX1, double GunX0, double GunY1, double GunY0, double GunAngle)
    {
        double y2 = (GunX1-GunX0)*sin(GunAngle*M_PI/180)+(GunY1-GunY0)*cos(GunAngle*M_PI/180)+GunY0;
        return y2;
    }

