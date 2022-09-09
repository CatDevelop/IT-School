//!Все используемые цвета
enum colorsFines {
    HAIRFINES01, ///< RGB(238, 91, 71)
    HAIRFINES02, ///< RGB(142, 67, 61), светло-коричневый
    SKINFINES01, ///< RGB(253, 227, 202), бежевый, кожа
    SKINFINES02, ///< RGB(194, 154, 93), бледно-коричневый
    TSHIRTFINES01, ///<  RGB(251, 149, 12), ярко-оранжевый
    TSHIRTFINES02, ///<  RGB(255, 243, 191), бледно-бежевый
    STROKEFINES01, ///< RGB(152, 104, 0), коричнево-желтый
    PANTSFINES01, ///< RGB(7, 69, 130), ярко-синий
    SHOESFINES01, ///< RGB(7, 75, 148), чуть более яркий синий
    SHOESFINES02, ///< RGB(218, 220, 232), ярко-серый
    SHOELACESFINES01, ///< RGB(255, 255,248), белый
    YEYFINES01, ///< RGB(240, 240, 240), ярко-бело-серый
    YEYFINES02, ///< RGB(39, 35, 109), темно-синий
    YEYFINES03, ///< RGB(124, 114, 102), бледно-серый
};
enum colorsJake {
    STROKEJAKE01, ///< RGB(11, 13, 10), черный
    SKINJAKE, ///< RGB(251, 203, 33), ярко-желтый
    SKINJAKE02, ///< RGB(241, 223, 53), бледно-желтый
    SKINJAKE03, ///< RGB(241, 243, 73), более бледно-желтый
    EYEJAKE01, ///< RGB(251, 251, 253), белый
    EYEJAKE02, ///< RGB(12, 14, 11), черный
    MOUTHJAKE01, ///< RGB(248, 150, 189), розовый
    MOUTHJAKE02, ///< RGB(200, 23, 36), ярко-красный
};
enum colorsDagget {
    SKINDAGGET01, ///< RGB(135, 76, 51), ярко-коричневый
    SKINDAGGET02, ///< RGB(165, 106, 81), бледно-коричневый
    SKINDAGGET03, ///< RGB(195, 136, 111), очень бледно-коричневый
    STROKEDAGGET01, ///< RGB(36, 6, 0), очень темно-коричневый
    STROKEDAGGET02, ///< RGB(37, 6, 0), очень темно-коричневый
    NOSEDAGGET01, ///< RGB(209, 23, 36), очень ярко-красный
    EYEDAGGET01, ///< RGB(253, 245, 121), очень бледно-желтый
    TEETHDAGGET01, ///< RGB(255, 255, 255), белый
};
enum colorsMario {
    CAPMARIO01, ///< RGB(254, 0, 0), ярко-красный
    SKINMARIO01, ///< RGB(231, 156, 44), темно-желтый
    PANTSMARIO01, ///< RGB(0, 0, 254), ярко-синий
    HAIRMARIO01, ///< RGB(96, 56, 20), коричневый
    HAIRMARIO02, ///< RGB(56, 36, 20), темно-коричневый
    HAIRMARIO03, ///< RGB(116, 66, 20), ярко-коричневый
    TSHIRTMARIO01, ///< RGB(234, 0, 0), красный
    BOOTSMARIO01, ///< RGB(91, 53, 19), коричневый
    EYESMARIO02, ///< RGB(107, 142, 35), бледно-зеленый
    EYESMARIO03, ///< RGB(70, 130, 180), голубой
    FACEMARIO01, ///< RGB(251, 176, 59), желтый
};
enum colorsCJ {
    STROKECJ01, ///< RGB(14, 0, 0), черный
    SKINCJ01, ///< RGB(132, 79, 48), коричневый
    SKINCJ02, ///< RGB(255, 228, 196), бледно-бежевый
    HAIRCJ01, ///< RGB(29, 14, 9), темно-коричневый
    SHIRTCJ01, ///< RGB(254, 254, 254), белый
    REDSHIRTCJ, ///< RGB(178, 34, 34), красный
    ORANGESHIRTCJ, ///< RGB(255, 140, 0), оранжевый
    YELLOWSHIRTCJ, ///< RGB(255, 255, 0), желтый
    BROWNSHIRTCJ, ///< RGB(139, 69, 19), коричневый
    GREENSHIRTCJ, ///< RGB(0, 128, 0), зеленый
    BLUESHIRTCJ, ///< RGB(0, 128, 128), голуюой
    JEANSCJ01, ///< RGB(102, 114, 130), серый
    BOOTSCJ01, ///< RGB(26, 26, 26), немного светлый черный
    MOUTHCJ01, ///< RGB(150, 96, 60), бледно-коричневый
};
enum colorsMike {
    EYEMIKE01, ///< RGB(245, 245, 245), белый
    EYEMIKE02, ///< RGB(12, 93, 60), зеленый
    EYEMIKE03, ///< RGB(0, 3, 2), черный
    SKINMIKE01, ///< RGB(113, 152, 37), светло-зеленый
    HORNMIKE01, ///< RGB(174, 170, 106), какой-то странный серо-зеленый
    MOUTHMIKE01, ///< RGB(21, 30, 13), очень темно-зеленый
    STROKEMIKE01, ///< RGB(5, 10, 3), черный
};


/*!
    \brief Рисует персонажа Финеса.
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.
    \param[in] shoesFines Размер правого кроссовка Финеса.
    \param[in] pantsFines Длинна шорт Финеса.
    \param[in] mood Настроение Финеса.
    True - улыбается, False - грустит.
    \param[in] eyesFines Открыть/закрыть глаза Финеса.
    True - глаза открыты, False - глаза открыты.
    \param[in] haireFines Рисовать/не рисовать волосы Финеса.
    True - волсы рисуются, False - волосы не рисуются.
    \param[in] reverseColor Поменять местами цвет футболки и шорт.
    True - шорты синие, футболка оранжевая, False - шорты оранжевые, футболка синяя.
    \param[in] legsFines Рисовать/не рисовать ноги Финеса.
    True - шорты, ноги, кроссовки рисуются, False - шорты, ноги, кроссовки не рисуются.
    \param[in] bodyFines Рисовать/не рисовать туловище Финеса.
    True - голова, торс, руки, футболка рисуются, False - голова, торс, руки, футболка рисуются.
    \param[in] scaleFines Масштаб персонажа.
    \warning Параметр shoesFines изменяет размер только правого кроссовка.
    P.S. сохраняйтесь чаще.

    \usage \code
    drawFines(int x, int y, double shoesFines, double pantsFines, bool mood, bool eyesFines, bool hairFines, bool reverseColor, bool legsFines, bool bodyFines, double scaleFines)
    \endcode
*/
void drawFines(int x, int y, double shoesFines, double pantsFines, bool  mood, bool eyesFines, bool hairFines, bool reverseColor, bool legsFines, bool bodyFines, double scaleFines);

/*!
    \brief Рисует персонажа Джейка.
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.
    \param[in] eyeJake Размер глаз Джейка.
    \param[in] colorJake Цвет Джейка.
    0 - оригинальный цвет, 1 - высветвленный цвет, 2 - высветленный х2 цвет.
    \param[in] noseJake Рисовать/не рисовать нос Джейка.
    True - рисовать нос, False - не рисовать нос.
    \param[in] mouthJake Рот Джейка закрыт/открыт.
    True - рот закрыт, False - рот открыт.
    \param[in] armsJake Рисовать/не рисовать руки Джейка.
    True - рисовать руки, False - не рисовать руки.
    \param[in] headJake Размер головы Джейка.
    \param[in] earsJake Рисовать/не рисовать уши Джейка.
    True - рисовать уши, False - руки подняты.
    \param[in] armsUpJake Руки Джейка опущены/подняты.
    True - руки опущены, False - руки подняты.
    \param[in] scaleJake Масштаб персонажа.

    \usage \code
    drawJake(int x, int y, double eyeJake, int colorJake, bool noseJake, bool mouthJake, bool armsJake, double headJake, bool earsJake, bool armsUpJake, double scaleJake);
    \endcode
*/
void drawJake(int x, int y, double eyeJake, int colorJake, bool noseJake, bool mouthJake, bool armsJake, double headJake, bool earsJake, bool armsUpJake, double scaleJake);

/*!
    \brief Рисует персонажа Даггета.
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.
    \param[in] eyeDagget Размер глаз Даггета.
    \param[in] teethDagget Размер зуов Даггета.
    \param[in] hairDagget Рисовать/не рисовать волосы Даггета.
    True - рисовать волосы, False - не рисовать волосы.
    \param[in] handsDagget Размер верхних лап Даггета.
    \param[in] legsDagget Размер верхних лап Даггета.
    \param[in] colorDagget Цвет Даггета.
    0 - оригинальный цвет, 1 - высветвленный цвет, 2 - высветленный х2 цвет.
    \param[in] noseDagget Рисовать/не рисовать нос Даггета.
    True - рисовать нос, False - не рисовать нос.
    \param[in] legsHandsDagget Рисовать/не рисовать лапы Даггета.
    True - рисовать лапы, False - не рисовать лапы.
    \param[in] scaleDagget Масштаб персонажа.

    \usage \code
    drawDagget(double x, double y, double eyeDagget, double teethDagget, bool hairDagget, double handsDagget, double legsDagget, int colorDagget, bool noseDagget, bool legsHandsDagget, double scaleDagget);
    \endcode
*/
void drawDagget(double x, double y, double eyeDagget, double teethDagget, bool hairDagget, double handsDagget, double legsDagget, int colorDagget, bool noseDagget, bool legsHandsDagget, double scaleDagget);

/*!
    \brief Рисует персонажа Марио.
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.
    \param[in] capMario Кепка направлена в правую/левую сторону.
    True - кепка нправлена в правую сторону, False - кепка нправлена в левую сторону,
    \param[in] mustacheMario Рисовать/не рисовать усы Марио.
    True - рисовать усы, False - не рисовать усы.
    \param[in] hairMario Меняет цвет волос Марио
    0 - Оригинальный цвет, 1 - темный цвет, 2 - ствелый цвет.
    \param[in] eyesMario Меняет цвет глаз Марио.
    "dark" - темный цвет глаз, "green" - зеленый цвет глаз, "blue" - голубой цвет глаз.
    \param[in] handsUpMario Руки Марио подняты/опущены.
    \param[in] bootsMario Размер ботинок.
    \param[in] pantsMario Рисовать комбинизон/джинсы.
    True - рисовать комбинизон, False - рисовать джинсы.
    \param[in] headMario Рисовать/не рисовать голову Даггета.
    True - рисовать голову, False - не рисовать голову.
    \param[in] scaleMario Масштаб персонажа.

    \usage \code
    void drawMario(int x, int y, bool capMario, bool mustacheMario, int hairMario, string eyesMario, bool handsUpMario, int bootsMario, bool pantsMario, bool headMario, double scaleMario);
    \endcode
*/
void drawMario(int x, int y, bool capMario, bool mustacheMario, int hairMario, string eyesMario, bool handsUpMario, int bootsMario, bool pantsMario, bool headMario, double scaleMario);

/*!
    \brief Рисует персонажа CJ.
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.
    \param[in] mouthCJ Рот закрыт/веселый/грустный.
    0 - рот закрыт, 1 - веселый, 2 - грустный.
    \param[in] colorCJ Цвет кожи темный/светлый.
    True - темный, False - светлый.
    \param[in] colorShirtCJ Цвет майки CJ.
    "red" - красный, "orange" - оранжевый, "yellow" - желтый, "brown" - коричневый, "green"- зеленый, "blue" - синий.
    \param[in] legsCJ Рисовать/не рисовать ноги CJ.
    True - рисовать ноги, джинсы, кроссовки, False - не рисовать ноги, джинсы, кроссовки.
    \param[in] faceCJ Рисовать/не рисовать лицо.
    Е
    \param[in] eyesCJ Размер глаз CJ.
    \param[in] hairCJ CJ с волосами/лысый.
    True - с волосами, False - лысый
    \param[in] bodyCJ Рисовать/не рисовать туловище Даггета.
    True - рисовать туловище, False - не рисовать туловище.
    \param[in] scaleCJ Масштаб персонажа.

    \usage \code
    drawCJ(int x, int y, int mouthCJ, bool colorCJ, string colorShirtCJ, bool legsCJ, bool faceCJ, double eyesCJ, bool hairCJ, bool bodyCJ, double scaleCJ);
    \endcode
*/
void drawCJ(int x, int y, int mouthCJ, bool colorCJ, string colorShirtCJ, bool legsCJ, bool faceCJ, double eyesCJ, bool hairCJ, bool bodyCJ, double scaleCJ);

/*!
    \brief Рисует Майка Вазовски.
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.
    \param[in] eyeMike Размер глаз(а).
    \param[in] hornMike Длинна рогов.
    \param[in] doubleEyesMike Рисовать два/один глаз.
    TRUE - рисовать 2 глаза, FALSE - рисовать 1 глаз.
    \param[in] mouthOpenMike Рот Майка открыт/закрыт.
    TRUE - рот открыт, FALSE - рот закрыт.
    \param[in] colorMike Цвет Майка оригинальный/накуренный.
    TRUE - оригинальный цвет, FALSE - накуренный цвет.
    \param[in] doubleFingersLegs Рисовать два/три пальца на ногах.
    TRUE - два пальца на ногах, FALSE - три пальца на ногах.
    \param[in] scaleMile Масштаб персонажа.

    \usage \code
    drawMike(int x, int y, double eyeMike, double hornMike, bool doubleEyesMike, bool mouthOpenMike, bool colorMike, bool doubleFingersLegs, double scaleMike);
    \endcode
*/
void drawMike(int x, int y, double eyeMike, double hornMike, bool doubleEyesMike, bool mouthOpenMike, bool colorMike, bool doubleFingersLegs, double scaleMike);

/*!
    \brief Рисует фон (земля, деревья, небо, облака).
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.

    \usage \code
    drawBackground(int x, int y);
    \endcode
*/
void drawBackground(int x, int y);

/*!
    \brief Рисует окно диалога.
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.
    \param[in] scaleDialog Размер диалогового окна.

    \usage \code
    drawDialog(int x, int y, double scaleDialog);
    \endcode
*/

void drawDialog(int x, int y, double scaleDialog);

/*!
    \brief Рисует трубу Марио.
    \param[in] x X-координата крайней левой точки.
    \param[in] y Y-координата крайней верхней точки.
    \param[in] scalePipe Размер трубы.

    \usage
    \code
    drawPipe(int x, int y, double scalePipe);
    \endcode
*/
void drawPipe(int x, int y, double scalePipe);

