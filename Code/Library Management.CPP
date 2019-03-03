/* Following source code on titled "LIBRARY MANAGEMENT" belongs to 

				*	RAHUL

This program is complied in                  DEV-CPP_5.6.3

*/


#include<iostream>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

void dispchar(char a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a;
	}
}



//Function welcome will display "WELCOME TO LIBRARY" 

void welcome()
{
      dispchar('*',96);
      cout<<"\n\t\tÛÛ     ÛÛ      ";
      cout<<"\n\t\tÛÛ     ÛÛ ÛÛÛÛÛÛÛ ÛÛ      ÛÛÛÛÛÛ  ÛÛÛÛÛÛÛ ÛÛÛ   ÛÛÛ ÛÛÛÛÛÛÛ ";
      cout<<"\n\t\tÛÛ     ÛÛ ÛÛ      ÛÛ      ÛÛ      ÛÛ   ÛÛ ÛÛ ÛÛÛ ÛÛ ÛÛ      ";
      cout<<"\n\t\tÛÛ  Û  ÛÛ ÛÛÛÛÛ   ÛÛ      ÛÛ      ÛÛ   ÛÛ ÛÛ  Û  ÛÛ ÛÛÛÛÛ   ";
      cout<<"\n\t\tÛÛ ÛÛÛ ÛÛ ÛÛ      ÛÛ      ÛÛ      ÛÛ   ÛÛ ÛÛ     ÛÛ ÛÛ      ";
      cout<<"\n\t\tÛÛÛ   ÛÛÛ ÛÛÛÛÛÛÛ ÛÛÛÛÛÛÛ ÛÛÛÛÛÛ  ÛÛÛÛÛÛÛ ÛÛ     ÛÛ ÛÛÛÛÛÛÛ ";
      
      
    cout<<"\n\n\t\t\t           ÛÛÛÛÛÛÛÛ  ÛÛÛÛÛ    ";
      cout<<"\n\t\t\t              ÛÛ     Û   Û    ";
      cout<<"\n\t\t\t              ÛÛ     ÛÛÛÛÛ    ";
      
      
      cout<<"\n\t\t    ÛÛ                                                ";
      cout<<"\n\t\t    ÛÛ      ÛÛ ÛÛÛÛÛÛÛ ÛÛÛÛÛÛ    ÛÛ    ÛÛÛÛÛÛ ÛÛ    ÛÛ";
      cout<<"\n\t\t    ÛÛ      ÛÛ ÛÛ   ÛÛ ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛ ";
      cout<<"\n\t\t    ÛÛ      ÛÛ ÛÛÛÛÛ   ÛÛÛÛ    ÛÛÜÜÛÛ  ÛÛÛÛ      ÛÛ   ";
      cout<<"\n\t\t    ÛÛ      ÛÛ ÛÛ   ÛÛ ÛÛ ÛÛ  ÛÛ    ÛÛ ÛÛ ÛÛ     ÛÛ   ";
      cout<<"\n\t\t    ÛÛÛÛÛÛÛ ÛÛ ÛÛÛÛÛÛÛ ÛÛ  ÛÛ ÛÛ    ÛÛ ÛÛ  ÛÛ    ÛÛ \n";
      
      dispchar('*',96);
      cout<<"\n\t\t\t\t       LIBRARY MANAGEMENT CS PROJECT BY  :-\n";
      cout<<"\n\t\t\t\t*  RAHUL"<<"\t\t  XII - C\t\t ";
      getch();
	system("cls");
}



void introduction()
{
	system("cls");
	
	dispchar('*',96);
	cout<<"\n\t\t\t\tSOME THINGS YOU SHOULD KNOW\n";
	dispchar('*',96);
	
	cout<<"\n\n\n1: While writing a record use '_' insted of using spacebar between the words. \n\n";
	cout<<"\tEg : Write 'WELCOME_TO_LIBRARY' insted of WELCOME TO LIBRARY\n\n\n";
	
	cout<<"2: While entering the date , write the date one after other.\n\n";
	cout<<"\tEg : Date_Format(DD MM YYYY)\n\n\tDate(DD) : 25\n\tMonth(MM) : 09\n\tYear(YYYY) : 2015\n\n\n";
	
	cout<<"3: While changing the password a MASTER PASSWORD is required. \n\n";
	
	dispchar('-',96);
	
	cout<<"\n\n";
	system("pause");
}



