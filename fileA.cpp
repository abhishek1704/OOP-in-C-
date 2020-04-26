#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

int writeToFile()
{
	int i,n,flag=0;
	char name[20],sname[20];
	int rollNo;
	float per;
	
	ofstream fout;
	ifstream fin;
	
	fout.open("example.txt");
	cout<<"Enter the number of records you want to create:"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the roll no.: ";
		cin>>rollNo;
		cout<<"\nEnter the name: ";
		cin>>name;
		cout<<"\nEnter the percentage: ";
		cin>>per;
		fout<<setw(8)<<rollNo<<setw(12)<<name<<setw(15)<<per<<endl;		
	}	
	fout.close();
	return n;
}

void preDisplay()
{
	cout<<"\n|  Roll No.  |   Name   |  Percentage  |\n"<<endl;
	cout<<"__________________________________________\n"<<endl;
}

void display(int n)
{
	int i;
	char str[100];
	ifstream fin;
	fin.open("example.txt");
	preDisplay();
	
	for(i=0;i<n;i++)
	{
		fin.getline(str,100);
		cout<<str<<endl;
	}
}

int search(char key[])
{
	char roll[10],per[10];
	char name[100];
	ifstream fin("example.txt");
	
	while(!fin.eof())
	{
		fin>>roll;
		fin>>name;
		fin>>per;		
		
		if(!strcmp(key,roll))
		{
			fin.close();
			return 1;
		}	
	}
	
	fin.close();
	return 0;
}

int main()
{
	int n,m,ch;
	char roll[20];
	
	do
	{
		cout<<"\n__Main Menu__\n"<<endl;
		cout<<"1. Create record"<<endl;
		cout<<"2. Display record"<<endl;
		cout<<"3. Search record"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"\nEnter your choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				n = writeToFile();
				break;
				
			case 2:
				display(n);
				break;
				
			case 3:
				cout<<"Enter the roll no. to search:";
				cin>>roll;
				m = search(roll);
				if(m==1)
					cout<<"\nRecord found !!"<<endl;				
				else
					cout<<"\nRecord not found !!"<<endl;
					
				break;
				
			case 4:
				break;
			
			default:cout<<"Enter a valid choice..!!"<<endl;
		}
	}while(ch!=4);
	
	return 0;
}

/*

-------- Output --------


__Main Menu__

1. Create record
2. Display record
3. Search record
4. Exit

Enter your choice:1
Enter the number of records you want to create:
3

Enter the roll no.: 3

Enter the name: grgr

Enter the percentage: 76

Enter the roll no.: 4

Enter the name: htht

Enter the percentage: 87

Enter the roll no.: 12

Enter the name: grg

Enter the percentage: 79

__Main Menu__

1. Create record
2. Display record
3. Search record
4. Exit

Enter your choice:2

|  Roll No.  |   Name   |  Percentage  |

__________________________________________

       3        grgr             76
       4        htht             87
      12         grg             79

__Main Menu__

1. Create record
2. Display record
3. Search record
4. Exit

Enter your choice:3
Enter the roll no. to search:12

Record found !!

__Main Menu__

1. Create record
2. Display record
3. Search record
4. Exit

Enter your choice:3
Enter the roll no. to search:1

Record not found !!

__Main Menu__

1. Create record
2. Display record
3. Search record
4. Exit

Enter your choice:4
*/
