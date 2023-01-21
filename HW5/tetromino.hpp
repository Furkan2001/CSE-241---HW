#ifndef TETROMINO
#define TETROMINO

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <thread>

using namespace std;

namespace game
{
    struct MoveActions          //  I created this struct to hold my moves of tetrominos
    {
        char tetromin;         // I used this strust especially for lastMove function...
        int number_down;
        int number_right;
        int number_left;
    };


    class Tetromino
    {
    
     public :
    
        enum class NumberOfShape {I, O, T, J, L, S, Z};
        Tetromino();
        Tetromino(NumberOfShape choice);
        int get_row() const;
        int get_column() const;
        char get_hold_enum() const;
        void operator()(NumberOfShape choice);
        char get_value_of_index(int i, int j) const;
        void print() const;
        void rotate(char direction_of_rotation);
        vector < vector < char > > return_shape();
        ~Tetromino();
        
     private :
    
        vector < vector < char > > shape;
        char hold_enum;
        int VariableOfShape;
        int number_of_column;
        int number_of_row;
    
    };
}

using namespace game;

#endif

