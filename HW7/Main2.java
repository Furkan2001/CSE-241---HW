/**
 *
 *@author Ahmet Furkan Ekinci - 200104004063
 *
 */

import java.util.Scanner;

/**
 *
 * This class is Main class. It is the starting point of the program
 *
 */
public class Main2
{
    /**
     * Default constructor for creating Main2 objects without parameters.
     */
    public Main2(){}
    
    /**
     *The main method of the program. It creates a Tetris object and calls its methods to run the game.
     *
     *@param args is a String[] parameter.
     *
     */
    public static void main(String[] args)
    {
        Tetris copyTetris = new Tetris();
        int[] coordinate;
        Tetromino tetromino = new Tetromino();

        coordinate = new int[2];

        copyTetris.my_first_main_function(coordinate);
        
        Tetris tetris = new Tetris(coordinate);

        tetris.Draw();
        
        while (true)
        {
            tetris.my_second_main_function(tetromino);
            tetris.my_third_main_function(tetromino);
            tetris.Draw();
        }
    }
}

