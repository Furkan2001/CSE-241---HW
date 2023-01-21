/*
 * File:   const_iterator.hpp
 * Author: Ahmet Furkan Ekinci
 *
 */

#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include "node.hpp"

namespace namespace4
{

    template<typename T>
    class const_iterator_
    {
    public:
        
        using iterator_category = random_access_iterator_tag; /* These are tags of my iterator..*/
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        
        const_iterator_() : current(nullptr) {} // No parameter constructor..
        const_iterator_(const const_iterator_<T>& other) {this -> current = other.current;} // Copy constructor
        const_iterator_(const shared_ptr<node<T>>& other) : current(other) {} //One parameter constructor
        ~const_iterator_(){} // Destructor

        const T& operator*() const {return current->getData();}
        T* operator->() {T* temp; temp = &(*current); return temp;}
        
        const_iterator_ operator -(const difference_type& n)
        {
            difference_type i = n;
            
            shared_ptr<node<T>> temp = current;
            while (i-- != n)
                temp--;
                
            return const_iterator_(temp);
            
        }
        const_iterator_ operator +(const difference_type& n)
        {
            difference_type i = 0;
            
            shared_ptr<node<T>> temp = current;
            while (i++ != n)
                temp++;
                
            return const_iterator_(temp);
        }
        
        std::ptrdiff_t operator -(const const_iterator_& other) {return std::distance(other.current,current);}
        operator bool() const {return current != nullptr;}
        
        const_iterator_& operator +=(const std::ptrdiff_t& mvar) {this -> current += mvar; return(*this);}
        const_iterator_& operator -=(const std::ptrdiff_t& mvar) {this -> current -= mvar; return(*this);}

        const_iterator_& operator ++() {current = current->getNext(); return *this;} // prefix ++ opeartor

        const_iterator_ operator ++(int empty) {const_iterator_ start(current); current = current->getNext(); return start;} // postfix
        
        const_iterator_& operator --() {current = current->getPrev(); return *this;} // prefix -- operator
        
        const_iterator_ operator --(int empty) {const_iterator_ start(current); current = current->getPrev(); return start;} // postfix
        
        bool operator == (const const_iterator_& right) const {return (current == right.current);}

        bool operator != (const const_iterator_& right) const {return (current != right.current);}
        
        bool operator <(const const_iterator_& right) const
        { return (this -> current -> getData() < (right.current) -> getData()); }
        
        bool operator >(const const_iterator_& right) const
        { return (this -> current -> getData() > (right.current) -> getData()); }
        
        bool operator >=(const const_iterator_& right) const
        { return (this -> current -> getData() >= (right.current) -> getData()); }
        
        bool operator <=(const const_iterator_ & right) const
        { return (this -> current -> getData() <= (right.current) -> getData()); }

        const_iterator_ & operator=(const const_iterator_ & right)
        {current = right.current; return *this;}
        
    private:
        shared_ptr<node<T>> current;
    
    };
}

using namespace namespace4;

#endif // CONST_ITERATOR_HPP

