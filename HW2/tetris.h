#ifndef TETRIS
#define TETRIS

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "tetromino.h"

using namespace std;

class Tetris
{
    
private:
    vector < vector < char > > tetris_board;
    vector < vector < char > > copy_tetris_board;
    int number_tetromino;
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
    int* my_first_main_function();
    void add(vector<vector<char>>);
    void my_second_main_function(Tetromino &tetromino);
    void Draw() const;
    bool find_space_and_fit(Tetromino &tetromino);
    bool are_they_space_up(Tetromino &tetromino, int row, int column);
    void slide_right(Tetromino &tetromino, int row, int column);
  //  bool are_they_space_right(Tetromino &tetromino, int row, int column);
    void slide_bottom(Tetromino &tetromino, int row, int column);
    bool are_they_space_bottom(Tetromino &tetromino, int row, int column);
    void slide_left(Tetromino &tetromino, int row, int column);
    void Animate(Tetromino &tetromino);
    void real_animate();
    
};

#endif


/*
std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                cout << "\x1b[0J";
                cout << "\x1b[H";
*/
