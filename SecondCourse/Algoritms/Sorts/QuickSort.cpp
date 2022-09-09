    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <iostream>
    using namespace std;

    void quickSort(int *arr, int size);

    int main()
    {
        int size = 0;
        cout << "Size: ";
        cin >> size;
        int *arr = new int[size];

        srand(time(NULL));
        cout << "Array:      ";
        for (int k = 0; k < size; k++)
        {
            arr[k] = rand()%20-10;
            cout << arr[k]  << "  ";
        }

        quickSort(arr, size);

        cout << "\nSort array: ";
        for (int k = 0; k < size; k++)
        {
            cout << arr[k] << "  ";
        }
        cout << "\n";

        system ("pause");
        return 0;
    }

    void quickSort(int *arr, int size)
    {
        int i = 0;
        int j = size - 1;
        int mid = arr[size / 2];

        while (i <= j) 
        {
            while(arr[i] < mid) {
                i++;
            }
            while(arr[j] > mid) {
                j--;
            }

            if (i <= j) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
                j--;
            }
        }

        if(j > 0) {
            quickSort(arr, j + 1);
        }
        if (i < size) {
            quickSort(&arr[i], size - i);
        }
    }
