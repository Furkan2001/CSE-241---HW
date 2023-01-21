#include "tetromino.hpp"
#include "vector.hpp"
#include "array.hpp"
#include "adapter.hpp"
#include "abstractTetris.hpp"
#include "adapter.cpp"

Tetromino createTetromino();
void TetrisGame(abstractTetris* tetris, int* coordinate, Tetromino &tetro);
void TetrisForExceptionControl();

int main()
{
    try
    {
        Tetromino tetro;
        
        tetro = createTetromino();
        
        int *coordinate;
            
        coordinate = new int[2];
        cout << "\nI will give size to Tetris 10x10\n\n\n";
        coordinate[0] = 10;
        coordinate[1] = 10;
        
        
        abstractTetris* ptr;
        
        cout << "\nVECTOR TETRIS PART \n\n\n" << endl;
        Tetris tetris(coordinate);
        ptr = &tetris;
        TetrisGame(ptr, coordinate, tetro);
        cout << "\nThe END of VECTOR TETRIS PART \n\n\n" << endl << "-----------------------------------------------" << endl << endl;
        
        cout << "\nI will give size to Tetris 12x12\n\n\n";
        
        cout << "\n1D ARRAY TETRIS PART \n\n\n" << endl;
        Tetris2 tetris2(coordinate);
        ptr = &tetris2;
        TetrisGame(ptr, coordinate, tetro);
        cout << "\nThe END of 1D ARRAY TETRIS PART \n\n\n" << endl << "-----------------------------------------------" << endl << endl;
        
        cout << "\nI will give size to Tetris 14x14\n\n\n";
        cout << "----------------------------------------" << endl << "This is VECTOR in Adapter class..." << endl << "----------------------------------------" << endl << endl;
        cout << "\nADAPTER TETRIS PART \n\n\n" << endl;
        Tetris3<vector<char>> tetris3(coordinate);
        ptr = &tetris3;
        TetrisGame(ptr, coordinate, tetro);
        cout << "\nThe END of ADAPTER TETRIS PART \n\n\n" << endl << "-----------------------------------------------" << endl << endl;
        
        
        cout << "\nI will give size to Tetris 16x16\n\n\n";
        cout << "----------------------------------------" << endl << "This is DEQUE in Adapter class..." << endl << "----------------------------------------" << endl << endl;
        cout << "\nADAPTER TETRIS PART \n\n\n" << endl;
        Tetris3<deque<char>> tetris4(coordinate);
        ptr = &tetris4;
        TetrisGame(ptr, coordinate, tetro);
        cout << "\nThe END of ADAPTER TETRIS PART \n\n\n" << endl << "-----------------------------------------------" << endl << endl;
        
        
        cout << "\nI will give size to Tetris 18x18\n\n\n";
        cout << "----------------------------------------" << endl << "This is VECTOR in Adapter class..." << endl << "----------------------------------------" << endl << endl;
        cout << "\nADAPTER TETRIS PART \n\n\n" << endl;
        Tetris3<vector<char>> tetris5(coordinate);
        ptr = &tetris5;
        TetrisGame(ptr, coordinate, tetro);
        cout << "\nThe END of ADAPTER TETRIS PART \n\n\n" << endl << "-----------------------------------------------" << endl << endl;
        
        cout << endl << "I will demonstrate to work my lastMove function correctly in here..." << endl << endl;
        TetrisForExceptionControl();
        
        delete [] coordinate;
        coordinate = nullptr;
        
    }
    catch (const char* txtException)
    {
        cout << "Exception : " << txtException << endl;
    }
    
    cout << "\n\nDriver2 is starting...\n\n";
    
    return (0);
}



