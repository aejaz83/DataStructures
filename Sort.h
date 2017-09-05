#pragma once
#include <queue>

namespace sort
{

    void Swap(int* p1, int* p2)
    {
        int tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;

    }
    void SelectionSort(int arr[], int len)
    {
        for(int i = 0; i < (len - 2); i++)
        {
            int imin = i;

            for(int j = i ; j < len - 1; j++)
            {
                if(arr[j] < arr[imin])
                {
                    imin = j;
                }
            }

            if(imin != i)
            {
                Swap(&arr[i], &arr[imin]);
            }

        }

    }

    void BubbleSort(int arr[], int len)
    {
        for(int i = 0; i < (len - 1); i++)
        {
            for(int j = 0; j < (len - 2); j++)
            {
                if(arr[j] > arr[j + 1])
                {
                    Swap(&arr[j], &arr[j + 1]);

                }
            }
        }

    }

    void InsertionSort(int arr[], int len)
    {
        for(int i = 1; i < len ; i++)
        {

            int value = arr[i];
            int hole = i - 1;

            while(hole >= 0 && (arr[hole] > value))
            {
                arr[hole + 1] = arr[hole];
                hole--;
            }

            arr[hole + 1] = value;
        }

    }

    void Merge(int arr[], int low, int mid, int high)
    {
        std::queue<int> q1, q2;

        for(int i = low; i <= mid; i++)
        {
            q1.push(arr[i]);
        }

        for(int i = mid + 1; i <= high; i++)
        {
            q2.push(arr[i]);
        }

        int i = low;

        while(!q1.empty() && !q2.empty())
        {
            if(q1.front() < q2.front())
            {
                arr[i++] = q1.front();
                q1.pop();
            }
            else
            {
                arr[i++] = q2.front();
                q2.pop();

            }

        }

        while(!q1.empty())
        {
            arr[i++] = q1.front();
            q1.pop();

        }

        while(!q2.empty())
        {
            arr[i++] = q2.front();
            q2.pop();

        }

    }

    void MergeSort(int arr[], int low, int high)
    {
        if(low < high)
        {
            int mid = (low + high) / 2;
            MergeSort(arr, low, mid);
            MergeSort(arr, mid + 1, high);
            Merge(arr, low, mid, high);
        }
    }

    int Partition(int arr[], int low, int high)
    {
        int firsthigh = low;
        int pivot = high;
        int i;

        for(int i = low; i < high; i++)
        {
            if(arr[i] < arr[pivot])
            {
                Swap(&arr[i], &arr[firsthigh]);
                firsthigh++;
            }
        }

        Swap(&arr[pivot], &arr[firsthigh]);
        pivot = firsthigh;

        return pivot;
    }
    void QuickSort(int arr[], int low, int high)
    {
        if(low < high)
        {
            int pivot = Partition(arr, low, high);
            QuickSort(arr, low, pivot - 1);
            QuickSort(arr,  pivot + 1, high);
        }
    }

    int BinarySearchIterative(int arr[], int len, int key)
    {
        int low = 0, high = len - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(arr[mid] == key)
            {
                return mid;
            }
            else if(arr[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }

}