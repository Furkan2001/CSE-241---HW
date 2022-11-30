#ifndef TETRIS
#define TETRIS

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <thread>
#include "tetromino.h"

using namespace std;
using namespace game;

namespace game2
{
    class Tetris
    {
    
    private:
        char **tetris_board;
        int row;
        int column;
        int space_row;
        int space_column;
        int tetro_row;
        int tetro_column;
        int coordinate0;
        int coordinate1;
        
    public:
        
        Tetris ();
        Tetris (int* coordinate);
        int get_tetro_column() const;
        int get_tetro_row() const;
        void my_first_main_function(int *coordinate);
        void my_second_main_function(Tetromino &tetromino);
        void my_third_main_function(Tetromino &tetromino);
        void Draw() const;
        void operator +=(Tetromino &tetromino);
        bool are_they_space_right(Tetromino &tetromino, int row, int column);
        void slide_right(Tetromino &tetromino, int row, int column);
        void slide_bottom(Tetromino &tetromino, int row, int column);
        bool are_they_space_bottom(Tetromino &tetromino, int row, int column);
        bool are_they_space_left(Tetromino &tetromino, int row, int column);
        void slide_left(Tetromino &tetromino, int row, int column);
        void real_animate();
        ~Tetris();
    };
}

using namespace game2;

#endif
