//Created: 20-08-2025
//Going to overload the iterative methods to stop after reaching
//a certain error threshold
//Going to add iterative methods for differential linear systems
//Need to edit the definition of dot() to allow the computation of the dot
//product of a column and row vector.
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <iomanip>

struct EigenResult
{
    std::vector<std::vector<double>> eigenVector;
    double eigenvalue;
};

double det(std::vector<std::vector<double>> &m);
//Precondition: The matrix must be a square matrix i.e. ROWS = COLUMNS where 2 <= ROWS, COLUMNS <= 4
//AND populated with rational numbers.
//Postcondition: The function returns the determinant of the matrix.

std::vector<std::vector<double>> operator *(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
//Precondition: The columns of the first matrix must be equal to the rows of the second matrix.
//Postcondition: The function returns the resulting matrix from matrix multiplication.

std::ostream& operator <<(std::ostream& os, const std::vector<std::vector<double>> &m);
//Postcondition: Prints the entries of a matrix/vector.

std::vector<std::vector<double>> gauss_seidel(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &b, int iterations);
//Precondition: The matrix must be strictly diagonally dominant to converge to a solution and the matrix must be square i.e. ROWS = COLUMNS where 2 <= ROWS, COLUMNS <= 4
//Postcondition: The function returns approximate solution values to the linear system.

std::vector<std::vector<double>> jacobi(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &b, int iterations);
//Precondition: The matrices passed as arguments must be non-singular(det!=0) and square(rows=columns).
//It is sufficient that the matrix is diagonally dominant for the system to converge to a solution.
//Postcondition: The function returns approximate solution values to the linear system.

std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> &X);
//Precondition: The matrix must be populated with valid values
//Postcondition: The function transposes the given matrix, a process where the value of the rows switches with the
//value of the columns and returns the transposed matrix.

