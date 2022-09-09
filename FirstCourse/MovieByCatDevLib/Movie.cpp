    #include "TXLib.h"
    #include "CatDevLib.h"

    void scene1(HDC Fade);
    void scene2(HDC scene2_background);
    void scene3(HDC openDoor, HDC closeDoor, HDC sky);
    void scene4(HDC minutes);
    void scene5(HDC openDoor, HDC sky);
    void scene6(HDC Scene6);
    void scene7(HDC Directed2, HDC Directed3, HDC Directed4);

    int main()
    {
        //Заливка фона
        txCreateWindow (1400, 800);
        txSetFillColor (TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        HDC Fade = txLoadImage ("Resources\\Fade.bmp");
        txPlaySound("Resources\\start.wav", SND_ASYNC);
        scene1(Fade);

        HDC scene2_background = txLoadImage("Resources\\Scene2_background.bmp");
        txPlaySound("Resources\\tv.wav", SND_ASYNC);
        scene2(scene2_background);

        HDC openDoor = txLoadImage("Resources\\OpenDoor.bmp");
        HDC closeDoor = txLoadImage("Resources\\CloseDoor.bmp");
        HDC sky = txLoadImage("Resources\\Sky.bmp");
        scene3(openDoor, closeDoor, sky);

        HDC minutes = txLoadImage("Resources\\5minutes.bmp");
        scene4(minutes);

        scene5(openDoor, sky);

        HDC Scene6 = txLoadImage("Resources\\Scene6.bmp");
        scene6(Scene6);

        HDC Directed2 = txLoadImage("Resources\\Directed2.bmp");
        HDC Directed3 = txLoadImage("Resources\\Directed3.bmp");
        HDC Directed4 = txLoadImage("Resources\\Directed4.bmp");
        scene7(Directed2, Directed3, Directed4);

        return 0;
    }

    void SkubiEyes1(int x, int y, int SkubiScale, bool SkubiEyes, COLORREF SkubiStrokePanelColor, COLORREF SkubiEyesColor)
    {
        if(SkubiEyes)
        {
            txSetFillColor(WHITE);
            txSetColor(WHITE);
            txCircle(x+(111*SkubiScale), y+(-226*SkubiScale), 10*SkubiScale);
            txCircle(x+(86*SkubiScale), y+(-213*SkubiScale), 10*SkubiScale);
            txSetFillColor(SkubiEyesColor);
            txSetColor(SkubiEyesColor);
            txCircle(x+(111*SkubiScale), y+(-226*SkubiScale), 6*SkubiScale);
            txCircle(x+(86*SkubiScale), y+(-213*SkubiScale), 6*SkubiScale);
            txSetFillColor(SkubiStrokePanelColor);
            txCircle(x+(111*SkubiScale), y+(-226*SkubiScale), 4*SkubiScale);
            txCircle(x+(86*SkubiScale), y+(-213*SkubiScale), 4*SkubiScale);
        }else{
            txSetColor(SkubiStrokePanelColor, 5);
            txLine(x+(72*SkubiScale), y+(-247*SkubiScale), x+(85*SkubiScale), y+(-262*SkubiScale));
            txLine(x+(85*SkubiScale), y+(-262*SkubiScale), x+(93*SkubiScale), y+(-258*SkubiScale));
            txLine(x+(107*SkubiScale), y+(-257*SkubiScale), x+(117*SkubiScale), y+(-263*SkubiScale));
            txLine(x+(117*SkubiScale), y+(-263*SkubiScale), x+(134*SkubiScale), y+(-257*SkubiScale));

            txSetColor(SkubiStrokePanelColor, 3);
            txLine(x+(70*SkubiScale), y+(-214*SkubiScale), x+(95*SkubiScale), y+(-216*SkubiScale));
            txLine(x+(127*SkubiScale), y+(-231*SkubiScale), x+(103*SkubiScale), y+(-224*SkubiScale));
        }
    }

    void scene1(HDC Fade)
    {
        txBitBlt (txDC(), 0, 0, 1400, 800, Fade, 0, 0);
        txSleep(7000);
        txDeleteDC (Fade);
    }

    void scene2(HDC scene2_background)
    {
        int pigX = 913;
        int pigY = 450;
        int pigEar = 3;  //0-Нет ушей, 1-Правое ухо, 2-Левое ухо, 3-Оба уха
        int pigHand = 3;  //0-Нет рук, 1-Правая рука, 2-Левая рука, 3-Обе руки
        int pigScale = 1;
        bool pigEyes; //= true;
        bool pigLeg = true;
        bool pigLeftArm; //= 1;
        bool pigRoth = true;
        COLORREF pigEarColor = RGB(230, 152, 194);
        COLORREF pigNoseColor = RGB(251, 202, 205);
        COLORREF pigShirtColor = RGB(240, 78, 150);
        COLORREF pigSkinColor = RGB(251, 202, 205);

        int flyX = 431;
        int flyY = 275;
        int flyHand = 3;  //0-Нет рук, 1-Правая рука, 2-Левая рука, 3-Обе руки
        int flyScale = 1;
        bool flyLeg = true;//При отсутствии ног, крылья автоматические исчезают
        bool flyHair = true;
        bool flyWings = true;
        bool flyEyes;
        COLORREF flyRothColor = RGB(148, 56, 105);
        COLORREF flyShirtColor = RGB(255, 0, 0);
        COLORREF flySkinColor = RGB(88, 165, 155);
        COLORREF flyEyesColor = RGB(255, 255, 0);

        txBegin();
        for(int i=1; i<17; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, scene2_background, 0, 0);

            drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
            drawFly(flyX, flyY, flyHand, flyLeg, flyScale, flyHair, flyWings, flyEyes, flyRothColor, flyShirtColor, flySkinColor, flyEyesColor);

            if(i%5==0)
            {
                flyEyes=false;
            }else{
                flyEyes=true;
            }

            if(i%6==0)
            {
                pigEyes=false;
            }else{
                pigEyes=true;
            }

            if(i%4==0)
            {
                pigLeftArm = 1;
            }else{
                pigLeftArm = 0;
            }

            txSleep(500);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        int MinionX = -250;
        int MinionY = 446;
        int MinionHand = 3;  //0-Нет рук, 1-Правая рука, 2-Левая рука, 3-Обе руки
        int MinionScale = 1;
        bool MinionGlasses = true;
        bool MinionHair = true;
        bool MinionRoth = true;
        COLORREF MinionEyesColor = RGB(117, 79, 56);
        COLORREF MinionPantsColor = RGB(0, 139, 255);
        COLORREF MinionGlassesColor = RGB(87, 78, 64);
        COLORREF MinionPocketColor = RGB(0, 139, 255);

        txBegin();
        for(int i=1; i<34; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, scene2_background, 0, 0);

            drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
            drawFly(flyX, flyY, flyHand, flyLeg, flyScale, flyHair, flyWings, flyEyes, flyRothColor, flyShirtColor, flySkinColor, flyEyesColor);
            drawMinion(MinionX, MinionY, MinionHand, MinionScale, MinionGlasses, MinionHair, MinionRoth, MinionEyesColor, MinionPantsColor, MinionGlassesColor, MinionPocketColor);

            MinionX=MinionX+10;

            if(i%2)
            {
                MinionY=MinionY+10;
            }else{
                MinionY=MinionY-10;
            }

            if(i%10==0)
            {
                flyEyes=false;
            }else{
                flyEyes=true;
            }

            if(i%6==0)
            {
                pigEyes=false;
            }else{
                pigEyes=true;
            }

            txSleep(250);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        txPlaySound("Resources\\minion.wav", SND_ASYNC);
        txBegin();
        for(int i=1; i<6; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, scene2_background, 0, 0);

            drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
            drawFly(flyX, flyY, flyHand, flyLeg, flyScale, flyHair, flyWings, flyEyes, flyRothColor, flyShirtColor, flySkinColor, flyEyesColor);
            drawMinion(MinionX, MinionY, MinionHand, MinionScale, MinionGlasses, MinionHair, MinionRoth, MinionEyesColor, MinionPantsColor, MinionGlassesColor, MinionPocketColor);

            SIZE size = txGetTextExtent ("Миньон: Друзья, пойдёмте кушац!");
            txSelectFont ("Comic Sans MS", 40);
            txTextOut (700 - size.cx/2, 700, "Миньон: Друзья, пойдёмте кушац!");

            if(i%5==0)
            {
                flyEyes=false;
            }else{
                flyEyes=true;
            }

            if(i%6==0)
            {
                pigEyes=false;
            }else{
                pigEyes=true;
            }

            MinionRoth = !MinionRoth;
            txSleep(500);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();
        txDeleteDC (scene2_background);
    }

    void scene3(HDC openDoor, HDC closeDoor, HDC sky)
    {
        txBitBlt (txDC(), 0, 0, 1400, 800, closeDoor, 0, 0);
        txPlaySound("Resources\\fbi.wav", SND_SYNC);
        txDeleteDC (closeDoor);

        int penguinX = 750;//670
        int penguinY = 403;
        int penguinHand = 3;  //0-Нет рук, 1-Правая рука, 2-Левая рука, 3-Обе руки
        int penguinLeg = 3;  //0-Нет ног, 1-Правая нога, 2-Левая нога, 3-Обе ноги
        int penguinEyes = 3; //0-Нет глаз, 1-Правый глаз, 2-Левый газ, 3-Оба глаза
        int penguinScale = 1;
        bool penguinRoth = true;
        COLORREF penguinEyesColor = RGB(51, 83, 128);
        COLORREF penguinLegsColor = RGB(169, 95, 46);
        COLORREF penguinBackColor = RGB(0, 0, 1);
        COLORREF penguinBallyColor = RGB(255, 255, 241);

        int SkubiX = 726;//602
        int SkubiY = 758;
        int SkubiScale = 1;
        bool SkubiNose = true;
        bool SkubiKeychain = true;
        bool skubyiMoles = true;
        bool SkubiEyes = false;
        bool SkubiTeeth = true;
        COLORREF SkubiStrokePanelColor = RGB(0, 0, 2);
        COLORREF SkubiSkinColor = RGB(142, 80, 6);
        COLORREF SkubiCollarColor = RGB(10, 105, 127);
        COLORREF SkubiEyesColor = RGB(51, 83, 128);

        txBegin();
        for(int i=1; i<7; i++)
        {
            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);
            txBitBlt (txDC(), 0, 0, 1400, 800, sky, 0, 0);

            drawPenguin(penguinX, penguinY, penguinHand, penguinLeg, penguinScale, penguinRoth, penguinEyes, penguinEyesColor, penguinLegsColor, penguinBackColor, penguinBallyColor);
            drawSkubi(SkubiX, SkubiY, SkubiScale, SkubiKeychain, skubyiMoles, SkubiEyes, SkubiNose, SkubiTeeth, SkubiStrokePanelColor, SkubiSkinColor, SkubiCollarColor, SkubiEyesColor);

            penguinX = penguinX-10;
            SkubiX = SkubiX-20;

            txAlphaBlend(txDC(), 0, 0, 1400, 800, openDoor, 0, 0, 1);

            txSleep(125);
        }
        txEnd();

        txPlaySound("Resources\\SkubiKush.wav", SND_ASYNC);

        txBegin();
        for(int i=1; i<3; i++)
        {
            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);
            txBitBlt (txDC(), 0, 0, 1400, 800, sky, 0, 0);

            drawPenguin(penguinX, penguinY, penguinHand, penguinLeg, penguinScale, penguinRoth, penguinEyes, penguinEyesColor, penguinLegsColor, penguinBackColor, penguinBallyColor);
            drawSkubi(SkubiX, SkubiY, SkubiScale, SkubiKeychain, skubyiMoles, SkubiEyes, SkubiNose, SkubiTeeth, SkubiStrokePanelColor, SkubiSkinColor, SkubiCollarColor, SkubiEyesColor);

            SkubiTeeth = !SkubiTeeth;

            txAlphaBlend(txDC(), 0, 0, 1400, 800, openDoor, 0, 0, 1);
            SkubiEyes1(SkubiX, SkubiY, SkubiScale, SkubiEyes, SkubiStrokePanelColor, SkubiEyesColor);

            SkubiEyes = !SkubiEyes;

            txSleep(1000);
        }
        txEnd();
        txSleep(250);
    }

    void scene4(HDC minutes)
    {
        txBitBlt (txDC(), 0, 0, 1400, 800, minutes, 0, 0);
        txPlaySound("Resources\\5minutes.wav", SND_SYNC);
        txDeleteDC (minutes);
        txSetFillColor(BLACK);
        txClear();
        txPlaySound("Resources\\eat.wav", SND_SYNC);
    }

    void scene5(HDC openDoor, HDC sky)
    {
        int penguinX = 680;//670
        int penguinY = 403;
        int penguinHand = 3;  //0-Нет рук, 1-Правая рука, 2-Левая рука, 3-Обе руки
        int penguinLeg = 3;  //0-Нет ног, 1-Правая нога, 2-Левая нога, 3-Обе ноги
        int penguinEyes = 3; //0-Нет глаз, 1-Правый глаз, 2-Левый газ, 3-Оба глаза
        int penguinScale = 1;
        bool penguinRoth = true;
        COLORREF penguinEyesColor = RGB(51, 83, 128);
        COLORREF penguinLegsColor = RGB(169, 95, 46);
        COLORREF penguinBackColor = RGB(0, 0, 1);
        COLORREF penguinBallyColor = RGB(255, 255, 241);

        int SkubiX = 586;//602
        int SkubiY = 758;
        int SkubiScale = 1;
        bool SkubiNose = true;
        bool SkubiKeychain = true;
        bool skubyiMoles = true;
        bool SkubiEyes = true;
        bool SkubiTeeth = false;
        COLORREF SkubiStrokePanelColor = RGB(0, 0, 2);
        COLORREF SkubiSkinColor = RGB(142, 80, 6);
        COLORREF SkubiCollarColor = RGB(10, 105, 127);
        COLORREF SkubiEyesColor = RGB(51, 83, 128);

        txBitBlt (txDC(), 0, 0, 1400, 800, sky, 0, 0);

        drawPenguin(penguinX, penguinY, penguinHand, penguinLeg, penguinScale, penguinRoth, penguinEyes, penguinEyesColor, penguinLegsColor, penguinBackColor, penguinBallyColor);
        drawSkubi(SkubiX, SkubiY, SkubiScale, SkubiKeychain, skubyiMoles, SkubiEyes, SkubiNose, SkubiTeeth, SkubiStrokePanelColor, SkubiSkinColor, SkubiCollarColor, SkubiEyesColor);

        txAlphaBlend(txDC(), 0, 0, 1400, 800, openDoor, 0, 0, 1);
        SkubiEyes1(SkubiX, SkubiY, SkubiScale, SkubiEyes, SkubiStrokePanelColor, SkubiEyesColor);
        txSleep(1000);

        txPlaySound("Resources\\SkubiPosh.wav", SND_ASYNC);

        txBegin();
        for(int i=1; i<3; i++)
        {
            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);
            txBitBlt (txDC(), 0, 0, 1400, 800, sky, 0, 0);

            drawPenguin(penguinX, penguinY, penguinHand, penguinLeg, penguinScale, penguinRoth, penguinEyes, penguinEyesColor, penguinLegsColor, penguinBackColor, penguinBallyColor);
            drawSkubi(SkubiX, SkubiY, SkubiScale, SkubiKeychain, skubyiMoles, SkubiEyes, SkubiNose, SkubiTeeth, SkubiStrokePanelColor, SkubiSkinColor, SkubiCollarColor, SkubiEyesColor);

            SkubiTeeth = !SkubiTeeth;

            txAlphaBlend(txDC(), 0, 0, 1400, 800, openDoor, 0, 0, 1);
            SkubiEyes1(SkubiX, SkubiY, SkubiScale, SkubiEyes, SkubiStrokePanelColor, SkubiEyesColor);

            SkubiEyes = !SkubiEyes;

            txSleep(1000);
        }
        txEnd();

        for(int i=1; i<12; i++)
        {
            txSetFillColor (TX_WHITE);
            txFloodFill(0, 0, FLOODFILLBORDER);
            txBitBlt (txDC(), 0, 0, 1400, 800, sky, 0, 0);

            drawPenguin(penguinX, penguinY, penguinHand, penguinLeg, penguinScale, penguinRoth, penguinEyes, penguinEyesColor, penguinLegsColor, penguinBackColor, penguinBallyColor);
            drawSkubi(SkubiX, SkubiY, SkubiScale, SkubiKeychain, skubyiMoles, SkubiEyes, SkubiNose, SkubiTeeth, SkubiStrokePanelColor, SkubiSkinColor, SkubiCollarColor, SkubiEyesColor);

            penguinX = penguinX+10;
            SkubiX = SkubiX+20;

            txAlphaBlend(txDC(), 0, 0, 1400, 800, openDoor, 0, 0, 1);

            txSleep(125);
        }
        txDeleteDC(openDoor);
    }

    void scene6(HDC Scene6)
    {
        int pigX = 913;
        int pigY = 450;
        int pigEar = 3;  //0-Нет ушей, 1-Правое ухо, 2-Левое ухо, 3-Оба уха
        int pigHand = 3;  //0-Нет рук, 1-Правая рука, 2-Левая рука, 3-Обе руки
        int pigScale = 1;
        bool pigEyes; //= true;
        bool pigLeg = true;
        bool pigLeftArm=1; //= 1;
        bool pigRoth = true;
        COLORREF pigEarColor = RGB(230, 152, 194);
        COLORREF pigNoseColor = RGB(251, 202, 205);
        COLORREF pigShirtColor = RGB(240, 78, 150);
        COLORREF pigSkinColor = RGB(251, 202, 205);

        int timonX = 178;
        int timonY = 493;
        int timonEar = 3;  //0-Нет ушей, 1-Правое ухо, 2-Левое ухо, 3-Оба уха
        int timonLeg = 3;  //0-Нет ног, 1-Правая нога, 2-Левая нога, 3-Обе ноги
        int timonScale = 1;
        bool timonTale = true;
        bool timonHair = true;
        bool timonRoth = false;
        COLORREF timonBallyColor = RGB(241, 217, 183);
        COLORREF timonBackColor = RGB(169, 95, 46);
        COLORREF timonHairColor = RGB(166, 61, 40);
        COLORREF timonLimbColor = RGB(87, 78, 64);

        txPlaySound("Resources\\Where.wav", SND_ASYNC);

        txBegin();
        for(int i=1; i<4; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, Scene6, 0, 0);

            drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
            drawTimon(timonX, timonY, timonEar, timonLeg, timonScale, timonTale, timonHair, timonRoth, timonBallyColor, timonBackColor, timonHairColor, timonLimbColor);

            if(i%2==0)
            {
                pigEyes=false;
            }else{
                pigEyes=true;
            }
            pigRoth = !pigRoth;

            txSleep(500);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        txBitBlt (txDC(), 0, 0, 1400, 800, Scene6, 0, 0);
        drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
        drawTimon(timonX, timonY, timonEar, timonLeg, timonScale, timonTale, timonHair, timonRoth, timonBallyColor, timonBackColor, timonHairColor, timonLimbColor);
        txPlaySound("Resources\\IDon'tKnow.wav", SND_ASYNC);

        txBegin();
        for(int i=1; i<12; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, Scene6, 0, 0);

            drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
            drawTimon(timonX, timonY, timonEar, timonLeg, timonScale, timonTale, timonHair, timonRoth, timonBallyColor, timonBackColor, timonHairColor, timonLimbColor);

            if(i%2==0)
            {
                pigEyes=false;
            }else{
                pigEyes=true;
            }

            timonRoth=!timonRoth;

            txSleep(250);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        txBegin();
        for(int i=1; i<80; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, Scene6, 0, 0);

            drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
            drawTimon(timonX, timonY, timonEar, timonLeg, timonScale, timonTale, timonHair, timonRoth, timonBallyColor, timonBackColor, timonHairColor, timonLimbColor);

            if(i%6==0)
            {
                pigEyes=false;
            }else{
                pigEyes=true;
            }

            if(i%2==0)
            {
                timonY=timonY+15;
            }else{
                timonY=timonY-15;
            }

            timonX=timonX+20;

            txSleep(100);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        txBitBlt (txDC(), 0, 0, 1400, 800, Scene6, 0, 0);
        drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
        txPlaySound("Resources\\obed.wav", SND_ASYNC);

        txBegin();
        for(int i=1; i<5; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, Scene6, 0, 0);

            drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
            if(i%2==0)
            {
                pigEyes=false;
            }else{
                pigEyes=true;
            }
            pigRoth = !pigRoth;
            txSleep(1000);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();

        pigX = 1184;
        pigY = 829;
        pigScale = 3;
        pigEyes = true;

        txPlaySound("Resources\\ubir.wav", SND_ASYNC);

        txBegin();
        for(int i=1; i<3; i++)
        {
            txBitBlt (txDC(), 0, 0, 1400, 800, Scene6, 0, 0);

            drawPig(pigX, pigY, pigEar, pigHand, pigScale, pigEyes, pigLeg, pigLeftArm, pigRoth, pigEarColor, pigNoseColor, pigShirtColor, pigSkinColor);
            if(i%2==0)
            {
                pigEyes=false;
            }else{
                pigEyes=true;
            }
            pigRoth = !pigRoth;
            txSleep(1000);
            txSetFillColor(WHITE);
            txClear();
        }
        txEnd();
        txDeleteDC(Scene6);
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



