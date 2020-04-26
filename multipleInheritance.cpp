#include<iostream>
using namespace std;

class personalDetails
{
	protected:
	char name[30];
	char dob[10];
	char bloodGrp[10];
};

class profDetails
{
	protected:
	int yrsOfExp;
	char skill[30];	
};

class academicDetails
{
	protected:
	float degreePer;
	
};

class person:public personalDetails,public profDetails,public academicDetails
{
	public:
	void inputData()
	{
		cin.ignore();
		cout<<"Enter the name of the person:"<<endl;
		cin>>name;
		cout<<"Enter date of birth:"<<endl;
		cin>>dob;
		cout<<"Enter the blood group:"<<endl;
		cin>>bloodGrp;
		cout<<"Number of years of experience:"<<endl;
		cin>>yrsOfExp;
		cout<<"Enter any skill:"<<endl;
		cin>>skill;
		cout<<"Enter the degree percentile:"<<endl;
		cin>>degreePer;
	}
	
	void displayData()
	{
		int i=0;
		cout<<"  "<<i<<"\t "<<name<<"\t"<<dob<<"\t "<<bloodGrp<<"\t      "<<yrsOfExp<<"\t  "<<skill<<"\t   "<<degreePer<<endl;
	}
	
};


void preDisplay()
	{
		cout<<"\n| No.|   name   |  Date of Birth  | Blood Grp | YrsOfExp |  Skill  | Percentile |"<<endl;
		cout<<"___________________________________________________________________________________\n"<< endl;
	}
	

int main()
{
	int i,n,ch;
	person p[30];
	
	do
	{
		cout<<"\n--Main Menu--\n\n1.Input data\n2.Display data\n3.Exit"<<endl;
		cout<<"\nEnter your choice:"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
			cout<<"Enter the number of records you want to insert:"<<endl;
			cin>>n;
			for(i=0;i<n;i++)
				p[i].inputData();
				
			break;
			
			case 2:
			preDisplay();
			for(i=0;i<n;i++)
				p[i].displayData();
			
			case 3:
			break;
		}
	}while(ch!=3);
	
	return 0;
}

/*

------ Output ------


--Main Menu--

1.Input data
2.Display data
3.Exit

Enter your choice:
1
Enter the number of records you want to insert:
3
Enter the name of the person:
vbrr
Enter date of birth:
2/09/2000
Enter the blood group:
grgrgr
Number of years of experience:
4
Enter any skill:
grgrgh
Enter the degree percentile:
43

Enter the name of the person:
nthth
Enter date of birth:
2/3/2000
Enter the blood group:
rgrg
Number of years of experience:
5
Enter any skill:
ttjt
Enter the degree percentile:
45

Enter the name of the person:
grgrg
Enter date of birth:
2/04/2000
Enter the blood group:
yjyjy
Number of years of experience:
5 
Enter any skill:
thth
Enter the degree percentile:
34

--Main Menu--

1.Input data
2.Display data
3.Exit

Enter your choice:
2

| No.|   name   |  Date of Birth  | Blood Grp | YrsOfExp |  Skill  | Percentile |
___________________________________________________________________________________

  0	 vbrr	2/09/2000	 grgrgr	      4	  grgrgh	   43
  0	 nthth	2/3/2000	 rgrg	      5	  ttjt	   45
  0	 grgrg	2/04/2000	 yjyjy	      5	  thth	   34

--Main Menu--

1.Input data
2.Display data
3.Exit

Enter your choice:
3



	