void TetrisGame(abstractTetris* tetris, int* coordinate, Tetromino &tetro)
{
    char    choice;
    tetris -> Draw();
        
    cout << "I will add tetromino to Tetris board...\n\n";
    (*tetris) += tetro;
        
    cout << "\nI will slide to right once..\n";
    tetris -> slide_right(tetro, tetris -> get_tetro_row() - tetro.get_row() + 1, tetris -> get_tetro_column() + tetro.get_column() - 1);
    tetris -> Draw();
        
    cout << "\nI will slide to left twice..\n";
    tetris -> slide_left(tetro, tetris -> get_tetro_row() - tetro.get_row() + 1, tetris -> get_tetro_column());
    tetris -> slide_left(tetro, tetris -> get_tetro_row() - tetro.get_row() + 1, tetris -> get_tetro_column());
    tetris -> Draw();
        
    cout << "\nI will slide to bottom up to it hit the bottom..\n";
    while (tetris -> are_they_space_bottom(tetro, tetris -> get_tetro_row(), tetris -> get_tetro_column()) != 0)
        tetris -> slide_bottom(tetro, tetris -> get_tetro_row(), tetris -> get_tetro_column() + tetro.get_column() - 1);
    tetris -> Draw();
    
    cout << endl << "!!! Tetris_Board moved " << tetris -> numberOfMoves() << " times..." << endl;
    
    cout << endl << "I will wirte this in file1.txt..." << endl << endl << endl << endl;
    
    tetris -> writeToFile("driver1_file1.txt");
    
    cout << "I will control my last move using lastMove function now in here..." << endl;
    
    tetris -> lastMove();
    
    cout << endl << "And now I will add a new tetromino to my tetris_board..." << endl << endl;
    
    Tetromino tetro2;
    
    tetro2((Tetromino::NumberOfShape::T));
    cout << endl << "Your Tetrominos now :  T\n";
    
    
    
    cout << "I will print tetromino to screen with my \"print\" function...\n";
    tetro2.print();
    
    cout << "I will add tetromino to Tetris board...\n\n";
    (*tetris) += tetro2;
    
    
    cout << endl << "I will slide to right two times..." << endl << endl;

    tetris -> slide_right(tetro2, tetris -> get_tetro_row() - tetro2.get_row() + 1, tetris -> get_tetro_column() + tetro2.get_column() - 1);
    tetris -> slide_right(tetro2, tetris -> get_tetro_row() - tetro2.get_row() + 1, tetris -> get_tetro_column() + tetro2.get_column() - 1);
    tetris -> Draw();
    
    cout << "\nI will slide to bottom up to it hit the bottom..\n";
    while (tetris -> are_they_space_bottom(tetro2, tetris -> get_tetro_row(), tetris -> get_tetro_column()) != 0)
        tetris -> slide_bottom(tetro2, tetris -> get_tetro_row(), tetris -> get_tetro_column() + tetro2.get_column() - 1);
    tetris -> Draw();
    
    cout << "I will control my last move using lastMove function now in here..." << endl;
        
    tetris -> lastMove();
    
    cout << endl << "I will read from the file and I will make it my tetris_board then I will continue the game over this tetris_board...If I just wanted to read from the file, I could do it without using my equalVectors function..." << endl << endl;
    
    tetris -> readFromFile("driver1_file1.txt");
    
    cout << "This is board which I read from the file1.txt..."  << endl;
    tetris -> Draw_v1();
    
    cout << endl << "This is my normal game board"  << endl;
    tetris -> Draw();
    
    cout << endl << "And now I will make board which I read from the file1.txt my tetris_board then I will continue the game over this tetris_board..." << endl << endl;

    tetris -> equalBoards();
    
    cout << endl << "This is my normal game board anymore..."  << endl;
    tetris -> Draw();
    
    cout << endl << endl << "-----------------------------------------------" << endl << endl << endl << endl;
    
}



void TetrisForExceptionControl()
{
    int *coordinate;
    
    coordinate = new int[2];
    cout << "I will give size to Tetris 10x10\n\n";
    coordinate[0] = 10;
    coordinate[1] = 10;
    Tetris tetris(coordinate);
    tetris.Draw();
    
    cout << "I will call my lastMove function... Then it will throw an exception because I did not add any tetromino in tetris_board so there is not any move... If there was any move then it will return my MoveActions struct..." << endl << endl;
    
    tetris.lastMove();
    
    cout << "------------------------------------------------------------" << endl << endl << endl;
    
    delete [] coordinate;
    coordinate = nullptr;
    
}


Tetromino createTetromino()
{
    char    choice;
       
    Tetromino tetro;
    
    cout << "When the program stops in this driver, it means that it is asking you for input. The reason I get input from the user is that I want to test my driver under different conditions." << endl << endl;
    cout << "TETROMINO PART \n\n\n";
    
    do
    {
        cout << "What are the types of tetromino?  TYPES(L, J, T, I, O, S, Z)\n";
        cin >> choice;
        
        if (choice == 'I')
        {
            tetro((Tetromino::NumberOfShape::I));
            cout << endl << "Your Tetrominos :  I\n\n";
        }
        else if (choice == 'O')
        {
            tetro((Tetromino::NumberOfShape::O));
            cout << endl << "Your Tetrominos :  O\n\n";
        }
        else if (choice == 'T')
        {
            tetro((Tetromino::NumberOfShape::T));
            cout << endl << "Your Tetrominos :  T\n\n";
        }
        else if (choice == 'J')
        {
            tetro((Tetromino::NumberOfShape::J));
            cout << endl << "Your Tetrominos :  J\n\n";
        }
        else if (choice == 'L')
        {
            tetro((Tetromino::NumberOfShape::L));
            cout << endl << "Your Tetrominos :  L\n\n";
        }
        else if (choice == 'S')
        {
            tetro((Tetromino::NumberOfShape::S));
            cout << endl << "Your Tetrominos :  S\n\n";
        }
        else if(choice == 'Z')
        {
            tetro((Tetromino::NumberOfShape::Z));
            cout << endl << "Your Tetrominos :  Z\n\n";
        }
    } while ( ! (choice == 'I' || choice == 'O' || choice == 'T' || choice == 'J' || choice == 'L' || choice == 'S' || choice == 'Z'));
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
    
    return (tetro);
}
