#ifndef ListADT_h
#define ListADT_h

#include <iostream>

using namespace std;

template <class T>
class ListADT
{
public:
    virtual void insert(T) = 0;
    virtual void remove(T) = 0;
    virtual bool search(T) = 0;
    virtual void print() = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual ~ListADT() {}
};

#endif /* ListADT_h */