double dot(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
//Precondition: The input vector must be a row or column vector.
//Postcondition: Returns the dot product of two row/column vectors.

std::vector<std::vector<double>> pow(std::vector<std::vector<double>> &X, int pow);
//Precondition: The number of rows and columns must have the same size
//Postcondition: Returns the power of a matrix

bool isStrictlyDiagonallyDominant(std::vector<std::vector<double>> &v);
//Precondition: The given matrix/vector must be a square
//Postcondition: Returns a boolean value indicated whether matrix is strictly diagonally dominant or not.

std::vector<std::vector<double>> operator +(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2);
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

std::vector<std::vector<double>> inv(std::vector<std::vector<double>> &m);
//Precondition: The argument matrix must be square (row=cols), singular(det!=0), and 2 <= row,cols <= 5
//Postcondition: The function returns an approximated inverse using the gauss-seidel

EigenResult power_method(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &X, int iterations);
//Precondition: The passed matrix must be square(rows=cols)
//Postcondition: The method returns the dominant eigenvalue and associated eigenvector

std::ostream& operator <<(std::ostream &os, EigenResult &result);
//Postconditon: Prints the contents of the EigenResult object

int main()
{
    std::vector<std::vector<double>> A = {{2,1},{1,3}};

    std::vector<std::vector<double>> b = {{1},{0}};

    std::vector<std::vector<double>> w = {{4,1,2},{9,0,3},{2,3,7}};

    std::cout << gauss_seidel(A, b, 50);

    //EigenResult r = power_method(A, X, 3);
    //std::cout << r;

    return 0;
}

std::ostream& operator <<(std::ostream &os, EigenResult &result) {
    std::cout << "Eigenvalue: " << result.eigenvalue << std::endl;
    std::cout << "Associated eigenvector: " << std::endl;
    std::cout << result.eigenVector;
    std::cout << std::endl;

    return os;
}

EigenResult power_method(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &X, int iterations) {
    long double euclidNorm;
    std::vector<std::vector<double>> x_i, nextX;
    std::vector<std::vector<double>> y_i;
    double eigenVApprox = 0;
    EigenResult result;

    euclidNorm = euclid_norm(X);
    x_i = (1.0/euclidNorm)*X;

    for (int i = 0; i < iterations; i++) {
        y_i = A * x_i;

        euclidNorm = euclid_norm(y_i);
        nextX = (1/euclidNorm)*y_i;
        eigenVApprox = dot(x_i, y_i);
        //std::cout << "Eigenvalue approximation: " << eigenVApprox << std::endl;
        x_i = nextX;
    }
    result.eigenvalue = eigenVApprox;
    result.eigenVector = nextX;

    return result;
}

double dot(std::vector<std::vector<double>> &m1, std::vector<std::vector<double>> &m2) {
    int rows1 = m1.size();
    int cols1 = m1[0].size();
    int rows2 = m2.size();
    int cols2 = m2[0].size();
    double sum = 0;

    if ((cols1 != 1) && (rows1 != 1)) {
        std::cout << "Input vector not a row or column vector" << std::endl;
        return -1;
    }

    if ((rows1 == rows2) && (cols1 == cols2)) {
        if (rows1 == 1) {
            for (int i = 0; i < cols1; i++) {
                sum += m1[0][i]*m2[0][i];
            }
        }
        if (cols1 == 1) {
            for (int j = 0; j < rows1; j++) {
                sum += m1[j][0]*m2[j][0];
            }
        }
    }

    return sum;
}

std::vector<std::vector<double>> inv(std::vector<std::vector<double>> &m) {
    int rows = m.size();
    int cols = m[0].size();
    std::vector<std::vector<double>> result = {{}};
    int determinant;

    determinant = det(m);

    if ((determinant != 0) && (rows == cols)) {
        if ((rows == 2) && (cols == 2)) {
            double scalar = 1.0/(m[0][0]*m[1][1] - m[0][1]*m[1][0]);
            result = {{m[1][1], -m[0][1]},{-m[1][0], m[0][0]}};

            result = scalar * result;
        }
        if ((rows == 3) && (cols == 3)) {
            //standard vectors
            std::vector<std::vector<double>> a_1 = {{1},{0},{0}};
            std::vector<std::vector<double>> a_2 = {{0},{1},{0}};
            std::vector<std::vector<double>> a_3 = {{0},{0},{1}};

            std::vector<std::vector<double>> col1 = gauss_seidel(m, a_1, 50);
            std::vector<std::vector<double>> col2 = gauss_seidel(m, a_2, 50);
            std::vector<std::vector<double>> col3 = gauss_seidel(m, a_3, 50);

            return {{col1[0][0],col2[0][0],col3[0][0]},
                    {col1[0][1],col2[0][1],col3[0][1]},
                    {col1[0][2],col2[0][2],col3[0][2]}};
        }
        if ((rows == 4) & (cols == 4)) {
            //Standard vectors
            std::vector<std::vector<double>> a_1 = {{1},{0},{0},{0}};
            std::vector<std::vector<double>> a_2 = {{0},{1},{0},{0}};
            std::vector<std::vector<double>> a_3 = {{0},{0},{1},{0}};
            std::vector<std::vector<double>> a_4 = {{0},{0},{0},{1}};

            std::vector<std::vector<double>> col1 = gauss_seidel(m, a_1, 50);
            std::vector<std::vector<double>> col2 = gauss_seidel(m, a_2, 50);
            std::vector<std::vector<double>> col3 = gauss_seidel(m, a_3, 50);
            std::vector<std::vector<double>> col4 = gauss_seidel(m, a_4, 50);

            return {{col1[0][0],col2[0][0],col3[0][0],col4[0][0]},
                    {col1[0][1],col2[0][1],col3[0][1],col4[0][1]},
                    {col1[0][2],col2[0][2],col3[0][2],col4[0][2]},
                    {col1[0][3],col2[0][3],col3[0][3],col4[0][3]}};
        }
        if ((rows == 5) && (cols == 5)) {
            //Standard vectors
            std::vector<std::vector<double>> a_1 = {{1},{0},{0},{0},{0}};
            std::vector<std::vector<double>> a_2 = {{0},{1},{0},{0},{0}};
            std::vector<std::vector<double>> a_3 = {{0},{0},{1},{0},{0}};
            std::vector<std::vector<double>> a_4 = {{0},{0},{0},{1},{0}};
            std::vector<std::vector<double>> a_5 = {{0},{0},{0},{0},{1}};

            std::vector<std::vector<double>> col1 = gauss_seidel(m, a_1, 50);
            std::vector<std::vector<double>> col2 = gauss_seidel(m, a_2, 50);
            std::vector<std::vector<double>> col3 = gauss_seidel(m, a_3, 50);
            std::vector<std::vector<double>> col4 = gauss_seidel(m, a_4, 50);
            std::vector<std::vector<double>> col5 = gauss_seidel(m, a_5, 50);

            return {{col1[0][0],col2[0][0],col3[0][0],col4[0][0],col5[0][0]},
                    {col1[0][1],col2[0][1],col3[0][1],col4[0][1],col5[0][1]},
                    {col1[0][2],col2[0][2],col3[0][2],col4[0][2],col5[0][2]},
                    {col1[0][3],col2[0][3],col3[0][3],col4[0][3],col5[0][3]},
                    {col1[0][4],col2[0][4],col3[0][4],col4[0][4],col5[0][4]}};
        }
    } else {
        std::cout << "Matrix is singular or the matrix is not square" << std::endl;
        return {{}};
    }

    return result;
}

std::vector<std::vector<double>> pow(std::vector<std::vector<double>> &X, int pow)
{
    std::vector<std::vector<double>> result = X;
    int rows = X.size();
    int cols = X[0].size();

    if (rows != cols) {
        std::cout << "Mismatch between rows and columns" << std::endl;
        return {{}};
    } else {
        for (int i = 1; i < pow; i++) {
            result = result * X;
        }
    }


    return result;
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

std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> &X)
{
    int rows = X.size();
    int cols = X[0].size();

    std::vector<std::vector<double>> Xt(cols, std::vector<double>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Xt[j][i] = X[i][j];
        }
    }

    return Xt;
}

