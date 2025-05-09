#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{
public:
    Matrix (){
        vector<vector<int>> m(0);
        matrix = m;
    }

    Matrix (const int& rows, const int& columns){
        if (rows < 0 || columns < 0){
            throw out_of_range("");
        }
        if (rows == 0 || columns == 0){
            vector<vector<int>> m(0, vector<int>(0));
            matrix = m;
        }
        else{
            vector<vector<int>> m(rows, vector<int>(columns));
            matrix = m;
        }
        
    }

    void Reset (const int& rows, const int& columns){
        if (rows < 0 || columns < 0){
            throw out_of_range("");
        }
        if (rows == 0 || columns == 0){
            vector<vector<int>> m(0, vector<int>(0));
            matrix = m;
        }
        else{
            vector<vector<int>> m(rows, vector<int>(columns));
            matrix = m;
        }
        
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[i].size(); ++j){
                matrix[i][j] = 0;
            }
        }
    }

    int At (const int& row, const int& column) const {
        if (row < 0 || column < 0){
            throw out_of_range("");
        }
        if (row >= GetNumRows() || column >= GetNumColumns()){
            throw out_of_range("");
        }
        return matrix[row][column];
    }

    int& At (const int& row, const int& column) {
        if (row < 0 || column < 0){
            throw out_of_range("");
        }
        if (row >= GetNumRows() || column >= GetNumColumns()){
            throw out_of_range("");
        }
        return matrix[row][column];
    }

    int GetNumRows() const {
        return matrix.size();
    }

    int GetNumColumns() const {
        if (matrix.size() == 0){
            return 0;
        }
        return matrix[0].size();
    }
private:
    vector<vector<int>> matrix;
};


ostream& operator<< (ostream& stream, const Matrix& m){
    stream << m.GetNumRows() << " " << m.GetNumColumns() << endl;
    for (int i = 0; i < m.GetNumRows(); ++i){
        for (int j = 0; j < m.GetNumColumns(); ++j){
            stream << m.At(i, j) << " ";
        }
        stream << endl;
    }
    return stream;
}

istream& operator>> (istream& stream, Matrix& m){
    int row, col;
    stream >> row;
    stream.ignore(1);
    stream >> col;
    Matrix tmp(row, col);
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            stream >> tmp.At(i, j);
        }   
    }
    m = tmp;
    return stream;
}

bool operator== (const Matrix& lhs, const Matrix& rhs){
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()){
        return false;
    }
    for (int i = 0; i < lhs.GetNumRows(); ++i){
        for (int j = 0; j < lhs.GetNumColumns(); ++j){
            if (lhs.At(i, j) != rhs.At(i, j)){
                return false;
            }
        }   
    }
    return true;
}

Matrix operator+ (const Matrix& lhs, const Matrix& rhs){
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()){
        throw invalid_argument("");
    }
    Matrix sum (lhs.GetNumRows(), lhs.GetNumColumns());

    for (int i = 0; i < lhs.GetNumRows(); ++i){
        for (int j = 0; j < lhs.GetNumColumns(); ++j){
            sum.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }   
    }
    return sum;
}


int main() {
    Matrix one(4,0);
    Matrix two(0,5);
    Matrix three = one + two;
    cout << three << endl;
    bool r = one == two;
    cout << r << endl;

    three.Reset(3, 3);
    cout << three << endl;
    three.Reset(0, 0);
    cout << three << endl;
    // cout << one.At(0, 0);

    return 0;
}