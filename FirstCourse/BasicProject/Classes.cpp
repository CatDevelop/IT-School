    #include "TXLib.h"
    #include <string>

    class Button
    {
        private:
            int X1;
            int Y1;
            int X2;
            int Y2;

        public:
            void SetCoordinate(int ValueX1, int ValueY1, int ValueX2, int ValueY2)
            {
                X1 = ValueX1;
                Y1 = ValueY1; 
                X2 = ValueX2;
                Y2 = ValueY2;
            }

            void UploadHDC(char Name)
            {
                HDC Image = txLoadImage(strtok("Resources\\", Name));
            }

            void Drawing(HDC Image)
            {
                txAlphaBlend(txDC(), 0, 0, 1296, 720, Image, 0, 0, 1);
            }

            bool IsClicked()
            {
                RECT Collision = {X1, Y1, X2, Y2};
                if(GetAsyncKeyState(VK_LBUTTON))
                {
                    if(In(txMousePos(), Collision))
                    {
                        return true;
                    }
                }
            }
    };

    void Keyboard(Button FirstButton)
    {
        if(FirstButton.IsClicked())
        {
            printf("%s", "123");
            Sleep(100);
        }
    }

    int main()
    {
        txCreateWindow(1296, 720);
        txSetFillColor(TX_WHITE);
        txFloodFill(0, 0, FLOODFILLBORDER);
        char BTN_Map[100];

        Button FirstButton;
        FirstButton.SetCoordinate(942, 0, 1037, 95);
        FirstButton.UploadHDC(BTN_Map);

        while(TRUE)
        {
            FirstButton.Drawing(BTN_Map);
            Keyboard(FirstButton);
        }
    }

    