// Вычислить длину вектора с координатами x, y, z.

    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <math.h>


    int main()
    {
        int x, y, z = 0;

        std::cout << "X: ";
        std::cin >> x;

        std::cout << "Y: ";
        std::cin >> y;

        std::cout << "Z: ";
        std::cin >> z;
        
        std::cout << "Vector length: " << sqrt(x*x+y*y+z*z) << "\n";
        
        system("pause");
        return 0;
    }