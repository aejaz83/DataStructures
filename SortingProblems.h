#pragma once
#include<iostream>
#include<string>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;

namespace sortproblems
{
    //10.1  You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B.
    // a method to merge B into A in sorted order.

    void MergeSortedArrays(int A[], int B[], int lenA,  int lenB)
    {
        int indexMerged = lenA + lenB - 1;
        int indexA = lenA - 1;
        int indexB = lenB - 1;

        while(indexB >= 0)
        {
            if(indexA >= 0 && (A[indexA] > B[indexB]))
            {
                A[indexMerged] = A[indexA];
                indexA--;
            }
            else
            {
                A[indexMerged] = B[indexB];
                indexB--;
            }

            indexMerged--;
        }
    }
    void testMergeSortedArrays()
    {
        int a[] = { 2, 3, 4, 5, 6, 8, 10, 100, 0, 0, 0, 0, 0, 0 };
        int b[] = { 1, 4, 7, 6, 7, 7 };
        MergeSortedArrays(a, b, 8, 6);

        for(auto var : a)
        {
            cout << var << " ";
        }

        cout << endl;
    }


    int CompareAnagram(string s1, string s2)
    {
        std::sort(begin(s1), end(s1));
        std::sort(begin(s2), end(s2));
        return s1 == s2;
    }
    int PartitionAnagram(string arr[], int low, int high)
    {
        int firsthigh = low;
        int pivot = high;
        int i;

        for(int i = low; i < high; i++)
        {

            if(CompareAnagram(arr[i], arr[pivot]))
            {
                std::swap(arr[i], arr[firsthigh]);
                firsthigh++;
            }
        }

        std::swap(arr[pivot], arr[firsthigh]);
        pivot = firsthigh;

        return pivot;
    }
    void QuickSortAnagram(string arr[], int low, int high)
    {
        if(low < high)
        {
            int pivot = PartitionAnagram(arr, low, high);
            QuickSortAnagram(arr, low, pivot - 1);
            QuickSortAnagram(arr, pivot + 1, high);
        }
    }

    /*Question 10.2 Write a method to sort an array of strings so that all the anagrams are next to each other.*/
    void testQuickSortAnagram()
    {
        string array[] = { "apple", "banana", "carrot", "ele", "duck", "papel", "tarroc", "cudk", "eel", "lee" };
        QuickSortAnagram(array, 0, 9);

        for(auto var : array)
        {
            cout << var << " ";
        }

        cout << endl;
    }

