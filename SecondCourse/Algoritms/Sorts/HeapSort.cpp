    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <iostream>
    using namespace std;

    void heapSort(int *array, int size);
    void heapify(int *array, int size, int first);

    int main()
    {
        int size = 0;
        cout << "Size: ";
        cin >> size;

        int *array = new int[size];

        std::cout << "Array:      ";
        srand(time(NULL));
        for(int i = 0; i<size; i++)
        {
            array[i] = rand()%100-50;
            std::cout << array[i] << " ";
        }

        heapSort(array, size);

        cout << "\nSort array: ";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << "\n";

        delete[] array;

        system("pause");
        return 0;
    }

    void heapSort(int *array, int size)
    {
        for(int i = size/2-1; i>=0; i--)
        {
            heapify(array, size, i);
        }

        for(int i = size-1; i>=0; i--)
        {
            swap(array[0], array[i]);
            heapify(array, i, 0);
        }
    }

    void heapify(int *array, int size, int first)
    {
        int largest = first;
        int l = 2*first+1;
        int r = 2*first+2;

        if(l<size && array[l]>array[largest])
        {
            largest = l;
        }

        if(r<size && array[r]>array[largest])
        {
            largest = r;
        }

        if(largest != first)
        {
            swap(array[first], array[largest]);
            heapify(array, size, largest);
        }
    }
