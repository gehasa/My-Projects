#include <iostream>
//Made by Gehasa

int binarySearch(int* arr, int firstIndex,int lastIndex, int elem){
    int middle = (firstIndex + lastIndex) / 2;
    if(firstIndex == lastIndex && *(arr + firstIndex) != elem){
        std::cout << "No number found";  
        return -1;
    }
    else if(*(arr + firstIndex) == elem){
        return firstIndex;
    }
    if (*(arr + middle) == elem){
        return middle;
    }
    
    if(*(arr + middle) > elem){
        return binarySearch(arr, firstIndex, middle, elem);
    }
    else{
        return binarySearch(arr, middle + 1, lastIndex, elem);
    }
    
}

int main(){
    int len = 7;
    int arr[] = {1,2,7,9,22,99,102}; 
    int elem = 102;
    if (elem >= *(arr + 0) && elem <= *(arr + len - 1)){
        std::cout << binarySearch(arr, 0,len - 1, elem);
    }
    else{
        std::cout << "No number found";
        return 0;
    }
}