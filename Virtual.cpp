#include<iostream>
using namespace std;

class shape
{
	protected:
		double x,y;
	public:
		void inputData(double x,double y)
		{
			this->x = x;
			this->y = y;
		}
		
		virtual void computeArea()=0;
		
};

class rect:public shape
{
	
	public:
		void computeArea()
		{
			cout<<"\nArea is: "<<x*y<<" sq.metre"<<endl;
		}	
};

class tri:public shape
{
	public:
		void computeArea()
		{
			cout<<"\nArea is: "<<0.5*x*y<<" sq.metre"<<endl;
		}
	
};

int main()
{
	int i,n,ch;
	double x,y;
	shape *ptr1,*ptr2;
	tri t;
	rect r;
	ptr1 = &t;
	ptr2 = &r;
	
	do
	{
		cout<<"\n\n--Main Menu--\n\n1.Area of rectangle\n2.Area of triangle\n3.Exit"<<endl;
		cout<<"\nEnter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the length:"<<endl;
				cin>>x;
				cout<<"\nEnter the breadth:"<<endl;
				cin>>y;
				ptr2->inputData(x,y);
				ptr2->computeArea();
				break;
				
			case 2:
				cout<<"\nEnter the base:"<<endl;
				cin>>x;
				cout<<"\nEnter the height:"<<endl;
				cin>>y;
				ptr1->inputData(x,y);
				ptr1->computeArea();
				break;
				
			case 3:
				break;
		}
		
	}while(ch!=3);
			
			
	return 0;
}

/*

------- Output ------

--Main Menu--

1.Area of rectangle
2.Area of triangle
3.Exit

Enter your choice:
1

Enter the length:
3

Enter the breadth:
2

Area is: 6 sq.metre


--Main Menu--

1.Area of rectangle
2.Area of triangle
3.Exit

Enter your choice:
2

Enter the base:
3.2

Enter the height:
3.21

Area is:5.136 sq.metre


--Main Menu--

1.Area of rectangle
2.Area of triangle
3.Exit

Enter your choice:
3

*/