//Creating structure of date which will take input of issue date & deposit date

struct date
{
	int day;
	int month;
	int year;
};



/*
Class library will take data from librarian if
1:A new book is came to library
2:A book got damage
*/


class library
{
	public:
	int book_no;
	char book_name[40];
	char author[30];
	int year_of_publication;
	int price;					//for damaged book it will use as fine

	public:
		void display_books();
		void input_book_detail(int x);
};



//Class issue will take input data if a student want to issue a book

class issue
{
	public:
	char sd_name[20];
	int clas;
	char sec[1];
	int roll;
	int book_no;
	char book_name[25];
	date d_issued;

		void issuing_book();
};



//Class issue will take input data if a student want to deposit a book

class deposit
{
	public:
	char sd_name[20];
	int clas;
	char sec[1];
	int roll;
	int book_no;
	char book_name[25];
	date d_issued;
	date d_deposite;

	void deposit_book(int b_no);
};



/*
Function input_book_detail(int x) will takes data of new as well as damaged book
			and will store in txt file
If value passed to function will be 3 than it will take input of new books
If value passed to function will be 4 than it will take input of damaged books
*/

void library::input_book_detail(int x)
{
	system("cls");
	
	library s1;
	
	ofstream fdamage,ftotal;
	fdamage.open("Books\\damaged.txt",ios::app|ios::binary);
	ftotal.open("Books\\total.txt",ios::app|ios::binary);
	
	dispchar('*',96);
	cout<<"\n\t\t\t\tENTER DETAILS OF BOOK\n";
	dispchar('*',96);
		
	cout<<"\n\n\n";
	cout<<"1.Book_No : ";
	cin>>s1.book_no;
	cout<<"2.Book_Name : ";
	cin>>s1.book_name;
	cout<<"3.Author : ";
	cin>>s1.author;
	cout<<"4.Year_Of_Publication : ";
	cin>>s1.year_of_publication;
	
	if(x==3)
	{
		cout<<"5.Price : ";
		cin>>s1.price;
	}
	else
	{
		cout<<"5.Fine : ";
		cin>>s1.price;
	}
	if(x==3)
	{
		ftotal.write((char*)&s1,sizeof(s1));
		ftotal.close();
		cout<<"\n\n";
		system("pause");
	}
	else if(x==4)
	{
		fdamage.write((char*)&s1,sizeof(s1));
		fdamage.close();
		cout<<"\n\n";
		system("pause");
	}
	else
	cout<<"\n\nINVALID INPUT";
	
}



/*
Function issuing_book() will takes data of issuing book
		and will store in txt file
*/

void issue::issuing_book()
{
	library l;
	issue s1;
	
	int b_no,count=0;
	
	ofstream fout;
	ifstream ftotal;
	fout.open("Books\\issued.txt",ios::app|ios::binary);
	ftotal.open("Books\\total.txt",ios::app|ios::binary);
	
	dispchar('*',96);
	cout<<"\n\t\t\t\tENTER DETAILS OF ISSUING BOOK\n";
	dispchar('*',96);
	
	cout<<"\n\nBook no : ";
	cin>>b_no;
	
	while(ftotal.read((char*)&l,sizeof(l)))
	{
		if(l.book_no==b_no)
		{
			cout<<"\n\n";
			cout<<"1.Student Name : ";
			cin>>s1.sd_name;
			cout<<"2.Class : ";
			cin>>s1.clas;
			cout<<"3.Sec : ";
			cin>>s1.sec;
			cout<<"4.Roll : ";
			cin>>s1.roll;
			s1.book_no=b_no;
			strcpy(s1.book_name,l.book_name);
			cout<<"\n7.Date_Of_Issue(DD MM YYYY)\n\n";
			cout<<"\tDate(DD) : ";
			cin>>s1.d_issued.day;
			cout<<"\tMonth(MM) : ";
			cin>>s1.d_issued.month;
			cout<<"\tYear(YYYY) : ";
			cin>>s1.d_issued.year;
	
			fout.write((char*)&s1,sizeof(s1));
			fout.close();
			count=1;
		}
	}
	
	if(count==0)
	{
		cout<<"\n\nBook having book no. "<<b_no<<" is not present in the library\n\n\n";
	}
	
	system("pause");
}



