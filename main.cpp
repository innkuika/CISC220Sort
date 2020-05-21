#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int *makeArray(int size)
/* Parameter: int
 *
 * Return: an int pointer to array
 *
 * This method is used to create an arraya and select random number between 0 and 100.
 */
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
/* Parameter: an int pointer to the array, int
 *
 * Return: None
 *
 * This method is used to print out the array.
 */
{
    cout << "printing array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void insertionSort(int arr[], int length)
/* Parameter: an array, an int
 *
 * Return: None.
 *
 * This method is used to sort the array using the insertionSort. InsertionSort sorted array is
 * built having one item at a time. The array elements are compared with each other sequentially
 * and then arranged simultaneously in some particular order.
 */
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
/* Parameter: an array, int, int
 *
 * Return: None.
 *
 * This method is used to sort array using selectionSort.  SelectionSort repeatedly finding the
 * minimum element (considering ascending order) from unsorted part and putting it at the beginning.
 * The algorithm maintains two subarrays in a given array.
 */
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
/* Parameter: an array, int, int, int
 *
 * Return: None.
 *
 * This function is used to merge two different halves.
 */
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
/* Parameter: array, int, int
 *
 * Return: None.
 *
 * This function is used to call the mergefunction to sort the array.
 */
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



void minMaxSort(int arr[], int len)
/* Parameter: an array, int
 *
 * Return: None.
 *
 * This method works on the minimum and maximum element of the array. It finds the
 * minimum and maximum element from the array and set on the first and last position
 * of the array. Then the array index increment from the first position and
 * decrement from the last position to get the new array.
 */
{
    for (int i = 0; i < len; i++)
    {
        int m = i;
        int k = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[m])
            {
                m = j;
            }
            if (arr[j] > arr[k])
            {
                k = j;
            }
        }
        int tmp = arr[m];
        arr[m] = arr[i];
        arr[i] = tmp;

        tmp = arr[k];
        arr[k] = arr[len - 1];
        arr[len - 1] = tmp;
    }
}

void insertionSort2(int arr[], int beg, int end)
{
    int j = 0;
    int temp = arr[0];
    for (int i = beg; i < end; i++)
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

int help2(int beg, int end, int arr[])
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
void timSort(int arr[], int beg, int end)
/* Parameter:a string pointer
 *
 * Return: None.
 *
 * This method is used to  take advantage of runs of consecutive ordered elements
 * that already exist in most real-world data, natural runs. It iterates over the data
 * collecting elements into runs and simultaneously putting those runs in a stack.
 * Whenever the runs on the top of the stack match a merge criterion, they are merged together.
 * This goes on until all data is traversed; then, all runs are merged two at a time
 * and only one sorted run remains.
 */

{
    int m = help2(beg, end, arr);
    if (m - 1 < 100)
    {
        insertionSort2(arr, beg, m - 1);
    }
    else
    {
        timSort(arr, beg, m - 1);
    }

    if (end - m + 1 < 100)
    {
        insertionSort2(arr, m + 1, end);
    }
    else
    {
        timSort(arr, m + 1, end);
    }
}

void averageTime(int caseNum)
/* Parameter: int
 *
 * Return: None.
 *
 * This function is used to calculate the average running time for each kind of sort method.
 */
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
            break;
        case 4:
            minMaxSort(arr, 10000);
            break;
        case 5:
            timSort(arr, 0, 10000);
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
    cout<<"********************** Part A ***********************"<<endl;
    cout<<"testing insertioin sort"<<endl;
    int *arr = makeArray(100);
    cout<<"before sorting:"<<endl;
    printArray(arr, 100);
    insertionSort(arr, 100);
    cout<<"after sorting:"<<endl;
    printArray(arr, 100);
    delete [] arr;

    cout<<"testing selection sort"<<endl;
    arr = makeArray(100);
    cout<<"before sorting:"<<endl;
    printArray(arr, 100);
    selectionSort(arr, 100, 100);
    cout<<"after sorting:"<<endl;
    printArray(arr, 100);
    delete [] arr;

    cout<<"testing quick sort"<<endl;
    arr = makeArray(100);
    cout<<"before sorting:"<<endl;
    printArray(arr, 100);
    quickSort(arr, 0, 100);
    cout<<"after sorting:"<<endl;
    printArray(arr, 100);
    delete [] arr;

    cout<<"testing merge sort"<<endl;
    arr = makeArray(100);
    cout<<"before sorting:"<<endl;
    printArray(arr, 100);
    mergeSort(arr, 0, 100);
    cout<<"after sorting:"<<endl;
    printArray(arr, 100);
    delete [] arr;

    cout<<"********************** Part B ***********************"<<endl;
    cout << "timing for insertion sort: " << endl;
    averageTime(0);
    cout << "timing for selection sort: " << endl;
    averageTime(1);
    cout << "timing for quick sort: " << endl;
    averageTime(2);
    cout << "timing for merge sort: " << endl;
    averageTime(3);

    cout<<"********************** Part C ***********************"<<endl;
    cout<<"testing min max sort"<<endl;
    arr = makeArray(100);
    cout<<"before sorting:"<<endl;
    printArray(arr, 100);
    minMaxSort(arr, 100);
    cout<<"after sorting:"<<endl;
    printArray(arr, 100);
    delete [] arr;

    cout << "testing time sort" << endl;
    arr = makeArray(1000);
    cout << "before sorting:" << endl;
    printArray(arr, 100);
    timSort(arr, 0, 100);
    cout << "after sorting:" << endl;
    printArray(arr, 100);
    delete[] arr;

    cout << "timing for : " << endl;
    averageTime(4);
    cout << "timing for tim sort: " << endl;
    averageTime(5);

    return 0;
}
