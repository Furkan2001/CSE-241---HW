#ifndef ABSTRACT
#define ABSTRACT

#include "tetromino.hpp"

namespace game5
{
    class abstractTetris
    {
    public:
        
        virtual ~abstractTetris() = default;
        
        virtual int get_tetro_column() const = 0;
        virtual int get_tetro_row() const = 0;
        virtual void my_first_main_function(int *coordinate) = 0;
        virtual void my_second_main_function(Tetromino &tetromino) = 0;
        virtual void my_third_main_function(Tetromino &tetromino) = 0;
        virtual void readFromFile(const string filename) = 0;
        virtual void writeToFile(const string filename) = 0;
        virtual void operator+=(Tetromino& tetromino) = 0;
        virtual bool are_they_space_right(Tetromino &tetromino, int row, int column) = 0;
        virtual void slide_right(Tetromino &tetromino, int row, int column) = 0;
        virtual void slide_bottom(Tetromino &tetromino, int row, int column) = 0;
        virtual bool are_they_space_bottom(Tetromino &tetromino, int row, int column) = 0;
        virtual bool are_they_space_left(Tetromino &tetromino, int row, int column) = 0;
        virtual void slide_left(Tetromino &tetromino, int row, int column) = 0;
        virtual void real_animate() = 0;
        virtual void equalBoards() = 0;
        virtual void Draw() const = 0;
        virtual void Draw_v1() const = 0;
        virtual MoveActions lastMove() const = 0;
        virtual int numberOfMoves() const = 0;
        
    };
}

using namespace game5;

#endif