/*
Function deposit_book(int b_no) will takes 
		
" book no & date to deposit only "
		
and rest data will copy fron issude data
and than it will store in txt file
*/

void deposit::deposit_book(int b_no)
{
	int count=0;
	issue s1;
	deposit s2;
	
	ifstream fin;
	ofstream fout,ftemp,extra;
	fout.open("Books\\deposit.txt",ios::app|ios::binary);
	fin.open("Books\\issued.txt",ios::in|ios::binary);
	ftemp.open("Books\\temp.txt",ios::app|ios::binary);
	
	while(fin.read((char*)&s1,sizeof(s1)))
	{
		if(s1.book_no==b_no)
		{
			strcpy(s2.sd_name , s1.sd_name);
			s2.clas = s1.clas;
			strcpy(s2.sec , s1.sec);
			s2.roll = s1.roll;
			s2.book_no = s1.book_no;
			strcpy(s2.book_name , s1.book_name);
			s2.d_issued.day = s1.d_issued.day;
			s2.d_issued.month = s1.d_issued.month;
			s2.d_issued.year = s1.d_issued.year;
	
			cout<<"\n   7.Date_Of_Deposit(DD MM YYYY)\n\n";
			cout<<"\t   Date(DD) : ";
			cin>>s2.d_deposite.day;
			cout<<"\t   Month(MM) : ";
			cin>>s2.d_deposite.month;
			cout<<"\t   Year(YYYY) : ";
			cin>>s2.d_deposite.year;
			fout.write((char*)&s2,sizeof(s2));
			fout.close();
			count++;
		}
		else
		{
			ftemp.write((char*)&s1,sizeof(s1));
		}
	}
	
	fin.close();
	ftemp.close();
	extra.open("Books\\issued.txt",ios::out|ios::binary);
	extra.close();
	
	rename("Books\\issued.txt","Books\\abc.txt");
	rename("Books\\temp.txt","Books\\issued.txt");
	rename("Books\\abc.txt","Books\\temp.txt");
	
	if(count<1)
	{
		cout<<"\n\n\n\t\tBook Has not been issued\n";
	}
	
	system("pause");
}



//Function modify() will modify the issued books data only

void modify()
{
	int b_no,count=0;
	
	issue s1;
	
	ifstream fissued;
	ofstream ftemp,extra;
	fissued.open("Books\\issued.txt",ios::in|ios::binary);
	ftemp.open("Books\\temp.txt",ios::app|ios::binary);
	
	dispchar('*',96);
	cout<<"\n\t\t\tENTER DETAILS OF ISSUED BOOK TO MODIFY\n";
	dispchar('*',96);
	
	cout<<"\nModify data of issued book\n";
	cout<<"\nEnter Book no. which has to be modified : ";
	cin>>b_no;
	
		while(fissued.read((char*)&s1,sizeof(s1)))
		{
			if(b_no==s1.book_no)
			{
				cout<<"\nEnter Details\n\n";
				cout<<"1.Student Name : ";
				cin>>s1.sd_name;
				cout<<"2.Class : ";
				cin>>s1.clas;
				cout<<"3.Sec : ";
				cin>>s1.sec;
				cout<<"4.Roll : ";
				cin>>s1.roll;
				s1.book_no=b_no;
				cout<<"5.Book_name : ";
				cin>>s1.book_name;
				cout<<"\n6.Date_Of_Issue(DD MM YYYY)\n\n";
				cout<<"\tDate(DD) : ";
				cin>>s1.d_issued.day;
				cout<<"\tMonth(MM) : ";
				cin>>s1.d_issued.month;
				cout<<"\tYear(YYYY) : ";
				cin>>s1.d_issued.year;
				ftemp.write((char*)&s1,sizeof(s1));
				count++;
			}
			else
			{
				ftemp.write((char*)&s1,sizeof(s1));
			}
		}
		
		fissued.close();
		ftemp.close();
			extra.open("Books\\issued.txt",ios::out|ios::binary);
			extra.close();
			rename("Books\\issued.txt","Books\\abc.txt");
			rename("Books\\temp.txt","Books\\issued.txt");
			rename("Books\\abc.txt","Books\\temp.txt");
		
		if(count<1)
		{
			cout<<"\nBook not found\n";
		}
		
	system("pause");
}



