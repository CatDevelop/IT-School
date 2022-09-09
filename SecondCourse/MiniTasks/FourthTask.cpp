// Составить алгоритм определяющий, есть ли среди цифр введенного трехзначного числа — одинаковые. Число вводится с клавиатуры.

    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <string>

    int main()
    {
        int n = 0;
        char str[3];

        std::cout << "n: ";
        std::cin >> n;
        itoa(n, str, 10);

        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)    
            {
                if(i != j)
                {
                    if(str[i] == str[j])
                    {
                        std::cout << "Yes\n";
                        system("pause");
                        return 0;
                    }else{
                        std::cout << "No\n";
                        system("pause");
                        return 0;
                    }
                }
            }
        }
    }