#include "tetromino.h"

Tetromino :: Tetromino(NumberOfShape choice)
{
    VariableOfShape = (int) choice; // I assigned my enum variable to an integer variable. My purpose is that can use it in next lines...
    if (choice == NumberOfShape::I)  // I filled my vectors.
    {
        shape.push_back ({'I', 'I', 'I', 'I'});
    }
    else if (choice == NumberOfShape::O)
    {
        shape.push_back ({'O', 'O'});
        shape.push_back ({'O', 'O'});
    }
    else if (choice == NumberOfShape::T)
    {
        shape.push_back ({'T', 'T', 'T'});
        shape.push_back ({' ', 'T', ' '});
    }
    else if (choice == NumberOfShape::J)
    {
        shape.push_back ({' ', 'J'});
        shape.push_back ({' ', 'J'});
        shape.push_back ({'J', 'J'});
    }
    else if (choice == NumberOfShape::L)
    {
        shape.push_back ({'L', ' '});
        shape.push_back ({'L', ' '});
        shape.push_back ({'L', 'L'});
    }
    else if (choice == NumberOfShape::S)
    {
        shape.push_back ({' ', 'S', 'S'});
        shape.push_back ({'S', 'S', ' '});
    }
    else if (choice == NumberOfShape::Z)
    {
        shape.push_back ({'Z', 'Z', ' '});
        shape.push_back ({' ', 'Z', 'Z'});
    }
    copy_shape = shape;   // I equated the vector named shape that I created to the vector named copy_shape..
    number_of_column = (int)shape[0].size(); // I I created it to be able to use its size in some areas that I need in the next lines.
    number_of_row = (int)shape.size();   // I I created it to be able to use its size in some areas that I need in the next lines...
}


void Tetromino :: print() const  // I created this function to print my vectors..
{
    for (int i = 0; i < shape.size(); i++)  // shape.size() = number of rows
    {
        for (int j = 0; j < shape[i].size(); j++)  // shape[i].size() = number of colummns
        {
            cout << shape[i][j];  //  I printed in here...
        }
        cout << endl;
    }
    cout << endl;
}


void Tetromino :: print_extra() const  // I created this function to print my copy_vector that in last part...
{
    for (int i = 0; i < copy_shape.size(); i++)   // copy_shape.size() = number of rows
    {
        for (int j = 0; j < copy_shape[i].size(); j++)    // copy_shape[i].size() = number of colummns
        {
            cout << copy_shape[i][j];    //  I printed in here...
        }
        cout << endl;
    }
    cout << endl;
}


Tetromino :: Tetromino()  // I created this constructor in my main file first to be able to create the objects of this class without using the constructor parameters.
{}


