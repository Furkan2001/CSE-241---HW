/**
 *
 *@author Ahmet Furkan Ekinci - 200104004063
 *
 */

import java.util.Scanner;

    /**
     *
     * This class is Tetris class.
     *
     */
    public class Tetromino
    {
        private char[][] shape;
        private NumberOfShape variableOfShape;
        private int numberOfColumn;
        private int numberOfRow;
        /**
         * Enumeration class representing the different shapes of Tetromino
         * @author Ahmet Furkan Ekinci
         */
        public enum NumberOfShape
        {
            /**
             * The I shape, represented by a vertical line of 4 blocks
             */
            I,
            /**
             * The O shape, represented by a 2x2 square of blocks
             */
            O,
            /**
             * The T shape, represented by a T-like shape of 3 blocks
             */
            T,
            /**
             * The J shape, represented by a L-like shape of 3 blocks
             */
            J,
            /**
             * The L shape, represented by a reversed L-like shape of 3 blocks
             */
            L,
            /**
             * The S shape, represented by a Z-like shape of 3 blocks
             */
            S,
            /**
             * The Z shape, represented by a reversed Z-like shape of 3 blocks
             */
            Z
        }


        
        /**
         * Default constructor for creating Tetromino objects without parameters.
         */
        public Tetromino(){/* I created this constructor in my main file first to be able to create the objects of this class without using the constructor parameters.*/}
        /**
         * Constructor for creating Tetromino objects with a specific shape.
         * @param choice is an NumberOfShape parameter, represents the shape of the Tetromino object.
         */
        public Tetromino(NumberOfShape choice)
        {
            variableOfShape = choice; // I assigned my enum variable to an integer variable. My purpose is that can use it in next lines...
            if (choice == NumberOfShape.I)  // I filled my arrays.
            {
                shape = new char[1][4];
                for (int i = 0; i < 4; i++)
                {
                    shape[0][i] = 'I';
                }
                numberOfRow = 1;
                numberOfColumn = 4;
            }
            else if (choice == NumberOfShape.O)
            {
                shape = new char[2][2];
                for (int i = 0; i < 2; i++)
                {
                    shape[i][0] = 'O';
                    shape[i][1] = 'O';
                }
                numberOfRow = 2;
                numberOfColumn = 2;
            }
            else if (choice == NumberOfShape.T)
            {
                shape = new char[2][3];
                for (int i = 0; i < 2; i++)
                {
                    shape[i][1] = 'T';
                }
                shape[0][0] = 'T';
                shape[0][2] = 'T';
                shape[1][0] = ' ';
                shape[1][2] = ' ';
                numberOfRow = 2;
                numberOfColumn = 3;
            }
            else if (choice == NumberOfShape.J)
            {
                shape = new char[3][2];
                for (int i = 0; i < 3; i++)
                {
                    shape[i][1] = 'J';
                }
                shape[0][0] = ' ';
                shape[1][0] = ' ';
                shape[2][0] = 'J';
                numberOfRow = 3;
                numberOfColumn = 2;
            }
            else if (choice == NumberOfShape.L)
            {
                shape = new char[3][2];
                for (int i = 0; i < 3; i++)
                {
                    shape[i][0] = 'L';
                }
                shape[0][1] = ' ';
                shape[1][1] = ' ';
                shape[2][1] = 'L';
                numberOfRow = 3;
                numberOfColumn = 2;
            }
            else if (choice == NumberOfShape.S)
            {
                shape = new char[2][3];
                for (int i = 0; i < 2; i++)
                {
                    shape[i][1] = 'S';
                }
                shape[0][0] = ' ';
                shape[0][2] = 'S';
                shape[1][0] = 'S';
                shape[1][2] = ' ';
                numberOfRow = 2;
                numberOfColumn = 3;
            }
            else if (choice == NumberOfShape.Z)
            {
                shape = new char[2][3];
                for (int i = 0; i < 2; i++)
                {
                    shape[i][1] = 'Z';
                }
                shape[0][0] = 'Z';
                shape[0][2] = ' ';
                shape[1][0] = ' ';
                shape[1][2] = 'Z';
                numberOfRow = 2;
                numberOfColumn = 3;
            }
        }
        /**
         *This method is getter for row.
         *
         *@return The value length of row for Tetromino object
         *
         */
        public int getRow()
        {
            return (numberOfRow);
        }
        /**
         *This method is getter for row.
         *
         *@return The value length of column for Tetromino object
         *
         */
        public int getColumn()
        {
            return (numberOfColumn);
        }
        /**
         *This is actually like my one parameter constructor because their aim is same but it is not constructor.
         *
         *@param choice NumberOfShape parameter used in the method..
         *
         */
        public void bracket(NumberOfShape choice) // parantez overloadının yerine kullanacağğım
        {
            variableOfShape = choice; // I assigned my enum variable to an integer variable. My purpose is that can use it in next lines...
            if (choice == NumberOfShape.I)  // I filled my arrays.
            {
                shape = new char[1][4];
                for (int i = 0; i < 4; i++)
                {
                    shape[0][i] = 'I';
                }
                numberOfRow = 1;
                numberOfColumn = 4;
            }
            else if (choice == NumberOfShape.O)
            {
                shape = new char[2][2];
                for (int i = 0; i < 2; i++)
                {
                    shape[i][0] = 'O';
                    shape[i][1] = 'O';
                }
                numberOfRow = 2;
                numberOfColumn = 2;
            }
            else if (choice == NumberOfShape.T)
            {
                shape = new char[2][3];
                for (int i = 0; i < 2; i++)
                {
                    shape[i][1] = 'T';
                }
                shape[0][0] = 'T';
                shape[0][2] = 'T';
                shape[1][0] = ' ';
                shape[1][2] = ' ';
                numberOfRow = 2;
                numberOfColumn = 3;
            }
            else if (choice == NumberOfShape.J)
            {
                shape = new char[3][2];
                for (int i = 0; i < 3; i++)
                {
                    shape[i][1] = 'J';
                }
                shape[0][0] = ' ';
                shape[1][0] = ' ';
                shape[2][0] = 'J';
                numberOfRow = 3;
                numberOfColumn = 2;
            }
            else if (choice == NumberOfShape.L)
            {
                shape = new char[3][2];
                for (int i = 0; i < 3; i++)
                {
                    shape[i][0] = 'L';
                }
                shape[0][1] = ' ';
                shape[1][1] = ' ';
                shape[2][1] = 'L';
                numberOfRow = 3;
                numberOfColumn = 2;
            }
            else if (choice == NumberOfShape.S)
            {
                shape = new char[2][3];
                for (int i = 0; i < 2; i++)
                {
                    shape[i][1] = 'S';
                }
                shape[0][0] = ' ';
                shape[0][2] = 'S';
                shape[1][0] = 'S';
                shape[1][2] = ' ';
                numberOfRow = 2;
                numberOfColumn = 3;
            }
            else if (choice == NumberOfShape.Z)
            {
                shape = new char[2][3];
                for (int i = 0; i < 2; i++)
                {
                    shape[i][1] = 'Z';
                }
                shape[0][0] = 'Z';
                shape[0][2] = ' ';
                shape[1][0] = ' ';
                shape[1][2] = 'Z';
                numberOfRow = 2;
                numberOfColumn = 3;
            }
        }
        /**
         *This method is getter for an index in shape variable of object.
         *
         *@param i is a integer parameter. It is about index...
         *@param j is a integer parameter. It is about index...
         *
         *@return The result of the task as a char value. It means a value in the address whisch we want.
         *
         */
        public char getValueOfIndex(int i, int j)
        {
            return (shape[i][j]);
        }
        /**
         *
         * This method for printing object of Tetromino.
         *
         */
        public void print()
        {
            for (int i = 0; i < numberOfRow; i++)  // number of rows
            {
                for (int j = 0; j < numberOfColumn; j++)  // number of colummns
                {
                    System.out.print(shape[i][j]);  //  I printed in here...
                }
                System.out.print("\n");
            }
            System.out.print("\n");
        }
        /**
         *This method to rotate shape variable of object.
         *
         *@param directionOfRotation is a char parameter in this method.
         *
         */
        public void rotate(char directionOfRotation)
        {
            char[][] temp;  // I created temporary array in here..
            int tempInt;
            
            temp = new char[numberOfColumn][numberOfRow];
            
            for (int i = 0; i < numberOfColumn; i++)   // By relocating the dimensions of my original vector, I defined the temporal vector as large enough to hold the return values. Shape's row -> temp's column, Shape's column -> temp's row
            {
                for(int j = 0; j < numberOfRow; j++)
                {
                    temp[i][j] = ' ';
                }
            }
            if (variableOfShape != NumberOfShape.O) // I never rotated 'O' because it will take the same shape when it is rotated.
            {
                if (directionOfRotation == 'r')  // 'r' means turn to the right side..
                {
                    if (variableOfShape == NumberOfShape.I)  // I sent the values ​​in the shape vector to the temp vector according to the coordinates that will occur when it returns...
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'I')
                                    temp[j][numberOfRow - 1 - i] = 'I';
                    }
                    else if (variableOfShape == NumberOfShape.T)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'T')
                                    temp[j][numberOfRow - 1 - i] = 'T';
                    }
                    else if (variableOfShape == NumberOfShape.J)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'J')
                                    temp[j][numberOfRow - 1 - i] = 'J';
                    }
                    else if (variableOfShape == NumberOfShape.L)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'L')
                                    temp[j][numberOfRow - 1 - i] = 'L';
                    }
                    else if (variableOfShape == NumberOfShape.S)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'S')
                                    temp[j][numberOfRow - 1 - i] = 'S';
                    }
                    else if (variableOfShape == NumberOfShape.Z)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'Z')
                                    temp[j][numberOfRow - 1 - i] = 'Z';
                    }
                    shape = new char[numberOfColumn][numberOfRow];
                    for (int i = 0; i < numberOfColumn; i++)
                        for (int j = 0; j < numberOfRow; j++)
                            shape[i][j] = temp[i][j];    // I equated the vector named temp that I created to the vector named shape..
                }
                else      //  means turn to the left side..
                {
                    if (variableOfShape == NumberOfShape.I)  // I sent the values ​​in the shape vector to the temp vector according to the coordinates that will occur when it returns...
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'I')
                                    temp[numberOfColumn - 1 - j][i] = 'I';
                    }
                    else if (variableOfShape == NumberOfShape.T)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'T')
                                    temp[numberOfColumn - 1 - j][i] = 'T';
                    }
                    else if (variableOfShape == NumberOfShape.J)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'J')
                                    temp[numberOfColumn - 1 - j][i] = 'J';
                    }
                    else if (variableOfShape == NumberOfShape.L)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'L')
                                    temp[numberOfColumn - 1 - j][i] = 'L';
                    }
                    else if (variableOfShape == NumberOfShape.S)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'S')
                                    temp[numberOfColumn - 1 - j][i] = 'S';
                    }
                    else if (variableOfShape == NumberOfShape.Z)
                    {
                        for (int i = 0; i < numberOfRow; i++)
                            for (int j = 0; j < numberOfColumn; j++)
                                if (shape[i][j] == 'Z')
                                    temp[numberOfColumn - 1 - j][i] = 'Z';
                    }
                    shape = new char[numberOfColumn][numberOfRow];
                    for (int i = 0; i < numberOfColumn; i++)
                        for (int j = 0; j < numberOfRow; j++)
                            shape[i][j] = temp[i][j];    // I equated the vector named temp that I created to the vector named shape..
                }
            }

            tempInt = numberOfRow;
            numberOfRow = numberOfColumn;         // Since the column and row numbers will change, I saved it again after returning it.
            numberOfColumn = tempInt;       // Since the column and row numbers will change, I saved it again after returning it.
        }
        /**
         *This method is getter for shape variable of object.
         *
         *@return This method return char[][]...
         *
         */
        public char[][] returnShape()
        {
            return (shape);
        }
    
    }