void drawFines(int x, int y, double shoesFines, double pantsFines, bool mood, bool eyesFines, bool hairFines, bool reverseColor, bool legsFines, bool bodyFines, double scaleFines){
    COLORREF HAIRFINES01 = RGB(238, 91, 71);
    COLORREF HAIRFINES02 = RGB(142, 67, 61);
    COLORREF SKINFINES01 = RGB(253, 227, 202);
    COLORREF SKINFINES02 = RGB(194, 154, 93);
    COLORREF TSHIRTFINES01 = RGB(251, 149, 12);
    COLORREF TSHIRTFINES02 = RGB(255, 243, 191);
    COLORREF STROKEFINES01 = RGB(152, 104, 0);
    COLORREF PANTSFINES01 = RGB(7, 69, 130);
    COLORREF SHOESFINES01 = RGB(7, 75, 148);
    COLORREF SHOESFINES02 = RGB(218, 220, 232);
    COLORREF SHOELACESFINES01 = RGB(255, 255,248);
    COLORREF YEYFINES01 = RGB(240, 240, 240);
    COLORREF YEYFINES02 = RGB(39, 35, 109);
    COLORREF YEYFINES03 = RGB(124, 114, 102);
    if (bodyFines){
        //hair
        if (hairFines){
            txSetColor(HAIRFINES02);
            txSetFillColor(HAIRFINES01);
            POINT hairfines[13]= {{x+15*scaleFines, y+41*scaleFines}, {x+9*scaleFines, y+51*scaleFines}, {x+7*scaleFines, y+46*scaleFines}, {x+5*scaleFines, y+59*scaleFines}, {x+5*scaleFines, y+45*scaleFines}, {x-9*scaleFines, y+49*scaleFines}, {x-1*scaleFines, y+33*scaleFines}, {x+3*scaleFines, y+5*scaleFines}, {x+10*scaleFines, y+13*scaleFines}, {x+24*scaleFines, y+4*scaleFines}, {x+15*scaleFines, y+16*scaleFines}, {x+30*scaleFines, y+16*scaleFines}, {x+19*scaleFines, y+29*scaleFines}};
            txPolygon(hairfines, 13);
        }
        // Ear
        txSetColor(SKINFINES02);
        txSetFillColor(SKINFINES01);
        txCircle(x+33*scaleFines, y+67*scaleFines, 10*scaleFines);
        txSetColor(SKINFINES01);
        txCircle(x+33*scaleFines, y+67*scaleFines, 9*scaleFines);

        //right eye
        if (eyesFines){
            txSetColor(YEYFINES03);
            txSetFillColor(YEYFINES01);
            txEllipse(x+54*scaleFines, y+25*scaleFines, x+89*scaleFines, y+54*scaleFines);
            txSetFillColor(YEYFINES02);
            txEllipse(x+74*scaleFines, y+28*scaleFines, x+82*scaleFines, y+39*scaleFines);
            txSetFillColor(YEYFINES01);
            txRectangle(x+81*scaleFines, y+29*scaleFines, x+82*scaleFines, y+32*scaleFines);
        }
        else{
            txSetColor(SKINFINES02);
            txSetFillColor(SKINFINES01);
            txEllipse(x+54*scaleFines, y+25*scaleFines, x+90*scaleFines, y+54*scaleFines);
            txArc(x-28*scaleFines, y-197*scaleFines, x+172*scaleFines, y+36*scaleFines, 261, 17);
        }
        // head
        txSetColor(SKINFINES02);
        txSetFillColor(SKINFINES01);
        POINT headfines[10]= {{x+50*scaleFines, y+108*scaleFines}, {x+45*scaleFines, y+86*scaleFines}, {x+40*scaleFines, y+73*scaleFines}, {x+32*scaleFines, y+61*scaleFines}, {x+8*scaleFines, y+39*scaleFines}, {x+7*scaleFines, y+35*scaleFines}, {x+10*scaleFines, y+28*scaleFines}, {x+125*scaleFines, y+45*scaleFines}, {x+60*scaleFines, y+105*scaleFines}, {x+57*scaleFines, y+108*scaleFines}};
        txPolygon(headfines, 10);

        //mouth
        if (mood){
            txArc(x+47*scaleFines, y+79*scaleFines, x+127*scaleFines, y+41*scaleFines, 200, 80);
        }
        else{
            txArc(x+42*scaleFines, y+79*scaleFines, x+122*scaleFines, y+117*scaleFines, 70, 80);
        }
        txSetColor(SKINFINES01);
        txCircle(x+33*scaleFines, y+67*scaleFines, 9);

        //left eye
        if (eyesFines){
            txSetColor(YEYFINES03);
            txSetFillColor(YEYFINES01);
            txEllipse(x+42*scaleFines, y+22*scaleFines, x+77*scaleFines, y+51*scaleFines);
            txSetFillColor(YEYFINES02);
            txEllipse(x+55*scaleFines, y+30*scaleFines, x+64*scaleFines, y+41*scaleFines);
            txSetFillColor(YEYFINES01);
            txRectangle(x+63*scaleFines, y+33*scaleFines, x+59*scaleFines, y+38*scaleFines);
        }
        else{
            txSetColor(SKINFINES02);
            txSetFillColor(SKINFINES01);
            txEllipse(x+42*scaleFines, y+22*scaleFines, x+77*scaleFines, y+51*scaleFines);
            txArc(x-40*scaleFines, y-200*scaleFines, x+160*scaleFines, y+36*scaleFines, 261, 17);
        }

        //body
        txSetColor(SKINFINES02);
        txSetFillColor(SKINFINES01);

        //left hand
        POINT lefthandfines[15]={{x+28*scaleFines, y+118*scaleFines}, {x+3*scaleFines, y+134*scaleFines}, {x-4*scaleFines, y+136*scaleFines}, {x-9*scaleFines, y+141*scaleFines}, {x-14*scaleFines, y+142*scaleFines}, {x-14*scaleFines, y+145*scaleFines}, {x-11*scaleFines, y+146*scaleFines}, {x-7*scaleFines, y+144*scaleFines}, {x-9*scaleFines, y+154*scaleFines}, {x-6*scaleFines, y+164*scaleFines}, {x-4*scaleFines, y+164*scaleFines}, {x-1*scaleFines, y+163*scaleFines}, {x+5*scaleFines, y+147*scaleFines}, {x+6*scaleFines, y+139*scaleFines}, {x+34*scaleFines, y+122*scaleFines}};
        txPolygon(lefthandfines, 15);
        txLine(x-7*scaleFines, y+163*scaleFines, x-5*scaleFines, y+150*scaleFines);
        txLine(x-3*scaleFines, y+163*scaleFines, x-2*scaleFines, y+150*scaleFines);
        txLine(x-2*scaleFines, y+145*scaleFines, x-2*scaleFines, y+138*scaleFines);

        //right hand
        POINT righthandfines[14]={{x+82*scaleFines, y+117*scaleFines}, {x+103*scaleFines, y+128*scaleFines}, {x+109*scaleFines, y+128*scaleFines},  {x+115*scaleFines, y+133*scaleFines}, {x+121*scaleFines, y+133*scaleFines}, {x+120*scaleFines, y+136*scaleFines}, {x+113*scaleFines, y+136*scaleFines}, {x+113*scaleFines, y+141*scaleFines}, {x+116*scaleFines, y+152*scaleFines}, {x+115*scaleFines, y+156*scaleFines}, {x+109*scaleFines, y+157*scaleFines}, {x+101*scaleFines, y+139*scaleFines}, {x+97*scaleFines, y+130*scaleFines}, {x+76*scaleFines, y+120*scaleFines}};
        txPolygon(righthandfines, 14);
        txLine(x+112*scaleFines, y+156*scaleFines,  x+108*scaleFines, y+145*scaleFines);
        txLine(x+115*scaleFines, y+156*scaleFines, x+111*scaleFines, y+145*scaleFines);
        txLine(x+109*scaleFines, y+141*scaleFines, x+106*scaleFines, y+128*scaleFines);
    }

    if (legsFines){
        //left leg
        txSetColor(SKINFINES02);
        txSetFillColor(SKINFINES01);
        POINT leftleg[4]={{x+40*scaleFines, y+190*scaleFines}, {x+31*scaleFines, y+218*scaleFines}, {x+35*scaleFines, y+219*scaleFines}, {x+46*scaleFines, y+191*scaleFines}};
        txPolygon(leftleg, 4);
        //right leg
        txSetColor(SKINFINES02);
        txSetFillColor(SKINFINES01);
        POINT rightleg[4]={{x+64*scaleFines, y+190*scaleFines}, {x+60*scaleFines, y+219*scaleFines}, {x+66*scaleFines, y+219*scaleFines}, {x+69*scaleFines, y+191*scaleFines}};
        txPolygon(rightleg, 4);

        //pants
        if (reverseColor){
            txSetColor(STROKEFINES01);
            txSetFillColor(TSHIRTFINES01);
            POINT pantsfines[9]={{x+40*scaleFines, y+159*scaleFines}, {x+37*scaleFines, y+(182+2*pantsFines)*scaleFines}, {x+32*scaleFines, y+(191+4*pantsFines)*scaleFines}, {x+44*scaleFines, y+(195+5*pantsFines)*scaleFines}, {x+57*scaleFines, y+(195+5*pantsFines)*scaleFines}, {x+57*scaleFines, y+(193+5*pantsFines)*scaleFines}, {x+79*scaleFines, y+(194+5*pantsFines)*scaleFines}, {x+81*scaleFines, y+(182+2*pantsFines)*scaleFines}, {x+78*scaleFines, y+160*scaleFines}};
            txPolygon(pantsfines, 9);
            txLine(x+58*scaleFines, y+(193+4*pantsFines)*scaleFines, x+58*scaleFines, y+158*scaleFines);
        }
        else{
            txSetColor(STROKEFINES01);
            txSetFillColor(PANTSFINES01);
            POINT pantsfines[9]={{x+40*scaleFines, y+159*scaleFines}, {x+37*scaleFines, y+(182+2*pantsFines)*scaleFines}, {x+32*scaleFines, y+(191+4*pantsFines)*scaleFines}, {x+44*scaleFines, y+(195+5*pantsFines)*scaleFines}, {x+57*scaleFines, y+(195+5*pantsFines)*scaleFines}, {x+57*scaleFines, y+(193+5*pantsFines)*scaleFines}, {x+79*scaleFines, y+(194+5*pantsFines)*scaleFines}, {x+81*scaleFines, y+(182+2*pantsFines)*scaleFines}, {x+78*scaleFines, y+160*scaleFines}};
            txPolygon(pantsfines, 9);
            txLine(x+58*scaleFines, y+(193+5*pantsFines)*scaleFines, x+58*scaleFines, y+158*scaleFines);
        }

    //t-shirt
    if (bodyFines){
        if (reverseColor){
            txSetColor(STROKEFINES01);
            txSetFillColor(PANTSFINES01);
            POINT tshirtfines[15]={{x+50*scaleFines, y+105*scaleFines}, {x+60*scaleFines, y+106*scaleFines}, {x+84*scaleFines, y+117*scaleFines}, {x+73*scaleFines, y+131*scaleFines}, {x+65*scaleFines, y+116*scaleFines}, {x+83*scaleFines, y+162*scaleFines}, {x+72*scaleFines, y+166*scaleFines}, {x+53*scaleFines, y+165*scaleFines}, {x+38*scaleFines, y+165*scaleFines}, {x+42*scaleFines, y+144*scaleFines}, {x+48*scaleFines, y+118*scaleFines}, {x+42*scaleFines, y+124*scaleFines}, {x+36*scaleFines, y+132*scaleFines}, {x+24*scaleFines, y+120*scaleFines}, {x+36*scaleFines, y+111*scaleFines}};
            txPolygon(tshirtfines, 15);
        }
        else{
            txSetColor(STROKEFINES01);
            txSetFillColor(TSHIRTFINES01);
            POINT tshirtfines[15]={{x+50*scaleFines, y+105*scaleFines}, {x+60*scaleFines, y+106*scaleFines}, {x+84*scaleFines, y+117*scaleFines}, {x+73*scaleFines, y+131*scaleFines}, {x+65*scaleFines, y+116*scaleFines}, {x+83*scaleFines, y+162*scaleFines}, {x+72*scaleFines, y+166*scaleFines}, {x+53*scaleFines, y+165*scaleFines}, {x+38*scaleFines, y+165*scaleFines}, {x+42*scaleFines, y+144*scaleFines}, {x+48*scaleFines, y+118*scaleFines}, {x+42*scaleFines, y+124*scaleFines}, {x+36*scaleFines, y+132*scaleFines}, {x+24*scaleFines, y+120*scaleFines}, {x+36*scaleFines, y+111*scaleFines}};
            txPolygon(tshirtfines, 15);
        }
    }
        if (legsFines){
            //left shoe
            txSetColor(STROKEFINES01);
            txSetFillColor(SHOESFINES01);
            POINT leftshoefines01[11]={{x+30*scaleFines, y+217*scaleFines}, {x+28*scaleFines, y+219*scaleFines}, {x+(26-5*shoesFines)*scaleFines, y+219*scaleFines}, {x+(17-7*shoesFines)*scaleFines, y+219*scaleFines}, {x+(14-10*shoesFines)*scaleFines, y+220*scaleFines}, {x+(16-7*shoesFines)*scaleFines, y+(224+1*shoesFines)*scaleFines}, {x+(17+1*shoesFines)*scaleFines, y+(229+2*shoesFines)*scaleFines}, {x+29*scaleFines, y+(228+2*shoesFines)*scaleFines}, {x+36*scaleFines, y+(226+1*shoesFines)*scaleFines}, {x+35*scaleFines, y+220*scaleFines}, {x+35*scaleFines, y+219*scaleFines}};
            txPolygon(leftshoefines01, 11);

            txSetFillColor(SHOESFINES02);
            POINT leftshoefines02[7]={{x+(14-10*shoesFines)*scaleFines, y+221*scaleFines},{x+(17-7*shoesFines)*scaleFines, y+(224+1*shoesFines)*scaleFines}, {x+(17-7*shoesFines)*scaleFines, y+(229+2*shoesFines)*scaleFines}, {x+(6-10*shoesFines)*scaleFines,y+(229+2*shoesFines)*scaleFines}, {x+(4-11*shoesFines)*scaleFines, y+(228+2*shoesFines)*scaleFines}, {x+(4-11*shoesFines)*scaleFines, y+(226+1*shoesFines)*scaleFines}, {x+(8-9*shoesFines)*scaleFines, y+222*scaleFines}};
            txPolygon(leftshoefines02,7);

            POINT leftshoefines03[10]={{x+(4-11*shoesFines)*scaleFines, y+(228+2*shoesFines)*scaleFines}, {x+(7-10*shoesFines)*scaleFines, y+(229+2*shoesFines)*scaleFines}, {x+21*scaleFines, y+(229+2*shoesFines)*scaleFines}, {x+31*scaleFines, y+(228+2*shoesFines)*scaleFines}, {x+35*scaleFines, y+(226+2*shoesFines)*scaleFines}, {x+37*scaleFines, y+(228+2*shoesFines)*scaleFines}, {x+34*scaleFines, y+(230+2*shoesFines)*scaleFines}, {x+25*scaleFines, y+(232+2*shoesFines)*scaleFines}, {x+(9-10*shoesFines)*scaleFines, y+(233+2*shoesFines)*scaleFines}, {x+(4-11*shoesFines)*scaleFines, y+(231+2*shoesFines)*scaleFines}};
            txPolygon(leftshoefines03, 10);

            //right shoe
            txSetColor(STROKEFINES01);
            txSetFillColor(SHOESFINES01);
            POINT rightshoefines01[10]={{x+65*scaleFines, y+218*scaleFines}, {x+66*scaleFines, y+220*scaleFines}, {x+(73+5*shoesFines)*scaleFines, y+221*scaleFines}, {x+(77+7*shoesFines)*scaleFines, y+222*scaleFines}, {x+(75+10*shoesFines)*scaleFines, y+224*scaleFines}, {x+(74+7*shoesFines)*scaleFines, y+(229+1*shoesFines)*scaleFines}, {x+(63-1*shoesFines)*scaleFines, y+(228+2*shoesFines)*scaleFines}, {x+56*scaleFines, y+(226+2*shoesFines)*scaleFines}, {x+59*scaleFines, y+(221+1*shoesFines)*scaleFines}, {x+59*scaleFines, y+217*scaleFines}};
            txPolygon(rightshoefines01, 10);

            txSetFillColor(SHOESFINES02);
            POINT rightshoefines02[5]={{x+(77+10*shoesFines)*scaleFines, y+222*scaleFines}, {x+(83+7*shoesFines)*scaleFines, y+(226+1*shoesFines)*scaleFines}, {x+(83+7*shoesFines)*scaleFines, y+(229+2*shoesFines)*scaleFines}, {x+74*scaleFines, y+229*scaleFines}, {x+74*scaleFines, y+226*scaleFines}};
            txPolygon(rightshoefines02, 5);

            POINT rightshoefines03[9]={{x+(56+11*shoesFines)*scaleFines, y+(227+2*shoesFines)*scaleFines}, {x+(64+10*shoesFines)*scaleFines, y+(228+2*shoesFines)*scaleFines}, {x+67*scaleFines, y+(229+2*shoesFines)*scaleFines}, {x+81*scaleFines, y+(229+2*shoesFines)*scaleFines}, {x+83*scaleFines, y+(228+2*shoesFines)*scaleFines}, {x+83*scaleFines, y+(231+2*shoesFines)*scaleFines}, {x+82*scaleFines, y+(232+2*shoesFines)*scaleFines}, {x+62*scaleFines, y+(232+2*shoesFines)*scaleFines}, {x+56*scaleFines, y+231*scaleFines}};
            txPolygon(rightshoefines03, 9);
        }


    }
}
void drawJake(int x, int y, double eyeJake, int colorJake, bool noseJake, bool mouthJake, bool armsJake, double headJake, bool earsJake, bool armsUpJake, double scaleJake){
    COLORREF STROKEJAKE01 = RGB(11, 13, 10);
    COLORREF SKINJAKE = RGB(251, 203, 33);
    COLORREF SKINJAKE02 = RGB(241, 223, 53);
    COLORREF SKINJAKE03 = RGB(241, 243, 73);
    COLORREF EYEJAKE01 = RGB(251, 251, 253);
    COLORREF EYEJAKE02 = RGB(12, 14, 11);
    COLORREF MOUTHJAKE01 = RGB(248, 150, 189);
    COLORREF MOUTHJAKE02 = RGB(200, 23, 36);
    if (armsJake, armsUpJake)
    {
        //left hand
        txSetColor(STROKEJAKE01, 2);
        txSetFillColor(SKINJAKE);
        POINT lefthandjake01[21]={{x+111*scaleJake, y+168*scaleJake}, {x+77*scaleJake, y+131*scaleJake}, {x+73*scaleJake, y+126*scaleJake}, {x+71*scaleJake, y+122*scaleJake}, {x+68*scaleJake, y+116*scaleJake}, {x+66*scaleJake, y+111*scaleJake}, {x+65*scaleJake, y+106*scaleJake}, {x+63*scaleJake, y+51*scaleJake}, {x+65*scaleJake, y+47*scaleJake}, {x+66*scaleJake, y+42*scaleJake}, {x+68*scaleJake, y+46*scaleJake}, {x+70*scaleJake, y+43*scaleJake}, {x+72*scaleJake, y+46*scaleJake}, {x+73*scaleJake, y+44*scaleJake}, {x+74*scaleJake, y+43*scaleJake}, {x+77*scaleJake, y+91*scaleJake}, {x+80*scaleJake, y+106*scaleJake}, {x+82*scaleJake, y+111*scaleJake}, {x+86*scaleJake, y+115*scaleJake}, {x+89*scaleJake, y+118*scaleJake}, {x+116*scaleJake, y+148*scaleJake}};
        txPolygon(lefthandjake01, 21);

        //right hand
        txSetColor(STROKEJAKE01, 2);
        txSetFillColor(SKINJAKE);
        POINT righthandjake01[21]={{x+275*scaleJake, y+168*scaleJake}, {x+309*scaleJake, y+131*scaleJake}, {x+313*scaleJake, y+126*scaleJake}, {x+315*scaleJake, y+122*scaleJake}, {x+318*scaleJake, y+116*scaleJake}, {x+320*scaleJake, y+111*scaleJake}, {x+321*scaleJake, y+106*scaleJake}, {x+323*scaleJake, y+51*scaleJake}, {x+321*scaleJake, y+47*scaleJake}, {x+320*scaleJake, y+42*scaleJake}, {x+318*scaleJake, y+46*scaleJake}, {x+316*scaleJake, y+43*scaleJake}, {x+314*scaleJake, y+46*scaleJake}, {x+313*scaleJake, y+44*scaleJake}, {x+312*scaleJake, y+43*scaleJake}, {x+309*scaleJake, y+91*scaleJake}, {x+306*scaleJake, y+106*scaleJake}, {x+304*scaleJake, y+111*scaleJake}, {x+300*scaleJake, y+115*scaleJake}, {x+297*scaleJake, y+118*scaleJake}, {x+260*scaleJake, y+158*scaleJake}};
        txPolygon(righthandjake01, 21);

        txSetColor(SKINJAKE);
        txSetFillColor(SKINJAKE);
        txRectangle(x+110*scaleJake, y+140*scaleJake, x+276*scaleJake, y+169*scaleJake);
        txRectangle(x+200*scaleJake, y+140*scaleJake, x+276*scaleJake, y+169*scaleJake);
        txLine(x+111*scaleJake, y+118*scaleJake, x+111*scaleJake, y+142*scaleJake);
        txLine(x+275*scaleJake, y+138*scaleJake, x+275*scaleJake, y+200*scaleJake);

    }
    if (armsJake, !armsUpJake)
    {
        //left hand
        txSetColor(STROKEJAKE01, 2);
        txSetFillColor(SKINJAKE);
        POINT lefthandjake01[21]={{x+111*scaleJake, y+118*scaleJake}, {x+77*scaleJake, y+155*scaleJake}, {x+73*scaleJake, y+160*scaleJake}, {x+71*scaleJake, y+164*scaleJake}, {x+68*scaleJake, y+170*scaleJake}, {x+66*scaleJake, y+175*scaleJake}, {x+65*scaleJake, y+180*scaleJake}, {x+63*scaleJake, y+230*scaleJake}, {x+65*scaleJake, y+226*scaleJake}, {x+66*scaleJake, y+231*scaleJake}, {x+68*scaleJake, y+227*scaleJake}, {x+70*scaleJake, y+230*scaleJake}, {x+72*scaleJake, y+227*scaleJake}, {x+73*scaleJake, y+229*scaleJake}, {x+74*scaleJake, y+230*scaleJake}, {x+77*scaleJake, y+182*scaleJake}, {x+80*scaleJake, y+177*scaleJake}, {x+82*scaleJake, y+172*scaleJake}, {x+86*scaleJake, y+168*scaleJake}, {x+89*scaleJake, y+165*scaleJake}, {x+116*scaleJake, y+135*scaleJake}};
        txPolygon(lefthandjake01, 21);

        //right hand
        txSetColor(STROKEJAKE01, 2);
        txSetFillColor(SKINJAKE);
        POINT righthandjake01[21]={{x+275*scaleJake, y+118*scaleJake}, {x+309*scaleJake, y+155*scaleJake}, {x+313*scaleJake, y+160*scaleJake}, {x+315*scaleJake, y+164*scaleJake}, {x+318*scaleJake, y+170*scaleJake}, {x+320*scaleJake, y+175*scaleJake}, {x+321*scaleJake, y+180*scaleJake}, {x+323*scaleJake, y+230*scaleJake}, {x+321*scaleJake, y+226*scaleJake}, {x+320*scaleJake, y+231*scaleJake}, {x+318*scaleJake, y+227*scaleJake}, {x+316*scaleJake, y+230*scaleJake}, {x+314*scaleJake, y+227*scaleJake}, {x+313*scaleJake, y+229*scaleJake}, {x+312*scaleJake, y+230*scaleJake}, {x+309*scaleJake, y+182*scaleJake}, {x+306*scaleJake, y+177*scaleJake}, {x+304*scaleJake, y+172*scaleJake}, {x+300*scaleJake, y+168*scaleJake}, {x+297*scaleJake, y+165*scaleJake}, {x+260*scaleJake, y+135*scaleJake}};
        txPolygon(righthandjake01, 21);
        txSetColor(SKINJAKE);
        txSetFillColor(SKINJAKE);
        txRectangle(x+110*scaleJake, y+142*scaleJake, x+276*scaleJake, y+120*scaleJake);
        txRectangle(x+200*scaleJake, y+120*scaleJake, x+276*scaleJake, y+147*scaleJake);
        txLine(x+111*scaleJake, y+118*scaleJake, x+111*scaleJake, y+142*scaleJake);
        txLine(x+275*scaleJake, y+118*scaleJake, x+275*scaleJake, y+150*scaleJake);
    }
    else
    {
        txSetColor(STROKEJAKE01, 2);
        txLine(x+111*scaleJake, y+118*scaleJake, x+111*scaleJake, y+142*scaleJake);
        txLine(x+275*scaleJake, y+118*scaleJake, x+275*scaleJake, y+150*scaleJake);
    }
    // body
    if (earsJake)
    {
        txSetColor(STROKEJAKE01, 2);
        txSetFillColor(SKINJAKE);
        txArc(x+(100-10*headJake)*scaleJake, y+(20-10*headJake)*scaleJake, x+(285+10*headJake)*scaleJake, y+(190+10*headJake)*scaleJake, 358, 184);
        txArc(x+(100-10*headJake)*scaleJake, y+(96-2*headJake)*scaleJake, x+111*scaleJake, y+(118+2*headJake)*scaleJake, 184, 180);
        txArc(x+(285+10*headJake)*scaleJake, y+(96-2*headJake)*scaleJake, x+274*scaleJake, y+(118+2*headJake)*scaleJake, 184, 180);
    }
    else
    {
        txSetColor(STROKEJAKE01, 2);
        txSetFillColor(SKINJAKE);
        txArc(x+109*scaleJake, y+20*scaleJake, x+277*scaleJake, y+190*scaleJake, 10, 160);


    }

    txLine(x+111*scaleJake, y+91*scaleJake, x+111*scaleJake, y+118*scaleJake);
    txLine(x+111*scaleJake, y+142*scaleJake, x+111*scaleJake, y+190*scaleJake);

    txLine(x+275*scaleJake, y+91*scaleJake, x+275*scaleJake, y+118*scaleJake);
    txLine(x+275*scaleJake, y+148*scaleJake, x+275*scaleJake, y+190*scaleJake);
    txArc(x+110*scaleJake, y+122*scaleJake, x+275*scaleJake, y+258*scaleJake, 180, 180);
    txSetColor(SKINJAKE);

    txFloodFill(x+120*scaleJake, y+120*scaleJake, STROKEJAKE01, FLOODFILLBORDER);
    txSetColor(STROKEJAKE01, 2);

    //left leg
    txSetColor(STROKEJAKE01, 2*scaleJake);
    txSetFillColor(SKINJAKE);
    txArc(x+130*scaleJake, y+196*scaleJake, x+242*scaleJake, y+396*scaleJake, 130, 90);
    txArc(x+145*scaleJake, y+221*scaleJake, x+227*scaleJake, y+381*scaleJake, 119, 110);

    POINT leftlegjake01[10]={{x+135*scaleJake, y+338*scaleJake}, {x+127*scaleJake, y+348*scaleJake}, {x+127*scaleJake, y+355*scaleJake}, {x+133*scaleJake, y+357*scaleJake}, {x+148*scaleJake, y+342*scaleJake}, {x+150*scaleJake, y+340*scaleJake}};
    txPolygon(leftlegjake01, 6);

    txSetColor(SKINJAKE, 3*scaleJake);
    txLine(x+137*scaleJake, y+338*scaleJake, x+146*scaleJake, y+339*scaleJake);
    txRectangle(x+155*scaleJake, y+240*scaleJake, x+141*scaleJake, y+250*scaleJake);
    txFloodFill(x+120*scaleJake, y+120*scaleJake, STROKEJAKE01, FLOODFILLBORDER);
    //right leg
    txSetColor(STROKEJAKE01, 2);
    txSetFillColor(SKINJAKE);
    txArc(x+145*scaleJake, y+196*scaleJake, x+257*scaleJake, y+396*scaleJake, 321, 90);
    txArc(x+160*scaleJake, y+221*scaleJake, x+242*scaleJake, y+381*scaleJake, 312, 106);

    POINT rightlegjake01[10]={{x+250*scaleJake, y+338*scaleJake}, {x+258*scaleJake, y+348*scaleJake}, {x+258*scaleJake, y+355*scaleJake}, {x+252*scaleJake, y+357*scaleJake}, {x+237*scaleJake, y+342*scaleJake}, {x+235*scaleJake, y+340*scaleJake}};
    txPolygon(rightlegjake01, 6);

    txSetColor(SKINJAKE, 3*scaleJake);
    txLine(x+237*scaleJake, y+339*scaleJake, x+248*scaleJake, y+339*scaleJake);
    txRectangle(x+246*scaleJake, y+239*scaleJake, x+233*scaleJake, y+250*scaleJake);
    txFloodFill(x+120*scaleJake, y+120*scaleJake, STROKEJAKE01, FLOODFILLBORDER);





    // Color
    if (colorJake==0)
    {
        txSetFillColor(SKINJAKE);
        txFloodFill(x+120*scaleJake, y+220*scaleJake, STROKEJAKE01, FLOODFILLBORDER);

    }

    if (colorJake==1)
    {
        txSetFillColor(SKINJAKE02);
        txFloodFill(x+120*scaleJake, y+220*scaleJake, STROKEJAKE01, FLOODFILLBORDER);

    }

    if (colorJake==2)
    {
        txSetFillColor(SKINJAKE03);
        txFloodFill(x+120*scaleJake, y+220*scaleJake, STROKEJAKE01, FLOODFILLBORDER);

    }

    // left eye
    txSetColor(EYEJAKE02);
    txSetFillColor(EYEJAKE02);
    txCircle(x+151*scaleJake, y+86*scaleJake, (23*eyeJake)*scaleJake);

    txSetColor(EYEJAKE01);
    txSetFillColor(EYEJAKE01);
    txCircle(x+154*scaleJake, y+82*scaleJake, (15*eyeJake)*scaleJake);

    // right eye
    txSetColor(EYEJAKE02);
    txSetFillColor(EYEJAKE02);
    txCircle(x+231*scaleJake, y+86*scaleJake, (23*eyeJake)*scaleJake);

    txSetColor(EYEJAKE01);
    txSetFillColor(EYEJAKE01);
    txCircle(x+234*scaleJake, y+82*scaleJake, (15*eyeJake)*scaleJake);



    //nose
    if (noseJake)
    {
        txSetColor(STROKEJAKE01, 2);
        txSetFillColor(SKINJAKE);
        txArc(x+153*scaleJake, y+76*scaleJake, x+223*scaleJake, y+166*scaleJake, 358, 184);
        txArc(x+153*scaleJake, y+110*scaleJake, x+176*scaleJake, y+134*scaleJake, 178, 179);
        txArc(x+174*scaleJake, y+98*scaleJake, x+203*scaleJake, y+155*scaleJake, 358, 184);
        txArc(x+153*scaleJake, y+110*scaleJake, x+176*scaleJake, y+134*scaleJake, 178, 179);
        txArc(x+201*scaleJake, y+110*scaleJake, x+223*scaleJake, y+134*scaleJake, 178, 179);

    txSetFillColor(STROKEJAKE01);
    txEllipse(x+175*scaleJake, y+98*scaleJake, x+203*scaleJake, y+112*scaleJake);
    }

    // Color2
    if (colorJake==0 and noseJake)
    {
        txSetFillColor(SKINJAKE);
        txFloodFill(x+167*scaleJake, y+113*scaleJake, STROKEJAKE01, FLOODFILLBORDER);
    }

    if (colorJake==1 and noseJake)
    {
        txSetFillColor(SKINJAKE02);
        txFloodFill(x+167*scaleJake, y+113*scaleJake, STROKEJAKE01, FLOODFILLBORDER);
    }

    if (colorJake==2 and noseJake)
    {
        txSetFillColor(SKINJAKE03);
        txFloodFill(x+167*scaleJake, y+113*scaleJake, STROKEJAKE01, FLOODFILLBORDER);
    }

    // mouth
    if (!mouthJake)
    {
        txSetColor(STROKEJAKE01, 4);
        txArc(x+150*scaleJake, y+8*scaleJake, x+228*scaleJake, y+127*scaleJake, 260, 18);
    }
    else
    {
        txSetColor(STROKEJAKE01, 2);
        txArc(x+150*scaleJake, y+4*scaleJake, x+228*scaleJake, y+123*scaleJake, 256, 26);
        txArc(x+152*scaleJake, y-166*scaleJake, x+226*scaleJake, y+133*scaleJake, 264, 12);
        txSetFillColor(MOUTHJAKE02);
        txFloodFill(x+190*scaleJake, y+125*scaleJake, STROKEJAKE01, FLOODFILLBORDER);
    }
}
void drawDagget(double x, double y, double eyeDagget, double teethDagget, bool hairDagget, double handsDagget, double legsDagget, int colorDagget, bool noseDagget, bool legsHandsDagget, double scaleDagget){
        COLORREF SKINDAGGET01 = RGB(135, 76, 51);
        COLORREF SKINDAGGET02 = RGB(165, 106, 81);
        COLORREF SKINDAGGET03 = RGB(195, 136, 111);
        COLORREF STROKEDAGGET01 = RGB(36, 6, 0);
        COLORREF STROKEDAGGET02 = RGB(37, 6, 0);
        COLORREF NOSEDAGGET01 = RGB(209, 23, 36);
        COLORREF EYEDAGGET01 = RGB(253, 245, 121);
        COLORREF TEETHDAGGET01 = RGB(255, 255, 255);
        //hair
        if (hairDagget)
        {
            txSetColor(STROKEDAGGET01, 2);
            txSetFillColor(STROKEDAGGET01);
            txArc(x+32*scaleDagget, y+45*scaleDagget, x+310*scaleDagget, y+293*scaleDagget, 30, 65);
            txArc(x+42*scaleDagget, y+85*scaleDagget, x+320*scaleDagget, y+323*scaleDagget, 30, 37);
            txLine(x+216*scaleDagget, y+90*scaleDagget, x+286*scaleDagget, y+102*scaleDagget);
            txLine(x+235*scaleDagget, y+130*scaleDagget, x+296*scaleDagget, y+138*scaleDagget);
        }


        // left hand

        txSetColor(STROKEDAGGET01, 2);
        txSetFillColor(SKINDAGGET01);
        txLine(x+132*scaleDagget, y+126*scaleDagget, x+107*scaleDagget, y+166*scaleDagget);
        txLine(x+109*scaleDagget, y+166*scaleDagget, x+135*scaleDagget, y+146*scaleDagget);

        if (legsHandsDagget)
        {
            txSetFillColor(STROKEDAGGET01);
            POINT lefthanddagget01[9]={{x+107*scaleDagget, y+166*scaleDagget}, {x+(86-3*handsDagget)*scaleDagget, y+(177+2*handsDagget)*scaleDagget}, {x+103*scaleDagget, y+171*scaleDagget}, {x+(87-2*handsDagget)*scaleDagget, y+(186+3*handsDagget)*scaleDagget}, {x+104*scaleDagget, y+173*scaleDagget}, {x+(98-1*handsDagget)*scaleDagget, y+(184+3*handsDagget)*scaleDagget}, {x+109*scaleDagget, y+172*scaleDagget}, {x+(111+1*handsDagget)*scaleDagget, y+(185+3*handsDagget)*scaleDagget}, {x+111*scaleDagget, y+167*scaleDagget}};
            txPolygon(lefthanddagget01, 9);
        }

        // body
        txSetColor(STROKEDAGGET01, 2);
        txSetFillColor(SKINDAGGET01);
        txArc(x+53*scaleDagget, y+40*scaleDagget, x+323*scaleDagget, y+233*scaleDagget, 110, 56);
        txArc(x-25*scaleDagget, y+99*scaleDagget, x+265*scaleDagget, y+240*scaleDagget, 45, 88);
        txArc(x+25*scaleDagget, y+40*scaleDagget, x+240*scaleDagget, y+300*scaleDagget, 350, 90);
        txArc(x+238*scaleDagget, y+121*scaleDagget, x+404*scaleDagget, y+256*scaleDagget, 175, 35);
        txArc(x+111*scaleDagget, y+203*scaleDagget, x+262*scaleDagget, y+295*scaleDagget, 20, 140);
        txArc(x-97*scaleDagget, y+48*scaleDagget, x+138*scaleDagget, y+284*scaleDagget, 329, 66);

        if (colorDagget==0)
        {
            txSetFillColor(SKINDAGGET01);
            txFloodFill(x+115*scaleDagget, y+80*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);


        }
        if (colorDagget==1)
        {
            txSetFillColor(SKINDAGGET02);
            txFloodFill(x+115*scaleDagget, y+80*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);
        }
        if (colorDagget==2)
        {
            txSetFillColor(SKINDAGGET03);
            txFloodFill(x+115*scaleDagget, y+80*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);
        }

        //legs
        if (legsHandsDagget)
        {
            txSetFillColor(STROKEDAGGET01);
            POINT leftlegdagget01[9]={{x+120*scaleDagget, y+223*scaleDagget}, {x+(99-3*legsDagget)*scaleDagget, y+(234+2*legsDagget)*scaleDagget}, {x+116*scaleDagget, y+228*scaleDagget}, {x+(100-2*legsDagget)*scaleDagget, y+(243+3*legsDagget)*scaleDagget}, {x+117*scaleDagget, y+230*scaleDagget}, {x+(111-1*legsDagget)*scaleDagget, y+(241+3*legsDagget)*scaleDagget}, {x+(122+1*legsDagget)*scaleDagget, y+229*scaleDagget}, {x+(134+1*legsDagget)*scaleDagget, y+(227+3*legsDagget)*scaleDagget}, {x+124*scaleDagget, y+224*scaleDagget}};
            txPolygon(leftlegdagget01, 9);

            x=x+5*scaleDagget;
            txSetFillColor(STROKEDAGGET01);
            POINT rightlegdagget01[9]={{x+245*scaleDagget, y+223*scaleDagget}, {x+(224-3*legsDagget)*scaleDagget, y+(234+2*legsDagget)*scaleDagget}, {x+241*scaleDagget, y+228*scaleDagget}, {x+(225-2*legsDagget)*scaleDagget, y+(243+3*legsDagget)*scaleDagget}, {x+242*scaleDagget, y+230*scaleDagget}, {x+(236-1*legsDagget)*scaleDagget, y+(241+3*legsDagget)*scaleDagget}, {x+(247+1*legsDagget)*scaleDagget, y+229*scaleDagget}, {x+(259+1*legsDagget)*scaleDagget, y+(227+3*legsDagget)*scaleDagget}, {x+249*scaleDagget, y+224*scaleDagget}};
            txPolygon(rightlegdagget01, 9);
            x=x-5*scaleDagget;
        }
        // nose
        if (noseDagget)
        {
            txSetColor(STROKEDAGGET01, 2);
            txSetFillColor(NOSEDAGGET01);
            txArc(x+17*scaleDagget, y+80*scaleDagget, x+95*scaleDagget, y+165*scaleDagget, 33, 31);
            txFloodFill(x+75*scaleDagget, y+95*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);
        }

        //right hand

        txSetColor(STROKEDAGGET02, 2);
        txSetFillColor(SKINDAGGET01);
        txArc(x+35*scaleDagget, y+79*scaleDagget, x+247*scaleDagget, y+276*scaleDagget, 5, 40);


        txSetColor(SKINDAGGET01);
        txRectangle(x+237*scaleDagget, y+145*scaleDagget, x+241*scaleDagget, y+165*scaleDagget);
        txRectangle(x+233*scaleDagget, y+137*scaleDagget, x+238*scaleDagget, y+145*scaleDagget);
        txRectangle(x+232*scaleDagget, y+133*scaleDagget, x+236*scaleDagget, y+137*scaleDagget);

        txSetColor(STROKEDAGGET02, 2);
        txLine(x+200*scaleDagget, y+126*scaleDagget, x+245*scaleDagget, y+170*scaleDagget);



        if (colorDagget==0)
        {
            txSetFillColor(SKINDAGGET01);
            txFloodFill(x+212*scaleDagget, y+115*scaleDagget, STROKEDAGGET02, FLOODFILLSURFACE);
            txFloodFill(x+133*scaleDagget, y+144*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);



        }
        if (colorDagget==1)
        {
            txSetFillColor(SKINDAGGET02);
            txFloodFill(x+212*scaleDagget, y+115*scaleDagget, STROKEDAGGET02, FLOODFILLSURFACE);
            txFloodFill(x+133*scaleDagget, y+144*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);
        }
        if (colorDagget==2)
        {
            txSetFillColor(SKINDAGGET03);
            txFloodFill(x+212*scaleDagget, y+115*scaleDagget, STROKEDAGGET02, FLOODFILLSURFACE);
            txFloodFill(x+133*scaleDagget, y+144*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);
        }


        if (legsHandsDagget)
        {
            txSetColor(STROKEDAGGET01);
            txSetFillColor(STROKEDAGGET01);
            POINT righthanddagget01[9]={{x+242*scaleDagget, y+166*scaleDagget}, {x+221*scaleDagget, y+177*scaleDagget}, {x+238*scaleDagget, y+171*scaleDagget}, {x+222*scaleDagget, y+186*scaleDagget}, {x+239*scaleDagget, y+173*scaleDagget}, {x+233*scaleDagget, y+184*scaleDagget}, {x+244*scaleDagget, y+172*scaleDagget}, {x+246*scaleDagget, y+185*scaleDagget}, {x+246*scaleDagget, y+167*scaleDagget}};
            txPolygon(righthanddagget01, 9);
        }

        //teeth
        txSetColor(STROKEDAGGET02, 2);
        txSetFillColor(TEETHDAGGET01);
        POINT teethdagget01[7]={{x+100*scaleDagget, y+100*scaleDagget}, {x+101*scaleDagget, y+(122+25E-1*teethDagget)*scaleDagget}, {x+110*scaleDagget, y+(125+3*teethDagget)*scaleDagget}, {x+110*scaleDagget, y+100*scaleDagget}, {x+110*scaleDagget, y+(125+3*teethDagget)*scaleDagget}, {x+118*scaleDagget, y+(125+3*teethDagget)*scaleDagget}, {x+120*scaleDagget, y+100*scaleDagget}};
        txPolygon(teethdagget01, 7);

        // hair2
        if (hairDagget)
        {
            txSetFillColor(STROKEDAGGET01);
            txFloodFill(x+235*scaleDagget, y+125*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);
            txFloodFill(x+235*scaleDagget, y+85*scaleDagget, STROKEDAGGET01, FLOODFILLBORDER);
        }

        //eyes
        txSetColor(STROKEDAGGET02, 2);
        txSetFillColor(EYEDAGGET01);

        txEllipse(x+(135-2*eyeDagget)*scaleDagget, y+(28-2*eyeDagget)*scaleDagget, x+(155+2*eyeDagget)*scaleDagget, y+(58+2*eyeDagget)*scaleDagget);
        txSetFillColor(STROKEDAGGET02);
        txRectangle(x+(145-eyeDagget)*scaleDagget, y+(42-eyeDagget)*scaleDagget, x+(147+eyeDagget)*scaleDagget, y+(44+eyeDagget)*scaleDagget);

        txSetFillColor(EYEDAGGET01);
        txEllipse(x+(150-2*eyeDagget)*scaleDagget, y+(26-2*eyeDagget)*scaleDagget, x+(170+2*eyeDagget)*scaleDagget, y+(60+2*eyeDagget)*scaleDagget);
        txSetFillColor(STROKEDAGGET02);
        txRectangle(x+(160-eyeDagget)*scaleDagget, y+(41-eyeDagget)*scaleDagget, x+(162+eyeDagget)*scaleDagget, y+(43+eyeDagget)*scaleDagget);


        if (colorDagget==0)
        {
            txSetColor(SKINDAGGET01);
            txLine(x+200*scaleDagget, y+126*scaleDagget, x+216*scaleDagget, y+110*scaleDagget);

        }
        if (colorDagget==1)
        {
            txSetColor(SKINDAGGET02);
            txLine(x+200*scaleDagget, y+126*scaleDagget, x+216*scaleDagget, y+110*scaleDagget);

        }
        if (colorDagget==2)
        {
            txSetColor(SKINDAGGET03);
            txLine(x+200*scaleDagget, y+126*scaleDagget, x+216*scaleDagget, y+110*scaleDagget);
        }
    }
