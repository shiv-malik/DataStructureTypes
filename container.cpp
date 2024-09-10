#include "container.h"
#include <fstream>
using namespace std;


//ArrayStack
ArrayStack::ArrayStack(int cap) : Stack{"ArrayStack"}, capacity{cap}, size{0}
{
    buf = new string[capacity];
}

void ArrayStack::push(const string& word)
{
    buf[size] = word;
    ++size;
}

void ArrayStack::pop() { --size; }

string ArrayStack::top() 
{ 
    if (size > 0)
        return buf[size - 1];
    error("ArrayStack", "empty");
}

bool ArrayStack::is_empty() { return (size == 0); }
bool ArrayStack::is_full() { return (size == capacity); }

void ArrayStack::print(ostream& out)
{
    for (int i = size - 1; i >= 0; --i)
        out << buf[i] << " ";
}

ArrayStack::~ArrayStack() { delete[] buf; }

//end ArrayStack




//ListNode

void ListNode::print(ostream& out, ListNode* L)
{
    for (ListNode* trav = L; trav != nullptr; trav = trav->next)
        out << trav->data << " ";
}

void ListNode::delete_list(ListNode* L)
{
    for (ListNode* trav = L; trav != nullptr; )
    {
        ListNode* next = trav->next;
        delete trav;
        trav = next;
    }
}

//end ListNode




//LinkedStack
LinkedStack::LinkedStack() : Stack{"LinkedStack"}, head{nullptr} {}

void LinkedStack::push(const string& word) { head = new ListNode{word, head}; }

void LinkedStack::pop()
{
    if (head != nullptr)
    {
        ListNode* removing = head;
        head = head->next;
        delete removing;
    }
}

string LinkedStack::top()
{
    if (head != nullptr)
        return head->data;
    error("LinkedStack", "empty");
}

bool LinkedStack::is_empty() { return head == nullptr; }
bool LinkedStack::is_full() { return false; }
void LinkedStack::print(ostream& out) { ListNode::print(out, head); }
LinkedStack::~LinkedStack() { ListNode::delete_list(head); }

//end LinkedStack




//ArrayQueue
ArrayQueue::ArrayQueue(int cap) : Queue("ArrayQueue"), capacity{cap}, front{0}, rear{0}
{
    buf = new string[capacity];
}

void ArrayQueue::enq(const string& word)
{
    if (!is_full())
        buf[(rear++) % capacity] = word;
    else
        error("ArrayQueue", "full");
}

void ArrayQueue::deq() 
{ 
    if (!is_empty())   
        ++front;
    else
        error("ArrayQueue", "empty");
}

string ArrayQueue::next() 
{   
    if (!is_empty()) 
        return buf[front % capacity]; 
    error("ArrayQueue", "empty");
}

bool ArrayQueue::is_empty() { return front == rear; }
bool ArrayQueue::is_full() { return rear - front == capacity; }

void ArrayQueue::print(ostream & out)
{
    for (int i = front; i < rear; ++i)
        out << buf[i % capacity] << " ";
}

ArrayQueue::~ArrayQueue() { delete[] buf; }

//end ArrayQueue







//LinkedQueue

LinkedQueue::LinkedQueue() : Queue{"LinkedQueue"}, head{nullptr}, tail{nullptr} {}

void LinkedQueue::enq(const string& word)
{
    if (is_empty())
    {
        head = new ListNode{word, nullptr};
        tail = head;
    }

    else 
    {
        tail->next = new ListNode{word, nullptr};
        tail = tail->next;
    }
}

void LinkedQueue::deq()
{
    if (!is_empty())
    {
        ListNode* next = head->next;
        delete head;
        head = next;

        if (head == nullptr)
            tail = nullptr;
    }
}

string LinkedQueue::next()
{
    if (head != nullptr)
        return head->data;
    error("LinkedQueue", "empty");
}

bool LinkedQueue::is_empty() { return head == nullptr; }
bool LinkedQueue::is_full() { return false; }
void LinkedQueue::print(ostream & out) { ListNode::print(out, head); } 
LinkedQueue::~LinkedQueue() { ListNode::delete_list(head); }

//end LinkedQueue


//Container
ostream & operator << (ostream& out, Container& L)
{
    L.print(out);
    return out;
}

