#include <iostream>
using namespace std;

class Complex{
	private:
		float real,img; //abstraction ke liye
	public:
		Complex(){ //constructor by default 0
			real=0;
			img=0;
		}
	Complex(float a,float b){ //argument wala contructor
		real=a;img =b;
	}

	Complex operator +(Complex const &c){ //+ ke liye overload kar rahe aur temp return kar rahe, same for others
		Complex temp;
		temp.real = real + c.real;
		temp.img = img + c.img;
		return temp;
	}

	Complex operator -(Complex const &c){
		Complex temp;
		temp.real = real - c.real;
		temp.img = img - c.img;
		return temp;
	}

	Complex operator *(Complex const &c){
		Complex temp;
		temp.real = (real*c.real)-(img*c.img);
		temp.img = (real*c.img)+(img*c.real);
		return temp;
	}

	Complex operator /(Complex const &c){
		Complex temp;
		temp.real = (real* c.real + img*c.img)/(c.real*c.real + c.img*c.img);
		temp.img = (img*c.real + real*c.img)/(c.real*c.real + c.img*c.img);
		return temp;
	}

	friend ostream &operator<<(ostream &o,Complex &c){ //output stream ko friend le rahe and << ko overload
		if(c.img<0){
			o<<c.real<<c.img<<"i"<<endl; // agar nahi karenge to 1-2i galat dikhega,1+-2i dikhega fir
		}
		else{
			o<<c.real<<"+"<<c.img<<"i"<<endl; //normal display hoga
		}
		return o;
	}

	friend istream &operator>>(istream&i,Complex &c){ //input stream ko dost banaya >> overlaod karke
		cout<<"Enter value of real part:"<<endl;
		i>>c.real;
		cout<<"Enter value of imaginary part"<<endl;
		i>>c.img;
		return i;
	}
};


int main()
{
	int operation; //jo operation karenge aur hamare declared variables
	bool cont = true;
	Complex a,b,add,subtract,multiply,div;
	while(cont){
		cout<<"Enter value of a"<<endl;
		cin>>a;
		cout<<a;
		cout<<"Enter value of b"<<endl;
		cin>>b;
		cout<<b;
		cout<<"Choose desired operation: \n 1.Add \n 2.Subtract \n 3.Multiply \n 4.Divide \n 5.Exit"<<endl; //menu
		cin>>operation;
		switch(operation){ //switch case to handle output
		case 1:
			add = a+b;
			cout<<add;
			break;
		case 2:
			subtract = a-b;
			cout<<subtract;
			break;
		case 3:
			multiply = a*b;
			cout<<multiply;
			break;
		case 4:
			div = a/b;
			cout<<div;
			break;
		case 5:
			cout<<"Byeeee"<<endl;
			cont = false;
			break;
		default:
			cout<<"Enter appropriate choice"<<endl;
		}

	}
	return 0;
}