//Function delet() will delete the library books data

void delet()
{
	int b_no,count=0;
	
	library s1;
	
	ifstream ftotal;
	ofstream ftemp,extra;
	ftotal.open("Books\\total.txt",ios::app|ios::binary);
	ftemp.open("Books\\temp.txt",ios::app|ios::binary);
	
	cout<<"\nDelete data of a book\n";
	cout<<"\nEnter Book no. which has to be delete : ";
	cin>>b_no;
	
	while(ftotal.read((char*)&s1,sizeof(s1)))
	{
		if(b_no==s1.book_no)
		{
			cout<<"\n\n\t\tData of '"<<s1.book_name<<"' having Book no. : "<<s1.book_no<<" has been deleted from record";
			count++;
			cout<<"\n\n";
		}
		else
		{
			ftemp.write((char*)&s1,sizeof(s1));
		}
	}
	ftotal.close();
		ftemp.close();
			extra.open("Books\\total.txt",ios::out|ios::binary);
			extra.close();
			
			rename("Books\\total.txt","Books\\abc.txt");
			rename("Books\\temp.txt","Books\\total.txt");
			rename("Books\\abc.txt","Books\\temp.txt");
		
		if(count<1)
		{
			cout<<"\nBook not found\n";
		}
	
			system("pause");
}



/*
Function will display 
1:All books of library details
2:Issued books details
3:Deposit books details
4:Damage books details
*/

void library::display_books()
{
	int choice;
	
	library s1;
	issue s2;
	deposit s3;
	
	ifstream ftotal,fissued,fdamaged,fdeposit;
	ftotal.open("Books\\total.txt",ios::app|ios::binary);
	fissued.open("Books\\issued.txt",ios::app|ios::binary);
	fdamaged.open("Books\\damaged.txt",ios::app|ios::binary);
	fdeposit.open("Books\\deposit.txt",ios::app|ios::binary);
	
	dispchar('*',96);
	cout<<"\n\t\t\t\t\tWHAT DO YOU WANT TO SEE\n";
	dispchar('*',96);
	
	cout<<"\n\n1:List of all books\n2:List of issued books\n3:List of deposited books\n4:List of damaged books\t";
	cin>>choice;
	
	if(choice==1)
	{
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t   LIST OF ALL BOOKS OF LIBRARY\n";
		dispchar('*',96);
		
		cout<<"\n\n\nBook_no \tBook_name\tAuthor\tYear_of_publication\tPrice\n\n";
		while(ftotal.read((char*)&s1,sizeof(s1)))
		{
		       cout<<s1.book_no<<"\t\t"<<s1.book_name<<"\t\t"<<s1.author<<"\t\t"<<s1.year_of_publication<<"\t\t"<<s1.price<<"\n";
		}
		ftotal.close();
	}
	else if(choice==2)
	{
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t\tLIST OF ISSUED BOOKS\n";
		dispchar('*',96);
		
		cout<<"\n\n\nName\t\tClass Sec\tRoll\tBook_no\tBook_name\tdate_of_issue\n\n";
		while(fissued.read((char*)&s2,sizeof(s2)))
		{
		       cout<<s2.sd_name<<"\t\t"<<s2.clas<<" "<<s2.sec<<"\t\t"<<s2.roll<<"\t"<<s2.book_no<<"\t"<<s2.book_name<<"\t   "<<s2.d_issued.day<<"-"<<s2.d_issued.month<<"-"<<s2.d_issued.year<<"\n";
		}
		fissued.close();
	}
	else if(choice==3)
	{
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t\tLIST OF DEPOSIT BOOKS\n";
		dispchar('*',96);
		
		cout<<"\n\n\nName\t\tClass Sec\tRoll\tBook_no\tBook_name\tdate_of_issue\tdate_of_deposit\n\n";
		while(fdeposit.read((char*)&s3,sizeof(s3)))
		{
		       cout<<s3.sd_name<<"\t\t"<<s3.clas<<" "<<s3.sec<<"\t\t"<<s3.roll<<"\t"<<s3.book_no<<"\t"<<s3.book_name<<"\t\t"<<s3.d_issued.day<<"-"<<s3.d_issued.month<<"-"<<s3.d_issued.year<<"\t"<<s3.d_deposite.day<<"-"<<s3.d_deposite.month<<"-"<<s3.d_deposite.year<<"\n";
		}
		fdeposit.close();
	}
	else if(choice==4)
	{
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\tLIST OF DAMAGED BOOKS\n";
		dispchar('*',96);
		
		cout<<"\n\n\nBook_no \tBook_name\tAuthor\tYear_of_publication\tFine\n\n";
		while(fdamaged.read((char*)&s1,sizeof(s1)))
		{
		       cout<<s1.book_no<<"\t\t"<<s1.book_name<<"\t\t"<<s1.author<<"\t\t"<<s1.year_of_publication<<"\t\t"<<s1.price<<"\n";
		}
		fdamaged.close();
	}
	else
	cout<<"\n\nINVALID INPUT";
	getch();
}



