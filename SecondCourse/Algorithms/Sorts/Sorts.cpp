    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <iostream>

    class SortingArray
    {
        private:
            int size;
            int *array;

            void quick(int *a, int size)
            {
                int i = 0;
                int j = size - 1;
                int middle = a[size / 2];

                while (i <= j)
                {
                    while(a[i] < middle) {
                        i++;
                    }
                    while(a[j] > middle) {
                        j--;
                    }

                    if (i <= j) {
                        int temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;

                        i++;
                        j--;
                    }
                }

                if(j > 0) {
                    quick(a, j + 1);
                }
                if (i < size) {
                    quick(&a[i], size - i);
                }
            }

            void merge(int a[], int l, int m, int r)
            {
                int n1 = m - l + 1;
                int n2 = r - m;
                int L[n1], R[n2];

                for (int i = 0; i < n1; i++)
                {
                    L[i] = a[l + i];
                }

                for (int j = 0; j < n2; j++)
                {
                    R[j] = a[m + 1 + j];
                }


                int i = 0;
                int j = 0;
                int k = l;

                while (i < n1 && j < n2)
                {
                    if (L[i] <= R[j])
                    {
                        a[k] = L[i];
                        i++;
                    } else {
                        a[k] = R[j];
                        j++;
                    }
                    k++;
                }

                while (i < n1)
                {
                    a[k] = L[i];
                    i++;
                    k++;
                }

                while (j < n2)
                {
                    a[k] = R[j];
                    j++;
                    k++;
                }
            }

            void merging(int array[],int l,int r)
            {
                if(l>=r)
                {
                    return;
                }

                int m = (l+r-1)/2;
                merging(array,l,m);
                merging(array,m+1,r);
                merge(array,l,m,r);
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
                    std::swap(array[first], array[largest]);
                    heapify(array, size, largest);
                }
            }

        public:
            SortingArray(int valueSize)
            {
                size = valueSize;
                array = new int[size];
            }

            void SetRandomArray()
            {
                srand(time(NULL));
                for(int i = 0; i<size; i++)
                {
                    array[i] = rand()%100-50;
                }
            }
            void SetArray(int *valueArray) { array = valueArray; }

            int GetSize() { return size; }
            int GetArray(int index) { return array[index]; }

            void BubbleSort()
            {
                int temp = 0;

                for(int i = 0; i < size-1; i++)
                {
                    for(int j = 0; j < size-i+1; j++)
                    {
                        if (array[j] > array[j+1])
                        {
                            temp = array[j];
                            array[j] = array[j + 1];
                            array[j + 1] = temp;
                        }
                    }
                }
            }

            void InsertSort()
            {
                int temp = 0;
                int i, j;

                for (i=0; i < size; i++)
                {
                    temp = array[i];
                    for (j=i-1; j>=0 && array[j] > temp; j--)
                    {
                        array[j+1] = array[j];
                    }

                    array[j+1] = temp;
                }
            }

            void ShakerSort()
            {
                int start = 1;
                int end = size - 1;
                while (start <= end)
                {
                    for (int i = end; i >= start; i--)
                    {
                        if (array[i - 1] > array[i])
                        {
                            std::swap(array[i], array[i-1]);
                        }
                    }
                    start++;

                    for (int i = start; i <= end; i++)
                    {
                        if (array[i - 1] > array[i])
                        {
                            std::swap(array[i], array[i-1]);
                        }
                    }
                    end--;
                }
            }

            void ShellSort()
            {
                int d = size / 2;

                while (d > 0)
                {
                    for (int i = 0; i < size - d; i++)
                    {
                        int j = i;
                        while (j >= 0 && array[j] > array[j + d])
                        {
                                int temp = array[j];
                                array[j] = array[j + d];
                                array[j + d] = temp;

                            j--;
                        }
                    }
                    d = d/2;
                }
            }

            void QuickSort()
            {
                quick(array, size);
            }

            void MergeSort()
            {
                merging(array, 0, size-1);
            }

            void HeapSort()
            {
                for(int i = size/2-1; i>=0; i--)
                {
                    heapify(array, size, i);
                }

                for(int i = size-1; i>=0; i--)
                {
                    std::swap(array[0], array[i]);
                    heapify(array, i, 0);
                }
            }
    };

    int main()
    {
        int size;
        std::cout << "Size: ";
        std::cin >> size;

        SortingArray array(size);
        array.SetRandomArray();

        int choose;
        std::cout << "\nSelect sort: \n1. BubbleSort\n2. InsertSort\n3. ShakerSort\n4. ShellSort\n5. MergeSort(Not Working)\n6. QuickSort\n7. HeapSort\n";
        std::cin >> choose;

        std::cout << "\nUnsort array: ";
        for(int i = 0; i<array.GetSize(); i++)
        {
            std::cout << array.GetArray(i) << " ";
        }

        switch(choose)
        {
            case 1:
                array.BubbleSort();
                break;
            case 2:
                array.InsertSort();
                break;
            case 3:
                array.ShakerSort();
                break;
            case 4:
                array.ShellSort();
                break;
            case 5:
                array.MergeSort();
                break;
            case 6:
                array.QuickSort();
                break;
            case 7:
                array.HeapSort();
                break;
        }

        std::cout << "\nSort array: ";
        for(int i = 0; i<array.GetSize(); i++)
        {
            std::cout << array.GetArray(i) << " ";
        }
        std::cout << "\n";

        system ("pause");
        return 1;
    }
