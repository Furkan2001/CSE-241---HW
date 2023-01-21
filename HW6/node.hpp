/*
 * File:   node.hpp
 * Author: Ahmet Furkan Ekinci
 *
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

namespace namespace1 {

    template<typename T>
    class node // This is my node class.. I created it because I want to reach next data and previos things while I use iterator.
    {
    public:
        node() : next(nullptr), prev(nullptr) {} // These are my constructor...
        node(const T& _Data) :data(_Data), next(nullptr), prev(nullptr) {}
        node(const T& _Data, shared_ptr<node<T>> _Prev, shared_ptr<node<T>> _Next) : data(_Data), prev(_Prev), next(_Next) {}
        
        void setData(const T& _Data) { data = _Data;} // These are my set functions...
        void setNext(shared_ptr<node<T>> _Next) { next = _Next; }
        void setPrev(shared_ptr<node<T>> _Prev) { prev = _Prev; }
        
        shared_ptr<node<T>> getNext() const { return next; } // These are my get functions...
        shared_ptr<node<T>> getPrev() const { return prev; }
        T& getData() { return data;}
        
        ~node(){} // This is my destructor...

    private:
        shared_ptr<node<T> >  next;
        shared_ptr<node<T> >  prev;
        T data;
    };
}

using namespace namespace1;

#endif // NODE_HPP