bool isStrictlyDiagonallyDominant(std::vector<std::vector<double>> &v)
{
    bool isDDominant = false;
    int rows = v.size(), cols = v[0].size();
    long double sum = 0, diagonalEntry;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            if (i != j) { sum += fabs(v[i][j]); }
            if (i = j) { diagonalEntry = v[i][j]; }
        }
        if (fabs(diagonalEntry) >= sum) {
            isDDominant = true;
        } else {
            return false;
        }
    }

    return isDDominant;
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

std::vector<std::vector<double>> gauss_seidel(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &b, int iterations)
{
    int rows = A.size();
    int cols = A[0].size();

    std::vector<std::vector<double>> x;

    if ((rows == 2) && (cols == 2)) {
        double firstApprox, secondApprox;

        x = {{0,0}}; //initial approximation

        //std::cout << "x1:         x2:" << std::endl;
        for (int iter = 0; iter < iterations; iter++)
        {
            firstApprox = (1 / A[0][0]) * (b[0][0] - A[0][1] * x[0][1]);
            x[0][0] = firstApprox;
            secondApprox = (1 / A[1][1]) * (b[1][0] - A[1][0] * x[0][0]);
            x[0][1] = secondApprox;

            //std::cout << std::fixed << std::setprecision(5);
            //std::cout << firstApprox << "   " << secondApprox << std::endl;
            // update all values at once
        }
    }

    if ((rows == 3) && (cols == 3)) { //This case is not tested
        double firstApprox, secondApprox, thirdApprox;

        x = {{0,0,0}}; //initial approximation

        //std::cout << "x1:         x2:       x3:" << std::endl;
        for (int iter = 0; iter < iterations; iter++)
        {
            firstApprox = (1 / A[0][0]) * (b[0][0] - A[0][1] * x[0][1] - A[0][2] * x[0][2]);
            x[0][0] = firstApprox;
            secondApprox = (1 / A[1][1]) * (b[1][0] - A[1][0] * x[0][0] - A[1][2] * x[0][2]);
            x[0][1] = secondApprox;
            thirdApprox = (1 / A[2][2]) * (b[2][0] - A[2][0] * x[0][0] - A[2][1] * x[0][1]);
            x[0][2] = thirdApprox;

            //std::cout << std::fixed << std::setprecision(5);
            //std::cout << firstApprox << "   " << secondApprox << "   " << thirdApprox << std::endl;
            // update all values at once
        }
    }

    if ((rows == 4) && (cols == 4)) {
        double firstApprox, secondApprox, thirdApprox, fourthApprox;

        x = {{0,0,0,0}}; //initial approximation

        //std::cout << "x1:         x2:       x3:        x4:" << std::endl;
        for (int iter = 0; iter < iterations; iter++)
        {
            firstApprox = (1 / A[0][0]) * (b[0][0] - A[0][1] * x[0][1] - A[0][2] * x[0][2] - A[0][3] * x[0][3]);
            x[0][0] = firstApprox;
            secondApprox = (1 / A[1][1]) * (b[1][0] - A[1][0] * x[0][0] - A[1][2] * x[0][2] - A[1][3] * x[0][3]);
            x[0][1] = secondApprox;
            thirdApprox = (1 / A[2][2]) * (b[2][0] - A[2][0] * x[0][0] - A[2][1] * x[0][1] - A[2][3] * x[0][3]);
            x[0][2] = thirdApprox;
            fourthApprox = (1 / A[3][3]) * (b[3][0] - A[3][0] * x[0][0] - A[3][1] * x[0][1] - A[3][2] * x[0][2]);
            x[0][3] = fourthApprox;

            //std::cout << std::fixed << std::setprecision(5);
            //std::cout << firstApprox << "   " << secondApprox << "   " << thirdApprox << "   " << fourthApprox << std::endl;
            // update all values at once
        }
    }

    return x;
}

