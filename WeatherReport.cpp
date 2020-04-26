#include<iostream>
using namespace std;

class weatherreport
{

	int day;
	float amtrain,amtsnow,lowtemp,hightemp;
	static float avgrain,avgsnow,avglowtemp,avghightemp,l;

public:
	weatherreport()
	{
		day=00.00;
		amtrain=99.00;
		amtsnow=99.00;
		lowtemp=-99.00;
		hightemp=99.00;		
	}
	void set(int d)
	{
		day=d;
		amtrain = get_amtrain();
		amtsnow = get_amtsnow();
		lowtemp = get_lowtemp();
		hightemp = get_hightemp(lowtemp);	
		
	}
	void display()
	{
		cout<<"\n "<<day<<"           "<<amtrain<<"           "<<amtsnow;
		cout<<"               "<<lowtemp<<"                "<<hightemp; 
	}
	void displayavg()
	{
		cout<<"\nday:"<<day<<"\namount of rain:"<<amtrain<<"\namount of snow:"<<amtsnow;
		cout<<"\nlowest temperature:"<<lowtemp<<"\nhighest temperatur:"<<hightemp; 
	}
	void average()
	{
		avgrain=avgrain+amtrain;
		avgsnow=avgsnow+amtsnow;
		avglowtemp=avglowtemp+lowtemp;
		avghightemp=avghightemp+hightemp;
		l++;		
	} 
	static void averagedisp()
	{
		avgrain=(avgrain/l);
		avgsnow=(avgsnow/l);
		avglowtemp=(avglowtemp/l);
		avghightemp=(avghightemp/l);
		cout<<"average="<<avgrain<<"\naverage snow="<<avgsnow;
		cout<<"\naverage low temperature="<<avglowtemp<<"\naverage high temp="<<avghightemp;
	}
	float get_amtrain()
	{
	    cout<<"\n please enter the amount of rain taking place: ";
		cin>>amtrain;
		while(amtrain<0 || amtrain>100)
		{
			cout<<"\nplease re-enter the value as you violated the condition:\n";
			cin>>amtrain;
		}
		return amtrain;
    }
    float get_amtsnow()
    {
        cout<<"\n please enter the amount of snow taking place: ";
		cin>>amtsnow;
		while(amtsnow<0 || amtsnow>100)
		{
			cout<<"\nplease re-enter the value as you violated the condition:\n";
			cin>>amtsnow;
		}
		return amtsnow;
	}
	float get_lowtemp()
	{
	    
		cout<<"\n please enter the lowest temperature of the day: ";
		cin>>lowtemp;
		while(lowtemp<(-50) || lowtemp>50)
		{
			cout<<"\nplease re-enter the value as you violated the condition:\n";
			cin>>lowtemp;
		}
		return lowtemp;
	}
	float get_hightemp(float low_temp)
	{
        cout<<"\n please enter the higest temperature of the day: ";
		cin>>hightemp;
		while(hightemp<0 || hightemp>100 || hightemp<=lowtemp)
		{
			cout<<"\nplease re-enter the value as you violated the condition:\n";
			cin>>hightemp;
		}
		return hightemp;
	}
        
        
	
};float weatherreport::l=0;float weatherreport::avgrain=0;float weatherreport::avgsnow=0;float weatherreport::avglowtemp=0;float weatherreport::avghightemp=0;



int main()
{
	int n,m,k=0,p,day;
	weatherreport w[30];
	while(k==0)
	{
		cout<<"\n\n----:Main Menu:------\n1.Input data\n2.display monthly data\n3.display for a single day\n4.Average\n5.Exit\n\nEnter your choice: ";
		cin>>m;
		switch(m)
		{
			case 1:
				cout<<"\nplease enter the number of days for which data is to be collected: ";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"enter the day: ";
					cin>>day;
					w[day-1].set(day);
					w[day-1].average();	
				}
			break;
			case 2:
				cout<<"\nday"<<" amount of rain"<<" amount of snow";
				cout<<" lowest temperature"<<" highest temperature";
				for(int i=0;i<30;i++)
				{
					w[i].display();	
				} 
					
			break;
			case 3:
				cout<<"please enter the day for which you want to display data: ";
				cin>>day;
				w[day].displayavg();
				break;
			case 4:
				weatherreport::averagedisp();
			break;
			case 5:
				k++; 
			break;	
	    }
    }
 	return 0;	
}

/*


----:Main Menu:------
1.Input data
2.display monthly data
3.display for a single day
4.Average
5.Exit

Enter your choice: 2

day amount of rain amount of snow lowest temperature highest temperature
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99

----:Main Menu:------
1.Input data
2.display monthly data
3.display for a single day
4.Average
5.Exit

Enter your choice: 1

please enter the number of days for which data is to be collected: 2
enter the day: 1

 please enter the amount of rain taking place: 67

 please enter the amount of snow taking place: 56

 please enter the lowest temperature of the day: 12

 please enter the higest temperature of the day: 34
enter the day: 4

 please enter the amount of rain taking place: 87

 please enter the amount of snow taking place: 98

 please enter the lowest temperature of the day: 12

 please enter the higest temperature of the day: 23


----:Main Menu:------
1.Input data
2.display monthly data
3.display for a single day
4.Average
5.Exit

Enter your choice: 2

day amount of rain amount of snow lowest temperature highest temperature
 1           67           56               12                34
 0           99           99               -99                99
 0           99           99               -99                99
 4           87           98               12                23
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99
 0           99           99               -99                99

----:Main Menu:------
1.Input data
2.display monthly data
3.display for a single day
4.Average
5.Exit

Enter your choice: 3
please enter the day for which you want to display data: 3

day:4
amount of rain:87
amount of snow:98
lowest temperature:12
highest temperatur:23

----:Main Menu:------
1.Input data
2.display monthly data
3.display for a single day
4.Average
5.Exit

Enter your choice: 4
average=77
average snow=77
average low temperature=12
average high temp=28.5

----:Main Menu:------
1.Input data
2.display monthly data
3.display for a single day
4.Average
5.Exit

Enter your choice: 5

*/
