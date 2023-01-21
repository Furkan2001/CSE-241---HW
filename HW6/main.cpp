#include "dynamic.hpp"
#include "iterator.hpp"
#include "node.hpp"
#include "dynamic.cpp"
#include "const_iterator.hpp"

void myfunction (int i) 
{  // function:
   std::cout << i << " ";
}

void myfunction2 (int i) 
{  // function2:
  std::cout << i * 2 << " ";
}

void myfunction3 (char i) 
{  // function:
   std::cout << i << " ";
}

void myfunction4 (float i) 
{  // function:
   std::cout << i << " ";
}

void myfunction5 (float i) 
{  // function2:
  std::cout << i * 2 << " ";
}

int main()
{
	cout << endl << "Welcome To World of Iterator..." << endl << endl;
	
	cout << endl << endl << "INTEGER PART" << endl << endl;
	
    cout << "I will created in here a object of Dynamic<int> class..." << endl;
    Dynamic<int> d1;
    cout << "I will created in here a object(iterator) of iterator_<int> class..." << endl;
    iterator_<int> it;
    
    cout << "I will insert(using insertback()) 11 from start and I will print(using print_()) to screen my d1 object..." << endl;
    d1.insertback(11);
    d1.print_();
    cout << endl << "I will insert(using insertback()) 872 from start and I will print(using print_()) to screen my d1 object..." << endl;
    d1.insertback(872);
    d1.print_();
    
    cout << endl << "I will insert (using insert()) 21 24 21 543 75 2 57 571 1903 57 and then I will print(using print_() to screen my d1 object...)" << endl;
    d1.insert(21);
    d1.insert(24);
    d1.insert(21);
    d1.insert(543);
    d1.insert(75);
    d1.insert(2);
    d1.insert(57);
    d1.insert(571);
    d1.insert(1903);
    d1.insert(57);
    d1.print_();
    
    cout << endl << "I will insert(using insertback()) from back 1 and then I will print(using print_() to screen my d1 object..." << endl;
    d1.insertback(1);
    d1.print_();
    
    cout << endl << "I will sort first 3 element(using std::sort(d1.begin(), d1.begin() + 3) and then I will print(using print_() to screen my d1 object..." << endl;
    cout << endl << "SORTING" << endl;
    sort(d1.begin(), d1.begin() + 3);
    d1.print_();
    
    cout << endl << "I will sort first 5 element(using std::sort(d1.begin(), d1.begin() + 5) and then I will print(using print_() to screen my d1 object..." << endl;
    cout << endl << "SORTING" << endl;
    sort(d1.begin(), d1.begin() + 5);
    d1.print_();
    
    cout << endl << "I will sort last 3 element(using std::sort(d1.begin() + 8, d1.end()) and then I will print(using print_() to screen my d1 object..." << endl;
    cout << endl << "SORTING" << endl;
    sort(d1.begin() + 8, d1.end() + 1);
    d1.print_();
    
    cout << endl << "I will sort all of them(using std::sort(d1.begin(), d1.end()) and then I will print(using print_() to screen my d1 object..." << endl;
    cout << endl << "SORTING" << endl;
    sort(d1.begin(), d1.end() + 1);
    d1.print_();
    
    
    cout << endl << "I will find(using std::find(d1.begin(), d1.end())) 75 in my d1 object if there is I will print \"it is found\" if there is not then I will print \"it is not found\" " << endl;
    cout << "FIND FUNCTİON İS CALLED" << endl;
    it = find(d1.begin(), d1.end(), 75);
    if (it != d1.end())
        cout << "it is found" << endl;
    else
        cout << "it is not found" << endl;
    
    
    cout << endl << "I will find(using std::find(d1.begin(), d1.end())) 1453 in my d1 object if there is I will print \"it is found\" if there is not then I will print \"it is not found\" " << endl;
    cout << "FIND FUNCTİON İS CALLED" << endl;
    it = find(d1.begin(), d1.end(), 1453);
    if (it != d1.end())
        cout << "it is found" << endl;
    else
        cout << "it is not found" << endl;
        
    cout << endl << "I will use for_each funtion to print my d1 object...(using  for_each(d1.begin(), d1.end()+1, myfunction))" << endl;
    cout << endl << "FOR_EACH" << endl;
    for_each(d1.begin(), d1.end()+1, myfunction);
    
   	cout << endl << endl << "I will use for_each funtion to print my 2 * d1 object..."  << endl;
    cout << endl << "FOR_EACH" << endl;
    for_each(d1.begin(), d1.end()+1, myfunction2);
    cout << endl;
    
    cout << endl << "I will print my real d1 object...(using print_())" << endl;
    d1.print_();

    cout << endl << endl << "I will erase(using erase(value)) 872 from my d1 object and I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    try
    {
        d1.erase(872);
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d1.print_();
    
     cout << endl << endl << "I will erase(using erase(value)) 872 again from my d1 object and I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    try
    {
        d1.erase(872);
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d1.print_();
    
     cout << endl << endl << "I will erase(using erase(value)) 25 from my d1 object and I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    try
    {
        d1.erase(25);
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d1.print_();
    
    cout << endl << endl << "(using size())  size: " << d1.size() << endl;
    
    cout << endl << endl << "I will erase(using erase(value)) 57 from my d1 object if there is more than one it will erase all of them lets see... I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    cout << "Erasing..." << endl;
    try
    {
        d1.erase(57);
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d1.print_();
    
    cout << endl << endl << "(using size())  size: " << d1.size() << endl;
    
    
    cout << endl << "I will erase(using erase(iterator)) 1.index(using begin() + 1)" << endl;
    d1.erase(d1.begin() + 1);
    d1.print_();
    cout << endl << endl << "(using size())  size: " << d1.size() << endl;
    
    
    cout << endl << "I will erase(using erase(iterator)) 7.index(using end() - 1)" << endl;
    d1.erase(d1.end()- 1);
    d1.print_();
    cout << endl << endl << "(using size())  size: " << d1.size() << endl;
    
    cout << endl << "I will give last index to my iterator(it) and I will print last element to screen" << endl;
    it = d1.end();
    cout << *it << endl;
    
    cout << endl << "I will erase(using erase(iterator1, iterator2)) 0-3 indexes(using begin(), begin() + 4)" << endl;
    d1.erase(d1.begin(), d1.begin() + 3);
    d1.print_();
    
    cout << endl << endl << "(using size())  size: " << d1.size() << endl;
    
    cout << endl << "I will clear(using clear()) my d1 object and then prin it and size..." << endl;
    d1.clear();
    cout << "d1: "; d1.print_();
    cout << endl << endl << "(using size())  size: " << d1.size() << endl;
    
    
    
    
    
    
    cout << endl << endl << "************************************************************************************************************" << endl;
    
    cout << endl << endl << "CHAR PART" << endl << endl;
    
    cout << "I will created in here a object of Dynamic<char> class..." << endl;
    Dynamic<char> d2;
    cout << "I will created in here a object(iterator) of iterator_<char> class..." << endl;
    iterator_<char> it2;
    
    cout << "I will insert(using insertback()) G from start and I will print(using print_()) to screen my d2 object..." << endl;
    d2.insertback('G');
    d2.print_();
    cout << endl << "I will insert(using insertback()) H from start and I will print(using print_()) to screen my d2 object..." << endl;
    d2.insertback('H');
    d2.print_();
    
    cout << endl << "I will insert (using insert()) Z t k l K t f F y x and then I will print(using print_() to screen my d2 object...)" << endl;
    d2.insert('Z');
    d2.insert('t');
    d2.insert('k');
    d2.insert('l');
    d2.insert('K');
    d2.insert('t');
    d2.insert('f');
    d2.insert('F');
    d2.insert('y');
    d2.insert('x');
    d2.print_();
    
    cout << endl << "I will insert(using insertback()) from back B and then I will print(using print_() to screen my d2 object..." << endl;
    d2.insertback('B');
    d2.print_();
    
    cout << endl << "I will sort first 3 element(using std::sort(d2.begin(), d2.begin() + 3) and then I will print(using print_() to screen my d2 object..." << endl;
    cout << endl << "SORTING" << endl;
    sort(d2.begin(), d2.begin() + 3);
    d2.print_();
    
    cout << endl << "I will sort all of them(using std::sort(d2.begin(), d2.end()) and then I will print(using print_() to screen my d2 object..." << endl;
    cout << endl << "SORTING" << endl;
    sort(d2.begin(), d2.end() + 1);
    d2.print_();
    
    cout << endl << "I will find(using std::find(d2.begin(), d2.end())) x in my d1 object if there is I will print \"it is found\" if there is not then I will print \"it is not found\" " << endl;
    cout << "FIND FUNCTİON İS CALLED" << endl;
    it2 = find(d2.begin(), d2.end(), 'x');
    if (it2 != d2.end())
        cout << "it is found" << endl;
    else
        cout << "it is not found" << endl;
        
    cout << endl << "I will find(using std::find(d2.begin(), d2.end())) A in my d2 object if there is I will print \"it is found\" if there is not then I will print \"it is not found\" " << endl;
    cout << "FIND FUNCTİON İS CALLED" << endl;
    it2 = find(d2.begin(), d2.end(), 'A');
    if (it2 != d2.end())
        cout << "it is found" << endl;
    else
        cout << "it is not found" << endl;
        
    cout << endl << "I will use for_each funtion to print my d2 object(as ASCII)...(using  for_each(d2.begin(), d2.end(), myfunction))" << endl;
    cout << "FOR_EACH" << endl;
    for_each(d2.begin(), d2.end()+1, myfunction);    
    cout << endl << endl << "(using size())  size: " << d2.size() << endl;
        
	cout << endl << endl << "I will use for_each funtion to print(as ASCII) my 2 * d2 object..."  << endl;
    cout << "FOR_EACH" << endl;
    for_each(d2.begin(), d2.end()+1, myfunction2);
    cout << endl << endl << "(using size())  size: " << d2.size() << endl;
    
    cout << endl << "I will print my real d2 object...(using print_())" << endl;
    d2.print_();

    cout << endl << endl << "I will erase(using erase(value)) k from my d2 object and I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    try
    {
        d2.erase('k');
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d2.print_();
     cout << endl << endl << "(using size())  size: " << d2.size() << endl;
    
    cout << endl << endl << "I will erase(using erase(value)) k again from my d2 object and I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    try
    {
        d2.erase('k');
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d1.print_();
     cout << endl << endl << "(using size())  size: " << d2.size() << endl;
    
    cout << endl << endl << "I will erase(using erase(value)) t from my d2 object and if there is more than one it will erase all of them lets see...I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    try
    {
        d2.erase('t');
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d2.print_();
     cout << endl << endl << "(using size())  size: " << d2.size() << endl;
     
     cout << endl << "I will erase(using erase(iterator)) 1.index(using begin() + 1)" << endl;
    d2.erase(d2.begin() + 1);
    d2.print_();
    cout << endl << endl << "(using size())  size: " << d2.size() << endl;
    
    cout << endl << "I will erase(using erase(iterator)) 7.index(using end() - 1)" << endl;
    d2.erase(d2.end()- 1);
    d2.print_();
    cout << endl << endl << "(using size())  size: " << d2.size() << endl;
    
    cout << endl << "I will give last index to my iterator(it2) and I will print last element to screen" << endl;
    it2 = d2.end();
    cout << *it2 << endl;
    
    cout << endl << "I will erase(using erase(iterator1, iterator2)) 0-3 indexes(using begin(), begin() + 4)" << endl;
    d2.erase(d2.begin(), d2.begin() + 3);
    d2.print_();
    cout << endl << endl << "(using size())  size: " << d2.size() << endl;
    
    cout << endl << "I will clear(using clear()) my d2 object and then prin it and size..." << endl;
    d2.clear();
    cout << "d2: "; d2.print_();
    cout << endl << endl << "(using size())  size: " << d2.size() << endl;
    
    
    
    
    
    
    cout << endl << endl << "************************************************************************************************************" << endl;
    
    cout << endl << endl << "CHAR PART" << endl << endl;
    cout << "I will created in here a object of Dynamic<float> class..." << endl;
    Dynamic<float> d3;
    cout << "I will created in here a object(iterator) of iterator_<float> class..." << endl;
    iterator_<float> it3;
    
    cout << endl << "I will insert(using insertback()) 11.3 from start and I will print(using print_()) to screen my d3 object..." << endl;
    d3.insertback(11.3);
    d3.print_();
    cout << endl << "I will insert(using insertback()) 872.75 from start and I will print(using print_()) to screen my d3 object..." << endl;
    d3.insertback(872.75);
    d3.print_();
    
    cout << endl << "I will insert (using insert()) 21.4 24.2 21.4 543.42 435.1 45.42 75.81 12.4 2.1 57.987 and then I will print(using print_() to screen my d3 object...)" << endl;
    d3.insert(21.4);
    d3.insert(24.2);
    d3.insert(21.4);
    d3.insert(543.42);
    d3.insert(435.1);
    d3.insert(45.52);
    d3.insert(75.81);
    d3.insert(12.4);
    d3.insert(2.1);
    d3.insert(57.987);
    d3.print_();
    
    cout << endl << "I will insert(using insertback()) from back 1.8 and then I will print(using print_() to screen my d3 object..." << endl;
    d3.insertback(1.8);
    d3.print_();
    
    cout << endl << "I will sort first 3 element(using std::sort(d3.begin(), d3.begin() + 3) and then I will print(using print_() to screen my d3 object..." << endl;
    cout << "SORTING" << endl;
    sort(d3.begin(), d3.begin() + 3);
    d3.print_();
    
	cout << endl << "I will sort first 5 element(using std::sort(d3.begin(), d3.begin() + 5) and then I will print(using print_() to screen my d3 object..." << endl;
    cout << endl << "SORTING" << endl;
    sort(d3.begin(), d3.begin() + 5);
    d3.print_();
    
    cout << endl << "I will sort all of them(using std::sort(d3.begin(), d3.end()) and then I will print(using print_() to screen my d3 object..." << endl;
    cout << endl << "SORTING" << endl;
    sort(d3.begin(), d3.end() + 1);
    d3.print_();
    
    cout << endl << "I will find(using std::find(d3.begin(), d3.end())) 435.1 in my d1 object if there is I will print \"it is found\" if there is not then I will print \"it is not found\" " << endl;
    cout << "FIND FUNCTİON İS CALLED" << endl;
    it3 = find(d3.begin(), d3.end(), 435.1);
    if (it3 != d3.end())
        cout << "it is found" << endl;
    else
        cout << "it is not found" << endl;
        
        cout << endl << "I will find(using std::find(d3.begin(), d3.end())) 1453 in my d1 object if there is I will print \"it is found\" if there is not then I will print \"it is not found\" " << endl;
    cout << "FIND FUNCTİON İS CALLED" << endl;
    it3 = find(d3.begin(), d3.end(), 1453);
    if (it3 != d3.end())
        cout << "it is found" << endl;
    else
        cout << "it is not found" << endl;
    
    cout << endl << "I will use for_each funtion to print my d3 object...(using  for_each(d3.begin(), d3.end()+1, myfunction))" << endl;
    cout << "FOR_EACH" << endl;
    for_each(d3.begin(), d3.end()+1, myfunction4);
    cout << endl;
    
    cout << endl << endl << "I will use for_each funtion to print my 2 * d3 object..."  << endl;
    cout << endl << "FOR_EACH" << endl;
    for_each(d3.begin(), d3.end() + 1, myfunction5);
    cout << endl;
    
    cout << endl << "I will print my real d3 object...(using print_())" << endl;
    d3.print_();
    
    cout << endl << endl << "I will erase(using erase(value)) 872.75 from my d3 object and I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    try
    {
        d3.erase(872.75);
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d3.print_();
    
     cout << endl << endl << "I will erase(using erase(value)) 872.75 again from my d3 object and I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    try
    {
        d3.erase(872.75);
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d3.print_();
    
     cout << endl << endl << "I will erase(using erase(value)) 21.4 from my d3 object if there is more than one it will erase all of them lets see... I will put it in try catch blocks.. If any error occure this function throws exception..." << endl;
    cout << "Erasing..." << endl;
    try
    {
        d3.erase(21.4);
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    d3.print_();
    
    cout << endl << endl << "(using size())  size: " << d3.size() << endl;
    
    
    cout << endl << "I will erase(using erase(iterator)) 1.index(using begin() + 1)" << endl;
    d3.erase(d3.begin() + 1);
    d3.print_();
    cout << endl << endl << "(using size())  size: " << d3.size() << endl;
    
    
    cout << endl << "I will erase(using erase(iterator)) 7.index(using end() - 1)" << endl;
    d3.erase(d3.end()- 1);
    d3.print_();
    cout << endl << endl << "(using size())  size: " << d3.size() << endl;
    
    
    cout << endl << "I will give last index to my iterator(it3) and I will print last element to screen" << endl;
    it3 = d3.end();
    cout << *it3 << endl << endl;
    
    
    cout << endl << "I will erase(using erase(iterator1, iterator2)) 0-3 indexes(using begin(), begin() + 4)" << endl;
    d3.erase(d3.begin(), d3.begin() + 3);
    d3.print_();
    
    cout << endl << endl << "(using size())  size: " << d3.size() << endl;
    
    cout << endl << "I will clear(using clear()) my d3 object and then prin it and size..." << endl;
    d3.clear();
    cout << "d3: "; d1.print_();
    cout << endl << endl << "(using size())  size: " << d3.size() << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return (0);
}
