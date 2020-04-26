#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

#define max 50
class Base1
{
	protected:	
	char name[50],bgrp[5];
	int d,m,y;

	public	:	
	void getData1();
};

void Base1::getData1()
{
	cin.ignore();
	cout<<"\nName : ";
	cin.getline(name,50);
	cout<<"Blood Group : ";
	cin>>bgrp;
	cout<<"Date Of Birth :\n";
	do
	{
		cout<<"   Date  : ";
		cin>>d;
		if(d<1||d>31)
			cout<<"\nEnter CORRECT date..!!\n";
	}while(d<1||d>31);
	do
	{
		cout<<"   Month : ";
		cin>>m;
		if(m<1||m>12)
			cout<<"\nEnter CORRECT month..!!\n";
	}while(m<1||m>12);
	do
	{
		cout<<"   Year  : ";
		cin>>y;
		if(y<1900||y>2019)
			cout<<"\nEnter CORRECT year..!!\n";
	}while(y<1900||y>2019);
}

class Base2
{
	protected:	
	int height,weight;

	public	:
	void getData2();
};

void Base2::getData2()
{
	cout<<"Height : ";
	cin>>height;
	cout<<"Weight : ";
	cin>>weight;
}

class Base3
{
	protected:	
	long int polno;
	char add[50];

	public	:	
	void getData3();
};

void Base3::getData3()
{
	cin.ignore();
	cout<<"Address : ";
	cin.getline(add,50);
	cout<<"Insurance Policy No : ";
	cin>>polno;
}


class Derived:public Base1,public Base2,public Base3
{
	protected:	
	long int teleno,dlno;

	public	:	
	void getData4();
	void display(int i);
	void searchData(Derived D[max],char sch[50],int n);
	void modify(int n);
	int deleteData(Derived D[max],int d,int n);
};

void Derived::getData4()
{
	getData1();
	getData2();
	getData3();
	cout<<"Telephone No : ";
	cin>>teleno;
	cout<<"Driving License No : ";
	cin>>dlno;
}

void Derived::display(int i)
{
	cout<<setw(5)<<i+1;
	cout<<setw(15)<<name;
	cout<<setw(15)<<bgrp;
	cout<<setw(2)<<d<<"-"<<setw(2)<<m<<"-"<<setw(5)<<y;
	cout<<setw(8)<<height;
	cout<<setw(8)<<weight;
	cout<<setw(15)<<add;
	cout<<setw(17)<<polno;
	cout<<setw(16)<<teleno;
	cout<<setw(15)<<dlno<<endl;
}

void table()
{
    cout<<"| Sr no.|    name    | Blood_group  | Birthdate |  Height  | Weight |  Address  | Policy Number | Phone number | license number |"<<endl<<endl;
}

void Derived::searchData(Derived D[max],char sch[50],int n)
{
	int f=1,i;
	for(int i=0;i<n;i++)
	{
		if(!strcmp(sch,D[i].name))
		{	D[i].display(i);
			f=0;
		}	
	}
	if(f)
		cout<<"\nData NOT Found..!!\n";
}

void Derived::modify(int n)
{
	int ch;
	do
	{
		cout<<"\n<-------------MODIFY MENU ------------->";
		cout<<"\nWhat do u want to modify..??\n1) Name\n2) Blood Group\n3) DOB\n4) Height\n5) Weight\n6) Address\n7) Insurance Policy No.\n8) Telephone No.\n9) Driving License N0.\n10) Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	cin.ignore();
					cout<<"\nName : ";
					cin.getline(name,50);	
					break;
					
			case 2:	cout<<"Blood Group : ";
					cin>>bgrp;
					break;
					
			case 3:	cout<<"Date Of Birth :\n   Date  : ";
					cin>>d;
					cout<<"   Month : ";
					cin>>m;
					cout<<"   Year  : ";
					cin>>y;
					break;
					
			case 4:	cout<<"Height : ";
					cin>>height;
					break;
					
			case 5:	cout<<"Weight : ";
					cin>>weight;
					break;
					
			case 6:	cin.ignore();
					cout<<"Address : ";
					cin.getline(add,50);
					break;
					
			case 7:	cout<<"Insurance Policy No : ";
					cin>>polno;
					break;
					
			case 8:	cout<<"Telephone No : ";
					cin>>teleno;
					break;
					
			case 9:	cout<<"Driving License No : ";
					cin>>dlno;
					break;
					
			case 10:break;
			
			default:cout<<"\nEnter VALID Choice..!!\n";
		}
	}while(ch!=10);
	
	cout<<"\nData Modified Successfully..!!\n";
}

int Derived::deleteData(Derived D[max],int d,int n)
{
	int i;
	for(i=d-1;i<n-1;i++)
	{
		D[i]=D[i+1];
	}
	n--;
	cout<<"\nData Deleted Successfully..!!\n";
	return n;
}

