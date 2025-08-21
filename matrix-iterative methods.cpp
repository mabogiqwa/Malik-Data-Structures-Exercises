#include <iostream>
#include <cmath>
#include <vector>

const int ROWS = 3;
const int COLUMNS = 3;

double compute_determinant(std::vector<std::vector<double>> &m);
//Precondition: The matrix must be a square matrix i.e. WIDTH = HEIGHT where 2 <= HEIGHT, WIDTH <= 4
//AND populated with rational numbers.
//Postcondition: The function returns the determinant of the matrix

std::vector<std::vector<double>> operator *(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
//Precondition: The columns of the first matrix must be equal to the rows of the second matrix.
//Postcondition: The function returns the resulting matrix from matrix multiplication.

std::ostream& operator <<(std::ostream& os, const std::vector<std::vector<double>> &m);
//Postcondition: Prints the entries of a matrix/vector.

std::vector<double> gauss_seidel(std::vector<std::vector<double>> &v);
//Precondition: The matrix must be strictly diagonally dominant to converge to a solution.
//Postcondition: The function returns approximate solution values to the linear system.

int main()
{
    std::vector<std::vector<double>> v(ROWS, std::vector<double>(COLUMNS));
    v = {{2,1,0},{1,-1,2},{0,2,4}};
    //double m[WIDTH][HEIGHT] = {{1,0,4,-6},{2,5,0,3},{-1,2,3,5},{2,1,-2,3}};
    std::vector<std::vector<double>> w(3, std::vector<double>(1));
    w = {{2},{5},{-1}};

    std::cout << v * w;

    return 0;
}

std::ostream& operator <<(std::ostream& os, const std::vector<std::vector<double>> &m) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return os;
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
