#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>
using namespace std;

constexpr int MAXWORDS = 45392;

class Sorter
{
protected:
    vector<string> vec;
public:
    const string name;

    Sorter(string my_name) : name(my_name) { }
    void fill(int count, string file_name);
    void print(ostream & out);
    virtual void sort() = 0;
    bool verify_sorted();
};


class QuickSorter : public Sorter
{
public:
    QuickSorter() : Sorter("QuickSorter") { }
    static string select_pivot(vector<string>& vec, int low, int high);
    static int partition(vector<string>& vec, int low, int high);
    static void quicksort(vector<string>& vec, int low, int high);
    void sort() override;
};

class HeapSorter : public Sorter
{
public:
    HeapSorter() : Sorter("HeapSorter") { }
    static void heapify(vector<string>& vec, int high, int root);
    static void heapsort(vector<string>& vec, int low, int high);
    void sort() override;
};

class IntroSorter : public Sorter
{
public:
    IntroSorter() : Sorter("IntroSorter") { }
    static void introsort(vector<string>& vec, int low, int high, int depth_limit);
    void sort() override;
};

class ShellSorter : public Sorter
{
public:
    ShellSorter() : Sorter("ShellSorter") { }
    void gapInsertionSort(vector<string> & avector, int start, int gap);
    void shellSort(vector<string> & avector);
    void sort() override;
};

#endif