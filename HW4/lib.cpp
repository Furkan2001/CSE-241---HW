/*   lib.cpp
//
//   Implementaition file
//
//   200104004063_AhmetFurkanEkinci
*/
#include "lib.hpp"

namespace my_namespace
{

    DayofYearSet::DayofYear::DayofYear(int d, int m) //This is my two parameter constructor..
    {
        control_day(d, m);
    }

    DayofYearSet::DayofYear::DayofYear(int m)   //This is my one parameter constructor..
    {
        day = 1;
        control_month(m);
    }


    DayofYearSet::DayofYear::DayofYear(const DayofYear &obj)  // This is my copy constructor...
    {
        this -> day = obj.day;
        this -> month = obj.month;
    }


	
    void DayofYearSet::DayofYear::operator() (int d, int m) //This is my operator overloading about ()...
    {
        set_ex_day(d);
        set_ex_month(m);
    }	
	

    void DayofYearSet::DayofYear::control_day(int d, int m)    //This is my controller about day and month number...
    {
        control_month(m);
        if (d < 1)
        {
            d = 1;
            day = d;
            return;
        }
        if (m == 1)
        {
            if (d < 32)
            {
                day = d;
                return;
            }
            d = d % 31;
        }
        else if(m == 2)
        {
            if (d < 30)
            {
                day = d;
                return;
            }
            d = d % 29;
        }
        else if(m == 3)
        {
            if (d < 32)
            {
                day = d;
                return;
            }
            d = d % 31;
        }
        else if(m == 4)
        {
            if (d < 31)
            {
                day = d;
                return;
            }
            d = d % 30;
        }
        else if(m == 5)
        {
            if (d < 32)
            {
                day = d;
                return;
            }
            d = d % 31;
        }
        else if(m == 6)
        {
            if (d < 31)
            {
                day = d;
                return;
            }
            d = d % 30;
        }
        else if(m == 7)
        {
            if (d < 32)
            {
                day = d;
                return;
            }
            d = d % 31;
        }
        else if(m == 8)
        {
            if (d < 32)
            {
                day = d;
                return;
            }
            d = d % 31;
        }
        else if(m == 9)
        {
            if (d < 31)
            {
                day = d;
                return;
            }
            d = d % 30;
        }
        else if(m == 10)
        {
            if (d < 32)
            {
                day = d;
                return;
            }
            d = d % 31;
        }
        else if(m == 11)
        {
            if (d < 31)
            {
                day = d;
                return;
            }
            d = d % 30;
        }
        else
        {
            if (d < 32)
            {
                day = d;
                return;
            }
            d = d % 31;
        }
        
        day = d;
    }


    void DayofYearSet::DayofYear::control_month(int m) //This is my controller about month number...
    {
        if (m < 1)
        {
            m = 1;
            month = m;
            return;
        }
        if (m > 0 && m < 13)
        {
            month = m;
            return;
        }
        
        m = m % 12;
        month = m;
    }


    void DayofYearSet::DayofYear::set_ex_day(int d) // I used it to change day number with parameter when I did not reach private members..
    {
        this -> day = d;
    }

    void DayofYearSet::DayofYear::set_ex_month(int m)  // I used it to change month number with parameter when I did not reach private members..
    {
        this -> month = m;
    }



    DayofYearSet::DayofYearSet()  // No parameter constructor
    {
        _size = 0;
        ptr_day_of_year = new DayofYear[1];
    }


    DayofYearSet::DayofYearSet(const DayofYearSet &obj)   // Copy constructor... I used decltype in here...
    {
        for(decltype(_size) i = 0; i < obj._size; i++)
        {
            this -> ptr_day_of_year[i].set_ex_day(obj.ptr_day_of_year[i].get_day());
            this -> ptr_day_of_year[i].set_ex_month(obj.ptr_day_of_year[i].get_month());
        }
        this -> _size = obj._size;
    }


