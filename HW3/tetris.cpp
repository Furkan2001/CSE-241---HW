#include "tetris.h"
#include "tetromino.h"


Tetris :: Tetris(){}

// This is my constructor...
/* I created to create new array which has row and column..*/
// row -> coordinate[0]       column -> coordinate[1]
Tetris :: Tetris (int* coordinate)
{
    coordinate[0] += 2;
    coordinate[1] += 2;
    
    tetris_board = new char*[coordinate[0]];
    for (int i = 0; i < coordinate[0]; i++)
        tetris_board[i] = new char[coordinate[1]];
    
    for (int i = 0; i < coordinate[0]; i++)
    {
        for (int j = 0; j < coordinate[1]; j++)
        {
            if (i == 0 || i == coordinate[0] - 1 || j == 0 || j == coordinate[1] - 1)
                tetris_board[i][j] = 'x';
            else
                tetris_board[i][j] = ' ';
        }
    }
    coordinate0 = coordinate[0] - 2;
    coordinate1 = coordinate[1] - 2;
}


int Tetris :: get_tetro_row() const
{
    return (tetro_row);
}


int Tetris :: get_tetro_column() const
{
    return (tetro_column);
}



/* It is my first main function that give information about row and column from user...*/
void Tetris :: my_first_main_function(int *coordinate)
{
    while (1)   // I wrote this loop to check value that user entered...
    {
        cout << "Enter the row:\n";
        if (cin >> coordinate[0] && coordinate[0] > 0) // I wrote this if because I want quantity bigger than 0 and quantity must be integer...
            break;
        else
        {
            cout << "Please enter valid value!\n" << endl;
            cin.clear();
            cin.ignore(94, '\n');
        }
    }
    while (1)   // I wrote this loop to check value that user entered...
    {
        cout << "Enter thw column:\n";
        if (cin >> coordinate[1] && coordinate[1] > 0) // I wrote this if because I want quantity bigger than 0 and quantity must be integer...
            break;
        else
        {
            cout << "Please enter valid value!\n" << endl;
            cin.clear();
            cin.ignore(94, '\n');
        }
    }
    coordinate0 = coordinate[0];
    coordinate1 = coordinate[1];
}



/* This funtion is drawing my vector to the screen...*/
void Tetris :: Draw() const
{
    for (int i = 0; i < coordinate0 + 2; i++)
    {
        for (int j = 0; j < coordinate1 + 2; j++)
            cout << tetris_board[i][j];
        cout << endl;
    }
}



/* I wrote this function to give information about type of tetromino from user...*/
void Tetris :: my_second_main_function(Tetromino &tetromino)
{
    char choice;
    int value;
    
    value = -1;
    cout << "Which type you want? If you do not have any idea about which tetromino you want, you shold write 'R' ; If you want to quit, you must write 'Q' ...\n";
    while (1)
    {
        cin >> choice;
        if (choice == 'Q')
        {
            cout << "Program terminated...\n";
            exit(1);
        }
        else if (choice == 'R')
        {
            srand(time(0));
            value = rand() % 6;
            if (value == 0)
                choice = 'I';
            else if(value == 1)
                choice = 'O';
            else if(value == 2)
                choice = 'T';
            else if(value == 3)
                choice = 'J';
            else if(value == 4)
                choice = 'L';
            else if(value == 5)
                choice = 'S';
            else
                choice = 'Z';
        }
        if (choice == 'I' || choice == 'O' || choice == 'T' || choice == 'J' || choice == 'L' || choice == 'S' || choice == 'Z')
        {
            /* I used my operator overload () in here...*/
            if (choice == 'I')
                tetromino((Tetromino::NumberOfShape::I));
            else if (choice == 'O')
                tetromino((Tetromino::NumberOfShape::O));
            else if (choice == 'T')
                tetromino((Tetromino::NumberOfShape::T));
            else if (choice == 'J')
                tetromino((Tetromino::NumberOfShape::J));
            else if (choice == 'L')
                tetromino((Tetromino::NumberOfShape::L));
            else if (choice == 'S')
                tetromino((Tetromino::NumberOfShape::S));
            else
                tetromino((Tetromino::NumberOfShape::Z));
            break;
        }
        else
            cout << "Try AGAIN. Your entry is invalid..!\n";
    }
    
    /* I wrote this lines to control whether size is sufficient...*/
    if (tetromino.get_row() > coordinate0 || tetromino.get_column() > coordinate1)
    {
        cout << endl << "You entered size of row and column does not include the size of this tetromino..\n";
        exit(1);
    }
    cout << "Tetromino you choised is;\n";
    tetromino.print();
}


