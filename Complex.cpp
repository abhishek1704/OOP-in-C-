#include<iostream>
using namespace std;

class complex
{
	float real,img;
	public:
		complex()
		{
			real = 0;
			img = 0;
		}
		
		void set()
		{
			cout<<"\nReal part:";
			cin>>real;
			cout<<"\nImaginary part:";
			cin>>img;
		}
		
		friend complex operator+(complex,complex);
		friend complex operator-(complex,complex);
		complex operator*(complex);
		complex operator/(complex);
		void operator=(complex);
		friend istream & operator>>(istream &in,complex &c);
		friend ostream & operator<<(ostream &out,const complex &c);		
		
		void show()
		{
			cout<<real<<" + ("<<img<<")i"<<endl;
		}
};

int main()
{
	complex c1,c2,c3,c4;
	c1.set();
	c2.set();	
	int k=0,ch,p;
	
	do
	{
		cout<<"\n--Main Menu--\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division"<<endl;
		cout<<"5.Insertion and Extraction\n6.EqualTo\n7.Exit"<<endl;
		cout<<"\nEnter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			c3 = c1 + c2;
			cout<<"\nAdition is : "<<endl;
			c3.show();
			break;
			
		case 2:
			c3 = c1 - c2;
			cout<<"\nSubtraction is : "<<endl;
			c3.show();
			break;
			
		case 3:
			c3 = c1*c2;
			cout<<"\nMultiplication is :"<<endl;
			c3.show();
			break;
			
		case 4:
			c3 = c1/c2;
			cout<<"\nDivision is :"<<endl;
			c3.show();
			break;
			
		case 5:
			cin>>c1;
			cout<<c1;
			break;
			
		case 6:
			c3 = c1;
			c3.show();
			cout<<endl;
			c4 = c2;
			c4.show();
			break;
			
		case 7:
			k++;
			break;
		}
		if(ch!=7)
		{
			cout<<"\nDo you want to continue?\nPress 1 if yes and 0 if no:"<<endl;
			cin>>p;
		}
			 
	}while(k==0 && p!=0);

	return 0;
}

complex operator+(complex c1,complex c2)
{
	complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	
	return temp;
}
	
complex operator-(complex c1,complex c2)
{
	complex temp;
	temp.real = c1.real - c2.real;
	temp.img = c1.img - c2.img;
		
	return temp;
}

complex complex::operator*(complex c)
{
	complex temp;
	temp.real = real*c.real - img*c.img;
	temp.img = real*c.img + c.real*img;
			
	return temp;
}	

complex complex::operator/(complex c)
{
	complex temp;
	temp.real = (real*c.real + img*c.img)/(c.real*c.real + c.img*c.img);
	temp.img = (c.real*img - real*c.img)/(c.real*c.real + c.img*c.img);
	
	return temp;
}

void complex::operator=(complex c1)
{
	real = c1.real;
	img = c1.img;
}

istream & operator >> (istream &in,complex &c)
{
	cout<<"Enter the real part:"<<endl;
	in>>c.real;
	cout<<"Enter the img part:"<<endl;
	in>>c.img;
	
	return in;
}

ostream & operator << (ostream &out,const complex &c)
{
	out<<"\nEntered complex number is:"<<endl;
	out<<c.real<<" + ("<<c.img<<")i"<<endl;
	
	return out;	
}

/*
----- Output --------

Real part:3

Imaginary part:2

Real part:4

Imaginary part:2

--Main Menu--
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Insertion and Extraction
6.EqualTo
7.Exit

Enter your choice: 
1

Adition is : 
7 + (4)i

Do you want to continue?
Press 1 if yes and 0 if no:
1

--Main Menu--
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Insertion and Extraction
6.EqualTo
7.Exit

Enter your choice: 
2

Subtraction is : 
-1 + (0)i

Do you want to continue?
Press 1 if yes and 0 if no:
1

--Main Menu--
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Insertion and Extraction
6.EqualTo
7.Exit

Enter your choice: 
3

Multiplication is :
8 + (14)i

Do you want to continue?
Press 1 if yes and 0 if no:
1

--Main Menu--
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Insertion and Extraction
6.EqualTo
7.Exit

Enter your choice: 
4

Division is :
0.8 + (0.1)i

Do you want to continue?
Press 1 if yes and 0 if no:
1

--Main Menu--
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Insertion and Extraction
6.EqualTo
7.Exit

Enter your choice: 
5
Enter the real part:
3
Enter the img part:
6

Entered complex number is:
3 + (6)i

Do you want to continue?
Press 1 if yes and 0 if no:
1

--Main Menu--
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Insertion and Extraction
6.EqualTo
7.Exit

Enter your choice: 
6
3 + (6)i

4 + (2)i

Do you want to continue?
Press 1 if yes and 0 if no:
1

--Main Menu--
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Insertion and Extraction
6.EqualTo
7.Exit

Enter your choice: 
7

*/
