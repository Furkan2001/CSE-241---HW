#include "array.hpp"


Tetris2 :: Tetris2(){ flag = 0; number_of_moves = 0; }

// This is my constructor...
/* I created to create new array which has row and column..*/
// row -> coordinate[0]       column -> coordinate[1]
Tetris2 :: Tetris2 (int* coordinate)
{
    
    int length;
    coordinate[0] += 2;
    coordinate[1] += 2;
    number_of_moves = 0;
    flag = 0;
    
    length = coordinate[0] *  coordinate[1];
    
    tetris_board = new char[length];
    coordinate0 = coordinate[0] - 2;  // Normal row
    coordinate1 = coordinate[1] - 2;  // Normal column
    
    for (int i = 0; i < coordinate[0]; i++)
    {
        for (int j = 0; j < coordinate[1]; j++)
        {
            if (i == 0 || i == coordinate[0] - 1 || j == 0 || j == coordinate[1] - 1)
                tetris_board[(i * coordinate[1]) + j] = 'x';
            else
                tetris_board[(i * coordinate[1]) + j] = ' ';
        }
    }
}


int Tetris2 :: get_tetro_row() const
{
    return (tetro_row);
}


int Tetris2 :: get_tetro_column() const
{
    return (tetro_column);
}


int Tetris2 :: numberOfMoves() const
{
    return (number_of_moves);
}


/* It is my first main function that give information about row and column from user...*/
void Tetris2 :: my_first_main_function(int *coordinate)
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
void Tetris2 :: Draw() const
{
    for (int i = 0; i < coordinate0 + 2; i++)
    {
        for (int j = 0; j < coordinate1 + 2; j++)
            cout << tetris_board[(i * (coordinate1 + 2)) + j];
        cout << endl;
    }
    cout << endl;
}


void Tetris2 :: Draw_v1() const
{
    for (auto row : v1)
    {
        for (auto col : row)
            cout << col;
        cout << endl;
    }
    cout << endl;
}


/* I wrote this function to give information about type of tetromino from user...*/
void Tetris2 :: my_second_main_function(Tetromino &tetromino)
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
void Tetris2 :: operator +=(Tetromino &tetromino)
{
    int location;
    
    move_info.tetromin = 'X';
    move_info.number_right = 0;
    move_info.number_down = 0;
    move_info.number_left = 0;
    
    if (tetromino.get_hold_enum() == 'I')
        move_info.tetromin = 'I';
    else if (tetromino.get_hold_enum() == 'S')
        move_info.tetromin = 'S';
    else if (tetromino.get_hold_enum() == 'Z')
        move_info.tetromin = 'Z';
    else if (tetromino.get_hold_enum() == 'L')
        move_info.tetromin = 'L';
    else if (tetromino.get_hold_enum() == 'J')
        move_info.tetromin = 'J';
    else if (tetromino.get_hold_enum() == 'O')
        move_info.tetromin = 'O';
    else if (tetromino.get_hold_enum() == 'T')
        move_info.tetromin = 'T';

    flag++;
    location = ((coordinate1) / 2) - ((tetromino.get_column()) / 2); // Location holds the value of middle of tetris...
    for (int i = 0; i < (tetromino.get_row()); i++)
    {
        for (int j = 0; j < (tetromino.get_column()); j++)
        {
            if ( tetris_board[((i + 1) * (coordinate1 + 2)) + location + j + 1] != ' ')
            {
                cout << "OUT of the game line  or  CRASH of tetrominos...\n";
                cout << "Game is over...\n";
                exit(-1);
            }
            tetris_board[((i + 1) * (coordinate1 + 2)) + location + j + 1] = tetromino.get_value_of_index(i, j);  // I added tetromino to tetris board in here...
            if (i == tetromino.get_row() - 1 && j == 0)
            {
                tetro_row = i + 1;
                tetro_column = location + j + 1;
            }
        }
    }
    Draw();
}


