// Даны три целых числа: h, m, s. Определите угол (в градусах) между часовой стрелкой на циферблате часов в момент времени “h часов, m минут, s секунд” и между часовой стрелкой в полночь. 

    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    int main()
    {
        int h = 0;
        int m = 0;
        int s = 0;  

        std::cout << "h: ";    
        std::cin >> h;

        std::cout << "m: ";    
        std::cin >> m;

        std::cout << "s: ";    
        std::cin >> s;

        h %= 12;
        m %= 60;
        s %= 60;
        
        std::cout << "Result: " << 30*h + 0.5*m + 30.0/3600*s << "\n";    
        system ("pause");
        return 1;
    }