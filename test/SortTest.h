#pragma once
#include "Sort.h"
#include "Heap.h"
#include <iostream>

using namespace std;
namespace sort
{

    void testSelectionSort()
    {
        int arr[] = {5, 23, 0, 55, 8, 34, 4325, 2, 43, 42153};
        SelectionSort(arr, 10);
        cout << "Sorted using selection sort: ";

        for(auto var : arr)
        {
            cout << var << " ";
        }

        cout << endl;
    }

    void testBubbleSort()
    {
        int arr[] = { 5, 23, 0, 55, 8, 34, -99, 2, 4, 42153 };
        BubbleSort(arr, 10);
        cout << "Sorted using bubble sort: ";

        for(auto var : arr)
        {
            cout << var << " ";
        }

        cout << endl;
    }

    void testInsertonSort()
    {
        int arr[] = { 5, 23, 67, -55, 8, 304, 2, 0, -99, 2, 4, 42153 };
        InsertionSort(arr, 12);
        cout << "Sorted using insertion sort: ";

        for(auto var : arr)
        {
            cout << var << " ";
        }

        cout << endl;
    }


    void testMergeSort()
    {
        int arr[] = { 5, 23, 67, -55, 8, 304, 2, 0, -99, 2, 4, 42153 };
        MergeSort(arr, 0, 11);
        cout << "Sorted using Merge sort: ";

        for(auto var : arr)
        {
            cout << var << " ";
        }

        cout << endl;
    }

    void testQuickSort()
    {
        int arr[] = { 5, 23, 67, -55, 8, 304, 2, 0, -99, 2, 4, 42153 };
        // int arr[] = { 5, 23, 67};
        QuickSort(arr, 0, 11);
        cout << "Sorted using Quick sort: ";

        for(auto var : arr)
        {
            cout << var << " ";
        }

        cout << endl;
    }

    void testHeapSort()
    {
        int arr[] = { 5, 23, 67, -55, 8, 304, 2, 0, -99, 2, 4, 42153 };
        // int arr[] = { 5, 23, 67};
        HeapSort(arr, 12);
        cout << "Sorted using Heap  sort: ";

        for(auto var : arr)
        {
            cout << var << " ";
        }

        cout << endl;
    }

    void testBinarySearchIterative()
    {
        int arr[] = { 5, 23, 67, -55, 8, 304, 2, 0, -99, 2, 4, 42153 };
        MergeSort(arr, 0, 11);
        cout << "Sorted using Merge sort: ";

        int ret = BinarySearchIterative(arr, 12, 304);

        if(ret != -1)
        {
            cout << "Found 304 in pos: " << ret << " val: " << arr[ret] << endl;;
        }

        ret = BinarySearchIterative(arr, 12, 7);

        if(ret == -1)
        {
            cout << "Didnot find 7 : " << ret << endl;
        }

        cout << endl;
    }
}
