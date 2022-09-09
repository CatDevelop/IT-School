    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <iostream>
    using namespace std;

    void shakerSort(int *array, int size);
    void swap(int *array, int i);

    int main()
    {
        int size = 0;
        cout << "Size: ";
        cin >> size;
        int *array = new int[size];

        std::cout << "Array:      ";
        srand(time(NULL));
        for (int k = 0; k < size; k++)
        {
            array[k] = rand()%20-10;
            cout << array[k]  << " ";
        }

        shakerSort(array, size);

        cout << "\nSort array: ";
        for (int k = 0; k < size; k++)
        {
            cout << array[k] << " ";
        }
        cout << "\n";
        
        system ("pause");
        return 0;
    }

    void swap(int *array, int i)
    {
        int temp;
        temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temp;
    }

    void shakerSort(int *array, int size)
    {
        int start = 1;
        int end = size - 1;
        while (start <= end)
        {
            for (int i = end; i >= start; i--)
            {
                if (array[i - 1] > array[i])
                {
                    swap(array, i);
                }
            } 
            start++;


            for (int i = start; i <= end; i++)
            {
                if (array[i - 1] > array[i]) 
                {
                    swap(array, i);
                }
            }
            end--;
        }
    }

    