int main()
{
	Derived D[max];
	int i,n=0,ch,md;
	char sch[50];

	do
	{
		cout<<"\nMenu :\n1. Build Master Table\n2. Display Records\n3. Insert Record\n4. Search Record\n5. Edit Record\n6. Delete Record\n7. Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"\nEnter No. of Records : ";
					cin>>n;
					for(i=0;i<n;i++)
						D[i].getData4();
					break;

			case 2:table();
					for(i=0;i<n;i++)
						D[i].display(i);
					break;

			case 3:	D[n].getData4();
					n++;
					break;

			case 4:	cin.ignore();
					cout<<"\nEnter Name to Search : ";
					cin.getline(sch,50);
					cout<<"\nSEARCH RESULT :\n";
					D[0].searchData(D,sch,n);
					break;

			case 5:	cin.ignore();
					cout<<"\nEnter Sr.No. of Data to Modify : ";
					cin>>md;
					D[md-1].modify(n);
					break;

			case 6:	cout<<"\nEnter Sr.No. of Data to Delete : ";
					cin>>md;
					n=D[0].deleteData(D,md,n);
					break;

			case 7:	break;

			default:cout<<"\nEnter VALID Choice..!!\n";
		}
	}while(ch!=7);
	return 0;
}

/*

----- Output -------


Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 1

Enter No. of Records : 3

Name : efeg
Blood Group : opos    
Date Of Birth :
   Date  : 2
   Month : 3
   Year  : 2000
Height : 123
Weight : 53
Address : hthth
Insurance Policy No : 54
Telephone No : 4646764
Driving License No : 646

Name : grgrh
Blood Group : opmft
Date Of Birth :
   Date  : 6
   Month : 5
   Year  : 2000
Height : 5
Weight : 75
Address : hthu
Insurance Policy No : 64
Telephone No : 647474
Driving License No : 646464

Name : fhtt
Blood Group : fht
Date Of Birth :
   Date  : 3
   Month : 4
   Year  : 2000
Height : 564
Weight : 35  
Address : httj
Insurance Policy No : 434
Telephone No : 5464646
Driving License No : 34353

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 2
| Sr no.|    name    | Blood_group  | Birthdate |  Height  | Weight |  Address  | Policy Number | Phone number | license number |

    1           efeg           opos 2- 3- 2000     123      53          hthth               54         4646764            646
    2          grgrh          opmft 6- 5- 2000       5      75           hthu               64          647474         646464
    3           fhtt            fht 3- 4- 2000     564      35           httj              434         5464646          34353

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 3

Name : grgr
Blood Group : hthtj
Date Of Birth :
   Date  : 3
   Month : 4
   Year  : 2000
Height : 646
Weight : 535
Address : hhr
Insurance Policy No : 64
Telephone No : 345353
Driving License No : 75744

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 2
| Sr no.|    name    | Blood_group  | Birthdate |  Height  | Weight |  Address  | Policy Number | Phone number | license number |

    1           efeg           opos 2- 3- 2000     123      53          hthth               54         4646764            646
    2          grgrh          opmft 6- 5- 2000       5      75           hthu               64          647474         646464
    3           fhtt            fht 3- 4- 2000     564      35           httj              434         5464646          34353
    4           grgr          hthtj 3- 4- 2000     646     535            hhr               64          345353          75744

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 4

Enter Name to Search : grgr

SEARCH RESULT :
    4           grgr          hthtj 3- 4- 2000     646     535            hhr               64          345353          75744

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 5

Enter Sr.No. of Data to Modify : 2

<-------------MODIFY MENU ------------->
What do u want to modify..??
1) Name
2) Blood Group
3) DOB
4) Height
5) Weight
6) Address
7) Insurance Policy No.
8) Telephone No.
9) Driving License N0.
10) Exit
Enter your choice : 5
Weight : 56

<-------------MODIFY MENU ------------->
What do u want to modify..??
1) Name
2) Blood Group
3) DOB
4) Height
5) Weight
6) Address
7) Insurance Policy No.
8) Telephone No.
9) Driving License N0.
10) Exit
Enter your choice : 10

Data Modified Successfully..!!

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 2
| Sr no.|    name    | Blood_group  | Birthdate |  Height  | Weight |  Address  | Policy Number | Phone number | license number |

    1           efeg           opos 2- 3- 2000     123      53          hthth               54         4646764            646
    2          grgrh          opmft 6- 5- 2000       5      56           hthu               64          647474         646464
    3           fhtt            fht 3- 4- 2000     564      35           httj              434         5464646          34353
    4           grgr          hthtj 3- 4- 2000     646     535            hhr               64          345353          75744

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 6

Enter Sr.No. of Data to Delete : 4

Data Deleted Successfully..!!

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 2
| Sr no.|    name    | Blood_group  | Birthdate |  Height  | Weight |  Address  | Policy Number | Phone number | license number |

    1           efeg           opos 2- 3- 2000     123      53          hthth               54         4646764            646
    2          grgrh          opmft 6- 5- 2000       5      56           hthu               64          647474         646464
    3           fhtt            fht 3- 4- 2000     564      35           httj              434         5464646          34353

Menu :
1. Build Master Table
2. Display Records
3. Insert Record
4. Search Record
5. Edit Record
6. Delete Record
7. Exit
Enter your choice : 7

*/
