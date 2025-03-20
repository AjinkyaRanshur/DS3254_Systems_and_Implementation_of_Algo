#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    // Matrix data stored in a vector of vectors.
    vector<vector<float>> _mat;
    int _rows;
    int _cols;

public:
    // Constructor that reads a matrix from a file.
    // File format: first two numbers are rows and columns, followed by the elements.
    Matrix(const string& filename) {
        ifstream file(filename);
        if (!file) {
            throw runtime_error("Could not open file: " + filename);
        }
        file >> _rows >> _cols;
        _mat.resize(_rows, vector<float>(_cols, 0));
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                if (!(file >> _mat[i][j])) {
                    throw runtime_error("File format error in " + filename);
                }
            }
        }
    }

    // Alternate constructor to create a matrix with given dimensions (filled with zeros)
    Matrix(int r, int c) : _rows(r), _cols(c), _mat(r, vector<float>(c, 0)) {}

    int rows() const { return _rows; }
    int cols() const { return _cols; }

    Matrix add(const Matrix& other) const {
        if (_rows != other._rows || _cols != other._cols) {
            throw invalid_argument("Matrix dimensions must be the same for addition.");
        }
        Matrix sum(_rows, _cols);
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                sum._mat[i][j] = _mat[i][j] + other._mat[i][j];
            }
        }
        return sum;
    }

    Matrix subtract(const Matrix& other) const {
        if (_rows != other._rows || _cols != other._cols) {
            throw invalid_argument("Matrix dimensions must be the same for subtraction.");
        }
        Matrix diff(_rows, _cols);
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                diff._mat[i][j] = _mat[i][j] - other._mat[i][j];
            }
        }
        return diff;
    }

    Matrix multiply(const Matrix& other) const {
        if (_cols != other._rows) {
            throw invalid_argument("Matrix dimensions must match for multiplication.");
        }
        Matrix product(_rows, other._cols);
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < other._cols; j++) {
                product._mat[i][j] = 0; // Initialize product cell
                for (int k = 0; k < _cols; k++) { // _cols == other._rows
                    product._mat[i][j] += _mat[i][k] * other._mat[k][j];
                }
            }
        }
        return product;
    }

    // Overloads the subscript operator to allow direct access to rows.
    vector<float>& operator[](int i) { return _mat[i]; }
    const vector<float>& operator[](int i) const { return _mat[i]; }

    // Overloads the insertion operator for outputting a matrix.
    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows(); i++) {
            for (int j = 0; j < m.cols(); j++) {
                out << m._mat[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
};

int main(){
    try {
        // Read matrices from files.
        // Ensure that "matrix1.txt" and "matrix2.txt" exist and follow the proper format.
        Matrix m1("matrix1.txt");
        Matrix m2("matrix2.txt");

        cout << "Matrix 1:\n" << m1;
        cout << "Matrix 2:\n" << m2;

        // Example: perform subtraction.
        Matrix diff = m1.subtract(m2);
        cout << "Subtraction of Matrices:\n" << diff;

        // Example: perform multiplication if dimensions are appropriate.
        // Note: For multiplication, the number of columns in m1 must equal the number of rows in m2.
        // Uncomment the following lines if this condition is met.
        // Matrix prod = m1.multiply(m2);
        // cout << "Multiplication of Matrices:\n" << prod;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
