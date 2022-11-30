#include "tetromino.h"
#include "tetris.h"

int main()
{
    char    choice;
       
    Tetromino tetro;
    
    cout << "TETROMINO PART \n\n\n";
    
    do
    {
        cout << "What are the types of tetromino?\n";
        cin >> choice;
        
        if (choice == 'I')
        {
            tetro((Tetromino::NumberOfShape::I));
            cout << endl << "Your Tetrominos :  I\n";
        }
        else if (choice == 'O')
        {
            tetro((Tetromino::NumberOfShape::O));
            cout << endl << "Your Tetrominos :  O\n";
        }
        else if (choice == 'T')
        {
            tetro((Tetromino::NumberOfShape::T));
            cout << endl << "Your Tetrominos :  T\n";
        }
        else if (choice == 'J')
        {
            tetro((Tetromino::NumberOfShape::J));
            cout << endl << "Your Tetrominos :  J\n";
        }
        else if (choice == 'L')
        {
            tetro((Tetromino::NumberOfShape::L));
            cout << endl << "Your Tetrominos :  L\n";
        }
        else if (choice == 'S')
        {
            tetro((Tetromino::NumberOfShape::S));
            cout << endl << "Your Tetrominos :  S\n";
        }
        else if(choice == 'Z')
        {
            tetro((Tetromino::NumberOfShape::Z));
            cout << endl << "Your Tetrominos :  Z\n";
        }
    }while ( ! (choice == 'I' || choice == 'O' || choice == 'T' || choice == 'J' || choice == 'L' || choice == 'S' || choice == 'Z'));
        cout << "I will print tetromino to screen with my \"print\" function...\n";
        tetro.print();
        
        
        cout << "I will control length of row of this tetromino : ";
        cout << tetro.get_row() << "\n";
        cout << "I will control length of column of this tetromino : ";
        cout << tetro.get_column() << "\n\n\n";
        
        
        
        cout << "I will look the index I want of tetromino with my get_value_of_index function...\n";
        cout << "[0][0] : " << tetro.get_value_of_index(0, 0) << endl;
        cout << "[0][1] : " << tetro.get_value_of_index(0, 1) << endl;
        cout << "\n-------------------------------------\n\n";
        
        cout << "I will rotate first once left and then two right and i will print to screen...\n";
        tetro.rotate('l');
        cout << "\nThis turn is left\n";
        tetro.print();
        tetro.rotate('r');
        tetro.rotate('r');
        cout << "\nThis turn is right for two times\n";
        tetro.print();
        
        cout << "\nTETRIS PART \n\n\n";
        
        int *coordinate;
        
        coordinate = new int[2];
        cout << "I will give size to Tetris 10x10\n\n";
        coordinate[0] = 10;
        coordinate[1] = 10;
        Tetris tetris(coordinate);
        tetris.Draw();
        
        cout << "I will add tetromino to Tetris board...\n\n";
        tetris += tetro;
        
        cout << "\nI will slide to right once..\n";
        tetris.slide_right(tetro, tetris.get_tetro_row() - tetro.get_row() + 1, tetris.get_tetro_column() + tetro.get_column() - 1);
        tetris.Draw();
        
        cout << "\nI will slide to left twice..\n";
        tetris.slide_left(tetro, tetris.get_tetro_row() - tetro.get_row() + 1, tetris.get_tetro_column());
        tetris.slide_left(tetro, tetris.get_tetro_row() - tetro.get_row() + 1, tetris.get_tetro_column());
        tetris.Draw();
        
        cout << "\nI will slide to bottom twice..\n";
        tetris.slide_bottom(tetro, tetris.get_tetro_row(), tetris.get_tetro_column() + tetro.get_column() - 1);
        tetris.slide_bottom(tetro, tetris.get_tetro_row(), tetris.get_tetro_column() + tetro.get_column() - 1);
        tetris.Draw();
        
        delete [] coordinate;
    
    cout << "\n\nDriver2 is starting...\n\n";
    
    return (0);
}