std::vector<std::vector<double>> jacobi(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &b, int iterations)
{
    int rows = A.size();
    int cols = A[0].size();

    std::vector<std::vector<double>> x;

    if ((rows == 2) && (cols == 2)) {
        double firstApprox, secondApprox;

        x = {{0,0}}; //initial approximation
        std::vector<double> x_old(2, 0.0);

        //std::cout << "x1:         x2:" << std::endl;
        for (int iter = 0; iter < iterations; iter++)
        {
            x_old = x[0];

            firstApprox = (1 / A[0][0]) * (b[0][0] - A[0][1] * x_old[1]);
            secondApprox = (1 / A[1][1]) * (b[1][0] - A[1][0] * x_old[0]);

            //std::cout << std::fixed << std::setprecision(5);
            //std::cout << firstApprox << "   " << secondApprox << std::endl;
            // update all values at once
            x[0][0] = firstApprox;
            x[0][1] = secondApprox;
        }
    }

    if ((rows == 3) && (cols == 3)) { //This case is not tested
        double firstApprox, secondApprox, thirdApprox;

        x = {{0,0,0}}; //initial approximation
        std::vector<double> x_old(3, 0.0);

        //std::cout << "x1:         x2:       x3:" << std::endl;
        for (int iter = 0; iter < iterations; iter++)
        {
            x_old = x[0];

            firstApprox = (1 / A[0][0]) * (b[0][0] - A[0][1] * x_old[1] - A[0][2] * x_old[2]);
            secondApprox = (1 / A[1][1]) * (b[1][0] - A[1][0] * x_old[0] - A[1][2] * x_old[2]);
            thirdApprox = (1 / A[2][2]) * (b[2][0] - A[2][0] * x_old[0] - A[2][1] * x_old[1]);

            //std::cout << std::fixed << std::setprecision(5);
            //std::cout << firstApprox << "   " << secondApprox << "   " << thirdApprox << std::endl;
            // update all values at once
            x[0][0] = firstApprox;
            x[0][1] = secondApprox;
            x[0][2] = thirdApprox;
        }
    }

    if ((rows == 4) && (cols == 4)) {
        double firstApprox, secondApprox, thirdApprox, fourthApprox;

        x = {{0,0,0,0}}; //initial approximation
        std::vector<double> x_old(4, 0.0);

        //std::cout << "x1:         x2:       x3:        x4:" << std::endl;
        for (int iter = 0; iter < iterations; iter++)
        {
            x_old = x[0]; // save previous iteration

            firstApprox = (1 / A[0][0]) * (b[0][0] - A[0][1] * x_old[1] - A[0][2] * x_old[2] - A[0][3] * x_old[3]);
            secondApprox = (1 / A[1][1]) * (b[1][0] - A[1][0] * x_old[0] - A[1][2] * x_old[2] - A[1][3] * x_old[3]);
            thirdApprox = (1 / A[2][2]) * (b[2][0] - A[2][0] * x_old[0] - A[2][1] * x_old[1] - A[2][3] * x_old[3]);
            fourthApprox = (1 / A[3][3]) * (b[3][0] - A[3][0] * x_old[0] - A[3][1] * x_old[1] - A[3][2] * x_old[2]);

            //std::cout << std::fixed << std::setprecision(5);
            //std::cout << firstApprox << "   " << secondApprox << "   " << thirdApprox << "   " << fourthApprox << std::endl;
            // update all values at once
            x[0][0] = firstApprox;
            x[0][1] = secondApprox;
            x[0][2] = thirdApprox;
            x[0][3] = fourthApprox;
        }
    }

    return x;
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
