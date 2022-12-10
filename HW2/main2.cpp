#include "tetromino.h"
#include "tetris.h"

int main()
{
    
    Tetris copy_tetris;
    Tetromino *tetromino;
    int* coordinate_1;
    int i;
    
    i = 0;
    tetromino = new Tetromino[1000];
    coordinate_1 = copy_tetris.my_first_main_function();
    Tetris tetris(coordinate_1);
    tetris.Draw();
    while (1)
    {
        tetris.my_second_main_function(tetromino[i]);
        tetris.Animate(tetromino[i]);
        i++;
    }
    tetris.Draw();
    
    return 0;
}

