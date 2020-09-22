#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

void addcontact();
void searchcontact();
void exit();
void show();
void delete_contacts();
bool check_digit(string);
bool check_number(string);

string fname,lname, phone_number; 


int main()
{
	system("cls");
	cout<<"\n\n\n\t\t\t PhoneBook Management System"<<endl;
	cout<<"\n\t 1. Add Contact";
	cout<<"\n\t 2. Search Contact";
	cout<<"\n\t 3. Exit";
	cout<<"\n\t 4. Show contact";
	cout<<"\n\t 5. Delete All Contacts"<<endl;
	
	int choice;
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			addcontact();
            break;
        case 2:
		     searchcontact();
			 break;
		case 3:
		    exit();
			break;
		case 4:
			show();
			break;
		case 5:
			delete_contacts();
			break;
		default:
			system("cls");
		   cout<<"\n\n\t invalid  input";
	       cout<<"\n\t Press any key to continue.."<<endl; 
		   getch();
		   main();	
	}
	return 0;
}

void delete_contacts()
{
	ofstream myfile("number.txt", ios :: out);
	cout<<"All Records has been deleted"<<endl;
	myfile<<"No contacts present";
	myfile.close();
	cout<<"press any key for main menu"<<endl;
		   	 getch(); 
			 main();
}
void addcontact()
{
	ofstream phone("number.txt",ios ::app);
	system("cls");
	cout<<"\n\t enter fisrt name : ";
	cin>>fname;
	cout<<"\n\t enter last name : ";
	cin>>lname;
	cout<<"\n\t enter Phone Number name : ";
	cin>>phone_number;
	
	if(check_digit(phone_number) == true)
	{
		if(check_number(phone_number) == true)
		{
		   if(phone.is_open()) 
		   {
		   	 phone<< fname <<" "<<lname<<" "<<phone_number<<endl;
		   	 cout<<"\n\t conntact saved successfully"<<endl;
		   	 cout<<"press any key for main menu";
		   	 getch(); 
			 main();
		   	 
		   }else
		   {
		   	cout<<"\n\t file not opening"<<endl;
		   }
		}
		else
		{
			system("cls");
		    cout<<"\n\n\t\t invalid phone number"<<endl;
			cout<<"press any key for main menu";
		   	 getch(); 
			 main();	
		}
	}
	else
	{
		cout<<"\n\t phone number must contain 10 digits"<<endl;
		cout<<"press any key for main menu";
		getch(); 
        main();
	}
    phone.close();
}
	
void show()
{
	ifstream fin("number.txt",ios :: in);
	char ch;
	ch = fin.get();
	while(!fin.eof())
	{
		cout<<ch;
		ch = fin.get();
	}
	fin.close();
	cout<<"press any key for main menu";
		   	 getch(); 
			 main();
 } 
void searchcontact()
{
	system("cls");
	bool found = false;
	string a;
	cout<<"\n\n\t Please Enter Name for which You are Looking for : ";
	cin>>a;
	ifstream myfile("number.txt",ios :: in);
	
	while(!myfile.eof())
	{
		if(a == fname || a == lname)
		{
			system("cls");
			cout<<"\n\n\t\t contact found"<<endl;
			cout<<"\t\t First Name : " << fname<<endl;
			cout<<"\t\t last Name : " << lname<<endl;
			cout<<"\t\t Phone Number : " << phone_number<<endl;
	         
			found = true;
			break; 		
		}
	}
	if(found == false)
	{
		system("cls");
		cout<<"\n\n\t\t Contact Not Found"<<endl;
	}
      	cout<<"\n\n\t\tpress any key for main menu";
		getch(); 
        main();	
}
void exit()
{
	system("cls");
	cout<<"\n\n\n\t\t\tThankYou for Using"<<endl;
}
bool check_digit(string A)
{
	if(A.size() == 10)
	{
		return true;
	}
	return false;
}
bool check_number(string x)
{
	bool check = true;
	
	for(int i =0;i<x.size(); i++)
	{
		if(!(x[i] >= 48 && x[i]<=57))
		{
			check = false;
			break;
		}
	}
	return check;
}