    //10.3 search in rotated array which is sorted.
    // http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
    int BinarySearch(int arr[], int low, int high, int key)
    {
        if(high < low)
        {
            return -1;
        }

        int mid = (low + high) / 2;  /*low + (high - low)/2;*/

        if(key == arr[mid])
        {
            return mid;
        }

        if(key > arr[mid])
        {
            return BinarySearch(arr, (mid + 1), high, key);
        }

        return BinarySearch(arr, low, (mid - 1), key);
    }
    /* Function to get pivot. For array 3, 4, 5, 6, 1, 2 it returns
    3 (index of 6) */
    int FindPivot(int arr[], int low, int high)
    {
        // base cases
        if(high < low)
        {
            return -1;
        }

        if(high == low)
        {
            return low;
        }

        int mid = (low + high) / 2;   /*low + (high - low)/2;*/

        if(mid < high && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        if(mid > low && arr[mid] < arr[mid - 1])
        {
            return (mid - 1);
        }

        if(arr[low] >= arr[mid])
        {
            return FindPivot(arr, low, mid - 1);
        }

        return FindPivot(arr, mid + 1, high);
    }
    /* Searches an element key in a pivoted sorted array arrp[]
    of size n */
    int PivotedBinarySearch(int arr[], int n, int key)
    {
        int pivot = FindPivot(arr, 0, n - 1);

        if(pivot == -1)
        {
            return  BinarySearch(arr, 0, n - 1, key);
        }

        if(arr[pivot] == key)
        {
            return pivot;
        }

        if(arr[0] <= key)
        {
            return BinarySearch(arr, 0, pivot - 1, key);

        }

        return BinarySearch(arr, pivot + 1, n - 1, key);
    }

    int testPivotedBinarySearch()
    {
        // Let us search 3 in below array
        int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
        int n = sizeof(arr1) / sizeof(arr1[0]);
        int key = 3;
        printf("Index: %d\n", PivotedBinarySearch(arr1, n, key));
        return 0;
    }
    ////////////10.5//////////////////////////////////////
    //10.3 search in a sorted array of strings which has empty strings intersped in it

    int GetNearestValidString(string arr[], int index, string key)
    {
        int i = index, j = index;

        while(arr[i] == "")
        {
            i++;
        }

        while(arr[j] == "")
        {
            j--;
        }

        if(arr[i] == key)
        {
            return i;
        }

        if(arr[j] == key)
        {
            return j;
        }

        if(arr[i] > key && arr[j] > key)
        {
            return j;
        }
        else if(arr[i] < key && arr[j] < key)
        {
            return i;
        }
        else
        {
            return -1;
        }

    }
    int BinarySearchForString(string arr[], int low, int high, string key)
    {
        if(high < low)
        {
            return -1;
        }

        int mid = (low + high) / 2;  /*low + (high - low)/2;*/

        if(key == arr[mid])
        {
            return mid;
        }

        if(arr[mid] == "")
        {
            int index =  GetNearestValidString(arr, mid, key);

            if(arr[index] == key)
            {
                return index;
            }
            else if(index == -1)
            {
                return -1;
            }
            else if(arr[index] > key)
            {
                return BinarySearchForString(arr, low, (index - 1), key);
            }
            else
            {
                return BinarySearchForString(arr, (index + 1), high, key);
            }
        }

        if(key > arr[mid])
        {
            return BinarySearchForString(arr, (mid + 1), high, key);
        }

        return BinarySearchForString(arr, low, (mid - 1), key);
    }

    void testBinarySearchForString()
    {
        string stringList[] = { "apple", "", "", "banana", "", "", "", "carrot", "duck", "", "", "eel", "", "flower" };
        cout << "duck appears at location " << BinarySearchForString(stringList, 0, 13, string("duck")) << endl;
        cout << "banana appears at location " << BinarySearchForString(stringList, 0, 13, string("banana")) << endl;
        cout << "apple appears at location " << BinarySearchForString(stringList, 0, 13, string("apple")) << endl;
        cout << "flower appears at location " <<  BinarySearchForString(stringList, 0, 13, string("flower")) << endl;
        /*for(auto& s : stringList)
        {
            cout << " appears at location " + BinarySearchForString(stringList, 0, 13, s) << endl;
        }*/
    }

    //10.9 sorted matrix search: Given an M*N matrix in which row and column are sorted in ascending order,
    // find an element in it
    //0  1  2   3   0 4 8
    //4  5  6   7   1 5 9
    //8  9  10  11  2 6 10
    //              3 7 11


    /* bool BinarySearchMatrix(int mat[][4], int lowr, int highr, int lowc, int highc, int key)
     {
         if((lowr > highr) || (lowc > highc))
         {
             return false;
         }

         int midr = (lowr + highr) / 2;
         int midc = (lowc + highc) / 2;

         if(mat[midr][midc] == key)
         {
             return true;
         }
         else if(mat[midr][midc] < key)
         {
             return BinarySearchMatrix(mat, lowr, midr - 1, lowc, midc - 1, key);
         }
         else
         {
             return BinarySearchMatrix(mat,  midr + 1, highr,   midc + 1, highc, key);

         }
     }*/


    bool SortedMatrixSearch(int mat[][4], int key)
    {

        bool res = false;
        int i = 0, j = 3;


        while((i <= 3) && (j >= 0))
        {
            if(mat[i][j] == key)
            {
                res = true;
                break;
            }
            else if(mat[i][j] > key)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return res;

    }

    void testSortedMatrixSearch()
    {
        int mat[4][4] = { { 10, 20, 30, 40 },
            { 15, 25, 35, 45 },
            { 27, 29, 37, 48 },
            { 32, 33, 39, 50 }
        };
        cout << "search for 27: " << SortedMatrixSearch(mat, 27) << endl;
        cout << "search for 25: " << SortedMatrixSearch(mat, 25) << endl;
        cout << "search for 125: " << SortedMatrixSearch(mat, 125) << endl;


    }
}