// This is my another operator overloading...
/* I added my tetromino to top of tetris board in this funtion...*/
void Tetris :: operator +=(Tetromino &tetromino)
{
    int location;

    location = ((coordinate1) / 2) - ((tetromino.get_column()) / 2); // Location holds the value of middle of tetris...
    for (int i = 0; i < (tetromino.get_row()); i++)
    {
        for (int j = 0; j < (tetromino.get_column()); j++)
        {
            if ( tetris_board[i + 1][location + j + 1] != ' ')
            {
                cout << "OUT of the game line  or  CRASH of tetrominos...\n";
                cout << "Game is over...\n";
                exit(-1);
            }
            tetris_board[i + 1][location + j + 1] = tetromino.get_value_of_index(i, j);  // I added tetromino to tetris board in here...
            if (i == tetromino.get_row() - 1 && j == 0)
            {
                tetro_row = i + 1;
                tetro_column = location + j + 1;
            }
        }
    }
    Draw();
}


void Tetris :: my_third_main_function(Tetromino &tetromino)
{
    char rotation_direction;
    int rotation_count;
    char move_direction;
    int move_count;
    
    do
    {
        cout << "Enter the rotation direction. (Right -> r,  Left -> l)\n";
        cin >> rotation_direction;
    }while(rotation_direction != 'r' && rotation_direction != 'l');
    
    while (1)   // I wrote this loop to check value that user entered...
    {
        cout << "Enter the rotation count\n";
        if (cin >> rotation_count && rotation_count > -1) // I wrote this if because I want quantity bigger than 0 and quantity must be integer...
            break;
        else
        {
            cout << "Please enter valid value!\n" << endl;
            cin.clear();
            cin.ignore(94, '\n');
        }
    }
    
    for (int i = 0; i < rotation_count; i++)
        tetromino.rotate(rotation_direction);
    cout << "-------------------------------------------\n";
    (*this)+=tetromino;
    
    do
    {
        cout << "Enter the move direction (if you want to move right, enter 'r' ; if you want to move left, enter 'l')\n";
        cin >> move_direction;
    }while(move_direction != 'r' && move_direction != 'l');
    
    while (1)   // I wrote this loop to check value that user entered...
    {
        cout << "Enter the move count\n";
        if (cin >> move_count && move_count > -1) // I wrote this if because I want quantity bigger than 0 and quantity must be integer...
            break;
        else
        {
            cout << "Please enter valid value!\n" << endl;
            cin.clear();
            cin.ignore(94, '\n');
        }
    }
    
    if(move_direction == 'r')
    {
        for (int i = 0; i < move_count; i++)
        {
            if (are_they_space_right(tetromino, tetro_row - tetromino.get_row() + 1, tetro_column + tetromino.get_column() - 1) == 0)
            {
                cout << "OUT of the game line  or  CRASH of tetrominos...\n";
                cout << "Game is over...\n";
                exit(-1);
            }
            /* parameters of slide right function are a tetromino object and indexes of highest right side of shape of this tetromino object*/
            this -> slide_right(tetromino, tetro_row - tetromino.get_row() + 1, tetro_column + tetromino.get_column() - 1);
            real_animate();
        }
        while (are_they_space_bottom(tetromino, tetro_row, tetro_column) != 0)
        {
            /* parameters of slide bottom function are a tetromino object and indexes of bottomest right side of shape of this tetromino object*/
            slide_bottom(tetromino, tetro_row, tetro_column + tetromino.get_column() - 1);
            real_animate();
        }
    }
    else
    {
        for (int i = 0; i < move_count; i++)
        {
            if (are_they_space_left(tetromino, tetro_row - tetromino.get_row() + 1, tetro_column) == 0)
            {
                cout << "OUT of the game line  or  CRASH of tetrominos...\n";
                cout << "Game is over...\n";
                exit(-1);
            }
            /* parameters of slide left function are a tetromino object and indexes of highest left side of shape of this tetromino object*/
            this -> slide_left(tetromino, tetro_row - tetromino.get_row() + 1, tetro_column);
            real_animate();
        }
        while (are_they_space_bottom(tetromino, tetro_row, tetro_column) != 0)
        {
            /* parameters of slide bottom function are a tetromino object and indexes of bottomest right side of shape of this tetromino object*/
            slide_bottom(tetromino, tetro_row, tetro_column + tetromino.get_column() - 1);
            real_animate();
        }
    }
}

