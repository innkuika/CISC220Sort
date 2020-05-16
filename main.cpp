#include <iostream>
using namespace std;

int *makeArray(int *arr, int size)
{
    int *newArr = new int[size];
    //original array?
    //using rand val less than 100
    for (int i = 0; i < size; i++)
    {
        newArr[i] = rand() % 100;
    }
}

void printArray(int *arr, int size)
{
    cout << "printing array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", " << endl;
    }
}

void insertionSort(int arr[], int length)
{
    int j = 0;
    int temp = arr[0];
    for (int i = 1; i < length; i++)
    {
        j = i;
        temp = arr[j];
        j--;
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return;
}

void selectionSort(int arr[], int len, int loops)
{
    for (int i = 0; i < loops; i++)
    {
        int m = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[m])
            {
                m = j;
            }
        }
        int tmp = arr[m];
        arr[m] = arr[i];
        arr[i] = tmp;
    }
}

void mergeSort(int arr[], int l1, int l2)
{
    int k;
    if (l1 < l2)
    {
        k = (l1 + l2) / 2;
        mergeSort(arr, l1, k);
        mergeSort(arr, k + 1, l2);
        merge(arr, l1, k, l2);
    }
}
void merge(int arr[], int le, int m, int r)
{ // the helper function for the above sorting algorithm
    int i, j, k;
    int lenL = m - le + 1;
    int lenR = r - m;

    int leftArr[lenL];
    // the sorted left array
    int rightArr[lenR];
    // the sorted right array
    for (i = 0; i < lenL; i++)
    {
        leftArr[i] = arr[le + i];
    }
    for (j = 0; j < lenR; j++)
    {
        rightArr[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = le;
    while (i < lenL && j < lenR)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < lenL)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < lenR)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

int help(int beg, int end, int arr[])
{
    int x = beg;
    int y = end;
    int tmp;
    int j = arr[x++];
    while (x <= y)
    {
        while (arr[x] < j)
            x++;
        while (arr[y] > j)
            y--;
        if (x <= y)
        {
            tmp = arr[x];
            arr[x] = arr[y];
            arr[y] = tmp;
            x++;
            y--;
        }
    }
    arr[beg] = arr[y];
    arr[y] = j;
    return y;
}
void quickSort(int arr[], int beg, int end)
{
    int m = help(beg, end, arr);
    if (m - 1 > beg)
    {
        quickSort(arr, beg, m - 1);
    }
    if (m + 1 < end)
    {
        quickSort(arr, m + 1, end);
    }
}

int main()
{
    return 0;
}