void drawMario(int x, int y, bool capMario, bool mustacheMario, int hairMario, string eyesMario, bool handsUpMario, int bootsMario, bool pantsMario, bool headMario, double scaleMario ){
        COLORREF CAPMARIO01 = RGB(254, 0, 0);
        COLORREF SKINMARIO01 = RGB(231, 156, 44);
        COLORREF PANTSMARIO01 = RGB(0, 0, 254);
        COLORREF HAIRMARIO01 = RGB(96, 56, 20);
        COLORREF HAIRMARIO02 = RGB(56, 36, 20);
        COLORREF HAIRMARIO03 = RGB(116, 66, 20);
        COLORREF TSHIRTMARIO01 = RGB(234, 0, 0);
        COLORREF BOOTSMARIO01 = RGB(91, 53, 19);
        COLORREF EYESMARIO02 = RGB(107, 142, 35);
        COLORREF EYESMARIO03 = RGB(70, 130, 180);
        COLORREF FACEMARIO01 = RGB(251, 176, 59);
        if (headMario)
        {

            // cap
            if (capMario)
            {
                txSetColor(CAPMARIO01);
                txSetFillColor(CAPMARIO01);
                txRectangle(x+100*scaleMario, y+0.1*scaleMario, x+200*scaleMario, y+20*scaleMario);
                txRectangle(x+40*scaleMario, y+20*scaleMario, x+220*scaleMario, y+40*scaleMario);
            }
            else
            {
            txSetColor(CAPMARIO01);
            txSetFillColor(CAPMARIO01);
            txRectangle(x+100*scaleMario, y+0.1*scaleMario, x+200*scaleMario, y+20*scaleMario);
            txRectangle(x+80*scaleMario, y+20*scaleMario, x+260*scaleMario, y+40*scaleMario);
        }


            //body
            txSetColor(FACEMARIO01);
            txSetFillColor(FACEMARIO01);
            txRectangle(x+60*scaleMario, y+60*scaleMario, x+260*scaleMario, y+120*scaleMario);
            txRectangle(x+100*scaleMario, y+40*scaleMario, x+220*scaleMario, y+140*scaleMario);
            txRectangle(x+260*scaleMario, y+80*scaleMario, x+280*scaleMario, y+100*scaleMario);

            txRectangle(x+120*scaleMario, y+200*scaleMario, x+200*scaleMario, y+220*scaleMario);


            // hair
            if (hairMario==0)
            {
                txSetColor(HAIRMARIO01);
                txSetFillColor(HAIRMARIO01);
            }

            if (hairMario==1)
            {
                txSetColor(HAIRMARIO02);
                txSetFillColor(HAIRMARIO02);
            }

            if (hairMario==2)
            {
                txSetColor(HAIRMARIO03);
                txSetFillColor(HAIRMARIO03);
            }

            txRectangle(x+80*scaleMario, y+40*scaleMario, x+140*scaleMario, y+60*scaleMario);
            txRectangle(x+100*scaleMario, y+60*scaleMario, x+120*scaleMario, y+100*scaleMario);
            txRectangle(x+120*scaleMario, y+80*scaleMario, x+140*scaleMario, y+100*scaleMario);
            txRectangle(x+60*scaleMario, y+60*scaleMario, x+80*scaleMario, y+120*scaleMario);
            txRectangle(x+80*scaleMario, y+100*scaleMario, x+100*scaleMario, y+120*scaleMario);

            // mustache
            txSetColor(HAIRMARIO01);
            txSetFillColor(HAIRMARIO01);
            if (mustacheMario)
            {
                txRectangle(x+200*scaleMario, y+80*scaleMario, x+220*scaleMario, y+120*scaleMario);
                txRectangle(x+180*scaleMario, y+100*scaleMario, x+260*scaleMario, y+120*scaleMario);
            }

            //eyes
            if (eyesMario== "dark")
            {
                txSetColor(HAIRMARIO01);
                txSetFillColor(HAIRMARIO01);
            }

            if (eyesMario== "green")
            {
                txSetColor(EYESMARIO02);
                txSetFillColor(EYESMARIO02);
            }

            if (eyesMario== "blue")
            {
                txSetColor(EYESMARIO03);
                txSetFillColor(EYESMARIO03);
            }

            txRectangle(x+180*scaleMario, y+40*scaleMario, x+200*scaleMario, y+80*scaleMario);
        }


        //hands+t-shirt
        if (handsUpMario)
        {
            txSetColor(TSHIRTMARIO01);
            txSetFillColor(TSHIRTMARIO01);

            txRectangle(x+60*scaleMario, y+140*scaleMario, x+80*scaleMario, y+160*scaleMario);
            txRectangle(x+100*scaleMario, y+140*scaleMario, x+220*scaleMario, y+160*scaleMario);
            txRectangle(x+240*scaleMario, y+140*scaleMario, x+260*scaleMario, y+160*scaleMario);
            txRectangle(x+20*scaleMario, y+160*scaleMario, x+300*scaleMario, y+180*scaleMario);
            txRectangle(x+40*scaleMario, y+180*scaleMario, x+280*scaleMario, y+200*scaleMario);
            txRectangle(x+80*scaleMario, y+200*scaleMario, x+100*scaleMario, y+220*scaleMario);
            txRectangle(x+220*scaleMario, y+200*scaleMario, x+240*scaleMario, y+220*scaleMario);

            txSetColor(SKINMARIO01);
            txSetFillColor(SKINMARIO01);

            txRectangle(x+240*scaleMario, y+120*scaleMario, x+300*scaleMario, y+140*scaleMario);
            txRectangle(x+260*scaleMario, y+120*scaleMario, x+300*scaleMario, y+160*scaleMario);

            txRectangle(x+20*scaleMario, y+120*scaleMario, x+80*scaleMario, y+140*scaleMario);
            txRectangle(x+20*scaleMario, y+120*scaleMario, x+60*scaleMario, y+160*scaleMario);
        }
        else
        {
            txSetColor(TSHIRTMARIO01);
            txSetFillColor(TSHIRTMARIO01);
            txRectangle(x+80*scaleMario, y+140*scaleMario, x+220*scaleMario, y+160*scaleMario);
            txRectangle(x+60*scaleMario, y+160*scaleMario, x+260*scaleMario, y+180*scaleMario);
            txRectangle(x+40*scaleMario, y+180*scaleMario, x+280*scaleMario, y+200*scaleMario);
            txRectangle(x+80*scaleMario, y+200*scaleMario, x+100*scaleMario, y+220*scaleMario);
            txRectangle(x+220*scaleMario, y+200*scaleMario, x+240*scaleMario, y+220*scaleMario);

            txSetColor(SKINMARIO01);
            txSetFillColor(SKINMARIO01);
            txRectangle(x+40*scaleMario, y+200*scaleMario, x+280*scaleMario, y+260*scaleMario);
        }

        //pants
        if (pantsMario)
        {
            txSetColor(PANTSMARIO01);
            txSetFillColor(PANTSMARIO01);

            txRectangle(x+100*scaleMario, y+200*scaleMario, x+140*scaleMario, y+220*scaleMario);
            txRectangle(x+180*scaleMario, y+200*scaleMario, x+220*scaleMario, y+220*scaleMario);
            txRectangle(x+100*scaleMario, y+220*scaleMario, x+220*scaleMario, y+260*scaleMario);
            txRectangle(x+80*scaleMario, y+240*scaleMario, x+140*scaleMario, y+280*scaleMario);
            txRectangle(x+180*scaleMario, y+240*scaleMario, x+240*scaleMario, y+280*scaleMario);
        }
        else
        {
            txSetColor(PANTSMARIO01);
            txSetFillColor(PANTSMARIO01);
            txRectangle(x+120*scaleMario, y+140*scaleMario, x+140*scaleMario, y+200*scaleMario);
            txRectangle(x+140*scaleMario, y+180*scaleMario, x+200*scaleMario, y+200*scaleMario);
            txRectangle(x+180*scaleMario, y+160*scaleMario, x+200*scaleMario, y+180*scaleMario);
            txRectangle(x+140*scaleMario, y+200*scaleMario, x+180*scaleMario, y+220*scaleMario);
            txRectangle(x+100*scaleMario, y+200*scaleMario, x+120*scaleMario, y+220*scaleMario);
            txRectangle(x+200*scaleMario, y+200*scaleMario, x+220*scaleMario, y+220*scaleMario);
            txRectangle(x+100*scaleMario, y+220*scaleMario, x+220*scaleMario, y+260*scaleMario);
            txRectangle(x+80*scaleMario, y+240*scaleMario, x+140*scaleMario, y+280*scaleMario);
            txRectangle(x+180*scaleMario, y+240*scaleMario, x+240*scaleMario, y+280*scaleMario);
        }

        //boots
        txSetColor(BOOTSMARIO01);
        txSetFillColor(BOOTSMARIO01);
        txRectangle(x+(60-10*bootsMario)*scaleMario, y+280*scaleMario, x+120*scaleMario, y+(300+10*bootsMario)*scaleMario);
        txRectangle(x+(40-20*bootsMario)*scaleMario, y+(300+10*bootsMario)*scaleMario, x+120*scaleMario, y+(320+20*bootsMario)*scaleMario);

        txRectangle(x+200*scaleMario, y+280*scaleMario, x+(260+10*bootsMario)*scaleMario, y+(300+10*bootsMario)*scaleMario);
        txRectangle(x+200*scaleMario, y+(300+10*bootsMario)*scaleMario, x+(280+20*bootsMario)*scaleMario, y+(320+20*bootsMario)*scaleMario);



    }
