    #include "TXLib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <cmath>
    #define LEN 100000

    class button
    {
        private:
            int firstX;
            int firstY;
            int secondX;
            int secondY;

        public:
            button(int valueFirstX, int valueFirstY, int valueSecondX, int valueSecondY)
            {
                firstX = valueFirstX; 
                firstY = valueFirstY;
                secondX = valueSecondX; 
                secondY = valueSecondY;
            }

            bool IsOver()
            {
                RECT collision = {firstX, firstY, secondX, secondY};
                if(In(txMousePos(), collision))
                {  
                    return true;
                }else{
                    return false;
                }
            }

            bool IsClicked()
            {
                RECT collision = {firstX, firstY, secondX, secondY};
                if(GetAsyncKeyState(VK_LBUTTON))
                {
                    if(In(txMousePos(), collision))
                    {  
                        return true;
                    }else{
                        return false;
                    }
                }
            }

            int GetFirstX() { return firstX; }
            int GetFirstY() { return firstY; }
            int GetSecondX() { return secondX; }
            int GetSecondY() { return secondY; }
    };

    double straight(double x, double k, double b);
    double module(double x, double k, double a);
    double parabola(double x, double a, double b, double c);
    double parabolaBranch(double x, double k, double a);
    double cubicParabola(double x, double k, double a);
    double radioWaves(double x, double k, double b, double c);
    double sinus(double x, double k, double a, double b);
    double tangent(double x, double k, double b);
    double arcTangent(double x, double k, double b);
    void markingBuilder(int scale);
    void graphicsBuilder(int graphicOnCanvas, double k, double a, double b, double c, double scale);
    void information(int graphicOnCanvas, char *info, double *coefficients);

    double straight(double x, double k, double b) { return k*x+b; }
    double module(double x, double k, double a) { return k*abs(x)+a; }
    double parabola(double x, double a, double b, double c) { return (a*pow(x, 2)+b*x+c)*2; }
    double parabolaBranch(double x, double k, double a) { return k*sqrt(x)+a; }
    double cubicParabola(double x, double k, double a) { return k*(x*x*x)+a; }
    double radioWaves(double x, double k, double b, double c) { return k*sin(x)/tan(x)*x*x/10*(x/2+x-(x/2))+b*x+c; }
    double sinus(double x, double k, double a, double b) { return k*sin(x*a)+b; }
    double tangent(double x, double k, double b) { return k*tan(x)+b; }
    double arcTangent(double x, double k, double b) { return k*atan(x)+b; }

    void markingBuilder(int scale)
    {
        txSetColor(RGB(125, 125, 125));
        for(int i = 0; i<477/scale; i++)
        {
            txLine(0+scale*i, 0, 0+scale*i, 357);
        }
        for(int i = 0; i<960/scale/2; i++)
        {
            txLine(480+scale*i, 0, 480+scale*i, 357);
        }
        for(int i = 0; i<477/scale; i++)
        {
            txLine(0+scale*i, 361, 0+scale*i, 720);
        }
        for(int i = 0; i<960/scale/2; i++)
        {
            txLine(480+scale*i, 361, 480+scale*i, 720);
        }

        for(int i = 0; i<357/scale; i++)
        {
            txLine(0, 0+scale*i, 477, 0+scale*i);
        }
        for(int i = 0; i<361/scale; i++)
        {
            txLine(0, 361+scale*i, 477, 361+scale*i);
        }
        for(int i = 0; i<357/scale; i++)
        {
            txLine(480, 0+scale*i, 960, 0+scale*i);
        }
        for(int i = 0; i<361/scale; i++)
        {
            txLine(480, 361+scale*i, 960, 361+scale*i);
        }
    }

    void graphicsBuilder(int graphicOnCanvas, double k, double a, double b, double c, double scale)
    {
        int array[960];
        txSetColor(RGB(255, 0, 0), 2);

        switch(graphicOnCanvas)
        {
            case 1:
                for(int x = 0; x < 959; x++)
                {
                    array[x] = 359-(straight(x-479, k, b));
                }
                for(int x = 0; x < 959; x++)
                {
                    txLine(x, array[x], x+1, array[x+1]);
                }
                break;

            case 2:
                for(int x = 0; x < 959; x++)
                {
                    array[x] = 359-(module(x-479, k, a));
                }
                for(int x = 0; x < 959; x++)
                {
                    txLine(x, array[x], x+1, array[x+1]);
                }
                break;

            case 3:
                for(int x = 0; x < 959; x++)
                {
                    array[x] = 359-(parabola(x-479, a, b, c));
                }
                for(int x = 0; x < 959; x++)
                {
                    txLine(x, array[x], x+1, array[x+1]);
                }
                break;

            case 4:
                for(int x = 479; x < 959; x++)
                {
                    array[x] = 359-(parabolaBranch(x-479, k, a));
                }
                for(int x = 479; x < 959; x++)
                {
                    txLine(x, array[x], x+1, array[x+1]);
                }
                break;

            case 5:
                for(double x = 0; x < 959; x=x+0.1)
                {
                    array[int(x)] = 359-(cubicParabola(x-479, k, a));
                }
                for(double x = 0; x < 959; x=x+0.1)
                {
                    txLine(x, array[int(x)], x+1, array[int(x)+1]);
                }
                break;  
            
            case 6:
                txSetColor(RGB(255, 0, 0), 1);
                for(double x = 0; x < 958; x=x+0.1)
                {
                    array[int(x)] = 359-(radioWaves(x-479, k, b, c));
                }
                for(double x = 0; x < 958; x=x+0.1)
                {
                    txLine(x, array[int(x)], x+1, array[int(x)+1]);
                }
                break;  

            case 7:
                for(int x = 0; x < 959; x++)
                {
                    array[x] = 359-(sinus(x-479, k, a, b));
                }
                for(int x = 0; x < 959; x++)
                {
                    txLine(x, array[x], x+1, array[x+1]);
                }
                break;  

            case 8:
                for(int x = 0; x < 959; x++)
                {
                    array[x] = 359-(tangent(x-479, k, b));
                }
                for(int x = 0; x < 959; x++)
                {
                    txLine(x, array[x], x+1, array[x+1]);
                }
                break;  

            case 9:
                for(int x = 0; x < 959; x++)
                {
                    array[x] = 359-(arcTangent(x-479, k, b));
                }
                for(int x = 0; x < 959; x++)
                {
                    txLine(x, array[x], x+1, array[x+1]);
                }
                break;  
        }
    }

    void information(int graphicOnCanvas, char *info, double *coefficients)
    {
        char kText[100];
        char aText[100];
        char bText[100];
        char cText[100];
        switch(graphicOnCanvas)
        {
            case 1:
                *info = ' ';
                itoa(coefficients[0], kText, 10);
                itoa(coefficients[2], bText, 10);
                strcpy(info, "y = kx+b\n");
                strcat(info, "k = ");
                strcat(info, kText);
                strcat(info, "  b = ");
                strcat(info, bText);
                break;

            case 2:
                *info = ' ';
                itoa(coefficients[0], kText, 10);
                itoa(coefficients[1], aText, 10);
                strcpy(info, "y = k*abs(x)+a\n");
                strcat(info, "k = ");
                strcat(info, kText);
                strcat(info, "  a = ");
                strcat(info, aText);
                break;

            case 3:
                *info = ' ';
                itoa(coefficients[1], aText, 10);
                itoa(coefficients[2], bText, 10);
                itoa(coefficients[3], cText, 10);
                strcpy(info, "y = ax^2+bx+c\n");
                strcat(info, "a = ");
                strcat(info, aText);
                strcat(info, "  b = ");
                strcat(info, bText);
                strcat(info, "  c = ");
                strcat(info, cText);
                break;

            case 4:
                *info = ' ';
                itoa(coefficients[0], kText, 10);
                itoa(coefficients[1], aText, 10);
                strcpy(info, "y = k*sqrt(x)+a\n");
                strcat(info, "k = ");
                strcat(info, kText);
                strcat(info, "  a = ");
                strcat(info, aText);
                break;

            case 5:
                *info = ' ';
                itoa(coefficients[0], kText, 10);
                itoa(coefficients[1], aText, 10);
                strcpy(info, "y = k*x^3+a\n");
                strcat(info, "k = ");
                strcat(info, kText);
                strcat(info, "  a = ");
                strcat(info, aText);
                break;

            case 6:
                *info = ' ';
                itoa(coefficients[0], kText, 10);
                itoa(coefficients[2], bText, 10);
                itoa(coefficients[3], cText, 10);
                strcpy(info, "y = k*sinX/tgX*x^2/\n/10*(x/2+x-(x/2))+b*x+c\n");
                strcat(info, "k = ");
                strcat(info, kText);
                strcat(info, "  b = ");
                strcat(info, bText);
                strcat(info, "  c = ");
                strcat(info, cText);
                break;

            case 7:
                *info = ' ';
                itoa(coefficients[0], kText, 10);
                itoa(coefficients[1], aText, 10);
                itoa(coefficients[2], bText, 10);
                strcpy(info, "y = k*(sinX*a)+b\n");
                strcat(info, "k = ");
                strcat(info, kText);
                strcat(info, "  a = ");
                strcat(info, aText);
                strcat(info, "  b = ");
                strcat(info, bText);
                break;

            case 8:
                *info = ' ';
                itoa(coefficients[0], kText, 10);
                itoa(coefficients[2], bText, 10);
                strcpy(info, "y = k*tgX+b\n");
                strcat(info, "k = ");
                strcat(info, kText);
                strcat(info, "  b = ");
                strcat(info, bText);
                break;

            case 9:
                *info = ' ';
                itoa(coefficients[0], kText, 10);
                itoa(coefficients[2], bText, 10);
                strcpy(info, "y = k*arctgX+b\n");
                strcat(info, "k = ");
                strcat(info, kText);
                strcat(info, "  b = ");
                strcat(info, bText);
                break;
        }
        txSetColor(TX_BLACK);
        txSelectFont("TimesNewRoman", 40);
        txDrawText(970, 95, 1270, 240, info);
    }