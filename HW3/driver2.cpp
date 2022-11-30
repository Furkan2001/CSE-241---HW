#include "tetromino.h"
#include "tetris.h"


int main()
{
    Tetris copy_tetris;
    Tetromino *tetromino;
    int* coordinate;
    int i;
    
    coordinate = new int[2];
    i = 0;
    
    copy_tetris.my_first_main_function(coordinate);
    
    Tetris tetris(coordinate);
    
    tetris.Draw();
    
    while(1)
    {
        tetromino = new Tetromino[1];
        tetris.my_second_main_function(tetromino[0]);
        tetris.my_third_main_function(tetromino[0]);
        tetris.Draw();
    
        delete [] tetromino;
    }
    delete [] coordinate;
    
    return 0;
}
