#include "hashtable.h"
#include <iostream>

using namespace std;

ListNode* ListNode::find(string key, ListNode* L)
{
    for (ListNode* trav = L; trav != nullptr; trav = trav->next)
    {
        if (trav->data == key)
            return trav;
    }

    return nullptr;
}

ListNode* ListNode::insert(string key, ListNode* L)
{
    return new ListNode {key, L};
}

ListNode* ListNode::remove(string key, ListNode* L)
{
    for (ListNode* trav = L, * prev = nullptr; trav != nullptr; prev = trav, trav = trav->next)
    {
        if (trav->data == key)
        {
            if (prev == nullptr)
                L = trav->next;
            else
                prev->next = trav->next;
            delete trav;
            break;
        }
    }

    return L;
}

void ListNode::print(ostream & out, ListNode * L)
{
    for (ListNode* trav = L; trav != nullptr; trav = trav->next)
        out << trav->data << " ";
}

int ListNode::length(ListNode * L)
{
    int count = 0;
    for (ListNode* trav = L; trav != nullptr; trav = trav->next, ++count)
        continue;

    return count;
}

void ListNode::delete_list(ListNode * L)
{
    for (ListNode* trav = L; trav != nullptr; )
    {
        ListNode* next = trav->next;
        delete trav;
        trav = next;
    }
}





void HashTable::insert( const string & word)
{
    size_t hashValue = hasher.hash(word, capacity);
    buf[hashValue] = ListNode::insert(word, buf[hashValue]);
}

bool HashTable::find( const string & word)
{
    size_t hashValue = hasher.hash(word, capacity);
    return ListNode::find(word, buf[hashValue]) != nullptr;
}

void HashTable::remove( const string & word)
{
    size_t hashValue = hasher.hash(word, capacity);
    buf[hashValue] = ListNode::remove(word, buf[hashValue]);
}

bool HashTable::is_empty()
{
    for (size_t i = 0; i < capacity; ++i)
    {
        if (buf[i] != nullptr)
            return false;
    }

    return true;
}

bool HashTable::is_full()
{
    return false;
}

void HashTable::print(ostream & out)
{
    for (size_t i = 0; i < capacity; ++i)
        ListNode::print(out, buf[i]);
}
HashTable::~HashTable()
{
    for (size_t i = 0; i < capacity; ++i)
        ListNode::delete_list(buf[i]);

    delete[] buf;
}

size_t HashTable::number_of_entries()
{
    size_t totalLength = 0;
    for (size_t i = 0; i < capacity; ++i)
        totalLength += ListNode::length(buf[i]);
    return totalLength;
}

size_t HashTable::number_of_chains()
{
    return capacity;
}

void HashTable::get_chain_lengths(vector<int> & v)
{
    for (size_t i = 0; i < capacity; ++i)
        v.push_back(ListNode::length(buf[i]));
}