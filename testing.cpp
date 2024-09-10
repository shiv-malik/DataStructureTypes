#include "Timer.h"
//#include <Container Type Here>
#include <fstream>

void insert_all_words(int k, string file_name, Container& L)
{
    Timer t;
    double eTime;
    ifstream in {file_name};
    int limit = k * MAXWORDS / 10;
    t.start();
    for (string word; (in >> word) && limit > 0; --limit)
        L.insert(word);

    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tInsert = " << eTime << endl;
}

//find all words not for Stacks/Queues
void find_all_words(string file_name, Container& L)
{
    Timer t;
    double eTime;
    ifstream in {file_name};
    int limit = k * MAXWORDS / 10;
    t.start();
    for (string word; (in >> word) && limit > 0; --limit)
        L.find(word);

    t.elapsedUserTime(eTime);
    in.close();
    cout << "F = " << eTime << endl;
}

void remove_all_words(int k, string file_name, Container& L)
{
    Timer t;
    double eTime;
    ifstream in {file_name};
    int limit = k * MAXWORDS / 10;
    t.start();
    for (; limit > 0; --limit)
        L.remove();

    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tRemove = " << eTime << endl;
}

void measure_Container(string file_name, Container& L)
{
    cout << L.name << endl;

    for (int k = 1; k <= 10; ++k)
    {
        cout << "\tK = " << k << endl;
        insert_all_words(k, file_name, L);
        find_all_words(k, file_name, L);
        remove_all_words(k, file_name, L);
        if (!L.is_empty())
            error(L.name, "is not empty");
    }
}
