#include "stats.h"
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;


double compute_stddev(const vector<int>& v)
{
    double sumSquares = 0;
    double mean = accumulate(v.begin(), v.end(), 0) / double(v.size());
    double len = v.size();
    for (auto n : v)
    {
        double diff = n - mean;
        sumSquares += diff * diff;
    }

    return sqrt(sumSquares / len);
}


Stats::Stats(string name, const vector<int> & chain_lengths) 
    : name{name}, 
    entries {accumulate(chain_lengths.begin(), chain_lengths.end(), 0)},
    chains{int(chain_lengths.size())},
    load_factor{double(entries) / chains},
    min{*min_element(chain_lengths.begin(), chain_lengths.end())},
    max{*max_element(chain_lengths.begin(), chain_lengths.end())},
    span{max - min},
    mean{accumulate(chain_lengths.begin(), chain_lengths.end(), 0) / double(chains)},
    stddev{compute_stddev(chain_lengths)}, 
    chain_lengths{chain_lengths} 
{

}