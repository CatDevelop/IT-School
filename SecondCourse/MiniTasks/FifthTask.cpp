// С клавиатуры вводится число N (типа int). Используя алгоритм «Решето Эратосфена», необходимо найти все простые числа (т.е. делящиеся только на себя и на единицу) в интервале [0;N].
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <string>

    int main()
    {
        int n = 0;

        std::cout << "n: ";
        std::cin >> n;

        for (int i = 2; i<n; i++)
        {
            if ((i == 2) || (i == 3) || (i == 5) || (i == 7))
            {
                std::cout << i << " ";
                continue;
            }

            if ((i % 2 != 0) and ((i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0)))
            {
                std::cout << i << " ";
            }
        }
        return 0;
    }