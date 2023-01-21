/*
 * File:   iterator.hpp
 * Author: Ahmet Furkan Ekinci
 *
 */


#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "node.hpp"

namespace namespace2
{

    template<typename T>
    class iterator_
    {
    public:
        
        using iterator_category = random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        
        iterator_() : current(nullptr) {}
        iterator_(const iterator_<T>& other) {this -> current = other.current;}
        iterator_(const shared_ptr<node<T>> other) : current(other) {}
        ~iterator_(){}

        T& operator*() const {return current->getData();}
        T* operator->() {T* temp; temp = &(*current); return temp;}
        
        
        iterator_ operator -(const int& n)
        {
            int i = 0;
            
            shared_ptr<node<T>> temp = current;
            while (i++ != n)
                temp = temp -> getPrev();
                
            return iterator_(temp);
        }
        
        
        iterator_ operator +(const int& n)
        {
            int i = 0;
            
            shared_ptr<node<T>> temp = this -> current;
            while (i++ != n)
                temp = temp -> getNext();
            return iterator_(temp);
        }
        
        const int operator -(const iterator_& other)
        {
            int i = 0;
  
            shared_ptr<node<T>> temp = other.current;
            while (temp != nullptr)
            {
                temp = temp -> getNext();
                i++;
            }
            return i;
        } 
        
        iterator_& operator +=(const int& mvar) {(*this) += mvar; return(*this);}
        iterator_& operator -=(const int& mvar) {(*this) -= mvar; return(*this);}

        iterator_& operator ++() {if (current) current = current->getNext(); return *this;} // prefix ++ opeartor

        iterator_ operator ++(int empty) {iterator_ start(current); if (current) current = current->getNext(); return start;} // postfix
        
        iterator_& operator --() {if (current) current = current->getPrev(); return *this;} // prefix -- operator
        
        iterator_ operator --(int empty) {iterator_ start(current); if (current) current = current->getPrev(); return start;} // postfix
        
        bool operator == (const iterator_ & right) const {return (current == right.current);}
        
        bool operator == (const shared_ptr<node<T>> right) const {return (current == right);}

        bool operator != (const iterator_ & right) const {return (current != right.current);}
        
        bool operator != (const shared_ptr<node<T>> right) const {return (current != right);}
        
        bool operator <(const iterator_ & right) const
        {
        	if (right == (*this))
        		return (0);
			return (this -> current -> getData() < (right.current) -> getData()); 
        }

        
        bool operator >(const iterator_ & right) const
        { 
        	if (right == (*this))
        		return (0);
        	return (this -> current -> getData() > (right.current) -> getData());
        }
        
        bool operator >=(const iterator_ & right) const
        { return (this -> current -> getData() >= (right.current) -> getData()); }
        
        bool operator <=(const iterator_ & right) const
        { return (this -> current -> getData() <= (right.current) -> getData()); }

        iterator_& operator=(const iterator_& right)
        {this -> current = right.current; return *this;}
        
        iterator_& operator=(const shared_ptr<node<T>> right)
        {this -> current = right; return *this;}
        
        const shared_ptr<node<T>> getCurrent() const noexcept {return current;}

    private:
        shared_ptr<node<T>> current;
    
    };
}

using namespace namespace2;

#endif // ITERATOR_HPP





