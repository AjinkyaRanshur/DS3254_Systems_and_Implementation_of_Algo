//Q9 Implement a class for Polynomials.
//Q10 Implement a class for Matrices.

#include <iostream>
using namespace std;


class Complex{
private:
      double real; //to store the real part of the complex number
      double imag; //to store the imaginary part of the complex number

public:
//Constructor with the default parameter. If no arguments are provided,it creates 0+0i
Complex(double r=0,double i=0):real(r),imag(i){}

~Complex(){ } // Destructor (empty in this case since there is no dynamic memory).

//Method to display the Complex number
void display() const{
     cout<<real;
     if(imag >=0){
	cout <<"+"<< imag<<"i"<< endl;
	}
     else{
	cout <<"-"<<-imag<<"i"<<endl;
	}
}

Complex add (const Complex& other) const{
   return Complex(real +other.real,imag+other.imag);
}

Complex subtract(const Complex& other) const{
   return Complex(real-other.real,imag - other.imag);
}

Complex multiply(const Complex& other) const{
   return Complex(real * other.real - imag * other.imag,real*other.imag + imag* other.real);
}

};

class Polynomial{

private:
    int degree;
    int *poly;	

public:
//Constructor with the default parameter. Used to define an array
Polynomial(int deg=0,int eq[]=nullptr){
	degree=deg;
	poly=new int[degree+1];
	for(int i=0;i<=degree;i++){
		poly[i]=eq[i];
		}
}

~Polynomial() {
	delete[] poly;
	}


Polynomial() {}

void display() {
	for(int i=0;i<=degree;i++){
		if(i>0){
		cout << poly[i];
		cout <<"x^"<< i;
		}
		else{
		cout <<poly[i];
		}
		if (i != degree){
		cout<<"+";
		}
		}

	cout << endl;
	}




};

//class Matrices{
//}

int main(){
    
    int degree=2;
    int eq[degree]={1,2,3};
 
    Polynomial poly(degree,eq);
    poly.display();
    
    //Creating two Complex Numbers
    //Complex c1(3,4);
    //Complex c2(1,-2);
    
    //Display the complex numbers
    //cout <<"First Complex Numbers: ";
    //c1.display();

    //cout <<"Second Complex Numbers: ";
    //c2.display();

    //Complex sum=c1.add(c2);
    //cout << "Sum: ";
    //sum.display();

    //Complex diff=c1.subtract(c2);
    //cout << "Difference: ";
    //diff.display();


    return 0;

}
	