void Tetris2 :: my_third_main_function(Tetromino &tetromino)
{
    char rotation_direction;
    int rotation_count;
    char move_direction;
    int move_count;
    
    do
    {
        cout << "Enter the rotation direction. (Right -> r,  Left -> l) (You can rotate the tetromino that appears above, according to the shape you want to see in the middle of the tetris board..)\n";
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
    {
        number_of_moves++;
        tetromino.rotate(rotation_direction);
    }
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
    //tetro_row - tetro_column  tetrominonun boardın içerisindeki en sağ üstünü tutar...
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
void Tetris2 :: slide_right(Tetromino &tetromino, int row, int column)
{
    for (int i = column; column - i < tetromino.get_column(); i--)
    {
        for (int j = row; j - row < tetromino.get_row(); j++)
        {
            if ( ! (tetris_board[(j * (coordinate1 + 2)) + i] == ' ' && tetris_board[(j * (coordinate1 + 2)) + i + 1] != ' '))
            {
                tetris_board[(j * (coordinate1 + 2)) + i + 1] = tetris_board[(j * (coordinate1 + 2)) + i];
                tetris_board[(j * (coordinate1 + 2)) + i] = ' ';
            }
        }
    }
    tetro_column++;
    number_of_moves++;
    this -> move_info.number_right++;
}

/* I controlled to if right sides of tetromino is empty in here...  If empty return 1 but it is not empty return 0...*/
/* parameters of slide right function are a tetromino object and indexes of highest right side of shape of this tetromino object*/
bool Tetris2 :: are_they_space_right(Tetromino &tetromino, int row, int column)
{
    for (int i = 0; i < tetromino.get_row(); i++)
        if (tetris_board[((row + i) * (coordinate1 + 2)) + column + 1] != ' ' && tetris_board[((row + i) * (coordinate1 + 2)) + column] != ' ')
            return (0);
    return (1);
}


/* I created this function to slide to bottom a tetromino which in tetris...*/
/* parameters of slide bottom function are a tetromino object and indexes of bottomest right side of shape of this tetromino object*/
void Tetris2 :: slide_bottom(Tetromino &tetromino, int row, int column)
{
    for (int i = row; row - i < tetromino.get_row(); i--)
    {
        for (int j = column; column - j < tetromino.get_column(); j--)
        {
            if ( ! (tetris_board[(i * (coordinate1 + 2)) + j] == ' ' && tetris_board[((i + 1) * (coordinate1 + 2)) + j] != ' '))
            {
                tetris_board[((i + 1) * (coordinate1 + 2)) + j] = tetris_board[((i) * (coordinate1 + 2)) + j];
                tetris_board[(i * (coordinate1 + 2)) + j] = ' ';
            }
        }
    }
    tetro_row++;
    number_of_moves++;
    this -> move_info.number_down++;
}


/* parameters of slide bottom function are a tetromino object and indexes of bottomest left side of shape of this tetromino object*/
/* I controlled to if bottom sides of tetromino is empty in here...  If empty return 1 but it is not empty return 0...*/
bool Tetris2 :: are_they_space_bottom(Tetromino &tetromino, int row, int column)
{
    int i = 0;
    
    while (i < tetromino.get_column())
    {
        if (tetris_board[((row + 1) * (coordinate1 + 2)) + column + i] != ' ' && tetris_board[(row * (coordinate1 + 2)) + column + i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

/* parameters of slide left function are a tetromino object and indexes of highest left side of shape of this tetromino object*/
void Tetris2 :: slide_left(Tetromino &tetromino, int row, int column)
{
    for (int i = column; i - column < tetromino.get_column(); i++)
    {
        for (int j = row; j - row < tetromino.get_row(); j++)
        {
            if ( ! (tetris_board[(j * (coordinate1 + 2)) + i] == ' ' && tetris_board[(j * (coordinate1 + 2)) + i - 1] != ' '))
            {
                tetris_board[(j * (coordinate1 + 2)) + i - 1] = tetris_board[(j * (coordinate1 + 2)) + i];
                tetris_board[(j * (coordinate1 + 2)) + i] = ' ';
            }
        }
    }
    tetro_column--;
    number_of_moves++;
    this -> move_info.number_left++;
}

/* I controlled to if left sides of tetromino is empty in here...  If empty return 1 but it is not empty return 0...*/
/* parameters of slide left function are a tetromino object and indexes of highest left side of shape of this tetromino object*/
bool Tetris2 :: are_they_space_left(Tetromino &tetromino, int row, int column)
{
    for (int i = 0; i < tetromino.get_row(); i++)
        if (tetris_board[((row + i) * (coordinate1 + 2)) + column - 1] != ' ' && tetris_board[((row + i) * (coordinate1 + 2)) + column] != ' ')
            return (0);
    return (1);
}


void Tetris2 :: real_animate()
{
    Draw();
    this_thread::sleep_for(chrono::milliseconds(550));
    cout << "\x1b[2J"; // Erases entire screen
    cout << "\x1b[H"; // Move cursor to home position (0,0)
}


MoveActions Tetris2 :: lastMove() const
{
    if (flag != 0)
    {
        cout << endl << endl << "Last INFORMATIONS ; " << endl;
        cout << "Last moving Tetromino : " << move_info.tetromin << endl;
        cout << "Number of times the last Tetromino went right : " << move_info.number_right << endl;
        cout << "Number of times the last Tetromino went left : " << move_info.number_left << endl;
        cout << "Number of times the last Tetromino went bottom : " << move_info.number_down << endl << endl;
        
        return (move_info);
    }
    else
        throw "No last move...";
}


void Tetris2 :: equalBoards()   // I equaled my real tetris board and vector which I read from file in here...
{
    for(int i = 0; i < v1.size(); i++)
    {
        for(int j = 0; j < v1[0].size(); j++)
        {
            tetris_board[(i * v1[0].size()) + j] = v1[i][j];   // Deep Copy not Shallow copy
        }
    }
    coordinate0 = (int) v1.size() - 2;
    coordinate1 = (int) v1[0].size() - 2;
}


void Tetris2 :: readFromFile(const string file)
{
    ifstream read;   //  Streaming for read from file
    read.open(file);  // Open the file
    v1.resize(0, vector<char>(0));  // I resized in here because it may be has a board from before
    
    string line;
    while (getline(read, line))
    {
        vector <char> temporary;
        for (auto x : line)
            if (x != '\n')
                temporary.push_back(x);
        v1.push_back(temporary);
    }
    
    read.close();  // Close the file
}


void Tetris2 :: writeToFile(const string file)
{
    ofstream write;  //  Streaming for write to file

    write.open(file);   // Open the file
   
    for (int i = 0; i < coordinate0 + 2; i++)
    {
        for (int j = 0; j < coordinate1 + 2; j++)
            write << tetris_board[(i * (coordinate1 + 2)) + j];
        write << endl;
    }
   
   write.close();            // Close the file
}


/* This is my destructor..*/
/* I created this to freed my array...*/
Tetris2 :: ~Tetris2()
{
    delete [] tetris_board;
    tetris_board = nullptr;
}
