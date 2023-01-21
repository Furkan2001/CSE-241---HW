#ifndef ARRAY
#define ARRAY

#include "tetromino.hpp"
#include "abstractTetris.hpp"


namespace game3
{
    class Tetris2 : public abstractTetris
    {
    
    private:
        char *tetris_board;  // This is my real tetris board for game...
        vector<vector<char>> v1; // This vector is just a vector that I use as a temp while reading from the file...
        int number_of_moves;   // I used this variable to hold moves of tetris_board..
        MoveActions move_info;  // I used this variable to lastMove function..
        int flag;  // This variable help me to exception thing...
        int tetro_row;   //   Number of row of tetromino which is added in tetris_board
        int tetro_column;   //   Number of column of tetromino which is added in tetris_board
        int coordinate0;    // row length of tetris board except x
        int coordinate1;   // column length of tetris board except x
        
    public:
        
        Tetris2 ();
        Tetris2 (int* coordinate);
        int get_tetro_column() const;
        int get_tetro_row() const;
        int numberOfMoves() const;
        void my_first_main_function(int *coordinate);
        void my_second_main_function(Tetromino &tetromino);
        void my_third_main_function(Tetromino &tetromino);
        void Draw() const;
        void Draw_v1() const;
        void operator +=(Tetromino &tetromino);
        bool are_they_space_right(Tetromino &tetromino, int row, int column);
        void slide_right(Tetromino &tetromino, int row, int column);
        void slide_bottom(Tetromino &tetromino, int row, int column);
        bool are_they_space_bottom(Tetromino &tetromino, int row, int column);
        bool are_they_space_left(Tetromino &tetromino, int row, int column);
        void slide_left(Tetromino &tetromino, int row, int column);
        void real_animate();
        MoveActions lastMove() const;
        void equalBoards();
        void readFromFile(const string file);
        void writeToFile(const string file);
        ~Tetris2();
    };
}

using namespace game3;

#endif
