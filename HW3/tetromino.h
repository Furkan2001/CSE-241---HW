#ifndef TETROMINO
#define TETROMINO

#include <iostream>
#include <vector>

using namespace std;

namespace game
{
    class Tetromino
    {
    
     public :
    
        enum class NumberOfShape {I, O, T, J, L, S, Z};
        Tetromino();
        Tetromino(NumberOfShape choice);
        int get_row();
        int get_column();
        void operator()(NumberOfShape choice);
        char get_value_of_index(int i, int j);
        void print() const;
        void rotate(char direction_of_rotation);
        char **return_shape();
        ~Tetromino();
        
     private :
    
        char **shape;
        char hold_enum;
        int VariableOfShape;
        int number_of_column;
        int number_of_row;
    
    };
}

#endif
