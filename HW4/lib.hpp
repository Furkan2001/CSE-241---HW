/*   lib.hpp
//
//   Header file
//
//   200104004063_AhmetFurkanEkinci
*/



#ifndef DAYOFYEARSET_H_
#define DAYOFYEARSET_H_

#include <iostream>
#include <fstream>
#include <list>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::list;
using std::vector;


namespace my_namespace
{
    class DayofYearSet
    {
    public:
        
        class DayofYear
        {
            
        public:
            
            DayofYear(int d, int m); // It is two parameter constructor...
            DayofYear(int m);  // It is one parameter constructor...
            DayofYear(const DayofYear &obj);   // It is copy constructor...
            DayofYear() : day(1), month(1) {}     //This is my no parameter constructor..
            int get_day() const {return (this -> day);}   // Getter..
            int get_month() const {return (this -> month);}
            void set_ex_day(int d);   //Setter..
            void set_ex_month(int m);
            void control_day(int d, int m);  // Controller..
            void control_month(int m);
            void operator() (int d, int m);  //Operator overloading about ()
            
        private:
            
            int month;
            int day;
            
        };
        
        DayofYearSet(); // No parameter constructor..
        DayofYearSet(const DayofYearSet &obj); // Copy constructor...
        DayofYearSet(const list<DayofYear> list_DayofYear);  // List constructor...
        DayofYearSet(const vector<DayofYear> vector_DayofYear);  // Vector constructor...
        void operator+(const DayofYear &obj);  // Plus opeerator..
        DayofYearSet operator+(const DayofYearSet &obj);  // Plus operator with return..
        DayofYearSet operator-(const DayofYearSet &obj);  // Operator overloading about - with return...
        void operator-(int s);   // Operator overloading about - ...
        DayofYearSet operator^(const DayofYearSet &obj);   // Operator overloading with ^
        DayofYearSet operator!();   // Operator overloading with !
        DayofYear& operator[](int size);   // Operator overloading with []
        int size(){return (_size);}   // This returns _size variable...
        bool operator ==(const DayofYearSet &obj);  // Operator overloading with ==
        bool operator !=(const DayofYearSet &obj);   // Operator overloading with !=
        friend std::ostream& operator<<(std::ostream &out, DayofYearSet &obj);  // Operator overloading with <<
        void operator=(const DayofYearSet &obj);   // Operator overloading with =
        void remove(int s);  // This function remove one elements from ptr_day_of_year...
        ~DayofYearSet(){delete [] ptr_day_of_year; ptr_day_of_year = nullptr;} //This is my destructor...
        
    private:
        
        DayofYear *ptr_day_of_year;   // This pointer holds DayofYear objects...
        int _size = 0;  // I created this int variable to hold size of ptr_day_of_year...
        
};

}

#endif
