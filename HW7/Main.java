/**
 *
 *@author Ahmet Furkan Ekinci - 200104004063
 *
 */

import java.util.Scanner;
import java.util.Random;

/**
 *
 * This class is Main class. It is the starting point of the program
 *
 */
public class Main
{
    /**
     * Default constructor for creating Main objects without parameters.
     */
    public Main(){}
    /**
     *The main method of the program.
     *
     *@param args is a String[] parameter.
     *
     */
    public static void main(String[] args)
    {
        char    choice;
        int value;
        
        Tetromino tetro = new Tetromino();
        System.out.println("I will choose random tetromino now...");
        
        value = (int)(Math.random() * 6);
        if (value == 0)
            choice = 'I';
        else if(value == 1)
            choice = 'O';
        else if(value == 2)
            choice = 'T';
        else if(value == 3)
            choice = 'J';
        else if(value == 4)
            choice = 'L';
        else if(value == 5)
            choice = 'S';
        else
            choice = 'Z';
        
        System.out.println(choice + "\n\n");
        
        if (choice == 'I')
            tetro.bracket(Tetromino.NumberOfShape.I);
        else if (choice == 'O')
            tetro.bracket(Tetromino.NumberOfShape.O);
        else if (choice == 'T')
            tetro.bracket(Tetromino.NumberOfShape.T);
        else if (choice == 'J')
            tetro.bracket(Tetromino.NumberOfShape.J);
        else if (choice == 'L')
            tetro.bracket(Tetromino.NumberOfShape.L);
        else if (choice == 'S')
            tetro.bracket(Tetromino.NumberOfShape.S);
        else
            tetro.bracket(Tetromino.NumberOfShape.Z);
            
        System.out.print("I will print tetromino to screen with my \"print\" function...\n");
        tetro.print();
        
        System.out.print("I will control length of row of this tetromino : ");
        System.out.print(tetro.getRow() + "\n");
        System.out.print("I will control length of column of this tetromino : ");
        System.out.print(tetro.getColumn() + "\n\n\n");
        
        
        
        System.out.print("I will look the index I want of tetromino with my get_value_of_index function...\n");
        System.out.print("[0][0] : " + tetro.getValueOfIndex(0, 0) + "\n");
        System.out.print("[0][1] : " + tetro.getValueOfIndex(0, 1) + "\n");
        System.out.print("\n-------------------------------------\n\n");
        
        System.out.print("I will rotate first once left and then two right and i will print to screen...\n");
        tetro.rotate('l');
        System.out.print("\nThis turn is left\n");
        tetro.print();
        tetro.rotate('r');
        tetro.rotate('r');
        System.out.print("\nThis turn is right for two times\n");
        tetro.print();
        
        System.out.print("\nTETRIS PART \n\n\n");
        
        int[] coordinate;
        
        coordinate = new int[2];
        System.out.print("I will give size to Tetris 10x10\n\n");
        coordinate[0] = 10;
        coordinate[1] = 10;
        Tetris tetris = new Tetris(coordinate);
        tetris.Draw();
        
        System.out.print("I will add tetromino to Tetris board...\n\n");
        tetris.add(tetro);
        
        System.out.print("\nI will slide to right once..\n");
        tetris.slideRight(tetro, tetris.getTetroRow() - tetro.getRow() + 1, tetris.getTetroColumn() + tetro.getColumn() - 1);
        tetris.Draw();
        
        System.out.print("\nI will slide to left twice..\n");
        tetris.slideLeft(tetro, tetris.getTetroRow() - tetro.getRow() + 1, tetris.getTetroColumn());
        tetris.slideLeft(tetro, tetris.getTetroRow() - tetro.getRow() + 1, tetris.getTetroColumn());
        tetris.Draw();
        
        System.out.print("\nI will slide to bottom twice..\n");
        tetris.slideBottom(tetro, tetris.getTetroRow(), tetris.getTetroColumn() + tetro.getColumn() - 1);
        tetris.slideBottom(tetro, tetris.getTetroRow(), tetris.getTetroColumn() + tetro.getColumn() - 1);
        tetris.Draw();
                         
        System.out.print("\n\nDriver2 is starting...\n\n");
    }
}
