#include <iostream>
#include <cmath>
#include <vector>

const int ROWS = 2;
const int COLUMNS = 2;

double compute_determinant(std::vector<std::vector<double>> &m);
//Precondition: The matrix must be a square matrix i.e. WIDTH = HEIGHT where 2 <= HEIGHT, WIDTH <= 4
//AND populated with rational numbers.
//Postcondition: The function returns the determinant of the matrix

std::vector<std::vector<double>> operator *(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
//Precondition: The columns of the first matrix must be equal to the rows of the second matrix.
//Postcondition: The function returns the resulting matrix from matrix multiplication.

void print(std::vector<std::vector<double>> &m);
//Postcondition: Prints the contents of a matrix/vector.

int main()
{
    std::vector<std::vector<double>> v(ROWS, std::vector<double>(COLUMNS));
    v = {{1,2},{3,4}};
    //double m[WIDTH][HEIGHT] = {{1,0,4,-6},{2,5,0,3},{-1,2,3,5},{2,1,-2,3}};
    std::vector<std::vector<double>> w(ROWS, std::vector<double>(COLUMNS));
    w = {{5,6},{6,7}};

    std::vector<std::vector<double>> resultingMatrix(ROWS, std::vector<double>(COLUMNS));

    resultingMatrix = v * w;

    print(resultingMatrix);

    return 0;
}

void print(std::vector<std::vector<double>> &m) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<double>> operator *(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2)
{

    std::vector<std::vector<double>> C(ROWS, std::vector<double>(COLUMNS));
    int m, n, p;

    m = m1.size();
    n = m1[0].size();
    p = m2[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return C;
}

double compute_determinant(std::vector<std::vector<double>> &m)
{
    double determinant;

    if ((ROWS == 2) && (COLUMNS == 2)) {
        determinant = (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);
    }

    if ((ROWS == 3) && (ROWS == 3)) {
        determinant =
            m[0][0] * (m[1][1] * m[2][2] -
                                  m[1][2] * m[2][1])
          - m[0][1] * (m[1][0] * m[2][2] -
                                  m[1][2] * m[2][0])
          + m[0][2] * (m[1][0] * m[2][1] -
                                  m[1][1] * m[2][0]);
    }


    if ((ROWS == 4) && (COLUMNS == 4)) {
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
