#include <iostream>
#include <cmath>

const int WIDTH = 3;
const int HEIGHT = 3;

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

int main()
{
    double squareMatrix[WIDTH][HEIGHT] = {{1,2,3},{3,4,5},{5,6,1}};

    std::cout << compute_determinant(squareMatrix);

    return 0;
}
