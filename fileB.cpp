#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

int create()
{
	char id[10],age[10];
	char name[100];
	fstream fout;
	fout.open("Database.txt",ios::app || ios::out);
	int N,i;
	cout<<"Enter number of students :";
	cin>>N;
	for(i=0;i<N;i++)
	{
		cout<<"\nEnter student ID: ";
		cin>>id;
		fout<<setw(4)<<id;
		cout<<"Enter name of student: ";
		cin.ignore();
		cin.getline(name,98);;
		fout<<setw(10)<<name;
		cout<<"Enter age: ";
		cin>>age;
		fout<<setw(7)<<age;
	}
	fout.close();	
	return N;
}

void display()
{
	char id[10],age[10];
	char name[100];
	ifstream fin("Database.txt");
	
	cout<<"\n|  ID   |  NAME  |   AGE  |\n"<<endl;
	cout<<"___________________________\n"<<endl;
	
	while(!fin.eof())
	{
		fin>>id;
		fin>>name;
		fin>>age;
		cout<<setw(4)<<id;
		cout<<setw(10)<<name;
		cout<<setw(7)<<age<<endl;	
	}

	fin.close();
}

int search(char key[])
{
	char id[10],age[10];
	char name[100];
	ifstream fin("Database.txt");
	while(1)
	{
		fin>>id;
		fin>>name;
		fin>>age;
		
		
		if(!strcmp(key,id))
		{
			fin.close();
			return 1;
		}	
	if(fin.eof())
		break;
	}
	
	fin.close();
	return 0;
}

void deleterec(char key[],int N)
{
	char id[30],prev[30]="0",name[30],age[10];
	char str[100];
	ifstream fin("Database.txt");
	ofstream fout("Temp.txt");
	int c=0;	
	int F=search(key);
	if(!F)
	{
		cout<<"Data NOT Found...!!\n";
		return;
	}
	while(!fin.eof())
	{
	
		c++;
		fin>>id;
		fin>>name;
		fin>>age;

		if(strcmp(id,key)!=0)
		{
			fout<<setw(4)<<id;
			fout<<setw(10)<<name;
			fout<<setw(7)<<age;
		}
	}
	fin.close();
	fout.close();
	
	fin.open("Temp.txt");
	fout.open("Database.txt");
	
	while(!fin.eof())
	{
		fin.getline(str,98);
		fout<<str;
	}
	
	remove("Temp.txt");
	cout<<"Deleted successfully...!!\n";
}

void modify(char key[],int N)
{
	char id[30],prev[30]="0",name[30],age[10];
	char str[100];
	ifstream fin("Database.txt");
	ofstream fout("Temp.txt");
	int c=0;	
	int F=search(key);
	if(!F)
	{
		cout<<"Data NOT Found !!\n";
		return;
	}
	while(!fin.eof())
	{
		c++;
		fin>>id;
		fin>>name;
		fin>>age;

		if(strcmp(id,key)!=0)
		{
			fout<<setw(4)<<id;
			fout<<setw(10)<<name;
			fout<<setw(7)<<age;
		}
		else
		{
			cout<<"Enter the modifications.."<<endl;
			cout<<"\nEnter student ID : ";
			cin>>id;
			fout<<setw(4)<<id;
			cout<<"Enter name : ";
			cin.ignore();
			cin.getline(name,98);;
			fout<<setw(10)<<name;
			cout<<"Enter age : ";
			cin>>age;
			fout<<setw(7)<<age<<endl;
		}
	}
	fin.close();
	fout.close();
	
	fin.open("Temp.txt");
	fout.open("Database.txt");
	
	while(!fin.eof())
	{
		fin.getline(str,98);
		fout<<str;
	}
	remove("Temp.txt");
	cout<<"\nRecord modified successfully !!\n";
}

int main()
{
	int N,i,j,ch,age;
	char name[100],id[10];
		ofstream fout;
	do
	{
		cout<<"\n__Main Menu__\n"<<endl;
		cout<<"1. Create record"<<endl;
		cout<<"2. Display records"<<endl;
		cout<<"3. Add records"<<endl;
		cout<<"4. Delete record"<<endl;
		cout<<"5. Modify record"<<endl;
		cout<<"6. Search record"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:				
				fout.open("Database.txt");
				fout.close();
				N=create();
				break;
				
			case 2:				
				display();
				break;
				
			case 3:			
				N=create();
				break;
				
			case 4:
				cout<<"Enter ID to be deleted :";
				cin.ignore();
				cin.getline(id,9);
				deleterec(id,N);
				break;
			
			case 5:
				cout<<"Enter ID to be modified :";
				cin.ignore();
				cin.getline(id,9);
				modify(id,N);
				break;
				
			case 6:	
				int F;
				cout<<"Enter ID to be searched :";
				cin.ignore();
				cin.getline(id,9);
				F=search(id);
				if(F)				
					cout<<"Data Found...!!\n";
				else
					cout<<"Data Not Found...!!\n";
				break;
			
			case 7:
				break;
				
			default :
				cout<<"Enter a valid choice !!\n";
		}
		
	}while(ch!=7);
	
	return 0;
}

/*

------- Output --------

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 1
Enter number of students :3

Enter student ID: 2
Enter name of student: thth
Enter age: 34

Enter student ID: 4
Enter name of student: hhtyh
Enter age: 5

Enter student ID: 5
Enter name of student: hthth
Enter age: 23

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 2

|  ID   |  NAME  |   AGE  |

___________________________

   2      thth     34
   4     hhtyh      5
   5     hthth     23

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 3
Enter number of students :1

Enter student ID: 12
Enter name of student: frgg
Enter age: 34

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 2

|  ID   |  NAME  |   AGE  |

___________________________

   2      thth     34
   4     hhtyh      5
   5     hthth     23
  12      frgg     34

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 4
Enter ID to be deleted :5
Deleted successfully...!!

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 3
Enter number of students :1

Enter student ID: 15
Enter name of student: btt
Enter age: 23

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 2

|  ID   |  NAME  |   AGE  |

___________________________

   2      thth     34
   4     hhtyh      5
  12      frgg     34
  15       btt     23

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 5
Enter ID to be modified :15
Enter the modifications..

Enter student ID : 23
Enter name : frgeg
Enter age : 25

Record modified successfully !!

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 2

|  ID   |  NAME  |   AGE  |

___________________________

   2      thth     34
   4     hhtyh      5
  12      frgg     34
  23     frgeg     25

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 6
Enter ID to be searched :4
Data Found...!!

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 6
Enter ID to be searched :34
Data Not Found...!!

__Main Menu__

1. Create record
2. Display records
3. Add records
4. Delete record
5. Modify record
6. Search record
7. Exit

Enter your choice : 7

