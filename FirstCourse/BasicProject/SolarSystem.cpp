/*
    1) Солнце - 109%.                           109
    2) Меркурий (2440 км) – 38% от земного.     0.38
    3) Венера (6 052 км) – 95% от земного.      0.95
    4) Земля (6 371 км) - 100%.                 1
    5) Марс (3390 км) – 53% от земного.         0.53
    6) Юпитер (69 911 км) – 1.120% земного.     11.12
    7) Сатурн (58 232 км) – 945% земного.       9.45
    8) Уран (25 362 км) – 400% земного.         4
    9) Нептун (24 622 км) – 388% земного.       3.88
*/

    #include "TXLib.h"

    void drawSolarSystem(double CoefficientOfAll, bool Solar);

    int main()
    {
        txCreateWindow (1400, 800);

        txSetFillColor (TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        double CoefficientOfAll = 1;
        bool Solar = false;

        drawSolarSystem(CoefficientOfAll, Solar);

        return 0;
    }

    void drawSolarSystem(double CoefficientOfAll, bool Solar)
    {
        double Coefficients [9] = {109, 0.38, 0.95, 1, 0.53, 11.12, 9.45, 4, 3.88};
        double X [9] = {0};
        txSetColor(TX_BLACK);
        for(int i = 0; i<9; i++)
        {
            if(i == 0)
            {
                if (Solar == true)
                {
                    txCircle((5*Coefficients[i]*CoefficientOfAll), 400, 5*Coefficients[i]*CoefficientOfAll);
                    X[i] = {(5*Coefficients[i]*CoefficientOfAll)};
                }
            }else{
                    X[i] = {(5*Coefficients[i]*CoefficientOfAll)+(5*Coefficients[i-1]*CoefficientOfAll)+10+X[i-1]};
                    txCircle(X[i], 400, 5*Coefficients[i]*CoefficientOfAll);
            }
        }
    }
