#include "sorter.h"
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;


//QuickSorter
string QuickSorter::select_pivot(vector<string>& vec, int low, int high)
{
    int mid = (low + high) / 2;
    if (vec[mid] < vec[low])
        swap(vec[mid], vec[low]);
    if (vec[high] < vec[low])
        swap(vec[high], vec[low]);
    if (vec[high] < vec[mid])
        swap(vec[high], vec[mid]);
    return vec[high];
}

int QuickSorter::partition(vector<string>& vec, int low, int high)
{
    string pivot = select_pivot(vec, low, high);
    int below = low, above = high - 1;
    while (true)
    {
        while (vec[below] < pivot) 
            ++below;
        while (pivot < vec[above])
            --above;
        if (below < above)
            swap(vec[below++], vec[above--]);
        else
            break;
    }
    swap(vec[below], vec[high]);
    return below;

}

void QuickSorter::quicksort(vector<string>& vec, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(vec, low, high);
        quicksort(vec, low, pivot - 1);
        quicksort(vec, pivot + 1, high);
    }
}

void QuickSorter::sort() { quicksort(vec, 0, vec.size() - 1); }





//HeapSorter
void HeapSorter::heapify(vector<string>& vec, int high, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < high && vec[left] > vec[largest])
        largest = left;

    if (right < high && vec[right] > vec[largest])
        largest = right;

    if (largest != root)
    {
        swap(vec[root], vec[largest]);
        heapify(vec, high, largest);
    }
}

void HeapSorter::heapsort(vector<string>& vec, int low, int high)
{
    int size = vec.size();
    for (int root = size / 2 - 1; root >= 0; --root)
        heapify(vec, size, root);
    
    for (int e = size - 1; e > 0; --e)
    {
        swap(vec[0], vec[e]);
        heapify(vec, e, 0);
    }
}

void HeapSorter::sort() { heapsort(vec, 0, vec.size() - 1); }



//ShellSorter
void ShellSorter::gapInsertionSort(vector<string> & avector, int start, int gap)
{
    int size = avector.size();
    for (int i = start + gap; i < size; i += gap)
    {
        string cur = avector[i];
        int pos = i;

        while (pos >= gap && avector[pos - gap] > cur)
        {
            avector[pos] = avector[pos - gap];
            pos -= gap;
        }

        avector[pos] = cur;
    }
}

void ShellSorter::shellSort(vector<string> & avector)
{
    int gap = avector.size() / 2;
    while (gap > 0)
    {
        for (int start = 0; start < gap; ++start, gap /= 2)
            gapInsertionSort(avector, start, gap);
    }
}

void ShellSorter::sort() { shellSort(vec); }
