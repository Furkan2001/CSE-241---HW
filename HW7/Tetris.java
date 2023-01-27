/**
 *
 *@author Ahmet Furkan Ekinci - 200104004063
 *
 */

import java.util.Scanner;
import java.util.Random;
    
    /**
     *
     * This class is Tetris class.
     *
     */
    public class Tetris
    {
        private char[][] tetrisBoard;
        private int row;
        private int column;
        private int tetroRow;
        private int tetroColumn;
        private int coordinate0;
        private int coordinate1;
        
        /**
         * Default constructor for creating Tetris objects without parameters.
         */
        public Tetris (){}
        /**
         *This is a one parameter constructor
         *
         *@param coordinate is a int[] parameter.
         *
         */
        public Tetris (int[] coordinate)
        {
            coordinate[0] += 2;
            coordinate[1] += 2;
            
            tetrisBoard = new char[coordinate[0]][coordinate[1]];
            
            for (int i = 0; i < coordinate[0]; i++)
            {
                for (int j = 0; j < coordinate[1]; j++)
                {
                    if (i == 0 || i == coordinate[0] - 1 || j == 0 || j == coordinate[1] - 1)
                        tetrisBoard[i][j] = 'x';
                    else
                        tetrisBoard[i][j] = ' ';
                }
            }
            coordinate0 = coordinate[0] - 2;
            coordinate1 = coordinate[1] - 2;
        }
        /**
         *This is getter for column.
         *
         *@return Return value is an integer.The value means that length of column of tetromino in tetrisBoard.
         *
         */
        public int getTetroColumn()
        {
            return (tetroColumn);
        }
        /**
         *This is getter for row.
         *
         *@return Return value is an integer.The value means that length of row of tetromino in tetrisBoard.
         *
         */
        public int getTetroRow()
        {
            return (tetroRow);
        }
        /**
         *This function for main method..
         *
         *@param coordinate is int[]parameter for this method.It holds sizes of tetrisBoard.
         *
         */
        public void my_first_main_function(int[] coordinate)
        {
            Scanner input = new Scanner(System.in);
            while (true)  // I wrote this loop to check value that user entered...
            {
                System.out.print("Enter the row: ");
                while (!input.hasNextInt())
                {
                           System.out.println("Please enter a valid value!!!");
                           input.next();
                }
                int row = input.nextInt();
                if (row > 0)
                {
                    coordinate[0] = row;
                    break;
                }
                else
                {
                    System.out.println("Please enter a valid value!");
                }
            }
            while (true)
            {
                System.out.print("Enter the column:");
                while (!input.hasNextInt())
                {
                           System.out.println("Please enter a valid value!!!");
                           input.next();
                }
                int column = input.nextInt();
                if (column > 0)
                {
                    coordinate[1] = column;
                    break;
                }
                else
                {
                    System.out.println("Please enter a valid value!");
                }
            }
            coordinate0 = coordinate[0];
            coordinate1 = coordinate[1];
        }
        /**
         *This function for main method..
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *
         */
        public void my_second_main_function(Tetromino tetromino)
        {
            char choice;
            int value;
            
            value = -1;
            Scanner input = new Scanner(System.in);
            System.out.println("Which type you want? If you do not have any idea about which tetromino you want, you shold write 'R' ; If you want to quit, you must write 'Q' ...");
            while (true)
            {
                choice = input.next().charAt(0);
                if (choice == 'Q')
                {
                    System.out.println("Program terminated...");
                    System.exit(0);
                }
                else if (choice == 'R')
                {
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
                }
                if (choice == 'I' || choice == 'O' || choice == 'T' || choice == 'J' || choice == 'L' || choice == 'S' || choice == 'Z')
                {
                    /* I used my bracket method in here...*/
                    if (choice == 'I')
                        tetromino.bracket(Tetromino.NumberOfShape.I);
                    else if (choice == 'O')
                        tetromino.bracket(Tetromino.NumberOfShape.O);
                    else if (choice == 'T')
                        tetromino.bracket(Tetromino.NumberOfShape.T);
                    else if (choice == 'J')
                        tetromino.bracket(Tetromino.NumberOfShape.J);
                    else if (choice == 'L')
                        tetromino.bracket(Tetromino.NumberOfShape.L);
                    else if (choice == 'S')
                        tetromino.bracket(Tetromino.NumberOfShape.S);
                    else
                        tetromino.bracket(Tetromino.NumberOfShape.Z);
                    break;
                }
                else
                    System.out.println("Try AGAIN. Your entry is invalid..!");
            }
            
            /* I wrote this lines to control whether size is sufficient...*/
            if (tetromino.getRow() > coordinate0 || tetromino.getColumn() > coordinate1)
            {
                System.out.println("\nYou entered size of row and column does not include the size of this tetromino..");
                System.exit(1);
            }
            System.out.println("Tetromino you choised is ");
            tetromino.print();
        }
        /**
         *This function for main method..
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *
         */
        public void my_third_main_function(Tetromino tetromino)
        {
            char rotation_direction;
            int rotation_count;
            char move_direction;
            int move_count;
            
            rotation_count = (int)(Math.random() * 2);
            
            if (rotation_count == 0)
                rotation_direction = 'r';
            else
                rotation_direction = 'l';
            
            rotation_count = (int)(Math.random() * 8);
            
            for (int i = 0; i < rotation_count; i++)
                tetromino.rotate(rotation_direction);
            System.out.println("-------------------------------------------");
            add(tetromino);
            
            rotation_count = (int)(Math.random() * 2);
            
            if (rotation_count == 0)
                move_direction = 'r';
            else
                move_direction = 'l';
            
            move_count = (int) (Math.random() * ((coordinate1 / 2) - (tetroColumn / 2) + 1));
            
            if(move_direction == 'r')
            {
                for (int i = 0; i < move_count; i++)
                {
                    if (!areTheySpaceRight(tetromino, tetroRow - tetromino.getRow() + 1, tetroColumn + tetromino.getColumn() - 1))
                    {
                        System.out.println("OUT of the game line  or  CRASH of tetrominos...");
                        System.out.println("Game is over...");
                        System.exit(-1);
                    }
                    /* parameters of slide right function are a tetromino object and indexes of highest right side of shape of this tetromino object*/
                    this.slideRight(tetromino, tetroRow - tetromino.getRow() + 1, tetroColumn + tetromino.getColumn() - 1);
                    realAnimate();
                }
                while (areTheySpaceBottom(tetromino, tetroRow, tetroColumn))
                {
                    /* parameters of slide bottom function are a tetromino object and indexes of bottomest right side of shape of this tetromino object*/
                    if (areTheyOk(tetromino, tetroRow, tetroColumn))
                    {
                        slideBottom(tetromino, tetroRow, tetroColumn + tetromino.getColumn() - 1);
                        realAnimate();
                    }
                    else
                    {
                        break;
                    }
                }
            }

            else
            {
                for (int i = 0; i < move_count; i++)
                {
                    if (!(areTheySpaceLeft(tetromino, tetroRow - tetromino.getRow() + 1, tetroColumn)))
                    {
                        System.out.println("OUT of the game line or CRASH of tetrominos...");
                        System.out.println("Game is over...");
                        System.exit(0);
                    }
                    /* parameters of slide left function are a tetromino object and indexes of highest left side of shape of this tetromino object*/
                    this.slideLeft(tetromino, tetroRow - tetromino.getRow() + 1, tetroColumn);
                    realAnimate();
                }
                while (areTheySpaceBottom(tetromino, tetroRow, tetroColumn))
                {
                    /* parameters of slide bottom function are a tetromino object and indexes of bottomest right side of shape of this tetromino object*/
                    if (areTheyOk(tetromino, tetroRow, tetroColumn))
                    {
                        slideBottom(tetromino, tetroRow, tetroColumn + tetromino.getColumn() - 1);
                        realAnimate();
                    }
                    else
                        break;
                }
            }
        }
        /**
         *
         *This method for the print to screen tetrisBoard variable.
         *
         */
        public void Draw()
        {
            for (int i = 0; i < coordinate0 + 2; i++)
            {
                for (int j = 0; j < coordinate1 + 2; j++)
                    System.out.print(tetrisBoard[i][j]);
                System.out.print("\n");
            }
        }
        /**
         *This method add a tetromino inside to tetrisBoard.
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *
         */
        public void add(Tetromino tetromino)
        {
            int location;

            location = ((coordinate1) / 2) - ((tetromino.getColumn()) / 2); // Location holds the value of middle of tetris...
            for (int i = 0; i < (tetromino.getRow()); i++)
            {
                for (int j = 0; j < (tetromino.getColumn()); j++)
                {
                    if ( tetrisBoard[i + 1][location + j + 1] != ' ')
                    {
                        System.out.println("OUT of the game line  or  CRASH of tetrominos...");
                        System.out.println("Game is over...");
                        System.exit(0);
                    }
                    tetrisBoard[i + 1][location + j + 1] = tetromino.getValueOfIndex(i, j);  // I added tetromino to tetris board in here...
                    if (i == tetromino.getRow() - 1 && j == 0)
                    {
                        tetroRow = i + 1;
                        tetroColumn = location + j + 1;
                    }
                }
            }
            Draw();
        }
        /**
         *This is control method layout.
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *@param row is a int parameter.
         *@param column is a int parameter.
         *
         *@return The result of the task as a boolean value.
         *
         */
        public boolean areTheyOk(Tetromino tetromino, int row, int column)
        {
            int counter;
            
            counter = 0;
            for (int i = 0; i < tetromino.getRow(); i++)
            {
                for (int j = 0; j < tetromino.getColumn(); j++)
                {
                    if (tetrisBoard[row - i][column + j] != ' ')
                        counter++;
                }
            }
            if (counter == 4)
                return (true);
            else
                return (false);
        }
        /**
         *This method controls is the right side of the tetromino blank.If there is blank then return true otherwise return false.
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *@param row is a int parameter.
         *@param column is a int parameter.
         *
         *@return The result of the task as a boolean value.
         *
         */
        public boolean areTheySpaceRight(Tetromino tetromino, int row, int column)
        {
            for (int i = 0; i < tetromino.getRow(); i++)
                if (tetrisBoard[row + i][column + 1] != ' ' && tetrisBoard[row + i][column] != ' ')
                    return (false);
            return (true);
        }
        /**
         *This method slide tetromino to right side
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *@param row is a int parameter.
         *@param column is a int parameter.
         *
         */
        public void slideRight(Tetromino tetromino, int row, int column)
        {
            for (int i = column; column - i < tetromino.getColumn(); i--)
            {
                for (int j = row; j - row < tetromino.getRow(); j++)
                {
                    if ( ! (tetrisBoard[j][i] == ' ' && tetrisBoard[j][i + 1] != ' '))
                    {
                        tetrisBoard[j][i + 1] = tetrisBoard[j][i];
                        tetrisBoard[j][i] = ' ';
                    }
                }
            }
            tetroColumn++;
        }
        /**
         *This method slide tetromino to down.
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *@param row is a int parameter.
         *@param column is a int parameter.
         *
         */
        public void slideBottom(Tetromino tetromino, int row, int column)
        {
            for (int i = row; row - i < tetromino.getRow(); i--)
            {
                for (int j = column; column - j < tetromino.getColumn(); j--)
                {
                    if ( ! (tetrisBoard[i][j] == ' ' && tetrisBoard[i + 1][j] != ' '))
                    {
                        tetrisBoard[i + 1][j] = tetrisBoard[i][j];
                        tetrisBoard[i][j] = ' ';
                    }
                }
            }
            tetroRow++;
        }
        /**
         *This method controls is the down of the tetromino blank.If there is blank then return true otherwise return false.
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *@param row is a int parameter.
         *@param column is a int parameter.
         *
         *@return The result of the task as a boolean value.
         *
         */
        public boolean areTheySpaceBottom(Tetromino tetromino, int row, int column)
        {
            int i = 0;
            
            while (i < tetromino.getColumn())
            {
                if (tetrisBoard[row + 1][column + i] != ' ' && tetrisBoard[row][column + i] != ' ')
                    return (false);
                i++;
            }
            return (true);
        }
        /**
         *This method controls is the left side of the tetromino blank.If there is blank then return true otherwise return false.
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *@param row is a int parameter.
         *@param column is a int parameter.
         *
         *@return The result of the task as a boolean value.
         *
         */
        public boolean areTheySpaceLeft(Tetromino tetromino, int row, int column)
        {
            for (int i = 0; i < tetromino.getRow(); i++)
                if (tetrisBoard[row + i][column - 1] != ' ' && tetrisBoard[row + i][column] != ' ')
                    return (false);
            return (true);
        }
        /**
         *This method slide tetromino to left side
         *
         *@param tetromino is a object of Tetromino as a paramete for this method.
         *@param row is a int parameter.
         *@param column is a int parameter.
         *
         */
        public void slideLeft(Tetromino tetromino, int row, int column)
        {
            for (int i = column; i - column < tetromino.getColumn(); i++)
            {
                for (int j = row; j - row < tetromino.getRow(); j++)
                {
                    if ( ! (tetrisBoard[j][i] == ' ' && tetrisBoard[j][i - 1] != ' '))
                    {
                        tetrisBoard[j][i - 1] = tetrisBoard[j][i];
                        tetrisBoard[j][i] = ' ';
                    }
                }
            }
            tetroColumn--;
        }
        /**
         *
         *This method is made for animation.
         *
         */
        public void realAnimate()
        {
            Draw();
            try
            {
                Thread.sleep(50); // Sleeps 100 milliseconds
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            System.out.print("\033[H\033[2J");   // Erases entire screen
            System.out.flush(); // flush the output buffer
        }
    }