    DayofYearSet::DayofYearSet(const list<DayofYear> list_DayofYear)  // This is my list initialization constructor...
    {
        _size = 0;
        ptr_day_of_year = new DayofYear[1];
        for (auto x : list_DayofYear)  // I used auto type in here...
        {
            (*this) + x;
        }
    }
    
    
    DayofYearSet::DayofYearSet(const vector<DayofYear> vector_DayofYear)  // This is my vector initialization constructor...
    {
        _size = 0;
        ptr_day_of_year = new DayofYear[1];
        for (auto x : vector_DayofYear)   // I used auto type in here...
        {
            (*this) + x;
        }
    }


    void DayofYearSet::operator+(const DayofYear &obj)
    {
        for (decltype(_size) i = 0; i < _size; i++) // I checked if the object I will add is already in the set... If it is already in set then ı will not add again it.. So I wrote return keyword in if statement...
        {
            if (ptr_day_of_year[i].get_day() == obj.get_day() && ptr_day_of_year[i].get_month() == obj.get_month())
            {
                return;
            }
        }
        
        _size++;  //I increased my _size variable because I will add new object in my ptr_day_of_year...
        DayofYear *temp; // I created new pointer to hold my old objcet in ptr_day_of_year
        temp = new DayofYear[_size]; // I allocate area from memory for variable which name is temp..
        
        for(decltype(_size) i = 0; i < _size - 1; i++) //I added my old objects in ptr_day_of_year to temp.
        {
            temp[i].set_ex_day(ptr_day_of_year[i].get_day());
            temp[i].set_ex_month(ptr_day_of_year[i].get_month());
        }
        // I added last index of temp new object in here...
        temp[_size - 1].set_ex_day(obj.get_day());
        temp[_size - 1].set_ex_month(obj.get_month());
        
        delete [] ptr_day_of_year;
        ptr_day_of_year = new DayofYear[_size]; // I allocate again my ptr_day_of_year.. Because my _size grew up 1 so I increased area of ptr_day_of_year in memory..

        for(decltype(_size) i = 0; i < _size; i++) // I added objects which in temp to my ptr_day_of_year...
        {
            ptr_day_of_year[i].set_ex_day(temp[i].get_day());
            ptr_day_of_year[i].set_ex_month(temp[i].get_month());
        }
        delete [] temp; // I freed temp in here...
    }


    DayofYearSet DayofYearSet::operator+(const DayofYearSet &obj)
    {
        vector <DayofYear> temp;
        int counter;
      
   		counter = 0;
        for (decltype(_size) i = 0; i < this -> _size; i++)
        {
        	temp.push_back(1);
        	temp[counter].set_ex_day(this -> ptr_day_of_year[i].get_day());
        	temp[counter].set_ex_month(this -> ptr_day_of_year[i].get_month());
        	counter++;
        }
        for (decltype(_size) i = 0; i < obj._size; i++)
        {
        	temp.push_back(1);
        	temp[counter].set_ex_day(this -> ptr_day_of_year[i].get_day());
        	temp[counter].set_ex_month(this -> ptr_day_of_year[i].get_month());
        	counter++;
        }
        return (DayofYearSet(temp));   // Returns as anonymous in here...
    }


    void DayofYearSet::operator=(const DayofYearSet &obj)
    {
    	if (this -> _size != obj._size)  //If their _size variables are not equal then I must equal their _size variables...
    		delete [] this -> ptr_day_of_year;  // I deleted ptr_day_of_year pointer in here...
    	ptr_day_of_year = new DayofYear[obj._size];
    
        for (decltype(_size) i = 0; i < obj._size; i++)
        {
            this -> ptr_day_of_year[i].set_ex_day(obj.ptr_day_of_year[i].get_day());
            this -> ptr_day_of_year[i].set_ex_month(obj.ptr_day_of_year[i].get_month());
        }
        this -> _size = obj._size;
    }


