#include <iostream>
using namespace std;

class Matrix{
  private:
	//Declares a pointer to a pointer of float.This will be later used to create a 2D array dynamically.
	float **_mat;
	//These variables store the number of rows and columns in the matrix respectively.
	int _rows;
	int _cols;

  public:
	//Constructor of the matrix class
	Matrix(int r,int c):_rows(r),_cols(c){
		//Dynamically allocates an array of float * with size equal to _rows.This will serve as the array of row pointers
		_mat=new float*[_rows];
		//Begins a loop that iterates over each row of the matrix
		for(int i=0;i<_rows;i++){
			//For each row i,dynamically allocates an array of floats with size equal to _cols.This effectively creates a 2D array by allocating for each row
			_mat[i]=new float[_cols];
		}
	}
	
	//A constant memeber function that returns the number of rows in the matrix.The const keyword indicates that this function does not modify the object
	int rows() const {return _rows;}
	//Similarly this function returns the number of cols in the matrix 
	int cols() const {return _cols;}	

	//Destructor of the matrix class.It is automatically called when an object of the class is destroyed and is responsible for freeing any dynamically allocated memory
	~Matrix(){
	  for(int i=0;i<_rows;i++){
		//Frees the memory allocated for the ith row.The delete[] operator is used because each row was allocated as an array
		delete [] _mat[i];
		}
		//After all rows are deallocated, this frees the memory allocated the array of row pointers
		delete [] _mat;
	}
	

	Matrix add(const Matrix& other){
		if (_rows != other._rows || _cols != other._cols) {
        		throw invalid_argument("Matrix dimensions must be the same for addition.");
   		}	
		
		Matrix sum(_rows,_cols);	
		for(int i=0;i<_rows;i++){
		    for(int j=0;j<_cols;j++){
			sum[i][j]=_mat[i][j]+other._mat[i][j];
			
			}
		}
		
		return sum;
	}
		
	Matrix subtract(const Matrix& other){
		if (_rows != other._rows || _cols != other._cols) {
        		throw invalid_argument("Matrix dimensions must be the same for addition.");
   		}	
		
		Matrix sum(_rows,_cols);	
		for(int i=0;i<_rows;i++){
		    for(int j=0;j<_cols;j++){
			sum[i][j]=_mat[i][j]-other._mat[i][j];
			
			}
		}
		
		return sum;
	}
	
        Matrix multiply(const Matrix& other) {
	    if (_cols != other._rows) {
        	throw invalid_argument("Matrix dimensions must match for multiplication.");
    		}

    	   Matrix product(_rows, other._cols);

    		for (int i = 0; i < _rows; i++) {
        		for (int j = 0; j < other._cols; j++) {
            			product[i][j] = 0; // Initialize product cell
            			for (int k = 0; k < _cols; k++) { // _cols == other._rows
                			product[i][j] += _mat[i][k] * other._mat[k][j]; // Proper multiplication formula
            			}
        		}
    		}

    		return product;
	   }		


	//Overloads the subscript operator[] to allow direct access to the rows of the matrix.This returns a reference to the pointer at index i.This enables syntax like m[i][j] to acess elements
	float*& operator[](const int i){return _mat[i];}
	
	//Declares a friend function that overloads the insertion operator << for outputting a matrix object.Being a friend allows the function to access private members of matrix.
	friend ostream& operator<<(ostream& out,const Matrix& m){
		for(int i=0;i<m.rows();i++){
		    for(int j=0;j<m.cols();j++){
			out<<" "<<m._mat[i][j];
			}
			out<<endl;
		}
		return out;
		
	}


};

int main(){
	//Creates an object m of type Matrix with 4 rows and 5 columns by calling the constructor.Memory for a 4x5 matrix is dynamically allocated1
	Matrix m1(4, 5);
    	Matrix m2(4, 5);

	for(int i=0;i<m1.rows();i++){
	    for(int j=0;j<m1.cols();j++){
		m1[i][j]=i+j+1;
		}
	}

	for (int i = 0; i < m2.rows(); i++) {
        	for (int j = 0; j < m2.cols(); j++) {
            		m2[i][j] = (i + 1) * (j + 1);  // Example: m2 contains a multiplication pattern
        	}
    	}
	
	//Uses the overloaded operator to print the matrix m to the standard output
	cout << "Matrix 1:\n" << m1;
    	cout << "Matrix 2:\n" << m2;
	
	Matrix result = m1.subtract(m2);
        cout << "Multiplication of Matrices:\n" << result;
	return 0;
	}



