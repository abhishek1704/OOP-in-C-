
#include<iostream>
#include<string.h>
using namespace std;

class bookshop
{
    char *author,*publisher,*name;
    int *price,*stock;
    static int val,inv;
    
    public:
    bookshop()
    {
        author = new char[30];
        name = new char[30];
        publisher = new char[30];
        price = new int;
        stock = new int;
    }
    
    void add()
    {
        cin.ignore();
        cout<<"Enter the name of book:"<<endl;
        cin.getline(name,20);
        cout<<"Enter the name of author:"<<endl;
        cin.getline(author,20);
        cout<<"Enter the name of publisher:"<<endl;
        cin.getline(publisher,20);
        cout<<"Enter price:"<<endl;
        cin>>*price;
        cout<<"Enter number of books in stock:"<<endl;
        cin>>*stock;
    }
    
    void display_table()
    {
        cout<<"--------------------------------------------"<<endl;
        cout<<" Book\t Author\t Publisher  Price  stock "<<endl;
        cout<<"--------------------------------------------"<<endl;
    }
        
    
    void display()
    {        
        cout<<"  "<<name<<"\t  "<<author<<"\t  "<<publisher<<"\t    "<<*price<<"\t    "<<*stock<<endl; 
    }
    
    void search(char b[],char a[],int *flag)
    {
        int cmp,cmp1;

        cmp = strcmp(b,name);
        cmp1 = strcmp(a,author);
        
        if(cmp==0 && cmp1==0)
        {
            cout<<"Book found !!"<<endl;
            *flag = 1;
        }
    }
    
    int update(char b[],char a[])
    {
    	if(strcmp(b,name)==0 && strcmp(a,author)==0)
    	{	
    		cout<<"Book found !!"<<endl;
			cout<<"Enter the updation:"<<endl;
			cout<<"Enter the name of book:"<<endl;
			cin.ignore();
		    cin.getline(name,20);
		    cout<<"Enter the name of author:"<<endl;
		    cin.getline(author,20);
		    cout<<"Enter the name of publisher:"<<endl;
		    cin.getline(publisher,20);
		    cout<<"Enter price:"<<endl;
		    cin>>*price;
		    cout<<"Enter number of books in stock:"<<endl;
		    cin>>*stock;
		    return 1;
        } 
        else 
        	return 0;  
   }
   
   int purchase(char c[])
   {
   		int q;
		if(strcmp(c,name)==0)
		{
			cout<<"\nEnter the number of books you want to buy:";
			cin>>q;
			if(q<=*stock)
			{
				cout<<"\nso the amount of books you want is available\n";
				cout<<"the price is:"<<q*(*price)<<endl;
				val++;
				(*stock)-=q;
				return 1;
			}
			else
			{	
				inv++;
				cout<<"\ntransaction not possible";
				return 1;
			}
		}
		else 
		{
			return 0;
		}
	}
	
	static void valid()
	{
		cout<<"\n\nthe amount of valid transactions are:"<<val<<endl;
		cout<<"\nthe amount of invalid transactions are:"<<inv<<endl;
	}
	
	void delet()
	{
		delete price;
		delete stock;
		delete []publisher;
		delete []author;
		delete []name;
	}
             
};
    int bookshop::val=0;
	int bookshop::inv=0;

int main()
{
    bookshop *books[50];
    int i=0,k=0,n,ch,count=0,*flag,p=0,m;
    char b[20],a[20],bname[20],aname[20],c[20];
    
    flag = &p;
    do
    {
        cout<<"----- Main Menu-----\n"<<endl;
        cout<<"1.Add\n2.Update\n3.Search\n4.Purchase\n5.Exit\n"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
		    cout<<"Enter the number of books you want to add: ";
		    cin>>n;
		    for(i=0;i<n;i++)
		    {
		        books[i]=new bookshop;	

		    }
		    for(i=0;i<n;i++)
		    {
				books[i]->add();
		    }
		    
		    cout<<" Book\t Author\t Publisher  Price  stock "<<endl;
		    cout<<"--------------------------------------------------"<<endl;
		    for(i=0;i<n;i++)
		    {
		       books[i]->display();
		       count++;
		    }
        	break;
        
        case 2:
		    cin.ignore();
		    cout<<"Enter the name of the book to be updated: "<<endl;
		    cin.getline(bname,20);
		    cout<<"Enter the corresponding author name: "<<endl;
		    cin.getline(aname,20);
		    for(i=0;i<count;i++)
		    {
		    	n = books[i]->update(bname,aname);
		    	if(n==1)
		    	{
		    		break;
		    	}
		    }
		    if(n==0)
		    		cout<<"Book not found !!"<<endl;

		    for(i=0;i<count;i++)
		    {
		       books[i]->display();
		       
		    }		    
		    break;
		    	
        case 3:
		    cin.ignore();
		    cout<<"Enter the name of the book to search:"<<endl;
		    cin.getline(b,20);
		    cout<<"Enter corresponding author name:"<<endl;
		    cin.getline(a,20);
		   
		    for(i=0;i<count;i++)
		    {
		        books[i]->search(b,a,&p);
		        if(p==1){
		        books[i]->display_table();
		        books[i]->display();            
		        break;}  
		        
		    }
		    if(p==0){
		        cout<<"Book not found !!"<<endl; 
		        break;     
		    }
		    break; 
		    
		 case 4:
		 	cin.ignore();
			cout<<endl<<"\nplease enter the books title to be purchased:";				
			cin.getline(c,20);
			m=0;
			for(int j=0;j<count;j++)
			{
				m=books[j]->purchase(c);
				if(m==1)
				{
					break;
				}
			}
			if(m==0)
			{
				cout<<"\nthe name of title you entered was wrong\n";
			}
		 	break;
		 	
		 	case 5:
					bookshop::valid();
			break;
			case 6:
				for(int j=0;j<count;j++)
				{
					books[j]->delet();	
				}
				for(int j=0;j<i;j++)
				{
					delete books[j];	
				}
			break;	
		}              
        cout<<"\nDo you want to continue?\nPress 1 if yes and 0 if no.: ";
        cin>>k;
        
    }while(ch!=5 && k!=0);
       
    return 0;
}


