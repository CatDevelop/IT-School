    #include "TXlib.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    enum level {parking, cars, clothes, fastfood, computers, none};

    void drawing(int frame, level floor, HDC lift1, HDC lift2, HDC lift3, HDC lift4, HDC control, HDC numberFloor, HDC backgroundParking, HDC backgroundCars, HDC backgroundClothes, HDC backgroundFastfood, HDC backgroundComputers);
    void openLift(int *frame, level *floor, HDC lift1, HDC lift2, HDC lift3, HDC lift4, HDC control, HDC numberFloor, HDC backgroundParking, HDC backgroundCars, HDC backgroundClothes, HDC backgroundFastfood, HDC backgroundComputers);
    void closeLift(int *frame, level *floor, HDC lift1, HDC lift2, HDC lift3, HDC lift4, HDC control, HDC numberFloor, HDC backgroundParking, HDC backgroundCars, HDC backgroundClothes, HDC backgroundFastfood, HDC backgroundComputers);
    void keyboardControls(int *frame, level *floor, RECT zero, RECT first, RECT second, RECT third, RECT fourth, HDC lift1, HDC lift2, HDC lift3, HDC lift4, HDC control, HDC numberFloor, HDC backgroundParking, HDC backgroundCars, HDC backgroundClothes, HDC backgroundFastfood, HDC backgroundComputers);

    int main()
    {
        txCreateWindow(1296, 720);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);

        HDC control = txLoadImage("Resources\\UI_Control.bmp");
        HDC numberFloor = txLoadImage("Resources\\UI_NumberFloor.bmp");
        HDC lift1 = txLoadImage("Resources\\Lift_1.bmp");
        HDC lift2 = txLoadImage("Resources\\Lift_2.bmp");
        HDC lift3 = txLoadImage("Resources\\Lift_3.bmp");
        HDC lift4 = txLoadImage("Resources\\Lift_4.bmp");
        
        HDC backgroundParking = txLoadImage("Resources\\BACKGROUND_Parking.bmp");
        HDC backgroundCars = txLoadImage("Resources\\BACKGROUND_Cars.bmp");
        HDC backgroundClothes = txLoadImage("Resources\\BACKGROUND_Clothes.bmp");
        HDC backgroundFastfood = txLoadImage("Resources\\BACKGROUND_FastFood.bmp");
        HDC backgroundComputers = txLoadImage("Resources\\BACKGROUND_Computers.bmp");

        RECT zero = {562, 485, 580, 516};
        RECT first = {599, 485, 612, 516};
        RECT second = {628, 485, 647, 516};
        RECT third = {663, 485, 680, 516};
        RECT fourth = {696, 485, 716, 516};

        level floor = parking;
        int frame = 1;

        while(TRUE)
        {  
            txBegin();
            drawing(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
            txEnd();
            keyboardControls(&frame, &floor, zero, first, second, third, fourth, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
        }
    }

    void drawing(int frame, level floor, HDC lift1, HDC lift2, HDC lift3, HDC lift4, HDC control, HDC numberFloor, HDC backgroundParking, HDC backgroundCars, HDC backgroundClothes, HDC backgroundFastfood, HDC backgroundComputers)
    {
        txSetFillColor(RGB(255, 255, 255));
        txClear();

        switch(floor)
        {
            case parking:
                txBitBlt(txDC(), 0, 0, 1280, 720, backgroundParking, 0, 0);
                txBitBlt(txDC(), 591, 168, 96, 74, numberFloor, 0, 0);
                txSetColor(TX_WHITE);
                txSelectFont ("Arial", 70, 0, FW_BOLD);
                txDrawText(601, 178, 676, 231, "0");
                break;
            case cars:
                txBitBlt(txDC(), 0, 0, 1280, 720, backgroundCars, 0, 0);
                txBitBlt(txDC(), 591, 168, 96, 74, numberFloor, 0, 0);
                txSetColor(TX_WHITE);
                txSelectFont ("Arial", 70, 0, FW_BOLD);
                txDrawText(601, 178, 676, 231, "1");
                break;
            case clothes:
                txBitBlt(txDC(), 0, 0, 1280, 720, backgroundClothes, 0, 0);
                txBitBlt(txDC(), 591, 168, 96, 74, numberFloor, 0, 0);
                txSetColor(TX_WHITE);
                txSelectFont ("Arial", 70, 0, FW_BOLD);
                txDrawText(601, 178, 676, 231, "2");
                break;
            case fastfood:
                txBitBlt(txDC(), 0, 0, 1280, 720, backgroundFastfood, 0, 0);
                txBitBlt(txDC(), 567, 242, 144, 234, lift4, 0, 0);
                txBitBlt(txDC(), 591, 168, 96, 74, numberFloor, 0, 0);
                txSetColor(TX_WHITE);
                txSelectFont ("Arial", 70, 0, FW_BOLD);
                txDrawText(601, 178, 676, 231, "3");
                break;
            case computers:
                txBitBlt(txDC(), 0, 0, 1280, 720, backgroundComputers, 0, 0);
                txBitBlt(txDC(), 567, 242, 144, 234, lift4, 0, 0);
                txBitBlt(txDC(), 591, 168, 96, 74, numberFloor, 0, 0);
                txSetColor(TX_WHITE);
                txSelectFont ("Arial", 70, 0, FW_BOLD);
                txDrawText(601, 178, 676, 231, "4");
                break;
        }

        switch(frame)
        {
            case 1:
                txBitBlt(txDC(), 567, 242, 144, 234, lift1, 0, 0);
                break;
            case 2:
                txBitBlt(txDC(), 567, 242, 144, 234, lift2, 0, 0);
                break;
            case 3:
                txBitBlt(txDC(), 567, 242, 144, 234, lift3, 0, 0);
                break;
            case 4:
                txBitBlt(txDC(), 567, 242, 144, 234, lift4, 0, 0);
                break;
        }

        
        txAlphaBlend(txDC(), 562, 485, 155, 32, control, 0, 0, 1);
        
    }

    void keyboardControls(int *frame, level *floor, RECT zero, RECT first, RECT second, RECT third, RECT fourth, HDC lift1, HDC lift2, HDC lift3, HDC lift4, HDC control, HDC numberFloor, HDC backgroundParking, HDC backgroundCars, HDC backgroundClothes, HDC backgroundFastfood, HDC backgroundComputers)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(In(txMousePos(), zero) and *floor != parking)
            {  
                closeLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
                *floor = parking;
                openLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
            }
            if(In(txMousePos(), first) and *floor != cars)
            {  
                closeLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
                *floor = cars;
                openLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
            }
            if(In(txMousePos(), second) and *floor != clothes)
            {  
                closeLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
                *floor = clothes;
                openLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
            }
            if(In(txMousePos(), third) and *floor != fastfood)
            {  
                closeLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
                *floor = fastfood;
                openLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
            }
            if(In(txMousePos(), fourth) and *floor != computers)
            {  
                closeLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
                *floor = computers;
                openLift(frame, floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
                
            }
        }
    }

    void openLift(int *frame, level *floor, HDC lift1, HDC lift2, HDC lift3, HDC lift4, HDC control, HDC numberFloor, HDC backgroundParking, HDC backgroundCars, HDC backgroundClothes, HDC backgroundFastfood, HDC backgroundComputers)
    {
        Sleep(300);
        *frame = 4;
        drawing(*frame, *floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
        Sleep(300);
        *frame = 3;
        drawing(*frame, *floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
        Sleep(300);
        *frame = 2;
        drawing(*frame, *floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
        Sleep(300);
        *frame = 1;
        drawing(*frame, *floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
        Sleep(1000);
    }

    void closeLift(int *frame, level *floor, HDC lift1, HDC lift2, HDC lift3, HDC lift4, HDC control, HDC numberFloor, HDC backgroundParking, HDC backgroundCars, HDC backgroundClothes, HDC backgroundFastfood, HDC backgroundComputers)
    {
        *floor = none;
        Sleep(500);
        *frame = 2;
        drawing(*frame, *floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
        Sleep(300);
        *frame = 3;
        drawing(*frame, *floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
        Sleep(300);
        *frame = 4;
        drawing(*frame, *floor, lift1, lift2, lift3, lift4, control, numberFloor, backgroundParking, backgroundCars, backgroundClothes, backgroundFastfood, backgroundComputers);
        Sleep(1000);
    }