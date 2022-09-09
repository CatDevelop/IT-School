//{============================================================================
//! @file		Documentation/MainPage.txt
//! @brief	Главная страница системы помощи
//}============================================================================

/*! 	@mainpage Титульная страница

		@section 	MainPage 	CatDevLib (Cat Developer Library)
			$Version: 1.0.0 $
			$Date: 20.01.2020 $
			$Copyright: (C) CatDev (Maxim Rozhkov, https://vk.com/cat_dev) <r.maximka@mail.ru> $

		@section    Description	Назначение 
			TX Library - компактная графическая библиотека для С++. <br>
			Она имеет 6 функций, которые рисуют персонажей из разных мультфильмов.
		
		@section 	Screenshots 	Скриншоты
			@image html Image/All.png		
			@image html Image/Movie.png				
		
		@section 	Contents 	Разделы системы помощи
             -  @ref MainPage	"Информация о библиотеке"
             -  @ref Modules		"Функции"
				-  @ref Timon	"Тимон"
				-  @ref Pig		"Пятачок"
				-  @ref Pa 	"Прапор"
				-  @ref Fly 	"Вжиг"
				-  @ref Minion 	"Миньон"
				-  @ref Skubi 	"Скуби-Ду"
             -  @ref Tutor		"Пример реализации"
*/

//! @defgroup Timon	Тимон 
//! @defgroup Pig   	Пятачок
//! @defgroup Pa	Прапор 
//! @defgroup Fly	Вжиг 
//! @defgroup Minion	Миньон 
//! @defgroup Skubi	Скуби-Ду 
//! @defgroup  Tutor Пример реализации


CONST COLORREF DARKORANGE = RGB(117, 79, 56);
CONST COLORREF DARKGRAY = RGB(26, 15, 13);
CONST COLORREF BLACK = RGB(0, 0, 1);
CONST COLORREF ORANGE = RGB(166, 61, 40);
CONST COLORREF WHITE = RGB(255, 255, 241);
CONST COLORREF LIGHTBLUE = RGB(138, 218, 245);
CONST COLORREF YELLOW = RGB(255, 255, 0);