/*
Function will display 
1:Issued books details by perticular class
2:Deposit books details by perticular class
*/

void display_by_class()
{
	int choice,classs,rv,count=0;
	char section[1];
	
	issue s2;
	deposit s3;
	
	ifstream fissued,fdeposit;
	fissued.open("Books\\issued.txt",ios::in|ios::binary);
	fdeposit.open("Books\\deposit.txt",ios::in|ios::binary);
	
	dispchar('*',96);
	cout<<"\n\t\t\t\t\tWHAT DO YOU WANT TO SEE\n";
	dispchar('*',96);
	
	cout<<"\n\n1:List of issued books\n2:List of deposited books\t";
	cin>>choice;
	
	if(choice==1)
	{
		count=0;
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t   LIST OF BOOKS OF LIBRARY\n";
		dispchar('*',96);
		
		cout<<"\n\nEnter Class : ";
		cin>>classs;
		rv=classs;
		cout<<"Enter Sec : ";
		cin>>section;
		strcpy(section,strupr(section));
	
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t   LIST OF BOOKS OF LIBRARY\n";
		dispchar('*',96);
		
		cout<<"\n\n\nName\t\tClass Sec\tRoll\tBook_no\tBook_name\tdate_of_issue\n\n";
		while(fissued.read((char*)&s2,sizeof(s2)))
		{
			if(rv==s2.clas && strcmp(section,s2.sec)==0)
			{
		       cout<<s2.sd_name<<"\t\t"<<s2.clas<<" "<<s2.sec<<"\t\t"<<s2.roll<<"\t"<<s2.book_no<<"\t"<<s2.book_name<<"\t"<<s2.d_issued.day<<"-"<<s2.d_issued.month<<"-"<<s2.d_issued.year<<"\n";
		       count++;
		    }
		}
		cout<<"\n\n"<<count<<" student of "<<rv<<" "<<section<<" is having books";
		fissued.close();
	}
	else if(choice==2)
	{
		count=0;
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t   LIST OF BOOKS OF LIBRARY\n";
		dispchar('*',96);
		
		cout<<"\n\nEnter Class : ";
		cin>>classs;
		rv=classs;
		cout<<"Enter Sec : ";
		cin>>section;
		strcpy(section,strupr(section));
		system("cls");
		
		dispchar('*',96);
		cout<<"\n\t\t\t\t   LIST OF BOOKS OF LIBRARY\n";
		dispchar('*',96);
		
		cout<<"\n\n\nName\t\tClass Sec\tRoll\tBook_no\tBook_name\tdate_of_issue\tdate_of_deposit\n\n";
		while(fdeposit.read((char*)&s3,sizeof(s3)))
		{
			if(rv==s3.clas && strcmp(section,s3.sec)==0)
			{
				cout<<s3.sd_name<<"\t\t"<<s3.clas<<" "<<s3.sec<<"\t\t"<<s3.roll<<"\t"<<s3.book_no<<"\t"<<s3.book_name<<"\t\t"<<s3.d_issued.day<<"-"<<s3.d_issued.month<<"-"<<s3.d_issued.year<<"\t"<<s3.d_deposite.day<<"-"<<s3.d_deposite.month<<"-"<<s3.d_deposite.year<<"\n";
				count++;
			}
		}
		cout<<"\n\n"<<count<<" student of "<<rv<<" "<<section<<" had deposited the books";
		fissued.close();
	}
	else
	cout<<"\n\nINVALID INPUT";
	
	cout<<"\n\n\n";
	system("pause");
}



