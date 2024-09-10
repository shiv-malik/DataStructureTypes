#ifndef HASHER_H
#define HASHER_H
#include <iostream>

using namespace std;

struct Hasher
{
    const string name;
    Hasher(const char *nm)
        : name(nm) { }
    virtual size_t hash(string key, int N) const = 0;
};


struct MyHasher : public Hasher
{
    MyHasher() : Hasher{"MyHasher"} {}

    size_t hash(string key, int N) const 
    {
        size_t result = 11;
        size_t mod = 127;
        size_t distributor = (size_t) - 1;

        for (char c : key)
        {
            result *= (c * 659);

            mod *= c/13;

            distributor /= c;
            distributor *= 19;
        }

        return ((distributor % result) % mod) % N;
    }

};
#endif