/*

------ Output ----------

----- Main Menu-----

1.Add
2.Update
3.Search
4.Purchase
5.Exit

Enter your choice: 
1
Enter the number of books you want to add: 3
Enter the name of book:
grg  
Enter the name of author:
grgr
Enter the name of publisher:
ttt
Enter price:
454
Enter number of books in stock:
7
Enter the name of book:
hghb
Enter the name of author:
rg
Enter the name of publisher:
nth
Enter price:
43
Enter number of books in stock:
45
Enter the name of book:
nn
Enter the name of author:
tht
Enter the name of publisher:
hth
Enter price:
667
Enter number of books in stock:
8
 Book	 Author	 Publisher  Price  stock 
--------------------------------------------------
  grg	  grgr	  ttt	    454	    7
  hghb	  rg	  nth	    43	    45
  nn	  tht	  hth	    667	    8

Do you want to continue?
Press 1 if yes and 0 if no.: 1
----- Main Menu-----

1.Add
2.Update
3.Search
4.Purchase
5.Exit

Enter your choice: 
4


please enter the books title to be purchased:nn

Enter the number of books you want to buy:7

so the amount of books you want is available
the price is:4669

Do you want to continue?
Press 1 if yes and 0 if no.: 1
----- Main Menu-----

1.Add
2.Update
3.Search
4.Purchase
5.Exit

Enter your choice: 
3
Enter the name of the book to search:
grg
Enter corresponding author name:
grgr
Book found !!
--------------------------------------------
 Book	 Author	 Publisher  Price  stock 
--------------------------------------------
  grg	  grgr	  ttt	    454	    7

Do you want to continue?
Press 1 if yes and 0 if no.: 1
----- Main Menu-----

1.Add
2.Update
3.Search
4.Purchase
5.Exit

Enter your choice: 
2
Enter the name of the book to be updated: 
grgr
Enter the corresponding author name: 
grg
Book not found !!
--------------------------------------------
 Book	 Author	 Publisher  Price  stock 
--------------------------------------------
  grg	  grgr	  ttt	    454	    7
  hghb	  rg	  nth	    43	    45
  nn	  tht	  hth	    667	    1

Do you want to continue?
Press 1 if yes and 0 if no.: 1
----- Main Menu-----

1.Add
2.Update
3.Search
4.Purchase
5.Exit

Enter your choice: 
2  
Enter the name of the book to be updated: 
grg
Enter the corresponding author name: 
grgr
Book found !!
Enter the updation:
Enter the name of book:
ee
Enter the name of author:
gbgb
Enter the name of publisher:
tnth
Enter price:
565 
Enter number of books in stock:
6
--------------------------------------------
 Book	 Author	 Publisher  Price  stock 
--------------------------------------------
  ee	  gbgb	  tnth	    565	    6
  hghb	  rg	  nth	    43	    45
  nn	  tht	  hth	    667	    1

Do you want to continue?
Press 1 if yes and 0 if no.: 1
----- Main Menu-----

1.Add
2.Update
3.Search
4.Purchase
5.Exit

Enter your choice: 
3
Enter the name of the book to search:
ee
Enter corresponding author name:
gbgb
Book found !!
--------------------------------------------
 Book	 Author	 Publisher  Price  stock 
--------------------------------------------
  ee	  gbgb	  tnth	    565	    6


*/
