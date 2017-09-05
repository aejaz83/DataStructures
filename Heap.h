#pragma once
#include <vector>


using std::vector;

int heap_parent(int n)
{
    if(n == 1)
    {
        return(-1);
    }
    else
    {
        return((int)n / 2);    /* implicitly take floor(n/2) */
    }
}
int heap_young_child(int n)
{
    return(2 * n);
}

void bubble_up(vector<int>& heap, int p)
{
    if(heap_parent(p) == -1)
    {
        return;    /* at root of heap, no parent */
    }

    if(heap[heap_parent(p)] > heap[p])
    {
        std::swap(heap[p], heap[heap_parent(p)]);
        bubble_up(heap, heap_parent(p));
    }
}
void heap_insert(vector<int>& heap, int x)
{

    heap.push_back(x);
    bubble_up(heap, heap.size() - 1);

}
void MakeHeap(vector<int>& heap, int arr[], int n)

{
    int i; /* counter */
    heap.push_back(INT_MAX);

    for(i = 0; i < n; i++)
    {
        heap_insert(heap, arr[i]);
    }
}

void bubble_down(vector<int>& heap, int p)
{
    int c; /* child index */
    int i; /* counter */
    int min_index; /* index of lightest child */
    c = heap_young_child(p);
    min_index = p;

    for(i = 0; i <= 1; i++)
        if((c + i) <= heap.size() - 1)
        {
            if(heap[min_index] > heap[c + i])
            {
                min_index = c + i;
            }
        }

    if(min_index != p)
    {
        std::swap(heap[p], heap[min_index]);
        bubble_down(heap, min_index);
    }
}

int ExtractMin(vector<int>& heap)
{
    int min = -1; /* minimum value */

    if(heap.size() == 0)
    {
        printf("Warning: empty priority queue.\n");
    }
    else
    {
        min = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        bubble_down(heap, 1);
    }

    return(min);
}
void HeapSort(int s[], int n)
{
    //vector<int> vecHeap = new vector<int>();
    vector<int> vecHeap ;
    MakeHeap(vecHeap, s, n);

    for(auto it : vecHeap)
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;


    for(int i = 0; i < n; i++)
    {
        s[i] = ExtractMin(vecHeap);
    }
}

