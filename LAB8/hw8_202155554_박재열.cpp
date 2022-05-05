#include <iostream>
using namespace std;

class Matrix{
    int** values;
    int row, column;

public:
    Matrix(const int rowIn = 0, const int columnIn = 0){
        this->row = rowIn;
        this->column = columnIn;

        values = new int* [rowIn];
        for (int i = 0; i < rowIn; i++)
            values[i] = new int[columnIn];
    }

    Matrix(const Matrix& matrix){
        this->row = matrix.row;
        this->column = matrix.column;

        values = new int* [row];
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++)
                values[i] = new int[j];
        }

        for (int i = 0; i < matrix.row; i++){
            for (int j = 0; j < matrix.column; j++){
                values[i][j] = matrix.values[i][j];
            }
        }
    }

    ~Matrix(){
        delete[] values;
    }

    Matrix& operator + (const Matrix& matrix){
        for (int i = 0; i < matrix.row; i++){
            for (int j = 0; j < matrix.column; j++){
                values[i][j] += matrix.values[i][j];
            }
        }
        return *this;
    }

    Matrix* operator = (const Matrix& matrix){
        for (int i = 0; i < matrix.row; i++){
            for (int j = 0; j < matrix.column; j++){
                values[i][j] = matrix.values[i][j];
            }
        }
        return this;
    }

    friend istream& operator >> (istream& is, const Matrix& matrix);
    friend ostream& operator << (ostream& os, const Matrix& matrix);
    friend Matrix operator * (const Matrix matrix, const int n);

};

Matrix operator * (const Matrix matrix, const int n){
    for (int i = 0; i < matrix.row; i++){
        for (int j = 0; j < matrix.column; j++){
            matrix.values[i][j] = matrix.values[i][j] * n;
        }
    }
    return matrix;
}

istream& operator >> (istream& is, const Matrix& matrix){
    for (int i = 0; i < matrix.row; i++){
        for (int j = 0; j < matrix.column; j++){
            is >> matrix.values[i][j];
        }
    }
    return is;
}

ostream& operator << (ostream& os, const Matrix& matrix){
    for (int i = 0; i < matrix.row; i++){
        for (int j = 0; j < matrix.column; j++){
            os << matrix.values[i][j] << "\t";
        }
        os << endl;
    }
    return os;
}

int main(){
    Matrix m1(2, 2), m2(2, 2);
    cin >> m1;
    cin >> m2;

    Matrix m3(m1 + m2);
    Matrix m4(2, 2);

    m4 = m3 * 10;

    cout << m3 << endl << m4 << endl;
}