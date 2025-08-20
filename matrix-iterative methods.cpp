#include <iostream>
#include <cmath>

const int WIDTH = 3;
const int HEIGHT = 3;

double compute_determinant(double squareMatrix[WIDTH][HEIGHT]);
//Precondition: The matrix must be a square matrix i.e. WIDTH = HEIGHT where 2 <= HEIGHT, WIDTH <= 3
//AND populated with rational numbers.
//Postcondition: The function returns the determinant of the matrix

int main()
{
    double squareMatrix[WIDTH][HEIGHT] = {{1.567,2.56,3.69},{3.11,4.34,5.31},{5.90,6.34,1.112}};

    std::cout << compute_determinant(squareMatrix);

    return 0;
}

double compute_determinant(double squareMatrix[WIDTH][HEIGHT])
{
    double determinant;

    if ((WIDTH == 2) && (HEIGHT == 2)) {
        determinant = (squareMatrix[0][0]*squareMatrix[1][1]) - (squareMatrix[0][1]*squareMatrix[1][0]);
    }

    if ((WIDTH == 3) && (HEIGHT == 3)) {
        determinant =
            squareMatrix[0][0] * (squareMatrix[1][1] * squareMatrix[2][2] -
                                  squareMatrix[1][2] * squareMatrix[2][1])
          - squareMatrix[0][1] * (squareMatrix[1][0] * squareMatrix[2][2] -
                                  squareMatrix[1][2] * squareMatrix[2][0])
          + squareMatrix[0][2] * (squareMatrix[1][0] * squareMatrix[2][1] -
                                  squareMatrix[1][1] * squareMatrix[2][0]);
    }

    return determinant;
}
