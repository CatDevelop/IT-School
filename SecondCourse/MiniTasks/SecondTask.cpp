// Написать функцию, определяющую является ли заданное число степенью двойки.

    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    bool IsPowerOfTwo(int n);

    int main()
    {
        int n = 0;
        std::cout << "n: ";
        std::cin >> n;
        
        if(IsPowerOfTwo(n))
        {
            std::cout << "Yes\n";
        }else{
            std::cout << "No\n"; 
        }
        
        system("pause");
        return 0;
    }

    bool IsPowerOfTwo(int n)
    {
        int i;
        while (n) 
        {
            i += n % 2;
            n /= 2;
        }

        if (i == 1){
            return true;
        } else {
            return false;
        }
    }