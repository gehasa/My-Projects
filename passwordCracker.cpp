#include <iostream>

void makeCountersZero(int* arr, int len)
{
    for (size_t i = 0; i < len; i++)
    {
        arr[i] = 0;
    }
}

void print(char* arr)
{
    for (size_t i = 0; arr[i] != '\0'; i++)
    {
        std::cout << arr[i];
    }
    
}

bool isMatching(char *pass, char *guess, const int len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (*(pass + i) != *(guess + i))
        {
            return false;
        }
        
    }
    return true;
}

void moveCounters(int* arr, char* allSym, bool *isLastChar)
{
    if (isLastChar[6] == 1 && arr[7] == 82)
    {
        isLastChar[7] == 1;
        return;
    }
    arr[7]++;
    if (arr[7] == 82 && isLastChar[6] != 1)
    {
        if (isLastChar[5] == 1 && arr[6] == 82)
        {
            isLastChar[6] == 1;
        }
        else
        {
            arr[6]++;
        }
        arr[7] = 0;
        if (arr[6] == 82 && isLastChar[5] != 1)
        {
            if (isLastChar[4] == 1 && arr[5] == 82)
            {
                isLastChar[5] == 1;
            }
            else
            {
                arr[5]++;
            }
            arr[6] = 0;
            if (arr[5] == 82 && isLastChar[4] != 1)
            {
                if (isLastChar[3] == 1 && arr[4] == 82)
                {
                    isLastChar[4] == 1;
                }
                else
                {
                    arr[4]++;
                }
                arr[5] = 0;
                if (arr[4] == 82 && isLastChar[3] != 1)
                {
                    if (isLastChar[2] == 1 && arr[3] == 82)
                    {
                        isLastChar[3] == 1;
                    }
                    else
                    {
                        arr[3]++;
                    }
                    arr[4] = 0;
                    if (arr[3] == 82 && isLastChar[2] != 1)
                    {
                        if (isLastChar[1] == 1 && arr[2] == 82)
                        {
                            isLastChar[2] == 1;
                        }
                        else
                        {
                            arr[2]++;
                        }
                        arr[3] = 0;
                        if (arr[2] == 82 && isLastChar[1] != 1)
                        {
                            if (isLastChar[0] == 1 && arr[1] == 82)
                            {
                                isLastChar[1] == 1;
                            }
                            else
                            {
                                arr[1]++;
                            }
                            arr[2] = 0;

                            if (arr[1] == 82 && isLastChar[0] != 1)
                            {
                                if (arr[0] == 82)
                                {
                                    isLastChar[0] = 1;
                                }
                                arr[0]++;
                                arr[1] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

void guessPass(char *allChars,char* pass, const int len)
{
    char *arr = new char[len +1];
    *(arr + len) = '\0';
 
    int counters[8];
    makeCountersZero(counters, len);
    bool isLastChar[8] = {0};

    while (*(arr) != *(allChars + 82) && *(arr + len - 1) != *(allChars + 82))
    {
        for (size_t i = 0; arr[i] != '\0'; i++)
        {
            arr[i] = allChars[counters[i]];
        }
        moveCounters(counters, allChars, isLastChar);
        if (isMatching(pass, arr, len))
        {
            std::cout << arr;
            delete[] arr;
            return;
        }
    }
    std::cout << arr;
    delete[] arr;
    std::cout << "Invalid Pass";
    return;
}

int main()
{
    char pass[] = "aaaaaabc";
    char allChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+,-./:;<=>?@[]^_`{|}~";
    guessPass(allChars, pass, 8);
    return 0;
}