//Function for searching books if it is issued/diposited

void find_book()
{
	dispchar('*',96);
	cout<<"\n\t\t\tSEARCHING BOOKS IF IT IS ISSUED or DIPOSITED\n";
	dispchar('*',96);
	
	int b_no,found=0;
	
	issue s2;
	deposit s3;
	
	ifstream fissued,fdeposit;
	fissued.open("Books\\issued.txt",ios::in|ios::binary);
	fdeposit.open("Books\\deposit.txt",ios::in|ios::binary);
	
	cout<<"\n\n\tEnter Book no to seach : ";
	cin>>b_no;
	
	while(fissued.read((char*)&s2,sizeof(s2)))
	{
		if(b_no==s2.book_no)
		{
	       cout<<"\n\n\tThe Book having book no. "<<s2.book_no<<" is issue to student : \n\n";
		   cout<<"\tName           : "<<s2.sd_name<<"\n";
		   cout<<"\tClass Sec      : "<<s2.clas<<" "<<s2.sec<<"\n";
		   cout<<"\tRoll no.       : "<<s2.roll<<"\n";
		   cout<<"\tBook name      : "<<s2.book_name<<"\n";
		   cout<<"\tDate of Issued : "<<s2.d_issued.day<<"-"<<s2.d_issued.month<<"-"<<s2.d_issued.year;
		   
		   found=1;
		}
	}
	fissued.close();
	
	
	if(found==0)
	{
		cout<<"\n\n\tThe book is not issued";
	}
		
	while(fdeposit.read((char*)&s3,sizeof(s3)))
	{
		if(b_no==s3.book_no)
		{
		   cout<<"\n\n\tThe Book having book no. "<<s3.book_no<<" was last time deposited by student : \n\n";
		   cout<<"\tName           : "<<s3.sd_name<<"\n";
		   cout<<"\tClass Sec      : "<<s3.clas<<" "<<s2.sec<<"\n";
		   cout<<"\tRoll no.       : "<<s3.roll<<"\n";
		   cout<<"\tBook name      : "<<s3.book_name<<"\n";
		   cout<<"\tDate of Issued : "<<s3.d_issued.day<<"-"<<s3.d_issued.month<<"-"<<s3.d_issued.year<<"\n";
	       cout<<"\tDate of Deposit: "<<s3.d_deposite.day<<"-"<<s3.d_deposite.month<<"-"<<s3.d_deposite.year;
	       break;
	    }
	}
	fdeposit.close();
	
	cout<<"\n\n\n\t";	
	system("pause");
}



/*
Function will give print out of
1:All books of library details
2:Issued books details
3:Deposit books details
4:Damage books details
*/


void print()
{
	int choice;
	
	library s1;
	issue s2;
	deposit s3;
	
	ifstream ftotal,fissued,fdamaged,fdeposit;
	ofstream fout;
	ftotal.open("Books\\total.txt",ios::in|ios::binary);
	fissued.open("Books\\issued.txt",ios::in|ios::binary);
	fdamaged.open("Books\\damaged.txt",ios::in|ios::binary);
	fdeposit.open("Books\\deposit.txt",ios::in|ios::binary);
	
	fout.open("PRN");
	
	dispchar('*',96);
	cout<<"\n\t\t\t\t\tWHAT DO YOU WANT TO PRINT\n";
	dispchar('*',96);
	
	cout<<"\n1:List of all books\n2:List of issued books\n3:List of deposited books\n4:List of damaged books\t";
	cin>>choice;
	
	if(choice==1)
	{
		while(ftotal.read((char*)&s1,sizeof(s1)))
		{
			fout.write((char*)&s1,sizeof(s1));
		}
		ftotal.close();
		fout.close();
	}
	else if(choice==2)
	{
		while(fissued.read((char*)&s2,sizeof(s2)))
		{
			fout.write((char*)&s1,sizeof(s1));
		}
		fissued.close();
		fout.close();
	}
	else if(choice==3)
	{
		while(fdeposit.read((char*)&s3,sizeof(s3)))
		{
			fout.write((char*)&s1,sizeof(s1));
		}
		fdeposit.close();
		fout.close();
	}
	else if(choice==4)
	{
		while(fdamaged.read((char*)&s1,sizeof(s1)))
		{
			fout.write((char*)&s1,sizeof(s1));
		} 
		fdamaged.close();
		fout.close();
	}
	else
	cout<<"\n\nINVALID INPUT";
}