void Tetromino :: rotate(char direction_of_rotation)
{
    vector <vector <char>> temp(number_of_column);  // I created temporary vector in here..
    
    for (int i = 0; i < number_of_column; i++)   // By relocating the dimensions of my original vector, I defined the temporal vector as large enough to hold the return values. Shape's row -> temp's column, Shape's column -> temp's row
    {
        for(int j = 0; j < number_of_row; j++)
        {
            temp[i].push_back(' ');
        }
    }
    if (VariableOfShape != 1) // I never rotated 'O' because it will take the same shape when it is rotated.
    {
        if (direction_of_rotation == 'r')  // 'r' means turn to the right side..
        {
            if (VariableOfShape == 0)  // I sent the values ​​in the shape vector to the temp vector according to the coordinates that will occur when it returns...
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'I')
                            temp[j][number_of_row - 1 - i] = 'I';
            }
            else if (VariableOfShape == 2)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'T')
                            temp[j][number_of_row - 1 - i] = 'T';
            }
            else if (VariableOfShape == 3)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'J')
                            temp[j][number_of_row - 1 - i] = 'J';
            }
            else if (VariableOfShape == 4)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'L')
                            temp[j][number_of_row - 1 - i] = 'L';
            }
            else if (VariableOfShape == 5)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'S')
                            temp[j][number_of_row - 1 - i] = 'S';
            }
            else if (VariableOfShape == 6)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'Z')
                            temp[j][number_of_row - 1 - i] = 'Z';
            }
            shape = temp;    // I equated the vector named temp that I created to the vector named shape..
        }
        else      //  means turn to the left side..
        {
            if (VariableOfShape == 0)  // I sent the values ​​in the shape vector to the temp vector according to the coordinates that will occur when it returns...
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'I')
                            temp[number_of_column - 1 - j][i] = 'I';
            }
            else if (VariableOfShape == 2)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'T')
                            temp[number_of_column - 1 - j][i] = 'T';
            }
            else if (VariableOfShape == 3)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'J')
                            temp[number_of_column - 1 - j][i] = 'J';
            }
            else if (VariableOfShape == 4)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'L')
                            temp[number_of_column - 1 - j][i] = 'L';
            }
            else if (VariableOfShape == 5)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'S')
                            temp[number_of_column - 1 - j][i] = 'S';
            }
            else if (VariableOfShape == 6)
            {
                for (int i = 0; i < shape.size(); i++)
                    for (int j = 0; j < shape[i].size(); j++)
                        if (shape[i][j] == 'Z')
                            temp[number_of_column - 1 - j][i] = 'Z';
            }
            shape = temp;     // I equated the vector named temp that I created to the vector named shape..
        }
    }
    copy_shape = shape;      // I equated the vector named shape that I created to the vector named copy_shape..
    number_of_row = (int)shape.size();   // Since the column and row numbers will change, I saved it again after returning it.
    number_of_column = (int)shape[0].size();    // Since the column and row numbers will change, I saved it again after returning it.
}


void Tetromino :: JustForFirstObj()   // I created this function so that there is no space left-under the first tetromino object..  According to the shapes we have, the lower left region of all shapes becomes full in a maximum of 2 turns.
{
    if (DownerAndLefter() != 1)
        rotate('r');
    if (DownerAndLefter() != 1)
        rotate('r');
}

bool Tetromino :: canFit(Tetromino previous)
{
    int number_of_char_in_bottom;   // I created this variable to hold number that in bottom of vector...
    int number_of_turn;  //  I created it to keep the total number of turns

    number_of_turn = 0;
    while (number_of_turn < 4)  // 4 turns -> 360 degree..
    {
        number_of_char_in_bottom = previous.ElementsOfLastRow();
        if (DownerAndLefter() == 1)  // bottom left index fullness control
        {
            if (number_of_char_in_bottom == (int)previous.copy_shape[0].size())
                return (1);
            else
            {
                if (number_of_char_in_bottom + 1 == previous.copy_shape[0].size())  //I tried to test if the remaining spaces in the bottom line can be filled
                {
                    if (copy_shape[0][0] == 'I' || copy_shape[copy_shape.size() - 2][0] == ' ')
                        return (1);
                    else
                        rotate('r');
                }
                else if (number_of_char_in_bottom + 2 == previous.copy_shape[0].size())  //I tried to test if the remaining spaces in the bottom line can be filled
                {
                    if (copy_shape[0][0] == 'I' || copy_shape[number_of_row-2][0] == ' ' && copy_shape[number_of_row-2][1] == ' ')
                        return (1);
                    else
                        rotate('r');
                }
            }
        }
        else
            rotate('r');
        number_of_turn++;
    }
    return (0);
}


bool Tetromino :: DownerAndLefter() const // Control for fullness in left-down
{
    if (copy_shape[number_of_row - 1][0] != ' ')
        return (1);
    return (0);
}


int Tetromino :: ElementsOfLastRow() const // I wrote this function to find the total spaces left at the far right of the bottom row...
{
    int counter;
    int control;
    
    control = 0;
    counter = 0;
    for (int i = 0; i < copy_shape[0].size(); i++)
    {
        if (copy_shape[copy_shape.size() - 1][i] != ' ')
        {
            counter++;
            if (control != 0)
            {
                counter += control;
                control = 0;
            }
        }
        else
            control++;
    }
    return (counter);
}


