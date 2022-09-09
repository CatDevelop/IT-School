#include <iostream> 
#include <ctime>
#include <cmath>
 
using namespace std;

void shellSort(int array[], int size);

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
 
    shellSort(array, size);

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
 
void shellSort(int array[], int size)                                       
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
 