//Main program

int main()
{       
	system("cls");
	
	int choice=1,n;
	char pwd[20],f_pwd[20],mas_pwd[]={"rahul"};
	
	ifstream fin("Books\\pwd.txt",ios::in);
	
	library s1;
	issue s2;
	deposit d1;
	
	welcome();
	
	fin>>f_pwd;
	
  for(int rv=0;rv<3;rv++)
  {
  	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\tEnter Password : ";
	cin>>pwd;
	if(strcmp(pwd,f_pwd)==0||strcmp(pwd,mas_pwd)==0)
	{
		fin.close();
		cout<<"\t\t\t\t  Correct Password\n\n\t\t\t   ";
		system("pause");
		introduction();
		while(choice!=12)
		{
			system("cls");
			dispchar('*',96);
			cout<<"\n\t\t\t\t\tWELCOME TO LIBRARY\n";
			dispchar('*',96);
			cout<<"\n\n\n   1.Issuing a book";
			cout<<"\n   2.Depositing a book";
			cout<<"\n   3.New books details";
			cout<<"\n   4.A book got damage";
			cout<<"\n   5.Display list of all books";
			cout<<"\n   6.Display books by class";
			cout<<"\n   7.Search a book if it is issued or deposited";
			cout<<"\n   8.Modify Details";
			cout<<"\n   9.Delete data of a book ";
			cout<<"\n   10.Print a Record";
			cout<<"\n   11.Reset the app password";
			cout<<"\n   12.Exit";
			cout<<"\n\n   Enter Your Choice : ";
			cin>>choice;
		
			if(choice==1)
			{
				system("cls");
				s2.issuing_book();
			}
			else if(choice==2)
			{
				cout<<"\n   Enter book no to deposit : ";
				cin>>n;
				d1.deposit_book(n);
			}
			else if(choice==3)
			{
				s1.input_book_detail(3);
			}
			else if(choice==4)
			{
				s1.input_book_detail(4);
			}
			else if(choice==5)
			{
				system("cls");
				s1.display_books();
			}
			else if(choice==6)
			{
				system("cls");
				display_by_class();
			}
			else if(choice==7)
			{
				system("cls");
				find_book();
			}
			else if(choice==8)
			{
				system("cls");
				modify();
			}
			else if(choice==9)
			{
				delet();
			}
			else if(choice==10)
			{
				system("cls");
				print();
			}
			else if(choice==11)
			{		
				cout<<"\n   Enter Master Password : ";
				cin>>pwd;
				if(strcmp(pwd,mas_pwd)==0)
				{
					char new_pwd1[20],new_pwd2[20];
					cout<<"   New Password : ";
					cin>>new_pwd1;
					cout<<"   Reenter Password : ";
					cin>>new_pwd2;
					
					if(strcmp(new_pwd1,new_pwd2)==0)
					{
						ofstream fout("Books\\pwd.txt",ios::out);
						fout<<new_pwd1;
						cout<<"\n\t   Password Successfully Changed\n\t";
						system("pause");
					}
					else
					{
						cout<<"\n\t   Password Does Not Match";
						system("pause");
					}
				}
				else
				{
					cout<<"\n   Incorrect Password";
					getch();
				}
			}
			else if(choice==12)
			{
				cout<<"\n\n\t\t\t\tBYE HAVE A NICE DAY\n";
				cout<<"\t\t\t    Leave your suggestion on : \n";
				cout<<"\t\t\t   Email : rahul0512.pi@gmail.com\n\t\t\t   ";
				system("pause");
			}
			else
			{
				cout<<"\n\n\tINVALID INPUT\n\t";
				system("pause");
			}
			
		}
		break;
	}
	else
	{
		cout<<"\t\t\t\t  Incorrect Password\n\t\t\t\n\n\n\n\n";
	}
	getch();
  }
	return 0;
}