void Tetromino :: CreateNewTetromino(Tetromino previous)
{
    int flag;  //it keeps the row row while setting the size by keeping the larger value..
    int number_of_char_in_bottom;  // it keeps number of char in bottom..
    int control; // I will do a control using this variable in bottom lines of this funtion..
    
    control = 0;
    if (copy_shape.size() < previous.copy_shape.size()) //I gave value to flag to hold row size..
        flag = (int)previous.copy_shape.size();
    else
        flag = (int)copy_shape.size();
    vector<vector<char>> temp(flag);
    
    for (int i = 0; i < (flag); i++)
        for (int j = 0; j < (int)(copy_shape[0].size() + previous.copy_shape[0].size()); j++) // I used their total length to join two separate vectors
            temp[i].push_back(' ');
    
    for (int i = 0; i < (int)previous.copy_shape.size(); i++)  // I threw the previous vector into the temporary vector in here...
        for (int j = 0; j < (int)previous.copy_shape[i].size(); j++)
            if (previous.copy_shape[i][j] != ' ')
                temp[(temp.size() - previous.copy_shape.size()) + i][j] = previous.copy_shape[i][j];
    
    number_of_char_in_bottom = previous.ElementsOfLastRow();
    if (canFit(previous) == 1) //If the return value from the canFit function is 1, here I fill the temporary vector with the copy_shape vector of this object.
    {
        for (int i = 0; i < (int)copy_shape.size(); i++)
            for (int j = 0; j < (int)copy_shape[i].size(); j++)
            {
                if (number_of_char_in_bottom == previous.copy_shape[0].size() && copy_shape[i][j] != ' ')
                    temp[(temp.size() - copy_shape.size()) + i][j + previous.copy_shape[0].size()] = copy_shape[i][j];
                else if (number_of_char_in_bottom + 1 == previous.copy_shape[0].size() && ((copy_shape[number_of_row-2][0] == ' ' && copy_shape[i][j] != ' ') || copy_shape[0][0] == 'I'))
                    temp[(temp.size() - copy_shape.size()) + i][j + (temp[0].size() - copy_shape[0].size()) - 1] = copy_shape[i][j];
                else if (number_of_char_in_bottom + 2 == previous.copy_shape[0].size() && ((copy_shape[number_of_row-2][0] == ' ' && copy_shape[i][j] != ' ') || copy_shape[0][0] == 'I'))
                    temp[(temp.size() - copy_shape.size()) + i][j + (temp[0].size() - copy_shape[0].size()) - 2] = copy_shape[i][j];
                else if (copy_shape[i][j] != ' ')
                    temp[(temp.size() - copy_shape.size()) + i][j + copy_shape[0].size()] = copy_shape[i][j];
            }
    }
    else // If the return vavlue from the canFit function is 0, I continued to fill in the temporary vector from where the previous vector left off...
    {
        for (int i = 0; i < (int)copy_shape.size(); i++)
            for (int j = 0; j < (int)copy_shape[i].size(); j++)
                temp[(temp.size() - copy_shape.size()) + i][j + (temp[0].size() - copy_shape[0].size())] = copy_shape[i][j];
    }
    for (int i = 0; i < temp.size(); i++) //If nesting has occurred thanks to the canFit function, there may be spaces left in the last column of the temporary vector. If there is an empty space in the Temporary vector, I check and delete it
    {
        if (temp[i][temp[0].size()-1] != ' ')
            control = 1;
    }
    if (control == 0) //Delete hapening in here...
    {
        for (int i = 0; i < temp.size(); i++)
            temp[i].pop_back();
    }
    copy_shape = temp;
}


vector<vector<char>> Tetromino :: return_shape()
{
    return (shape);
}
