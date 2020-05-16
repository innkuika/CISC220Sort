#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int *makeArray(int size)
{
    int *newArr = new int[size];
    //original array?
    //using rand val less than 100
    for (int i = 0; i < size; i++)
    {
        newArr[i] = rand() % 100;
    }
    return newArr;
}

void printArray(int *arr, int size)
{
    cout << "printing array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
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

void averageTime(int caseNum)
{
    int totalDuration = 0;
    for (int i = 0; i < 5; i++)
    {
        int *arr = makeArray(10000);
        auto start = high_resolution_clock::now();
        switch (caseNum)
        {
        case 0:
            insertionSort(arr, 10000);
            break;
        case 1:
            selectionSort(arr, 10000, 10000);
            break;
        case 2:
            quickSort(arr, 0, 10000);
            break;
        case 3:
            mergeSort(arr, 0, 10000);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "time sorting one array: " << duration.count() << endl;
        totalDuration += duration.count();
    }
    cout << "average sorting time: " << totalDuration / 5 << "\n"
         << endl;
}

int main()
{
    srand(time(NULL));

    // cout<<"testing insertioin sort"<<endl;
    // int *arr = makeArray(NULL, 100);
    // cout<<"before sorting:"<<endl;
    // printArray(arr, 100);
    // insertionSort(arr, 100);
    // cout<<"after sorting:"<<endl;
    // printArray(arr, 100);
    // delete [] arr;

    // cout<<"testing selection sort"<<endl;
    // arr = makeArray(NULL, 100);
    // cout<<"before sorting:"<<endl;
    // printArray(arr, 100);
    // selectionSort(arr, 100, 100);
    // cout<<"after sorting:"<<endl;
    // printArray(arr, 100);
    // delete [] arr;

    // cout<<"testing quick sort"<<endl;
    // arr = makeArray(NULL, 100);
    // cout<<"before sorting:"<<endl;
    // printArray(arr, 100);
    // quickSort(arr, 0, 100);
    // cout<<"after sorting:"<<endl;
    // printArray(arr, 100);
    // delete [] arr;

    // cout<<"testing merge sort"<<endl;
    // arr = makeArray(NULL, 100);
    // cout<<"before sorting:"<<endl;
    // printArray(arr, 100);
    // mergeSort(arr, 0, 100);
    // cout<<"after sorting:"<<endl;
    // printArray(arr, 100);
    // delete [] arr;

    // cout << "timing for insertion sort: " << endl;
    // averageTime(0);
    // cout << "timing for selection sort: " << endl;
    // averageTime(1);
    // cout << "timing for quick sort: " << endl;
    // averageTime(2);
    // cout << "timing for merge sort: " << endl;
    // averageTime(3);

    

    return 0;
}