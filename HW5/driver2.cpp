#include "tetromino.hpp"
#include "vector.hpp"
#include "array.hpp"
#include "adapter.hpp"
#include "adapter.cpp"


int main()
{
    char choice;  // Choose which board type to play
    int select;   // I created it to set file operations...
    int flag;   // I used it to check the file functions...
    
    flag = 0;
    do
    {
        cout << "Which type of Tetris Class do you want?   Enter V(for Vector) or 1(for 1D Array) or A(for Adapter)\n";
        cin >> choice;
      
    } while ( ! (choice == 'V' || choice == '1' || choice == 'A'));
    
    switch(choice)
    {
            
        case 'V':
        {
            cout << endl << "You choised VECTOR CLASS.. HAPPY Games" << endl << endl;
            Tetris copy_tetris;
            Tetromino *tetromino;
            int* coordinate;
            int i;
            
            coordinate = new int[2];
            i = 0;
            copy_tetris.my_first_main_function(coordinate);
            Tetris tetris(coordinate);
            while(1)
            {
                tetris.Draw();
                tetromino = new Tetromino[1];
                tetris.my_second_main_function(tetromino[0]);
                tetris.my_third_main_function(tetromino[0]);
                tetris.Draw();
                cout << endl << "!!! Tetris_Board moved(with rotate) " << tetris.numberOfMoves() << " times..." << endl << endl << endl;
                
                while (1)
                {
                    cout << "If you saved this to a .txt file you can enter 1.." << endl << "If you read a board from .txt file then you can enter 2.." << endl << "If you do not want to do one of them then enter another number you want..." << endl;
                    if (cin >> select)
                        break;
                    else
                    {
                        cout << "Please enter valid value!\n\n" << endl;
                        cin.clear();
                        cin.ignore(94, '\n');
                    }
                }
                
                if (select == 1)
                {
                    cout << "You saved this board in file_read_write.txt" << endl;
                    tetris.writeToFile("file_read_write.txt");
                    flag++;
                    tetris.lastMove();
                }
                else if(select == 2)
                {
                    if (flag > 0)
                    {
                        tetris.readFromFile("file_read_write.txt");
                        cout << "This is tetris_board which you read from file.." << endl;
                        tetris.Draw_v1();
                        while (1)
                        {
                            cout << "If you want to make this your new tetris board please enter 3 otherwise enter 4 or another number..." << endl;
                            if (cin >> select)
                                break;
                            else
                            {
                                cout << "Please enter valid value!\n\n" << endl;
                                cin.clear();
                                cin.ignore(94, '\n');
                            }
                        }
                        
                        if (select == 3)
                        {
                            cout << endl << "This is your new board anymore... HAPPY GAMES" << endl;
                            tetris.equalBoards();
                        }
                        else
                        {
                            cout << "You did not want to make this your new tetris board...Game will continue same board.. HAPPY GAMES" << endl << endl;
                            tetris.lastMove();
                        }
                    }
                    else
                    {
                        cout << "You did not save any board yet so you can not read any board in .txt file" << endl;
                        tetris.lastMove();
                    }
                }
                else
                    tetris.lastMove();
                
                delete [] tetromino;
            }
            delete [] coordinate;
            
            break;
        }
        case '1':
        {
            cout << endl << "You choised 1D ARRAY CLASS.. HAPPY Games" << endl << endl;
            Tetris2 copy_tetris;
            Tetromino *tetromino;
            int* coordinate;
            int i;
            
            coordinate = new int[2];
            i = 0;
            copy_tetris.my_first_main_function(coordinate);
            Tetris2 tetris(coordinate);
            while(1)
            {
                tetris.Draw();
                tetromino = new Tetromino[1];
                tetris.my_second_main_function(tetromino[0]);
                tetris.my_third_main_function(tetromino[0]);
                tetris.Draw();
                cout << endl << "!!! Tetris_Board moved(with rotate) " << tetris.numberOfMoves() << " times..." << endl << endl << endl;
                
                while (1)
                {
                    cout << "If you saved this to a .txt file you can enter 1.." << endl << "If you read a board from .txt file then you can enter 2.." << endl << "If you do not want to do one of them then enter another number you want..." << endl;
                    if (cin >> select)
                        break;
                    else
                    {
                        cout << "Please enter valid value!\n\n" << endl;
                        cin.clear();
                        cin.ignore(94, '\n');
                    }
                }
                if (select == 1)
                {
                    cout << "You saved this board in file_read_write.txt" << endl;
                    tetris.writeToFile("file_read_write.txt");
                    flag++;
                    tetris.lastMove();
                }
                else if(select == 2)
                {
                    if (flag > 0)
                    {
                        tetris.readFromFile("file_read_write.txt");
                        cout << "This is tetris_board which you read from file.." << endl;
                        tetris.Draw_v1();
            
                        while (1)
                        {
                            cout << "If you want to make this your new tetris board please enter 3 otherwise enter 4 or another number..." << endl;
                            if (cin >> select)
                                break;
                            else
                            {
                                cout << "Please enter valid value!\n\n" << endl;
                                cin.clear();
                                cin.ignore(94, '\n');
                            }
                        }
                        if (select == 3)
                        {
                            cout << endl << "This is your new board anymore... HAPPY GAMES" << endl;
                            tetris.equalBoards();
                        }
                        else
                        {
                            cout << "You did not want to make this your new tetris board...Game will continue same board.. HAPPY GAMES" << endl << endl;
                            tetris.lastMove();
                        }
                    }
                    else
                    {
                        cout << "You did not save any board yet so you can not read any board in .txt file" << endl;
                        tetris.lastMove();
                    }
                }
                else
                    tetris.lastMove();
                
                delete [] tetromino;
            }
            delete [] coordinate;
            
            
            break;
        }
            
        case 'A':
        {
            cout << endl << "You choised ADAPTER CLASS.. HAPPY Games" << endl << endl;
            char choice;
            Tetris copy_tetris;
            Tetromino *tetromino;
            int* coordinate;
            int i;
            
            coordinate = new int[2];
            i = 0;
            copy_tetris.my_first_main_function(coordinate);
            do
            {
                cout << endl << "IF you want to use VECTOR class then enter (V), If you want to use DEQUE class then you enter (D)..." << endl;
                cin >> choice;
                if (choice == 'V')
                {
                    cout << "You choised VECTOR CLASS in ADAPTER CLASS..." << endl << endl;
                    Tetris3<vector<char>> tetris(coordinate);
                    while(1)
                    {
                        tetris.Draw();
                        tetromino = new Tetromino[1];
                        tetris.my_second_main_function(tetromino[0]);
                        tetris.my_third_main_function(tetromino[0]);
                        tetris.Draw();
                        cout << endl << "!!! Tetris_Board moved(with rotate) " << tetris.numberOfMoves() << " times..." << endl << endl << endl;
                        
                        while (1)
                        {
                            cout << "If you saved this to a .txt file you can enter 1.." << endl << "If you read a board from .txt file then you can enter 2.." << endl << "If you do not want to do one of them then enter another number you want..." << endl;
                            if (cin >> select)
                                break;
                            else
                            {
                                cout << "Please enter valid value!\n\n" << endl;
                                cin.clear();
                                cin.ignore(94, '\n');
                            }
                        }
                        if (select == 1)
                        {
                            cout << "You saved this board in file_read_write.txt" << endl;
                            tetris.writeToFile("file_read_write.txt");
                            flag++;
                            tetris.lastMove();
                        }
                        else if(select == 2)
                        {
                            if (flag > 0)
                            {
                                tetris.readFromFile("file_read_write.txt");
                                cout << "This is tetris_board which you read from file.." << endl;
                                tetris.Draw_v1();
                            
                                while (1)
                                {
                                    cout << "If you want to make this your new tetris board please enter 3 otherwise enter 4 or another number..." << endl;
                                    if (cin >> select)
                                        break;
                                    else
                                    {
                                        cout << "Please enter valid value!\n\n" << endl;
                                        cin.clear();
                                        cin.ignore(94, '\n');
                                    }
                                }
                                if (select == 3)
                                {
                                    cout << endl << "This is your new board anymore... HAPPY GAMES" << endl;
                                    tetris.equalBoards();
                                }
                                else
                                {
                                    cout << "You did not want to make this your new tetris board...Game will continue same board.. HAPPY GAMES" << endl << endl;
                                    tetris.lastMove();
                                }
                            }
                            else
                            {
                                cout << "You did not save any board yet so you can not read any board in .txt file" << endl;
                                tetris.lastMove();
                            }
                        }
                        else
                            tetris.lastMove();
                        
                        delete [] tetromino;
                    }
                }
                else if(choice == 'D')
                {
                    cout << "You choised DEQUE CLASS in ADAPTER CLASS..." << endl << endl;
                    Tetris3<deque<char>> tetris(coordinate);
                    while(1)
                    {
                        tetris.Draw();
                        tetromino = new Tetromino[1];
                        tetris.my_second_main_function(tetromino[0]);
                        tetris.my_third_main_function(tetromino[0]);
                        tetris.Draw();
                        cout << endl << "!!! Tetris_Board moved(with rotate) " << tetris.numberOfMoves() << " times..." << endl << endl << endl;
                        
                        while (1)
                        {
                            cout << "If you saved this to a .txt file you can enter 1.." << endl << "If you read a board from .txt file then you can enter 2.." << endl << "If you do not want to do one of them then enter another number you want..." << endl;
                            if (cin >> select)
                                break;
                            else
                            {
                                cout << "Please enter valid value!\n\n" << endl;
                                cin.clear();
                                cin.ignore(94, '\n');
                            }
                        }
                        if (select == 1)
                        {
                            cout << "You saved this board in file_read_write.txt" << endl;
                            tetris.writeToFile("file_read_write.txt");
                            flag++;
                            tetris.lastMove();
                        }
                        else if(select == 2)
                        {
                            if (flag > 0)
                            {
                                tetris.readFromFile("file_read_write.txt");
                                cout << "This is tetris_board which you read from file.." << endl;
                                tetris.Draw_v1();
                
                                while (1)
                                {
                                    cout << "If you want to make this your new tetris board please enter 3 otherwise enter 4 or another number..." << endl;
                                    if (cin >> select)
                                        break;
                                    else
                                    {
                                        cout << "Please enter valid value!\n\n" << endl;
                                        cin.clear();
                                        cin.ignore(94, '\n');
                                    }
                                }
                                if (select == 3)
                                {
                                    cout << endl << "This is your new board anymore... HAPPY GAMES" << endl;
                                    tetris.equalBoards();
                                }
                                else
                                {
                                    cout << "You did not want to make this your new tetris board...Game will continue same board.. HAPPY GAMES" << endl << endl;
                                    tetris.lastMove();
                                }
                            }
                            else
                            {
                                cout << "You did not save any board yet so you can not read any board in .txt file" << endl;
                                tetris.lastMove();
                            }
                        }
                        else
                            tetris.lastMove();
                        
                        delete [] tetromino;
                    }
                }
                else
                    cout << "You entered invalid value... Please try again..." << endl << endl;
            } while(choice != 'V' && choice != 'D');
            delete [] coordinate;
            
            break;
        }
    }
    return 0;
}
