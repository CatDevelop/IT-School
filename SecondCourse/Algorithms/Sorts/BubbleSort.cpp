    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <iostream>

    int main()
    {
        int size = 0;
        int temp = 0;
        int sum = 0;

        std::cin >> size;

        int m[size];

        srand(time(NULL));
        for(int i = 0; i<size+1; i++)
        {
            m[i] = rand()%100-50;
            std::cout << m[i] << " ";
        }

        for(int i = 0; i < size-1; i++)
        {
            for(int j = 0; j < size-i+1; j++)
            {
                if (m[j] > m[j+1])
                {
                    temp = m[j];
                    m[j] = m[j + 1];
                    m[j + 1] = temp;
                }
            }
        }

        std::cout << "\n";
        for(int i = 0; i<size+1; i++)
        {
            std::cout << m[i] << " ";
        }
        std::cout << "\n";

        for(int i = 0; i < size+1; i++)
        {
            if(m[i] < 0)
            {
                sum = sum + m[i];
            }
        }
        std::cout << "Sum of negative numbers: " << sum << "\n";

        system ("pause");
        return 1;
    }
