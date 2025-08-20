#include <iostream>
#include <cmath>

const int WIDTH = 4;
const int HEIGHT = 4;

double compute_determinant(double m[WIDTH][HEIGHT]);
//Precondition: The matrix must be a square matrix i.e. WIDTH = HEIGHT where 2 <= HEIGHT, WIDTH <= 4
//AND populated with rational numbers.
//Postcondition: The function returns the determinant of the matrix

int main()
{
    double m[WIDTH][HEIGHT] = {{1,0,4,-6},{2,5,0,3},{-1,2,3,5},{2,1,-2,3}};

    std::cout << compute_determinant(m);

    return 0;
}

double compute_determinant(double m[WIDTH][HEIGHT])
{
    double determinant;

    if ((WIDTH == 2) && (HEIGHT == 2)) {
        determinant = (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);
    }

    if ((WIDTH == 3) && (HEIGHT == 3)) {
        determinant =
            m[0][0] * (m[1][1] * m[2][2] -
                                  m[1][2] * m[2][1])
          - m[0][1] * (m[1][0] * m[2][2] -
                                  m[1][2] * m[2][0])
          + m[0][2] * (m[1][0] * m[2][1] -
                                  m[1][1] * m[2][0]);
    }


    if ((WIDTH == 4) && (HEIGHT == 4)) {
        determinant =
            m[0][0] * ( m[1][1] * (m[2][2]*m[3][3] - m[2][3]*m[3][2])
                      - m[1][2] * (m[2][1]*m[3][3] - m[2][3]*m[3][1])
                      + m[1][3] * (m[2][1]*m[3][2] - m[2][2]*m[3][1]) )
          - m[0][1] * ( m[1][0] * (m[2][2]*m[3][3] - m[2][3]*m[3][2])
                      - m[1][2] * (m[2][0]*m[3][3] - m[2][3]*m[3][0])
                      + m[1][3] * (m[2][0]*m[3][2] - m[2][2]*m[3][0]) )
          + m[0][2] * ( m[1][0] * (m[2][1]*m[3][3] - m[2][3]*m[3][1])
                      - m[1][1] * (m[2][0]*m[3][3] - m[2][3]*m[3][0])
                      + m[1][3] * (m[2][0]*m[3][1] - m[2][1]*m[3][0]) )
          - m[0][3] * ( m[1][0] * (m[2][1]*m[3][2] - m[2][2]*m[3][1])
                      - m[1][1] * (m[2][0]*m[3][2] - m[2][2]*m[3][0])
                      + m[1][2] * (m[2][0]*m[3][1] - m[2][1]*m[3][0]) );
    }

    return determinant;
}
