    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <time.h>

    void mergeSort(int *numberArray, int first, int last);
    void merge(int *arr, int l, int m, int r);

    int main()
    {
        int size = 0;
        std::cout << "Size: ";
        std::cin >> size;

        int numberArray[size];

        std::cout << "Array:      ";
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            numberArray[i] = rand() % 20 - 10;
            std::cout << numberArray[i]  << " ";
        }
        
        mergeSort(numberArray, 0, size);

        std::cout << "\nSort array: ";
        for (int i = 0; i< size ; i++)
        {
            std::cout << numberArray[i] << " ";;
        }
        std::cout << "\n";

        system ("pause");
        return 0;
    }

    void mergeSort(int *numberArray, int first, int last)
    {
        if (first<last)
        {
            int m = first+(last-first)/2;
            mergeSort(numberArray, first, (first+last)/2-1); //сортировка левой части
            mergeSort(numberArray, (first+last)/2+1, last); //сортировка правой части
            merge(numberArray, first, m, last); //слияние двух частей
        }
    }

    void merge(int *arr, int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        // Create temp arrays
        int L[n1], R[n2];
        // Copy data to temp array
        for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
        // Merge the temp arrays
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
        if (L[i] <= R[j])
        {
        arr[k] = L[i];
        i++;
        }
        else
        {
        arr[k] = R[j];
        j++;
        }
        k++;
        }
        // Copy the remaining elements of L[]
        while (i < n1)
        {
        arr[k] = L[i];
        i++;
        k++;
        }
        // Copy the remaining elements of R[]
        while (j < n2)
        {
        arr[k] = R[j];
        j++;
        k++;
        }
    }

