//==========[ Подключение библиотек ]==========
    #include "Resources\\Libs\\HeRLib.h"
//=============================================

//==========[ Создание холста игры ]==========
    int main()
    {
        txCreateWindow(1296, 720);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);
        txTextCursor(FALSE);
//============================================

//===============[ Переменные ]===============
        int layout = 0;
        int act = 1;
        int money = 250; 
        int actMoney = 0;
        int houseUpgrade = 0; 
        int treesUpgrade = 0;
        int vegetablesUpgrade = 0;
        int smithyUpgradeSelect = 11;
        int houseUpgradeSelect = 1;
        int backgroundX1 = 0;
        int backgroundX2 = 1296;
        int menuStage = 1;
        int mapMove = 0;
        int time = 0;
        int blacksmithFrame = 1;
//============================================
        
//================[ Объекты ]=================
        hrCollector collectorArray[3];
        hrWoodcutter woodcutterArray[3];
        hrKnight knightArray[3];
        hrArcher archerArray[3];
        hrWizard wizardArray[3];
        hrLizard lizardArray[20];

        hrVegetables vegetablesArray[6]; 
        vegetablesArray[0].SetCoordinate(288, 200);
        vegetablesArray[1].SetCoordinate(335, 184);
        vegetablesArray[2].SetCoordinate(380, 195);
        vegetablesArray[3].SetCoordinate(425, 179);
        vegetablesArray[4].SetCoordinate(470, 190);
        vegetablesArray[5].SetCoordinate(520, 200);

        hrTrees treesArray[3];
        treesArray[0].SetCoordinate(596, 91);
        treesArray[1].SetCoordinate(723, 91);
        treesArray[2].SetCoordinate(849, 91);

        hrButton newGame1(437, 304, 867, 412, 0);
        hrButton newGame2(437, 246, 867, 354, 0); 
        hrButton resumeGame(437, 365, 867, 473, 0); 
        hrButton left(36, 324, 80, 395, 1); 
        hrButton right(1225, 324, 1269, 395, 1);
        hrButton smithy(941, 0, 1036, 95, 1);
        hrButton upgrade(941, 0, 1036, 95, 1);
        hrButton map(941, 0, 1036, 95, 1);

        hrButton smithyUpgrade11(414, 69, 509, 164, 2);
        hrButton smithyUpgrade12(533, 69, 628, 164, 2);
        hrButton smithyUpgrade13(652, 69, 747, 164, 2);
        hrButton smithyUpgrade21(414, 190, 509, 285, 2);
        hrButton smithyUpgrade22(533, 190, 628, 285, 2);
        hrButton smithyUpgrade23(652, 190, 747, 285, 2);
        hrButton smithyUpgrade31(414, 311, 509, 406, 2);
        hrButton smithyUpgrade32(533, 311, 628, 406, 2);
        hrButton smithyUpgrade33(652, 311, 747, 406, 2);
        hrButton smithyUpgrade41(414, 432, 509, 527, 2);
        hrButton smithyUpgrade42(533, 432, 628, 527, 2);
        hrButton smithyUpgrade43(652, 432, 747, 527, 2);
        hrButton smithyUpgrade51(414, 553, 509, 648, 2);
        hrButton smithyUpgrade52(533, 553, 628, 648, 2);
        hrButton smithyUpgrade53(652, 553, 747, 648, 2);
        hrButton smithyBuy(938, 597, 1056, 631, 2);
        hrButton smithyBack(944, 638, 1050, 670, 2);

        hrButton upgr(431, 557, 646, 611, 3);
        hrButton upgradeFirstLvl(66, 171, 261, 236, 3); 
        hrButton upgradeSecondLvl(63, 288, 270, 403, 3);
        hrButton upgradeThirdLvl(63, 442, 267, 513, 3);
        hrButton upgradeBack(115, 613, 221, 645, 3);

        hrButton vFirstAct(265, 488, 375, 567, 4);
        hrButton xFirstAct(265, 479, 375, 578, 4);
        hrButton vSecondAct(564, 388, 672, 467, 4);
        hrButton xSecondAct(562, 379, 672, 478, 4);
        hrButton vThirdAct(320, 252, 430, 331, 4);
        hrButton xThirdAct(320, 243, 430, 342, 4);
        hrButton vFourthAct(920, 476, 1030, 555, 4);
        hrButton xFourthAct(920, 467, 1030, 566, 4);
        hrButton vFifthAct(879, 229, 989, 308, 4);
        hrButton xFifthAct(879, 220, 989, 319, 4);
        hrButton mapBack(534, 610, 759, 703, 4);

        hrButton gameFirstAction(369, 630, 458, 719, 5);
        hrButton gameSecondAction(462, 630, 551, 719, 5);
        hrButton gameThirdAction(555, 630, 644, 719, 5);
        hrButton gameFourthAction(651, 630, 740, 719, 5);
        hrButton gameFifthAction(744, 630, 833, 719, 5);
        hrButton gameSixthAction(837, 630, 926, 719, 5);
