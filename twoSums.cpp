/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. 

Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

#include <iostream>

void print(const int* arr, const int len)
{
    for (size_t i = 0; i < len; i++)
    {
        std::cout << *(arr + i) << ' ';
    }
}

int* fillIndexes(int indexesNum, const int len)
{
    
    int* arr = new int[2];
    for (int i = len - 1; i >= 0; i--)
    {
        *(arr + i) = indexesNum % 10;
        indexesNum /= 10;
    }
    return arr;
}

int findFirstIdexesForTwoSum(int* arr,const int target,const int len)
{
    int start = 0;
    while (start < len - 1)
    {
        for (size_t i = start + 1; i < len; i++)
        {
            if (*(arr + start) + *(arr + i) == target)
            {
                return start * 10 + i;
            }
        }
        start++;
    }
    return -1;
}

int main()
{
    int arr[] = {2,7,11,15};
    constexpr int len = 4;
    int sum = 9;
    if(findFirstIdexesForTwoSum(arr, sum, len) > 0)
    {
        int* ptr = fillIndexes(findFirstIdexesForTwoSum(arr, sum, len), 2);
        print(ptr, 2);
        delete[] ptr;
    }
    return 0;
}