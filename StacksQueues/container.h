#ifndef CONTAINER_H
#define HEADER_H

#include <iostream>

using namespace std;

constexpr int MAXWORDS = 45392;

struct Container
{
    const string name;
    Container(const string & new_name)
        : name(new_name) { }

    virtual void insert( const string & word) = 0;
    virtual void remove() = 0;
    virtual string peek() = 0;
    virtual bool is_empty() = 0;
    virtual bool is_full() = 0;
    virtual void print(ostream & out) = 0;
    virtual ~Container() { }
    Container(const Container & L) = delete;
    Container& operator =(const Container & L) = delete;
};

struct Stack
    : public Container
{
    Stack(const string & new_name) : Container(new_name) { }
    virtual void push(const string & word) = 0;
    virtual void pop() = 0;
    virtual string top() = 0;
 
    virtual void insert( const string & word) { push(word); }
    virtual void remove() { pop(); }
    virtual string peek() { return top(); }
};

struct Queue
    : public Container
{
    Queue(const string & new_name) : Container(new_name) { }
    virtual void enq(const string & word) = 0;
    virtual void deq() = 0;
    virtual string next() = 0;
 
    virtual void insert( const string & word) { enq(word); }
    virtual void remove() { deq(); }
    virtual string peek() { return next(); }
};

ostream & operator << (ostream & out, Container & L);

class ArrayStack
    : public Stack
{
    const int capacity;
    int size;
    string * buf;
public:
    ArrayStack(int cap = MAXWORDS);
    void push(const string & word);
    void pop();
    string top();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~ArrayStack();
};


struct ListNode {
    string data;
    ListNode * next;
    ListNode(string new_data, ListNode * new_next)
        : data(new_data), next(new_next) { }
    static void print(ostream & out, ListNode * L);
    static void delete_list(ListNode * L);
};

class LinkedStack
    : public Stack
{

    ListNode * head;

public:
    LinkedStack();
    void push(const string & word);
    void pop();
    string top();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~LinkedStack();
};

class ArrayQueue
    : public Queue
{
    const int capacity;
    int front, rear;
    string * buf;
public:
    ArrayQueue(int cap = MAXWORDS);
    void enq(const string & word);
    void deq();
    string next();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~ArrayQueue();
};

class LinkedQueue
    : public Queue
{
    ListNode * head, * tail;
public:
    LinkedQueue();
    void enq(const string & word);
    void deq();
    string next();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~LinkedQueue();
};

#endif