    DayofYearSet::DayofYear& DayofYearSet::operator[](int size)  //I just made operator overloading in here...
    {
        int temp;
        
        if (size < _size)  // I controlled parameter whether valid in here
            return (this -> ptr_day_of_year[size]);
        else
            cout << "This size is not valid for this DayofYearSet object..." << endl;
        
        temp = size % _size;
        cout << "I taked mod what you entered number and then it is " << temp << endl;
        return (this -> ptr_day_of_year[temp]);  // I returned DayofYear object...
    }


    bool DayofYearSet::operator ==(const DayofYearSet &obj)  // I controlled objects whether equal in here...
    {
        int control;
        
        if (this -> _size != obj._size)  // If their _size are diffirent then they are not same
            return (0);  // If objects are not same then return 0...
        for (decltype(_size) i = 0; i < this -> _size; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < obj._size; j++)
            {
                if (this -> ptr_day_of_year[i].get_day() == obj.ptr_day_of_year[j].get_day() && this -> ptr_day_of_year[i].get_month() == obj.ptr_day_of_year[j].get_month())
                    control = 1;
            }
            if (control != 1)
                return (0);  // If objects are not same then return 0...
        }
             return (1); // If objects are same then return 1...
    }

    bool DayofYearSet::operator !=(const DayofYearSet &obj)
    {
        int control;
        
        if (this -> _size != obj._size)
            return (1);  // If objects are not same then return 1...
        for (decltype(_size) i = 0; i < this -> _size; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < obj._size; j++)
            {
                if (this -> ptr_day_of_year[i].get_day() == obj.ptr_day_of_year[j].get_day() && this -> ptr_day_of_year[i].get_month() == obj.ptr_day_of_year[j].get_month())
                    control = 1;
            }
            if (control != 1)
                return (1);   // If objects are not same then return 1...
        }
             return (0);   // If objects are same then return 0...
    }


    void DayofYearSet::remove(int s)  // I removed an element index in index which write in parameter from array...
    {
        if (this -> _size > s && s > -1)
        {
            DayofYear *temp;
            temp = new DayofYear[(this -> _size) - 1];
            for (decltype(_size) i = 0; i < this -> _size; i++)
            {
                if (i < s)
                {
                    temp[i].set_ex_day(this -> ptr_day_of_year[i].get_day());
                    temp[i].set_ex_month(this -> ptr_day_of_year[i].get_month());
                }
                if (i > s)
                {
                    temp[i - 1].set_ex_day(this -> ptr_day_of_year[i].get_day());
                    temp[i - 1].set_ex_month(this -> ptr_day_of_year[i].get_month());
                }
            }
            delete [] this -> ptr_day_of_year;  // I deleted my pointer which name is ptr_day_of_year...
            (this -> _size)--;
            this -> ptr_day_of_year = new DayofYear[_size];

            for (decltype(_size) i = 0; i < this -> _size; i++)
            {
                this -> ptr_day_of_year[i].set_ex_day(temp[i].get_day());
                this -> ptr_day_of_year[i].set_ex_month(temp[i].get_month());
            }
            delete [] temp;   // I deleted my pointer which name is temp...
        }
        else
        {
            cout << "This size is out of the set..." << endl << endl;
        }
    }


    DayofYearSet DayofYearSet::operator-(const DayofYearSet &obj)
    {
        vector <DayofYear> temp;  // I used vector in here to hold DayofYear objects...
        int control;
        int counter;
        
        counter = 0;
        for (decltype(_size) i = 0; i < this -> _size; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < obj._size; j++)
            {
                if (this -> ptr_day_of_year[i].get_day() == obj.ptr_day_of_year[j].get_day() && this -> ptr_day_of_year[i].get_month() == obj.ptr_day_of_year[j].get_month())
                    control = 1;
            }
            if (control == 0)
            {
            	temp.push_back(1);
        		temp[counter].set_ex_day(this -> ptr_day_of_year[i].get_day());
        		temp[counter].set_ex_month(this -> ptr_day_of_year[i].get_month());
        		counter++;
            }
        }
        return (DayofYearSet(temp));  // Returns as anonymous in here...
    }


    void DayofYearSet::operator-(int s)
    {
        if (this -> _size > s && s > -1)
        {
            DayofYear *temp;
            temp = new DayofYear[(this -> _size) - 1];
            for (decltype(_size) i = 0; i < this -> _size; i++)
            {
                if (i < s)
                {
                    temp[i].set_ex_day(this -> ptr_day_of_year[i].get_day());
                    temp[i].set_ex_month(this -> ptr_day_of_year[i].get_month());
                }
                if (i > s)
                {
                    temp[i - 1].set_ex_day(this -> ptr_day_of_year[i].get_day());
                    temp[i - 1].set_ex_month(this -> ptr_day_of_year[i].get_month());
                }
            }
            delete [] this -> ptr_day_of_year;
            (this -> _size)--;
            this -> ptr_day_of_year = new DayofYear[_size];

            for (decltype(_size) i = 0; i < this -> _size; i++)
            {
                this -> ptr_day_of_year[i].set_ex_day(temp[i].get_day());
                this -> ptr_day_of_year[i].set_ex_month(temp[i].get_month());
            }
            delete [] temp;
        }
        else
        {
            cout << "This size is out of the set..." << endl;
        }
    }


    DayofYearSet DayofYearSet::operator^(const DayofYearSet &obj)
    {
        vector <DayofYear> temp;
        int counter;
        
        counter = 0;
        for (decltype(_size) i = 0; i < this -> _size; i++)
        {
            for (decltype(_size) j = 0; j < obj._size; j++)
            {
                if (this -> ptr_day_of_year[i].get_day() == obj.ptr_day_of_year[j].get_day() && this -> ptr_day_of_year[i].get_month() == obj.ptr_day_of_year[j].get_month())
                {
                	temp.push_back(1);
        			temp[counter].set_ex_day(obj.ptr_day_of_year[j].get_day());
        			temp[counter].set_ex_month(obj.ptr_day_of_year[j].get_month());
        			counter++;
            	
                }
            }
        }
          return (DayofYearSet(temp));   // Returns as anonymous in here...
    }


    DayofYearSet DayofYearSet::operator!()
    {
        vector <DayofYear> temp;
        int control;
        int counter;
        
       counter = 0;
        for(decltype(_size) i = 1; i < 32; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 1)
                    control = 1;
            }
            if (control == 0)
            {
          	 	temp.push_back(1);
          	 	temp[counter](i, 1);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 30; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 2)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 2);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 32; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 3)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 3);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 31; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 4)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 4);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 32; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 5)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 5);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 31; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 6)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 6);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 32; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 7)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 7);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 32; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 8)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 8);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 31; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 9)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 9);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 32; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 10)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 10);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 31; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 11)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 11);
            	counter ++;
            }
        }
        for(decltype(_size) i = 1; i < 32; i++)
        {
            control = 0;
            for (decltype(_size) j = 0; j < this -> _size; j++)
            {
                if (this -> ptr_day_of_year[j].get_day() == i && this -> ptr_day_of_year[j].get_month() == 12)
                    control = 1;
            }
            if (control == 0)
            {
                temp.push_back(1);
          	 	temp[counter](i, 12);
            	counter ++;
            }
        }
        return (DayofYearSet(temp));    // Returns as anonymous in here...
    }


    std::ostream& operator<<(std::ostream &out, my_namespace::DayofYearSet &obj)  // Operator ovarloading with <<
    {
        out << endl << "----------------------------------------" << endl;
        
        for (int i = 0; i < obj.size(); i++)
            out << obj[i].get_day() << " " << obj[i].get_month() << endl;
        
        out << "----------------------------------------" << endl << endl;
        
        return (out);
    }

}

