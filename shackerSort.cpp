#include <iostream>

//Made by Gehasa

void print(int* arr, int len)
{
    for (size_t i = 0; i < len; i++)
    {
        std::cout << *(arr + i) << ' ';
    }
}

void swap(int* arr, int index1, int index2)
{
    int temp = *(arr + index1);
    *(arr + index1) = *(arr + index2);
    *(arr + index2) = temp;
}

void shackerSort(int* arr, int lastIndex, int startIndex)
{
    while (startIndex != lastIndex)
    {
        for (size_t i = 0; i <= lastIndex; i++)
        {
            if (i + 1 <= lastIndex && *(arr + i) > *(arr + i + 1))
            {
                swap(arr, i, i + 1);
            }
            
        }
        for (int i = lastIndex; i >= startIndex; i--)
        {
            if (i - 1 >= startIndex && *(arr + i) < *(arr + i - 1))
            {
                swap(arr, i, i - 1); 
            }
        }
        lastIndex--;
        startIndex++;
    }
}

int main(){
    const int len = 17;
    int arr[] = {2,6,1,2,7,8,3,0,-1,5,-2,-30,1,5,22,100,55};
    shackerSort(arr, len - 1, 0);
    print(arr, len);
}