    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <iostream>

    int main()
    {
        int size = 0;
        int temp = 0;
        int sum = 0;
        int i, j;

        std::cin >> size;

        int m[size];

        srand(time(NULL));
        for(int i = 0; i<size+1; i++)
        {
            m[i] = rand()%100-50;
            std::cout << m[i] << " ";
        }

        for (i=0; i < size; i++)
        {
            temp = m[i];
            for (j=i-1; j>=0 && m[j] > temp; j--)
            {
                m[j+1] = m[j];
            }

            m[j+1] = temp;
      }

        std::cout << "\n";
        for(int i = 0; i<size+1; i++)
        {
            std::cout << m[i] << " ";
        }
        std::cout << "\n";


        system ("pause");
        return 1;
    }