//============================================

//===========[ Загрузка картинок ]============
        HDC backgroundLoad = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_Load.bmp");
        txBitBlt(txDC(), 0, 0, 1296, 720, backgroundLoad, 0, 0);

        txBegin();
        HDC backgroundMainMenuNew = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_MainMenu1.bmp");
        HDC backgroundMainMenuResume = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_MainMenu2.bmp");
        HDC backgroundMenu = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_Menu.bmp");
        HDC backgroundSmithy = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_Smithy.bmp");
        HDC backgroundUpgradeFirstLvl = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_Upgrade_FirstLvl.bmp");
        HDC backgroundUpgradeSecondLvl = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_Upgrade_SecondLvl.bmp");
        HDC backgroundUpgradeThirdLvl = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_Upgrade_ThirdLvl.bmp");
        HDC backgroundMap = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_Map.bmp");
        HDC backgroundGame = txLoadImage("Resources\\Images\\Backgrounds\\BACKGROUND_Game.bmp");

        HDC uiMenu = txLoadImage("Resources\\Images\\UI\\UI_Menu.bmp");
        HDC btnLeft = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_Left.bmp");
        HDC btnRight = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_Right.bmp");
        HDC btnSmithy = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_Smithy.bmp");
        HDC btnUpgrade = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_Upgrade.bmp");
        HDC btnMap = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_Map.bmp");

        HDC uiSmithyBuying = txLoadImage("Resources\\Images\\UI\\UI_Smithy_Buying.bmp");
        HDC uiSmithyUpgrade11 = txLoadImage("Resources\\Images\\UI\\UI_Smithy_11.bmp");
        HDC uiSmithyUpgrade12 = txLoadImage("Resources\\Images\\UI\\UI_Smithy_12.bmp");
        HDC uiSmithyUpgrade13 = txLoadImage("Resources\\Images\\UI\\UI_Smithy_13.bmp");
        HDC uiSmithyUpgrade21 = txLoadImage("Resources\\Images\\UI\\UI_Smithy_21.bmp");
        HDC uiSmithyUpgrade22 = txLoadImage("Resources\\Images\\UI\\UI_Smithy_22.bmp");
        HDC uiSmithyUpgrade23 = txLoadImage("Resources\\Images\\UI\\UI_Smithy_23.bmp");
        HDC uiSmithySelectUpgrade = txLoadImage("Resources\\Images\\UI\\UI_Smithy_SelectUpgrade.bmp");

        HDC uiUpgradeBuying = txLoadImage("Resources\\Images\\UI\\UI_Upgrade_Buying.bmp");

        HDC uiCloudAct1 = txLoadImage("Resources\\Images\\UI\\UI_Cloud_Act1.bmp");
        HDC uiCloudAct2 = txLoadImage("Resources\\Images\\UI\\UI_Cloud_Act2.bmp");
        HDC uiCloudAct3 = txLoadImage("Resources\\Images\\UI\\UI_Cloud_Act3.bmp");
        HDC uiCloudAct4 = txLoadImage("Resources\\Images\\UI\\UI_Cloud_Act4.bmp");
        HDC btnV = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_V.bmp");
        HDC btnX = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_X.bmp");

        HDC btnFirstActAction = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_FirstAct_Action.bmp");
        HDC btnSecondActAction = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_SecondAct_Action.bmp");
        HDC btnThirdActAction = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_ThirdAct_Action.bmp");
        HDC btnFourthAndFifthActAction = txLoadImage("Resources\\Images\\UI\\Buttons\\BTN_FourthAndFifthAct_Action.bmp");

        HDC Lizard_0_1_1 = txLoadImage("Resources\\Images\\Hero\\Lizard\\Lizard_0_1_1.bmp"); 
        HDC Lizard_0_1_2 = txLoadImage("Resources\\Images\\Hero\\Lizard\\Lizard_0_1_2.bmp");
        HDC Lizard_0_1_3 = txLoadImage("Resources\\Images\\Hero\\Lizard\\Lizard_0_1_3.bmp");
        HDC Lizard_0_2_1 = txLoadImage("Resources\\Images\\Hero\\Lizard\\Lizard_0_2_1.bmp");
        HDC Lizard_0_2_2 = txLoadImage("Resources\\Images\\Hero\\Lizard\\Lizard_0_2_2.bmp");
        HDC Lizard_0_2_3 = txLoadImage("Resources\\Images\\Hero\\Lizard\\Lizard_0_2_3.bmp");
        txEnd();
