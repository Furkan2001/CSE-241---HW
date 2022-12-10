#ifndef TETROMINO
#define TETROMINO

#include <iostream>
#include <vector>

using namespace std;

class Tetromino
{
    
    public :
    
        enum class NumberOfShape {I, O, T, J, L, S, Z};
        Tetromino();
        Tetromino(NumberOfShape choice);
        void print() const;
        void print_extra() const;
        void rotate(char direction_of_rotation);
        void JustForFirstObj();
        bool canFit(Tetromino previous);
        void CreateNewTetromino(Tetromino previous);
        bool DownerAndLefter() const;
        int ElementsOfLastRow() const;
        vector<vector<char>> return_shape();
    
    private :

        vector < vector < char > > shape;
        vector < vector < char > > copy_shape;
        char hold_enum;
        int VariableOfShape;
        int number_of_column;
        int number_of_row;
        
};

#endif
