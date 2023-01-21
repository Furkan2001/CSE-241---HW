/*
 * File:   dynamic.hpp
 * Author: Ahmet Furkan Ekinci
 *
 */


#ifndef DYNAMIC_HPP
#define DYNAMIC_HPP

#include "iterator.hpp"
#include "const_iterator.hpp"

namespace namespace3
{

    template <typename T>
    class Dynamic
    {
    public:

        Dynamic(); //Constructor
        Dynamic(const shared_ptr<Dynamic<T>> other); //One parameter constructor
        bool empty() const noexcept; // This function is controlling if my container is empty or not...
        int size() const noexcept; // This function is returning size of my container...
        void insert(const T& value) noexcept; // This funciton insert an element to my container from end...
        void insertback(const T& value) noexcept;  // This funciton insert an element to my container from begining...
        void erase(const T& value); //This function is erasing elements which equals parameter
        void erase(const iterator_<T> other); // This function erase element which be in that point..
        void erase (const iterator_<T> other1, const iterator_<T> other2);// This function erase elements which be between these points..
        void clear() noexcept; // This function is clearing my container...
        iterator_<T> begin() const noexcept {return iterator_<T>(this -> head);} // return begining
        iterator_<T> end() const noexcept; // return end
        const const_iterator_<T> cbegin() const noexcept {return const_iterator_<T>(this -> head);}// return const begining
        const const_iterator_<T> cend() const noexcept; // return const end
        void print_(); //This function is printing my container...
        ~Dynamic(){} //Destructor
        
    private:
        
        shared_ptr<node<T>> head;
        int size_;
        int capacity_;
    };
}

using namespace namespace3;

#endif // DYNAMIC_HPP


