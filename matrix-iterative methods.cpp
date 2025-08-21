//
#include <iostream>
#include <cmath>
#include <vector>

const int ROWS = 4;
const int COLUMNS = 4;

double compute_determinant(std::vector<std::vector<double>> &m);
//Precondition: The matrix must be a square matrix i.e. ROWS = COLUMNS where 2 <= ROWS, COLUMNS <= 4
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

std::vector<std::vector<double>> operator +(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
//Precondition: The matrices passed as arguments must have the same dimensions i.e rows = columns
//Postcondition: The function returns a vector which contains entries which are the difference of the corresponding
//entries of the matrices/vectors passed as arguments.
std::vector<std::vector<double>> operator -(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
//Precondition: The matrices passed as arguments must have the same dimensions i.e rows = columns
//Postcondition: The function returns a vector which contains entries which are the sum of the corresponding entries of the
//matrices/vectors passed as arguments. Might implement broadcasting later on.

int main()
{
    std::vector<std::vector<double>> v(4, std::vector<double>(4));
    v = {{2}};

    std::vector<std::vector<double>> w(4, std::vector<double>(4));
    w = {{4}};

    std::cout << w + v;

    return 0;
}

std::ostream& operator <<(std::ostream& os, const std::vector<std::vector<double>> &m) {
    int rows = m.size();
    int cols = m[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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

std::vector<std::vector<double>> operator +(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2)
{
    int rowSize1 = m1.size(); //retrieves number of rows
    int colSize1 = m1[0].size(); //retrieves number of columns
    int rowSize2 = m2.size();
    int colSize2 = m2[0].size();

    if ((rowSize1 == rowSize2) && (colSize1 == colSize2) && (rowSize1 == 1)) {
        return {{m1[0][0]+m2[0][0]}};
    }
    else if ((rowSize1 == rowSize2) && (colSize1 == colSize2) && (rowSize1 == 2)) {
        return {{m1[0][0]+m2[0][0], m1[0][1]+m2[0][1]},{m1[1][0]+m2[1][0],m1[1][1]+m2[1][1]}};
    }
    else if ((rowSize1 == rowSize2) && (colSize1 == colSize2) && (rowSize1 == 3)) {
        return {{m1[0][0]+m2[0][0],m1[0][1]+m2[0][1],m1[0][2]+m2[0][2]},{m1[1][0]+m2[1][0],m1[1][1]+m2[1][1],m1[1][2]+m2[1][2]},{m1[2][0]+m2[2][0],m1[2][1]+m2[2][1],m1[2][2]+m2[2][2]}};
    }
    else if ((rowSize1 == rowSize2) && (colSize1 == colSize2) && (rowSize1 == 4)) {
        return {{m1[0][0]+m2[0][0],m1[0][1]+m2[0][1],m1[0][2]+m2[0][2],m1[0][3]+m2[0][3]},{m1[1][0]+m2[1][0],m1[1][1]+m2[1][1],m1[1][2]+m2[1][2],m1[1][3]+m2[1][3]},{m1[2][0]+m2[2][0],m1[2][1]+m2[2][1],m1[2][2]+m2[2][2],m1[2][3]+m2[2][3]},{m1[3][0]+m2[3][0],m1[3][1]+m2[3][1],m1[3][2]+m2[3][2],m1[3][3]+m2[3][3]}};
    }
    else {
        return {};
    }
}

std::vector<std::vector<double>> operator -(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2)
{
    int rowSize1 = m1.size(); //retrieves number of rows
    int colSize1 = m1[0].size(); //retrieves number of columns
    int rowSize2 = m2.size();
    int colSize2 = m2[0].size();

    if ((rowSize1 == rowSize2) && (colSize1 == colSize2) && (rowSize1 == 1)) {
        return {{m1[0][0]-m2[0][0]}};
    }
    else if ((rowSize1 == rowSize2) && (colSize1 == colSize2) && (rowSize1 == 2)) {
        return {{m1[0][0]-m2[0][0], m1[0][1]-m2[0][1]},{m1[1][0]-m2[1][0],m1[1][1]-m2[1][1]}};
    }
    else if ((rowSize1 == rowSize2) && (colSize1 == colSize2) && (rowSize1 == 3)) {
        return {{m1[0][0]-m2[0][0],m1[0][1]-m2[0][1],m1[0][2]-m2[0][2]},{m1[1][0]-m2[1][0],m1[1][1]-m2[1][1],m1[1][2]-m2[1][2]},{m1[2][0]-m2[2][0],m1[2][1]-m2[2][1],m1[2][2]-m2[2][2]}};
    }
    else if ((rowSize1 == rowSize2) && (colSize1 == colSize2) && (rowSize1 == 4)) {
        return {{m1[0][0]-m2[0][0],m1[0][1]-m2[0][1],m1[0][2]-m2[0][2],m1[0][3]-m2[0][3]},{m1[1][0]-m2[1][0],m1[1][1]-m2[1][1],m1[1][2]-m2[1][2],m1[1][3]-m2[1][3]},{m1[2][0]-m2[2][0],m1[2][1]-m2[2][1],m1[2][2]-m2[2][2],m1[2][3]-m2[2][3]},{m1[3][0]-m2[3][0],m1[3][1]-m2[3][1],m1[3][2]-m2[3][2],m1[3][3]-m2[3][3]}};
    }
    else
    {
        return {};
    }
}
