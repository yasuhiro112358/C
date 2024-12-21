#include <stdio.h>

int linear_search(int arr[], int array_size, int target_value)
{
    for (int index = 0; index < array_size; index++)
    {
        if (arr[index] == target_value)
        {
            return index;
        }
    }
    return -1;
}

int main()
{
    int numbers[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(numbers) / sizeof(numbers[0]); // 配列全体のバイト数を、1つの要素のバイト数で割ることで、配列の要素数を計算
    int target = 16;
    int result = linear_search(numbers, size, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found in the array\n");
    }

    return 0;
}