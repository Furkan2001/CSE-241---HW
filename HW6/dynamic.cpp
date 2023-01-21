/*
 * File:   dynamic.cpp
 * Author: Ahmet Furkan Ekinci
 *
 */
#include "dynamic.hpp"

template <typename T>
Dynamic<T>::Dynamic()
{
    head = nullptr;
    this -> size_ = 0;
    this -> capacity_ = 0;
}

template <typename T>
Dynamic<T>::Dynamic(const shared_ptr<Dynamic<T>> other)
{}

template <typename T>
bool Dynamic<T>::empty() const noexcept
{
    if (size_ == 0)
        return (1);
    return (0);
}

template <typename T>
int Dynamic<T>::size() const noexcept
{
    return (size_);
}

template <typename T>
void Dynamic<T>::insert(const T& value) noexcept
{
    if (this -> size_ == this -> capacity_) //If size is greater or equal than capacity then increse capacity...
        this -> capacity_ += 50;
    
    shared_ptr<node<T>> current = this -> head;
    shared_ptr<node<T>> new_(make_shared<node<T>>(value));
    
    if (this->head == nullptr) //If there is no any element in container then do this...
    {
        this->head = new_;
    }
    else
    {
        while(current -> getNext() != nullptr) // I found end of my container
            current = current -> getNext();
        current -> setNext(new_);  // I am setting in this three lines insert things...
        new_ -> setPrev(current);
        new_ -> setNext(nullptr);
    }
    this -> size_++;
}

template <typename T>
void Dynamic<T>::insertback(const T& value) noexcept
{
    if (this -> size_ == this -> capacity_)
        this -> capacity_ += 50;
    shared_ptr<node<T>> new_(make_shared<node<T>>(value));
    
    if (this->head == nullptr) //If there is no any element in container then do this...
    {
        this->head = new_;
    }
    else // I added to first index my new node...
    {
        new_ -> setNext(this -> head);
        new_ -> setPrev(nullptr);
        this -> head -> setPrev(new_);
        this -> head = new_;
    }
    this -> size_++;
}


template <typename T>
void Dynamic<T>::erase (const iterator_<T> other)
{
    shared_ptr<node<T>> current2 = this -> head; // Firstly current2 hold head of my container
    
    if (other == current2) // if they are equal then erase it...
    {
        this -> head = this -> head -> getNext();
        return;
    }
    
    while(other != current2 -> getNext())
        current2 = current2 -> getNext();
    if (current2 -> getNext() -> getNext() == nullptr)
    {
        current2 -> setNext(nullptr);
    }
    else //I erased in here
    {
        current2 -> setNext(current2 -> getNext() -> getNext());
        current2 -> getNext() -> setPrev(current2);
    }
    size_--;
}

template <typename T>
void Dynamic<T>::erase (const iterator_<T> other1, const iterator_<T> other2)
{
    shared_ptr<node<T>> now = other1.getCurrent();
    shared_ptr<node<T>> current = other1.getCurrent();
    
    if (now -> getPrev() == nullptr) // İf it equals nullptr then it could be problem for memory leak...
    {
        if (other2.getCurrent() == nullptr) //Both of them nullptr then do not anything...
        {
            return;
        }
        else
        {
            while (other2 != current)
            {
                current = current -> getNext();
            	size_--;
            }
            this -> head -> setNext(current); // I am setting in this three lines erase things...
            current -> setPrev(now);
            this -> head = this -> head -> getNext();
        }
    }
    else
    {
        now = now -> getPrev();
        
        while (other2 != current)
        {
            current = current -> getNext();
        	size_--;
        }
        
        now -> setNext(current);  // I am setting in this two lines erase things...
        current -> setPrev(now);
    }
}

template <typename T>
void Dynamic<T>::erase (const T& value) 
{
    int flag;
    
    flag = 0;  // I created this variable to hold there are how much member of this value in my container...
    shared_ptr<node<T>> current = this -> head;
    
    if (size_ == 0)
        throw "You can not erase this value because there is not any value in here...";
    
    while (current != nullptr)
    {
        if (current -> getData() == value)
            flag++;
        current = current -> getNext();
    }
    if (flag == 0)
        throw "You can not erase this value because there is not this value in here...";
    
    current = this -> head;
    if (size_ == 1)
    {
        head = (nullptr);
        size_--;
        return;
    }
    
    current = this -> head;
    if (size_ == 2)
    {
        if (flag == 1)
        {
            if (current -> getData() == value)
                head = head -> getNext();
            else if (current -> getNext() -> getData() == value)
                current -> setNext(nullptr);
            size_--;
        }
        else
        {
            head = nullptr;
            size_ -= 2;
        }
        return;
    }
    while (flag-- != 0)
    {
        if (this -> head -> getData() == value)
        {
            head = head -> getNext();
            size_--;
            if (flag == 1)
                return;
        }
        else
        {
            current = this -> head;
            while(current -> getNext() -> getData() != value)
                current = current -> getNext();
            
            if (current -> getNext() -> getNext() == nullptr)
            {
                current -> setNext(nullptr);
                size_--;
                if (flag == 1)
                    return;
            }
            else
            {
                current -> setNext(current -> getNext() -> getNext());
                current -> getNext() -> setPrev(current);
                size_--;
            }
        }
    }
}

template <typename T>
iterator_<T> Dynamic<T>::end() const noexcept  // I found the end of my container..
{
    shared_ptr<node<T>> temp = this -> head;

    while (temp -> getNext()!= nullptr)
        temp = temp -> getNext();
    
    return iterator_<T>(temp);
}

template <typename T>
const const_iterator_<T> Dynamic<T>::cend() const noexcept  // I found the end of my container and return constantly..
{
    shared_ptr<node<T>> temp = this -> head;
    while (temp -> getNext()!= nullptr)
        temp = temp -> getNext();

   // temp = temp -> getNext();
    return const_iterator_<T>(temp);
}

template <typename T>
void Dynamic<T>::clear() noexcept  // I cleared inside my container...
{
    size_ = 0;
    head = nullptr;
}

template <typename T>
void Dynamic<T>::print_() // I printed my container in this function...
{
    shared_ptr<node<T>> current = this -> head;
    
    while (current != nullptr)
    {
        cout << current -> getData() << " ";
        current = current -> getNext();
    }
    cout << endl << endl;
}
