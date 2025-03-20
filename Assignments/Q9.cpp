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

Polynomial add(const Polynomial& other) const{
	int maxdegree = max(degree,other.degree);
	cout<<"The maximum Degree is"<<maxdegree<<endl;
	int* sum=new int[maxdegree+1]();

	for(int i=0;i<=maxdegree;i++){	
		int coeff1=0;
		int coeff2=0;
		if(i<=degree){
			coeff1=poly[i];
		}
	
		if(i<=other.degree){
			coeff2=other.poly[i];
		}
	
		sum[i]=coeff1+coeff2;

	}
	
	Polynomial result(maxdegree,sum);
	delete[] sum;
	return result;
	}

Polynomial subtract(const Polynomial& other) const{
	int maxdegree = max(degree,other.degree);
	cout<<"The maximum Degree is"<<maxdegree<<endl;
	int* sum=new int[maxdegree+1]();

	for(int i=0;i<=maxdegree;i++){	
		int coeff1=0;
		int coeff2=0;
		if(i<=degree){
			coeff1=poly[i];
		}
	
		if(i<=other.degree){
			coeff2=other.poly[i];
		}
	
		sum[i]=coeff1-coeff2;

	}
	
	Polynomial result(maxdegree,sum);
	delete[] sum;
	return result;
	}


Polynomial multiply(const Polynomial& other) const{
	int maxdegree = max(degree,other.degree);
	int sumdegree=degree+other.degree-1; 
	cout<<"The maximum Degree is"<<sumdegree<<endl;
	int* product=new int[sumdegree+1]();

	for(int i=0;i<degree;i++){
	     for(int j=0;j<other.degree;j++){
		product[i+j]+=poly[i]*other.poly[j];
		}
	}
	
	Polynomial result(maxdegree,product);
	delete[] product;
	return result;
	}


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



int main(){
    
    int degree=4;
    int eq[degree]={1,2,3,9,9};
	
    int degree2=3;
    int eq2[degree2]={4,5,6,7};
 
    Polynomial poly1(degree,eq);
    Polynomial poly2(degree2,eq2);   

    poly1.display();
    poly2.display();

    Polynomial sum=poly1.add(poly2);
    
    cout<<"Sum of Polynomials"<<endl;
    sum.display();

    Polynomial product=poly1.multiply(poly2);
    cout<<"Product Of two Polynomials"<<endl;
    product.display();
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
	
