#include<iostream>
using namespace std;

class divide
{
	double num,den;
	
	public:
		divide()
		{
			num = 0.0;
			den = 0.0;
		}

		void get()
		{
			cout<<"Enter the numerator: "<<endl;
			cin>>num;
			
			cout<<"Enter the denomenator: "<<endl;
			cin>>den;
		}

		void show()
		{
			cout<<"\nNumerator = "<<num;
			cout<<"\nDenomemator  = "<<den<<endl;
		}

		double division()
		{
			
			if(den==0)
			{
				throw "\nMath error:Attempted to divide by Zero";
			}
			else
				return num/den;
		}

};

int main()
{
	divide q;
	int ch;
	double d;

	do
	{	cout<<"\nMenu :\n\n1. Input data\n2. Display data\n3. Division\n4. Exit\n\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	
				q.get();
				break;

			case 2:
				q.show();
				break;

			case 3:	
				try
				{
					d = q.division();	
					cout<<"\nThe quotient is "<<d<<endl;							
				}
						
				catch(const char *e)
				{
					cout<<e<<endl<<"\nAn exception occured !!\n"<<endl;
				}
			
			case 4:	
				break;

			default:cout<<"\nEnter valid choice !!\n";
		}
		
	}while(ch!=4);
	
	return 0;
	
}

/*

-------output------


Menu :

1. Input data
2. Display data
3. Division
4. Exit

Enter your choice : 1
Enter the numerator: 
2
Enter the denomenator: 
4

Menu :

1. Input data
2. Display data
3. Division
4. Exit

Enter your choice : 2

Numerator = 2
Denomemator  = 4

Menu :

1. Input data
2. Display data
3. Division
4. Exit

Enter your choice : 3

The quotient is 0.5

Menu :

1. Input data
2. Display data
3. Division
4. Exit

Enter your choice : 1
Enter the numerator: 
3
Enter the denomenator: 
0

Menu :

1. Input data
2. Display data
3. Division
4. Exit

Enter your choice : 3

Math error:Attempted to divide by Zero

An exception occured !!


Menu :

1. Input data
2. Display data
3. Division
4. Exit

Enter your choice : 4
*/

