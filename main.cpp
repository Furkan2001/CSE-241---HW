#include "tetromino.h"

int main()
{
    int     quantity,i,j;
    char    choice;
    
    j = -1;
    i = 0;
    while (1)   // I wrote this loop to check value that user entered...
    {
        cout << "How many tetrominos?\n";
        if (cin >> quantity && quantity > 0) // I wrote this if because I want quantity bigger than 0 and quantity must be integer...
            break;
        else
        {
            cout << "Please enter valid value!\n" << endl;
            cin.clear();
            cin.ignore(94, '\n');
        }
    }
    vector <Tetromino> tetris(quantity);
    cout << "What are the types?\n";
    while (i < quantity)
    {
        cin >> choice;
        if (choice == 'I' || choice == 'O' || choice == 'T' || choice == 'J' || choice == 'L' || choice == 'S' || choice == 'Z')
        {
            if (choice == 'I')
            {
                Tetromino x((Tetromino::NumberOfShape::I));
                tetris[i] = x;
            }
            else if (choice == 'O')
            {
                Tetromino x((Tetromino::NumberOfShape::O));
                tetris[i] = x;
            }
            else if (choice == 'T')
            {
                Tetromino x((Tetromino::NumberOfShape::T));
                tetris[i] = x;
            }
            else if (choice == 'J')
            {
                Tetromino x((Tetromino::NumberOfShape::J));
                tetris[i] = x;
            }
            else if (choice == 'L')
            {
                Tetromino x((Tetromino::NumberOfShape::L));
                tetris[i] = x;
            }
            else if (choice == 'S')
            {
                Tetromino x((Tetromino::NumberOfShape::S));
                tetris[i] = x;
            }
            else
            {
                Tetromino x((Tetromino::NumberOfShape::Z));
                tetris[i] = x;
            }
            i++;
        }
        else
            cout << "Try AGAIN. Your entry is invalid..!\n";
    }
    i = 0;
    cout << endl << "Your Tetrominos\n";
    while(i < quantity)
    {
        tetris[i].print();
        i++;
    }
    tetris[0].JustForFirstObj();
    i = 0;
    if (quantity > 1)
    {
        while (i < quantity - 1)
        {
            tetris[i+1].canFit(tetris[i]);
            tetris[i+1].CreateNewTetromino(tetris[i]);
            i++;
        }
    }
    cout << "Horizontally best-fit tetrominos\n";
    tetris[quantity - 1].print_extra();
    return (0);
}