/* I created this function to slide to right a tetromino which in tetris...*/
/* parameters of slide right function are a tetromino object and indexes of highest right side of shape of this tetromino object*/
void Tetris :: slide_right(Tetromino &tetromino, int row, int column)
{
    for (int i = column; column - i < tetromino.get_column(); i--)
    {
        for (int j = row; j - row < tetromino.get_row(); j++)
        {
            if ( ! (tetris_board[j][i] == ' ' && tetris_board[j][i + 1] != ' '))
            {
                tetris_board[j][i + 1] = tetris_board[j][i];
                tetris_board[j][i] = ' ';
            }
        }
    }
    tetro_column++;
}

/* I controlled to if right sides of tetromino is empty in here...  If empty return 1 but it is not empty return 0...*/
/* parameters of slide right function are a tetromino object and indexes of highest right side of shape of this tetromino object*/
bool Tetris :: are_they_space_right(Tetromino &tetromino, int row, int column)
{
    for (int i = 0; i < tetromino.get_row(); i++)
        if (tetris_board[row + i][column + 1] != ' ' && tetris_board[row + i][column] != ' ')
            return (0);
    return (1);
}


/* I created this function to slide to bottom a tetromino which in tetris...*/
/* parameters of slide bottom function are a tetromino object and indexes of bottomest right side of shape of this tetromino object*/
void Tetris :: slide_bottom(Tetromino &tetromino, int row, int column)
{
    for (int i = row; row - i < tetromino.get_row(); i--)
    {
        for (int j = column; column - j < tetromino.get_column(); j--)
        {
            if ( ! (tetris_board[i][j] == ' ' && tetris_board[i + 1][j] != ' '))
            {
                tetris_board[i + 1][j] = tetris_board[i][j];
                tetris_board[i][j] = ' ';
            }
        }
    }
    tetro_row++;
}


/* parameters of slide bottom function are a tetromino object and indexes of bottomest left side of shape of this tetromino object*/
/* I controlled to if bottom sides of tetromino is empty in here...  If empty return 1 but it is not empty return 0...*/
bool Tetris :: are_they_space_bottom(Tetromino &tetromino, int row, int column)
{
    int i = 0;
    
    while (i < tetromino.get_column())
    {
        if (tetris_board[row + 1][column + i] != ' ' && tetris_board[row][column + i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

/* parameters of slide left function are a tetromino object and indexes of highest left side of shape of this tetromino object*/
void Tetris :: slide_left(Tetromino &tetromino, int row, int column)
{
    for (int i = column; i - column < tetromino.get_column(); i++)
    {
        for (int j = row; j - row < tetromino.get_row(); j++)
        {
            if ( ! (tetris_board[j][i] == ' ' && tetris_board[j][i - 1] != ' '))
            {
                tetris_board[j][i - 1] = tetris_board[j][i];
                tetris_board[j][i] = ' ';
            }
        }
    }
    tetro_column--;
}

/* I controlled to if left sides of tetromino is empty in here...  If empty return 1 but it is not empty return 0...*/
/* parameters of slide left function are a tetromino object and indexes of highest left side of shape of this tetromino object*/
bool Tetris :: are_they_space_left(Tetromino &tetromino, int row, int column)
{
    for (int i = 0; i < tetromino.get_row(); i++)
        if (tetris_board[row + i][column - 1] != ' ' && tetris_board[row + i][column] != ' ')
            return (0);
    return (1);
}


void Tetris :: real_animate()
{
    Draw();
    this_thread::sleep_for(chrono::milliseconds(550));
    cout << "\x1b[2J"; // Erases entire screen
    cout << "\x1b[H"; // Move cursor to home position (0,0)
}

/* This is my destructor..*/
/* I created this to freed my array...*/
Tetris :: ~Tetris()
{
    //Deallocate.
    for(int i = 0; i < coordinate0 + 2; i++)
        delete [] tetris_board[i];
    delete [] tetris_board;
    tetris_board = nullptr;
}