//=================================================================================================================
//{          Drawing
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Timon
//! @brief   Отрисовка персонажа ,,Тимон" - герой анимационного фильма «Король Лев».
//!
//! @image html Image/Timon.png
//!
//! @param   x   Х-координата точки
//! @param   y 	Y-координата точки
//! @param   timonEar 	Наличие ушей у персонажа (0 - Нет ушей, 1 - Правое ухо, 2 - Левое ухо, 3 - Оба уха)
//! @param   timonLeg	Наличие ног у персонажа (0 - Нет ног, 1 - Правая нога, 2 - Левая нога, 3 - Обе ноги)
//! @param   timonScale	Размер персонажа (1 - Стандартный размер, 2 - В 2 раза больше стандартного размера и т.д.)
//! @param   timonTale	Наличие хвоста у персонажа (0 - Нет хвоста, 1 - Есть хвост)
//! @param   timonHair	Наличие волос у персонажа (0 - Нет волос, 1 - Есть волос)
//! @param   timonRoth	Наличие рта у персонажа (0 - Нет рта, 1 - Есть рот)
//! @param   timonBallyColor Цвет пузика персонажа)))
//! @param   timonBackColor  Цвет спины персонажа
//! @param   timonHairColor	Цвет волос персонажа
//! @param   timonLimbColor	Цвет конечностей персонажа
//!
//! @warning Если цвета разных частей тела совпадают, <del>может произойти ядерный коллапс</del> могут наблюдаться серъёзные графические баги.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @note    Для использования функции нужно создать холст из TXLib.
//!
//! Пример использования функции смотрите в @ref Tutor "примере реализации".
//}----------------------------------------------------------------------------------------------------------------

	void drawTimon(int x, int y, int timonEar, int timonLeg, int timonScale, bool timonTale, bool timonHair, bool timonRoth, COLORREF timonBallyColor, COLORREF timonBackColor, COLORREF timonHairColor, COLORREF timonLimbColor)
    {
        //Тимон
		if (timonLeg == 0)
		{
			POINT TimonBack2 [14] = {{x+(-33*timonScale), y+(181*timonScale)}, {x+(-29*timonScale), y+(186*timonScale)}, {x+(-19*timonScale), y+(196*timonScale)}, {x+(-8*timonScale), y+(203*timonScale)}, {x+(1*timonScale), y+(203*timonScale)}, {x+(1*timonScale), y+(203*timonScale)}, {x+(-6*timonScale), y+(197*timonScale)}, {x+(-9*timonScale), y+(192*timonScale)}, {x+(-10*timonScale), y+(191*timonScale)}, {x+(-10*timonScale), y+(162*timonScale)}, {x+(-10*timonScale), y+(162*timonScale)}, {x+(-24*timonScale), y+(162*timonScale)}, {x+(-30*timonScale), y+(176*timonScale)}, {x+(-33*timonScale), y+(182*timonScale)}};
			txSetColor(BLACK);
			txSetFillColor(timonBackColor);
			txPolygon(TimonBack2, 14);
		}

		if (timonLeg == 1)
		{
			//Правая стопа
			POINT TimonRightSole [14] = {{x+(-73*timonScale), y+(259*timonScale)}, {x+(-59*timonScale), y+(258*timonScale)}, {x+(-48*timonScale), y+(254*timonScale)}, {x+(-37*timonScale), y+(250*timonScale)}, {x+(-34*timonScale), y+(248*timonScale)}, {x+(-34*timonScale), y+(242*timonScale)}, {x+(-36*timonScale), y+(239*timonScale)}, {x+(-41*timonScale), y+(234*timonScale)}, {x+(-55*timonScale), y+(234*timonScale)}, {x+(-62*timonScale), y+(236*timonScale)}, {x+(-67*timonScale), y+(240*timonScale)}, {x+(-71*timonScale), y+(244*timonScale)}, {x+(-74*timonScale), y+(249*timonScale)}, {x+(-76*timonScale), y+(256*timonScale)}, };

			txSetColor(BLACK);
			txSetFillColor(timonLimbColor);
			txPolygon(TimonRightSole, 14);

			//Правые пальцы
			txSetColor(RGB (45, 27, 27));
			txLine(x+(-75*timonScale), y+(253*timonScale), x+(-73*timonScale), y+(250*timonScale));
			txLine(x+(-73*timonScale), y+(250*timonScale), x+(-69*timonScale), y+(247*timonScale));
			txLine(x+(-69*timonScale), y+(247*timonScale), x+(-65*timonScale), y+(243*timonScale));
			txLine(x+(-65*timonScale), y+(243*timonScale), x+(-62*timonScale), y+(241*timonScale));
			txLine(x+(-62*timonScale), y+(241*timonScale), x+(-60*timonScale), y+(240*timonScale));

			txLine(x+(-73*timonScale), y+(257*timonScale), x+(-67*timonScale), y+(251*timonScale));
			txLine(x+(-67*timonScale), y+(251*timonScale), x+(-60*timonScale), y+(248*timonScale));
			txLine(x+(-60*timonScale), y+(248*timonScale), x+(-56*timonScale), y+(245*timonScale));
			txLine(x+(-56*timonScale), y+(245*timonScale), x+(-52*timonScale), y+(244*timonScale));


			//Правая нога
			POINT TimonRightLeg [38] = {{x+(-33*timonScale), y+(248*timonScale)}, {x+(-23*timonScale), y+(245*timonScale)}, {x+(-10*timonScale), y+(242*timonScale)}, {x+(-2*timonScale), y+(240*timonScale)}, {x+(3*timonScale), y+(239*timonScale)}, {x+(4*timonScale), y+(237*timonScale)}, {x+(0*timonScale), y+(233*timonScale)}, {x+(-4*timonScale), y+(231*timonScale)}, {x+(-12*timonScale), y+(223*timonScale)}, {x+(-14*timonScale), y+(218*timonScale)}, {x+(-12*timonScale), y+(212*timonScale)}, {x+(-6*timonScale), y+(207*timonScale)}, {x+(0*timonScale), y+(204*timonScale)}, {x+(0*timonScale), y+(203*timonScale)}, {x+(-6*timonScale), y+(196*timonScale)}, {x+(-10*timonScale), y+(191*timonScale)}, {x+(-10*timonScale), y+(162*timonScale)}, {x+(-24*timonScale), y+(162*timonScale)}, {x+(-30*timonScale), y+(176*timonScale)}, {x+(-34*timonScale), y+(184*timonScale)}, {x+(-41*timonScale), y+(197*timonScale)}, {x+(-44*timonScale), y+(203*timonScale)}, {x+(-46*timonScale), y+(211*timonScale)}, {x+(-47*timonScale), y+(223*timonScale)}, {x+(-46*timonScale), y+(225*timonScale)}, {x+(-44*timonScale), y+(223*timonScale)}, {x+(-43*timonScale), y+(224*timonScale)}, {x+(-41*timonScale), y+(222*timonScale)}, {x+(-38*timonScale), y+(225*timonScale)}, {x+(-36*timonScale), y+(223*timonScale)}, {x+(-27*timonScale), y+(226*timonScale)}, {x+(-20*timonScale), y+(229*timonScale)}, {x+(-14*timonScale), y+(232*timonScale)}, {x+(-13*timonScale), y+(233*timonScale)}, {x+(-14*timonScale), y+(234*timonScale)}, {x+(-40*timonScale), y+(234*timonScale)}, {x+(-36*timonScale), y+(238*timonScale)}, {x+(-33*timonScale), y+(242*timonScale)}, };

			txSetColor(BLACK);
			txSetFillColor (timonBackColor);
			txPolygon(TimonRightLeg, 38);
		}

		if (timonLeg == 2)
		{
			POINT TimonBack2 [14] = {{x+(-33*timonScale), y+(181*timonScale)}, {x+(-29*timonScale), y+(186*timonScale)}, {x+(-19*timonScale), y+(196*timonScale)}, {x+(-8*timonScale), y+(203*timonScale)}, {x+(1*timonScale), y+(203*timonScale)}, {x+(1*timonScale), y+(203*timonScale)}, {x+(-6*timonScale), y+(197*timonScale)}, {x+(-9*timonScale), y+(192*timonScale)}, {x+(-10*timonScale), y+(191*timonScale)}, {x+(-10*timonScale), y+(162*timonScale)}, {x+(-10*timonScale), y+(162*timonScale)}, {x+(-24*timonScale), y+(162*timonScale)}, {x+(-30*timonScale), y+(176*timonScale)}, {x+(-33*timonScale), y+(182*timonScale)}};
			txSetColor(BLACK);
			txSetFillColor(timonBackColor);
			txPolygon(TimonBack2, 14);

			//Левая стопа
			POINT TimonLeftSole [15] = {{x+(112*timonScale), y+(237*timonScale)}, {x+(112*timonScale), y+(231*timonScale)}, {x+(119*timonScale), y+(224*timonScale)}, {x+(119*timonScale), y+(223*timonScale)}, {x+(121*timonScale), y+(222*timonScale)}, {x+(139*timonScale), y+(222*timonScale)}, {x+(148*timonScale), y+(227*timonScale)}, {x+(151*timonScale), y+(231*timonScale)}, {x+(152*timonScale), y+(234*timonScale)}, {x+(152*timonScale), y+(240*timonScale)}, {x+(151*timonScale), y+(241*timonScale)}, {x+(141*timonScale), y+(241*timonScale)}, {x+(136*timonScale), y+(240*timonScale)}, {x+(127*timonScale), y+(239*timonScale)}, {x+(119*timonScale), y+(238*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonLimbColor);
			txPolygon(TimonLeftSole, 15);

			//Левые пальцы
			txSetColor(RGB (45, 27, 27));
			txLine(x+(150*timonScale), y+(232*timonScale), x+(145*timonScale), y+(230*timonScale));
			txLine(x+(145*timonScale), y+(230*timonScale), x+(140*timonScale), y+(227*timonScale));
			txLine(x+(140*timonScale), y+(227*timonScale), x+(135*timonScale), y+(226*timonScale));

			txLine(x+(147*timonScale), y+(240*timonScale), x+(140*timonScale), y+(233*timonScale));
			txLine(x+(140*timonScale), y+(233*timonScale), x+(137*timonScale), y+(232*timonScale));
			txLine(x+(137*timonScale), y+(232*timonScale), x+(131*timonScale), y+(229*timonScale));

			//Левая нога
			POINT TimonLeftLeg [32] = {{x+(111*timonScale), y+(237*timonScale)}, {x+(111*timonScale), y+(231*timonScale)}, {x+(118*timonScale), y+(224*timonScale)}, {x+(118*timonScale), y+(223*timonScale)}, {x+(96*timonScale), y+(224*timonScale)}, {x+(79*timonScale), y+(207*timonScale)}, {x+(79*timonScale), y+(206*timonScale)}, {x+(61*timonScale), y+(188*timonScale)}, {x+(61*timonScale), y+(187*timonScale)}, {x+(58*timonScale), y+(183*timonScale)}, {x+(55*timonScale), y+(179*timonScale)}, {x+(51*timonScale), y+(173*timonScale)}, {x+(47*timonScale), y+(166*timonScale)}, {x+(43*timonScale), y+(160*timonScale)}, {x+(40*timonScale), y+(155*timonScale)}, {x+(39*timonScale), y+(156*timonScale)}, {x+(39*timonScale), y+(178*timonScale)}, {x+(37*timonScale), y+(184*timonScale)}, {x+(34*timonScale), y+(189*timonScale)}, {x+(30*timonScale), y+(193*timonScale)}, {x+(25*timonScale), y+(197*timonScale)}, {x+(20*timonScale), y+(200*timonScale)}, {x+(19*timonScale), y+(202*timonScale)}, {x+(41*timonScale), y+(203*timonScale)}, {x+(54*timonScale), y+(207*timonScale)}, {x+(64*timonScale), y+(211*timonScale)}, {x+(72*timonScale), y+(216*timonScale)}, {x+(78*timonScale), y+(221*timonScale)}, {x+(81*timonScale), y+(226*timonScale)}, {x+(82*timonScale), y+(233*timonScale)}, {x+(95*timonScale), y+(234*timonScale)}, {x+(106*timonScale), y+(236*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonBackColor);
			txPolygon(TimonLeftLeg, 32);
		}

		if (timonLeg == 3)
		{
			//Правая стопа
			POINT TimonRightSole [14] = {{x+(-73*timonScale), y+(259*timonScale)}, {x+(-59*timonScale), y+(258*timonScale)}, {x+(-48*timonScale), y+(254*timonScale)}, {x+(-37*timonScale), y+(250*timonScale)}, {x+(-34*timonScale), y+(248*timonScale)}, {x+(-34*timonScale), y+(242*timonScale)}, {x+(-36*timonScale), y+(239*timonScale)}, {x+(-41*timonScale), y+(234*timonScale)}, {x+(-55*timonScale), y+(234*timonScale)}, {x+(-62*timonScale), y+(236*timonScale)}, {x+(-67*timonScale), y+(240*timonScale)}, {x+(-71*timonScale), y+(244*timonScale)}, {x+(-74*timonScale), y+(249*timonScale)}, {x+(-76*timonScale), y+(256*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonLimbColor);
			txPolygon(TimonRightSole, 14);

			//Правые пальцы
			txSetColor(RGB (45, 27, 27));
			txLine(x+(-75*timonScale), y+(253*timonScale), x+(-73*timonScale), y+(250*timonScale));
			txLine(x+(-73*timonScale), y+(250*timonScale), x+(-69*timonScale), y+(247*timonScale));
			txLine(x+(-69*timonScale), y+(247*timonScale), x+(-65*timonScale), y+(243*timonScale));
			txLine(x+(-65*timonScale), y+(243*timonScale), x+(-62*timonScale), y+(241*timonScale));
			txLine(x+(-62*timonScale), y+(241*timonScale), x+(-60*timonScale), y+(240*timonScale));

			txLine(x+(-73*timonScale), y+(257*timonScale), x+(-67*timonScale), y+(251*timonScale));
			txLine(x+(-67*timonScale), y+(251*timonScale), x+(-60*timonScale), y+(248*timonScale));
			txLine(x+(-60*timonScale), y+(248*timonScale), x+(-56*timonScale), y+(245*timonScale));
			txLine(x+(-56*timonScale), y+(245*timonScale), x+(-52*timonScale), y+(244*timonScale));

			//Правая нога
			POINT TimonRightLeg [38] = {{x+(-33*timonScale), y+(248*timonScale)}, {x+(-23*timonScale), y+(245*timonScale)}, {x+(-10*timonScale), y+(242*timonScale)}, {x+(-2*timonScale), y+(240*timonScale)}, {x+(3*timonScale), y+(239*timonScale)}, {x+(4*timonScale), y+(237*timonScale)}, {x+(0*timonScale), y+(233*timonScale)}, {x+(-4*timonScale), y+(231*timonScale)}, {x+(-12*timonScale), y+(223*timonScale)}, {x+(-14*timonScale), y+(218*timonScale)}, {x+(-12*timonScale), y+(212*timonScale)}, {x+(-6*timonScale), y+(207*timonScale)}, {x+(0*timonScale), y+(204*timonScale)}, {x+(0*timonScale), y+(203*timonScale)}, {x+(-6*timonScale), y+(196*timonScale)}, {x+(-10*timonScale), y+(191*timonScale)}, {x+(-10*timonScale), y+(162*timonScale)}, {x+(-24*timonScale), y+(162*timonScale)}, {x+(-30*timonScale), y+(176*timonScale)}, {x+(-34*timonScale), y+(184*timonScale)}, {x+(-41*timonScale), y+(197*timonScale)}, {x+(-44*timonScale), y+(203*timonScale)}, {x+(-46*timonScale), y+(211*timonScale)}, {x+(-47*timonScale), y+(223*timonScale)}, {x+(-46*timonScale), y+(225*timonScale)}, {x+(-44*timonScale), y+(223*timonScale)}, {x+(-43*timonScale), y+(224*timonScale)}, {x+(-41*timonScale), y+(222*timonScale)}, {x+(-38*timonScale), y+(225*timonScale)}, {x+(-36*timonScale), y+(223*timonScale)}, {x+(-27*timonScale), y+(226*timonScale)}, {x+(-20*timonScale), y+(229*timonScale)}, {x+(-14*timonScale), y+(232*timonScale)}, {x+(-13*timonScale), y+(233*timonScale)}, {x+(-14*timonScale), y+(234*timonScale)}, {x+(-40*timonScale), y+(234*timonScale)}, {x+(-36*timonScale), y+(238*timonScale)}, {x+(-33*timonScale), y+(242*timonScale)}, };

			txSetColor(BLACK);
			txSetFillColor(timonBackColor);
			txPolygon(TimonRightLeg, 38);

			//Левая стопа
			POINT TimonLeftSole [15] = {{x+(112*timonScale), y+(237*timonScale)}, {x+(112*timonScale), y+(231*timonScale)}, {x+(119*timonScale), y+(224*timonScale)}, {x+(119*timonScale), y+(223*timonScale)}, {x+(121*timonScale), y+(222*timonScale)}, {x+(139*timonScale), y+(222*timonScale)}, {x+(148*timonScale), y+(227*timonScale)}, {x+(151*timonScale), y+(231*timonScale)}, {x+(152*timonScale), y+(234*timonScale)}, {x+(152*timonScale), y+(240*timonScale)}, {x+(151*timonScale), y+(241*timonScale)}, {x+(141*timonScale), y+(241*timonScale)}, {x+(136*timonScale), y+(240*timonScale)}, {x+(127*timonScale), y+(239*timonScale)}, {x+(119*timonScale), y+(238*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonLimbColor);
			txPolygon(TimonLeftSole, 15);

			//Левые пальцы
			txSetColor(RGB (45, 27, 27));
			txLine(x+(150*timonScale), y+(232*timonScale), x+(145*timonScale), y+(230*timonScale));
			txLine(x+(145*timonScale), y+(230*timonScale), x+(140*timonScale), y+(227*timonScale));
			txLine(x+(140*timonScale), y+(227*timonScale), x+(135*timonScale), y+(226*timonScale));

			txLine(x+(147*timonScale), y+(240*timonScale), x+(140*timonScale), y+(233*timonScale));
			txLine(x+(140*timonScale), y+(233*timonScale), x+(137*timonScale), y+(232*timonScale));
			txLine(x+(137*timonScale), y+(232*timonScale), x+(131*timonScale), y+(229*timonScale));

			//Левая нога
			POINT TimonLeftLeg [32] = {{x+(111*timonScale), y+(237*timonScale)}, {x+(111*timonScale), y+(231*timonScale)}, {x+(118*timonScale), y+(224*timonScale)}, {x+(118*timonScale), y+(223*timonScale)}, {x+(96*timonScale), y+(224*timonScale)}, {x+(79*timonScale), y+(207*timonScale)}, {x+(79*timonScale), y+(206*timonScale)}, {x+(61*timonScale), y+(188*timonScale)}, {x+(61*timonScale), y+(187*timonScale)}, {x+(58*timonScale), y+(183*timonScale)}, {x+(55*timonScale), y+(179*timonScale)}, {x+(51*timonScale), y+(173*timonScale)}, {x+(47*timonScale), y+(166*timonScale)}, {x+(43*timonScale), y+(160*timonScale)}, {x+(40*timonScale), y+(155*timonScale)}, {x+(39*timonScale), y+(156*timonScale)}, {x+(39*timonScale), y+(178*timonScale)}, {x+(37*timonScale), y+(184*timonScale)}, {x+(34*timonScale), y+(189*timonScale)}, {x+(30*timonScale), y+(193*timonScale)}, {x+(25*timonScale), y+(197*timonScale)}, {x+(20*timonScale), y+(200*timonScale)}, {x+(19*timonScale), y+(202*timonScale)}, {x+(41*timonScale), y+(203*timonScale)}, {x+(54*timonScale), y+(207*timonScale)}, {x+(64*timonScale), y+(211*timonScale)}, {x+(72*timonScale), y+(216*timonScale)}, {x+(78*timonScale), y+(221*timonScale)}, {x+(81*timonScale), y+(226*timonScale)}, {x+(82*timonScale), y+(233*timonScale)}, {x+(95*timonScale), y+(234*timonScale)}, {x+(106*timonScale), y+(236*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonBackColor);
			txPolygon(TimonLeftLeg, 32);
		}

			//Пузико
			POINT TimonBelly [52] = {{x+(1*timonScale), y+(203*timonScale)}, {x+(-6*timonScale), y+(197*timonScale)}, {x+(-9*timonScale), y+(192*timonScale)}, {x+(-10*timonScale), y+(191*timonScale)}, {x+(-10*timonScale), y+(162*timonScale)}, {x+(-9*timonScale), y+(161*timonScale)}, {x+(-8*timonScale), y+(155*timonScale)}, {x+(-6*timonScale), y+(148*timonScale)}, {x+(-3*timonScale), y+(141*timonScale)}, {x+(0*timonScale), y+(131*timonScale)}, {x+(2*timonScale), y+(116*timonScale)}, {x+(4*timonScale), y+(102*timonScale)}, {x+(7*timonScale), y+(90*timonScale)}, {x+(10*timonScale), y+(81*timonScale)}, {x+(13*timonScale), y+(72*timonScale)}, {x+(16*timonScale), y+(62*timonScale)}, {x+(16*timonScale), y+(40*timonScale)}, {x+(13*timonScale), y+(31*timonScale)}, {x+(10*timonScale), y+(23*timonScale)}, {x+(6*timonScale), y+(15*timonScale)}, {x+(3*timonScale), y+(8*timonScale)}, {x+(0*timonScale), y+(4*timonScale)}, {x+(0*timonScale), y+(0*timonScale)}, {x+(15*timonScale), y+(4*timonScale)}, {x+(21*timonScale), y+(6*timonScale)}, {x+(19*timonScale), y+(7*timonScale)}, {x+(25*timonScale), y+(11*timonScale)}, {x+(31*timonScale), y+(15*timonScale)}, {x+(25*timonScale), y+(14*timonScale)}, {x+(32*timonScale), y+(20*timonScale)}, {x+(39*timonScale), y+(27*timonScale)}, {x+(34*timonScale), y+(25*timonScale)}, {x+(39*timonScale), y+(37*timonScale)}, {x+(42*timonScale), y+(42*timonScale)}, {x+(42*timonScale), y+(46*timonScale)}, {x+(41*timonScale), y+(47*timonScale)}, {x+(38*timonScale), y+(57*timonScale)}, {x+(36*timonScale), y+(75*timonScale)}, {x+(34*timonScale), y+(93*timonScale)}, {x+(32*timonScale), y+(117*timonScale)}, {x+(34*timonScale), y+(131*timonScale)}, {x+(37*timonScale), y+(146*timonScale)}, {x+(40*timonScale), y+(154*timonScale)}, {x+(39*timonScale), y+(178*timonScale)}, {x+(37*timonScale), y+(184*timonScale)}, {x+(34*timonScale), y+(189*timonScale)}, {x+(30*timonScale), y+(193*timonScale)}, {x+(25*timonScale), y+(197*timonScale)}, {x+(20*timonScale), y+(200*timonScale)}, {x+(19*timonScale), y+(201*timonScale)}, {x+(5*timonScale), y+(202*timonScale)}, {x+(2*timonScale), y+(204*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonBallyColor);
			txPolygon(TimonBelly, 52);

		if (timonTale)
		{
			//Начало хвоста
			POINT TimonTaleStart [23] = {{x+(-19*timonScale), y+(143*timonScale)}, {x+(-20*timonScale), y+(143*timonScale)}, {x+(-30*timonScale), y+(133*timonScale)}, {x+(-34*timonScale), y+(127*timonScale)}, {x+(-38*timonScale), y+(121*timonScale)}, {x+(-43*timonScale), y+(113*timonScale)}, {x+(-48*timonScale), y+(107*timonScale)}, {x+(-51*timonScale), y+(102*timonScale)}, {x+(-56*timonScale), y+(98*timonScale)}, {x+(-61*timonScale), y+(95*timonScale)}, {x+(-64*timonScale), y+(92*timonScale)}, {x+(-65*timonScale), y+(92*timonScale)}, {x+(-66*timonScale), y+(93*timonScale)}, {x+(-70*timonScale), y+(93*timonScale)}, {x+(-72*timonScale), y+(93*timonScale)}, {x+(-73*timonScale), y+(94*timonScale)}, {x+(-74*timonScale), y+(96*timonScale)}, {x+(-74*timonScale), y+(103*timonScale)}, {x+(-74*timonScale), y+(104*timonScale)}, {x+(-68*timonScale), y+(110*timonScale)}, {x+(-53*timonScale), y+(145*timonScale)}, {x+(-33*timonScale), y+(181*timonScale)}, {x+(-24*timonScale), y+(164*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonBackColor);
			txPolygon(TimonTaleStart, 23);

			//Конец хвоста
			POINT TimonTaleEnd [17] = {{x+(-116*timonScale), y+(77*timonScale)}, {x+(-101*timonScale), y+(80*timonScale)}, {x+(-87*timonScale), y+(84*timonScale)}, {x+(-75*timonScale), y+(88*timonScale)}, {x+(-65*timonScale), y+(91*timonScale)}, {x+(-66*timonScale), y+(92*timonScale)}, {x+(-71*timonScale), y+(92*timonScale)}, {x+(-73*timonScale), y+(93*timonScale)}, {x+(-75*timonScale), y+(95*timonScale)}, {x+(-75*timonScale), y+(103*timonScale)}, {x+(-75*timonScale), y+(103*timonScale)}, {x+(-76*timonScale), y+(103*timonScale)}, {x+(-82*timonScale), y+(97*timonScale)}, {x+(-90*timonScale), y+(93*timonScale)}, {x+(-95*timonScale), y+(90*timonScale)}, {x+(-115*timonScale), y+(80*timonScale)}, {x+(-116*timonScale), y+(79*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonLimbColor);
			txPolygon(TimonTaleEnd, 17);
		}

		//Спина
		POINT TimonBack [32] = {{x+(-24*timonScale), y+(162*timonScale)}, {x+(-23*timonScale), y+(158*timonScale)}, {x+(-19*timonScale), y+(143*timonScale)}, {x+(-11*timonScale), y+(114*timonScale)}, {x+(-6*timonScale), y+(84*timonScale)}, {x+(-4*timonScale), y+(77*timonScale)}, {x+(-4*timonScale), y+(45*timonScale)}, {x+(-10*timonScale), y+(31*timonScale)}, {x+(-14*timonScale), y+(24*timonScale)}, {x+(-14*timonScale), y+(3*timonScale)}, {x+(-10*timonScale), y+(-1*timonScale)}, {x+(-9*timonScale), y+(-2*timonScale)}, {x+(0*timonScale), y+(-2*timonScale)}, {x+(0*timonScale), y+(0*timonScale)}, {x+(0*timonScale), y+(4*timonScale)}, {x+(3*timonScale), y+(8*timonScale)}, {x+(6*timonScale), y+(15*timonScale)}, {x+(10*timonScale), y+(23*timonScale)}, {x+(13*timonScale), y+(31*timonScale)}, {x+(16*timonScale), y+(40*timonScale)}, {x+(16*timonScale), y+(62*timonScale)}, {x+(13*timonScale), y+(72*timonScale)}, {x+(10*timonScale), y+(81*timonScale)}, {x+(7*timonScale), y+(90*timonScale)}, {x+(4*timonScale), y+(102*timonScale)}, {x+(2*timonScale), y+(116*timonScale)}, {x+(0*timonScale), y+(131*timonScale)}, {x+(-3*timonScale), y+(141*timonScale)}, {x+(-6*timonScale), y+(148*timonScale)}, {x+(-8*timonScale), y+(155*timonScale)}, {x+(-9*timonScale), y+(161*timonScale)}, {x+(-10*timonScale), y+(162*timonScale)}, };
		txSetColor(BLACK);
		txSetFillColor(timonBackColor);
		txPolygon(TimonBack, 32);

		txSetColor(timonBackColor);
		txLine(x+(-23*timonScale), y+(162*timonScale), x+(-10*timonScale), y+(162*timonScale));

		//Правая рука
		POINT TimonRightArm [50] = {{x+(-14*timonScale), y+(24*timonScale)}, {x+(-17*timonScale), y+(25*timonScale)}, {x+(-19*timonScale), y+(27*timonScale)}, {x+(-26*timonScale), y+(32*timonScale)}, {x+(-34*timonScale), y+(37*timonScale)}, {x+(-41*timonScale), y+(39*timonScale)}, {x+(-47*timonScale), y+(46*timonScale)}, {x+(-49*timonScale), y+(46*timonScale)}, {x+(-48*timonScale), y+(42*timonScale)}, {x+(-49*timonScale), y+(39*timonScale)}, {x+(-54*timonScale), y+(48*timonScale)}, {x+(-55*timonScale), y+(39*timonScale)}, {x+(-51*timonScale), y+(29*timonScale)}, {x+(-51*timonScale), y+(10*timonScale)}, {x+(-47*timonScale), y+(-7*timonScale)}, {x+(-47*timonScale), y+(-15*timonScale)}, {x+(-50*timonScale), y+(-19*timonScale)}, {x+(-57*timonScale), y+(-23*timonScale)}, {x+(-67*timonScale), y+(-23*timonScale)}, {x+(-80*timonScale), y+(-17*timonScale)}, {x+(-85*timonScale), y+(-17*timonScale)}, {x+(-87*timonScale), y+(-20*timonScale)}, {x+(-88*timonScale), y+(-21*timonScale)}, {x+(-104*timonScale), y+(-21*timonScale)}, {x+(-104*timonScale), y+(-24*timonScale)}, {x+(-99*timonScale), y+(-26*timonScale)}, {x+(-99*timonScale), y+(-28*timonScale)}, {x+(-101*timonScale), y+(-29*timonScale)}, {x+(-101*timonScale), y+(-32*timonScale)}, {x+(-93*timonScale), y+(-31*timonScale)}, {x+(-88*timonScale), y+(-28*timonScale)}, {x+(-67*timonScale), y+(-28*timonScale)}, {x+(-50*timonScale), y+(-39*timonScale)}, {x+(-43*timonScale), y+(-46*timonScale)}, {x+(-41*timonScale), y+(-49*timonScale)}, {x+(-41*timonScale), y+(-53*timonScale)}, {x+(-39*timonScale), y+(-56*timonScale)}, {x+(-29*timonScale), y+(-56*timonScale)}, {x+(-27*timonScale), y+(-54*timonScale)}, {x+(-27*timonScale), y+(-51*timonScale)}, {x+(-29*timonScale), y+(-49*timonScale)}, {x+(-33*timonScale), y+(-48*timonScale)}, {x+(-38*timonScale), y+(-41*timonScale)}, {x+(-41*timonScale), y+(-32*timonScale)}, {x+(-41*timonScale), y+(4*timonScale)}, {x+(-37*timonScale), y+(14*timonScale)}, {x+(-34*timonScale), y+(20*timonScale)}, {x+(-24*timonScale), y+(13*timonScale)}, {x+(-17*timonScale), y+(5*timonScale)}, {x+(-14*timonScale), y+(3*timonScale)}, };
		txSetColor(BLACK);
		txSetFillColor(timonBackColor);
		txPolygon(TimonRightArm, 50);

		txSetColor(BLACK);
		txLine(x+(-14*timonScale), y+(23*timonScale), x+(-14*timonScale), y+(4*timonScale));
		txSetColor(BLACK);
		txLine(x+(-34*timonScale), y+(21*timonScale), x+(-34*timonScale), y+(27*timonScale));
		txLine(x+(-34*timonScale), y+(27*timonScale), x+(-36*timonScale), y+(30*timonScale));

		txSetColor(BLACK);
		txLine(x+(-87*timonScale), y+(-20*timonScale), x+(-86*timonScale), y+(-20*timonScale));
		txLine(x+(-86*timonScale), y+(-20*timonScale), x+(-85*timonScale), y+(-22*timonScale));
		txLine(x+(-85*timonScale), y+(-22*timonScale), x+(-77*timonScale), y+(-24*timonScale));
		txLine(x+(-77*timonScale), y+(-24*timonScale), x+(-75*timonScale), y+(-26*timonScale));
		txLine(x+(-75*timonScale), y+(-26*timonScale), x+(-73*timonScale), y+(-28*timonScale));

		txSetFillColor (timonLimbColor);
		txFloodFill(x+(-91*timonScale), y+(-26*timonScale), BLACK, FLOODFILLBORDER);
		txLine(x+(-98*timonScale), y+(-27*timonScale), x+(-95*timonScale), y+(-26*timonScale));
		txLine(x+(-95*timonScale), y+(-26*timonScale), x+(-92*timonScale), y+(-24*timonScale));
		txLine(x+(-92*timonScale), y+(-24*timonScale), x+(-87*timonScale), y+(-20*timonScale));

		txLine(x+(-88*timonScale), y+(-28*timonScale), x+(-83*timonScale), y+(-24*timonScale));

		txLine(x+(-47*timonScale), y+(-42*timonScale), x+(-42*timonScale), y+(-41*timonScale));
		txLine(x+(-42*timonScale), y+(-41*timonScale), x+(-39*timonScale), y+(-38*timonScale));

		txSetFillColor (timonLimbColor);
		txFloodFill(x+(-35*timonScale), y+(-52*timonScale), BLACK, FLOODFILLBORDER);

		//Правая ладонь
		POINT TimonPalm [11] = {{x+(-60*timonScale), y+(-29*timonScale)}, {x+(-51*timonScale), y+(-33*timonScale)}, {x+(-50*timonScale), y+(-34*timonScale)}, {x+(-48*timonScale), y+(-34*timonScale)}, {x+(-45*timonScale), y+(-30*timonScale)}, {x+(-44*timonScale), y+(-23*timonScale)}, {x+(-45*timonScale), y+(-22*timonScale)}, {x+(-51*timonScale), y+(-22*timonScale)}, {x+(-54*timonScale), y+(-24*timonScale)}, {x+(-56*timonScale), y+(-26*timonScale)}, {x+(-60*timonScale), y+(-27*timonScale)}, };
		txSetColor(BLACK);
		txSetFillColor(timonBackColor);
		txPolygon(TimonPalm, 11);

		txSetColor(BLACK);
		txLine(x+(-76*timonScale), y+(-25*timonScale), x+(-69*timonScale), y+(-26*timonScale));
		txLine(x+(-69*timonScale), y+(-26*timonScale), x+(-60*timonScale), y+(-27*timonScale));

		//Левая рука
		POINT TimonLeftArm [60] = {{x+(0*timonScale), y+(0*timonScale)}, {x+(0*timonScale), y+(-2*timonScale)}, {x+(28*timonScale), y+(-2*timonScale)}, {x+(29*timonScale), y+(0*timonScale)}, {x+(49*timonScale), y+(20*timonScale)}, {x+(56*timonScale), y+(28*timonScale)}, {x+(59*timonScale), y+(28*timonScale)}, {x+(62*timonScale), y+(24*timonScale)}, {x+(66*timonScale), y+(19*timonScale)}, {x+(73*timonScale), y+(11*timonScale)}, {x+(85*timonScale), y+(-4*timonScale)}, {x+(86*timonScale), y+(-10*timonScale)}, {x+(99*timonScale), y+(-24*timonScale)}, {x+(101*timonScale), y+(-39*timonScale)}, {x+(103*timonScale), y+(-43*timonScale)}, {x+(106*timonScale), y+(-43*timonScale)}, {x+(109*timonScale), y+(-37*timonScale)}, {x+(109*timonScale), y+(-32*timonScale)}, {x+(105*timonScale), y+(-25*timonScale)}, {x+(105*timonScale), y+(-20*timonScale)}, {x+(111*timonScale), y+(-15*timonScale)}, {x+(130*timonScale), y+(-15*timonScale)}, {x+(138*timonScale), y+(-8*timonScale)}, {x+(140*timonScale), y+(-4*timonScale)}, {x+(140*timonScale), y+(0*timonScale)}, {x+(137*timonScale), y+(1*timonScale)}, {x+(136*timonScale), y+(4*timonScale)}, {x+(131*timonScale), y+(4*timonScale)}, {x+(116*timonScale), y+(-3*timonScale)}, {x+(103*timonScale), y+(-3*timonScale)}, {x+(90*timonScale), y+(2*timonScale)}, {x+(86*timonScale), y+(6*timonScale)}, {x+(82*timonScale), y+(12*timonScale)}, {x+(78*timonScale), y+(20*timonScale)}, {x+(73*timonScale), y+(32*timonScale)}, {x+(71*timonScale), y+(38*timonScale)}, {x+(69*timonScale), y+(40*timonScale)}, {x+(68*timonScale), y+(51*timonScale)}, {x+(64*timonScale), y+(57*timonScale)}, {x+(64*timonScale), y+(57*timonScale)}, {x+(63*timonScale), y+(54*timonScale)}, {x+(61*timonScale), y+(57*timonScale)}, {x+(60*timonScale), y+(54*timonScale)}, {x+(59*timonScale), y+(58*timonScale)}, {x+(56*timonScale), y+(53*timonScale)}, {x+(54*timonScale), y+(49*timonScale)}, {x+(48*timonScale), y+(43*timonScale)}, {x+(44*timonScale), y+(40*timonScale)}, {x+(42*timonScale), y+(46*timonScale)}, {x+(42*timonScale), y+(42*timonScale)}, {x+(39*timonScale), y+(37*timonScale)}, {x+(34*timonScale), y+(25*timonScale)}, {x+(39*timonScale), y+(27*timonScale)}, {x+(32*timonScale), y+(20*timonScale)}, {x+(25*timonScale), y+(14*timonScale)}, {x+(31*timonScale), y+(15*timonScale)}, {x+(25*timonScale), y+(11*timonScale)}, {x+(19*timonScale), y+(7*timonScale)}, {x+(21*timonScale), y+(6*timonScale)}, {x+(15*timonScale), y+(4*timonScale)}, };
		txSetColor(BLACK);
		txSetFillColor(timonBackColor);
		txPolygon(TimonLeftArm, 60);

		txSetColor(BLACK);
		txLine(x+(96*timonScale), y+(-20*timonScale), x+(99*timonScale), y+(-19*timonScale));
		txLine(x+(99*timonScale), y+(-19*timonScale), x+(103*timonScale), y+(-19*timonScale));
		txLine(x+(103*timonScale), y+(-19*timonScale), x+(105*timonScale), y+(-20*timonScale));

		txSetFillColor (timonLimbColor);
		txFloodFill(x+(104*timonScale), y+(-29*timonScale), BLACK, FLOODFILLBORDER);

		if(timonEar == 1)
		{
			//Правое ухо
			POINT TimonRightEar [14] = {{x+(-17*timonScale), y+(-2*timonScale)}, {x+(-18*timonScale), y+(2*timonScale)}, {x+(-22*timonScale), y+(5*timonScale)}, {x+(-27*timonScale), y+(5*timonScale)}, {x+(-32*timonScale), y+(1*timonScale)}, {x+(-34*timonScale), y+(1*timonScale)}, {x+(-34*timonScale), y+(-6*timonScale)}, {x+(-28*timonScale), y+(-14*timonScale)}, {x+(-24*timonScale), y+(-20*timonScale)}, {x+(-20*timonScale), y+(-25*timonScale)}, {x+(-17*timonScale), y+(-27*timonScale)}, {x+(-20*timonScale), y+(-19*timonScale)}, {x+(-24*timonScale), y+(-14*timonScale)}, {x+(-24*timonScale), y+(-7*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(BLACK);
			txPolygon(TimonRightEar, 14);

			txSetColor(BLACK);
			txSetFillColor(ORANGE);
			txCircle(x+(-22*timonScale), y+(-1*timonScale), 4*timonScale);
		}

		if(timonEar == 2)
		{
			//Левое ухо
			POINT TimonLeftEar [9] = {{x+(39*timonScale), y+(-9*timonScale)}, {x+(45*timonScale), y+(-10*timonScale)}, {x+(49*timonScale), y+(-12*timonScale)}, {x+(52*timonScale), y+(-15*timonScale)}, {x+(52*timonScale), y+(-27*timonScale)}, {x+(49*timonScale), y+(-28*timonScale)}, {x+(47*timonScale), y+(-24*timonScale)}, {x+(45*timonScale), y+(-20*timonScale)}, {x+(42*timonScale), y+(-16*timonScale)}};
			txSetColor(BLACK);
			txSetFillColor(BLACK);
			txPolygon(TimonLeftEar, 9);

			txSetColor(BLACK);
			txSetFillColor(ORANGE);
			txCircle(x+(44*timonScale), y+(-16*timonScale), 6*timonScale);
		}

		if(timonEar == 3)
		{
			//Правое ухо
			POINT TimonRightEar [14] = {{x+(-17*timonScale), y+(-2*timonScale)}, {x+(-18*timonScale), y+(2*timonScale)}, {x+(-22*timonScale), y+(5*timonScale)}, {x+(-27*timonScale), y+(5*timonScale)}, {x+(-32*timonScale), y+(1*timonScale)}, {x+(-34*timonScale), y+(1*timonScale)}, {x+(-34*timonScale), y+(-6*timonScale)}, {x+(-28*timonScale), y+(-14*timonScale)}, {x+(-24*timonScale), y+(-20*timonScale)}, {x+(-20*timonScale), y+(-25*timonScale)}, {x+(-17*timonScale), y+(-27*timonScale)}, {x+(-20*timonScale), y+(-19*timonScale)}, {x+(-24*timonScale), y+(-14*timonScale)}, {x+(-24*timonScale), y+(-7*timonScale)}};
			txSetColor(BLACK);
			txSetFillColor(BLACK);
			txPolygon(TimonRightEar, 14);

			txSetColor(BLACK);
			txSetFillColor(ORANGE);
			txCircle(x+(-22*timonScale), y+(-1*timonScale), 4*timonScale);

			//Левое ухо
			POINT TimonLeftEar [9] = {{x+(39*timonScale), y+(-9*timonScale)}, {x+(45*timonScale), y+(-10*timonScale)}, {x+(49*timonScale), y+(-12*timonScale)}, {x+(52*timonScale), y+(-15*timonScale)}, {x+(52*timonScale), y+(-27*timonScale)}, {x+(49*timonScale), y+(-28*timonScale)}, {x+(47*timonScale), y+(-24*timonScale)}, {x+(45*timonScale), y+(-20*timonScale)}, {x+(42*timonScale), y+(-16*timonScale)}};
			txSetColor(BLACK);
			txSetFillColor(BLACK);
			txPolygon(TimonLeftEar, 9);

			txSetColor(BLACK);
			txSetFillColor(ORANGE);
			txCircle(x+(44*timonScale), y+(-16*timonScale), 6*timonScale);
		}

		if (timonHair)
		{
			//Голова
			POINT TimonHead [30] = {{x+(-17*timonScale), y+(-2*timonScale)}, {x+(28*timonScale), y+(-2*timonScale)}, {x+(34*timonScale), y+(-4*timonScale)}, {x+(39*timonScale), y+(-9*timonScale)}, {x+(42*timonScale), y+(-16*timonScale)}, {x+(44*timonScale), y+(-20*timonScale)}, {x+(47*timonScale), y+(-24*timonScale)}, {x+(49*timonScale), y+(-28*timonScale)}, {x+(49*timonScale), y+(-39*timonScale)}, {x+(48*timonScale), y+(-40*timonScale)}, {x+(38*timonScale), y+(-41*timonScale)}, {x+(36*timonScale), y+(-44*timonScale)}, {x+(33*timonScale), y+(-48*timonScale)}, {x+(30*timonScale), y+(-52*timonScale)}, {x+(27*timonScale), y+(-55*timonScale)}, {x+(27*timonScale), y+(-57*timonScale)}, {x+(24*timonScale), y+(-63*timonScale)}, {x+(22*timonScale), y+(-64*timonScale)}, {x+(17*timonScale), y+(-61*timonScale)}, {x+(17*timonScale), y+(-56*timonScale)}, {x+(12*timonScale), y+(-56*timonScale)}, {x+(11*timonScale), y+(-58*timonScale)}, {x+(2*timonScale), y+(-58*timonScale)}, {x+(-4*timonScale), y+(-53*timonScale)}, {x+(-9*timonScale), y+(-46*timonScale)}, {x+(-12*timonScale), y+(-44*timonScale)}, {x+(-17*timonScale), y+(-27*timonScale)}, {x+(-20*timonScale), y+(-19*timonScale)}, {x+(-24*timonScale), y+(-14*timonScale)}, {x+(-24*timonScale), y+(-7*timonScale)}};
			txSetColor(BLACK);
			txSetFillColor(timonBackColor);
			txPolygon(TimonHead, 30);

			//Волосы
			POINT TimonHairstyle [29] = {{x+(-11*timonScale), y+(-45*timonScale)}, {x+(-11*timonScale), y+(-61*timonScale)}, {x+(-7*timonScale), y+(-57*timonScale)}, {x+(-3*timonScale), y+(-65*timonScale)}, {x+(1*timonScale), y+(-70*timonScale)}, {x+(5*timonScale), y+(-70*timonScale)}, {x+(2*timonScale), y+(-64*timonScale)}, {x+(3*timonScale), y+(-64*timonScale)}, {x+(8*timonScale), y+(-68*timonScale)}, {x+(17*timonScale), y+(-74*timonScale)}, {x+(18*timonScale), y+(-74*timonScale)}, {x+(18*timonScale), y+(-72*timonScale)}, {x+(15*timonScale), y+(-71*timonScale)}, {x+(19*timonScale), y+(-73*timonScale)}, {x+(14*timonScale), y+(-69*timonScale)}, {x+(19*timonScale), y+(-70*timonScale)}, {x+(28*timonScale), y+(-71*timonScale)}, {x+(29*timonScale), y+(-69*timonScale)}, {x+(24*timonScale), y+(-69*timonScale)}, {x+(31*timonScale), y+(-62*timonScale)}, {x+(24*timonScale), y+(-63*timonScale)}, {x+(22*timonScale), y+(-64*timonScale)}, {x+(17*timonScale), y+(-61*timonScale)}, {x+(17*timonScale), y+(-56*timonScale)}, {x+(12*timonScale), y+(-56*timonScale)}, {x+(11*timonScale), y+(-58*timonScale)}, {x+(2*timonScale), y+(-58*timonScale)}, {x+(-4*timonScale), y+(-53*timonScale)}, {x+(-9*timonScale), y+(-46*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(timonHairColor);
			txPolygon(TimonHairstyle, 29);
		}else{
			//Голова
			POINT TimonHead [30] = {{x+(-17*timonScale), y+(-2*timonScale)}, {x+(28*timonScale), y+(-2*timonScale)}, {x+(34*timonScale), y+(-4*timonScale)}, {x+(39*timonScale), y+(-9*timonScale)}, {x+(42*timonScale), y+(-16*timonScale)}, {x+(44*timonScale), y+(-20*timonScale)}, {x+(47*timonScale), y+(-24*timonScale)}, {x+(49*timonScale), y+(-28*timonScale)}, {x+(49*timonScale), y+(-39*timonScale)}, {x+(48*timonScale), y+(-40*timonScale)}, {x+(38*timonScale), y+(-41*timonScale)}, {x+(36*timonScale), y+(-44*timonScale)}, {x+(33*timonScale), y+(-48*timonScale)}, {x+(30*timonScale), y+(-52*timonScale)}, {x+(27*timonScale), y+(-55*timonScale)}, {x+(27*timonScale), y+(-57*timonScale)}, {x+(24*timonScale), y+(-63*timonScale)}, {x+(22*timonScale), y+(-64*timonScale)}, {x+(16*timonScale), y+(-64*timonScale)}, {x+(12*timonScale), y+(-63*timonScale)}, {x+(8*timonScale), y+(-62*timonScale)}, {x+(6*timonScale), y+(-61*timonScale)}, {x+(2*timonScale), y+(-58*timonScale)}, {x+(-4*timonScale), y+(-53*timonScale)}, {x+(-9*timonScale), y+(-46*timonScale)}, {x+(-12*timonScale), y+(-44*timonScale)}, {x+(-17*timonScale), y+(-27*timonScale)}, {x+(-20*timonScale), y+(-19*timonScale)}, {x+(-24*timonScale), y+(-14*timonScale)}, {x+(-24*timonScale), y+(-7*timonScale)}};
			txSetColor(BLACK);
			txSetFillColor(timonBackColor);
			txPolygon(TimonHead, 30);
		}

		//Нос
		POINT TimonNose [11] = {{x+(24*timonScale), y+(-25*timonScale)}, {x+(24*timonScale), y+(-30*timonScale)}, {x+(31*timonScale), y+(-34*timonScale)}, {x+(32*timonScale), y+(-35*timonScale)}, {x+(43*timonScale), y+(-35*timonScale)}, {x+(44*timonScale), y+(-34*timonScale)}, {x+(44*timonScale), y+(-30*timonScale)}, {x+(41*timonScale), y+(-25*timonScale)}, {x+(36*timonScale), y+(-20*timonScale)}, {x+(29*timonScale), y+(-20*timonScale)}, {x+(26*timonScale), y+(-22*timonScale)}, };
		txSetColor(BLACK);
		txSetFillColor(ORANGE);
		txPolygon(TimonNose, 11);

		POINT TimonRightEye [10] = {{x+(-5*timonScale), y+(-28*timonScale)}, {x+(-5*timonScale), y+(-41*timonScale)}, {x+(-3*timonScale), y+(-45*timonScale)}, {x+(0*timonScale), y+(-51*timonScale)}, {x+(3*timonScale), y+(-54*timonScale)}, {x+(6*timonScale), y+(-54*timonScale)}, {x+(11*timonScale), y+(-49*timonScale)}, {x+(16*timonScale), y+(-41*timonScale)}, {x+(16*timonScale), y+(-34*timonScale)}, {x+(13*timonScale), y+(-28*timonScale)}, };
		txSetColor(BLACK);
		txSetFillColor(ORANGE);
		txPolygon(TimonRightEye, 10);

		txSetColor(BLACK);
		txSetFillColor(WHITE);
		txEllipse(x+(2*timonScale), y+(-44*timonScale), x+(15*timonScale), y+(-28*timonScale));

		txSetColor(BLACK);
		txSetFillColor(BLACK);
		txCircle(x+(10*timonScale), y+(-40*timonScale), 3*timonScale);

		POINT TimonLeftEye [9] = {{x+(23*timonScale), y+(-44*timonScale)}, {x+(30*timonScale), y+(-36*timonScale)}, {x+(33*timonScale), y+(-36*timonScale)}, {x+(33*timonScale), y+(-46*timonScale)}, {x+(31*timonScale), y+(-50*timonScale)}, {x+(29*timonScale), y+(-53*timonScale)}, {x+(27*timonScale), y+(-53*timonScale)}, {x+(26*timonScale), y+(-52*timonScale)}, {x+(23*timonScale), y+(-49*timonScale)}, };
		txSetColor(BLACK);
		txSetFillColor(WHITE);
		txPolygon(TimonLeftEye, 9);

		txSetColor(BLACK);
		txSetFillColor(BLACK);
		txCircle(x+(28*timonScale), y+(-48*timonScale), 3*timonScale);

		txSetColor(BLACK);
		txLine(x+(120*timonScale), y+(-15*timonScale), x+(121*timonScale), y+(-10*timonScale));
		txLine(x+(121*timonScale), y+(-10*timonScale), x+(121*timonScale), y+(-7*timonScale));
		txLine(x+(121*timonScale), y+(-7*timonScale), x+(120*timonScale), y+(-1*timonScale));

		txSetFillColor(timonLimbColor);
		txFloodFill(x+(129*timonScale), y+(-7*timonScale), BLACK, FLOODFILLBORDER);

		txLine(x+(121*timonScale), y+(-10*timonScale), x+(126*timonScale), y+(-9*timonScale));
		txLine(x+(126*timonScale), y+(-9*timonScale), x+(132*timonScale), y+(-9*timonScale));
		txLine(x+(132*timonScale), y+(-9*timonScale), x+(136*timonScale), y+(-7*timonScale));
		txLine(x+(136*timonScale), y+(-7*timonScale), x+(139*timonScale), y+(-5*timonScale));

		txLine(x+(121*timonScale), y+(-7*timonScale), x+(128*timonScale), y+(-6*timonScale));
		txLine(x+(128*timonScale), y+(-6*timonScale), x+(132*timonScale), y+(-4*timonScale));
		txLine(x+(132*timonScale), y+(-4*timonScale), x+(135*timonScale), y+(-2*timonScale));
		txLine(x+(135*timonScale), y+(-2*timonScale), x+(137*timonScale), y+(1*timonScale));


		if(timonRoth)
		{
			//Рот
			POINT TimonRoth [19] = {{x+(-10*timonScale), y+(-17*timonScale)}, {x+(-4*timonScale), y+(-19*timonScale)}, {x+(-3*timonScale), y+(-20*timonScale)}, {x+(7*timonScale), y+(-20*timonScale)}, {x+(20*timonScale), y+(-17*timonScale)}, {x+(21*timonScale), y+(-16*timonScale)}, {x+(32*timonScale), y+(-16*timonScale)}, {x+(36*timonScale), y+(-17*timonScale)}, {x+(40*timonScale), y+(-19*timonScale)}, {x+(38*timonScale), y+(-16*timonScale)}, {x+(37*timonScale), y+(-13*timonScale)}, {x+(35*timonScale), y+(-10*timonScale)}, {x+(31*timonScale), y+(-8*timonScale)}, {x+(29*timonScale), y+(-7*timonScale)}, {x+(11*timonScale), y+(-7*timonScale)}, {x+(6*timonScale), y+(-9*timonScale)}, {x+(0*timonScale), y+(-11*timonScale)}, {x+(-2*timonScale), y+(-12*timonScale)}, {x+(-9*timonScale), y+(-14*timonScale)}, };
			txSetColor(BLACK);
			txSetFillColor(DARKORANGE);
			txPolygon(TimonRoth, 19);

			txSetColor(BLACK);
			txLine(x+(-9*timonScale), y+(-14*timonScale), x+(-6*timonScale), y+(-16*timonScale));
			txLine(x+(-6*timonScale), y+(-16*timonScale), x+(0*timonScale), y+(-16*timonScale));
			txLine(x+(0*timonScale), y+(-16*timonScale), x+(11*timonScale), y+(-12*timonScale));
			txLine(x+(11*timonScale), y+(-12*timonScale), x+(24*timonScale), y+(-11*timonScale));
			txLine(x+(24*timonScale), y+(-11*timonScale), x+(29*timonScale), y+(-10*timonScale));
			txLine(x+(29*timonScale), y+(-10*timonScale), x+(37*timonScale), y+(-13*timonScale));

			txLine(x+(-4*timonScale), y+(-19*timonScale), x+(-1*timonScale), y+(-18*timonScale));
			txLine(x+(-1*timonScale), y+(-18*timonScale), x+(8*timonScale), y+(-15*timonScale));
			txLine(x+(8*timonScale), y+(-15*timonScale), x+(17*timonScale), y+(-13*timonScale));
			txLine(x+(17*timonScale), y+(-13*timonScale), x+(25*timonScale), y+(-12*timonScale));
			txLine(x+(25*timonScale), y+(-12*timonScale), x+(29*timonScale), y+(-12*timonScale));
			txLine(x+(29*timonScale), y+(-12*timonScale), x+(38*timonScale), y+(-16*timonScale));
			txLine(x+(38*timonScale), y+(-16*timonScale), x+(40*timonScale), y+(-19*timonScale));

			txSetFillColor(WHITE);
			txFloodFill(x+(15*timonScale), y+(-9*timonScale), BLACK, FLOODFILLBORDER);
			txFloodFill(x+(20*timonScale), y+(-14*timonScale), BLACK, FLOODFILLBORDER);
			}else{
			txSetColor(BLACK);
			txLine(x+(-7*timonScale), y+(-12*timonScale), x+(31*timonScale), y+(-12*timonScale));
			txLine(x+(31*timonScale), y+(-12*timonScale), x+(37*timonScale), y+(-20*timonScale));
		}
    }
	
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Fly
//! @brief   Отрисовка персонажа ,,Вжиг" - герой мультсериала «Чип и Дейл спешат на помощь».
//!
//! @image html Image/Fly.png
//!
//! @param   x   Х-координата точки
//! @param   y 	Y-координата точки
//! @param   flyHand 	Наличие <del>рук</del> лапок у персонажа (0 - Нет рук, 1 - Правая рука, 2 - Левая рука, 3 - Обе руки)
//! @param   flyLeg		Наличие ног у персонажа (0 - Нет ног, 1 - Правая нога, 2 - Левая нога, 3 - Обе ноги) (При отсутствии ног, крылья автоматические исчезают)
//! @param   flyScale	Размер персонажа (1 - Стандартный размер, 2 - В 2 раза больше стандартного размера и т.д.)
//! @param   flyHair	Наличие волос у персонажа (0 - Нет волос, 1 - Есть волос)
//! @param   flyWings	Наличие крыльев у персонажа (0 - Нет крыльев, 1 - Есть крылья)
//! @param   flyEyes	Наличие глаз у персонажа (0 - Нет глаз, 1 - Есть глаза)
//! @param   flyRothColor	Цвет рта персонажа
//! @param   flyShirtColor	Цвет футболки персонажа
//! @param   flySkinColor		Цвет кожи персонажа 
//! @param   flyEyesColor	Цвет глаз персонажа
//!
//! @warning Если цвета разных частей тела совпадают, <del>может произойти ядерный коллапс</del> могут наблюдаться серъёзные графические баги.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @note    Для использования функции нужно создать холст из TXLib.
//!
//! Пример использования функции смотрите в @ref Tutor "примере реализации".
//}----------------------------------------------------------------------------------------------------------------

	void drawFly(int x, int y, int flyHand, int flyLeg, int flyScale, bool flyHair, bool flyWings, bool flyEyes, COLORREF flyRothColor, COLORREF flyShirtColor, COLORREF flySkinColor, COLORREF flyEyesColor)
    {
        //Муха
            if(flyLeg)
            {
                //Ноги
                POINT FlyLegs [35] = {{x+(36*flyScale), y+(239*flyScale)}, {x+(45*flyScale), y+(230*flyScale)}, {x+(51*flyScale), y+(228*flyScale)}, {x+(71*flyScale), y+(228*flyScale)}, {x+(60*flyScale), y+(215*flyScale)}, {x+(53*flyScale), y+(200*flyScale)}, {x+(45*flyScale), y+(173*flyScale)}, {x+(45*flyScale), y+(158*flyScale)}, {x+(68*flyScale), y+(171*flyScale)}, {x+(87*flyScale), y+(178*flyScale)}, {x+(100*flyScale), y+(178*flyScale)}, {x+(117*flyScale), y+(173*flyScale)}, {x+(128*flyScale), y+(166*flyScale)}, {x+(141*flyScale), y+(155*flyScale)}, {x+(141*flyScale), y+(188*flyScale)}, {x+(129*flyScale), y+(206*flyScale)}, {x+(119*flyScale), y+(222*flyScale)}, {x+(113*flyScale), y+(227*flyScale)}, {x+(113*flyScale), y+(230*flyScale)}, {x+(127*flyScale), y+(233*flyScale)}, {x+(136*flyScale), y+(242*flyScale)}, {x+(137*flyScale), y+(246*flyScale)}, {x+(134*flyScale), y+(247*flyScale)}, {x+(118*flyScale), y+(247*flyScale)}, {x+(107*flyScale), y+(241*flyScale)}, {x+(101*flyScale), y+(235*flyScale)}, {x+(103*flyScale), y+(226*flyScale)}, {x+(103*flyScale), y+(208*flyScale)}, {x+(100*flyScale), y+(198*flyScale)}, {x+(84*flyScale), y+(198*flyScale)}, {x+(80*flyScale), y+(210*flyScale)}, {x+(80*flyScale), y+(224*flyScale)}, {x+(82*flyScale), y+(234*flyScale)}, {x+(63*flyScale), y+(242*flyScale)}, {x+(43*flyScale), y+(242*flyScale)}};
                txSetColor(BLACK);
                txSetFillColor(flySkinColor);
                txPolygon(FlyLegs, 35);
            }else{
                flyWings = false;
            }

            //Тело
            POINT FlyBody [32] = {{x+(45*flyScale), y+(158*flyScale)}, {x+(68*flyScale), y+(171*flyScale)}, {x+(87*flyScale), y+(178*flyScale)}, {x+(100*flyScale), y+(178*flyScale)}, {x+(117*flyScale), y+(173*flyScale)}, {x+(128*flyScale), y+(166*flyScale)}, {x+(141*flyScale), y+(155*flyScale)}, {x+(140*flyScale), y+(126*flyScale)}, {x+(138*flyScale), y+(116*flyScale)}, {x+(134*flyScale), y+(97*flyScale)}, {x+(138*flyScale), y+(116*flyScale)}, {x+(151*flyScale), y+(107*flyScale)}, {x+(133*flyScale), y+(85*flyScale)}, {x+(132*flyScale), y+(75*flyScale)}, {x+(127*flyScale), y+(75*flyScale)}, {x+(118*flyScale), y+(82*flyScale)}, {x+(105*flyScale), y+(89*flyScale)}, {x+(92*flyScale), y+(89*flyScale)}, {x+(81*flyScale), y+(85*flyScale)}, {x+(73*flyScale), y+(81*flyScale)}, {x+(65*flyScale), y+(74*flyScale)}, {x+(59*flyScale), y+(73*flyScale)}, {x+(57*flyScale), y+(84*flyScale)}, {x+(50*flyScale), y+(93*flyScale)}, {x+(35*flyScale), y+(104*flyScale)}, {x+(40*flyScale), y+(108*flyScale)}, {x+(52*flyScale), y+(116*flyScale)}, {x+(61*flyScale), y+(97*flyScale)}, {x+(52*flyScale), y+(116*flyScale)}, {x+(48*flyScale), y+(130*flyScale)}, {x+(47*flyScale), y+(138*flyScale)}, {x+(45*flyScale), y+(150*flyScale)}};
            txSetColor(BLACK);
            txSetFillColor(flyShirtColor);
            txPolygon(FlyBody, 32);

            txLine(x+(57*flyScale), y+(83*flyScale), x+(71*flyScale), y+(96*flyScale));
            txLine(x+(71*flyScale), y+(96*flyScale), x+(87*flyScale), y+(104*flyScale));
            txLine(x+(87*flyScale), y+(104*flyScale), x+(104*flyScale), y+(104*flyScale));
            txLine(x+(104*flyScale), y+(104*flyScale), x+(124*flyScale), y+(93*flyScale));
            txLine(x+(124*flyScale), y+(93*flyScale), x+(133*flyScale), y+(85*flyScale));

            txLine(x+(118*flyScale), y+(87*flyScale), x+(132*flyScale), y+(80*flyScale));

            txLine(x+(75*flyScale), y+(89*flyScale), x+(69*flyScale), y+(87*flyScale));
            txLine(x+(69*flyScale), y+(87*flyScale), x+(58*flyScale), y+(77*flyScale));

            if (flyWings)
            {
                //Крылья
                txSetColor(BLACK);
                txLine(x+(80*flyScale), y+(210*flyScale), x+(89*flyScale), y+(213*flyScale));
                txLine(x+(89*flyScale), y+(213*flyScale), x+(99*flyScale), y+(213*flyScale));
                txLine(x+(99*flyScale), y+(213*flyScale), x+(103*flyScale), y+(208*flyScale));

                txLine(x+(92*flyScale), y+(213*flyScale), x+(92*flyScale), y+(211*flyScale));
                txLine(x+(92*flyScale), y+(211*flyScale), x+(97*flyScale), y+(205*flyScale));

                txLine(x+(52*flyScale), y+(195*flyScale), x+(44*flyScale), y+(187*flyScale));
                txLine(x+(44*flyScale), y+(187*flyScale), x+(38*flyScale), y+(174*flyScale));
                txLine(x+(38*flyScale), y+(174*flyScale), x+(39*flyScale), y+(158*flyScale));
                txLine(x+(39*flyScale), y+(158*flyScale), x+(43*flyScale), y+(144*flyScale));
                txLine(x+(43*flyScale), y+(144*flyScale), x+(47*flyScale), y+(138*flyScale));
            }

            if (flyHand == 1)
            {
                //Правая рука
                POINT FlyRightArm [18] = {{x+(40*flyScale), y+(108*flyScale)}, {x+(33*flyScale), y+(114*flyScale)}, {x+(21*flyScale), y+(137*flyScale)}, {x+(16*flyScale), y+(156*flyScale)}, {x+(16*flyScale), y+(174*flyScale)}, {x+(21*flyScale), y+(185*flyScale)}, {x+(27*flyScale), y+(189*flyScale)}, {x+(35*flyScale), y+(189*flyScale)}, {x+(38*flyScale), y+(184*flyScale)}, {x+(38*flyScale), y+(178*flyScale)}, {x+(36*flyScale), y+(175*flyScale)}, {x+(35*flyScale), y+(163*flyScale)}, {x+(31*flyScale), y+(155*flyScale)}, {x+(35*flyScale), y+(147*flyScale)}, {x+(41*flyScale), y+(138*flyScale)}, {x+(47*flyScale), y+(134*flyScale)}, {x+(48*flyScale), y+(130*flyScale)}, {x+(52*flyScale), y+(116*flyScale)}};
                txSetColor(BLACK);
                txSetFillColor(flySkinColor);
                txPolygon(FlyRightArm, 18);

                txLine(x+(36*flyScale), y+(172*flyScale), x+(26*flyScale), y+(166*flyScale));
            }

            if (flyHand == 2)
            {
                //Левая рука
                POINT FlyLeftArm [22] = {{x+(142*flyScale), y+(186*flyScale)}, {x+(149*flyScale), y+(190*flyScale)}, {x+(161*flyScale), y+(179*flyScale)}, {x+(166*flyScale), y+(165*flyScale)}, {x+(167*flyScale), y+(156*flyScale)}, {x+(167*flyScale), y+(146*flyScale)}, {x+(164*flyScale), y+(136*flyScale)}, {x+(157*flyScale), y+(125*flyScale)}, {x+(151*flyScale), y+(117*flyScale)}, {x+(146*flyScale), y+(111*flyScale)}, {x+(138*flyScale), y+(116*flyScale)}, {x+(140*flyScale), y+(126*flyScale)}, {x+(140*flyScale), y+(140*flyScale)}, {x+(151*flyScale), y+(153*flyScale)}, {x+(151*flyScale), y+(156*flyScale)}, {x+(150*flyScale), y+(160*flyScale)}, {x+(144*flyScale), y+(166*flyScale)}, {x+(144*flyScale), y+(169*flyScale)}, {x+(145*flyScale), y+(170*flyScale)}, {x+(146*flyScale), y+(172*flyScale)}, {x+(145*flyScale), y+(177*flyScale)}, {x+(142*flyScale), y+(182*flyScale)}};
                txSetColor(BLACK);
                txSetFillColor(flySkinColor);
                txPolygon(FlyLeftArm, 22);

                txLine(x+(146*flyScale), y+(172*flyScale), x+(150*flyScale), y+(172*flyScale));
                txLine(x+(150*flyScale), y+(172*flyScale), x+(156*flyScale), y+(165*flyScale));

                if (flyWings)
                {
                    txSetFillColor(LIGHTBLUE);
                    txFloodFill(x+(147*flyScale), y+(155*flyScale), BLACK, FLOODFILLBORDER);
                }
            }

            if (flyHand == 3)
            {
                POINT FlyRightArm [18] = {{x+(40*flyScale), y+(108*flyScale)}, {x+(33*flyScale), y+(114*flyScale)}, {x+(21*flyScale), y+(137*flyScale)}, {x+(16*flyScale), y+(156*flyScale)}, {x+(16*flyScale), y+(174*flyScale)}, {x+(21*flyScale), y+(185*flyScale)}, {x+(27*flyScale), y+(189*flyScale)}, {x+(35*flyScale), y+(189*flyScale)}, {x+(38*flyScale), y+(184*flyScale)}, {x+(38*flyScale), y+(178*flyScale)}, {x+(36*flyScale), y+(175*flyScale)}, {x+(35*flyScale), y+(163*flyScale)}, {x+(31*flyScale), y+(155*flyScale)}, {x+(35*flyScale), y+(147*flyScale)}, {x+(41*flyScale), y+(138*flyScale)}, {x+(47*flyScale), y+(134*flyScale)}, {x+(48*flyScale), y+(130*flyScale)}, {x+(52*flyScale), y+(116*flyScale)}};
                txSetColor(BLACK);
                txSetFillColor(flySkinColor);
                txPolygon(FlyRightArm, 18);

                txLine(x+(36*flyScale), y+(172*flyScale), x+(26*flyScale), y+(166*flyScale));

                //Левая рука
                POINT FlyLeftArm [22] = {{x+(142*flyScale), y+(186*flyScale)}, {x+(149*flyScale), y+(190*flyScale)}, {x+(161*flyScale), y+(179*flyScale)}, {x+(166*flyScale), y+(165*flyScale)}, {x+(167*flyScale), y+(156*flyScale)}, {x+(167*flyScale), y+(146*flyScale)}, {x+(164*flyScale), y+(136*flyScale)}, {x+(157*flyScale), y+(125*flyScale)}, {x+(151*flyScale), y+(117*flyScale)}, {x+(146*flyScale), y+(111*flyScale)}, {x+(138*flyScale), y+(116*flyScale)}, {x+(140*flyScale), y+(126*flyScale)}, {x+(140*flyScale), y+(140*flyScale)}, {x+(151*flyScale), y+(153*flyScale)}, {x+(151*flyScale), y+(156*flyScale)}, {x+(150*flyScale), y+(160*flyScale)}, {x+(144*flyScale), y+(166*flyScale)}, {x+(144*flyScale), y+(169*flyScale)}, {x+(145*flyScale), y+(170*flyScale)}, {x+(146*flyScale), y+(172*flyScale)}, {x+(145*flyScale), y+(177*flyScale)}, {x+(142*flyScale), y+(182*flyScale)}};
                txSetColor(BLACK);
                txSetFillColor(flySkinColor);
                txPolygon(FlyLeftArm, 22);

                txLine(x+(146*flyScale), y+(172*flyScale), x+(150*flyScale), y+(172*flyScale));
                txLine(x+(150*flyScale), y+(172*flyScale), x+(156*flyScale), y+(165*flyScale));

                if (flyWings)
                {
                    txSetFillColor(LIGHTBLUE);
                    txFloodFill(x+(147*flyScale), y+(155*flyScale), BLACK, FLOODFILLBORDER);
                }
            }

            //Голова
            POINT FlyHead [72] = {{x+(59*flyScale), y+(73*flyScale)}, {x+(65*flyScale), y+(74*flyScale)}, {x+(73*flyScale), y+(81*flyScale)}, {x+(81*flyScale), y+(85*flyScale)}, {x+(92*flyScale), y+(89*flyScale)}, {x+(105*flyScale), y+(89*flyScale)}, {x+(118*flyScale), y+(82*flyScale)}, {x+(127*flyScale), y+(75*flyScale)}, {x+(132*flyScale), y+(75*flyScale)}, {x+(139*flyScale), y+(74*flyScale)}, {x+(164*flyScale), y+(61*flyScale)}, {x+(182*flyScale), y+(48*flyScale)}, {x+(190*flyScale), y+(39*flyScale)}, {x+(198*flyScale), y+(25*flyScale)}, {x+(199*flyScale), y+(23*flyScale)}, {x+(199*flyScale), y+(5*flyScale)}, {x+(186*flyScale), y+(-4*flyScale)}, {x+(194*flyScale), y+(2*flyScale)}, {x+(193*flyScale), y+(-17*flyScale)}, {x+(191*flyScale), y+(-34*flyScale)}, {x+(188*flyScale), y+(-47*flyScale)}, {x+(185*flyScale), y+(-58*flyScale)}, {x+(180*flyScale), y+(-69*flyScale)}, {x+(171*flyScale), y+(-84*flyScale)}, {x+(163*flyScale), y+(-96*flyScale)}, {x+(152*flyScale), y+(-107*flyScale)}, {x+(142*flyScale), y+(-114*flyScale)}, {x+(133*flyScale), y+(-117*flyScale)}, {x+(114*flyScale), y+(-117*flyScale)}, {x+(109*flyScale), y+(-113*flyScale)}, {x+(105*flyScale), y+(-109*flyScale)}, {x+(102*flyScale), y+(-104*flyScale)}, {x+(100*flyScale), y+(-102*flyScale)}, {x+(99*flyScale), y+(-91*flyScale)}, {x+(100*flyScale), y+(-102*flyScale)}, {x+(98*flyScale), y+(-105*flyScale)}, {x+(92*flyScale), y+(-111*flyScale)}, {x+(88*flyScale), y+(-114*flyScale)}, {x+(83*flyScale), y+(-116*flyScale)}, {x+(76*flyScale), y+(-118*flyScale)}, {x+(75*flyScale), y+(-119*flyScale)}, {x+(70*flyScale), y+(-119*flyScale)}, {x+(65*flyScale), y+(-119*flyScale)}, {x+(60*flyScale), y+(-117*flyScale)}, {x+(57*flyScale), y+(-116*flyScale)}, {x+(57*flyScale), y+(-116*flyScale)}, {x+(52*flyScale), y+(-113*flyScale)}, {x+(47*flyScale), y+(-109*flyScale)}, {x+(35*flyScale), y+(-98*flyScale)}, {x+(26*flyScale), y+(-87*flyScale)}, {x+(21*flyScale), y+(-81*flyScale)}, {x+(13*flyScale), y+(-70*flyScale)}, {x+(8*flyScale), y+(-59*flyScale)}, {x+(4*flyScale), y+(-44*flyScale)}, {x+(1*flyScale), y+(-31*flyScale)}, {x+(0*flyScale), y+(0*flyScale)}, {x+(-6*flyScale), y+(7*flyScale)}, {x+(-9*flyScale), y+(14*flyScale)}, {x+(-10*flyScale), y+(18*flyScale)}, {x+(-10*flyScale), y+(22*flyScale)}, {x+(-7*flyScale), y+(28*flyScale)}, {x+(-4*flyScale), y+(33*flyScale)}, {x+(16*flyScale), y+(53*flyScale)}, {x+(27*flyScale), y+(61*flyScale)}, {x+(37*flyScale), y+(66*flyScale)}, {x+(46*flyScale), y+(69*flyScale)}, {x+(59*flyScale), y+(73*flyScale)}, {x+(65*flyScale), y+(74*flyScale)}, {x+(62*flyScale), y+(70*flyScale)}, {x+(57*flyScale), y+(63*flyScale)}, {x+(62*flyScale), y+(70*flyScale)}, {x+(65*flyScale), y+(74*flyScale)}};
            txSetColor(BLACK);
            txSetFillColor(flySkinColor);
            txPolygon(FlyHead, 72);

            txLine(x+(127*flyScale), y+(75*flyScale), x+(138*flyScale), y+(63*flyScale));

            if (flyHair)
            {
                POINT FlyHair [106] = {{x+(168*flyScale), y+(-140*flyScale)}, {x+(159*flyScale), y+(-137*flyScale)}, {x+(150*flyScale), y+(-132*flyScale)}, {x+(144*flyScale), y+(-124*flyScale)}, {x+(142*flyScale), y+(-114*flyScale)}, {x+(138*flyScale), y+(-116*flyScale)}, {x+(133*flyScale), y+(-117*flyScale)}, {x+(132*flyScale), y+(-121*flyScale)}, {x+(132*flyScale), y+(-127*flyScale)}, {x+(138*flyScale), y+(-135*flyScale)}, {x+(143*flyScale), y+(-139*flyScale)}, {x+(148*flyScale), y+(-141*flyScale)}, {x+(143*flyScale), y+(-139*flyScale)}, {x+(138*flyScale), y+(-135*flyScale)}, {x+(132*flyScale), y+(-127*flyScale)}, {x+(132*flyScale), y+(-124*flyScale)}, {x+(133*flyScale), y+(-117*flyScale)}, {x+(114*flyScale), y+(-117*flyScale)}, {x+(109*flyScale), y+(-113*flyScale)}, {x+(105*flyScale), y+(-109*flyScale)}, {x+(102*flyScale), y+(-104*flyScale)}, {x+(100*flyScale), y+(-102*flyScale)}, {x+(99*flyScale), y+(-91*flyScale)}, {x+(100*flyScale), y+(-102*flyScale)}, {x+(98*flyScale), y+(-105*flyScale)}, {x+(92*flyScale), y+(-111*flyScale)}, {x+(88*flyScale), y+(-114*flyScale)}, {x+(83*flyScale), y+(-116*flyScale)}, {x+(76*flyScale), y+(-118*flyScale)}, {x+(75*flyScale), y+(-119*flyScale)}, {x+(70*flyScale), y+(-119*flyScale)}, {x+(71*flyScale), y+(-121*flyScale)}, {x+(72*flyScale), y+(-131*flyScale)}, {x+(70*flyScale), y+(-138*flyScale)}, {x+(66*flyScale), y+(-143*flyScale)}, {x+(64*flyScale), y+(-146*flyScale)}, {x+(60*flyScale), y+(-150*flyScale)}, {x+(64*flyScale), y+(-146*flyScale)}, {x+(66*flyScale), y+(-143*flyScale)}, {x+(70*flyScale), y+(-138*flyScale)}, {x+(72*flyScale), y+(-131*flyScale)}, {x+(71*flyScale), y+(-121*flyScale)}, {x+(70*flyScale), y+(-119*flyScale)}, {x+(65*flyScale), y+(-119*flyScale)}, {x+(60*flyScale), y+(-117*flyScale)}, {x+(57*flyScale), y+(-116*flyScale)}, {x+(55*flyScale), y+(-123*flyScale)}, {x+(52*flyScale), y+(-128*flyScale)}, {x+(49*flyScale), y+(-133*flyScale)}, {x+(44*flyScale), y+(-138*flyScale)}, {x+(38*flyScale), y+(-141*flyScale)}, {x+(30*flyScale), y+(-144*flyScale)}, {x+(13*flyScale), y+(-147*flyScale)}, {x+(13*flyScale), y+(-147*flyScale)}, {x+(30*flyScale), y+(-144*flyScale)}, {x+(38*flyScale), y+(-141*flyScale)}, {x+(44*flyScale), y+(-138*flyScale)}, {x+(49*flyScale), y+(-133*flyScale)}, {x+(52*flyScale), y+(-128*flyScale)}, {x+(55*flyScale), y+(-123*flyScale)}, {x+(57*flyScale), y+(-116*flyScale)}, {x+(60*flyScale), y+(-117*flyScale)}, {x+(65*flyScale), y+(-119*flyScale)}, {x+(70*flyScale), y+(-119*flyScale)}, {x+(71*flyScale), y+(-121*flyScale)}, {x+(72*flyScale), y+(-131*flyScale)}, {x+(70*flyScale), y+(-138*flyScale)}, {x+(66*flyScale), y+(-143*flyScale)}, {x+(64*flyScale), y+(-146*flyScale)}, {x+(60*flyScale), y+(-150*flyScale)}, {x+(64*flyScale), y+(-146*flyScale)}, {x+(66*flyScale), y+(-143*flyScale)}, {x+(70*flyScale), y+(-138*flyScale)}, {x+(72*flyScale), y+(-131*flyScale)}, {x+(71*flyScale), y+(-121*flyScale)}, {x+(70*flyScale), y+(-119*flyScale)}, {x+(75*flyScale), y+(-119*flyScale)}, {x+(76*flyScale), y+(-118*flyScale)}, {x+(83*flyScale), y+(-116*flyScale)}, {x+(88*flyScale), y+(-114*flyScale)}, {x+(92*flyScale), y+(-111*flyScale)}, {x+(98*flyScale), y+(-105*flyScale)}, {x+(100*flyScale), y+(-102*flyScale)}, {x+(99*flyScale), y+(-91*flyScale)}, {x+(100*flyScale), y+(-102*flyScale)}, {x+(102*flyScale), y+(-104*flyScale)}, {x+(105*flyScale), y+(-109*flyScale)}, {x+(109*flyScale), y+(-113*flyScale)}, {x+(114*flyScale), y+(-117*flyScale)}, {x+(133*flyScale), y+(-117*flyScale)}, {x+(132*flyScale), y+(-124*flyScale)}, {x+(132*flyScale), y+(-127*flyScale)}, {x+(138*flyScale), y+(-135*flyScale)}, {x+(143*flyScale), y+(-139*flyScale)}, {x+(148*flyScale), y+(-141*flyScale)}, {x+(143*flyScale), y+(-139*flyScale)}, {x+(138*flyScale), y+(-135*flyScale)}, {x+(132*flyScale), y+(-127*flyScale)}, {x+(132*flyScale), y+(-121*flyScale)}, {x+(133*flyScale), y+(-117*flyScale)}, {x+(138*flyScale), y+(-116*flyScale)}, {x+(142*flyScale), y+(-114*flyScale)}, {x+(144*flyScale), y+(-124*flyScale)}, {x+(150*flyScale), y+(-132*flyScale)}, {x+(159*flyScale), y+(-137*flyScale)}, {x+(168*flyScale), y+(-140*flyScale)}, };
                txSetColor(BLACK);
                txPolygon(FlyHair, 106);
            }

            txLine(x+(0*flyScale), y+(0*flyScale), x+(10*flyScale), y+(-1*flyScale));

            if (flyEyes)
            {
                txSetColor(BLACK);
                txSetFillColor(BLACK);
                txCircle(x+(84*flyScale), y+(6*flyScale), 9*flyScale);
                txCircle(x+(111*flyScale), y+(5*flyScale), 10*flyScale);
            }else{
                txSetColor(BLACK, 2);
                txLine(x+(75*flyScale), y+(4*flyScale), x+(92*flyScale), y+(4*flyScale));
                txLine(x+(101*flyScale), y+(2*flyScale), x+(120*flyScale), y+(2*flyScale));
            }

            //Нос
            POINT FlyNose [20] = {{x+(69*flyScale), y+(27*flyScale)}, {x+(74*flyScale), y+(20*flyScale)}, {x+(79*flyScale), y+(16*flyScale)}, {x+(81*flyScale), y+(14*flyScale)}, {x+(91*flyScale), y+(11*flyScale)}, {x+(103*flyScale), y+(11*flyScale)}, {x+(113*flyScale), y+(15*flyScale)}, {x+(121*flyScale), y+(22*flyScale)}, {x+(125*flyScale), y+(27*flyScale)}, {x+(124*flyScale), y+(31*flyScale)}, {x+(121*flyScale), y+(36*flyScale)}, {x+(114*flyScale), y+(44*flyScale)}, {x+(105*flyScale), y+(48*flyScale)}, {x+(95*flyScale), y+(48*flyScale)}, {x+(89*flyScale), y+(47*flyScale)}, {x+(83*flyScale), y+(46*flyScale)}, {x+(79*flyScale), y+(44*flyScale)}, {x+(75*flyScale), y+(40*flyScale)}, {x+(72*flyScale), y+(35*flyScale)}, {x+(69*flyScale), y+(27*flyScale)}};
            txSetColor(BLACK);
            txSetFillColor(BLACK);
            txPolygon(FlyNose, 20);

            //Глаза
            txSetColor(BLACK);
            txLine(x+(69*flyScale), y+(28*flyScale), x+(57*flyScale), y+(28*flyScale));
            txLine(x+(57*flyScale), y+(28*flyScale), x+(51*flyScale), y+(27*flyScale));
            txLine(x+(51*flyScale), y+(27*flyScale), x+(42*flyScale), y+(25*flyScale));
            txLine(x+(42*flyScale), y+(25*flyScale), x+(34*flyScale), y+(22*flyScale));
            txLine(x+(34*flyScale), y+(22*flyScale), x+(28*flyScale), y+(18*flyScale));
            txLine(x+(28*flyScale), y+(18*flyScale), x+(22*flyScale), y+(12*flyScale));
            txLine(x+(22*flyScale), y+(12*flyScale), x+(17*flyScale), y+(3*flyScale));
            txLine(x+(17*flyScale), y+(3*flyScale), x+(13*flyScale), y+(-9*flyScale));
            txLine(x+(13*flyScale), y+(-9*flyScale), x+(10*flyScale), y+(-19*flyScale));
            txLine(x+(10*flyScale), y+(-19*flyScale), x+(10*flyScale), y+(-39*flyScale));
            txLine(x+(10*flyScale), y+(-39*flyScale), x+(13*flyScale), y+(-53*flyScale));
            txLine(x+(13*flyScale), y+(-53*flyScale), x+(17*flyScale), y+(-63*flyScale));
            txLine(x+(17*flyScale), y+(-63*flyScale), x+(20*flyScale), y+(-70*flyScale));
            txLine(x+(20*flyScale), y+(-70*flyScale), x+(24*flyScale), y+(-79*flyScale));
            txLine(x+(24*flyScale), y+(-79*flyScale), x+(28*flyScale), y+(-86*flyScale));
            txLine(x+(28*flyScale), y+(-86*flyScale), x+(35*flyScale), y+(-98*flyScale));

            txLine(x+(169*flyScale), y+(-87*flyScale), x+(177*flyScale), y+(-62*flyScale));
            txLine(x+(177*flyScale), y+(-62*flyScale), x+(182*flyScale), y+(-40*flyScale));
            txLine(x+(182*flyScale), y+(-40*flyScale), x+(182*flyScale), y+(-8*flyScale));
            txLine(x+(182*flyScale), y+(-8*flyScale), x+(177*flyScale), y+(4*flyScale));
            txLine(x+(177*flyScale), y+(4*flyScale), x+(173*flyScale), y+(14*flyScale));
            txLine(x+(173*flyScale), y+(14*flyScale), x+(165*flyScale), y+(21*flyScale));
            txLine(x+(165*flyScale), y+(21*flyScale), x+(155*flyScale), y+(27*flyScale));
            txLine(x+(155*flyScale), y+(27*flyScale), x+(125*flyScale), y+(27*flyScale));

            txSetFillColor(flyEyesColor);
            txFloodFill(x+(130*flyScale), y+(17*flyScale), BLACK, FLOODFILLBORDER);

            //Рот
            txSetColor(BLACK);
            txLine(x+(163*flyScale), y+(29*flyScale), x+(170*flyScale), y+(23*flyScale));
            txLine(x+(170*flyScale), y+(23*flyScale), x+(176*flyScale), y+(20*flyScale));
            txLine(x+(176*flyScale), y+(20*flyScale), x+(183*flyScale), y+(20*flyScale));

            txLine(x+(171*flyScale), y+(22*flyScale), x+(171*flyScale), y+(25*flyScale));
            txLine(x+(171*flyScale), y+(25*flyScale), x+(156*flyScale), y+(42*flyScale));
            txLine(x+(156*flyScale), y+(42*flyScale), x+(143*flyScale), y+(52*flyScale));

            txLine(x+(7*flyScale), y+(19*flyScale), x+(33*flyScale), y+(24*flyScale));

            txLine(x+(20*flyScale), y+(21*flyScale), x+(23*flyScale), y+(30*flyScale));
            txLine(x+(23*flyScale), y+(30*flyScale), x+(35*flyScale), y+(42*flyScale));
            txLine(x+(35*flyScale), y+(42*flyScale), x+(47*flyScale), y+(49*flyScale));
            txLine(x+(47*flyScale), y+(49*flyScale), x+(62*flyScale), y+(55*flyScale));

            POINT FlyRoth [11] = {{x+(62*flyScale), y+(55*flyScale)}, {x+(79*flyScale), y+(58*flyScale)}, {x+(126*flyScale), y+(58*flyScale)}, {x+(136*flyScale), y+(55*flyScale)}, {x+(143*flyScale), y+(52*flyScale)}, {x+(143*flyScale), y+(53*flyScale)}, {x+(118*flyScale), y+(76*flyScale)}, {x+(108*flyScale), y+(81*flyScale)}, {x+(93*flyScale), y+(81*flyScale)}, {x+(82*flyScale), y+(76*flyScale)}, {x+(62*flyScale), y+(58*flyScale)}};
            txSetColor(BLACK);
            txSetFillColor(flyRothColor);
            txPolygon(FlyRoth, 11);

            if (flyWings)
            {
                txSetFillColor(LIGHTBLUE);
                txFloodFill(x+(43*flyScale), y+(175*flyScale), BLACK, FLOODFILLBORDER);
                txFloodFill(x+(91*flyScale), y+(205*flyScale), BLACK, FLOODFILLBORDER);
            }
    }

	
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Pig
//! @brief   Отрисовка персонажа ,,Пятачок" - герой мультфильма «Винни-Пух».
//!
//! @image html Image/Pig.png
//!
//! @param   x   Х-координата точки
//! @param   y 	Y-координата точки
//! @param   pigEar 	Наличие ушей у персонажа (0 - Нет ушей, 1 - Правое ухо, 2 - Левое ухо, 3 - Оба уха)
//! @param   pigHand	Наличие <del>рук</del> лапок у персонажа (0 - Нет рук, 1 - Правая рука, 2 - Левая рука, 3 - Обе руки)
//! @param   pigScale	Размер персонажа (1 - Стандартный размер, 2 - В 2 раза больше стандартного размера и т.д.)
//! @param   pigEyes	Наличие глаз у персонажа (0 - Нет глаз, 1 - Есть глаза)
//! @param   pigLeg	Наличие <del>я в душе не знаю, что там у свиней: ноги, лапы, копыта</del> ног у персонажа (0 - Нет ног, 1 - Правая нога, 2 - Левая нога, 3 - Обе ноги)
//! @param   pigLeftArm Наличие левой руки (0 - Нет левой руки, 1 - Есть левая рука) (Изминение наличия правой руки отсутствует)
//! @param   pigRoth	Наличие рта у персонажа (0 - Нет рта, 1 - Есть рот)
//! @param   pigEarColor		Цвет ушей персонажа
//! @param   pigNoseColor 	Цвет <del>носа</del> пятачка персонажа
//! @param   pigShirtColor	Цвет футболки персонажа
//! @param   pigSkinColor	Цвет кожи персонажа
//!
//! @warning Если цвета разных частей тела совпадают, <del>может произойти ядерный коллапс</del> могут наблюдаться серъёзные графические баги.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @note    Для использования функции нужно создать холст из TXLib.
//!
//! Пример использования функции смотрите в @ref Tutor "примере реализации".
//}----------------------------------------------------------------------------------------------------------------
	
	void drawPig(int x, int y, int pigEar, int pigHand, int pigScale, bool pigEyes, bool pigLeg, bool pigLeftArm,  bool pigRoth, COLORREF pigEarColor, COLORREF pigNoseColor, COLORREF pigShirtColor, COLORREF pigSkinColor)
    {
        //Хрюня
            //Голова
            POINT PigHead [40] = {{x+(-210*pigScale), y+(-170*pigScale)}, {x+(-206*pigScale), y+(-188*pigScale)}, {x+(-202*pigScale), y+(-197*pigScale)}, {x+(-199*pigScale), y+(-202*pigScale)}, {x+(-196*pigScale), y+(-207*pigScale)}, {x+(-190*pigScale), y+(-211*pigScale)}, {x+(-180*pigScale), y+(-217*pigScale)}, {x+(-172*pigScale), y+(-219*pigScale)}, {x+(-159*pigScale), y+(-220*pigScale)}, {x+(-149*pigScale), y+(-218*pigScale)}, {x+(-140*pigScale), y+(-217*pigScale)}, {x+(-132*pigScale), y+(-216*pigScale)}, {x+(-126*pigScale), y+(-213*pigScale)}, {x+(-122*pigScale), y+(-210*pigScale)}, {x+(-117*pigScale), y+(-204*pigScale)}, {x+(-117*pigScale), y+(-204*pigScale)}, {x+(-112*pigScale), y+(-196*pigScale)}, {x+(-110*pigScale), y+(-188*pigScale)}, {x+(-109*pigScale), y+(-187*pigScale)}, {x+(-106*pigScale), y+(-156*pigScale)}, {x+(-110*pigScale), y+(-139*pigScale)}, {x+(-114*pigScale), y+(-125*pigScale)}, {x+(-118*pigScale), y+(-115*pigScale)}, {x+(-118*pigScale), y+(-91*pigScale)}, {x+(-121*pigScale), y+(-81*pigScale)}, {x+(-126*pigScale), y+(-75*pigScale)}, {x+(-131*pigScale), y+(-67*pigScale)}, {x+(-151*pigScale), y+(-53*pigScale)}, {x+(-152*pigScale), y+(-52*pigScale)}, {x+(-173*pigScale), y+(-51*pigScale)}, {x+(-181*pigScale), y+(-58*pigScale)}, {x+(-195*pigScale), y+(-71*pigScale)}, {x+(-214*pigScale), y+(-89*pigScale)}, {x+(-234*pigScale), y+(-112*pigScale)}, {x+(-236*pigScale), y+(-119*pigScale)}, {x+(-240*pigScale), y+(-127*pigScale)}, {x+(-240*pigScale), y+(-150*pigScale)}, {x+(-235*pigScale), y+(-158*pigScale)}, {x+(-231*pigScale), y+(-164*pigScale)}, {x+(-220*pigScale), y+(-167*pigScale)}};
            txSetColor(BLACK);
            txSetFillColor(pigSkinColor);
            txPolygon(PigHead, 40);

            if (pigEar == 1)
            {
                //Правое ухо
                POINT PigRightEar [22] = {{x+(-233*pigScale), y+(-199*pigScale)}, {x+(-236*pigScale), y+(-212*pigScale)}, {x+(-245*pigScale), y+(-224*pigScale)}, {x+(-245*pigScale), y+(-236*pigScale)}, {x+(-236*pigScale), y+(-243*pigScale)}, {x+(-230*pigScale), y+(-248*pigScale)}, {x+(-223*pigScale), y+(-261*pigScale)}, {x+(-208*pigScale), y+(-285*pigScale)}, {x+(-197*pigScale), y+(-285*pigScale)}, {x+(-179*pigScale), y+(-270*pigScale)}, {x+(-171*pigScale), y+(-258*pigScale)}, {x+(-165*pigScale), y+(-248*pigScale)}, {x+(-159*pigScale), y+(-220*pigScale)}, {x+(-172*pigScale), y+(-219*pigScale)}, {x+(-180*pigScale), y+(-217*pigScale)}, {x+(-190*pigScale), y+(-211*pigScale)}, {x+(-196*pigScale), y+(-207*pigScale)}, {x+(-199*pigScale), y+(-202*pigScale)}, {x+(-202*pigScale), y+(-202*pigScale)}, {x+(-217*pigScale), y+(-209*pigScale)}, {x+(-222*pigScale), y+(-203*pigScale)}, {x+(-225*pigScale), y+(-199*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigEarColor);
                txPolygon(PigRightEar, 22);

                txSetColor(BLACK);
                txLine(x+(-217*pigScale), y+(-209*pigScale), x+(-213*pigScale), y+(-215*pigScale));
                txLine(x+(-213*pigScale), y+(-215*pigScale), x+(-210*pigScale), y+(-225*pigScale));
                txLine(x+(-210*pigScale), y+(-225*pigScale), x+(-207*pigScale), y+(-232*pigScale));
                txLine(x+(-207*pigScale), y+(-232*pigScale), x+(-207*pigScale), y+(-269*pigScale));
                txLine(x+(-207*pigScale), y+(-269*pigScale), x+(-206*pigScale), y+(-270*pigScale));
            }

            if (pigEar == 2)
            {
                //Левое ухо
                POINT PigLeftEar [23] = {{x+(-140*pigScale), y+(-217*pigScale)}, {x+(-140*pigScale), y+(-244*pigScale)}, {x+(-133*pigScale), y+(-262*pigScale)}, {x+(-125*pigScale), y+(-273*pigScale)}, {x+(-111*pigScale), y+(-288*pigScale)}, {x+(-100*pigScale), y+(-301*pigScale)}, {x+(-94*pigScale), y+(-309*pigScale)}, {x+(-89*pigScale), y+(-325*pigScale)}, {x+(-72*pigScale), y+(-308*pigScale)}, {x+(-61*pigScale), y+(-284*pigScale)}, {x+(-58*pigScale), y+(-268*pigScale)}, {x+(-58*pigScale), y+(-238*pigScale)}, {x+(-64*pigScale), y+(-227*pigScale)}, {x+(-58*pigScale), y+(-238*pigScale)}, {x+(-64*pigScale), y+(-227*pigScale)}, {x+(-70*pigScale), y+(-214*pigScale)}, {x+(-84*pigScale), y+(-202*pigScale)}, {x+(-92*pigScale), y+(-197*pigScale)}, {x+(-109*pigScale), y+(-189*pigScale)}, {x+(-110*pigScale), y+(-188*pigScale)}, {x+(-121*pigScale), y+(-188*pigScale)}, {x+(-134*pigScale), y+(-204*pigScale)}, {x+(-138*pigScale), y+(-210*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigEarColor);
                txPolygon(PigLeftEar, 21);
            }

            if (pigEar == 3)
            {
                //Правое ухо
                POINT PigRightEar [22] = {{x+(-233*pigScale), y+(-199*pigScale)}, {x+(-236*pigScale), y+(-212*pigScale)}, {x+(-245*pigScale), y+(-224*pigScale)}, {x+(-245*pigScale), y+(-236*pigScale)}, {x+(-236*pigScale), y+(-243*pigScale)}, {x+(-230*pigScale), y+(-248*pigScale)}, {x+(-223*pigScale), y+(-261*pigScale)}, {x+(-208*pigScale), y+(-285*pigScale)}, {x+(-197*pigScale), y+(-285*pigScale)}, {x+(-179*pigScale), y+(-270*pigScale)}, {x+(-171*pigScale), y+(-258*pigScale)}, {x+(-165*pigScale), y+(-248*pigScale)}, {x+(-159*pigScale), y+(-220*pigScale)}, {x+(-172*pigScale), y+(-219*pigScale)}, {x+(-180*pigScale), y+(-217*pigScale)}, {x+(-190*pigScale), y+(-211*pigScale)}, {x+(-196*pigScale), y+(-207*pigScale)}, {x+(-199*pigScale), y+(-202*pigScale)}, {x+(-202*pigScale), y+(-202*pigScale)}, {x+(-217*pigScale), y+(-209*pigScale)}, {x+(-222*pigScale), y+(-203*pigScale)}, {x+(-225*pigScale), y+(-199*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigEarColor);
                txPolygon(PigRightEar, 22);

                txSetColor(BLACK);
                txLine(x+(-217*pigScale), y+(-209*pigScale), x+(-213*pigScale), y+(-215*pigScale));
                txLine(x+(-213*pigScale), y+(-215*pigScale), x+(-210*pigScale), y+(-225*pigScale));
                txLine(x+(-210*pigScale), y+(-225*pigScale), x+(-207*pigScale), y+(-232*pigScale));
                txLine(x+(-207*pigScale), y+(-232*pigScale), x+(-207*pigScale), y+(-269*pigScale));
                txLine(x+(-207*pigScale), y+(-269*pigScale), x+(-206*pigScale), y+(-270*pigScale));

                //Левое ухо
                POINT PigLeftEar [23] = {{x+(-140*pigScale), y+(-217*pigScale)}, {x+(-140*pigScale), y+(-244*pigScale)}, {x+(-133*pigScale), y+(-262*pigScale)}, {x+(-125*pigScale), y+(-273*pigScale)}, {x+(-111*pigScale), y+(-288*pigScale)}, {x+(-100*pigScale), y+(-301*pigScale)}, {x+(-94*pigScale), y+(-309*pigScale)}, {x+(-89*pigScale), y+(-325*pigScale)}, {x+(-72*pigScale), y+(-308*pigScale)}, {x+(-61*pigScale), y+(-284*pigScale)}, {x+(-58*pigScale), y+(-268*pigScale)}, {x+(-58*pigScale), y+(-238*pigScale)}, {x+(-64*pigScale), y+(-227*pigScale)}, {x+(-58*pigScale), y+(-238*pigScale)}, {x+(-64*pigScale), y+(-227*pigScale)}, {x+(-70*pigScale), y+(-214*pigScale)}, {x+(-84*pigScale), y+(-202*pigScale)}, {x+(-92*pigScale), y+(-197*pigScale)}, {x+(-109*pigScale), y+(-189*pigScale)}, {x+(-110*pigScale), y+(-188*pigScale)}, {x+(-121*pigScale), y+(-188*pigScale)}, {x+(-134*pigScale), y+(-204*pigScale)}, {x+(-138*pigScale), y+(-210*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigEarColor);
                txPolygon(PigLeftEar, 21);
            }

            if (pigHand == 1)
            {
                //Правая рука
                POINT PigRightHand [28] = {{x+(-234*pigScale), y+(-112*pigScale)}, {x+(-226*pigScale), y+(-111*pigScale)}, {x+(-219*pigScale), y+(-109*pigScale)}, {x+(-214*pigScale), y+(-103*pigScale)}, {x+(-214*pigScale), y+(-89*pigScale)}, {x+(-205*pigScale), y+(-80*pigScale)}, {x+(-205*pigScale), y+(-76*pigScale)}, {x+(-197*pigScale), y+(-58*pigScale)}, {x+(-193*pigScale), y+(-49*pigScale)}, {x+(-191*pigScale), y+(-49*pigScale)}, {x+(-188*pigScale), y+(-54*pigScale)}, {x+(-185*pigScale), y+(-57*pigScale)}, {x+(-185*pigScale), y+(-60*pigScale)}, {x+(-173*pigScale), y+(-51*pigScale)}, {x+(-154*pigScale), y+(-39*pigScale)}, {x+(-169*pigScale), y+(-21*pigScale)}, {x+(-184*pigScale), y+(-13*pigScale)}, {x+(-207*pigScale), y+(-13*pigScale)}, {x+(-214*pigScale), y+(-18*pigScale)}, {x+(-217*pigScale), y+(-22*pigScale)}, {x+(-220*pigScale), y+(-36*pigScale)}, {x+(-223*pigScale), y+(-49*pigScale)}, {x+(-226*pigScale), y+(-63*pigScale)}, {x+(-228*pigScale), y+(-68*pigScale)}, {x+(-227*pigScale), y+(-77*pigScale)}, {x+(-233*pigScale), y+(-83*pigScale)}, {x+(-237*pigScale), y+(-87*pigScale)}, {x+(-237*pigScale), y+(-105*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigSkinColor);
                txPolygon(PigRightHand, 28);

                //Рукав
                POINT PigSleeve [10] = {{x+(-116*pigScale), y+(-40*pigScale)}, {x+(-120*pigScale), y+(-45*pigScale)}, {x+(-120*pigScale), y+(-64*pigScale)}, {x+(-113*pigScale), y+(-73*pigScale)}, {x+(-111*pigScale), y+(-75*pigScale)}, {x+(-102*pigScale), y+(-75*pigScale)}, {x+(-91*pigScale), y+(-63*pigScale)}, {x+(-89*pigScale), y+(-59*pigScale)}, {x+(-85*pigScale), y+(-45*pigScale)}, {x+(-89*pigScale), y+(-40*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigSkinColor);
                txPolygon(PigSleeve, 10);
            }

            if (pigHand == 3)
            {
                //Правая рука
                POINT PigRightHand [28] = {{x+(-234*pigScale), y+(-112*pigScale)}, {x+(-226*pigScale), y+(-111*pigScale)}, {x+(-219*pigScale), y+(-109*pigScale)}, {x+(-214*pigScale), y+(-103*pigScale)}, {x+(-214*pigScale), y+(-89*pigScale)}, {x+(-205*pigScale), y+(-80*pigScale)}, {x+(-205*pigScale), y+(-76*pigScale)}, {x+(-197*pigScale), y+(-58*pigScale)}, {x+(-193*pigScale), y+(-49*pigScale)}, {x+(-191*pigScale), y+(-49*pigScale)}, {x+(-188*pigScale), y+(-54*pigScale)}, {x+(-185*pigScale), y+(-57*pigScale)}, {x+(-185*pigScale), y+(-60*pigScale)}, {x+(-173*pigScale), y+(-51*pigScale)}, {x+(-154*pigScale), y+(-39*pigScale)}, {x+(-169*pigScale), y+(-21*pigScale)}, {x+(-184*pigScale), y+(-13*pigScale)}, {x+(-207*pigScale), y+(-13*pigScale)}, {x+(-214*pigScale), y+(-18*pigScale)}, {x+(-217*pigScale), y+(-22*pigScale)}, {x+(-220*pigScale), y+(-36*pigScale)}, {x+(-223*pigScale), y+(-49*pigScale)}, {x+(-226*pigScale), y+(-63*pigScale)}, {x+(-228*pigScale), y+(-68*pigScale)}, {x+(-227*pigScale), y+(-77*pigScale)}, {x+(-233*pigScale), y+(-83*pigScale)}, {x+(-237*pigScale), y+(-87*pigScale)}, {x+(-237*pigScale), y+(-105*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigSkinColor);
                txPolygon(PigRightHand, 28);
            }

            //Тело
            POINT PigBody [33] = {{x+(-173*pigScale), y+(-51*pigScale)}, {x+(-154*pigScale), y+(-31*pigScale)}, {x+(-145*pigScale), y+(-24*pigScale)}, {x+(-124*pigScale), y+(-9*pigScale)}, {x+(-84*pigScale), y+(1*pigScale)}, {x+(-42*pigScale), y+(1*pigScale)}, {x+(-41*pigScale), y+(0*pigScale)}, {x+(0*pigScale), y+(0*pigScale)}, {x+(33*pigScale), y+(-9*pigScale)}, {x+(44*pigScale), y+(-17*pigScale)}, {x+(56*pigScale), y+(-26*pigScale)}, {x+(60*pigScale), y+(-34*pigScale)}, {x+(63*pigScale), y+(-45*pigScale)}, {x+(63*pigScale), y+(-77*pigScale)}, {x+(56*pigScale), y+(-94*pigScale)}, {x+(46*pigScale), y+(-105*pigScale)}, {x+(31*pigScale), y+(-115*pigScale)}, {x+(20*pigScale), y+(-122*pigScale)}, {x+(-6*pigScale), y+(-122*pigScale)}, {x+(-31*pigScale), y+(-115*pigScale)}, {x+(-43*pigScale), y+(-109*pigScale)}, {x+(-57*pigScale), y+(-101*pigScale)}, {x+(-78*pigScale), y+(-93*pigScale)}, {x+(-79*pigScale), y+(-92*pigScale)}, {x+(-101*pigScale), y+(-92*pigScale)}, {x+(-116*pigScale), y+(-102*pigScale)}, {x+(-118*pigScale), y+(-102*pigScale)}, {x+(-118*pigScale), y+(-91*pigScale)}, {x+(-121*pigScale), y+(-81*pigScale)}, {x+(-126*pigScale), y+(-75*pigScale)}, {x+(-131*pigScale), y+(-67*pigScale)}, {x+(-151*pigScale), y+(-53*pigScale)}, {x+(-152*pigScale), y+(-52*pigScale)}, };
            txSetColor(BLACK);
            txSetFillColor(pigShirtColor);
            txPolygon(PigBody, 33);

            //Полоски
            txSetColor(BLACK);
            txLine(x+(-152*pigScale), y+(-30*pigScale), x+(-135*pigScale), y+(-31*pigScale));
            txLine(x+(-135*pigScale), y+(-31*pigScale), x+(-120*pigScale), y+(-39*pigScale));

            txLine(x+(-83*pigScale), y+(-92*pigScale), x+(-78*pigScale), y+(-77*pigScale));
            txLine(x+(-78*pigScale), y+(-77*pigScale), x+(-78*pigScale), y+(-47*pigScale));
            txLine(x+(-78*pigScale), y+(-47*pigScale), x+(-85*pigScale), y+(-36*pigScale));

            txLine(x+(-66*pigScale), y+(-97*pigScale), x+(-56*pigScale), y+(-75*pigScale));
            txLine(x+(-56*pigScale), y+(-75*pigScale), x+(-54*pigScale), y+(-53*pigScale));
            txLine(x+(-54*pigScale), y+(-53*pigScale), x+(-54*pigScale), y+(-39*pigScale));
            txLine(x+(-54*pigScale), y+(-39*pigScale), x+(-61*pigScale), y+(-18*pigScale));
            txLine(x+(-61*pigScale), y+(-18*pigScale), x+(-72*pigScale), y+(1*pigScale));

            txLine(x+(-47*pigScale), y+(-106*pigScale), x+(-26*pigScale), y+(-85*pigScale));
            txLine(x+(-26*pigScale), y+(-85*pigScale), x+(-20*pigScale), y+(-62*pigScale));
            txLine(x+(-20*pigScale), y+(-62*pigScale), x+(-20*pigScale), y+(-27*pigScale));
            txLine(x+(-20*pigScale), y+(-27*pigScale), x+(-33*pigScale), y+(0*pigScale));

            txLine(x+(-24*pigScale), y+(-117*pigScale), x+(1*pigScale), y+(-94*pigScale));
            txLine(x+(1*pigScale), y+(-94*pigScale), x+(13*pigScale), y+(-65*pigScale));
            txLine(x+(13*pigScale), y+(-65*pigScale), x+(13*pigScale), y+(-46*pigScale));
            txLine(x+(13*pigScale), y+(-46*pigScale), x+(12*pigScale), y+(-29*pigScale));
            txLine(x+(12*pigScale), y+(-29*pigScale), x+(-2*pigScale), y+(0*pigScale));

            txLine(x+(9*pigScale), y+(-122*pigScale), x+(34*pigScale), y+(-98*pigScale));
            txLine(x+(34*pigScale), y+(-98*pigScale), x+(45*pigScale), y+(-69*pigScale));
            txLine(x+(45*pigScale), y+(-69*pigScale), x+(45*pigScale), y+(-37*pigScale));
            txLine(x+(45*pigScale), y+(-37*pigScale), x+(33*pigScale), y+(-9*pigScale));

            if (pigHand == 0)
            {
                //Рукав
                POINT PigSleeve [10] = {{x+(-116*pigScale), y+(-40*pigScale)}, {x+(-120*pigScale), y+(-45*pigScale)}, {x+(-120*pigScale), y+(-64*pigScale)}, {x+(-113*pigScale), y+(-73*pigScale)}, {x+(-111*pigScale), y+(-75*pigScale)}, {x+(-102*pigScale), y+(-75*pigScale)}, {x+(-91*pigScale), y+(-63*pigScale)}, {x+(-89*pigScale), y+(-59*pigScale)}, {x+(-85*pigScale), y+(-45*pigScale)}, {x+(-89*pigScale), y+(-40*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigSkinColor);
                txPolygon(PigSleeve, 10);
            }

            if (pigHand == 2)
            {
                //Левая рука
                POINT PigLeftArm [25] = {{x+(-194*pigScale), y+(7*pigScale)}, {x+(-180*pigScale), y+(4*pigScale)}, {x+(-161*pigScale), y+(3*pigScale)}, {x+(-141*pigScale), y+(-1*pigScale)}, {x+(-132*pigScale), y+(-3*pigScale)}, {x+(-124*pigScale), y+(-9*pigScale)}, {x+(-122*pigScale), y+(-9*pigScale)}, {x+(-121*pigScale), y+(-31*pigScale)}, {x+(-120*pigScale), y+(-64*pigScale)}, {x+(-113*pigScale), y+(-73*pigScale)}, {x+(-111*pigScale), y+(-75*pigScale)}, {x+(-102*pigScale), y+(-75*pigScale)}, {x+(-91*pigScale), y+(-63*pigScale)}, {x+(-89*pigScale), y+(-59*pigScale)}, {x+(-85*pigScale), y+(-40*pigScale)}, {x+(-85*pigScale), y+(2*pigScale)}, {x+(-93*pigScale), y+(17*pigScale)}, {x+(-105*pigScale), y+(25*pigScale)}, {x+(-126*pigScale), y+(30*pigScale)}, {x+(-140*pigScale), y+(32*pigScale)}, {x+(-174*pigScale), y+(32*pigScale)}, {x+(-182*pigScale), y+(31*pigScale)}, {x+(-184*pigScale), y+(28*pigScale)}, {x+(-189*pigScale), y+(24*pigScale)}, {x+(-194*pigScale), y+(20*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigSkinColor);
                txPolygon(PigLeftArm, 25);
            }

            if (pigHand == 3)
            {
                if(pigLeftArm==1)
                {
                    //Левая рука
                    POINT PigLeftArm [25] = {{x+(-194*pigScale), y+(7*pigScale)}, {x+(-180*pigScale), y+(4*pigScale)}, {x+(-161*pigScale), y+(3*pigScale)}, {x+(-141*pigScale), y+(-1*pigScale)}, {x+(-132*pigScale), y+(-3*pigScale)}, {x+(-124*pigScale), y+(-9*pigScale)}, {x+(-122*pigScale), y+(-9*pigScale)}, {x+(-121*pigScale), y+(-31*pigScale)}, {x+(-120*pigScale), y+(-64*pigScale)}, {x+(-113*pigScale), y+(-73*pigScale)}, {x+(-111*pigScale), y+(-75*pigScale)}, {x+(-102*pigScale), y+(-75*pigScale)}, {x+(-91*pigScale), y+(-63*pigScale)}, {x+(-89*pigScale), y+(-59*pigScale)}, {x+(-85*pigScale), y+(-40*pigScale)}, {x+(-85*pigScale), y+(2*pigScale)}, {x+(-93*pigScale), y+(17*pigScale)}, {x+(-105*pigScale), y+(25*pigScale)}, {x+(-126*pigScale), y+(30*pigScale)}, {x+(-140*pigScale), y+(32*pigScale)}, {x+(-174*pigScale), y+(32*pigScale)}, {x+(-182*pigScale), y+(31*pigScale)}, {x+(-184*pigScale), y+(28*pigScale)}, {x+(-189*pigScale), y+(24*pigScale)}, {x+(-194*pigScale), y+(20*pigScale)}, };
                    txSetColor(BLACK);
                    txSetFillColor(pigSkinColor);
                    txPolygon(PigLeftArm, 25);
                }else{
                    POINT PigLeftArm [25] = {{x+(-192*pigScale), y+(4*pigScale)}, {x+(-180*pigScale), y+(0*pigScale)}, {x+(-157*pigScale), y+(-1*pigScale)}, {x+(-151*pigScale), y+(-3*pigScale)}, {x+(-129*pigScale), y+(-3*pigScale)}, {x+(-124*pigScale), y+(-9*pigScale)}, {x+(-129*pigScale), y+(-4*pigScale)}, {x+(-123*pigScale), y+(-8*pigScale)}, {x+(-120*pigScale), y+(-64*pigScale)}, {x+(-113*pigScale), y+(-73*pigScale)}, {x+(-111*pigScale), y+(-75*pigScale)}, {x+(-102*pigScale), y+(-75*pigScale)}, {x+(-91*pigScale), y+(-63*pigScale)}, {x+(-89*pigScale), y+(-59*pigScale)}, {x+(-85*pigScale), y+(-40*pigScale)}, {x+(-85*pigScale), y+(2*pigScale)}, {x+(-93*pigScale), y+(17*pigScale)}, {x+(-105*pigScale), y+(25*pigScale)}, {x+(-93), y+(17)}, {x+(-105), y+(25)}, {x+(-116), y+(27)}, {x+(-182), y+(26)}, {x+(-184), y+(23)}, {x+(-189), y+(20)}, {x+(-194), y+(16)}, };
                    txSetColor(BLACK);
                    txSetFillColor(pigSkinColor);
                    txPolygon(PigLeftArm, 25);
                }
            }

            if (pigLeg)
            {
                //Левая нога
                POINT PigLeftLeg [27] = {{x+(63*pigScale), y+(-52*pigScale)}, {x+(79*pigScale), y+(-55*pigScale)}, {x+(90*pigScale), y+(-58*pigScale)}, {x+(88*pigScale), y+(-62*pigScale)}, {x+(77*pigScale), y+(-79*pigScale)}, {x+(74*pigScale), y+(-87*pigScale)}, {x+(71*pigScale), y+(-96*pigScale)}, {x+(70*pigScale), y+(-100*pigScale)}, {x+(73*pigScale), y+(-107*pigScale)}, {x+(80*pigScale), y+(-110*pigScale)}, {x+(102*pigScale), y+(-110*pigScale)}, {x+(110*pigScale), y+(-108*pigScale)}, {x+(118*pigScale), y+(-103*pigScale)}, {x+(126*pigScale), y+(-98*pigScale)}, {x+(132*pigScale), y+(-91*pigScale)}, {x+(132*pigScale), y+(-77*pigScale)}, {x+(130*pigScale), y+(-71*pigScale)}, {x+(122*pigScale), y+(-67*pigScale)}, {x+(113*pigScale), y+(-67*pigScale)}, {x+(112*pigScale), y+(-66*pigScale)}, {x+(118*pigScale), y+(-55*pigScale)}, {x+(118*pigScale), y+(-45*pigScale)}, {x+(99*pigScale), y+(-36*pigScale)}, {x+(82*pigScale), y+(-36*pigScale)}, {x+(60*pigScale), y+(-34*pigScale)}, {x+(61*pigScale), y+(-42*pigScale)}, {x+(63*pigScale), y+(-45*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigSkinColor);
                txPolygon(PigLeftLeg, 27);

                //Правая нога
                POINT PigRightLeg [5] = {{x+(63*pigScale), y+(-77*pigScale)}, {x+(63*pigScale), y+(-59*pigScale)}, {x+(75*pigScale), y+(-59*pigScale)}, {x+(88*pigScale), y+(-62*pigScale)}, {x+(77*pigScale), y+(-79*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigSkinColor);
                txPolygon(PigRightLeg, 5);

                //Правая стопа
                POINT PigRightSole [15] = {{x+(70*pigScale), y+(-100*pigScale)}, {x+(65*pigScale), y+(-106*pigScale)}, {x+(61*pigScale), y+(-116*pigScale)}, {x+(56*pigScale), y+(-125*pigScale)}, {x+(61*pigScale), y+(-131*pigScale)}, {x+(71*pigScale), y+(-133*pigScale)}, {x+(100*pigScale), y+(-133*pigScale)}, {x+(100*pigScale), y+(-133*pigScale)}, {x+(108*pigScale), y+(-130*pigScale)}, {x+(112*pigScale), y+(-124*pigScale)}, {x+(114*pigScale), y+(-113*pigScale)}, {x+(110*pigScale), y+(-108*pigScale)}, {x+(102*pigScale), y+(-110*pigScale)}, {x+(80*pigScale), y+(-110*pigScale)}, {x+(73*pigScale), y+(-107*pigScale)}, };
                txSetColor(BLACK);
                txSetFillColor(pigSkinColor);
                txPolygon(PigRightSole, 15);
            }

            if (pigRoth)
            {
                txSetColor(BLACK);
                txLine(x+(-220*pigScale), y+(-130*pigScale), x+(-214*pigScale), y+(-118*pigScale));
                txLine(x+(-214*pigScale), y+(-118*pigScale), x+(-203*pigScale), y+(-116*pigScale));
                txLine(x+(-203*pigScale), y+(-116*pigScale), x+(-196*pigScale), y+(-118*pigScale));
                txLine(x+(-196*pigScale), y+(-118*pigScale), x+(-188*pigScale), y+(-121*pigScale));
                txLine(x+(-188*pigScale), y+(-121*pigScale), x+(-186*pigScale), y+(-125*pigScale));
                txLine(x+(-186*pigScale), y+(-125*pigScale), x+(-182*pigScale), y+(-135*pigScale));

                txLine(x+(-185), y+(-137), x+(-178), y+(-133));
            }else{
                txSetColor(BLACK);
                txLine(x+(-219*pigScale), y+(-119*pigScale), x+(-218*pigScale), y+(-118*pigScale));
                txLine(x+(-218*pigScale), y+(-118*pigScale), x+(-191*pigScale), y+(-118*pigScale));
                txLine(x+(-191*pigScale), y+(-118*pigScale), x+(-189*pigScale), y+(-122*pigScale));
            }

            //Нос
            POINT PigNose [13] = {{x+(-217*pigScale), y+(-157*pigScale)}, {x+(-210*pigScale), y+(-157*pigScale)}, {x+(-201*pigScale), y+(-151*pigScale)}, {x+(-201*pigScale), y+(-139*pigScale)}, {x+(-201*pigScale), y+(-134*pigScale)}, {x+(-202*pigScale), y+(-132*pigScale)}, {x+(-217*pigScale), y+(-132*pigScale)}, {x+(-221*pigScale), y+(-135*pigScale)}, {x+(-223*pigScale), y+(-137*pigScale)}, {x+(-224*pigScale), y+(-140*pigScale)}, {x+(-225*pigScale), y+(-146*pigScale)}, {x+(-224*pigScale), y+(-150*pigScale)}, {x+(-220*pigScale), y+(-154*pigScale)}, };
            txSetColor(BLACK);
            txSetFillColor(pigNoseColor);
            txPolygon(PigNose, 13);

            if (pigEyes)
            {
                //Глаза
                txSetFillColor(BLACK);
                txEllipse(x+(-205*pigScale), y+(-164*pigScale), x+(-202*pigScale), y+(-158*pigScale));
                txEllipse(x+(-180*pigScale), y+(-158*pigScale), x+(-175*pigScale), y+(-150*pigScale));
            }else{
                txSetColor(BLACK, 2);
                txLine(x+(-207*pigScale), y+(-160*pigScale), x+(-202*pigScale), y+(-160*pigScale));
                txLine(x+(-180*pigScale), y+(-154*pigScale), x+(-175*pigScale), y+(-154*pigScale));
            }

            txSetColor(BLACK);
            txLine(x+(-200*pigScale), y+(-190*pigScale), x+(-199*pigScale), y+(-193*pigScale));
            txLine(x+(-199*pigScale), y+(-193*pigScale), x+(-195*pigScale), y+(-194*pigScale));

            txLine(x+(-174*pigScale), y+(-189*pigScale), x+(-171*pigScale), y+(-188*pigScale));
            txLine(x+(-171*pigScale), y+(-188*pigScale), x+(-169*pigScale), y+(-187*pigScale));
            txLine(x+(-169*pigScale), y+(-187*pigScale), x+(-168*pigScale), y+(-186*pigScale));
            txLine(x+(-168*pigScale), y+(-186*pigScale), x+(-167*pigScale), y+(-182*pigScale));
    }

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Minion
//! @brief   Отрисовка персонажа ,,Миньон" - герой мультфильма «Гадкий я».
//!
//! @image html Image/Minion.png
//!
//! @param   x   Х-координата точки
//! @param   y 	Y-координата точки
//! @param   MinionHand Наличие рук у персонажа (0 - Нет рук, 1 - Правая рука, 2 - Левая рука, 3 - Обе руки)
//! @param   MinionScale	Размер персонажа (1 - Стандартный размер, 2 - В 2 раза больше стандартного размера и т.д.)
//! @param   MinionGlasses Наличие очков у персонажа (0 - Нет очков, 1 - Есть очки)
//! @param   MinionHair Наличие волос у персонажа (0 - Нет волос, 1 - Есть волос)
//! @param   MinionRoth	Наличие рта у персонажа (0 - Нет рта, 1 - Есть рот)
//! @param   MinionEyesColor	Цвет глаз персонажа
//! @param   MinionPantsColor	Цвет штанов персонажа
//! @param   MinionGlassesColor Цвет очков персонажа
//! @param   MinionPocketColor	Цвет карманчика на штанах персонажа
//!
//! @warning Если цвета разных частей тела совпадают, <del>может произойти ядерный коллапс</del> могут наблюдаться серъёзные графические баги.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @note    Для использования функции нужно создать холст из TXLib.
//!
//! Пример использования функции смотрите в @ref Tutor "примере реализации".
//}----------------------------------------------------------------------------------------------------------------

	void drawMinion(int x, int y, int MinionHand, int MinionScale, bool MinionGlasses, bool MinionHair, bool MinionRoth, COLORREF MinionEyesColor, COLORREF MinionPantsColor, COLORREF MinionGlassesColor, COLORREF MinionPocketColor)
    {
        //Миньон
            //Правая нога
            POINT MinionRightLeg [14] = {{x+(49*MinionScale), y+(247*MinionScale)}, {x+(70*MinionScale), y+(250*MinionScale)}, {x+(106*MinionScale), y+(250*MinionScale)}, {x+(106*MinionScale), y+(274*MinionScale)}, {x+(110*MinionScale), y+(280*MinionScale)}, {x+(110*MinionScale), y+(293*MinionScale)}, {x+(103*MinionScale), y+(300*MinionScale)}, {x+(96*MinionScale), y+(302*MinionScale)}, {x+(63*MinionScale), y+(302*MinionScale)}, {x+(54*MinionScale), y+(299*MinionScale)}, {x+(48*MinionScale), y+(291*MinionScale)}, {x+(48*MinionScale), y+(276*MinionScale)}, {x+(50*MinionScale), y+(273*MinionScale)}, {x+(49*MinionScale), y+(273*MinionScale)}};
            txSetColor(BLACK);
            txSetFillColor(MinionPantsColor);
            txPolygon(MinionRightLeg, 14);

            txSetColor(BLACK);
            txLine(x+(50*MinionScale), y+(273*MinionScale), x+(63*MinionScale), y+(276*MinionScale));
            txLine(x+(63*MinionScale), y+(276*MinionScale), x+(91*MinionScale), y+(276*MinionScale));
            txLine(x+(91*MinionScale), y+(276*MinionScale), x+(106*MinionScale), y+(273*MinionScale));

            txSetFillColor(BLACK);
            txFloodFill(x+(109*MinionScale), y+(287*MinionScale), BLACK, FLOODFILLBORDER);

            //Левая нога
            POINT MinionLeftLeg [13] = {{x+(125*MinionScale), y+(250*MinionScale)}, {x+(173*MinionScale), y+(250*MinionScale)}, {x+(179*MinionScale), y+(248*MinionScale)}, {x+(179*MinionScale), y+(270*MinionScale)}, {x+(185*MinionScale), y+(277*MinionScale)}, {x+(185*MinionScale), y+(290*MinionScale)}, {x+(177*MinionScale), y+(298*MinionScale)}, {x+(166*MinionScale), y+(301*MinionScale)}, {x+(127*MinionScale), y+(301*MinionScale)}, {x+(122*MinionScale), y+(297*MinionScale)}, {x+(118*MinionScale), y+(293*MinionScale)}, {x+(118*MinionScale), y+(285*MinionScale)}, {x+(125*MinionScale), y+(275*MinionScale)}};
            txSetColor(BLACK);
            txSetFillColor(MinionPantsColor);
            txPolygon(MinionLeftLeg, 13);

            txSetFillColor(MinionPantsColor);
            txFloodFill(x+(155*MinionScale), y+(285*MinionScale), BLACK, FLOODFILLBORDER);

            txSetColor(BLACK);
            txLine(x+(125*MinionScale), y+(275*MinionScale), x+(169*MinionScale), y+(275*MinionScale));
            txLine(x+(169*MinionScale), y+(275*MinionScale), x+(179*MinionScale), y+(270*MinionScale));

            txSetFillColor(BLACK);
            txFloodFill(x+(184*MinionScale), y+(284*MinionScale), BLACK, FLOODFILLBORDER);

            //Тело
            POINT MinionBody [27] = {{x+(49*MinionScale), y+(247*MinionScale)}, {x+(70*MinionScale), y+(250*MinionScale)}, {x+(173*MinionScale), y+(250*MinionScale)}, {x+(179*MinionScale), y+(248*MinionScale)}, {x+(198*MinionScale), y+(245*MinionScale)}, {x+(212*MinionScale), y+(239*MinionScale)}, {x+(218*MinionScale), y+(228*MinionScale)}, {x+(213*MinionScale), y+(223*MinionScale)}, {x+(209*MinionScale), y+(216*MinionScale)}, {x+(209*MinionScale), y+(179*MinionScale)}, {x+(212*MinionScale), y+(170*MinionScale)}, {x+(212*MinionScale), y+(165*MinionScale)}, {x+(206*MinionScale), y+(157*MinionScale)}, {x+(195*MinionScale), y+(138*MinionScale)}, {x+(195*MinionScale), y+(136*MinionScale)}, {x+(52*MinionScale), y+(136*MinionScale)}, {x+(52*MinionScale), y+(138*MinionScale)}, {x+(40*MinionScale), y+(164*MinionScale)}, {x+(33*MinionScale), y+(161*MinionScale)}, {x+(33*MinionScale), y+(179*MinionScale)}, {x+(29*MinionScale), y+(195*MinionScale)}, {x+(24*MinionScale), y+(209*MinionScale)}, {x+(20*MinionScale), y+(216*MinionScale)}, {x+(13*MinionScale), y+(222*MinionScale)}, {x+(2*MinionScale), y+(227*MinionScale)}, {x+(18*MinionScale), y+(239*MinionScale)}, {x+(33*MinionScale), y+(243*MinionScale)}};
            txSetColor(BLACK);
            txSetFillColor(MinionPantsColor);
            txPolygon(MinionBody, 27);

            //Карман
            txSetColor(BLACK);
            txLine(x+(159*MinionScale), y+(181*MinionScale), x+(76*MinionScale), y+(181*MinionScale));
            txLine(x+(76*MinionScale), y+(181*MinionScale), x+(76*MinionScale), y+(218*MinionScale));
            txLine(x+(76*MinionScale), y+(218*MinionScale), x+(113*MinionScale), y+(236*MinionScale));
            txLine(x+(113*MinionScale), y+(236*MinionScale), x+(159*MinionScale), y+(218*MinionScale));
            txLine(x+(159*MinionScale), y+(218*MinionScale), x+(159*MinionScale), y+(181*MinionScale));
            txSetFillColor(MinionPocketColor);
            txFloodFill(x+(113*MinionScale), y+(209*MinionScale), BLACK, FLOODFILLBORDER);

            if (MinionHand == 1)
            {
                //Правая рука
                POINT MinionRightArm [17] = {{x+(2*MinionScale), y+(227*MinionScale)}, {x+(2*MinionScale), y+(211*MinionScale)}, {x+(-13*MinionScale), y+(209*MinionScale)}, {x+(-20*MinionScale), y+(204*MinionScale)}, {x+(-25*MinionScale), y+(200*MinionScale)}, {x+(-32*MinionScale), y+(187*MinionScale)}, {x+(-32*MinionScale), y+(173*MinionScale)}, {x+(-26*MinionScale), y+(165*MinionScale)}, {x+(-15*MinionScale), y+(155*MinionScale)}, {x+(1*MinionScale), y+(147*MinionScale)}, {x+(1*MinionScale), y+(144*MinionScale)}, {x+(33*MinionScale), y+(161*MinionScale)}, {x+(33*MinionScale), y+(179*MinionScale)}, {x+(29*MinionScale), y+(195*MinionScale)}, {x+(24*MinionScale), y+(209*MinionScale)}, {x+(20*MinionScale), y+(216*MinionScale)}, {x+(13*MinionScale), y+(222*MinionScale)}};
                txSetColor(BLACK);
                txSetFillColor(YELLOW);
                txPolygon(MinionRightArm, 17);

                txSetColor(BLACK);
                txLine(x+(2*MinionScale), y+(211*MinionScale), x+(2*MinionScale), y+(178*MinionScale));
                txLine(x+(2*MinionScale), y+(195*MinionScale), x+(29*MinionScale), y+(195*MinionScale));
                txLine(x+(-7*MinionScale), y+(190*MinionScale), x+(6*MinionScale), y+(174*MinionScale));

                //Левый бок
                txSetColor(BLACK);
                txLine(x+(229*MinionScale), y+(149*MinionScale), x+(229*MinionScale), y+(211*MinionScale));
                txLine(x+(229*MinionScale), y+(200*MinionScale), x+(209*MinionScale), y+(200*MinionScale));
                txLine(x+(229*MinionScale), y+(211*MinionScale), x+(218*MinionScale), y+(228*MinionScale));
            }

            if (MinionHand == 2)
            {
                //Левая рука
                POINT MinionLeftArm [18] = {{x+(209*MinionScale), y+(216*MinionScale)}, {x+(209*MinionScale), y+(179*MinionScale)}, {x+(212*MinionScale), y+(170*MinionScale)}, {x+(212*MinionScale), y+(165*MinionScale)}, {x+(229*MinionScale), y+(149*MinionScale)}, {x+(229*MinionScale), y+(161*MinionScale)}, {x+(226*MinionScale), y+(159*MinionScale)}, {x+(229*MinionScale), y+(161*MinionScale)}, {x+(238*MinionScale), y+(169*MinionScale)}, {x+(249*MinionScale), y+(178*MinionScale)}, {x+(259*MinionScale), y+(191*MinionScale)}, {x+(259*MinionScale), y+(203*MinionScale)}, {x+(250*MinionScale), y+(211*MinionScale)}, {x+(234*MinionScale), y+(219*MinionScale)}, {x+(223*MinionScale), y+(219*MinionScale)}, {x+(220*MinionScale), y+(228*MinionScale)}, {x+(218*MinionScale), y+(228*MinionScale)}, {x+(213*MinionScale), y+(223*MinionScale)}};
                txSetColor(BLACK);
                txSetFillColor(YELLOW);
                txPolygon(MinionLeftArm, 18);

                txSetColor(BLACK);
                txLine(x+(223*MinionScale), y+(219*MinionScale), x+(227*MinionScale), y+(211*MinionScale));
                txLine(x+(227*MinionScale), y+(211*MinionScale), x+(227*MinionScale), y+(192*MinionScale));
                txLine(x+(220*MinionScale), y+(185*MinionScale), x+(233*MinionScale), y+(197*MinionScale));
                txLine(x+(209*MinionScale), y+(200*MinionScale), x+(227*MinionScale), y+(200*MinionScale));

                //Правый бок
                txSetColor(BLACK);
                txLine(x+(2*MinionScale), y+(227*MinionScale), x+(2*MinionScale), y+(144*MinionScale));
            }

            if (MinionHand == 3)
            {
                //Правая рука
                POINT MinionRightArm [17] = {{x+(2*MinionScale), y+(227*MinionScale)}, {x+(2*MinionScale), y+(211*MinionScale)}, {x+(-13*MinionScale), y+(209*MinionScale)}, {x+(-20*MinionScale), y+(204*MinionScale)}, {x+(-25*MinionScale), y+(200*MinionScale)}, {x+(-32*MinionScale), y+(187*MinionScale)}, {x+(-32*MinionScale), y+(173*MinionScale)}, {x+(-26*MinionScale), y+(165*MinionScale)}, {x+(-15*MinionScale), y+(155*MinionScale)}, {x+(1*MinionScale), y+(147*MinionScale)}, {x+(1*MinionScale), y+(144*MinionScale)}, {x+(33*MinionScale), y+(161*MinionScale)}, {x+(33*MinionScale), y+(179*MinionScale)}, {x+(29*MinionScale), y+(195*MinionScale)}, {x+(24*MinionScale), y+(209*MinionScale)}, {x+(20*MinionScale), y+(216*MinionScale)}, {x+(13*MinionScale), y+(222*MinionScale)}};
                txSetColor(BLACK);
                txSetFillColor(YELLOW);
                txPolygon(MinionRightArm, 17);

                txSetColor(BLACK);
                txLine(x+(2*MinionScale), y+(211*MinionScale), x+(2*MinionScale), y+(178*MinionScale));
                txLine(x+(2*MinionScale), y+(195*MinionScale), x+(29*MinionScale), y+(195*MinionScale));
                txLine(x+(-7*MinionScale), y+(190*MinionScale), x+(6*MinionScale), y+(174*MinionScale));

                //Левая рука
                POINT MinionLeftArm [18] = {{x+(209*MinionScale), y+(216*MinionScale)}, {x+(209*MinionScale), y+(179*MinionScale)}, {x+(212*MinionScale), y+(170*MinionScale)}, {x+(212*MinionScale), y+(165*MinionScale)}, {x+(229*MinionScale), y+(149*MinionScale)}, {x+(229*MinionScale), y+(161*MinionScale)}, {x+(226*MinionScale), y+(159*MinionScale)}, {x+(229*MinionScale), y+(161*MinionScale)}, {x+(238*MinionScale), y+(169*MinionScale)}, {x+(249*MinionScale), y+(178*MinionScale)}, {x+(259*MinionScale), y+(191*MinionScale)}, {x+(259*MinionScale), y+(203*MinionScale)}, {x+(250*MinionScale), y+(211*MinionScale)}, {x+(234*MinionScale), y+(219*MinionScale)}, {x+(223*MinionScale), y+(219*MinionScale)}, {x+(220*MinionScale), y+(228*MinionScale)}, {x+(218*MinionScale), y+(228*MinionScale)}, {x+(213*MinionScale), y+(223*MinionScale)}};
                txSetColor(BLACK);
                txSetFillColor(YELLOW);
                txPolygon(MinionLeftArm, 18);

                txSetColor(BLACK);
                txLine(x+(223*MinionScale), y+(219*MinionScale), x+(227*MinionScale), y+(211*MinionScale));
                txLine(x+(227*MinionScale), y+(211*MinionScale), x+(227*MinionScale), y+(192*MinionScale));
                txLine(x+(220*MinionScale), y+(185*MinionScale), x+(233*MinionScale), y+(197*MinionScale));
                txLine(x+(209*MinionScale), y+(200*MinionScale), x+(227*MinionScale), y+(200*MinionScale));
            }

            //Лямки
            POINT MinionRightStrap [6] = {{x+(195*MinionScale), y+(136*MinionScale)}, {x+(195*MinionScale), y+(138*MinionScale)}, {x+(206*MinionScale), y+(157*MinionScale)}, {x+(212*MinionScale), y+(165*MinionScale)}, {x+(229*MinionScale), y+(149*MinionScale)}, {x+(229*MinionScale), y+(103*MinionScale)}};
            txSetColor(BLACK);
            txSetFillColor(MinionPantsColor);
            txPolygon(MinionRightStrap, 6);

            POINT MinionLeftStrap [5] = {{x+(1*MinionScale), y+(144*MinionScale)}, {x+(33*MinionScale), y+(161*MinionScale)}, {x+(40*MinionScale), y+(164*MinionScale)}, {x+(52*MinionScale), y+(138*MinionScale)}, {x+(1*MinionScale), y+(110*MinionScale)}};
            txSetColor(BLACK);
            txSetFillColor(MinionPantsColor);
            txPolygon(MinionLeftStrap, 5);

            if (MinionHand == 0)
            {
                //Правый бок
                txSetColor(BLACK);
                txLine(x+(2*MinionScale), y+(227*MinionScale), x+(2*MinionScale), y+(144*MinionScale));
                txSetFillColor(YELLOW);
                txFloodFill(x+(22*MinionScale), y+(181*MinionScale), BLACK, FLOODFILLBORDER);

                //Левый бок
                txSetColor(BLACK);
                txLine(x+(229*MinionScale), y+(149*MinionScale), x+(229*MinionScale), y+(211*MinionScale));
                txLine(x+(229*MinionScale), y+(200*MinionScale), x+(209*MinionScale), y+(200*MinionScale));
                txLine(x+(229*MinionScale), y+(211*MinionScale), x+(218*MinionScale), y+(228*MinionScale));
            }

            txSetColor(BLACK);
            txLine(x+(2*MinionScale), y+(195*MinionScale), x+(29*MinionScale), y+(195*MinionScale));
            txSetFillColor(MinionPantsColor);
            txFloodFill(x+(15*MinionScale), y+(207*MinionScale), BLACK, FLOODFILLBORDER);

            txSetFillColor(MinionPantsColor);
            txFloodFill(x+(219*MinionScale), y+(209*MinionScale), BLACK, FLOODFILLBORDER);
            txSetFillColor(YELLOW);
            txFloodFill(x+(216*MinionScale), y+(176*MinionScale), BLACK, FLOODFILLBORDER);
            txSetFillColor(YELLOW);
            txFloodFill(x+(22*MinionScale), y+(181*MinionScale), BLACK, FLOODFILLBORDER);

            //Голова
            txSetColor(BLACK);
            txLine(x+(229*MinionScale), y+(103*MinionScale), x+(229*MinionScale), y+(6*MinionScale));
            txLine(x+(1*MinionScale), y+(110*MinionScale), x+(1*MinionScale), y+(6*MinionScale));
            txArc (x+(1*MinionScale), y+(-65*MinionScale), x+(229*MinionScale), y+(78*MinionScale), 0, 180);

            txSetFillColor(YELLOW);
            txFloodFill(x+(227*MinionScale), y+(50*MinionScale), BLACK, FLOODFILLBORDER);

            if (MinionGlasses)
            {
                //Глаза
                POINT MinionRightEyeStrap [8] = {{x+(0*MinionScale), y+(46*MinionScale)}, {x+(20*MinionScale), y+(46*MinionScale)}, {x+(17*MinionScale), y+(38*MinionScale)}, {x+(16*MinionScale), y+(31*MinionScale)}, {x+(16*MinionScale), y+(24*MinionScale)}, {x+(17*MinionScale), y+(20*MinionScale)}, {x+(19*MinionScale), y+(14*MinionScale)}, {x+(0*MinionScale), y+(14*MinionScale)}};
                txSetColor(BLACK);
                txSetFillColor(MinionGlassesColor);
                txPolygon(MinionRightEyeStrap, 8);

                POINT MinionLeftEyeStrap [7] = {{x+(218*MinionScale), y+(44*MinionScale)}, {x+(228*MinionScale), y+(44*MinionScale)}, {x+(228*MinionScale), y+(8*MinionScale)}, {x+(216*MinionScale), y+(8*MinionScale)}, {x+(219*MinionScale), y+(16*MinionScale)}, {x+(220*MinionScale), y+(24*MinionScale)}, {x+(220*MinionScale), y+(35*MinionScale)}};
                txSetColor(BLACK);
                txSetFillColor(MinionGlassesColor);
                txPolygon(MinionLeftEyeStrap, 7);

                txSetColor(BLACK);
                txSetFillColor(MinionGlassesColor);
                txCircle(x+(68*MinionScale), y+(30*MinionScale), 52*MinionScale);
            }

            txSetColor(BLACK);
            txSetFillColor(WHITE);
            txCircle(x+(68*MinionScale), y+(30*MinionScale), 42*MinionScale);

            txSetColor(BLACK);
            txSetFillColor(MinionEyesColor);
            txCircle(x+(68*MinionScale), y+(36*MinionScale), 15*MinionScale);

            txSetColor(BLACK);
            txSetFillColor(BLACK);
            txCircle(x+(68*MinionScale), y+(36*MinionScale), 8*MinionScale);

            if (MinionGlasses)
            {
                txSetColor(BLACK);
                txSetFillColor(MinionGlassesColor);
                txCircle(x+(170*MinionScale), y+(30*MinionScale), 51*MinionScale);
            }

            txSetColor(BLACK);
            txSetFillColor(WHITE);
            txCircle(x+(170*MinionScale), y+(30*MinionScale), 41*MinionScale);

            txSetColor(BLACK);
            txSetFillColor(MinionEyesColor);
            txCircle(x+(162*MinionScale), y+(35*MinionScale), 17*MinionScale);

            txSetColor(BLACK);
            txSetFillColor(BLACK);
            txCircle(x+(161*MinionScale), y+(37*MinionScale), 7*MinionScale);

            if (MinionRoth)
            {
                //Рот
                POINT MinionRoth [15] = {{x+(75*MinionScale), y+(84*MinionScale)}, {x+(85*MinionScale), y+(84*MinionScale)}, {x+(102*MinionScale), y+(94*MinionScale)}, {x+(130*MinionScale), y+(94*MinionScale)}, {x+(149*MinionScale), y+(86*MinionScale)}, {x+(158*MinionScale), y+(86*MinionScale)}, {x+(162*MinionScale), y+(91*MinionScale)}, {x+(162*MinionScale), y+(109*MinionScale)}, {x+(151*MinionScale), y+(121*MinionScale)}, {x+(129*MinionScale), y+(129*MinionScale)}, {x+(101*MinionScale), y+(129*MinionScale)}, {x+(86*MinionScale), y+(122*MinionScale)}, {x+(76*MinionScale), y+(112*MinionScale)}, {x+(72*MinionScale), y+(97*MinionScale)}, {x+(72*MinionScale), y+(89*MinionScale)}};
                txSetColor(BLACK);
                txSetFillColor(WHITE);
                txPolygon(MinionRoth, 15);

                txSetColor(BLACK);
                txLine(x+(90*MinionScale), y+(124*MinionScale), x+(90*MinionScale), y+(106*MinionScale));
                txLine(x+(90*MinionScale), y+(106*MinionScale), x+(95*MinionScale), y+(90*MinionScale));

                txSetColor(BLACK);
                txLine(x+(128*MinionScale), y+(94*MinionScale), x+(128*MinionScale), y+(100*MinionScale));
                txLine(x+(128*MinionScale), y+(100*MinionScale), x+(129*MinionScale), y+(101*MinionScale));
                txLine(x+(129*MinionScale), y+(101*MinionScale), x+(129*MinionScale), y+(129*MinionScale));
            }else{
                txSetColor(BLACK, 3);
                txLine(x+(75*MinionScale), y+(107*MinionScale), x+(162*MinionScale), y+(107*MinionScale));
            }


            if (MinionHair)
            {
                //Волосы
                txSetColor(BLACK);
                txLine(x+(76*MinionScale), y+(-46*MinionScale), x+(34*MinionScale), y+(-60*MinionScale));
                txLine(x+(95*MinionScale), y+(-55*MinionScale), x+(39*MinionScale), y+(-74*MinionScale));
                txLine(x+(101*MinionScale), y+(-59*MinionScale), x+(66*MinionScale), y+(-89*MinionScale));
                txLine(x+(117*MinionScale), y+(-62*MinionScale), x+(139*MinionScale), y+(-90*MinionScale));
                txLine(x+(126*MinionScale), y+(-60*MinionScale), x+(168*MinionScale), y+(-83*MinionScale));
                txLine(x+(141*MinionScale), y+(-56*MinionScale), x+(189*MinionScale), y+(-69*MinionScale));
            }
    }

	
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Skubi
//! @brief   Отрисовка персонажа ,,Скуби-Ду" - герой мультсериала «Скуби-Ду шоу».
//!
//! @image html Image/Skubi.png
//!
//! @param   x   Х-координата точки
//! @param   y 	Y-координата точки
//! @param   SkubiScale Размер персонажа (1 - Стандартный размер, 2 - В 2 раза больше стандартного размера и т.д.)
//! @param   SkubiKeychain Наличие брелка у персонажа (0 - Нет брелка, 1 - Есть брелок)
//! @param   SkubyMoles	Наличие родинок у персонажа (0 - Нет родинок, 1 - Есть родинки)
//! @param   SkubiEyes	Наличие глаз у персонажа (0 - Нет глаз, 1 - Есть глаза)
//! @param   SkubiNose Наличие носа у персонажа (0 - Нет носа, 1 - Есть нос)
//! @param   SkubiTeeth	Наличие зубов у персонажа (0 - Нет зубов, 1 - Есть зубы)
//! @param   SkubiStrokePanelColor Цвет обводки у персонажа 
//! @param   SkubiSkinColor		Цвет кожи персонажа <del>Внимание: Мы против рассизма! </del>
//! @param   SkubiCollarColor	Цвет ошейника у персонажа 
//! @param   SkubiEyesColor 	Цвет глаз у персонажа 
//!
//! @warning Если цвета разных частей тела совпадают, <del>может произойти ядерный коллапс</del> могут наблюдаться серъёзные графические баги.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @note    Для использования функции нужно создать холст из TXLib.
//!
//! Пример использования функции смотрите в @ref Tutor "примере реализации".
//}----------------------------------------------------------------------------------------------------------------
    
	void drawSkubi(int x, int y, int SkubiScale, bool SkubiKeychain, bool SkubyMoles, bool SkubiEyes, bool SkubiNose, bool SkubiTeeth, COLORREF SkubiStrokePanelColor, COLORREF SkubiSkinColor, COLORREF SkubiCollarColor, COLORREF SkubiEyesColor)
    {
        //Скуби
            //Ошейник
            txSetColor(SkubiStrokePanelColor, 3);

            txLine(x+(0*SkubiScale), y+(0*SkubiScale), x+(17*SkubiScale), y+(21*SkubiScale));
            txLine(x+(17*SkubiScale), y+(21*SkubiScale), x+(36*SkubiScale), y+(31*SkubiScale));

            txLine(x+(45*SkubiScale), y+(38*SkubiScale), x+(106*SkubiScale), y+(58*SkubiScale));
            txLine(x+(106*SkubiScale), y+(58*SkubiScale), x+(126*SkubiScale), y+(58*SkubiScale));
            txLine(x+(126*SkubiScale), y+(58*SkubiScale), x+(135*SkubiScale), y+(36*SkubiScale));
            txLine(x+(135*SkubiScale), y+(36*SkubiScale), x+(106*SkubiScale), y+(35*SkubiScale));
            txLine(x+(106*SkubiScale), y+(35*SkubiScale), x+(57*SkubiScale), y+(16*SkubiScale));

            txLine(x+(47*SkubiScale), y+(11*SkubiScale), x+(16*SkubiScale), y+(-14*SkubiScale));
            txLine(x+(16*SkubiScale), y+(-14*SkubiScale), x+(0*SkubiScale), y+(0*SkubiScale));

            if (SkubiKeychain)
            {
                txLine(x+(52*SkubiScale), y+(6*SkubiScale), x+(58*SkubiScale), y+(15*SkubiScale));
                txLine(x+(58*SkubiScale), y+(15*SkubiScale), x+(50*SkubiScale), y+(20*SkubiScale));
                txLine(x+(50*SkubiScale), y+(20*SkubiScale), x+(45*SkubiScale), y+(32*SkubiScale));
                txLine(x+(45*SkubiScale), y+(32*SkubiScale), x+(45*SkubiScale), y+(47*SkubiScale));
                txLine(x+(45*SkubiScale), y+(47*SkubiScale), x+(37*SkubiScale), y+(47*SkubiScale));
                txLine(x+(37*SkubiScale), y+(47*SkubiScale), x+(36*SkubiScale), y+(31*SkubiScale));
                txLine(x+(36*SkubiScale), y+(31*SkubiScale), x+(40*SkubiScale), y+(19*SkubiScale));
                txLine(x+(40*SkubiScale), y+(19*SkubiScale), x+(52*SkubiScale), y+(6*SkubiScale));

                txLine(x+(27*SkubiScale), y+(50*SkubiScale), x+(37*SkubiScale), y+(39*SkubiScale));
                txLine(x+(37*SkubiScale), y+(39*SkubiScale), x+(37*SkubiScale), y+(47*SkubiScale));
                txLine(x+(37*SkubiScale), y+(47*SkubiScale), x+(35*SkubiScale), y+(47*SkubiScale));
                txLine(x+(35*SkubiScale), y+(47*SkubiScale), x+(35*SkubiScale), y+(64*SkubiScale));
                txLine(x+(35*SkubiScale), y+(64*SkubiScale), x+(46*SkubiScale), y+(54*SkubiScale));
                txLine(x+(46*SkubiScale), y+(54*SkubiScale), x+(46*SkubiScale), y+(48*SkubiScale));
                txLine(x+(46*SkubiScale), y+(48*SkubiScale), x+(45*SkubiScale), y+(47*SkubiScale));
                txLine(x+(45*SkubiScale), y+(47*SkubiScale), x+(45*SkubiScale), y+(38*SkubiScale));
                txLine(x+(45*SkubiScale), y+(38*SkubiScale), x+(50*SkubiScale), y+(39*SkubiScale));
                txLine(x+(50*SkubiScale), y+(39*SkubiScale), x+(53*SkubiScale), y+(56*SkubiScale));
                txLine(x+(53*SkubiScale), y+(56*SkubiScale), x+(32*SkubiScale), y+(73*SkubiScale));
                txLine(x+(32*SkubiScale), y+(73*SkubiScale), x+(27*SkubiScale), y+(50*SkubiScale));

                txSetFillColor(YELLOW);
                txFloodFill(x+(44*SkubiScale), y+(22*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
                txFloodFill(x+(35*SkubiScale), y+(68*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
                txSetFillColor(SkubiCollarColor);
                txFloodFill(x+(54*SkubiScale), y+(20*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
            }else{
                txSetColor(SkubiStrokePanelColor, 3);
                txLine(x+(47*SkubiScale), y+(11*SkubiScale), x+(57*SkubiScale), y+(16*SkubiScale));
                txLine(x+(17*SkubiScale), y+(21*SkubiScale), x+(50*SkubiScale), y+(39*SkubiScale));
            }

            //Шея
            txLine(x+(16*SkubiScale), y+(-14*SkubiScale), x+(43*SkubiScale), y+(-56*SkubiScale));

            txLine(x+(135*SkubiScale), y+(36*SkubiScale), x+(162*SkubiScale), y+(-33*SkubiScale));
            txLine(x+(162*SkubiScale), y+(-33*SkubiScale), x+(179*SkubiScale), y+(-113*SkubiScale));
            txLine(x+(179*SkubiScale), y+(-113*SkubiScale), x+(186*SkubiScale), y+(-196*SkubiScale));
            txLine(x+(186*SkubiScale), y+(-196*SkubiScale), x+(158*SkubiScale), y+(-251*SkubiScale));

            //Подбородок
            txLine(x+(139*SkubiScale), y+(-83*SkubiScale), x+(120*SkubiScale), y+(-75*SkubiScale));
            txLine(x+(120*SkubiScale), y+(-75*SkubiScale), x+(137*SkubiScale), y+(-91*SkubiScale));
            txLine(x+(137*SkubiScale), y+(-91*SkubiScale), x+(116*SkubiScale), y+(-71*SkubiScale));
            txLine(x+(116*SkubiScale), y+(-71*SkubiScale), x+(78*SkubiScale), y+(-56*SkubiScale));
            txLine(x+(78*SkubiScale), y+(-56*SkubiScale), x+(43*SkubiScale), y+(-56*SkubiScale));
            txLine(x+(43*SkubiScale), y+(-56*SkubiScale), x+(34*SkubiScale), y+(-73*SkubiScale));
            txLine(x+(34*SkubiScale), y+(-73*SkubiScale), x+(40*SkubiScale), y+(-88*SkubiScale));

            txLine(x+(34*SkubiScale), y+(-101*SkubiScale), x+(34*SkubiScale), y+(-91*SkubiScale));
            txLine(x+(34*SkubiScale), y+(-91*SkubiScale), x+(49*SkubiScale), y+(-84*SkubiScale));
            txLine(x+(49*SkubiScale), y+(-84*SkubiScale), x+(72*SkubiScale), y+(-86*SkubiScale));

            if (SkubiTeeth)
            {
            //Зубы
            txLine(x+(57*SkubiScale), y+(-105*SkubiScale), x+(59*SkubiScale), y+(-96*SkubiScale));
            txLine(x+(59*SkubiScale), y+(-96*SkubiScale), x+(85*SkubiScale), y+(-103*SkubiScale));

            txLine(x+(67*SkubiScale), y+(-109*SkubiScale), x+(67*SkubiScale), y+(-98*SkubiScale));

            txLine(x+(75*SkubiScale), y+(-100*SkubiScale), x+(75*SkubiScale), y+(-114*SkubiScale));
            }

            if (SkubiNose)
            {
                //Нос
                txLine(x+(75*SkubiScale), y+(-114*SkubiScale), x+(80*SkubiScale), y+(-119*SkubiScale));
                txLine(x+(80*SkubiScale), y+(-119*SkubiScale), x+(95*SkubiScale), y+(-132*SkubiScale));
                txLine(x+(95*SkubiScale), y+(-132*SkubiScale), x+(70*SkubiScale), y+(-143*SkubiScale));
                txLine(x+(70*SkubiScale), y+(-143*SkubiScale), x+(58*SkubiScale), y+(-160*SkubiScale));
                txLine(x+(58*SkubiScale), y+(-160*SkubiScale), x+(70*SkubiScale), y+(-177*SkubiScale));
                txLine(x+(70*SkubiScale), y+(-177*SkubiScale), x+(95*SkubiScale), y+(-186*SkubiScale));
                txLine(x+(95*SkubiScale), y+(-186*SkubiScale), x+(111*SkubiScale), y+(-186*SkubiScale));
                txLine(x+(111*SkubiScale), y+(-186*SkubiScale), x+(124*SkubiScale), y+(-180*SkubiScale));
                txLine(x+(124*SkubiScale), y+(-180*SkubiScale), x+(127*SkubiScale), y+(-167*SkubiScale));
                txLine(x+(127*SkubiScale), y+(-167*SkubiScale), x+(125*SkubiScale), y+(-157*SkubiScale));
                txLine(x+(125*SkubiScale), y+(-157*SkubiScale), x+(75*SkubiScale), y+(-114*SkubiScale));
            }

            txLine(x+(34*SkubiScale), y+(-101*SkubiScale), x+(26*SkubiScale), y+(-103*SkubiScale));
            txLine(x+(26*SkubiScale), y+(-103*SkubiScale), x+(23*SkubiScale), y+(-114*SkubiScale));
            txLine(x+(23*SkubiScale), y+(-114*SkubiScale), x+(27*SkubiScale), y+(-125*SkubiScale));
            txLine(x+(27*SkubiScale), y+(-125*SkubiScale), x+(20*SkubiScale), y+(-138*SkubiScale));
            txLine(x+(20*SkubiScale), y+(-138*SkubiScale), x+(20*SkubiScale), y+(-157*SkubiScale));
            txLine(x+(20*SkubiScale), y+(-157*SkubiScale), x+(30*SkubiScale), y+(-170*SkubiScale));
            txLine(x+(30*SkubiScale), y+(-170*SkubiScale), x+(34*SkubiScale), y+(-173*SkubiScale));
            txLine(x+(34*SkubiScale), y+(-173*SkubiScale), x+(50*SkubiScale), y+(-185*SkubiScale));
            txLine(x+(50*SkubiScale), y+(-185*SkubiScale), x+(48*SkubiScale), y+(-200*SkubiScale));

            txLine(x+(41*SkubiScale), y+(-196*SkubiScale), x+(54*SkubiScale), y+(-204*SkubiScale));

            txLine(x+(34*SkubiScale), y+(-173*SkubiScale), x+(30*SkubiScale), y+(-198*SkubiScale));
            txLine(x+(30*SkubiScale), y+(-198*SkubiScale), x+(54*SkubiScale), y+(-233*SkubiScale));

            txLine(x+(46*SkubiScale), y+(-222*SkubiScale), x+(40*SkubiScale), y+(-238*SkubiScale));
            txLine(x+(40*SkubiScale), y+(-238*SkubiScale), x+(40*SkubiScale), y+(-263*SkubiScale));
            txLine(x+(40*SkubiScale), y+(-263*SkubiScale), x+(34*SkubiScale), y+(-270*SkubiScale));
            txLine(x+(34*SkubiScale), y+(-270*SkubiScale), x+(34*SkubiScale), y+(-285*SkubiScale));
            txLine(x+(34*SkubiScale), y+(-285*SkubiScale), x+(46*SkubiScale), y+(-299*SkubiScale));
            txLine(x+(46*SkubiScale), y+(-299*SkubiScale), x+(59*SkubiScale), y+(-305*SkubiScale));
            txLine(x+(59*SkubiScale), y+(-305*SkubiScale), x+(66*SkubiScale), y+(-302*SkubiScale));
            txLine(x+(66*SkubiScale), y+(-302*SkubiScale), x+(66*SkubiScale), y+(-285*SkubiScale));
            txLine(x+(66*SkubiScale), y+(-285*SkubiScale), x+(79*SkubiScale), y+(-281*SkubiScale));
            txLine(x+(79*SkubiScale), y+(-281*SkubiScale), x+(87*SkubiScale), y+(-267*SkubiScale));
            txLine(x+(87*SkubiScale), y+(-267*SkubiScale), x+(99*SkubiScale), y+(-272*SkubiScale));
            txLine(x+(99*SkubiScale), y+(-272*SkubiScale), x+(107*SkubiScale), y+(-272*SkubiScale));
            txLine(x+(107*SkubiScale), y+(-272*SkubiScale), x+(125*SkubiScale), y+(-269*SkubiScale));
            txLine(x+(125*SkubiScale), y+(-269*SkubiScale), x+(122*SkubiScale), y+(-269*SkubiScale));
            txLine(x+(122*SkubiScale), y+(-269*SkubiScale), x+(153*SkubiScale), y+(-306*SkubiScale));
            txLine(x+(153*SkubiScale), y+(-306*SkubiScale), x+(175*SkubiScale), y+(-309*SkubiScale));
            txLine(x+(175*SkubiScale), y+(-309*SkubiScale), x+(186*SkubiScale), y+(-296*SkubiScale));
            txLine(x+(186*SkubiScale), y+(-296*SkubiScale), x+(186*SkubiScale), y+(-268*SkubiScale));
            txLine(x+(186*SkubiScale), y+(-268*SkubiScale), x+(178*SkubiScale), y+(-262*SkubiScale));
            txLine(x+(178*SkubiScale), y+(-262*SkubiScale), x+(170*SkubiScale), y+(-273*SkubiScale));
            txLine(x+(170*SkubiScale), y+(-273*SkubiScale), x+(170*SkubiScale), y+(-294*SkubiScale));
            txLine(x+(170*SkubiScale), y+(-294*SkubiScale), x+(158*SkubiScale), y+(-283*SkubiScale));
            txLine(x+(158*SkubiScale), y+(-283*SkubiScale), x+(153*SkubiScale), y+(-270*SkubiScale));

            txLine(x+(153*SkubiScale), y+(-274*SkubiScale), x+(170*SkubiScale), y+(-281*SkubiScale));
            txLine(x+(170*SkubiScale), y+(-281*SkubiScale), x+(170*SkubiScale), y+(-254*SkubiScale));
            txLine(x+(170*SkubiScale), y+(-254*SkubiScale), x+(166*SkubiScale), y+(-249*SkubiScale));
            txLine(x+(166*SkubiScale), y+(-249*SkubiScale), x+(163*SkubiScale), y+(-249*SkubiScale));
            txLine(x+(163*SkubiScale), y+(-249*SkubiScale), x+(158*SkubiScale), y+(-251*SkubiScale));

            txLine(x+(26*SkubiScale), y+(-103*SkubiScale), x+(34*SkubiScale), y+(-101*SkubiScale));
            txLine(x+(34*SkubiScale), y+(-101*SkubiScale), x+(57*SkubiScale), y+(-106*SkubiScale));
            txLine(x+(57*SkubiScale), y+(-106*SkubiScale), x+(67*SkubiScale), y+(-109*SkubiScale));
            txLine(x+(67*SkubiScale), y+(-109*SkubiScale), x+(75*SkubiScale), y+(-114*SkubiScale));
            txLine(x+(75*SkubiScale), y+(-114*SkubiScale), x+(80*SkubiScale), y+(-119*SkubiScale));

            //Губа
            txLine(x+(80*SkubiScale), y+(-119*SkubiScale), x+(86*SkubiScale), y+(-98*SkubiScale));
            txLine(x+(86*SkubiScale), y+(-98*SkubiScale), x+(115*SkubiScale), y+(-101*SkubiScale));
            txLine(x+(115*SkubiScale), y+(-101*SkubiScale), x+(138*SkubiScale), y+(-114*SkubiScale));
            txLine(x+(138*SkubiScale), y+(-114*SkubiScale), x+(157*SkubiScale), y+(-133*SkubiScale));
            txLine(x+(157*SkubiScale), y+(-133*SkubiScale), x+(166*SkubiScale), y+(-154*SkubiScale));
            txLine(x+(166*SkubiScale), y+(-154*SkubiScale), x+(163*SkubiScale), y+(-175*SkubiScale));
            txLine(x+(163*SkubiScale), y+(-175*SkubiScale), x+(144*SkubiScale), y+(-189*SkubiScale));
            txLine(x+(144*SkubiScale), y+(-189*SkubiScale), x+(157*SkubiScale), y+(-199*SkubiScale));
            txLine(x+(157*SkubiScale), y+(-199*SkubiScale), x+(159*SkubiScale), y+(-213*SkubiScale));
            txLine(x+(159*SkubiScale), y+(-213*SkubiScale), x+(154*SkubiScale), y+(-218*SkubiScale));

            txLine(x+(150*SkubiScale), y+(-215*SkubiScale), x+(158*SkubiScale), y+(-223*SkubiScale));

            if (SkubiEyes)
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

                txSetColor(SkubiStrokePanelColor, 2);
                txLine(x+(116*SkubiScale), y+(-213*SkubiScale), x+(121*SkubiScale), y+(-214*SkubiScale));
                txLine(x+(121*SkubiScale), y+(-214*SkubiScale), x+(127*SkubiScale), y+(-222*SkubiScale));
                txLine(x+(127*SkubiScale), y+(-222*SkubiScale), x+(127*SkubiScale), y+(-231*SkubiScale));
                txLine(x+(127*SkubiScale), y+(-231*SkubiScale), x+(123*SkubiScale), y+(-239*SkubiScale));
                txLine(x+(123*SkubiScale), y+(-239*SkubiScale), x+(116*SkubiScale), y+(-244*SkubiScale));
                txLine(x+(116*SkubiScale), y+(-244*SkubiScale), x+(102*SkubiScale), y+(-239*SkubiScale));
                txLine(x+(102*SkubiScale), y+(-239*SkubiScale), x+(102*SkubiScale), y+(-229*SkubiScale));


                txLine(x+(96*SkubiScale), y+(-226*SkubiScale), x+(92*SkubiScale), y+(-231*SkubiScale));
                txLine(x+(92*SkubiScale), y+(-231*SkubiScale), x+(83*SkubiScale), y+(-231*SkubiScale));
                txLine(x+(83*SkubiScale), y+(-231*SkubiScale), x+(77*SkubiScale), y+(-228*SkubiScale));
                txLine(x+(77*SkubiScale), y+(-228*SkubiScale), x+(72*SkubiScale), y+(-220*SkubiScale));
                txLine(x+(72*SkubiScale), y+(-220*SkubiScale), x+(70*SkubiScale), y+(-214*SkubiScale));
                txLine(x+(70*SkubiScale), y+(-214*SkubiScale), x+(70*SkubiScale), y+(-206*SkubiScale));
                txLine(x+(70*SkubiScale), y+(-206*SkubiScale), x+(73*SkubiScale), y+(-201*SkubiScale));
                txLine(x+(73*SkubiScale), y+(-201*SkubiScale), x+(80*SkubiScale), y+(-200*SkubiScale));
                txLine(x+(80*SkubiScale), y+(-200*SkubiScale), x+(85*SkubiScale), y+(-202*SkubiScale));

                txSetColor(SkubiStrokePanelColor, 5);
                txLine(x+(72*SkubiScale), y+(-247*SkubiScale), x+(85*SkubiScale), y+(-262*SkubiScale));
                txLine(x+(85*SkubiScale), y+(-262*SkubiScale), x+(93*SkubiScale), y+(-258*SkubiScale));

                txLine(x+(107*SkubiScale), y+(-257*SkubiScale), x+(117*SkubiScale), y+(-263*SkubiScale));
                txLine(x+(117*SkubiScale), y+(-263*SkubiScale), x+(134*SkubiScale), y+(-257*SkubiScale));

                txSetColor(SkubiStrokePanelColor, 2);
                txLine(x+(83*SkubiScale), y+(-196*SkubiScale), x+(90*SkubiScale), y+(-200*SkubiScale));
                txLine(x+(90*SkubiScale), y+(-200*SkubiScale), x+(94*SkubiScale), y+(-208*SkubiScale));

                txLine(x+(107*SkubiScale), y+(-214*SkubiScale), x+(117*SkubiScale), y+(-207*SkubiScale));
                txLine(x+(117*SkubiScale), y+(-207*SkubiScale), x+(127*SkubiScale), y+(-214*SkubiScale));

                txLine(x+(72*SkubiScale), y+(-230*SkubiScale), x+(83*SkubiScale), y+(-238*SkubiScale));
                txLine(x+(83*SkubiScale), y+(-238*SkubiScale), x+(92*SkubiScale), y+(-236*SkubiScale));

                txLine(x+(99*SkubiScale), y+(-241*SkubiScale), x+(103*SkubiScale), y+(-247*SkubiScale));
                txLine(x+(103*SkubiScale), y+(-247*SkubiScale), x+(116*SkubiScale), y+(-249*SkubiScale));
            }

            if (SkubyMoles)
            {
                txSetColor(SkubiStrokePanelColor, 2);
                txSetFillColor(SkubiStrokePanelColor);
                txCircle(x+(51*SkubiScale), y+(-139*SkubiScale), 2*SkubiScale);
                txCircle(x+(45*SkubiScale), y+(-129*SkubiScale), 3*SkubiScale);
                txCircle(x+(57*SkubiScale), y+(-127*SkubiScale), 2*SkubiScale);

                txCircle(x+(117*SkubiScale), y+(-125*SkubiScale), 2*SkubiScale);
                txCircle(x+(123*SkubiScale), y+(-137*SkubiScale), 3*SkubiScale);

                txCircle(x+(56*SkubiScale), y+(-74*SkubiScale), 2*SkubiScale);
                txCircle(x+(51*SkubiScale), y+(-68*SkubiScale), 2*SkubiScale);
            }

            txSetColor(SkubiStrokePanelColor, 2);
            txLine(x+(42*SkubiScale), y+(-292*SkubiScale), x+(42*SkubiScale), y+(-277*SkubiScale));
            txLine(x+(42*SkubiScale), y+(-277*SkubiScale), x+(40*SkubiScale), y+(-263*SkubiScale));
            txLine(x+(40*SkubiScale), y+(-263*SkubiScale), x+(49*SkubiScale), y+(-284*SkubiScale));
            txLine(x+(49*SkubiScale), y+(-284*SkubiScale), x+(61*SkubiScale), y+(-303*SkubiScale));

            txSetFillColor(SkubiStrokePanelColor);
            txFloodFill(x+(94*SkubiScale), y+(-166*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
            txSetFillColor(SkubiSkinColor);
            txFloodFill(x+(94*SkubiScale), y+(-26*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
            txFloodFill(x+(86*SkubiScale), y+(-131*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
            txFloodFill(x+(48*SkubiScale), y+(-292*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
            txFloodFill(x+(39*SkubiScale), y+(-276*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
            txSetFillColor(SkubiCollarColor);
            txFloodFill(x+(26*SkubiScale), y+(12*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
            txFloodFill(x+(74*SkubiScale), y+(38*SkubiScale), SkubiStrokePanelColor, FLOODFILLBORDER);
    }

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Pa
//! @brief   Отрисовка персонажа ,,Прапор" - герой мультфильма «Пингвины Мадагаскара».
//!
//! @image html Image/Penguin.png
//!
//! @param   x   Х-координата точки
//! @param   y 	Y-координата точки
//! @param   penguinHand 	Наличие рук у персонажа (0 - Нет рук, 1 - Правая рука, 2 - Левая рука, 3 - Обе руки)
//! @param   penguinLeg		Наличие ног у персонажа (0 - Нет ног, 1 - Правая нога, 2 - Левая нога, 3 - Обе ноги)
//! @param   penguinScale	Размер персонажа (1 - Стандартный размер, 2 - В 2 раза больше стандартного размера и т.д.)
//! @param   penguinRoth	Наличие рта у персонажа (0 - Нет рта, 1 - Есть рот)
//! @param   penguinEyes	Наличие глаз у персонажа (0 - Нет глаз, 1 - Есть глаза)
//! @param   penguinEyesColor	Цвет глаз у персонажа 
//! @param   penguinLegsColor	Цвет ног у персонажа 
//! @param   penguinBackColor	Цвет спины у персонажа 
//! @param   penguinBallyColor Цвет пузика у персонажа)))
//!
//! @warning Если цвета разных частей тела совпадают, <del>может произойти ядерный коллапс</del> могут наблюдаться серъёзные графические баги.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @note    Для использования функции нужно создать холст из TXLib.
//!
//! Пример использования функции смотрите в @ref Tutor "примере реализации".
//}----------------------------------------------------------------------------------------------------------------
	
	void drawPenguin(int x, int y, int penguinHand, int penguinLeg, int penguinScale, bool penguinRoth, int penguinEyes, COLORREF penguinEyesColor, COLORREF penguinLegsColor, COLORREF penguinBackColor, COLORREF penguinBallyColor)
    {
        //Пингвин
            if (penguinLeg == 1)
            {
                //Правая нога
                POINT PenguinRightLeg [19] = {{x+(18*penguinScale), y+(230*penguinScale)}, {x+(26*penguinScale), y+(233*penguinScale)}, {x+(35*penguinScale), y+(235*penguinScale)}, {x+(38*penguinScale), y+(242*penguinScale)}, {x+(38*penguinScale), y+(247*penguinScale)}, {x+(37*penguinScale), y+(250*penguinScale)}, {x+(33*penguinScale), y+(251*penguinScale)}, {x+(29*penguinScale), y+(251*penguinScale)}, {x+(27*penguinScale), y+(247*penguinScale)}, {x+(23*penguinScale), y+(247*penguinScale)}, {x+(22*penguinScale), y+(248*penguinScale)}, {x+(3*penguinScale), y+(250*penguinScale)}, {x+(3*penguinScale), y+(246*penguinScale)}, {x+(-11*penguinScale), y+(246*penguinScale)}, {x+(-9*penguinScale), y+(243*penguinScale)}, {x+(-3*penguinScale), y+(241*penguinScale)}, {x+(5*penguinScale), y+(239*penguinScale)}, {x+(11*penguinScale), y+(238*penguinScale)}, {x+(15*penguinScale), y+(237*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinLegsColor);
                txPolygon(PenguinRightLeg, 19);

                txSetColor(BLACK);
                txLine(x+(23*penguinScale), y+(247*penguinScale), x+(37*penguinScale), y+(247*penguinScale));

                txLine(x+(8*penguinScale), y+(239*penguinScale), x+(11*penguinScale), y+(240*penguinScale));
                txLine(x+(11*penguinScale), y+(240*penguinScale), x+(16*penguinScale), y+(241*penguinScale));
                txLine(x+(16*penguinScale), y+(241*penguinScale), x+(21*penguinScale), y+(243*penguinScale));
                txLine(x+(21*penguinScale), y+(243*penguinScale), x+(21*penguinScale), y+(248*penguinScale));

                txLine(x+(11*penguinScale), y+(240*penguinScale), x+(5*penguinScale), y+(243*penguinScale));
                txLine(x+(5*penguinScale), y+(243*penguinScale), x+(3*penguinScale), y+(246*penguinScale));
            }

            if (penguinLeg == 2)
            {
                //Левая нога
                POINT PenguinLeftLeg [32] = {{x+(88*penguinScale), y+(235*penguinScale)}, {x+(93*penguinScale), y+(235*penguinScale)}, {x+(103*penguinScale), y+(233*penguinScale)}, {x+(107*penguinScale), y+(232*penguinScale)}, {x+(107*penguinScale), y+(239*penguinScale)}, {x+(108*penguinScale), y+(240*penguinScale)}, {x+(113*penguinScale), y+(242*penguinScale)}, {x+(117*penguinScale), y+(244*penguinScale)}, {x+(122*penguinScale), y+(246*penguinScale)}, {x+(129*penguinScale), y+(248*penguinScale)}, {x+(133*penguinScale), y+(251*penguinScale)}, {x+(133*penguinScale), y+(254*penguinScale)}, {x+(129*penguinScale), y+(254*penguinScale)}, {x+(123*penguinScale), y+(253*penguinScale)}, {x+(123*penguinScale), y+(252*penguinScale)}, {x+(117*penguinScale), y+(252*penguinScale)}, {x+(116*penguinScale), y+(254*penguinScale)}, {x+(116*penguinScale), y+(256*penguinScale)}, {x+(110*penguinScale), y+(255*penguinScale)}, {x+(105*penguinScale), y+(253*penguinScale)}, {x+(103*penguinScale), y+(252*penguinScale)}, {x+(98*penguinScale), y+(252*penguinScale)}, {x+(97*penguinScale), y+(251*penguinScale)}, {x+(91*penguinScale), y+(252*penguinScale)}, {x+(89*penguinScale), y+(254*penguinScale)}, {x+(87*penguinScale), y+(254*penguinScale)}, {x+(85*penguinScale), y+(252*penguinScale)}, {x+(82*penguinScale), y+(250*penguinScale)}, {x+(82*penguinScale), y+(248*penguinScale)}, {x+(84*penguinScale), y+(246*penguinScale)}, {x+(86*penguinScale), y+(244*penguinScale)}, {x+(88*penguinScale), y+(240*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinLegsColor);
                txPolygon(PenguinLeftLeg, 32);

                txSetColor(BLACK);
                txLine(x+(103*penguinScale), y+(252*penguinScale), x+(108*penguinScale), y+(247*penguinScale));
                txLine(x+(108*penguinScale), y+(247*penguinScale), x+(113*penguinScale), y+(247*penguinScale));
                txLine(x+(113*penguinScale), y+(247*penguinScale), x+(116*penguinScale), y+(250*penguinScale));
                txLine(x+(116*penguinScale), y+(250*penguinScale), x+(117*penguinScale), y+(252*penguinScale));

                txLine(x+(123*penguinScale), y+(252*penguinScale), x+(123*penguinScale), y+(251*penguinScale));
                txLine(x+(123*penguinScale), y+(251*penguinScale), x+(126*penguinScale), y+(248*penguinScale));
                txLine(x+(126*penguinScale), y+(248*penguinScale), x+(129*penguinScale), y+(248*penguinScale));
                txLine(x+(129*penguinScale), y+(248*penguinScale), x+(133*penguinScale), y+(251*penguinScale));
            }

            if (penguinLeg == 3)
            {
                //Правая нога
                POINT PenguinRightLeg [19] = {{x+(18*penguinScale), y+(230*penguinScale)}, {x+(26*penguinScale), y+(233*penguinScale)}, {x+(35*penguinScale), y+(235*penguinScale)}, {x+(38*penguinScale), y+(242*penguinScale)}, {x+(38*penguinScale), y+(247*penguinScale)}, {x+(37*penguinScale), y+(250*penguinScale)}, {x+(33*penguinScale), y+(251*penguinScale)}, {x+(29*penguinScale), y+(251*penguinScale)}, {x+(27*penguinScale), y+(247*penguinScale)}, {x+(23*penguinScale), y+(247*penguinScale)}, {x+(22*penguinScale), y+(248*penguinScale)}, {x+(3*penguinScale), y+(250*penguinScale)}, {x+(3*penguinScale), y+(246*penguinScale)}, {x+(-11*penguinScale), y+(246*penguinScale)}, {x+(-9*penguinScale), y+(243*penguinScale)}, {x+(-3*penguinScale), y+(241*penguinScale)}, {x+(5*penguinScale), y+(239*penguinScale)}, {x+(11*penguinScale), y+(238*penguinScale)}, {x+(15*penguinScale), y+(237*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinLegsColor);
                txPolygon(PenguinRightLeg, 19);

                txSetColor(BLACK);
                txLine(x+(23*penguinScale), y+(247*penguinScale), x+(37*penguinScale), y+(247*penguinScale));

                txLine(x+(8*penguinScale), y+(239*penguinScale), x+(11*penguinScale), y+(240*penguinScale));
                txLine(x+(11*penguinScale), y+(240*penguinScale), x+(16*penguinScale), y+(241*penguinScale));
                txLine(x+(16*penguinScale), y+(241*penguinScale), x+(21*penguinScale), y+(243*penguinScale));
                txLine(x+(21*penguinScale), y+(243*penguinScale), x+(21*penguinScale), y+(248*penguinScale));

                txLine(x+(11*penguinScale), y+(240*penguinScale), x+(5*penguinScale), y+(243*penguinScale));
                txLine(x+(5*penguinScale), y+(243*penguinScale), x+(3*penguinScale), y+(246*penguinScale));

                //Левая нога
                POINT PenguinLeftLeg [32] = {{x+(88*penguinScale), y+(235*penguinScale)}, {x+(93*penguinScale), y+(235*penguinScale)}, {x+(103*penguinScale), y+(233*penguinScale)}, {x+(107*penguinScale), y+(232*penguinScale)}, {x+(107*penguinScale), y+(239*penguinScale)}, {x+(108*penguinScale), y+(240*penguinScale)}, {x+(113*penguinScale), y+(242*penguinScale)}, {x+(117*penguinScale), y+(244*penguinScale)}, {x+(122*penguinScale), y+(246*penguinScale)}, {x+(129*penguinScale), y+(248*penguinScale)}, {x+(133*penguinScale), y+(251*penguinScale)}, {x+(133*penguinScale), y+(254*penguinScale)}, {x+(129*penguinScale), y+(254*penguinScale)}, {x+(123*penguinScale), y+(253*penguinScale)}, {x+(123*penguinScale), y+(252*penguinScale)}, {x+(117*penguinScale), y+(252*penguinScale)}, {x+(116*penguinScale), y+(254*penguinScale)}, {x+(116*penguinScale), y+(256*penguinScale)}, {x+(110*penguinScale), y+(255*penguinScale)}, {x+(105*penguinScale), y+(253*penguinScale)}, {x+(103*penguinScale), y+(252*penguinScale)}, {x+(98*penguinScale), y+(252*penguinScale)}, {x+(97*penguinScale), y+(251*penguinScale)}, {x+(91*penguinScale), y+(252*penguinScale)}, {x+(89*penguinScale), y+(254*penguinScale)}, {x+(87*penguinScale), y+(254*penguinScale)}, {x+(85*penguinScale), y+(252*penguinScale)}, {x+(82*penguinScale), y+(250*penguinScale)}, {x+(82*penguinScale), y+(248*penguinScale)}, {x+(84*penguinScale), y+(246*penguinScale)}, {x+(86*penguinScale), y+(244*penguinScale)}, {x+(88*penguinScale), y+(240*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinLegsColor);
                txPolygon(PenguinLeftLeg, 32);
                txSetColor(BLACK);
                txLine(x+(103*penguinScale), y+(252*penguinScale), x+(108*penguinScale), y+(247*penguinScale));
                txLine(x+(108*penguinScale), y+(247*penguinScale), x+(113*penguinScale), y+(247*penguinScale));
                txLine(x+(113*penguinScale), y+(247*penguinScale), x+(116*penguinScale), y+(250*penguinScale));
                txLine(x+(116*penguinScale), y+(250*penguinScale), x+(117*penguinScale), y+(252*penguinScale));

                txLine(x+(123*penguinScale), y+(252*penguinScale), x+(123*penguinScale), y+(251*penguinScale));
                txLine(x+(123*penguinScale), y+(251*penguinScale), x+(126*penguinScale), y+(248*penguinScale));
                txLine(x+(126*penguinScale), y+(248*penguinScale), x+(129*penguinScale), y+(248*penguinScale));
                txLine(x+(129*penguinScale), y+(248*penguinScale), x+(133*penguinScale), y+(251*penguinScale));
            }

            if (penguinHand == 1)
            {
                //Правая рука
                POINT PenguinRightArm [34] = {{x+(-7*penguinScale), y+(52*penguinScale)}, {x+(-7*penguinScale), y+(77*penguinScale)}, {x+(-9*penguinScale), y+(84*penguinScale)}, {x+(-12*penguinScale), y+(93*penguinScale)}, {x+(-15*penguinScale), y+(101*penguinScale)}, {x+(-18*penguinScale), y+(113*penguinScale)}, {x+(-20*penguinScale), y+(120*penguinScale)}, {x+(-23*penguinScale), y+(129*penguinScale)}, {x+(-25*penguinScale), y+(138*penguinScale)}, {x+(-27*penguinScale), y+(147*penguinScale)}, {x+(-29*penguinScale), y+(156*penguinScale)}, {x+(-31*penguinScale), y+(164*penguinScale)}, {x+(-34*penguinScale), y+(174*penguinScale)}, {x+(-37*penguinScale), y+(185*penguinScale)}, {x+(-39*penguinScale), y+(192*penguinScale)}, {x+(-40*penguinScale), y+(198*penguinScale)}, {x+(-37*penguinScale), y+(193*penguinScale)}, {x+(-34*penguinScale), y+(186*penguinScale)}, {x+(-30*penguinScale), y+(178*penguinScale)}, {x+(-27*penguinScale), y+(171*penguinScale)}, {x+(-25*penguinScale), y+(165*penguinScale)}, {x+(-22*penguinScale), y+(157*penguinScale)}, {x+(-22*penguinScale), y+(150*penguinScale)}, {x+(-21*penguinScale), y+(142*penguinScale)}, {x+(-20*penguinScale), y+(134*penguinScale)}, {x+(-17*penguinScale), y+(126*penguinScale)}, {x+(-14*penguinScale), y+(118*penguinScale)}, {x+(-12*penguinScale), y+(113*penguinScale)}, {x+(-9*penguinScale), y+(107*penguinScale)}, {x+(-6*penguinScale), y+(102*penguinScale)}, {x+(-3*penguinScale), y+(95*penguinScale)}, {x+(-3*penguinScale), y+(71*penguinScale)}, {x+(-4*penguinScale), y+(62*penguinScale)}, {x+(-5*penguinScale), y+(58*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinBackColor);
                txPolygon(PenguinRightArm, 34);
            }

            if (penguinHand == 2)
            {
                //Левая рука
                POINT PenguinLeftArm [66] = {{x+(117*penguinScale), y+(17*penguinScale)}, {x+(118*penguinScale), y+(17*penguinScale)}, {x+(122*penguinScale), y+(19*penguinScale)}, {x+(125*penguinScale), y+(21*penguinScale)}, {x+(129*penguinScale), y+(23*penguinScale)}, {x+(134*penguinScale), y+(26*penguinScale)}, {x+(136*penguinScale), y+(27*penguinScale)}, {x+(139*penguinScale), y+(30*penguinScale)}, {x+(148*penguinScale), y+(38*penguinScale)}, {x+(155*penguinScale), y+(44*penguinScale)}, {x+(162*penguinScale), y+(58*penguinScale)}, {x+(166*penguinScale), y+(66*penguinScale)}, {x+(166*penguinScale), y+(86*penguinScale)}, {x+(162*penguinScale), y+(92*penguinScale)}, {x+(160*penguinScale), y+(97*penguinScale)}, {x+(140*penguinScale), y+(97*penguinScale)}, {x+(127*penguinScale), y+(87*penguinScale)}, {x+(126*penguinScale), y+(87*penguinScale)}, {x+(127*penguinScale), y+(90*penguinScale)}, {x+(131*penguinScale), y+(100*penguinScale)}, {x+(135*penguinScale), y+(111*penguinScale)}, {x+(139*penguinScale), y+(122*penguinScale)}, {x+(141*penguinScale), y+(134*penguinScale)}, {x+(141*penguinScale), y+(137*penguinScale)}, {x+(139*penguinScale), y+(133*penguinScale)}, {x+(136*penguinScale), y+(122*penguinScale)}, {x+(133*penguinScale), y+(116*penguinScale)}, {x+(127*penguinScale), y+(106*penguinScale)}, {x+(121*penguinScale), y+(96*penguinScale)}, {x+(113*penguinScale), y+(82*penguinScale)}, {x+(100*penguinScale), y+(69*penguinScale)}, {x+(97*penguinScale), y+(65*penguinScale)}, {x+(94*penguinScale), y+(60*penguinScale)}, {x+(89*penguinScale), y+(54*penguinScale)}, {x+(88*penguinScale), y+(47*penguinScale)}, {x+(87*penguinScale), y+(42*penguinScale)}, {x+(86*penguinScale), y+(37*penguinScale)}, {x+(85*penguinScale), y+(31*penguinScale)}, {x+(82*penguinScale), y+(26*penguinScale)}, {x+(79*penguinScale), y+(20*penguinScale)}, {x+(80*penguinScale), y+(17*penguinScale)}, {x+(85*penguinScale), y+(24*penguinScale)}, {x+(89*penguinScale), y+(30*penguinScale)}, {x+(93*penguinScale), y+(35*penguinScale)}, {x+(97*penguinScale), y+(41*penguinScale)}, {x+(101*penguinScale), y+(47*penguinScale)}, {x+(103*penguinScale), y+(48*penguinScale)}, {x+(108*penguinScale), y+(50*penguinScale)}, {x+(112*penguinScale), y+(52*penguinScale)}, {x+(115*penguinScale), y+(54*penguinScale)}, {x+(119*penguinScale), y+(56*penguinScale)}, {x+(122*penguinScale), y+(58*penguinScale)}, {x+(125*penguinScale), y+(60*penguinScale)}, {x+(129*penguinScale), y+(63*penguinScale)}, {x+(132*penguinScale), y+(65*penguinScale)}, {x+(135*penguinScale), y+(67*penguinScale)}, {x+(138*penguinScale), y+(69*penguinScale)}, {x+(140*penguinScale), y+(71*penguinScale)}, {x+(142*penguinScale), y+(71*penguinScale)}, {x+(142*penguinScale), y+(68*penguinScale)}, {x+(141*penguinScale), y+(67*penguinScale)}, {x+(139*penguinScale), y+(64*penguinScale)}, {x+(137*penguinScale), y+(60*penguinScale)}, {x+(123*penguinScale), y+(33*penguinScale)}, {x+(121*penguinScale), y+(28*penguinScale)}, {x+(119*penguinScale), y+(24*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinBackColor);
                txPolygon(PenguinLeftArm, 66);
            }

            if (penguinHand == 3)
            {
                //Правая рука
                POINT PenguinRightArm [34] = {{x+(-7*penguinScale), y+(52*penguinScale)}, {x+(-7*penguinScale), y+(77*penguinScale)}, {x+(-9*penguinScale), y+(84*penguinScale)}, {x+(-12*penguinScale), y+(93*penguinScale)}, {x+(-15*penguinScale), y+(101*penguinScale)}, {x+(-18*penguinScale), y+(113*penguinScale)}, {x+(-20*penguinScale), y+(120*penguinScale)}, {x+(-23*penguinScale), y+(129*penguinScale)}, {x+(-25*penguinScale), y+(138*penguinScale)}, {x+(-27*penguinScale), y+(147*penguinScale)}, {x+(-29*penguinScale), y+(156*penguinScale)}, {x+(-31*penguinScale), y+(164*penguinScale)}, {x+(-34*penguinScale), y+(174*penguinScale)}, {x+(-37*penguinScale), y+(185*penguinScale)}, {x+(-39*penguinScale), y+(192*penguinScale)}, {x+(-40*penguinScale), y+(198*penguinScale)}, {x+(-37*penguinScale), y+(193*penguinScale)}, {x+(-34*penguinScale), y+(186*penguinScale)}, {x+(-30*penguinScale), y+(178*penguinScale)}, {x+(-27*penguinScale), y+(171*penguinScale)}, {x+(-25*penguinScale), y+(165*penguinScale)}, {x+(-22*penguinScale), y+(157*penguinScale)}, {x+(-22*penguinScale), y+(150*penguinScale)}, {x+(-21*penguinScale), y+(142*penguinScale)}, {x+(-20*penguinScale), y+(134*penguinScale)}, {x+(-17*penguinScale), y+(126*penguinScale)}, {x+(-14*penguinScale), y+(118*penguinScale)}, {x+(-12*penguinScale), y+(113*penguinScale)}, {x+(-9*penguinScale), y+(107*penguinScale)}, {x+(-6*penguinScale), y+(102*penguinScale)}, {x+(-3*penguinScale), y+(95*penguinScale)}, {x+(-3*penguinScale), y+(71*penguinScale)}, {x+(-4*penguinScale), y+(62*penguinScale)}, {x+(-5*penguinScale), y+(58*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinBackColor);
                txPolygon(PenguinRightArm, 34);

                //Левая рука
                POINT PenguinLeftArm [66] = {{x+(117*penguinScale), y+(17*penguinScale)}, {x+(118*penguinScale), y+(17*penguinScale)}, {x+(122*penguinScale), y+(19*penguinScale)}, {x+(125*penguinScale), y+(21*penguinScale)}, {x+(129*penguinScale), y+(23*penguinScale)}, {x+(134*penguinScale), y+(26*penguinScale)}, {x+(136*penguinScale), y+(27*penguinScale)}, {x+(139*penguinScale), y+(30*penguinScale)}, {x+(148*penguinScale), y+(38*penguinScale)}, {x+(155*penguinScale), y+(44*penguinScale)}, {x+(162*penguinScale), y+(58*penguinScale)}, {x+(166*penguinScale), y+(66*penguinScale)}, {x+(166*penguinScale), y+(86*penguinScale)}, {x+(162*penguinScale), y+(92*penguinScale)}, {x+(160*penguinScale), y+(97*penguinScale)}, {x+(140*penguinScale), y+(97*penguinScale)}, {x+(127*penguinScale), y+(87*penguinScale)}, {x+(126*penguinScale), y+(87*penguinScale)}, {x+(127*penguinScale), y+(90*penguinScale)}, {x+(131*penguinScale), y+(100*penguinScale)}, {x+(135*penguinScale), y+(111*penguinScale)}, {x+(139*penguinScale), y+(122*penguinScale)}, {x+(141*penguinScale), y+(134*penguinScale)}, {x+(141*penguinScale), y+(137*penguinScale)}, {x+(139*penguinScale), y+(133*penguinScale)}, {x+(136*penguinScale), y+(122*penguinScale)}, {x+(133*penguinScale), y+(116*penguinScale)}, {x+(127*penguinScale), y+(106*penguinScale)}, {x+(121*penguinScale), y+(96*penguinScale)}, {x+(113*penguinScale), y+(82*penguinScale)}, {x+(100*penguinScale), y+(69*penguinScale)}, {x+(97*penguinScale), y+(65*penguinScale)}, {x+(94*penguinScale), y+(60*penguinScale)}, {x+(89*penguinScale), y+(54*penguinScale)}, {x+(88*penguinScale), y+(47*penguinScale)}, {x+(87*penguinScale), y+(42*penguinScale)}, {x+(86*penguinScale), y+(37*penguinScale)}, {x+(85*penguinScale), y+(31*penguinScale)}, {x+(82*penguinScale), y+(26*penguinScale)}, {x+(79*penguinScale), y+(20*penguinScale)}, {x+(80*penguinScale), y+(17*penguinScale)}, {x+(85*penguinScale), y+(24*penguinScale)}, {x+(89*penguinScale), y+(30*penguinScale)}, {x+(93*penguinScale), y+(35*penguinScale)}, {x+(97*penguinScale), y+(41*penguinScale)}, {x+(101*penguinScale), y+(47*penguinScale)}, {x+(103*penguinScale), y+(48*penguinScale)}, {x+(108*penguinScale), y+(50*penguinScale)}, {x+(112*penguinScale), y+(52*penguinScale)}, {x+(115*penguinScale), y+(54*penguinScale)}, {x+(119*penguinScale), y+(56*penguinScale)}, {x+(122*penguinScale), y+(58*penguinScale)}, {x+(125*penguinScale), y+(60*penguinScale)}, {x+(129*penguinScale), y+(63*penguinScale)}, {x+(132*penguinScale), y+(65*penguinScale)}, {x+(135*penguinScale), y+(67*penguinScale)}, {x+(138*penguinScale), y+(69*penguinScale)}, {x+(140*penguinScale), y+(71*penguinScale)}, {x+(142*penguinScale), y+(71*penguinScale)}, {x+(142*penguinScale), y+(68*penguinScale)}, {x+(141*penguinScale), y+(67*penguinScale)}, {x+(139*penguinScale), y+(64*penguinScale)}, {x+(137*penguinScale), y+(60*penguinScale)}, {x+(123*penguinScale), y+(33*penguinScale)}, {x+(121*penguinScale), y+(28*penguinScale)}, {x+(119*penguinScale), y+(24*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinBackColor);
                txPolygon(PenguinLeftArm, 66);
            }

            //Тело
            POINT PenguinBody [87] = {{x+(47*penguinScale), y+(237*penguinScale)}, {x+(75*penguinScale), y+(237*penguinScale)}, {x+(93*penguinScale), y+(235*penguinScale)}, {x+(103*penguinScale), y+(233*penguinScale)}, {x+(107*penguinScale), y+(232*penguinScale)}, {x+(108*penguinScale), y+(231*penguinScale)}, {x+(112*penguinScale), y+(228*penguinScale)}, {x+(117*penguinScale), y+(224*penguinScale)}, {x+(121*penguinScale), y+(219*penguinScale)}, {x+(126*penguinScale), y+(211*penguinScale)}, {x+(130*penguinScale), y+(203*penguinScale)}, {x+(135*penguinScale), y+(191*penguinScale)}, {x+(139*penguinScale), y+(177*penguinScale)}, {x+(142*penguinScale), y+(168*penguinScale)}, {x+(142*penguinScale), y+(141*penguinScale)}, {x+(141*penguinScale), y+(137*penguinScale)}, {x+(139*penguinScale), y+(133*penguinScale)}, {x+(136*penguinScale), y+(122*penguinScale)}, {x+(133*penguinScale), y+(116*penguinScale)}, {x+(127*penguinScale), y+(106*penguinScale)}, {x+(121*penguinScale), y+(96*penguinScale)}, {x+(113*penguinScale), y+(82*penguinScale)}, {x+(100*penguinScale), y+(69*penguinScale)}, {x+(97*penguinScale), y+(65*penguinScale)}, {x+(94*penguinScale), y+(60*penguinScale)}, {x+(89*penguinScale), y+(54*penguinScale)}, {x+(88*penguinScale), y+(47*penguinScale)}, {x+(87*penguinScale), y+(42*penguinScale)}, {x+(86*penguinScale), y+(37*penguinScale)}, {x+(85*penguinScale), y+(31*penguinScale)}, {x+(82*penguinScale), y+(26*penguinScale)}, {x+(79*penguinScale), y+(20*penguinScale)}, {x+(80*penguinScale), y+(17*penguinScale)}, {x+(77*penguinScale), y+(13*penguinScale)}, {x+(73*penguinScale), y+(8*penguinScale)}, {x+(70*penguinScale), y+(3*penguinScale)}, {x+(67*penguinScale), y+(-1*penguinScale)}, {x+(63*penguinScale), y+(-6*penguinScale)}, {x+(58*penguinScale), y+(-10*penguinScale)}, {x+(53*penguinScale), y+(-14*penguinScale)}, {x+(49*penguinScale), y+(-16*penguinScale)}, {x+(45*penguinScale), y+(-19*penguinScale)}, {x+(43*penguinScale), y+(-21*penguinScale)}, {x+(38*penguinScale), y+(-22*penguinScale)}, {x+(27*penguinScale), y+(-22*penguinScale)}, {x+(20*penguinScale), y+(-21*penguinScale)}, {x+(15*penguinScale), y+(-19*penguinScale)}, {x+(11*penguinScale), y+(-17*penguinScale)}, {x+(6*penguinScale), y+(-15*penguinScale)}, {x+(2*penguinScale), y+(-12*penguinScale)}, {x+(-1*penguinScale), y+(-9*penguinScale)}, {x+(-4*penguinScale), y+(-6*penguinScale)}, {x+(-6*penguinScale), y+(-2*penguinScale)}, {x+(-8*penguinScale), y+(1*penguinScale)}, {x+(-10*penguinScale), y+(5*penguinScale)}, {x+(-11*penguinScale), y+(9*penguinScale)}, {x+(-11*penguinScale), y+(35*penguinScale)}, {x+(-9*penguinScale), y+(44*penguinScale)}, {x+(-7*penguinScale), y+(49*penguinScale)}, {x+(-7*penguinScale), y+(52*penguinScale)}, {x+(-5*penguinScale), y+(58*penguinScale)}, {x+(-4*penguinScale), y+(62*penguinScale)}, {x+(-3*penguinScale), y+(71*penguinScale)}, {x+(-3*penguinScale), y+(95*penguinScale)}, {x+(-6*penguinScale), y+(102*penguinScale)}, {x+(-9*penguinScale), y+(107*penguinScale)}, {x+(-12*penguinScale), y+(113*penguinScale)}, {x+(-14*penguinScale), y+(118*penguinScale)}, {x+(-17*penguinScale), y+(126*penguinScale)}, {x+(-20*penguinScale), y+(134*penguinScale)}, {x+(-21*penguinScale), y+(142*penguinScale)}, {x+(-22*penguinScale), y+(150*penguinScale)}, {x+(-22*penguinScale), y+(157*penguinScale)}, {x+(-21*penguinScale), y+(168*penguinScale)}, {x+(-19*penguinScale), y+(179*penguinScale)}, {x+(-17*penguinScale), y+(184*penguinScale)}, {x+(-15*penguinScale), y+(190*penguinScale)}, {x+(-13*penguinScale), y+(196*penguinScale)}, {x+(-11*penguinScale), y+(201*penguinScale)}, {x+(-6*penguinScale), y+(209*penguinScale)}, {x+(-3*penguinScale), y+(214*penguinScale)}, {x+(3*penguinScale), y+(220*penguinScale)}, {x+(8*penguinScale), y+(224*penguinScale)}, {x+(14*penguinScale), y+(228*penguinScale)}, {x+(18*penguinScale), y+(230*penguinScale)}, {x+(26*penguinScale), y+(233*penguinScale)}, {x+(35*penguinScale), y+(235*penguinScale)}, };
            txSetColor(BLACK);
            txSetFillColor(penguinBallyColor);
            txPolygon(PenguinBody, 87);

            //Голова
            txSetColor(BLACK);
            txLine(x+(-11*penguinScale), y+(30*penguinScale), x+(-9*penguinScale), y+(16*penguinScale));
            txLine(x+(-9*penguinScale), y+(16*penguinScale), x+(-8*penguinScale), y+(10*penguinScale));
            txLine(x+(-8*penguinScale), y+(10*penguinScale), x+(-6*penguinScale), y+(5*penguinScale));
            txLine(x+(-6*penguinScale), y+(5*penguinScale), x+(-2*penguinScale), y+(2*penguinScale));
            txLine(x+(-2*penguinScale), y+(2*penguinScale), x+(0*penguinScale), y+(0*penguinScale));
            txLine(x+(0*penguinScale), y+(0*penguinScale), x+(18*penguinScale), y+(0*penguinScale));
            txLine(x+(18*penguinScale), y+(0*penguinScale), x+(21*penguinScale), y+(-5*penguinScale));
            txLine(x+(21*penguinScale), y+(-5*penguinScale), x+(23*penguinScale), y+(-8*penguinScale));
            txLine(x+(23*penguinScale), y+(-8*penguinScale), x+(32*penguinScale), y+(-17*penguinScale));
            txLine(x+(32*penguinScale), y+(-17*penguinScale), x+(41*penguinScale), y+(-17*penguinScale));
            txLine(x+(41*penguinScale), y+(-17*penguinScale), x+(51*penguinScale), y+(-12*penguinScale));
            txLine(x+(51*penguinScale), y+(-12*penguinScale), x+(59*penguinScale), y+(-4*penguinScale));
            txLine(x+(59*penguinScale), y+(-4*penguinScale), x+(65*penguinScale), y+(-3*penguinScale));

            txSetFillColor(penguinBackColor);
            txFloodFill(x+(12), y+(-7), BLACK, FLOODFILLBORDER);

            if (penguinRoth)
            {
                //Рот
                POINT PenguinRoth [26] = {{x+(-7*penguinScale), y+(37*penguinScale)}, {x+(6*penguinScale), y+(37*penguinScale)}, {x+(13*penguinScale), y+(33*penguinScale)}, {x+(18*penguinScale), y+(30*penguinScale)}, {x+(20*penguinScale), y+(24*penguinScale)}, {x+(24*penguinScale), y+(19*penguinScale)}, {x+(25*penguinScale), y+(18*penguinScale)}, {x+(45*penguinScale), y+(20*penguinScale)}, {x+(52*penguinScale), y+(16*penguinScale)}, {x+(61*penguinScale), y+(7*penguinScale)}, {x+(64*penguinScale), y+(1*penguinScale)}, {x+(65*penguinScale), y+(9*penguinScale)}, {x+(63*penguinScale), y+(14*penguinScale)}, {x+(61*penguinScale), y+(19*penguinScale)}, {x+(60*penguinScale), y+(21*penguinScale)}, {x+(54*penguinScale), y+(26*penguinScale)}, {x+(45*penguinScale), y+(33*penguinScale)}, {x+(42*penguinScale), y+(35*penguinScale)}, {x+(36*penguinScale), y+(36*penguinScale)}, {x+(30*penguinScale), y+(37*penguinScale)}, {x+(22*penguinScale), y+(43*penguinScale)}, {x+(14*penguinScale), y+(43*penguinScale)}, {x+(13*penguinScale), y+(44*penguinScale)}, {x+(0*penguinScale), y+(44*penguinScale)}, {x+(-3*penguinScale), y+(42*penguinScale)}, {x+(-6*penguinScale), y+(40*penguinScale)}, };
                txSetColor(BLACK);
                txSetFillColor(penguinBackColor);
                txPolygon(PenguinRoth, 26);
            }

            if (penguinEyes == 1)
            {
                //Глаза
                txSetFillColor(WHITE);
                txCircle(x+(11*penguinScale), y+(22*penguinScale), 8*penguinScale);
                txSetFillColor(penguinEyesColor);
                txCircle(x+(11*penguinScale), y+(22*penguinScale), 5*penguinScale);
                txSetFillColor(BLACK);
                txCircle(x+(11*penguinScale), y+(22*penguinScale), 2*penguinScale);
            }

            if (penguinEyes == 2)
            {
                txSetFillColor(WHITE);
                txCircle(x+(40*penguinScale), y+(10*penguinScale), 8*penguinScale);
                txSetFillColor(penguinEyesColor);
                txCircle(x+(40*penguinScale), y+(10*penguinScale), 5*penguinScale);
                txSetFillColor(BLACK);
                txCircle(x+(40*penguinScale), y+(10*penguinScale), 2*penguinScale);
            }

            if (penguinEyes == 3)
            {
                //Глаза
                txSetFillColor(WHITE);
                txCircle(x+(11*penguinScale), y+(22*penguinScale), 8*penguinScale);
                txSetFillColor(penguinEyesColor);
                txCircle(x+(11*penguinScale), y+(22*penguinScale), 5*penguinScale);
                txSetFillColor(BLACK);
                txCircle(x+(11*penguinScale), y+(22*penguinScale), 2*penguinScale);

                txSetFillColor(WHITE);
                txCircle(x+(40*penguinScale), y+(10*penguinScale), 8*penguinScale);
                txSetFillColor(penguinEyesColor);
                txCircle(x+(40*penguinScale), y+(10*penguinScale), 5*penguinScale);
                txSetFillColor(BLACK);
                txCircle(x+(40*penguinScale), y+(10*penguinScale), 2*penguinScale);
            }
        }

/*! 	@page Tutor_1st  Movie by CatDev
		@section 	MovieDis 	Описание
		В данном примере реализован мультфильм, с ипользованием всех функций CatDevLib.
	
		@section 	Connect 	Подключение библиотек
		Для работы с CatDevLib необходимо подключить минимум 2 библиотеки: TXLib и саму CatDevLib.
		@code
			#include "TXLib.h"
			#include "CatDevLib.h"
		@endcode
		@note Не забывайте, что для подключения библиотек, они должны находиться в папке с проектом (С файлом .cpp).
	
		@section 	Declaration 	Деклорация функций
		Затем декларируем наши функции мультфильма.
		@code
			void SkubiEyes1(int x, int y, int SkubiScale, bool SkubiEyes, COLORREF SkubiStrokePanelColor, COLORREF SkubiEyesColor);

			void scene1(HDC Fade);
			void scene2(HDC scene2_background);
			void scene3(HDC openDoor, HDC closeDoor, HDC sky);
			void scene4(HDC minutes);
			void scene5(HDC openDoor, HDC sky);
			void scene6(HDC Scene6);
			void scene7(HDC Directed2, HDC Directed3, HDC Directed4);
		@endcode
		
		@section 	Main 	Главная функция программы
		В главной функции программы прописаны вызовы логических функций и загрузка ресурсов для мультфильма.
		@code
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
		@endcode
		
		@section 	NotLikeThis 	Как не стоит поступать
		Здесь показан так называемый костыль. <br> 
		Костыли - некое поделие, призванное оперативно устранить возникшую проблему, невзирая на стилистику в целом и здравый смысл в частности. <br>
		В данном случае, этот "костыль" решает проблему с глазами Скуби-Ду.
		@warning Избегайте "костылей", ведь они нарушают красоту и гармонию программы. <br>
		Нередко случается, что со временем кода "особых случаев", которые обрабатывают "костыли", становится в разы больше чем основной логики. <br>
		<del>Но... Работает - не трогай.</del>
		
		@code
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
		@endcode
		@note Присмотритесь к названию этой функции. Не допускайте такого. <br> 
		<del>Иначе вас будет ожидать отдельный котёл в аду.</del> <br> 
		Названия функций, переменных, констант и т.д должны отражать их смысл.
		
		@section 	Logic	 Логические функции
		В логических функциях прописывается вызовы функций в определённое время с определёнными параметрами.
		@code
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
		@endcode
		
		@section 	ExAll 	Законченный пример
		@code
			#include "TXLib.h"
			#include "CatDevLib.h"

			void SkubiEyes1(int x, int y, int SkubiScale, bool SkubiEyes, COLORREF SkubiStrokePanelColor, COLORREF SkubiEyesColor);

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
		@endcode
*/
	