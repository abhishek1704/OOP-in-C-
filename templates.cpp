#include<iostream>
using namespace std;

#define MAX 50	

template<class T>
class matrix
{	
	public:
	T mat[MAX][MAX];
	int row,col;

	public:
	
	void get(int row,int col)
	{
		int i,j;
		this->row = row;
		this->col = col;
		
		cout<<"Enter the elements of matrix:"<<endl;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cin>>mat[i][j];
			}
		}
	}
	
	void show()
	{
		int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	template<class U>
	friend matrix<U> operator+(matrix<U> m1,matrix<U> m2);
	
	template<class U>
	friend matrix<U> operator+(matrix<U> m1,matrix<U> m2);

	template<class U>
	friend matrix<U> operator*(matrix<U> m1,matrix<U> m2);
	
};


template<class U>
matrix<U> operator+(matrix<U> m1,matrix<U> m2)
{
	int i,j;

	matrix<U> temp;
	temp.row = m1.row;
	temp.col = m1.col;
	
	for(i=0;i<temp.row;i++)
	{
		for(j=0;j<temp.col;j++)
		{
			temp.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
		}
	}
	
	return temp;
}

template<class U>
matrix<U> operator-(matrix<U> m1,matrix<U> m2)
{
	matrix<U> temp;
	int i,j;
	temp.row = m1.row;
	temp.col = m1.col;
	
	for(i=0;i<temp.row;i++)
	{
		for(j=0;j<temp.col;j++)
		{
			temp.mat[i][j] = m1.mat[i][j] - m2.mat[i][j];
		}
	}
	
	return temp;
}

template <class U> 
matrix<U> operator*(matrix<U> m1,matrix<U> m2)
{
    int i=0,j=0,k=0;
	matrix<U> temp;
	int row = m1.row;
	int col = m1.col;
	
    for(i=0;i<row;i++)
    {
        for(j=0;j<m2.col;j++)
        {
        	temp.mat[i][j] = 0; 	
            for(k=0;k<col;k++)
            {
            	temp.mat[i][j]=temp.mat[i][j]+(m1.mat[i][k]*m2.mat[k][j]);
            }
        }
    }
    
    return temp;
} 

int main()
{
	matrix<int>m3;
	matrix<int>m1;
	matrix<int>m2;
	
	int i,j,row1,col1,row2,col2,ch;
	
	do
	{
		cout<<"\n__Main Menu__\n\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit"<<endl;
		cout<<"\nEnter your choice:"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Enter the rows and columns in matrix 1:";
				cin>>row1>>col1;
				cout<<"Enter the rows and columns in matrix 2:";
				cin>>row2>>col2;
				m1.get(row1,col1);
				m2.get(row2,col2);
				cout<<"\nMatrix 1:\n"<<endl;
				m1.show();
				cout<<"\nMatrix 2:\n"<<endl;
				m2.show();
				if(row1==row2 && col1==col2)
				{	m3 = m1 + m2;
					cout<<"\nAddition is:\n"<<endl;
					m3.show();}
				else
					cout<<"Addition is not possiblie !!"<<endl;
				break;
			
			case 2:
				cout<<"Enter the rows and columns in matrix 1:";
				cin>>row1>>col1;
				cout<<"Enter the rows and columns in matrix 2:";
				cin>>row2>>col2;
				m1.get(row1,col1);
				m2.get(row2,col2);
				cout<<"\nMatrix 1:\n"<<endl;
				m1.show();
				cout<<"\nMatrix 2:\n"<<endl;
				m2.show();
				if(row1==row2 && col1==col2)	
				{	cout<<"\nSubtraction is:\n"<<endl;
					m3 = m1 - m2;
					m3.show();}
				else
					cout<<"Subtraction is not possiblie !!"<<endl;				
				break;
				
			case 3:
				cout<<"Enter the rows and columns in matrix 1:";
				cin>>row1>>col1;
				cout<<"Enter the rows and columns in matrix 2:";
				cin>>row2>>col2;
				m1.get(row1,col1);
				m2.get(row2,col2);
				cout<<"\nMatrix 1:\n"<<endl;
				m1.show();
				cout<<"\nMatrix 2:\n"<<endl;
				m2.show();
				if(row1==col2 && row2==col1)
				{	m3 = m1*m2;
					cout<<"\nMultiplication is:\n"<<endl;
					m3.show();}
				else
					cout<<"Multiplication is not possiblie !!"<<endl;								
				break;
				
			case 4:
				break;
				
			default:
				cout<<"\nYou have entered a wrong choice!!"<<endl;
				break;
				
		}
		
	}while(ch!=4);
	
	return 0;
}
	
/*

---- Output ----


__Main Menu__

1.Addition
2.Subtraction
3.Multiplication
4.Exit

Enter your choice:
1
Enter the rows and columns in matrix 1:2 3
Enter the rows and columns in matrix 2:3 3
Enter the elements of matrix:
1
2
2
1
1
2
Enter the elements of matrix:
3
32
3
4
3
4
3
2
1

Matrix 1:

1 2 2 
1 1 2 

Matrix 2:

3 32 3 
4 3 4 
3 2 1 
Addition is not possiblie !!

__Main Menu__

1.Addition
2.Subtraction
3.Multiplication
4.Exit

Enter your choice:
1
Enter the rows and columns in matrix 1:3 3
Enter the rows and columns in matrix 2:3 3
Enter the elements of matrix:
1
1
1
1
1
1
1
2
1
Enter the elements of matrix:
2
3
2
1
2
2
1
1
2

Matrix 1:

1 1 1 
1 1 1 
1 2 1 

Matrix 2:

2 3 2 
1 2 2 
1 1 2 

Addition is:

3 4 3 
2 3 3 
2 3 3 

__Main Menu__

1.Addition
2.Subtraction
3.Multiplication
4.Exit

Enter your choice:
2
Enter the rows and columns in matrix 1:3 3 
Enter the rows and columns in matrix 2:3 3
Enter the elements of matrix:
1
2
3
4
3
4
2
3
4
Enter the elements of matrix:
3
4
5
3
4
5
4
5
4

Matrix 1:

1 2 3 
4 3 4 
2 3 4 

Matrix 2:

3 4 5 
3 4 5 
4 5 4 

Subtraction is:

-2 -2 -2 
1 -1 -1 
-2 -2 0 

__Main Menu__

1.Addition
2.Subtraction
3.Multiplication
4.Exit

Enter your choice:
3
Enter the rows and columns in matrix 1:3 3
Enter the rows and columns in matrix 2:3 3
Enter the elements of matrix:
1
1
1
1
1
1
1
1
1
Enter the elements of matrix:
11
1
1
1
1
1
1
1
1

Matrix 1:

1 1 1 
1 1 1 
1 1 1 

Matrix 2:

11 1 1 
1 1 1 
1 1 1 

Multiplication is:

13 3 3 
13 3 3 
13 3 3 

__Main Menu__

1.Addition
2.Subtraction
3.Multiplication
4.Exit

Enter your choice:
4

*/
