#include "tetromino.h"
#include "tetris.h"

/* I created this function to reach number_of_row.. */
int Tetromino :: get_row()
{
    return (number_of_row);
}

/* I created this function to reach number of column.. */
int Tetromino :: get_column()
{
    return (number_of_column);
}


/* I created this function to reach indexes I want of shape array... */
char Tetromino :: get_value_of_index(int i, int j)
{
    return (shape[i][j]);
}



Tetromino :: Tetromino(NumberOfShape choice)
{
    VariableOfShape = (int) choice; // I assigned my enum variable to an integer variable. My purpose is that can use it in next lines...
    if (choice == NumberOfShape::I)  // I filled my arrays.
    {
        shape = new char*[1];
        shape[0] = new char[4];
        for (int i = 0; i < 4; i++)
        {
            shape[0][i] = 'I';
        }
        shape[0][4] = '\0';
        number_of_row = 1;
        number_of_column = 4;
    }
    else if (choice == NumberOfShape::O)
    {
        shape = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[2];
            shape[i][0] = 'O';
            shape[i][1] = 'O';
        }
        shape[0][2] = '\0';
        shape[1][2] = '\0';
        number_of_row = 2;
        number_of_column = 2;
    }
    else if (choice == NumberOfShape::T)
    {
        shape = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
            shape[i][1] = 'T';
        }
        shape[0][0] = 'T';
        shape[0][2] = 'T';
        shape[1][0] = ' ';
        shape[1][2] = ' ';
        shape[0][3] = '\0';
        shape[1][3] = '\0';
        number_of_row = 2;
        number_of_column = 3;
    }
    else if (choice == NumberOfShape::J)
    {
        shape = new char*[3];
        for (int i = 0; i < 3; i++)
        {
            shape[i] = new char[2];
            shape[i][1] = 'J';
        }
        shape[0][0] = ' ';
        shape[1][0] = ' ';
        shape[2][0] = 'J';
        shape[0][2] = '\0';
        shape[1][2] = '\0';
        shape[2][2] = '\0';
        number_of_row = 3;
        number_of_column = 2;
    }
    else if (choice == NumberOfShape::L)
    {
        shape = new char*[3];
        for (int i = 0; i < 3; i++)
        {
            shape[i] = new char[2];
            shape[i][0] = 'L';
        }
        shape[0][1] = ' ';
        shape[1][1] = ' ';
        shape[2][1] = 'L';
        shape[0][2] = '\0';
        shape[1][2] = '\0';
        shape[2][2] = '\0';
        number_of_row = 3;
        number_of_column = 2;
    }
    else if (choice == NumberOfShape::S)
    {
        shape = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
            shape[i][1] = 'S';
        }
        shape[0][0] = ' ';
        shape[0][2] = 'S';
        shape[1][0] = 'S';
        shape[1][2] = ' ';
        shape[0][3] = '\0';
        shape[1][3] = '\0';
        number_of_row = 2;
        number_of_column = 3;
    }
    else if (choice == NumberOfShape::Z)
    {
        shape = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
            shape[i][1] = 'Z';
        }
        shape[0][0] = 'Z';
        shape[0][2] = ' ';
        shape[1][0] = ' ';
        shape[1][2] = 'Z';
        shape[0][3] = '\0';
        shape[1][3] = '\0';
        number_of_row = 2;
        number_of_column = 3;
    }
}


Tetromino :: Tetromino()  // I created this constructor in my main file first to be able to create the objects of this class without using the constructor parameters.
{}


void Tetromino :: print() const  // I created this function to print my array..
{
    for (int i = 0; i < number_of_row; i++)  // number of rows
    {
        for (int j = 0; j < number_of_column; j++)  // number of colummns
        {
            cout << shape[i][j];  //  I printed in here...
        }
        cout << endl;
    }
    cout << endl;
}



