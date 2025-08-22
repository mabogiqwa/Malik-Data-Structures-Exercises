//Created: 20-08-2025
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

double det(std::vector<std::vector<double>> &m);
//Precondition: The matrix must be a square matrix i.e. ROWS = COLUMNS where 2 <= ROWS, COLUMNS <= 4
//AND populated with rational numbers.
//Postcondition: The function returns the determinant of the matrix.

std::vector<std::vector<double>> operator *(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
//Precondition: The columns of the first matrix must be equal to the rows of the second matrix.
//Postcondition: The function returns the resulting matrix from matrix multiplication.

std::ostream& operator <<(std::ostream& os, const std::vector<std::vector<double>> &m);
//Postcondition: Prints the entries of a matrix/vector.

std::vector<double> gauss_seidel(std::vector<std::vector<double>> &v);
//Precondition: The matrix must be strictly diagonally dominant to converge to a solution.
//Postcondition: The function returns approximate solution values to the linear system.

std::vector<double> jacobi(std::vector<std::vector<double>> &v);
//Precondition: The matrix passed as arguments must be non-singular(det!=0) and square(rows=columns).
//It is sufficient that the matrix is diagonally dominant for the system to converge to a solution.
//Postcondition: The function returns approximate solution values to the linear system.

std::vector<std::vector<double>> operator +(const std::vector<std::vector<double>> &m1, const std::vector<std::vector<double>> &m2);
//Precondition: The matrices passed as arguments must have the same dimensions i.e rows = columns
//Postcondition: The function returns a vector which contains entries which are the difference of the corresponding
//entries of the matrices/vectors passed as arguments.

std::vector<std::vector<double>> operator -(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
//Precondition: The matrices passed as arguments must have the same dimensions i.e rows = columns
//Postcondition: The function returns a vector which contains entries which are the sum of the corresponding entries of the
//matrices/vectors passed as arguments. Might implement broadcasting later on.

std::vector<std::vector<double>> operator *(double scalar, std::vector<std::vector<double>> &m);
//Precondition: The scalar must be an integer or rational number(finite-point decimal)
//Postcondition: The function must return the scaled matrix/vector in which every entry is scaled by scalar.

long double euclid_norm(std::vector<std::vector<double>> &m);
//Precondition: The argument matrix/vector has to be a row or column vector.
//Postcondition: The function returns the euclidean norm of the row/column vector.

long double taxicab_norm(std::vector<std::vector<double>> &m);
//Precondition: The argument matrix/vector has to be a row or column vector.
//Postcondition: The function returns the taxicab/manhattan norm of the row/column vector.

long double max_norm(std::vector<std::vector<double>> &m);
//Precondition: The passed value must be of type std::vector<std::vector<double>>
//Postcondition: The function returns a value which is the absolute maximum of a matrix/vector.

long double frobenius_norm(std::vector<std::vector<double>> &m);
//Precondition: The passed value must be of type std::vector<std::vector<double>>
//Postcondition: The functions a long double value which is the frobenius norm.

int main()
{
    std::vector<std::vector<double>> v(1, std::vector<double>(1));
    v = {{3,4,-1,0},{1,10,-9,-15},{0,78,-101,3}};

    std::vector<std::vector<double>> w(2, std::vector<double>(4));
    w = {{4,1},{9,0}};

    std::cout << frobenius_norm(v);

    return 0;
}

long double frobenius_norm(std::vector<std::vector<double>> &m)
{
    int rows = m.size();
    int cols = m[0].size();
    long double sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += (m[i][j]*m[i][j]);
        }
    }

    return sqrt(sum);
}

long double max_norm(std::vector<std::vector<double>> &m)
{
    long double largestVal = -std::numeric_limits<double>::infinity();
    int rows = m.size();
    int cols = m[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fabs(m[i][j]) > largestVal) {
                    largestVal = fabs(m[i][j]);
            }
        }
    }

    return largestVal;
}


long double taxicab_norm(std::vector<std::vector<double>> &m)
{
    long double absSum = 0;
    int rows = m.size();
    int cols = m[0].size();

    if (rows == 1) {
        for (int i = 0; i < cols; i++) {
            absSum += fabs(m[0][i]);
        }
    }
    if (cols == 1) {
        for (int j = 0; j < rows; j++) {
            absSum += fabs(m[j][0]);
        }
    }

    return absSum;
}

long double euclid_norm(std::vector<std::vector<double>> &m)
{
    int rows = m.size();
    int cols = m[0].size();
    long double sum = 0, norm = 0;

    if (cols == 1) {
        for (int i = 0; i < rows; i++) {
            sum += pow(m[i][0], 2.00);
        }
        norm = sqrt(sum);
    }
    if (rows == 1) {
        for (int j = 0; j < cols; j++) {
            sum += pow(m[0][j], 2.00);
        }
        norm = sqrt(sum);
    }

    return norm;
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

std::vector<std::vector<double>> operator *(double scalar, std::vector<std::vector<double>> &m)
{
    int rows = m.size();
    int cols = m[0].size();

    std::vector<std::vector<double>> result(rows, std::vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = scalar * m[i][j];
        }
    }

    return result;
}

std::vector<std::vector<double>> operator *(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2)
{
    int m, n, p;

    m = m1.size();
    n = m1[0].size();
    p = m2[0].size();

    std::vector<std::vector<double>> C(m, std::vector<double>(p));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return C;
}

double det(std::vector<std::vector<double>> &m)
{
    double determinant;
    int rows = m.size();
    int cols = m[0].size();

    if ((rows == 2) && (cols == 2)) {
        determinant = (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);
    }

    if ((rows == 3) && (cols == 3)) {
        determinant =
            m[0][0] * (m[1][1] * m[2][2] -
                                  m[1][2] * m[2][1])
          - m[0][1] * (m[1][0] * m[2][2] -
                                  m[1][2] * m[2][0])
          + m[0][2] * (m[1][0] * m[2][1] -
                                  m[1][1] * m[2][0]);
    }


    if ((rows == 4) && (cols == 4)) {
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