void drawCJ(int x, int y, int mouthCJ, bool colorCJ, string colorShirtCJ, bool legsCJ, bool faceCJ, double eyesCJ, bool hairCJ, bool bodyCJ, double scaleCJ){
    COLORREF STROKECJ01 = RGB(14, 0, 0);
    COLORREF SKINCJ01 = RGB(132, 79, 48);
    COLORREF SKINCJ02 = RGB(255, 228, 196);
    COLORREF HAIRCJ01 = RGB(29, 14, 9);
    COLORREF SHIRTCJ01 = RGB(254, 254, 254);
    COLORREF REDSHIRTCJ = RGB(178, 34, 34);
    COLORREF ORANGESHIRTCJ = RGB(255, 140, 0);
    COLORREF YELLOWSHIRTCJ = RGB(255, 255, 0);
    COLORREF BROWNSHIRTCJ = RGB(139, 69, 19);
    COLORREF GREENSHIRTCJ = RGB(0, 128, 0);
    COLORREF BLUESHIRTCJ = RGB(0, 128, 128);
    COLORREF JEANSCJ01 = RGB(102, 114, 130);
    COLORREF BOOTSCJ01 = RGB(26, 26, 26);
    COLORREF MOUTHCJ01 = RGB(150, 96, 60);
    if (bodyCJ)
    {
        //left hand1
        txSetColor(STROKECJ01, 2);
        if (colorCJ)
        {
            txSetFillColor(SKINCJ02);
        }
        else
        {
            txSetFillColor(SKINCJ01);
        }
        POINT lefthandcj01[17]={{x+68*scaleCJ, y+36*scaleCJ}, {x+57*scaleCJ, y+36*scaleCJ}, {x+50*scaleCJ, y+43*scaleCJ}, {x+46*scaleCJ, y+46*scaleCJ}, {x+42*scaleCJ, y+62*scaleCJ}, {x+45*scaleCJ, y+79*scaleCJ}, {x+40*scaleCJ, y+101*scaleCJ}, {x+37*scaleCJ, y+117*scaleCJ}, {x+40*scaleCJ, y+161*scaleCJ}, {x+47*scaleCJ, y+161*scaleCJ}, {x+60*scaleCJ, y+120*scaleCJ}, {x+63*scaleCJ, y+101*scaleCJ}, {x+58*scaleCJ, y+78*scaleCJ}, {x+59*scaleCJ, y+60*scaleCJ}, {x+59*scaleCJ, y+74*scaleCJ}, {x+65*scaleCJ, y+64*scaleCJ}, {x+68*scaleCJ, y+50*scaleCJ}};
        txPolygon(lefthandcj01, 17);

        POINT lefthandcj02[21]={{x+40*scaleCJ, y+161*scaleCJ}, {x+33*scaleCJ, y+177*scaleCJ}, {x+33*scaleCJ, y+186*scaleCJ}, {x+39*scaleCJ, y+195*scaleCJ}, {x+46*scaleCJ, y+198*scaleCJ}, {x+42*scaleCJ, y+189*scaleCJ}, {x+41*scaleCJ, y+183*scaleCJ}, {x+42*scaleCJ, y+189*scaleCJ}, {x+46*scaleCJ, y+198*scaleCJ}, {x+52*scaleCJ, y+201*scaleCJ}, {x+52*scaleCJ, y+197*scaleCJ}, {x+46*scaleCJ, y+191*scaleCJ}, {x+46*scaleCJ, y+182*scaleCJ}, {x+50*scaleCJ, y+178*scaleCJ}, {x+51*scaleCJ, y+182*scaleCJ}, {x+48*scaleCJ, y+186*scaleCJ}, {x+47*scaleCJ, y+190*scaleCJ}, {x+51*scaleCJ, y+189*scaleCJ}, {x+55*scaleCJ, y+179*scaleCJ}, {x+55*scaleCJ, y+168*scaleCJ}, {x+45*scaleCJ, y+161*scaleCJ}};
        txPolygon(lefthandcj02, 21);
        if (colorCJ)
        {
            txSetColor(SKINCJ02, 2);
            txLine(x+41*scaleCJ, y+261*scaleCJ, x+145*scaleCJ, y+261*scaleCJ);
        }
        else
        {
            txSetColor(SKINCJ01, 2);
            txLine(x+41*scaleCJ, y+161*scaleCJ, x+45*scaleCJ, y+161*scaleCJ);
        }

        //right hand
        txSetColor(STROKECJ01, 2);
        if (colorCJ)
        {
            txSetFillColor(SKINCJ02);
        }
        else
        {
            txSetFillColor(SKINCJ01);
        }
        POINT righthandcj01[35]={{x+132*scaleCJ, y+42*scaleCJ}, {x+143*scaleCJ, y+47*scaleCJ}, {x+151*scaleCJ, y+54*scaleCJ}, {x+154*scaleCJ, y+57*scaleCJ}, {x+153*scaleCJ, y+66*scaleCJ}, {x+152*scaleCJ, y+91*scaleCJ}, {x+154*scaleCJ, y+95*scaleCJ}, {x+159*scaleCJ, y+130*scaleCJ}, {x+158*scaleCJ, y+157*scaleCJ}, {x+161*scaleCJ, y+194*scaleCJ}, {x+152*scaleCJ, y+206*scaleCJ}, {x+156*scaleCJ, y+194*scaleCJ}, {x+152*scaleCJ, y+206*scaleCJ}, {x+147*scaleCJ, y+209*scaleCJ}, {x+142*scaleCJ, y+211*scaleCJ}, {x+142*scaleCJ, y+207*scaleCJ}, {x+149*scaleCJ, y+201*scaleCJ}, {x+148*scaleCJ, y+195*scaleCJ}, {x+146*scaleCJ, y+189*scaleCJ}, {x+146*scaleCJ, y+203*scaleCJ}, {x+141*scaleCJ, y+195*scaleCJ}, {x+141*scaleCJ, y+186*scaleCJ}, {x+146*scaleCJ, y+178*scaleCJ}, {x+146*scaleCJ, y+168*scaleCJ}, {x+140*scaleCJ, y+153*scaleCJ}, {x+136*scaleCJ, y+130*scaleCJ}, {x+136*scaleCJ, y+113*scaleCJ}, {x+134*scaleCJ, y+106*scaleCJ}, {x+134*scaleCJ, y+77*scaleCJ}, {x+138*scaleCJ, y+69*scaleCJ}, {x+138*scaleCJ, y+64*scaleCJ}, {x+138*scaleCJ, y+69*scaleCJ}, {x+134*scaleCJ, y+77*scaleCJ}, {x+129*scaleCJ, y+75*scaleCJ}, {x+127*scaleCJ, y+54*scaleCJ}};
        txPolygon(righthandcj01, 35);

        //neck
        txSetColor(STROKECJ01, 2);
        if (colorCJ)
        {
            txSetFillColor(SKINCJ02);
        }
        else
        {
            txSetFillColor(SKINCJ01);
        }
        POINT neckcj01[16]={{x+77*scaleCJ, y+37*scaleCJ}, {x+78*scaleCJ, y+37*scaleCJ}, {x+96*scaleCJ, y+54*scaleCJ}, {x+103*scaleCJ, y+54*scaleCJ}, {x+117*scaleCJ, y+46*scaleCJ}, {x+122*scaleCJ, y+35*scaleCJ}, {x+115*scaleCJ, y+29*scaleCJ}, {x+113*scaleCJ, y+24*scaleCJ}, {x+115*scaleCJ, y+19*scaleCJ}, {x+112*scaleCJ, y+19*scaleCJ}, {x+109*scaleCJ, y+22*scaleCJ}, {x+102*scaleCJ, y+22*scaleCJ}, {x+93*scaleCJ, y+17*scaleCJ}, {x+90*scaleCJ, y+8*scaleCJ}, {x+90*scaleCJ, y+20*scaleCJ}, {x+87*scaleCJ, y+23*scaleCJ}};
        txPolygon(neckcj01, 16);

        //shirt
        txSetColor(STROKECJ01, 2);
        txSetFillColor(SHIRTCJ01);
        POINT shirtcj01[30]={{x+77*scaleCJ, y+35*scaleCJ}, {x+78*scaleCJ, y+37*scaleCJ}, {x+96*scaleCJ, y+54*scaleCJ}, {x+103*scaleCJ, y+54*scaleCJ}, {x+117*scaleCJ, y+46*scaleCJ}, {x+122*scaleCJ, y+35*scaleCJ}, {x+131*scaleCJ, y+40*scaleCJ}, {x+129*scaleCJ, y+53*scaleCJ}, {x+129*scaleCJ, y+70*scaleCJ}, {x+130*scaleCJ, y+76*scaleCJ}, {x+134*scaleCJ, y+79*scaleCJ}, {x+133*scaleCJ, y+95*scaleCJ}, {x+125*scaleCJ, y+108*scaleCJ}, {x+127*scaleCJ, y+126*scaleCJ}, {x+128*scaleCJ, y+138*scaleCJ}, {x+132*scaleCJ, y+150*scaleCJ}, {x+132*scaleCJ, y+156*scaleCJ}, {x+122*scaleCJ, y+161*scaleCJ}, {x+100*scaleCJ, y+162*scaleCJ}, {x+72*scaleCJ, y+164*scaleCJ}, {x+62*scaleCJ, y+164*scaleCJ}, {x+62*scaleCJ, y+162*scaleCJ}, {x+64*scaleCJ, y+158*scaleCJ}, {x+67*scaleCJ, y+138*scaleCJ}, {x+65*scaleCJ, y+135*scaleCJ}, {x+66*scaleCJ, y+110*scaleCJ}, {x+58*scaleCJ, y+86*scaleCJ}, {x+59*scaleCJ, y+73*scaleCJ}, {x+65*scaleCJ, y+64*scaleCJ}, {x+68*scaleCJ, y+34*scaleCJ}};
        txPolygon(shirtcj01, 30);

        if (colorShirtCJ== "red")
        {
            txSetFillColor(REDSHIRTCJ);
            txFloodFill(x+100*scaleCJ, y+76*scaleCJ, SHIRTCJ01, FLOODFILLSURFACE);
        }
        if (colorShirtCJ== "orange")
        {
            txSetFillColor(ORANGESHIRTCJ);
            txFloodFill(x+100*scaleCJ, y+76*scaleCJ, SHIRTCJ01, FLOODFILLSURFACE);
        }
        if (colorShirtCJ== "yellow")
        {
            txSetFillColor(YELLOWSHIRTCJ);
            txFloodFill(x+100*scaleCJ, y+76*scaleCJ, SHIRTCJ01, FLOODFILLSURFACE);
        }
        if (colorShirtCJ== "brown")
        {
            txSetFillColor(BROWNSHIRTCJ);
            txFloodFill(x+100*scaleCJ, y+76*scaleCJ, SHIRTCJ01, FLOODFILLSURFACE);
        }
        if (colorShirtCJ== "green")
        {
            txSetFillColor(GREENSHIRTCJ);
            txFloodFill(x+100*scaleCJ, y+76*scaleCJ, SHIRTCJ01, FLOODFILLSURFACE);
        }
        if (colorShirtCJ== "blue")
        {
            txSetFillColor(BLUESHIRTCJ);
            txFloodFill(x+100*scaleCJ, y+76*scaleCJ, SHIRTCJ01, FLOODFILLSURFACE);
        }


        //head
        txSetColor(STROKECJ01, 2);
        if (colorCJ)
        {
            txSetFillColor(SKINCJ02);
        }
        else
        {
            txSetFillColor(SKINCJ01);
        }
        POINT headcj01[15]={{x+115*scaleCJ, y+19*scaleCJ}, {x+112*scaleCJ, y+19*scaleCJ}, {x+109*scaleCJ, y+22*scaleCJ}, {x+102*scaleCJ, y+22*scaleCJ}, {x+93*scaleCJ, y+17*scaleCJ}, {x+90*scaleCJ, y+8*scaleCJ}, {x+90*scaleCJ, y+0.1*scaleCJ}, {x+93*scaleCJ, y-11*scaleCJ}, {x+96*scaleCJ, y-16*scaleCJ}, {x+97*scaleCJ, y-21*scaleCJ}, {x+111*scaleCJ, y-20*scaleCJ}, {x+121*scaleCJ, y-16*scaleCJ}, {x+123*scaleCJ, y+6*scaleCJ}, {x+119*scaleCJ, y+10*scaleCJ}, {x+117*scaleCJ, y+16*scaleCJ}};
        txPolygon(headcj01, 15);

        // hair
        if (hairCJ)
        {
            txSetColor(STROKECJ01, 2);
            txSetFillColor(HAIRCJ01);
            POINT haircj01[17]={{x+91*scaleCJ, y-5*scaleCJ}, {x+93*scaleCJ, y-11*scaleCJ}, {x+95*scaleCJ, y-15*scaleCJ},{x+97*scaleCJ, y-21*scaleCJ}, {x+111*scaleCJ, y-20*scaleCJ}, {x+121*scaleCJ, y-16*scaleCJ}, {x+122*scaleCJ, y-3*scaleCJ}, {x+125*scaleCJ, y-7*scaleCJ}, {x+124*scaleCJ, y-16*scaleCJ}, {x+122*scaleCJ, y-19*scaleCJ}, {x+122*scaleCJ, y-21*scaleCJ}, {x+116*scaleCJ, y-28*scaleCJ}, {x+105*scaleCJ, y-30*scaleCJ}, {x+98*scaleCJ, y-28*scaleCJ}, {x+94*scaleCJ, y-23*scaleCJ}, {x+90*scaleCJ, y-17*scaleCJ}, {x+90*scaleCJ, y-7*scaleCJ}};
            txPolygon(haircj01, 17);
        }
        else
        {
            if (colorCJ)
            {
                txSetColor(SKINCJ02, 2);
                txSetFillColor(SKINCJ02);
            }
            else
            {
                txSetColor(SKINCJ01, 2);
                txSetFillColor(SKINCJ01);
            }
            txEllipse(x+92*scaleCJ, y-26*scaleCJ, x+124*scaleCJ, y+12*scaleCJ);
            txSetColor(STROKECJ01, 2);
            txArc(x+91*scaleCJ, y-26*scaleCJ, x+125*scaleCJ, y+12*scaleCJ, 340, 195);
        }
        //left ear
        txSetColor(STROKECJ01, 2);
        if (colorCJ)
        {
            txSetFillColor(SKINCJ02);
        }
        else
        {
            txSetFillColor(SKINCJ01);
        }
        POINT leftearcj01[7]={{x+90*scaleCJ, y+8*scaleCJ}, {x+87*scaleCJ, y+4*scaleCJ}, {x+86*scaleCJ, y+0.1*scaleCJ}, {x+86*scaleCJ, y-6*scaleCJ}, {x+87*scaleCJ, y-8*scaleCJ}, {x+90*scaleCJ, y-7*scaleCJ}, {x+91*scaleCJ, y-3*scaleCJ}};
        txPolygon(leftearcj01, 7);

        //right ear
        txSetColor(STROKECJ01, 2);
        if (colorCJ)
        {
            txSetFillColor(SKINCJ02);
        }
        else
        {
            txSetFillColor(SKINCJ01);
        }
        POINT rightearcj[5]={{x+122*scaleCJ, y+0.1*scaleCJ}, {x+125*scaleCJ, y+0.1*scaleCJ}, {x+126*scaleCJ, y+5*scaleCJ}, {x+120*scaleCJ, y+10*scaleCJ}, {x+119*scaleCJ, y+10*scaleCJ}};
        txPolygon(rightearcj, 5);
    }

    if (legsCJ)
    {
        //left boot
        txSetColor(STROKECJ01, 2);
        txSetFillColor(SHIRTCJ01);
        POINT leftbootcj02[7]={{x+34*scaleCJ, y+393*scaleCJ}, {x+34*scaleCJ, y+398*scaleCJ}, {x+36*scaleCJ, y+402*scaleCJ}, {x+50*scaleCJ, y+403*scaleCJ}, {x+62*scaleCJ, y+396*scaleCJ}, {x+65*scaleCJ, y+394*scaleCJ}, {x+73*scaleCJ, y+380*scaleCJ}};
        txPolygon(leftbootcj02, 7);

        txSetFillColor(BOOTSCJ01);
        POINT leftbootcj01[9]={{x+43*scaleCJ, y+377*scaleCJ}, {x+35*scaleCJ, y+385*scaleCJ}, {x+34*scaleCJ, y+393*scaleCJ}, {x+36*scaleCJ, y+397*scaleCJ}, {x+50*scaleCJ, y+398*scaleCJ}, {x+62*scaleCJ, y+391*scaleCJ}, {x+65*scaleCJ, y+386*scaleCJ}, {x+70*scaleCJ, y+386*scaleCJ}, {x+69*scaleCJ, y+378*scaleCJ}};
        txPolygon(leftbootcj01, 9);

        //right boot
        txSetColor(STROKECJ01, 2);
        txSetFillColor(SHIRTCJ01);
        POINT rightbootcj02[7]={{x+107*scaleCJ, y+380*scaleCJ}, {x+107*scaleCJ, y+385*scaleCJ}, {x+116*scaleCJ, y+390*scaleCJ}, {x+124*scaleCJ, y+396*scaleCJ}, {x+136*scaleCJ, y+396*scaleCJ}, {x+140*scaleCJ, y+392*scaleCJ}, {x+140*scaleCJ, y+389*scaleCJ}};
        txPolygon(rightbootcj02, 7);

        txSetFillColor(BOOTSCJ01);
        POINT rightbootcj01[9]={{x+107*scaleCJ, y+375*scaleCJ}, {x+107*scaleCJ, y+380*scaleCJ}, {x+116*scaleCJ, y+385*scaleCJ}, {x+124*scaleCJ, y+391*scaleCJ}, {x+136*scaleCJ, y+391*scaleCJ}, {x+140*scaleCJ, y+387*scaleCJ}, {x+140*scaleCJ, y+383*scaleCJ}, {x+128*scaleCJ, y+371*scaleCJ}, {x+116*scaleCJ, y+370*scaleCJ}};
        txPolygon(rightbootcj01, 9);

        //jeans
        txSetColor(STROKECJ01, 2);
        txSetFillColor(JEANSCJ01);
        POINT jeanscj01[61]={{x+132*scaleCJ, y+156*scaleCJ}, {x+122*scaleCJ, y+161*scaleCJ}, {x+100*scaleCJ, y+162*scaleCJ}, {x+72*scaleCJ, y+164*scaleCJ}, {x+62*scaleCJ, y+164*scaleCJ}, {x+63*scaleCJ, y+162*scaleCJ}, {x+62*scaleCJ, y+178*scaleCJ}, {x+57*scaleCJ, y+188*scaleCJ}, {x+57*scaleCJ, y+195*scaleCJ}, {x+51*scaleCJ, y+249*scaleCJ}, {x+49*scaleCJ, y+291*scaleCJ}, {x+45*scaleCJ, y+309*scaleCJ}, {x+40*scaleCJ, y+342*scaleCJ}, {x+40*scaleCJ, y+355*scaleCJ}, {x+35*scaleCJ, y+359*scaleCJ}, {x+34*scaleCJ, y+367*scaleCJ}, {x+38*scaleCJ, y+373*scaleCJ}, {x+39*scaleCJ, y+381*scaleCJ}, {x+48*scaleCJ, y+379*scaleCJ}, {x+62*scaleCJ, y+379*scaleCJ}, {x+67*scaleCJ, y+381*scaleCJ}, {x+73*scaleCJ, y+380*scaleCJ}, {x+74*scaleCJ, y+378*scaleCJ}, {x+72*scaleCJ, y+375*scaleCJ}, {x+72*scaleCJ, y+371*scaleCJ}, {x+76*scaleCJ, y+363*scaleCJ}, {x+76*scaleCJ, y+360*scaleCJ}, {x+73*scaleCJ, y+355*scaleCJ}, {x+75*scaleCJ, y+335*scaleCJ},  {x+80*scaleCJ, y+322*scaleCJ}, {x+82*scaleCJ, y+268*scaleCJ}, {x+87*scaleCJ, y+259*scaleCJ}, {x+93*scaleCJ, y+242*scaleCJ}, {x+94*scaleCJ, y+229*scaleCJ}, {x+99*scaleCJ, y+217*scaleCJ}, {x+100*scaleCJ, y+210*scaleCJ}, {x+99*scaleCJ, y+244*scaleCJ}, {x+103*scaleCJ, y+254*scaleCJ}, {x+106*scaleCJ, y+296*scaleCJ}, {x+104*scaleCJ, y+349*scaleCJ}, {x+101*scaleCJ, y+353*scaleCJ}, {x+100*scaleCJ, y+356*scaleCJ}, {x+102*scaleCJ, y+369*scaleCJ}, {x+99*scaleCJ, y+375*scaleCJ}, {x+107*scaleCJ, y+376*scaleCJ}, {x+116*scaleCJ, y+372*scaleCJ}, {x+132*scaleCJ, y+372*scaleCJ}, {x+136*scaleCJ, y+369*scaleCJ}, {x+138*scaleCJ, y+361*scaleCJ}, {x+134*scaleCJ, y+355*scaleCJ}, {x+135*scaleCJ, y+335*scaleCJ},  {x+138*scaleCJ, y+318*scaleCJ}, {x+139*scaleCJ, y+307*scaleCJ}, {x+135*scaleCJ, y+288*scaleCJ}, {x+134*scaleCJ, y+281*scaleCJ}, {x+140*scaleCJ, y+241*scaleCJ}, {x+143*scaleCJ, y+235*scaleCJ}, {x+140*scaleCJ, y+223*scaleCJ}, {x+140*scaleCJ, y+188*scaleCJ}, {x+138*scaleCJ, y+181*scaleCJ}, {x+138*scaleCJ, y+163*scaleCJ}};
        txPolygon(jeanscj01, 61);
    }

    if (faceCJ, bodyCJ)
    {
        // eyes
        txSetColor(STROKECJ01, 2);
        txSetFillColor(SHIRTCJ01);
        txLine(x+96*scaleCJ, y-11*scaleCJ, x+103*scaleCJ, y-9*scaleCJ);
        txLine(x+110*scaleCJ, y-8*scaleCJ, x+119*scaleCJ, y-6*scaleCJ);

        txEllipse(x+(96-1*eyesCJ)*scaleCJ, y-(6-1*eyesCJ)*scaleCJ, x+(104+1*eyesCJ)*scaleCJ, y-(1+1*eyesCJ)*scaleCJ);
        txEllipse(x+(110-1*eyesCJ)*scaleCJ, y-(3-1*eyesCJ)*scaleCJ, x+(118+1*eyesCJ)*scaleCJ, y+(2+1*eyesCJ)*scaleCJ);

        txSetFillColor(STROKECJ01);
        txEllipse(x+100*scaleCJ, y-4*scaleCJ, x+101*scaleCJ, y-3*scaleCJ);
        txEllipse( x+113*scaleCJ, y-1*scaleCJ, x+115*scaleCJ, y+0.1*scaleCJ);

        //nose
        if (colorCJ)
        {
            txSetFillColor(SKINCJ02);
        }
        else
        {
            txSetFillColor(SKINCJ01);
        }
        POINT nosecj01[6]={{x+107*scaleCJ, y-4*scaleCJ}, {x+107*scaleCJ, y+4*scaleCJ}, {x+109*scaleCJ, y+6*scaleCJ}, {x+109*scaleCJ, y+7*scaleCJ}, {x+108*scaleCJ, y+8*scaleCJ}, {x+104*scaleCJ, y+8*scaleCJ}};
        txPolygon(nosecj01, 6);

        if (colorCJ)
        {
            txSetColor(SKINCJ02, 2);
           txLine(x+107*scaleCJ, y-4*scaleCJ, x+104*scaleCJ, y+8*scaleCJ);
        }
        else
        {
            txSetColor(SKINCJ01, 2);
            txLine(x+107*scaleCJ, y-4*scaleCJ, x+104*scaleCJ, y+8*scaleCJ);
        }

        //mouth
        if (mouthCJ==0)
        {
            txSetColor(STROKECJ01);
            txSetFillColor(MOUTHCJ01);
            txEllipse(x+102*scaleCJ, y+10*scaleCJ, x+110*scaleCJ, y+15*scaleCJ);
        }
        if (mouthCJ==1)
        {

            txSetColor(STROKECJ01, 3);
            txSetFillColor(MOUTHCJ01);

            txArc(x+82*scaleCJ, y-70*scaleCJ, x+130*scaleCJ, y+15*scaleCJ, 265, 10);
        }
        if (mouthCJ==2)
        {
            txSetColor(STROKECJ01, 3);
            txSetFillColor(MOUTHCJ01);
            txArc(x+82*scaleCJ, y+15*scaleCJ, x+130*scaleCJ, y+85*scaleCJ, 85, 10);
        }
    }
}
void drawMike(int x, int y, double eyeMike, double hornMike, bool doubleEyesMike, bool mouthOpenMike, bool colorMike, bool doubleFingersLegs, double scaleMike){
    COLORREF EYEMIKE01 = RGB(245, 245, 245);
    COLORREF EYEMIKE02 = RGB(12, 93, 60);
    COLORREF EYEMIKE03 = RGB(0, 3, 2);
    COLORREF SKINMIKE01 = RGB(113, 152, 37);
    COLORREF HORNMIKE01 = RGB(174, 170, 106);
    COLORREF MOUTHMIKE01 = RGB(21, 30, 13);
    COLORREF STROKEMIKE01 = RGB(5, 10, 3);
    COLORREF REDSHIRTCJ = RGB(178, 34, 34);
    COLORREF BLUESHIRTCJ = RGB(0, 128, 128);
    //body
    txSetColor(STROKEMIKE01, 2);
    txSetFillColor(SKINMIKE01);
    POINT bodymike01[28]={{x+108*scaleMike, y+35*scaleMike}, {x+90*scaleMike, y+53*scaleMike}, {x+84*scaleMike, y+64*scaleMike}, {x+56*scaleMike, y+112*scaleMike}, {x+42*scaleMike, y+142*scaleMike}, {x+35*scaleMike, y+158*scaleMike}, {x+46*scaleMike, y+209*scaleMike}, {x+55*scaleMike, y+240*scaleMike}, {x+71*scaleMike, y+265*scaleMike}, {x+90*scaleMike, y+288*scaleMike}, {x+111*scaleMike, y+294*scaleMike}, {x+141*scaleMike, y+305*scaleMike}, {x+177*scaleMike, y+305*scaleMike}, {x+209*scaleMike, y+297*scaleMike}, {x+235*scaleMike, y+288*scaleMike}, {x+260*scaleMike, y+255*scaleMike}, {x+273*scaleMike, y+218*scaleMike}, {x+274*scaleMike, y+206*scaleMike}, {x+286*scaleMike, y+159*scaleMike}, {x+272*scaleMike, y+134*scaleMike}, {x+262*scaleMike, y+104*scaleMike}, {x+231*scaleMike, y+54*scaleMike}, {x+217*scaleMike, y+37*scaleMike}, {x+202*scaleMike, y+34*scaleMike}, {x+181*scaleMike, y+16*scaleMike}, {x+163*scaleMike, y+15*scaleMike}, {x+143*scaleMike, y+18*scaleMike}, {x+120*scaleMike, y+35*scaleMike}};
    txPolygon(bodymike01, 28);

    //left horn
    txSetColor(STROKEMIKE01, 2);
    txSetFillColor(HORNMIKE01);
    POINT lefthornmike01[7]={{x+90*scaleMike, y+53*scaleMike}, {x+89*scaleMike, y+(33-1*hornMike)*scaleMike}, {x+93*scaleMike, y+(23-2*hornMike)*scaleMike}, {x+102*scaleMike, y+(33-1*hornMike)*scaleMike}, {x+108*scaleMike, y+35*scaleMike}, {x+100*scaleMike, y+41*scaleMike}, {x+95*scaleMike, y+49*scaleMike}};
    txPolygon(lefthornmike01, 7);

    //right horn
    txSetColor(STROKEMIKE01, 2);
    txSetFillColor(HORNMIKE01);
    POINT righthornmike02[6]={{x+229*scaleMike, y+52*scaleMike}, {x+232*scaleMike, y+(33-1*hornMike)*scaleMike}, {x+229*scaleMike, y+(23-2*hornMike)*scaleMike}, {x+221*scaleMike, y+(30-1*hornMike)*scaleMike}, {x+217*scaleMike, y+36*scaleMike}, {x+225*scaleMike, y+46*scaleMike}};
    txPolygon(righthornmike02, 6);



    // left hand
    txSetColor(STROKEMIKE01, 2);
    txSetFillColor(SKINMIKE01);
    POINT lefthandmike01[12]={{x+39*scaleMike, y+153*scaleMike}, {x+34*scaleMike, y+159*scaleMike}, {x+23*scaleMike, y+231*scaleMike}, {x+22*scaleMike, y+243*scaleMike}, {x+19*scaleMike, y+266*scaleMike}, {x+15*scaleMike, y+349*scaleMike}, {x+34*scaleMike, y+348*scaleMike}, {x+34*scaleMike, y+250*scaleMike}, {x+42*scaleMike, y+214*scaleMike}, {x+46*scaleMike, y+209*scaleMike}, {x+46*scaleMike, y+196*scaleMike}, {x+39*scaleMike, y+168*scaleMike}};
    txPolygon(lefthandmike01, 12);

    POINT lefthandmike02[32]={{x+15*scaleMike, y+349*scaleMike}, {x+11*scaleMike, y+364*scaleMike}, {x+9*scaleMike, y+382*scaleMike}, {x+11*scaleMike, y+387*scaleMike}, {x+12*scaleMike, y+399*scaleMike}, {x+19*scaleMike, y+411*scaleMike}, {x+29*scaleMike, y+416*scaleMike}, {x+17*scaleMike, y+399*scaleMike}, {x+14*scaleMike, y+389*scaleMike}, {x+17*scaleMike, y+399*scaleMike}, {x+29*scaleMike, y+416*scaleMike}, {x+29*scaleMike, y+413*scaleMike}, {x+38*scaleMike, y+415*scaleMike}, {x+39*scaleMike, y+412*scaleMike}, {x+33*scaleMike, y+412*scaleMike}, {x+24*scaleMike, y+399*scaleMike}, {x+21*scaleMike, y+388*scaleMike}, {x+24*scaleMike, y+399*scaleMike}, {x+33*scaleMike, y+412*scaleMike}, {x+44*scaleMike, y+412*scaleMike}, {x+44*scaleMike, y+410*scaleMike}, {x+35*scaleMike, y+406*scaleMike}, {x+29*scaleMike, y+397*scaleMike}, {x+30*scaleMike, y+388*scaleMike}, {x+33*scaleMike, y+381*scaleMike}, {x+40*scaleMike, y+389*scaleMike}, {x+42*scaleMike, y+398*scaleMike}, {x+47*scaleMike, y+398*scaleMike}, {x+46*scaleMike, y+388*scaleMike}, {x+45*scaleMike, y+376*scaleMike}, {x+44*scaleMike, y+367*scaleMike}, {x+33*scaleMike, y+348*scaleMike}};
    txPolygon(lefthandmike02, 32);

    txSetColor(SKINMIKE01, 2);
    txLine(x+39*scaleMike, y+168*scaleMike, x+39*scaleMike, y+153*scaleMike);
    txLine(x+46*scaleMike, y+196*scaleMike, x+39*scaleMike, y+168*scaleMike);
    txLine(x+46*scaleMike, y+209*scaleMike, x+46*scaleMike, y+196*scaleMike);
    txLine(x+17*scaleMike, y+349*scaleMike, x+32*scaleMike, y+348*scaleMike);

    //right hand
    txSetColor(STROKEMIKE01, 2);
    txSetFillColor(SKINMIKE01);
    POINT righthandmike01[13]={{x+286*scaleMike, y+160*scaleMike}, {x+291*scaleMike, y+171*scaleMike}, {x+301*scaleMike, y+248*scaleMike}, {x+302*scaleMike, y+267*scaleMike}, {x+305*scaleMike, y+307*scaleMike}, {x+307*scaleMike, y+348*scaleMike}, {x+287*scaleMike, y+348*scaleMike}, {x+288*scaleMike, y+309*scaleMike}, {x+286*scaleMike, y+249*scaleMike}, {x+284*scaleMike, y+237*scaleMike}, {x+273*scaleMike, y+209*scaleMike}, {x+278*scaleMike, y+191*scaleMike}, {x+282*scaleMike, y+173*scaleMike}};
    txPolygon(righthandmike01, 13);

    POINT righthandmike02[39]={{x+307*scaleMike, y+348*scaleMike}, {x+312*scaleMike, y+363*scaleMike}, {x+313*scaleMike, y+381*scaleMike}, {x+310*scaleMike, y+397*scaleMike}, {x+306*scaleMike, y+406*scaleMike}, {x+298*scaleMike, y+411*scaleMike}, {x+302*scaleMike, y+402*scaleMike}, {x+306*scaleMike, y+399*scaleMike}, {x+308*scaleMike, y+388*scaleMike}, {x+306*scaleMike, y+399*scaleMike}, {x+302*scaleMike, y+402*scaleMike}, {x+298*scaleMike, y+411*scaleMike}, {x+294*scaleMike, y+414*scaleMike}, {x+290*scaleMike, y+412*scaleMike}, {x+302*scaleMike, y+398*scaleMike}, {x+302*scaleMike, y+387*scaleMike}, {x+302*scaleMike, y+398*scaleMike}, {x+290*scaleMike, y+412*scaleMike}, {x+284*scaleMike, y+414*scaleMike}, {x+284*scaleMike, y+412*scaleMike}, {x+290*scaleMike, y+412*scaleMike}, {x+301*scaleMike, y+399*scaleMike}, {x+302*scaleMike, y+387*scaleMike}, {x+301*scaleMike, y+399*scaleMike}, {x+290*scaleMike, y+412*scaleMike}, {x+279*scaleMike, y+412*scaleMike}, {x+279*scaleMike, y+412*scaleMike}, {x+287*scaleMike, y+404*scaleMike}, {x+295*scaleMike, y+396*scaleMike}, {x+295*scaleMike, y+387*scaleMike}, {x+291*scaleMike, y+381*scaleMike}, {x+289*scaleMike, y+381*scaleMike}, {x+285*scaleMike, y+388*scaleMike}, {x+283*scaleMike, y+397*scaleMike}, {x+279*scaleMike, y+400*scaleMike}, {x+275*scaleMike, y+396*scaleMike}, {x+277*scaleMike, y+385*scaleMike}, {x+279*scaleMike, y+370*scaleMike}, {x+287*scaleMike, y+348*scaleMike}};
    txPolygon(righthandmike02, 39);

    txSetColor(SKINMIKE01, 2);
    txLine(x+285*scaleMike, y+162*scaleMike, x+282*scaleMike, y+173*scaleMike);
    txLine(x+278*scaleMike, y+191*scaleMike, x+282*scaleMike, y+173*scaleMike);
    txLine(x+273*scaleMike, y+209*scaleMike, x+278*scaleMike, y+191*scaleMike);
    txLine(x+305*scaleMike, y+348*scaleMike, x+289*scaleMike, y+348*scaleMike);

    //left leg
    txSetColor(STROKEMIKE01, 2);
    txSetFillColor(SKINMIKE01);
    POINT leftlegmike01[30]={{x+89*scaleMike, y+288*scaleMike}, {x+90*scaleMike, y+343*scaleMike}, {x+91*scaleMike, y+350*scaleMike}, {x+98*scaleMike, y+397*scaleMike}, {x+96*scaleMike, y+413*scaleMike}, {x+88*scaleMike, y+425*scaleMike}, {x+69*scaleMike, y+428*scaleMike}, {x+55*scaleMike, y+431*scaleMike}, {x+44*scaleMike, y+439*scaleMike}, {x+42*scaleMike, y+447*scaleMike}, {x+46*scaleMike, y+449*scaleMike}, {x+54*scaleMike, y+449*scaleMike}, {x+58*scaleMike, y+439*scaleMike}, {x+63*scaleMike, y+435*scaleMike}, {x+58*scaleMike, y+439*scaleMike}, {x+54*scaleMike, y+449*scaleMike}, {x+64*scaleMike, y+450*scaleMike}, {x+77*scaleMike, y+448*scaleMike}, {x+81*scaleMike, y+437*scaleMike}, {x+87*scaleMike, y+431*scaleMike}, {x+81*scaleMike, y+437*scaleMike}, {x+77*scaleMike, y+448*scaleMike}, {x+81*scaleMike, y+453*scaleMike}, {x+90*scaleMike, y+453*scaleMike}, {x+119*scaleMike, y+440*scaleMike}, {x+120*scaleMike, y+437*scaleMike}, {x+114*scaleMike, y+413*scaleMike}, {x+110*scaleMike, y+369*scaleMike}, {x+108*scaleMike, y+345*scaleMike}, {x+110*scaleMike, y+293*scaleMike}};
    txPolygon(leftlegmike01, 30);

    txSetColor(SKINMIKE01, 2);
    txLine(x+91*scaleMike, y+288*scaleMike, x+110*scaleMike, y+293*scaleMike);
    txRectangle(x+92*scaleMike, y+286*scaleMike, x+110*scaleMike, y+293*scaleMike);

    if (doubleFingersLegs)
    {
        txRectangle(x+53*scaleMike, y+435*scaleMike, x+65*scaleMike, y+448*scaleMike);
    }

    //right leg
    txSetColor(STROKEMIKE01, 2);
    txSetFillColor(SKINMIKE01);
    POINT rightlegmike01[32]={{x+234*scaleMike, y+288*scaleMike}, {x+233*scaleMike, y+345*scaleMike}, {x+231*scaleMike, y+355*scaleMike}, {x+230*scaleMike, y+361*scaleMike}, {x+224*scaleMike, y+394*scaleMike}, {x+227*scaleMike, y+411*scaleMike}, {x+236*scaleMike, y+425*scaleMike}, {x+254*scaleMike, y+428*scaleMike}, {x+274*scaleMike, y+430*scaleMike}, {x+285*scaleMike, y+439*scaleMike}, {x+286*scaleMike, y+445*scaleMike}, {x+282*scaleMike, y+448*scaleMike}, {x+274*scaleMike, y+448*scaleMike}, {x+271*scaleMike, y+438*scaleMike}, {x+265*scaleMike, y+434*scaleMike}, {x+271*scaleMike, y+438*scaleMike}, {x+274*scaleMike, y+448*scaleMike}, {x+263*scaleMike, y+449*scaleMike}, {x+250*scaleMike, y+446*scaleMike}, {x+248*scaleMike, y+438*scaleMike}, {x+244*scaleMike, y+433*scaleMike}, {x+248*scaleMike, y+438*scaleMike}, {x+250*scaleMike, y+446*scaleMike}, {x+250*scaleMike, y+451*scaleMike}, {x+242*scaleMike, y+452*scaleMike}, {x+204*scaleMike, y+440*scaleMike}, {x+203*scaleMike, y+436*scaleMike}, {x+208*scaleMike, y+417*scaleMike}, {x+210*scaleMike, y+400*scaleMike}, {x+216*scaleMike, y+349*scaleMike}, {x+216*scaleMike, y+329*scaleMike}, {x+210*scaleMike, y+297*scaleMike}};
    txPolygon(rightlegmike01, 32);

    txSetColor(SKINMIKE01, 2);
    txLine(x+234*scaleMike, y+287*scaleMike, x+211*scaleMike, y+295*scaleMike);
    txRectangle(x+233*scaleMike, y+285*scaleMike, x+213*scaleMike, y+300*scaleMike);

    if (doubleFingersLegs)
    {
        txRectangle(x+260*scaleMike, y+433*scaleMike, x+275*scaleMike, y+448*scaleMike);
    }

    //mouth
    if (mouthOpenMike)
    {
        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(STROKEMIKE01);
        txArc(x+70*scaleMike, y+66*scaleMike, x+259*scaleMike, y+216*scaleMike, 225, 90);
        txArc(x+90*scaleMike, y+36*scaleMike, x+239*scaleMike, y+246*scaleMike, 225, 90);

        txSetFillColor (REDSHIRTCJ);
        txFloodFill(x+150*scaleMike, y+226*scaleMike, SKINMIKE01, FLOODFILLSURFACE);
    }
    else
    {
        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(STROKEMIKE01);
        txArc(x+70*scaleMike, y+66*scaleMike, x+259*scaleMike, y+216*scaleMike, 225, 90);
    }

    //eyes
    if (doubleEyesMike)
    {
        //left
        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE01);
        txCircle(x+126*scaleMike, y+100*scaleMike, 32*eyeMike*scaleMike);

        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE02);
        txCircle(x+125*scaleMike, y+99*scaleMike, 12*eyeMike*scaleMike);

        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE03);
        txCircle(x+124*scaleMike, y+100*scaleMike, 6*eyeMike*scaleMike);

        //right
        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE01);
        txCircle(x+206*scaleMike, y+100*scaleMike, 32*eyeMike*scaleMike);

        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE02);
        txCircle(x+206*scaleMike, y+99*scaleMike, 12*eyeMike*scaleMike);

        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE03);
        txCircle(x+205*scaleMike, y+100*scaleMike, 6*eyeMike*scaleMike);

    }
    else
    {
        //eye
        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE01);
        txCircle(x+166*scaleMike, y+100*scaleMike, 64*eyeMike*scaleMike);

        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE02);
        txCircle(x+168*scaleMike, y+99*scaleMike, 32*eyeMike*scaleMike);

        txSetColor(STROKEMIKE01, 2);
        txSetFillColor(EYEMIKE03);
        txCircle(x+167*scaleMike, y+100*scaleMike, 12*eyeMike*scaleMike);
    }
    if (colorMike)
    {
        txSetFillColor(BLUESHIRTCJ);
        txFloodFill(x+150*scaleMike, y+256*scaleMike, SKINMIKE01, FLOODFILLSURFACE);
    }
}
void drawBackground(int x, int y){
    // фон
    txSetColor(RGB(146, 222, 238));
    txSetFillColor(RGB(106, 222, 238));
    txRectangle(x, y, x+1250, y+500);

    txSetColor(RGB(0, 142, 0));
    txSetFillColor(RGB(0, 142, 0));
    txRectangle(x, y+500, x+1250, y+800);


    // Солнце
    txSetColor(TX_YELLOW);txSetFillColor(TX_BLUE);
    txSetFillColor(TX_YELLOW);
    txCircle(1, 1, 150);


    // облако 1
    txSetColor(RGB(245, 245, 245));
    txSetFillColor(RGB(245, 245, 245));
    txEllipse(x+100, y+70, x+400, y+120);
    txCircle(x+130, y+100, 30);
    txCircle(x+150, y+110, 30);
    txCircle(x+180, y+110, 35);
    txCircle(x+210, y+114, 32);
    txCircle(x+240, y+117, 34);
    txCircle(x+270, y+115, 30);
    txCircle(x+300, y+112, 34);
    txCircle(x+330, y+110, 31);
    txCircle(x+370, y+100, 30);

    txCircle(x+130, y+80, 30);
    txCircle(x+150, y+70, 30);
    txCircle(x+180, y+70, 35);
    txCircle(x+210, y+66, 32);
    txCircle(x+240, y+63, 34);
    txCircle(x+270, y+65, 30);
    txCircle(x+300, y+67, 34);
    txCircle(x+330, y+70, 31);
    txCircle(x+370, y+80, 30);

    // облако 2
    txSetColor(RGB(245, 245, 245));
    txSetFillColor(RGB(245, 245, 245));
    txEllipse(x+500, y+100, x+800, y+150);
    txCircle(x+530, y+130, 30);
    txCircle(x+550, y+130, 30);
    txCircle(x+580, y+130, 35);
    txCircle(x+610, y+134, 32);
    txCircle(x+640, y+137, 34);
    txCircle(x+670, y+135, 30);
    txCircle(x+700, y+132, 34);
    txCircle(x+730, y+130, 31);
    txCircle(x+770, y+130, 30);

    txCircle(x+530, y+110, 30);
    txCircle(x+550, y+100, 30);
    txCircle(x+580, y+100, 35);
    txCircle(x+610, y+96, 32);
    txCircle(x+640, y+93, 34);
    txCircle(x+670, y+95, 30);
    txCircle(x+700, y+97, 34);
    txCircle(x+730, y+100, 31);
    txCircle(x+770, y+110, 30);

    // облако 3
    txSetColor(RGB(245, 245, 245));
    txSetFillColor(RGB(245, 245, 245));
    txEllipse(x+900, y+70, x+1200, 120);
    txCircle(x+930, y+100, 30);
    txCircle(x+950, y+110, 30);
    txCircle(x+980, y+110, 35);
    txCircle(x+1010, y+114, 32);
    txCircle(x+1040, y+117, 34);
    txCircle(x+1070, y+115, 30);
    txCircle(x+1100, y+112, 34);
    txCircle(x+1130, y+110, 31);
    txCircle(x+1170, y+100, 30);

    txCircle(x+930, y+80, 30);
    txCircle(x+950, y+70, 30);
    txCircle(x+980, y+70, 35);
    txCircle(x+1010, y+66, 32);
    txCircle(x+1040, y+63, 34);
    txCircle(x+1070, y+65, 30);
    txCircle(x+1100, y+67, 34);
    txCircle(x+1130, y+70, 31);
    txCircle(x+1170, y+80, 30);

    //Дерево 1
    txSetColor(RGB(151, 75, 0));
    txSetFillColor(RGB(151, 75, 0));
    POINT wood[4]={{x+200, y+600}, {x+205, y+500}, {x+220, y+500}, {x+225, y+600}};
    txPolygon(wood, 4);

    txSetColor(TX_NULL);
    txSetFillColor(RGB(0, 111, 0));
    txCircle(x+212, y+470, 50);
    txSetFillColor(RGB(0, 108, 0));
    txCircle(x+210, y+400, 50);
    txSetFillColor(RGB(0, 118, 0));
    txCircle(x+228, y+435, 45);
    txSetFillColor(RGB(0, 124, 0));
    txCircle(x+196, y+435, 45);

    //Дерево 2
    txSetColor(RGB(151, 75, 0));
    txSetFillColor(RGB(151, 75, 0));
    POINT wood2[4]={{x+600, y+575}, {x+605, y+475}, {x+620, y+475}, {x+625, y+575}};
    txPolygon(wood2, 4);

    txSetColor(TX_NULL);
    txSetFillColor(RGB(0, 115, 0));
    txCircle(x+612, y+445, 50);
    txSetFillColor(RGB(0, 102, 0));
    txCircle(x+610, y+375, 50);
    txSetFillColor(RGB(0, 105, 0));
    txCircle(x+628, y+410, 45);
    txSetFillColor(RGB(0, 119, 0));
    txCircle(x+596, y+410, 45);

     //Дерево 3
    txSetColor(RGB(151, 75, 0));
    txSetFillColor(RGB(151, 75, 0));
    POINT wood3[4]={{x+1000, y+575}, {x+1005, y+475}, {x+1020, y+475}, {x+1025, y+575}};
    txPolygon(wood3, 4);

    txSetColor(TX_NULL);
    txSetFillColor(RGB(0, 119, 0));
    txCircle(x+1012, y+445, 50);
    txSetFillColor(RGB(0, 103, 0));
    txCircle(x+1010, y+375, 50);
    txSetFillColor(RGB(0, 113, 0));
    txCircle(x+1028, y+410, 45);
    txSetFillColor(RGB(0, 107, 0));
    txCircle(x+996, y+410, 45);
}
void drawDialog(int x, int y, double scaleDialog){
    txSetColor(TX_BLACK, 3);
    txSetFillColor(TX_WHITE);
    POINT dialog[5]={{x+0.1*scaleDialog, y-0.1*scaleDialog}, {x+25*scaleDialog, y-100*scaleDialog}, {x+225*scaleDialog, y-100*scaleDialog}, {x+225*scaleDialog, y-25*scaleDialog}, {x+25*scaleDialog, y-25*scaleDialog}};
    txPolygon(dialog,5);
}
void drawPipe(int x, int y, double scalePipe){
}