void Tetromino :: rotate(char direction_of_rotation)
{
    char **temp;  // I created temporary array in here..
    int temp_int;
    
    temp = new char*[number_of_column];
    for (int i = 0; i < number_of_column; i++)
        temp[i] = new char[number_of_row];
    
    for (int i = 0; i < number_of_column; i++)   // By relocating the dimensions of my original vector, I defined the temporal vector as large enough to hold the return values. Shape's row -> temp's column, Shape's column -> temp's row
    {
        for(int j = 0; j < number_of_row; j++)
        {
            temp[i][j] = ' ';
        }
    }
    if (VariableOfShape != 1) // I never rotated 'O' because it will take the same shape when it is rotated.
    {
        if (direction_of_rotation == 'r')  // 'r' means turn to the right side..
        {
            if (VariableOfShape == 0)  // I sent the values ​​in the shape vector to the temp vector according to the coordinates that will occur when it returns...
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'I')
                            temp[j][number_of_row - 1 - i] = 'I';
            }
            else if (VariableOfShape == 2)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'T')
                            temp[j][number_of_row - 1 - i] = 'T';
            }
            else if (VariableOfShape == 3)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'J')
                            temp[j][number_of_row - 1 - i] = 'J';
            }
            else if (VariableOfShape == 4)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'L')
                            temp[j][number_of_row - 1 - i] = 'L';
            }
            else if (VariableOfShape == 5)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'S')
                            temp[j][number_of_row - 1 - i] = 'S';
            }
            else if (VariableOfShape == 6)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'Z')
                            temp[j][number_of_row - 1 - i] = 'Z';
            }
            delete [] shape;
            shape = new char*[number_of_column];
            for (int i = 0; i < number_of_column; i++)
                shape[i] = new char[number_of_row];
            for (int i = 0; i < number_of_column; i++)
                for (int j = 0; j < number_of_row; j++)
                    shape[i][j] = temp[i][j];    // I equated the vector named temp that I created to the vector named shape..
            delete [] temp;
        }
        else      //  means turn to the left side..
        {
            if (VariableOfShape == 0)  // I sent the values ​​in the shape vector to the temp vector according to the coordinates that will occur when it returns...
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'I')
                            temp[number_of_column - 1 - j][i] = 'I';
            }
            else if (VariableOfShape == 2)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'T')
                            temp[number_of_column - 1 - j][i] = 'T';
            }
            else if (VariableOfShape == 3)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'J')
                            temp[number_of_column - 1 - j][i] = 'J';
            }
            else if (VariableOfShape == 4)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'L')
                            temp[number_of_column - 1 - j][i] = 'L';
            }
            else if (VariableOfShape == 5)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'S')
                            temp[number_of_column - 1 - j][i] = 'S';
            }
            else if (VariableOfShape == 6)
            {
                for (int i = 0; i < number_of_row; i++)
                    for (int j = 0; j < number_of_column; j++)
                        if (shape[i][j] == 'Z')
                            temp[number_of_column - 1 - j][i] = 'Z';
            }
            delete [] shape;
            shape = new char*[number_of_column];
            for (int i = 0; i < number_of_column; i++)
                shape[i] = new char[number_of_row];
            for (int i = 0; i < number_of_column; i++)
                for (int j = 0; j < number_of_row; j++)
                    shape[i][j] = temp[i][j];    // I equated the vector named temp that I created to the vector named shape..
            delete [] temp;
        }
    }

    temp_int = number_of_row;
    number_of_row = number_of_column;         // Since the column and row numbers will change, I saved it again after returning it.
    number_of_column = temp_int;       // Since the column and row numbers will change, I saved it again after returning it.
}



char** Tetromino :: return_shape()
{
    return (shape);
}


/* I created this operator overloading to create new tetris which has new dimensions...*/
/* This function is same with my constructor...*/
void Tetromino :: operator()(NumberOfShape choice)
{
    VariableOfShape = (int) choice; // I assigned my enum variable to an integer variable. My purpose is that can use it in next lines...
    if (choice == NumberOfShape::I)  // I filled my arrays.
    {
        shape = new char*[1];
        shape[0] = new char[4];
        for (int i = 0; i < 4; i++)
        {
            shape[0][i] = 'I';
        }
        shape[0][4] = '\0';
        number_of_row = 1;
        number_of_column = 4;
    }
    else if (choice == NumberOfShape::O)
    {
        shape = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[2];
            shape[i][0] = 'O';
            shape[i][1] = 'O';
        }
        shape[0][2] = '\0';
        shape[1][2] = '\0';
        number_of_row = 2;
        number_of_column = 2;
    }
    else if (choice == NumberOfShape::T)
    {
        shape = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
            shape[i][1] = 'T';
        }
        shape[0][0] = 'T';
        shape[0][2] = 'T';
        shape[1][0] = ' ';
        shape[1][2] = ' ';
        shape[0][3] = '\0';
        shape[1][3] = '\0';
        number_of_row = 2;
        number_of_column = 3;
    }
    else if (choice == NumberOfShape::J)
    {
        shape = new char*[3];
        for (int i = 0; i < 3; i++)
        {
            shape[i] = new char[2];
            shape[i][1] = 'J';
        }
        shape[0][0] = ' ';
        shape[1][0] = ' ';
        shape[2][0] = 'J';
        shape[0][2] = '\0';
        shape[1][2] = '\0';
        shape[2][2] = '\0';
        number_of_row = 3;
        number_of_column = 2;
    }
    else if (choice == NumberOfShape::L)
    {
        shape = new char*[3];
        for (int i = 0; i < 3; i++)
        {
            shape[i] = new char[2];
            shape[i][0] = 'L';
        }
        shape[0][1] = ' ';
        shape[1][1] = ' ';
        shape[2][1] = 'L';
        shape[0][2] = '\0';
        shape[1][2] = '\0';
        shape[2][2] = '\0';
        number_of_row = 3;
        number_of_column = 2;
    }
    else if (choice == NumberOfShape::S)
    {
        shape = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
            shape[i][1] = 'S';
        }
        shape[0][0] = ' ';
        shape[0][2] = 'S';
        shape[1][0] = 'S';
        shape[1][2] = ' ';
        shape[0][3] = '\0';
        shape[1][3] = '\0';
        number_of_row = 2;
        number_of_column = 3;
    }
    else if (choice == NumberOfShape::Z)
    {
        shape = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
            shape[i][1] = 'Z';
        }
        shape[0][0] = 'Z';
        shape[0][2] = ' ';
        shape[1][0] = ' ';
        shape[1][2] = 'Z';
        shape[0][3] = '\0';
        shape[1][3] = '\0';
        number_of_row = 2;
        number_of_column = 3;
    }
}


/* This is my destructor...*/
/* I freed my array in here...*/
Tetromino :: ~Tetromino()
{
    //deallocate...
    for (int i = 0; i < number_of_row; i++)
        delete [] shape[i];
    delete [] shape;
    
    shape = nullptr;
}

