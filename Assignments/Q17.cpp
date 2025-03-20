#include <iostream>
#include <stdexcept>
#include <vector>

//--------------------------------------------------
// Dense Matrix using 1-D Array
//--------------------------------------------------
class Matrix {
private:
    int rows, cols;
    int* data;
public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        if (r <= 0 || c <= 0)
            throw std::invalid_argument("Matrix dimensions must be positive.");
        data = new int[rows * cols]();
    }
    
    // Copy Constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++)
            data[i] = other.data[i];
    }
    
    // Assignment operator
    Matrix& operator=(const Matrix &other) {
        if (this != &other) {
            delete[] data;
            rows = other.rows;
            cols = other.cols;
            data = new int[rows * cols];
            for (int i = 0; i < rows * cols; i++)
                data[i] = other.data[i];
        }
        return *this;
    }
    
    // Destructor
    ~Matrix() {
        delete[] data;
    }
    
    // Access operators
    int& operator()(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw std::out_of_range("Index out of range.");
        return data[row * cols + col];
    }
    
    int operator()(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw std::out_of_range("Index out of range.");
        return data[row * cols + col];
    }
    
    // Get dimensions
    int numRows() const { return rows; }
    int numCols() const { return cols; }
    
    // Display matrix
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                std::cout << (*this)(i, j) << " ";
            std::cout << std::endl;
        }
    }
    
    // Addition operator
    Matrix operator+(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrix dimensions must agree for addition.");
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++)
            result.data[i] = this->data[i] + other.data[i];
        return result;
    }
    
    // Multiplication operator
    Matrix operator*(const Matrix &other) const {
        if (cols != other.rows)
            throw std::invalid_argument("Matrix dimensions incompatible for multiplication.");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++)
                    sum += (*this)(i, k) * other(k, j);
                result(i, j) = sum;
            }
        }
        return result;
    }
};

//--------------------------------------------------
// Sparse Matrix using vector of elements
//--------------------------------------------------
struct Element {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int rows, cols;
    std::vector<Element> elements;
public:
    // Constructor
    SparseMatrix(int r, int c) : rows(r), cols(c) {
        if (r <= 0 || c <= 0)
            throw std::invalid_argument("Matrix dimensions must be positive.");
    }
    
    // Get dimensions
    int numRows() const { return rows; }
    int numCols() const { return cols; }
    
    // Set an element (nonzero values stored only)
    void set(int row, int col, int value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw std::out_of_range("Index out of range.");
        
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (it->row == row && it->col == col) {
                if (value == 0)
                    elements.erase(it);
                else
                    it->value = value;
                return;
            }
        }
        if (value != 0)
            elements.push_back({row, col, value});
    }
    
    // Get an element's value (returns 0 if not stored)
    int get(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw std::out_of_range("Index out of range.");
        for (const auto &elem : elements)
            if (elem.row == row && elem.col == col)
                return elem.value;
        return 0;
    }
    
    // Display full matrix
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                std::cout << get(i, j) << " ";
            std::cout << std::endl;
        }
    }
    
    // Addition operator
    SparseMatrix operator+(const SparseMatrix &other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrix dimensions must agree for addition.");
        SparseMatrix result(rows, cols);
        // Add elements from the first matrix
        for (const auto &elem : elements)
            result.set(elem.row, elem.col, elem.value);
        // Add elements from the second matrix
        for (const auto &elem : other.elements)
            result.set(elem.row, elem.col, result.get(elem.row, elem.col) + elem.value);
        return result;
    }
    
    // Multiplication operator
    SparseMatrix operator*(const SparseMatrix &other) const {
        if (cols != other.rows)
            throw std::invalid_argument("Matrix dimensions incompatible for multiplication.");
        SparseMatrix result(rows, other.cols);
        // For each position in the result matrix, compute the sum product.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += this->get(i, k) * other.get(k, j);
                }
                if (sum != 0)
                    result.set(i, j, sum);
            }
        }
        return result;
    }
};

int main() {
    try {
        // ----- Dense Matrix Example -----
        std::cout << "Dense Matrix Example:" << std::endl;
        Matrix A(3, 3), B(3, 3);
        // Initialize A
        A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
        A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;
        A(2, 0) = 7; A(2, 1) = 8; A(2, 2) = 9;
        // Initialize B
        B(0, 0) = 9; B(0, 1) = 8; B(0, 2) = 7;
        B(1, 0) = 6; B(1, 1) = 5; B(1, 2) = 4;
        B(2, 0) = 3; B(2, 1) = 2; B(2, 2) = 1;
        
        std::cout << "Matrix A:" << std::endl;
        A.display();
        std::cout << "Matrix B:" << std::endl;
        B.display();
        
        Matrix sum = A + B;
        Matrix prod = A * B;
        
        std::cout << "A + B:" << std::endl;
        sum.display();
        std::cout << "A * B:" << std::endl;
        prod.display();
        
        // ----- Sparse Matrix Example -----
        std::cout << "\nSparse Matrix Example:" << std::endl;
        SparseMatrix S1(3, 3), S2(3, 3);
        // Initialize S1 with a few nonzero elements
        S1.set(0, 1, 2);
        S1.set(1, 0, 4);
        S1.set(2, 2, 5);
        
        // Initialize S2 with a few nonzero elements
        S2.set(0, 1, 3);
        S2.set(1, 2, 6);
        S2.set(2, 0, 7);
        
        std::cout << "Sparse Matrix S1:" << std::endl;
        S1.display();
        std::cout << "Sparse Matrix S2:" << std::endl;
        S2.display();
        
        SparseMatrix sSum = S1 + S2;
        SparseMatrix sProd = S1 * S2;
        
        std::cout << "S1 + S2:" << std::endl;
        sSum.display();
        std::cout << "S1 * S2:" << std::endl;
        sProd.display();
        
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
