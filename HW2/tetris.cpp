#include "tetris.h"
#include "tetromino.h"

Tetris :: Tetris(){}


Tetris :: Tetris (int* coordinate)
{
    number_tetromino = 1;
    coordinate[0] += 6;
    coordinate[1] += 6;
    
    vector < vector < char > > temp (coordinate[0], vector<char>(coordinate[1]));  //  I wrote a frame to outside area in here...
    
    for (int i = 0; i < coordinate[0]; i++)
    {
        for (int j = 0; j < coordinate[1]; j++)
        {
            if (i == 0 || i == coordinate[0] - 1 || j == 0 || j == coordinate[1] - 1)
                temp[i][j] = 'x';
            else if (i == 1 || i == coordinate[0] - 2 || j == 1 || j == coordinate[1] - 2)
                temp[i][j] = 'x';
            else if (i == 2 || i == coordinate[0] - 3 || j == 2 || j == coordinate[1] - 3)
                temp[i][j] = 'x';
            else
                temp[i][j] = ' ';
        }
    }
    tetris_board = temp;
    copy_tetris_board = tetris_board;
}

/* It is my first main function that give information about row and column from user...*/
int* Tetris :: my_first_main_function()
{
    int *coordinate;
    
    coordinate = new int[2];
    while (1)   // I wrote this loop to check value that user entered...
    {
        cout << "Enter thw row:\n";
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
    return (coordinate);
}

/* I added my tetromino to top of tetris board in this funtion...*/
void Tetris :: add(vector<vector<char>> tetromino)
{
    int location;
    location = ((tetris_board[0].size()) / 2) - ((tetromino[0].size()) / 2); // Location holds the value of middle of tetris...
    for (int i = 0; i < (tetromino.size()); i++)
    {
        for (int j = 0; j < (tetromino[0].size()); j++)
        {
            tetris_board[i + 3][location + j] = tetromino[i][j];  // I added tetromino to tetris board in here...
            if (i == tetromino.size() - 1 && j == 0)
            {
                tetro_row = i + 3;
                tetro_column = location + j;
            }
        }
    }
}

/* This funtion is drawing my vector to the screen...*/
void Tetris :: Draw() const
{
    for (auto row : tetris_board)
    {
        for (auto col : row)
            cout << col;
        cout << endl;
    }
}

/* I wrote this function to give information about type of tetromino from user...*/
void Tetris :: my_second_main_function(Tetromino &tetromino)
{
    char choice;
    
    cout << "Which type you want? If you want to quit, you must write Q...\n";
    while (1)
    {
        cin >> choice;
        if (choice == 'Q')
        {
            cout << "Program terminated...\n";
            exit(1);
        }
        if (choice == 'I' || choice == 'O' || choice == 'T' || choice == 'J' || choice == 'L' || choice == 'S' || choice == 'Z')
        {
            if (choice == 'I')
            {
                Tetromino x((Tetromino::NumberOfShape::I));
                tetromino = x;
            }
            else if (choice == 'O')
            {
                Tetromino x((Tetromino::NumberOfShape::O));
                tetromino = x;
            }
            else if (choice == 'T')
            {
                Tetromino x((Tetromino::NumberOfShape::T));
                tetromino = x;
            }
            else if (choice == 'J')
            {
                Tetromino x((Tetromino::NumberOfShape::J));
                tetromino = x;
            }
            else if (choice == 'L')
            {
                Tetromino x((Tetromino::NumberOfShape::L));
                tetromino = x;
            }
            else if (choice == 'S')
            {
                Tetromino x((Tetromino::NumberOfShape::S));
                tetromino = x;
            }
            else
            {
                Tetromino x((Tetromino::NumberOfShape::Z));
                tetromino = x;
            }
            break;
        }
        else
            cout << "Try AGAIN. Your entry is invalid..!\n";
    }
    vector < vector < char > > temp;
    temp = tetromino.return_shape();
    /* I wrote this lines to control whether size is sufficient...*/
    if (temp.size() + 6 > tetris_board.size() || temp[0].size() + 6 > tetris_board[0].size())
    {
        cout << endl << "You entered size of row and column does not include the size of this tetromino..\n";
        exit(1);
    }
}
/* I anmiated in here...*/
void Tetris :: Animate(Tetromino &tetromino)
{
    int counter1;
    int flag1;
    
    flag1 = 0;
    counter1 = 0;
    vector < vector < char > > temp;
    if(find_space_and_fit(tetromino) == 1) // This function find point which best fit and type of shape...
    {
        temp = tetromino.return_shape();
        add(temp);
        real_animate(); // it animated in here...
        if (tetro_column <= space_column) // Space column and row is best fit point.. Tetro column and row is point of tetromino.
        {
            while (tetro_column < space_column)
            {
                slide_right(tetromino, tetro_row - temp.size() + 1, tetro_column - temp[0].size() - 1); // it slides to right...
                real_animate(); // it animated in here...
                tetro_column++; //This is most left and most down point of tetromino(column).
            }
            if (are_they_space_up(tetromino, space_row, space_column) == 1)
            {
                while (tetro_row != space_row)
                {
                    slide_bottom(tetromino, tetro_row, tetro_column + temp[0].size() - 1);  // it slides to down
                    real_animate();  // it animated in here...
                    tetro_row++; //This is most left and most down point of tetromino(row).
                }
            }
            else
            {
                while (tetro_column < tetris_board[0].size() - 3)
                {
                    slide_right(tetromino, tetro_row - temp.size() + 1, tetro_column - temp[0].size() -1); // it slides to right..
                    real_animate();  // it animated in here...
                    tetro_column++;//This is most left and most down point of tetromino(column).
                    counter1++;
                    if (are_they_space_up(tetromino, space_row, space_column + counter1) == 1)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 1)
                {
                    while (tetro_row != space_row)
                    {
                        slide_bottom(tetromino, tetro_row, tetro_column + temp[0].size() - 1);   // it slides to down
                        real_animate();   // it animated in here...
                        tetro_row++;   //This is most left and most down point of tetromino(row).
                    }
                    while(tetro_column != space_column)
                    {
                        slide_left(tetromino, tetro_row - temp.size() + 1, tetro_column);
                        real_animate();   // it animated in here...
                        tetro_column--;   //This is most left and most down point of tetromino(column).
                    }
                }
                else
                {
                   while(1)
                   {
                       if (are_they_space_bottom(tetromino, tetro_row, tetro_column) == 1)
                       {
                           slide_bottom(tetromino,tetro_row, tetro_column + temp[0].size() - 1);
                           tetro_row++;   //This is most left and most down point of tetromino(row).
                           real_animate();    // it animated in here...
                       }
                       else
                       {
                           break;
                       }
                   }
                }
            }
        }
        else
        {
            while (tetro_column > space_column)
            {
                slide_left(tetromino, tetro_row - temp.size() + 1, tetro_column);
                real_animate();  // it animated in here...
                tetro_column--;   //This is most left and most down point of tetromino(column).
            }
            if (are_they_space_up(tetromino, space_row, space_column) == 1)
            {
                while (tetro_row != space_row )
                {
                    slide_bottom(tetromino, tetro_row, tetro_column + temp[0].size() - 1);
                    real_animate();   // it animated in here...
                    tetro_row++;   //This is most left and most down point of tetromino(row).
                }
            }
            else
            {
                while (tetro_column < tetris_board[0].size() - 3)
                {
                    slide_right(tetromino, tetro_row - temp.size() + 1, tetro_column - temp[0].size() -1);
                    real_animate();    // it animated in here...
                    tetro_column++;   //This is most left and most down point of tetromino(column).
                    counter1++;
                    if (are_they_space_up(tetromino, space_row, space_column + counter1) == 1)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 1)
                {
                    while (tetro_row != space_row)
                    {
                        slide_bottom(tetromino, tetro_row, tetro_column + temp[0].size() - 1);
                        real_animate();    // it animated in here...
                        tetro_row++;   //This is most left and most down point of tetromino(row).
                    }
                    while(tetro_column != space_column)
                    {
                        slide_left(tetromino, tetro_row - temp.size() + 1, tetro_column);
                        real_animate();     // it animated in here...
                        tetro_column--;     //This is most left and most down point of tetromino(column).
                    }
                }
                else
                {
                   while(1)
                   {
                       if (are_they_space_bottom(tetromino, tetro_row, tetro_column) == 1)
                       {
                           slide_bottom(tetromino,tetro_row, tetro_column + temp[0].size() - 1);
                           real_animate();    // it animated in here...
                           tetro_row++;   //This is most left and most down point of tetromino(row).
                       }
                       else
                       {
                           break;
                       }
                   }
                }
            }
        }
    }
    else
    {
        cout << "Game is over" << endl;
        exit(1);
    }
    number_tetromino++;
}

// This function find point which best fit and type of shape...
bool Tetris :: find_space_and_fit(Tetromino &tetromino)
{
    vector < vector < char > > temp;
    int counter;
    int fulling;
    int dead;
    
    for (int a = tetris_board.size() - 4; a >= 3; a--)
    {
        for (int b = 3; b < tetris_board[0].size() - 3; b++)
        {
            if (tetris_board[a][b] == ' ')
            {
                space_row = a;
                space_column = b;
                counter = 0;
                while (counter < 4)
                {
                    copy_tetris_board = tetris_board;
                    temp = tetromino.return_shape();
                    if (temp[temp.size() - 1][0] != ' ' || number_tetromino > 1)
                    {
                        
//--------------------------------------------------------------------------------------------------------
                        dead = 0;
                        while (dead < 4)
                        {
                            for (int i = temp.size() - 1; i >= 0; i--)
                            {
                                for (int j = 0; j < temp[0].size(); j++)
                                {
                                    copy_tetris_board[space_row + i - temp.size() - 1][space_column + j - 2] = temp[i][j];
                                }
                            }
                            
                            fulling = 0;
                            for (int i = copy_tetris_board.size() - 1; i > 0; i--)
                            {
                                for (int j = 0; j < copy_tetris_board[0].size(); j++)
                                {
                                    if (copy_tetris_board[i][j] != ' ' && copy_tetris_board[i][j] != 'x')
                                        fulling++;
                                }
                            }
                            if (fulling == (4 * number_tetromino))
                                return (1);
                            dead++;
                        }
                         copy_tetris_board = tetris_board;
//--------------------------------------------------------------------------------------------------------
                        dead = 0;
                        while (dead < 4)
                        {
                            for (int i = temp.size() - 1; i >= 0; i--)
                            {
                                for (int j = 0; j < temp[0].size(); j++)
                                {
                                    copy_tetris_board[space_row + i - temp.size() - 1][space_column + j - 1] = temp[i][j];
                                }
                            }
                            
                            fulling = 0;
                            for (int i = copy_tetris_board.size() - 1; i > 0; i--)
                            {
                                for (int j = 0; j < copy_tetris_board[0].size(); j++)
                                {
                                    if (copy_tetris_board[i][j] != ' ' && copy_tetris_board[i][j] != 'x')
                                        fulling++;
                                }
                            }
                            if (fulling == (4 * number_tetromino))
                                return (1);
                            dead++;
                        }
                         copy_tetris_board = tetris_board;
//--------------------------------------------------------------------------------------------------------
                        for (int i = temp.size() - 1; i >= 0; i--)
                        {
                            for (int j = 0; j < temp[0].size(); j++)
                            {
                                copy_tetris_board[space_row + i - temp.size() - 1][space_column + j] = temp[i][j];
                            }
                        }
                        fulling = 0;
                        for (int i = 3; i < copy_tetris_board.size() - 3; i++)
                        {
                            for (int j = 3; j < copy_tetris_board[0].size() - 3; j++)
                            {
                                if (copy_tetris_board[i][j] != ' ')
                                {
                                    fulling++;
                                }
                            }
                        }
                        if (fulling == (4 * number_tetromino))
                            return (1);
                        else
                            tetromino.rotate('r');
                    }
                    else
                    {
                        tetromino.rotate('r');
                    }
                    counter++;
                }
            }
        }
    }
    return (0);
}


bool Tetris :: are_they_space_up(Tetromino &tetromino, int row, int column)
{
    vector < vector < char > > temp;
    int i = 0;
    int j = 0;
    
    temp = tetromino.return_shape();
    while (row - i > tetro_row)
    {
        j = 0;
        while (column + j < column + temp[0].size())
        {
            if(tetris_board[row - i][column + j] != ' ')
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}


void Tetris :: slide_right(Tetromino &tetromino, int row, int column)
{
    vector < vector < char > > temp;
    
    temp = tetromino.return_shape();
    for (int i = column; column - i < temp[0].size(); i--)
    {
        for (int j = row; j - row < temp.size(); j++)
        {
            tetris_board[j][i + 1] = tetris_board[j][i];
            tetris_board[j][i] = ' ';
        }
    }
}

void Tetris :: slide_bottom(Tetromino &tetromino, int row, int column)
{
    vector < vector < char > > temp;
    
    temp = tetromino.return_shape();
    for (int i = row; row - i < temp.size(); i--)
    {
        for (int j = column; column - j < temp[0].size(); j--)
        {
            tetris_board[i + 1][j] = tetris_board[i][j];
            tetris_board[i][j] = ' ';
        }
    }
}


//Row column olarak tetrominonun sol en altını al.
//sadece 1 satır boşluk kontrol eder.
bool Tetris :: are_they_space_bottom(Tetromino &tetromino, int row, int column)
{
    vector < vector < char > > temp;
    int i = 0;
    
    temp = tetromino.return_shape();
    while (i < temp[0].size())
    {
        if (tetris_board[row + 1][column + i] != ' ')
            return (0);
    }
    return (1);
}


void Tetris :: slide_left(Tetromino &tetromino, int row, int column)
{
    vector < vector < char > > temp;
    
    temp = tetromino.return_shape();
    for (int i = row; i - row < temp.size(); i++)
    {
        for (int j = column; j - column < temp[0].size(); j++)
        {
            tetris_board[i][j - 1] = tetris_board[i][j];
            tetris_board[i][j] = ' ';
        }
    }
}


void Tetris :: real_animate()
{
    Draw();
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "\x1b[2J"; // Erases entire screen
    cout << "\x1b[H"; // Move cursor to home position (0,0)
}
