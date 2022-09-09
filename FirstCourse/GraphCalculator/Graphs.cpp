    #include "Resources\\Libs\\GraphLib.h"

    enum list {Menu = -2, Off = -1, None = 0, StraightG = 1, ModuleG, ParabolaG, ParabolaBranchG, CubicParabolaG, RadioWavesG, SinusG, TangentG, ArcTangentG};

    void drawning(list graphicOnCanvas, list window, list selectorOver, int coefSelect, double *coefficients, bool soundCheck,bool soundEnable, char *info, button selector, button menu, button down, button up, button kCoef, button aCoef, button bCoef, button cCoef, button firstScaleLvl, button secondScaleLvl, button thirdScaleLvl, button fourthScaleLvl, button fifthScaleLvl, button straight, button module, button parabola, button parabolaBranch, button cubicParabola, button radioWaves, button sinus, button tangent, button arcTangent, button audio, button help, button support, button exit, HDC mainBackground, HDC selectorOn, HDC menuOn, HDC downOff, HDC downOn, HDC upOff, HDC upOn, HDC cfFrame, HDC frame, HDC scalePoint, HDC selectorBackground, HDC allGraphics, HDC straightG, HDC moduleG, HDC parabolaG, HDC parabolaBranchG, HDC cubicParabolaG, HDC radioWavesG, HDC sinusG, HDC tangentG, HDC arcTangentG, HDC menuBackground, HDC menuAll, HDC menuAudio, HDC menuHelper, HDC menuSupport, HDC menuExit, HDC X);
    void keyboardControls(list *graphicOnCanvas, list *window, list *selectorOver, int *coefSelect, double *coefficients, bool *soundCheck, bool *soundEnable, char *info, button selector, button menu, button down, button up, button kCoef, button aCoef, button bCoef, button cCoef, button firstScaleLvl, button secondScaleLvl, button thirdScaleLvl, button fourthScaleLvl, button fifthScaleLvl, button straight, button module, button parabola, button parabolaBranch, button cubicParabola, button radioWaves, button sinus, button tangent, button arcTangent, button audio, button help, button support, button exit);

    int main()
    {
        txCreateWindow(1280, 720);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);
        txTextCursor(FALSE);

        list graphicOnCanvas = None;
        list window = Off;
        list selectorOver = Off;

        int coefSelect = 0;
        double coefficients[5] = {1, 1, 1 , 1, 3};
        bool soundCheck;
        bool soundEnable = true;
        char info[LEN];

        button selector(920, 552, 1276, 621);
        button menu(950, 622, 1280, 720);
        button down(984, 357, 1031, 400);
        button up(984, 290, 1031, 333);

        button kCoef(1077, 334, 1098, 357);  
        button aCoef(1122, 334, 1144, 357);
        button bCoef(1168, 334, 1185, 357);
        button cCoef(1208, 334, 1229, 357);

        button firstScaleLvl(1030, 470, 1035, 489); 
        button secondScaleLvl(1074, 470, 1079, 489);
        button thirdScaleLvl(1117, 470, 1122, 489);
        button fourthScaleLvl(1161, 470, 1166, 489);
        button fifthScaleLvl(1204, 470, 1209, 489);

        button straight(477, 125, 797, 167);
        button module(500, 177, 770, 221);
        button parabola(405, 233, 871, 275);
        button parabolaBranch(471, 272, 859, 329);
        button cubicParabola(360, 341, 913, 383);
        button radioWaves(357, 397, 917, 491);
        button sinus(493, 505, 783, 545);
        button tangent(491, 558, 784, 599);
        button arcTangent(422, 613, 852, 653);

        button audio(426, 108, 921, 175); 
        button help(507, 230, 773, 289); 
        button support(431, 351, 925, 419); 
        button exit(506, 472, 773, 551); 

        HDC mainBackground = txLoadImage("Resources\\Images\\Main\\mainBackground.bmp");
        HDC selectorOn = txLoadImage("Resources\\Images\\Main\\selectorOn.bmp");
        HDC menuOn = txLoadImage("Resources\\Images\\Main\\menuOn.bmp"); 
        HDC downOff = txLoadImage("Resources\\Images\\Main\\downOff.bmp"); 
        HDC downOn = txLoadImage("Resources\\Images\\Main\\downOn.bmp"); 
        HDC upOff = txLoadImage("Resources\\Images\\Main\\upOff.bmp"); 
        HDC upOn = txLoadImage("Resources\\Images\\Main\\upOn.bmp"); 
        HDC cfFrame = txLoadImage("Resources\\Images\\Main\\cfFrame.bmp"); 
        HDC frame = txLoadImage("Resources\\Images\\Main\\frame.bmp"); 
        HDC scalePoint = txLoadImage("Resources\\Images\\Main\\scalePoint.bmp");  

        HDC selectorBackground = txLoadImage("Resources\\Images\\Selector\\selectorBackground.bmp");
        HDC allGraphics = txLoadImage("Resources\\Images\\Selector\\all.bmp");
        HDC straightG = txLoadImage("Resources\\Images\\Selector\\straightG.bmp");
        HDC moduleG = txLoadImage("Resources\\Images\\Selector\\moduleG.bmp");
        HDC parabolaG = txLoadImage("Resources\\Images\\Selector\\parabolaG.bmp");
        HDC parabolaBranchG = txLoadImage("Resources\\Images\\Selector\\parabolaBranchG.bmp");
        HDC cubicParabolaG = txLoadImage("Resources\\Images\\Selector\\cubicParabolaG.bmp");
        HDC radioWavesG = txLoadImage("Resources\\Images\\Selector\\radioWavesG.bmp");
        HDC sinusG = txLoadImage("Resources\\Images\\Selector\\sinusG.bmp");
        HDC tangentG = txLoadImage("Resources\\Images\\Selector\\tangentG.bmp");
        HDC arcTangentG = txLoadImage("Resources\\Images\\Selector\\arcTangentG.bmp");

        HDC menuBackground = txLoadImage("Resources\\Images\\Menu\\menuBackground.bmp");
        HDC menuAll = txLoadImage("Resources\\Images\\Menu\\menuAll.bmp");
        HDC menuAudio = txLoadImage("Resources\\Images\\Menu\\menuAudio.bmp");
        HDC menuHelper = txLoadImage("Resources\\Images\\Menu\\menuHelper.bmp");
        HDC menuSupport = txLoadImage("Resources\\Images\\Menu\\menuSupport.bmp");
        HDC menuExit = txLoadImage("Resources\\Images\\Menu\\menuExit.bmp");
        HDC X = txLoadImage("Resources\\Images\\Menu\\X.bmp");

        while(TRUE)
        {
            txBegin();
            drawning(graphicOnCanvas, window, selectorOver, coefSelect, coefficients, soundCheck, soundEnable, info, selector, menu, down, up, kCoef, aCoef, bCoef, cCoef, firstScaleLvl, secondScaleLvl, thirdScaleLvl, fourthScaleLvl, fifthScaleLvl, straight, module, parabola, parabolaBranch, cubicParabola, radioWaves, sinus, tangent, arcTangent, audio, help, support, exit, mainBackground, selectorOn, menuOn, downOff, downOn, upOff, upOn, cfFrame, frame, scalePoint, selectorBackground, allGraphics, straightG, moduleG, parabolaG, parabolaBranchG, cubicParabolaG, radioWavesG, sinusG, tangentG, arcTangentG, menuBackground, menuAll, menuAudio, menuHelper, menuSupport, menuExit, X);
            txEnd();
            keyboardControls(&graphicOnCanvas, &window, &selectorOver, &coefSelect, coefficients, &soundCheck, &soundEnable, info, selector, menu, down, up, kCoef, aCoef, bCoef, cCoef, firstScaleLvl, secondScaleLvl, thirdScaleLvl, fourthScaleLvl, fifthScaleLvl, straight, module, parabola, parabolaBranch, cubicParabola, radioWaves,  sinus,  tangent, arcTangent, audio, help, support, exit);
            if(exit.IsClicked() and window == Menu)
            {
                txDisableAutoPause();
                txDeleteDC(mainBackground);	
                txDeleteDC(selectorOn);
                txDeleteDC(menuOn);
                txDeleteDC(downOff);
                txDeleteDC(downOn);
                txDeleteDC(upOff);
                txDeleteDC(upOn);
                txDeleteDC(cfFrame);
                txDeleteDC(frame);
                txDeleteDC(scalePoint);
                txDeleteDC(selectorBackground);
                txDeleteDC(allGraphics);
                txDeleteDC(straightG);
                txDeleteDC(moduleG);
                txDeleteDC(parabolaG);
                txDeleteDC(parabolaBranchG);
                txDeleteDC(cubicParabolaG);
                txDeleteDC(radioWavesG);
                txDeleteDC(sinusG);
                txDeleteDC(tangentG);
                txDeleteDC(arcTangentG);
                txDeleteDC(menuBackground);
                txDeleteDC(menuAll);
                txDeleteDC(menuAudio);
                txDeleteDC(menuHelper);
                txDeleteDC(menuSupport);
                txDeleteDC(menuExit);
                txDeleteDC(X);
                return 0;
            }
        }
    }

    void drawning(list graphicOnCanvas, list window, list selectorOver, int coefSelect, double *coefficients, bool soundCheck, bool soundEnable, char *info, button selector, button menu, button down, button up, button kCoef, button aCoef, button bCoef, button cCoef, button firstScaleLvl, button secondScaleLvl, button thirdScaleLvl, button fourthScaleLvl, button fifthScaleLvl, button straight, button module, button parabola, button parabolaBranch, button cubicParabola, button radioWaves, button sinus, button tangent, button arcTangent, button audio, button help, button support, button exit, HDC mainBackground, HDC selectorOn, HDC menuOn, HDC downOff, HDC downOn, HDC upOff, HDC upOn, HDC cfFrame, HDC frame, HDC scalePoint, HDC selectorBackground, HDC allGraphics, HDC straightG, HDC moduleG, HDC parabolaG, HDC parabolaBranchG, HDC cubicParabolaG, HDC radioWavesG, HDC sinusG, HDC tangentG, HDC arcTangentG, HDC menuBackground, HDC menuAll, HDC menuAudio, HDC menuHelper, HDC menuSupport, HDC menuExit, HDC X)
    {
        txSetFillColor(TX_WHITE);
        txClear();
        
        txBitBlt(txDC(), 0, 0, 1280, 720, mainBackground, 0, 0);
        markingBuilder(coefficients[4]);
        graphicsBuilder(graphicOnCanvas, coefficients[0], coefficients[1], coefficients[2], coefficients[3], coefficients[4]);
        information(graphicOnCanvas, info, coefficients);
        txAlphaBlend(txDC(), 0, 0, 1280, 720, frame, 0, 0, 1);

        if(up.IsOver() and window == Off)
        {
            txAlphaBlend(txDC(), 980, 290, 58, 53, upOn, 0, 0, 1);
        }else{
            txAlphaBlend(txDC(), 984, 290, 48, 44, upOff, 0, 0, 1);
        }

        if(down.IsOver() and window == Off)
        {
            txAlphaBlend(txDC(), 980, 357, 58, 53, downOn, 0, 0, 1);
        }else{
            txAlphaBlend(txDC(), 984, 357, 48, 44, downOff, 0, 0, 1);
        }

        if(coefSelect == 1)
        {
            txAlphaBlend(txDC(), 1062, 318, 52, 55, cfFrame, 0, 0, 1);
        }
        if(coefSelect == 2)
        {
            txAlphaBlend(txDC(), 1107, 318, 52, 55, cfFrame, 0, 0, 1);
        }
        if(coefSelect == 3)
        {
            txAlphaBlend(txDC(), 1151, 318, 52, 55, cfFrame, 0, 0, 1);
        }
        if(coefSelect == 4)
        {
            txAlphaBlend(txDC(), 1193, 318, 52, 55, cfFrame, 0, 0, 1);
        }

        switch(window)
        {
            case Menu:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, menuBackground, 0, 0, 1);
                if(!soundEnable)
                {
                    txAlphaBlend(txDC(), 379, 117, 43, 39, X, 0, 0, 1);
                }

                if(audio.IsOver())
                {
                    txAlphaBlend(txDC(), 0, 0, 1280, 720, menuAudio, 0, 0, 1);
                }else{
                if(help.IsOver())
                {
                    txAlphaBlend(txDC(), 0, 0, 1280, 720, menuHelper, 0, 0, 1);
                }else{
                if(support.IsOver())
                {
                    txAlphaBlend(txDC(), 0, 0, 1280, 720, menuSupport, 0, 0, 1);
                }else{
                if(exit.IsOver())
                {
                    txAlphaBlend(txDC(), 0, 0, 1280, 720, menuExit, 0, 0, 1);    
                }else{
                    txAlphaBlend(txDC(), 0, 0, 1280, 720, menuAll, 0, 0, 1);  
                }}}}
                break;
            case None:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                switch(selectorOver)
                {
                    case None:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, allGraphics, 0, 0, 1);
                        break;

                    case StraightG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, straightG, 0, 0, 1);
                        break;

                    case ModuleG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, moduleG, 0, 0, 1);
                        break;
                        
                    case ParabolaG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, parabolaG, 0, 0, 1);
                        break;

                    case ParabolaBranchG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, parabolaBranchG, 0, 0, 1);
                        break;

                    case CubicParabolaG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, cubicParabolaG, 0, 0, 1);
                        break;

                    case RadioWavesG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, radioWavesG, 0, 0, 1);
                        break;

                    case SinusG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, sinusG, 0, 0, 1);
                        break;

                    case TangentG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, tangentG, 0, 0, 1);
                        break;

                    case ArcTangentG:
                        txAlphaBlend(txDC(), 0, 0, 1280, 720, arcTangentG, 0, 0, 1);
                        break;
                }
                break;

            case StraightG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, straightG, 0, 0, 1);
                break;

            case ModuleG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, moduleG, 0, 0, 1);
                break;
                
            case ParabolaG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, parabolaG, 0, 0, 1);
                break;

            case ParabolaBranchG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, parabolaBranchG, 0, 0, 1);
                break;

            case CubicParabolaG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, cubicParabolaG, 0, 0, 1);
                break;

            case RadioWavesG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, radioWavesG, 0, 0, 1);
                break;

            case SinusG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, sinusG, 0, 0, 1);
                break;

            case TangentG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, tangentG, 0, 0, 1);
                break;

            case ArcTangentG:
                txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorBackground, 0, 0, 1);
                txAlphaBlend(txDC(), 0, 0, 1280, 720, arcTangentG, 0, 0, 1);
                break;
        }

        if(selector.IsOver() or (window != Off and window != Menu))
        {
            txAlphaBlend(txDC(), 0, 0, 1280, 720, selectorOn, 0, 0, 1);
        }
        if(menu.IsOver() or window == Menu)
        {
            txAlphaBlend(txDC(), 0, 0, 1280, 720, menuOn, 0, 0, 1);
        }

        if(coefficients[4]==3)
        {//1030 470
            txAlphaBlend(txDC(), 1021, 468, 23, 23, scalePoint, 0, 0, 1);
        }
        if(coefficients[4]==6)
        {//1030 470
            txAlphaBlend(txDC(), 1065, 468, 23, 23, scalePoint, 0, 0, 1);
        }
        if(coefficients[4]==9)
        {//1030 470
            txAlphaBlend(txDC(), 1108, 468, 23, 23, scalePoint, 0, 0, 1);
        }
        if(coefficients[4]==18)
        {//1030 470
            txAlphaBlend(txDC(), 1152, 468, 23, 23, scalePoint, 0, 0, 1);
        }
        if(coefficients[4]==25)
        {//1030 470
            txAlphaBlend(txDC(), 1195, 468, 23, 23, scalePoint, 0, 0, 1);
        }
    }

    void keyboardControls(list *graphicOnCanvas, list *window, list *selectorOver, int *coefSelect, double *coefficients, bool *soundCheck, bool *soundEnable, char *info, button selector, button menu, button down, button up, button kCoef, button aCoef, button bCoef, button cCoef, button firstScaleLvl, button secondScaleLvl, button thirdScaleLvl, button fourthScaleLvl, button fifthScaleLvl, button straight, button module, button parabola, button parabolaBranch, button cubicParabola, button radioWaves, button sinus, button tangent, button arcTangent, button audio, button help, button support, button exit)
    {
        if(!selector.IsOver() and !menu.IsOver() and !straight.IsOver() and !module.IsOver() and !parabola.IsOver() and !parabolaBranch.IsOver() and !cubicParabola.IsOver() and !radioWaves.IsOver() and !sinus.IsOver() and !tangent.IsOver() and !arcTangent.IsOver())
        {
            *soundCheck = true;
        }
        //Over
        if(selector.IsOver())
        {
            if(*soundCheck and (*window == Off or *window == Menu) and *soundEnable)
            {
                txPlaySound("Resources\\Sounds\\Cursor.wav", SND_ASYNC);
                *soundCheck = false;
            }
        }
            
        if(*window == None)
        {
            if(straight.IsOver())
            {
                *selectorOver = StraightG;
            }else{
            if(module.IsOver())
            {
                *selectorOver = ModuleG;
            }else{
            if(parabola.IsOver())
            {
                *selectorOver = ParabolaG;
            }else{
            if(parabolaBranch.IsOver())
            {
                *selectorOver = ParabolaBranchG;
            }else{
            if(cubicParabola.IsOver())
            {
                *selectorOver = CubicParabolaG;
            }else{
            if(radioWaves.IsOver())
            {
                *selectorOver = RadioWavesG;
            }else{
            if(sinus.IsOver())
            {
                *selectorOver = SinusG;
            }else{
            if(tangent.IsOver())
            {
                *selectorOver = TangentG;
            }else{
            if(arcTangent.IsOver())
            {
                *selectorOver = ArcTangentG;
            }else{
                *selectorOver = None;
            }}}}}}}}}
        }

        if(menu.IsOver())
        {
            if(*soundCheck and *window != Menu and *soundEnable)
            {
                txPlaySound("Resources\\Sounds\\Cursor.wav", SND_ASYNC);
                *soundCheck = false;
            }
        }

        if(kCoef.IsClicked() and *window == Off)
        {
            *coefSelect = 1;
        }
        if(aCoef.IsClicked() and *window == Off)
        {
            *coefSelect = 2;
        }
        if(bCoef.IsClicked() and *window == Off)
        {
            *coefSelect = 3;
        }
        if(cCoef.IsClicked() and *window == Off)
        {
            *coefSelect = 4;
        }

        if(up.IsClicked() and *window == Off)
        {
            switch(*coefSelect)
            {
                case 1:
                    coefficients[0] = coefficients[0]+0.1;
                    break;
                case 2:
                    coefficients[1] = coefficients[1]+0.1;
                    break;
                case 3:
                    coefficients[2] = coefficients[2]+0.1;
                    break;
                case 4:
                    coefficients[3] = coefficients[3]+0.1;
                    break;
            }
        }

        if(down.IsClicked() and *window == Off)
        {
            switch(*coefSelect)
            {
                case 1:
                    coefficients[0] = coefficients[0]-0.1;
                    break;
                case 2:
                    coefficients[1] = coefficients[1]-0.1;
                    break;
                case 3:
                    coefficients[2] = coefficients[2]-0.1;
                    break;
                case 4:
                    coefficients[3] = coefficients[3]-0.1;
                    break;
            }
        }

        if(selector.IsClicked())
        {
            if(*window == Off)
            {
                *window = *graphicOnCanvas;
                Sleep(200);
            }else{
                *window = Off;
                Sleep(200);
            }
        }
        
        if(straight.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = StraightG;
            *window = StraightG;
        }
        if(module.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = ModuleG;
            *window = ModuleG;
        }
        if(parabola.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = ParabolaG;
            *window = ParabolaG;
        }
        if(parabolaBranch.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = ParabolaBranchG;
            *window = ParabolaBranchG;
        }
        if(cubicParabola.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = CubicParabolaG;
            *window = CubicParabolaG;
        }
        if(radioWaves.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = RadioWavesG;
            *window = RadioWavesG;
        }
        if(sinus.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = SinusG;
            *window = SinusG;
        }
        if(tangent.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = TangentG;
            *window = TangentG;
        }
        if(arcTangent.IsClicked() and *window != Off and *window != Menu)
        {
            *graphicOnCanvas = ArcTangentG;
            *window = ArcTangentG;
        }

        if(menu.IsClicked())
        {
            if(*window != Menu)
            {
                *window = Menu;
                Sleep(200);
            }else{
                *window = Off;
                Sleep(200);
            }
        }
        if(*window == Menu)
        {
            if(audio.IsClicked())
            {
                *soundEnable = !*soundEnable;
                Sleep(200);
            }
            if(help.IsClicked())
            {
                
            }
            if(support.IsClicked())
            {
                printf("%i", 12);
                system("explorer https://vk.com/cat_dev");
                Sleep(1000);
            }
        }

        if(firstScaleLvl.IsClicked() and *window == Off)
        {
            coefficients[4] = 3;
        }
        if(secondScaleLvl.IsClicked() and *window == Off)
        {
            coefficients[4] = 6;
        }
        if(thirdScaleLvl.IsClicked() and *window == Off)
        {
            coefficients[4] = 9;
        }
        if(fourthScaleLvl.IsClicked() and *window == Off)
        {
            coefficients[4] = 18;
        }
        if(fifthScaleLvl.IsClicked() and *window == Off)
        {
            coefficients[4] = 25;
        }
    }