//============================================

//===========[ Цикл игры ]============
        while(TRUE)
        {
            time++;
            txClearConsole();
            txBegin();
                painting(layout, act, money, actMoney, houseUpgrade, treesUpgrade, vegetablesUpgrade, smithyUpgradeSelect, houseUpgradeSelect, backgroundX1, backgroundX2, menuStage, mapMove, &blacksmithFrame, collectorArray, woodcutterArray, knightArray, archerArray, wizardArray, lizardArray, vegetablesArray, treesArray, backgroundMainMenuNew, backgroundMainMenuResume, backgroundMenu, backgroundSmithy, backgroundUpgradeFirstLvl, backgroundUpgradeSecondLvl, backgroundUpgradeThirdLvl, backgroundMap, backgroundGame, uiMenu, btnLeft, btnRight, btnSmithy, btnUpgrade, btnMap, uiSmithyBuying, uiSmithySelectUpgrade, uiSmithyUpgrade11, uiSmithyUpgrade12, uiSmithyUpgrade13, uiSmithyUpgrade21, uiSmithyUpgrade22, uiSmithyUpgrade23, uiUpgradeBuying, uiCloudAct1, uiCloudAct2, uiCloudAct3, uiCloudAct4, btnV, btnX, btnFirstActAction, btnSecondActAction, btnThirdActAction, btnFourthAndFifthActAction, Lizard_0_1_1, Lizard_0_1_2, Lizard_0_1_3, Lizard_0_2_1, Lizard_0_2_2, Lizard_0_2_3);
            txEnd();

            if(mapMove == 0)
            {
                keyboardControls(&layout, &act, &money, &actMoney, &houseUpgrade, &treesUpgrade, &vegetablesUpgrade, &smithyUpgradeSelect, &houseUpgradeSelect, &backgroundX1, &backgroundX2, &menuStage, &mapMove, &blacksmithFrame, collectorArray, woodcutterArray, knightArray, archerArray, wizardArray, lizardArray, vegetablesArray, treesArray, newGame1, newGame2, resumeGame, left, right, smithy, upgrade, map, smithyUpgrade11, smithyUpgrade12, smithyUpgrade13, smithyUpgrade21, smithyUpgrade22, smithyUpgrade23, smithyUpgrade31, smithyUpgrade32, smithyUpgrade33, smithyUpgrade41, smithyUpgrade42, smithyUpgrade43, smithyUpgrade51, smithyUpgrade52, smithyUpgrade53, smithyBuy, smithyBack, upgr, upgradeFirstLvl, upgradeSecondLvl, upgradeThirdLvl, upgradeBack, vFirstAct, xFirstAct, vSecondAct, xSecondAct, vThirdAct, xThirdAct, vFourthAct, xFourthAct, vFifthAct, xFifthAct, mapBack, gameFirstAction, gameSecondAction, gameThirdAction, gameFourthAction, gameFifthAction, gameSixthAction, backgroundMainMenuNew, backgroundMainMenuResume, backgroundMenu, backgroundSmithy, backgroundUpgradeFirstLvl, backgroundUpgradeSecondLvl, backgroundUpgradeThirdLvl, backgroundMap, backgroundGame, uiMenu, btnLeft, btnRight, btnSmithy, btnUpgrade, btnMap, uiSmithyBuying, uiSmithySelectUpgrade, uiSmithyUpgrade11, uiSmithyUpgrade12, uiSmithyUpgrade13, uiSmithyUpgrade21, uiSmithyUpgrade22, uiSmithyUpgrade23, uiUpgradeBuying, uiCloudAct1, uiCloudAct2, uiCloudAct3, uiCloudAct4, btnV, btnX, btnFirstActAction, btnSecondActAction, btnThirdActAction, btnFourthAndFifthActAction, Lizard_0_1_1, Lizard_0_1_2, Lizard_0_1_3, Lizard_0_2_1, Lizard_0_2_2, Lizard_0_2_3);
            }

            if(layout == 5)
            {
                for(int i = 0; i<3; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        if(collectorArray[i].GetState())
                        { 
                            if(collectorArray[i].InPosition(j, vegetablesUpgrade))
                            {
                                if(vegetablesArray[j].GetFrame() == 4)
                                {
                                    if(!vegetablesArray[j].IsCollect())
                                    {
                                        vegetablesArray[j].SetCollecting(1);
                                        collectorArray[i].SetCollectVegetables(j);
                                        collectorArray[i].SetAnimation(2);
                                        collectorArray[i].SetFrame(1);
                                    }
                                }
                            }
                        }
                    }
                }
            
                for(int i = 0; i<3; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        if(woodcutterArray[i].GetState())
                        { 
                            if(woodcutterArray[i].InPosition(j))
                            {
                                if(treesArray[j].GetFrame() == 3)
                                {
                                    if(!treesArray[j].IsCollect())
                                    {
                                        treesArray[j].SetCollecting(1);
                                        woodcutterArray[i].SetCollectTrees(j);
                                        woodcutterArray[i].SetAnimation(2);
                                        woodcutterArray[i].SetFrame(1);
                                    }
                                }
                            }
                        }
                    }
                }
            
                for(int i = 0; i<3; i++)
                {
                    if(time%3 == 0)
                    {
                        if(collectorArray[i].GetState())
                        {
                            if(collectorArray[i].GetAnimation() == 1)
                            {
                                if(collectorArray[i].GetRotate() == 0)
                                {
                                    collectorArray[i].Frames(collectorArray[i].GetFrame());
                                    collectorArray[i].SetCoordinate(collectorArray[i].GetX()+7, 188+(i*3));
                                    if(collectorArray[i].GetX() > 550)
                                    {
                                        collectorArray[i].SetRotate(1);
                                        collectorArray[i].SetAnimation(1);
                                        collectorArray[i].SetFrame(1);
                                    }
                                }
                                if(collectorArray[i].GetRotate() == 1)
                                {
                                    collectorArray[i].Frames(collectorArray[i].GetFrame());
                                    collectorArray[i].SetCoordinate(collectorArray[i].GetX()-7, 188+(i*3));
                                    if(collectorArray[i].GetX() < 280)
                                    {
                                        collectorArray[i].SetRotate(0);
                                        collectorArray[i].SetAnimation(1);
                                        collectorArray[i].SetFrame(1);
                                    }
                                }
                            }
                            if(collectorArray[i].GetAnimation() == 2)
                            {
                                if(collectorArray[i].GetFrame() != 3)
                                {
                                    collectorArray[i].Frames(collectorArray[i].GetFrame());
                                }else{
                                    collectorArray[i].SetAnimation(1);
                                    collectorArray[i].SetFrame(1);
                                    vegetablesArray[collectorArray[i].GetCollectVegetables()].SetCollecting(0);
                                    vegetablesArray[collectorArray[i].GetCollectVegetables()].SetFrame(1);
                                    collectorArray[i].SetCollectVegetables(-1);
                                }
                            }
                        }
                    }
                }

                for(int i = 0; i<3; i++)
                {
                    if(time%3 == 0)
                    {
                        if(woodcutterArray[i].GetState())
                        {
                            if(woodcutterArray[i].GetAnimation() == 1)
                            {
                                if(woodcutterArray[i].GetRotate() == 0)
                                {
                                    woodcutterArray[i].Frames(woodcutterArray[i].GetFrame());
                                    woodcutterArray[i].SetCoordinate(woodcutterArray[i].GetX()+7, 188+(i*3));
                                    if(woodcutterArray[i].GetX() > 970)
                                    {
                                        woodcutterArray[i].SetRotate(1);
                                        woodcutterArray[i].SetAnimation(1);
                                        woodcutterArray[i].SetFrame(1);
                                    }
                                }
                                if(woodcutterArray[i].GetRotate() == 1)
                                {
                                    woodcutterArray[i].Frames(woodcutterArray[i].GetFrame());
                                    woodcutterArray[i].SetCoordinate(woodcutterArray[i].GetX()-7, 188+(i*3));
                                    if(woodcutterArray[i].GetX() < 590)
                                    {
                                        woodcutterArray[i].SetRotate(0);
                                        woodcutterArray[i].SetAnimation(1);
                                        woodcutterArray[i].SetFrame(1);
                                    }
                                }
                            }
                            if(woodcutterArray[i].GetAnimation() == 2)
                            {
                                if(woodcutterArray[i].GetFrame() != 3)
                                {
                                    woodcutterArray[i].Frames(woodcutterArray[i].GetFrame());
                                }else{
                                    woodcutterArray[i].SetAnimation(1);
                                    woodcutterArray[i].SetFrame(1);
                                    treesArray[woodcutterArray[i].GetCollectTrees()].SetCollecting(0);
                                    treesArray[woodcutterArray[i].GetCollectTrees()].SetFrame(1);
                                    woodcutterArray[i].SetCollectTrees(-1);
                                }
                            }
                        }
                    }
                }
    
                for(int i = 0; i<3; i++)
                {
                    if(time%2 == 0)
                    {
                        if(!knightArray[i].OnPosition(i))
                        {
                            knightArray[i].Frames(knightArray[i].GetFrame());
                            knightArray[i].SetCoordinate(knightArray[i].GetX()+7, 490+(20*i));
                        }else{
                            knightArray[i].Frames(knightArray[i].GetFrame());
                            for(int j = 0; j < 20; j++)
                            {
                                if(lizardArray[j].OnPosition())
                                {
                                    knightArray[i].SetAnimation(2);
                                    knightArray[i].Frames(knightArray[i].GetFrame());
                                    lizardArray[j].SetHealth(lizardArray[j].GetHealth()-6);
                                }
                            }
                            for(int j1 =  0; j1 < 20; j1++)
                            {
                                if(!lizardArray[0].OnPosition() and !lizardArray[1].OnPosition() and !lizardArray[2].OnPosition() and !lizardArray[3].OnPosition() and !lizardArray[4].OnPosition() and !lizardArray[5].OnPosition() and !lizardArray[6].OnPosition() and !lizardArray[7].OnPosition() and !lizardArray[8].OnPosition() and !lizardArray[9].OnPosition() and !lizardArray[10].OnPosition() and !lizardArray[11].OnPosition() and !lizardArray[12].OnPosition() and !lizardArray[13].OnPosition() and !lizardArray[14].OnPosition() and !lizardArray[15].OnPosition() and !lizardArray[16].OnPosition() and !lizardArray[17].OnPosition() and !lizardArray[18].OnPosition() and !lizardArray[19].OnPosition())
                                {
                                    knightArray[i].SetAnimation(1);
                                    knightArray[i].SetFrame(2);
                                }    
                            }
                        }
                    }
                }
            
                for(int i = 0; i<3; i++)
                {
                    if(time%5 == 0)
                    {
                        if(archerArray[i].GetState())
                        {
                            archerArray[i].Frames(archerArray[i].GetFrame());
                            if(archerArray[i].GetX() < 410-(30*i))
                            {
                                archerArray[i].SetCoordinate(archerArray[i].GetX()+7, 490+(20*i));
                            }
                        }
                    }
                }
            
                for(int i = 0; i<3; i++)
                {
                    if(time%5 == 0)
                    {
                        if(wizardArray[i].GetState())
                        {
                            wizardArray[i].Frames(wizardArray[i].GetFrame());
                            if(wizardArray[i].GetX() < 260-(30*i))
                            {
                                wizardArray[i].SetCoordinate(wizardArray[i].GetX()+7, 490+(20*i));
                            }
                        }
                    }
                }

                if(time%60 == 0)
                {
                    switch(act)
                    {
                        case 1:
                            for(int i = 0; i<5; i++)
                            {
                                if(lizardArray[i].GetState() == 0)
                                {
                                    lizardArray[i].SetState(1);
                                    lizardArray[i].SetCoordinate(1157, 510);
                                    lizardArray[i].SetHealth(100);
                                    break;
                                }
                            }
                            break;
                        case 2:
                            for(int i = 0; i<10; i++)
                            {
                                if(lizardArray[i].GetState() == 0)
                                {
                                    lizardArray[i].SetState(1);
                                    lizardArray[i].SetCoordinate(1157, 510);
                                    lizardArray[i].SetHealth(100);
                                    break;
                                }
                            }
                            break;
                        case 3:
                            for(int i = 0; i<15; i++)
                            {
                                if(lizardArray[i].GetState() == 0)
                                {
                                    lizardArray[i].SetState(1);
                                    lizardArray[i].SetCoordinate(1157, 510);
                                    lizardArray[i].SetHealth(100);
                                    break;
                                }
                            }
                            break;
                        case 4:
                            for(int i = 0; i<15; i++)
                            {
                                if(lizardArray[i].GetState() == 0)
                                {
                                    lizardArray[i].SetState(1);
                                    lizardArray[i].SetCoordinate(1157, 510);
                                    lizardArray[i].SetHealth(100);
                                    break;
                                }
                            }
                            break;
                        case 5:
                            for(int i = 0; i<20; i++)
                            {
                                if(lizardArray[i].GetState() == 0)
                                {
                                    lizardArray[i].SetState(1);
                                    lizardArray[i].SetCoordinate(1157, 510);
                                    lizardArray[i].SetHealth(100);
                                    break;
                                }
                            }
                            break;
                    }
                }


                for(int i = 0; i<20; i++)
                {
                    if(time%2 == 0)
                    {
                        if(!lizardArray[i].OnPosition())
                        {
                            lizardArray[i].Frames(lizardArray[i].GetFrame());
                            lizardArray[i].SetCoordinate(lizardArray[i].GetX()-7, 510);
                        }else{
                            lizardArray[i].Frames(lizardArray[i].GetFrame());
                            for(int j = 0; j < 3; j++)
                            {
                                if(knightArray[j].OnPosition(j))
                                {
                                    lizardArray[i].SetAnimation(2);
                                    lizardArray[i].Frames(lizardArray[i].GetFrame());
                                    knightArray[i].SetHealth(knightArray[i].GetHealth()-5);
                                }
                            }
                            if(!knightArray[0].OnPosition(0) and !knightArray[1].OnPosition(1) and !knightArray[2].OnPosition(2))
                            {
                               lizardArray[i].SetAnimation(1); 
                               lizardArray[i].SetFrame(2);
                            } 
                        }
                    }
                }

                /*for(int i = 0; i<20; i++)
                {
                    if(time%2 == 0)
                    {
                        if(lizardArray[i].GetState())
                        {
                            if(lizardArray[i].GetX() > 660)
                            {
                                lizardArray[i].Frames(lizardArray[i].GetFrame());
                                lizardArray[i].SetCoordinate(lizardArray[i].GetX()-7, 510);
                            }else{
                                if(knightArray[0].GetState() or knightArray[1].GetState() or knightArray[2].GetState())
                                {
                                    if(knightArray[0].GetX() > 499 or knightArray[1].GetX() > 499 or knightArray[2].GetX() > 499)
                                    {
                                        lizardArray[i].SetAnimation(2);
                                        lizardArray[i].Frames(lizardArray[i].GetFrame());
                                        for(int j = 0; j < 3; j++)
                                        {
                                            if(knightArray[j].GetState())
                                            {
                                                if(knightArray[j].GetX() > 499)
                                                {
                                                    knightArray[j].SetHealth(knightArray[j].GetHealth()-5);
                                                    /*if(knightArray[j].GetHealth() < 0)
                                                    {
                                                        lizardArray[i].SetAnimation(1);
                                                        lizardArray[i].SetFrame(1);
                                                    }
                                                    Sleep(100);
                                                }
                                            }else{
                                                if(archerArray[j].GetState())
                                                {
                                                    archerArray[j].SetHealth(archerArray[i].GetHealth()-5);
                                                    Sleep(100);
                                                }else{
                                                    if(wizardArray[j].GetState())
                                                    {
                                                        wizardArray[j].SetHealth(wizardArray[j].GetHealth()-5);
                                                        Sleep(100);
                                                    }
                                                }
                                            }
                                        }
                                    }else{
                                        lizardArray[i].SetFrame(2);
                                    }
                                }else{
                                    lizardArray[i].SetFrame(2);
                                }
                            }
                        }
                    }
                }*/

                for(int i = 0; i<3; i++)
                {
                    if(knightArray[i].GetHealth() < 0)
                    {
                        knightArray[i].SetState(0);
                        knightArray[i].SetAnimation(1);
                        knightArray[i].SetCoordinate(139, 530);
                        knightArray[i].SetFrame(1);
                        knightArray[i].SetHealth(100);
                    }
                }
                
                for(int i = 0; i<3; i++)
                {
                    if(archerArray[i].GetHealth() < 0)
                    {
                        archerArray[i].SetState(0);
                        archerArray[i].SetAnimation(1);
                        archerArray[i].SetCoordinate(139, 530);
                        archerArray[i].SetFrame(1);
                        archerArray[i].SetHealth(100);
                    }
                }

                for(int i = 0; i<3; i++)
                {
                    if(wizardArray[i].GetHealth() < 0)
                    {
                        wizardArray[i].SetState(0);
                        wizardArray[i].SetAnimation(1);
                        wizardArray[i].SetCoordinate(139, 530);
                        wizardArray[i].SetFrame(1);
                        wizardArray[i].SetHealth(100);
                    }
                }

                for(int i = 0; i<20; i++)
                {
                    if(lizardArray[i].GetHealth() < 0)
                    {
                        lizardArray[i].SetAnimation(0);
                        lizardArray[i].SetCoordinate(139, 530);
                        lizardArray[i].SetFrame(0);
                        lizardArray[i].SetHealth(-1);
                    }
                }
                

                if(time%20 == 0)
                {
                    for(int i = 0; i<6; i++)
                    {
                        if(rand()%3+1 == 1)
                        {
                            vegetablesArray[i].Frames(vegetablesArray[i].GetFrame());
                        }
                    }
                }

                if(time%50 == 0)
                {
                    for(int i = 0; i<3; i++)
                    {
                        if(rand()%5+1 == 1)
                        {
                            treesArray[i].Frames(treesArray[i].GetFrame());
                        }
                    }
                }
            }
        }
    }
//====================================

    