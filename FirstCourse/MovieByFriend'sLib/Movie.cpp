    #include "TXlib.h"
    #include "Lib.h"

    void scene1(HDC Fade);
    void scene2(HDC GTA);
    void scene3(HDC Storage);
    void scene4(HDC Minutes);
    void scene5(HDC JOJO);
    void scene7(HDC Directed2, HDC Directed3, HDC Directed4);

    CONST COLORREF DARKORANGE = RGB(117, 79, 56);
    CONST COLORREF DARKGRAY = RGB(26, 15, 13);
    CONST COLORREF BLACK = RGB(0, 0, 1);
    CONST COLORREF ORANGE = RGB(166, 61, 40);
    CONST COLORREF WHITE = RGB(255, 255, 241);
    CONST COLORREF LIGHTBLUE = RGB(138, 218, 245);
    CONST COLORREF YELLOW = RGB(255, 255, 0);

    int main()
    {
        //Заливка фона
        txCreateWindow (1400, 800);
        txSetFillColor (TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        HDC Fade = txLoadImage ("Resources\\Fade.bmp");
        txPlaySound("Resources\\start.wav", SND_ASYNC);
        scene1(Fade);

        HDC GTA = txLoadImage ("Resources\\GTA.bmp");
        scene2(GTA);

        HDC Storage = txLoadImage ("Resources\\Storage.bmp");
        scene3(Storage);

        HDC Minutes = txLoadImage("Resources\\5minutes.bmp");
        scene4(Minutes);

        HDC JOJO = txLoadImage("Resources\\JOJO.bmp");
        scene5(JOJO);

        HDC Directed2 = txLoadImage("Resources\\Directed2.bmp");
        HDC Directed3 = txLoadImage("Resources\\Directed3.bmp");
        HDC Directed4 = txLoadImage("Resources\\Directed4.bmp");
        scene7(Directed2, Directed3, Directed4);

        return 0;
    }

    void scene1(HDC Fade)
    {
        txBitBlt (txDC(), 0, 0, 1400, 800, Fade, 0, 0);
        txSleep(7000);
        txDeleteDC (Fade);
    }

    void scene2(HDC GTA)
    {
        txSetFillColor(TX_WHITE);
        txClear();

        int x5=750;
        int y5=320;
        int mouthCJ =1;
        bool colorCJ = 0;
        string colorShirtCJ= "white";
        bool legsCJ=1;
        bool faceCJ=1;
        double eyesCJ=0;
        bool hairCJ=1;
        bool bodyCJ=1;
        double scaleCJ=1;

        int xD = 900;
        int yD = 320;
        double scaleDialog = 1;

        int x1=450;
        int y1=400;
        double shoesFines=0;
        double pantsFines=0;
        bool  mood=1;
        bool eyesFines=1;
        bool hairFines=1;
        bool reverseColor=0;
        bool legsFines=1;
        bool bodyFines=1;
        double scaleFines=1;

        int x2=50;
        int y2=450;
        double eyeJake =1;
        int colorJake=0;
        bool noseJake=1;
        bool mouthJake=0;
        bool armsJake=1;
        double headJake=0;
        bool earsJake=1;
        bool armsUpJake=0;
        double scaleJake=1;

        double x3=1100;
        double y3=500;
        double eyeDagget=0;
        double teethDagget=0;
        bool hairDagget=1;
        double handsDagget=0;
        double legsDagget=0;
        int colorDagget=0;
        bool noseDagget=1;
        bool legsHandsDagget=1;
        double scaleDagget=1;

        int x6=950;
        int y6=400;
        double eyeMike=1;
        double hornMike=0;
        bool doubleEyesMike=0;
        bool mouthOpenMike=0;
        bool colorMike=0;
        bool doubleFingersLegs=1;
        double scaleMike= 0.6;



        txBegin();
        for(int i=1; i<17; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, GTA, 0, 0);

            drawDialog(xD, yD, scaleDialog);
            drawCJ(x5, y5, mouthCJ, colorCJ, colorShirtCJ, legsCJ, faceCJ, eyesCJ, hairCJ, bodyCJ, scaleCJ);
            txTextOut(xD+35, yD-85, "Нам нужно захватить");
            txTextOut(xD+35, yD-55, "    этот склад!");

            drawMike(x6, y6, eyeMike, hornMike, doubleEyesMike, mouthOpenMike, colorMike, doubleFingersLegs, scaleMike);
            drawDagget(x3, y3, eyeDagget, teethDagget, hairDagget, handsDagget, legsDagget, colorDagget, noseDagget, legsHandsDagget, scaleDagget);
            drawJake(x2, y2, eyeJake, colorJake, noseJake, mouthJake, armsJake, headJake, earsJake, armsUpJake, scaleJake);
            drawFines(x1, y1, shoesFines,  pantsFines, mood, eyesFines, hairFines, reverseColor, legsFines, bodyFines, scaleFines);

            if(i%3==0)
            {
                mouthCJ=1;
            }else{
                mouthCJ=0;
            }

            txSleep(500);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        xD = 1100;
        yD = 450;

        int xD2 = 500;
        int yD2 = 420;

        txBegin();
        for(int i=1; i<10; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, GTA, 0, 0);

            drawDialog(xD, yD, scaleDialog);
            drawDialog(xD2, yD2, scaleDialog);
            drawCJ(x5, y5, mouthCJ, colorCJ, colorShirtCJ, legsCJ, faceCJ, eyesCJ, hairCJ, bodyCJ, scaleCJ);
            txTextOut(xD2+35, yD2-85, "Погнали!");
            txTextOut(xD+35, yD-85, "Погнали!");

            drawMike(x6, y6, eyeMike, hornMike, doubleEyesMike, mouthOpenMike, colorMike, doubleFingersLegs, scaleMike);
            drawDagget(x3, y3, eyeDagget, teethDagget, hairDagget, handsDagget, legsDagget, colorDagget, noseDagget, legsHandsDagget, scaleDagget);
            drawJake(x2, y2, eyeJake, colorJake, noseJake, mouthJake, armsJake, headJake, earsJake, armsUpJake, scaleJake);
            drawFines(x1, y1, shoesFines,  pantsFines, mood, eyesFines, hairFines, reverseColor, legsFines, bodyFines, scaleFines);

            if(i%2==0)
            {
                mouthOpenMike = 1;
            }else{
                mouthOpenMike = 0;
            }

            if(i%3==0)
            {
                mood = 1;
            }else{
                mood = 0;
            }

            txSleep(500);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        txBegin();
        for(int i=1; i<120; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, GTA, 0, 0);

            drawCJ(x5, y5, mouthCJ, colorCJ, colorShirtCJ, legsCJ, faceCJ, eyesCJ, hairCJ, bodyCJ, scaleCJ);

            drawMike(x6, y6, eyeMike, hornMike, doubleEyesMike, mouthOpenMike, colorMike, doubleFingersLegs, scaleMike);
            drawDagget(x3, y3, eyeDagget, teethDagget, hairDagget, handsDagget, legsDagget, colorDagget, noseDagget, legsHandsDagget, scaleDagget);
            drawJake(x2, y2, eyeJake, colorJake, noseJake, mouthJake, armsJake, headJake, earsJake, armsUpJake, scaleJake);
            drawFines(x1, y1, shoesFines,  pantsFines, mood, eyesFines, hairFines, reverseColor, legsFines, bodyFines, scaleFines);

            x5 = x5+10;
            x1 = x1+10;
            x2 = x2+10;
            x3 = x3+10;
            x6 = x6+10;

            if(i%2==0)
            {
                y5 = y5+10;
                y1 = y1+10;
                y2 = y2+10;
                y3 = y3+10;
                y6 = y6+10;
            }else{
                y5 = y5-10;
                y1 = y1-10;
                y2 = y2-10;
                y3 = y3-10;
                y6 = y6-10;
            }

            txSleep(125);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        txDeleteDC (GTA);
    }

    void scene3(HDC Storage)
    {
        txSetFillColor(TX_WHITE);
        txClear();

        txBitBlt (txDC(), 0, 0, 1400, 800, Storage, 0, 0);

        int x4=630;
        int y4=450;
        bool capMario=0;
        bool mustacheMario=1;
        int hairMario=0;
        string eyesMario= "dark";
        bool handsUpMario=0;
        int bootsMario=0;
        bool pantsMario=0;
        bool headMario=1;
        double scaleMario=0.4;

        int x5=850;
        int y5=390;
        int mouthCJ =1;
        bool colorCJ = 0;
        string colorShirtCJ= "white";
        bool legsCJ=1;
        bool faceCJ=1;
        double eyesCJ=0;
        bool hairCJ=1;
        bool bodyCJ=1;
        double scaleCJ=1;

        int xD = 750;
        int yD = 450;
        double scaleDialog = 1;

        int x1=450;
        int y1=550;
        double shoesFines=0;
        double pantsFines=0;
        bool  mood=1;
        bool eyesFines=1;
        bool hairFines=1;
        bool reverseColor=0;
        bool legsFines=1;
        bool bodyFines=1;
        double scaleFines=1;

        int x2=20;
        int y2=450;
        double eyeJake =1;
        int colorJake=0;
        bool noseJake=1;
        bool mouthJake=0;
        bool armsJake=1;
        double headJake=0;
        bool earsJake=1;
        bool armsUpJake=0;
        double scaleJake=1;

        int x6=1100;
        int y6=470;
        double eyeMike=1;
        double hornMike=0;
        bool doubleEyesMike=0;
        bool mouthOpenMike=0;
        bool colorMike=0;
        bool doubleFingersLegs=1;
        double scaleMike= 0.6;

        drawMike(x6, y6, eyeMike, hornMike, doubleEyesMike, mouthOpenMike, colorMike, doubleFingersLegs, scaleMike);
        drawJake(x2, y2, eyeJake, colorJake, noseJake, mouthJake, armsJake, headJake, earsJake, armsUpJake, scaleJake);
        drawFines(x1, y1, shoesFines,  pantsFines, mood, eyesFines, hairFines, reverseColor, legsFines, bodyFines, scaleFines);
        drawCJ(x5, y5, mouthCJ, colorCJ, colorShirtCJ, legsCJ, faceCJ, eyesCJ, hairCJ, bodyCJ, scaleCJ);

        drawDialog(xD, yD, scaleDialog);
        txTextOut(xD+35, yD-85, "Не понял! Что вы тут");
        txTextOut(xD+35, yD-55, "    делаете?!");
        drawMario(x4, y4, capMario, mustacheMario, hairMario, eyesMario, handsUpMario, bootsMario, pantsMario, headMario, scaleMario);
        txSleep(2000);

        txSetFillColor(TX_WHITE);
        txClear();

        txBegin();
        for(int i=1; i<10; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, Storage, 0, 0);

            drawMike(x6, y6, eyeMike, hornMike, doubleEyesMike, mouthOpenMike, colorMike, doubleFingersLegs, scaleMike);
            drawJake(x2, y2, eyeJake, colorJake, noseJake, mouthJake, armsJake, headJake, earsJake, armsUpJake, scaleJake);
            drawFines(x1, y1, shoesFines,  pantsFines, mood, eyesFines, hairFines, reverseColor, legsFines, bodyFines, scaleFines);
            drawCJ(x5, y5, mouthCJ, colorCJ, colorShirtCJ, legsCJ, faceCJ, eyesCJ, hairCJ, bodyCJ, scaleCJ);
            drawMario(x4, y4, capMario, mustacheMario, hairMario, eyesMario, handsUpMario, bootsMario, pantsMario, headMario, scaleMario);

            xD = 950;
            yD = 350;
            scaleDialog = 1.3;
            drawDialog(xD, yD, scaleDialog);
            txTextOut(xD+35, yD-85, "    У нас есть предложение,");
            txTextOut(xD+35, yD-55, "от которого вы не сожете отказаться");

            if(i%3==0)
            {
                mouthCJ=1;
            }else{
                mouthCJ=0;
            }

            txSleep(500);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();


        txSetFillColor(TX_WHITE);
        txClear();

        txBitBlt (txDC(), 0, 0, 1400, 800, Storage, 0, 0);

        drawMike(x6, y6, eyeMike, hornMike, doubleEyesMike, mouthOpenMike, colorMike, doubleFingersLegs, scaleMike);
        drawJake(x2, y2, eyeJake, colorJake, noseJake, mouthJake, armsJake, headJake, earsJake, armsUpJake, scaleJake);
        drawFines(x1, y1, shoesFines,  pantsFines, mood, eyesFines, hairFines, reverseColor, legsFines, bodyFines, scaleFines);
        drawCJ(x5, y5, mouthCJ, colorCJ, colorShirtCJ, legsCJ, faceCJ, eyesCJ, hairCJ, bodyCJ, scaleCJ);
        drawMario(x4, y4, capMario, mustacheMario, hairMario, eyesMario, handsUpMario, bootsMario, pantsMario, headMario, scaleMario);

        xD = 750;
        yD = 450;
        scaleDialog = 1;
        drawDialog(xD, yD, scaleDialog);
        txTextOut(xD+35, yD-85, "  А что, если");
        txTextOut(xD+35, yD-55, "я не соглашусь?");
        txSleep(2000);
        txSetFillColor(TX_WHITE);
        txClear();

        txBegin();
        for(int i=1; i<10; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, Storage, 0, 0);

            drawMike(x6, y6, eyeMike, hornMike, doubleEyesMike, mouthOpenMike, colorMike, doubleFingersLegs, scaleMike);
            drawJake(x2, y2, eyeJake, colorJake, noseJake, mouthJake, armsJake, headJake, earsJake, armsUpJake, scaleJake);
            drawFines(x1, y1, shoesFines,  pantsFines, mood, eyesFines, hairFines, reverseColor, legsFines, bodyFines, scaleFines);
            drawCJ(x5, y5, mouthCJ, colorCJ, colorShirtCJ, legsCJ, faceCJ, eyesCJ, hairCJ, bodyCJ, scaleCJ);
            drawMario(x4, y4, capMario, mustacheMario, hairMario, eyesMario, handsUpMario, bootsMario, pantsMario, headMario, scaleMario);

            xD = 300;
            yD = 500;
            scaleDialog = 1;
            drawDialog(xD, yD, scaleDialog);
            txTextOut(xD+35, yD-80, "Будет очень плохо!");

            if(i%2==0)
            {
                headJake=headJake+0.2;
            }else{
                headJake=headJake-0.2;
            }

            txSleep(500);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        txSetFillColor(WHITE);
        txClear();

        txBitBlt (txDC(), 0, 0, 1400, 800, Storage, 0, 0);

        drawMike(x6, y6, eyeMike, hornMike, doubleEyesMike, mouthOpenMike, colorMike, doubleFingersLegs, scaleMike);
        drawJake(x2, y2, eyeJake, colorJake, noseJake, mouthJake, armsJake, headJake, earsJake, armsUpJake, scaleJake);
        drawFines(x1, y1, shoesFines,  pantsFines, mood, eyesFines, hairFines, reverseColor, legsFines, bodyFines, scaleFines);
        drawCJ(x5, y5, mouthCJ, colorCJ, colorShirtCJ, legsCJ, faceCJ, eyesCJ, hairCJ, bodyCJ, scaleCJ);
        drawMario(x4, y4, capMario, mustacheMario, hairMario, eyesMario, handsUpMario, bootsMario, pantsMario, headMario, scaleMario);

        xD = 750;
        yD = 450;
        scaleDialog = 1;
        drawDialog(xD, yD, scaleDialog);
        txTextOut(xD+35, yD-80, "Давайте по-плохому!");
        txPlaySound("Resources\\OSTJojo.wav", SND_ASYNC);
        txSleep(4000);

        txSetFillColor(WHITE);
        txClear();
        txDeleteDC (Storage);
    }

    void scene4(HDC Minutes)
    {
        txSetFillColor(BLACK);
        txClear();

        txBitBlt (txDC(), 0, 0, 1400, 800, Minutes, 0, 0);
        txSleep(10000);
        txDeleteDC (Minutes);
        txSetFillColor(BLACK);
        txClear();
    }

    void scene5(HDC JOJO)
    {
        txSetFillColor(TX_WHITE);
        txClear();

        int x4=20;
        int y4=0;
        bool capMario=0;
        bool mustacheMario=1;
        int hairMario=0;
        string eyesMario= "dark";
        bool handsUpMario=0;
        int bootsMario=0;
        bool pantsMario=0;
        bool headMario=1;
        double scaleMario=4;

        drawMario(x4, y4, capMario, mustacheMario, hairMario, eyesMario, handsUpMario, bootsMario, pantsMario, headMario, scaleMario);
        txAlphaBlend(txDC(), 0, 0, 1400, 800, JOJO, 0, 0, 1);
        txPlaySound("Resources\\WryyyyJojo.wav", SND_SYNC);
    }

    void scene7(HDC Directed2, HDC Directed3, HDC Directed4)
    {
        txSetFillColor(BLACK);
        txClear();

        txPlaySound("Resources\\directed1.wav", SND_SYNC);
        txSetFillColor(WHITE);
        txClear();

        txBitBlt (txDC(), 0, 0, 1400, 800, Directed2, 0, 0);
        txPlaySound("Resources\\directed2.wav", SND_SYNC);
        txSetFillColor(WHITE);
        txClear();
        txDeleteDC (Directed2);

        txBitBlt (txDC(), 0, 0, 1400, 800, Directed3, 0, 0);
        txPlaySound("Resources\\directed3.wav", SND_SYNC);
        txSetFillColor(WHITE);
        txClear();
        txDeleteDC (Directed3);

        txBitBlt (txDC(), 0, 0, 1400, 800, Directed4, 0, 0);
        txPlaySound("Resources\\directed4.wav", SND_SYNC);
        txSetFillColor(WHITE);
        txClear();
        txDeleteDC (Directed4);
    }
