/*   main.cpp
//
//   Main file
//
//   200104004063_AhmetFurkanEkinci
*/


#include "lib.hpp"

using namespace my_namespace;


void main_function_1();
void main_function_2();


int main()
{
    main_function_1();

    return (0);
}


void main_function_1()
{
    cout << "If large numbers are entered, I get the mode to reduce it to the required range. if zero or smaller numbers are entered, I round to 1... Also I will print whole elements of set being ('day' 'month')" << endl << endl;
    
    DayofYearSet::DayofYear a;
    
    cout << "I created 1 DayofYear object using no parameter constructor..." << endl << endl;
    
    cout << "a object -> day " << a.get_day() << " month " << a.get_month() << endl << endl;
    
    DayofYearSet::DayofYear b(1);
    
    cout << "I created 1 DayofYear object using one parameter constructor..." << endl << endl;
    
    
    cout << "b object -> day " << b.get_day() << " month " << b.get_month() << endl << endl;
    
    
    DayofYearSet::DayofYear c(2, 2);
    DayofYearSet::DayofYear d(3, 3);
    DayofYearSet::DayofYear e(4, 4);
    
    cout << "I created 3 DayofYear objects... I used two parameter constructor in here..." << endl << endl;
    
    cout << "c object -> day " << c.get_day() << " month " << c.get_month() << endl;
    cout << "d object -> day " << d.get_day() << " month " << d.get_month() << endl;
    cout << "e object -> day " << e.get_day() << " month " << e.get_month() << endl << endl;
    
    DayofYearSet::DayofYear f(36, 17);
    DayofYearSet::DayofYear g(37, 18);
    
    cout << "I created entering wrongly number for 2 DayofYear objects in here and my algorithm made it true..." << endl << endl;
    
    cout << "f object -> day " << f.get_day() << " month " << f.get_month() << endl;
    cout << "g object -> day " << g.get_day() << " month " << g.get_month() << endl << endl;
    
    list <DayofYearSet::DayofYear> obj1 = {a, b, c};
    
    DayofYearSet d1(obj1);
    
    cout << "I created a DayofYearSet object(d1) using initilizer_list in here. This object has a, b and c objects of DayofYear...If anyone of a, b, c are same then it will take one of them because it is set..." << endl << endl;
    
    cout << "d1 : " << d1;
    
    DayofYearSet d2;
    
    cout << "I created a DayofYearSet object(d2) using no parameter constructor and I will add DayofYear objects which are names a,b and c with operator+ in it..." << endl << endl;
    
    d2 + a;
    d2 + b;
    d2 + c;
    
    cout << "d2 : " << d2;
    
    cout << "Now I will compare two objects of DayofYearSet using my operator== and if they are same I will print 'You are EAGLE' if not I will print 'You are LION'... " << endl << endl;
    
    if (d1 == d2)
        cout << "You are EAGLE" << endl << endl;
    else
        cout << "You are LION" << endl << endl;
    
    cout << "I will add two new objects of DayofYear(d, e) to d2.." << endl << endl;
    
    d2 + d;
    d2 + e;
    
    cout << "d2 : " << d2;
    
    cout << "I will remove an element which be in size[1] from d2.. I will do it using remove function..." << endl << endl;
    
    d2.remove(1);
    
    cout << "d2 : " << d2;
    
    cout << "I will study remove an element which be size[4] from d2.. But it must give an error message because there is no any object in size[4] in d2..." << endl << endl;
    
    d2.remove(4);
    
    cout << "d2 : " << d2;
    
    cout << "Now I am going to remove an element which be size[1] from d1.. I will do it using operator-" << endl << endl;
    
    d1 - 1;
    
    cout << "d1 : " << d1;
    
    cout << "I will study remove an element which be size[5] from d1 with using overload-.. But it must give an error message because there is no any object in size[5] in d1..." << endl << endl;
    
    d1 - 5;
    
    cout << "d1 : " << d1;
    
    DayofYearSet d3;
    
    cout << "I created an object of DayofYearSet with no parameter constructor... Its name is d3..." << endl << endl;
    
    cout << "I will take the difference d2 and d1 using operator- ... Then I will equal to d3 using operator=" << endl << endl;
    
    d3 = (d2 - d1);
    
    cout << "d3 : " << d3;
    
    cout << "I will print sizes of d1, d2 and d3..." << endl << endl;
    
    cout << "size of d1 : " << d1.size() << endl;
    cout << "size of d2 : " << d2.size() << endl;
    cout << "size of d3 : " << d3.size() << endl << endl;
    
    cout << "I will print d1, d2 and d3 now..." << endl << endl;
    
    cout << "d1 : " << d1;
    cout << "d2 : " << d2;
    cout << "d3 : " << d3;
    
    cout << "I will compare d2 and d3 using operator!= ...If they are same I will print 'You are EAGLE' if not I will print 'You are LION'... " << endl << endl;
    
    if (d1 != d2)
        cout << "You are LION" << endl << endl;
    else
        cout << "You are EAGLE" << endl << endl;
    
    cout << "I will print elements of d3 using operator[]..." << endl << endl;
    
    cout << d3[0].get_day() << " " << d3[0].get_month() << "\t" << d3[1].get_day() << " " << d3[1].get_month() << endl << endl;
    
    DayofYearSet d4;
    
    cout << "I created an object of DayofYearSet(d4)..." << endl << endl;
    
    cout << "I will print d1, d2, d3 and d4" << endl << endl;
    
    cout << "d1 : " << d1;
    cout << "d2 : " << d2;
    cout << "d3 : " << d3;
    cout << "d4 : " << d4;
    
    cout << "I will find intersection d2 and d3 using operator^ ..Then I will equal that to d4 using operator= ..." << endl << endl;
    
    d4 = d2 ^ d3;
    
    cout << "d4 : " << d4;
    
    DayofYearSet d5;
    
    cout << "I created an object of DayofYearSet(d5)" << endl << endl;

    cout << "I will equal d5 to complement d4 with operator! and then I will print d5 set..." << endl << endl;
    
    d5 = (!d4);
    
    cout << "d5 : " << d5;
    
    cout << "I will print whole DayofYearSet objects which I created..." << endl << endl;
    
    cout << "d1 : " << d1;
    cout << "d2 : " << d2;
    cout << "d3 : " << d3;
    cout << "d4 : " << d4;
    cout << "d5 : " << d5;
    
    cout << "I will take complement d5 again with operator! because it is taking whole spaces, it is too big set now..." << endl << endl;
    
    d5 = (!d5);
    
    cout << "d5 : " << d5;
    
    cout << "I will add two elements to d5..." << endl << endl;
    
    d5 + f;
    d5 + g;
    
    cout << "d5 : " << d5;
    
    cout << "If I try to add same set again, my operator+ does not add it again... Lets try.." << endl << endl;
    
    d5 + f;
    
    cout << "d5 : " << d5;
    
    cout << "I will print whole DayofYearSet objects which I created..." << endl << endl;
    
    cout << "d1 : " << d1;
    cout << "d2 : " << d2;
    cout << "d3 : " << d3;
    cout << "d4 : " << d4;
    cout << "d5 : " << d5;
    
    cout << endl << endl << endl << endl << "I made whole function you want...Thats it..." << endl << endl << endl << endl;
}

