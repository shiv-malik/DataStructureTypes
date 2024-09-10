#ifndef STATS_H
#define STATS_H
#include <string>
#include <vector>
#include <map>
#include "hashtable.h"

using namespace std;

struct Stats {
    string name;
    int entries = 0;
    int chains = 0;
    double load_factor = 0;
    int min = 0;
    int max = 0;
    int span = 0;
    double mean = 0;
    double stddev = 0;
    vector<int> chain_lengths{};

    Stats(string name, const vector<int> & chain_lengths);

    void print(ostream & out)
    {
        out << "Entries = " << entries << endl;
        out << "Chains = " << chains << endl;
        out << "Load Factor = " << load_factor << endl;
        out << "Min = " << min << endl;
        out << "Max = " << max << endl;
        out << "Span = " << (max-min) << endl;
        out << "Mean = " << mean << endl;
        out << "StdDev = " << stddev << endl;
    }
};

#endif