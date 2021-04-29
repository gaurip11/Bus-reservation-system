#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bus
{
private:
string b_no,b_name,d_name;
int b_seats;
public:
void controll();
void admin();
void user_menu();
void new_bus();
void view_bus();
void view_single_bus();
void view_all_bus();
void update_bus();
void route_bus();
void seat_detail_bus();
void booking();
void renew_bus();
void search_booking();
void update_booking();
void del_booking();


};

void bus::controll()
{
	system("cls");
	p:
int option;
cout<<"\n********************************************************************************************";
cout<<"\n\t\t Welcome to Gold Bus Agency!";
cout<<"\n********************************************************************************************";
cout<<"\n\n\t 1. Administration mode";
cout<<"\n\n\t 2. User mode";
cout<<"\n\n\t Enter your choice :";
cin>>option;
switch(option)
{
	case 1:
		admin();
		break;
	case 2: 
	    user_menu();
	  break;
	default:
cout<<"\n\n Invalid choice...Please try again...";
}
getch();
goto p;
}


void bus::admin()
{
	bus b;
p:
system("cls");
string email,pass;
char ch;
int opt;
cout<<"\n\n\t\t\t************Login***********";
cout<<"\n\nEmail :";
cin>>email;
cout<<"\n\nPassword :";
for(int i=1;i<6;i++)
{
ch= getch();
pass += ch;
cout<<"*";
}
if(email=="siddhi@gmail.com" && pass=="sid12")
{
cout<<"\n\n\n\t\t\tLoading...";
for(int i=1;i<=5;i++)
{
Sleep(500);
cout<<".";
}
z:
cout<<"\n1. Add bus detail :";
cout<<"\n2. Update bus details :";
cout<<"\n2. Renew seats";
cout<<"\n3. Go back :";
cout<<"\nEnter your choice :";
cin>>opt;
switch(opt)
{
	case 1:
		new_bus();
	  break;
	case 2:
		update_bus();
	  break;
	  case 3:
	  	renew_bus();
	  	break;
	case 4:
		controll();
    default:
cout<<"\n\n Invalid choice...Please try again...";
}
getch();
goto z;
}
else
{
cout<<"\n\n\t\tYour email and password is wrong...";
getch();
goto p;
}
}


void bus::user_menu()
{
system("cls");
p:
int choice;
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";

cout<<"\n 1. View Bus detail";
cout<<"\n 2. Routes of buses";
cout<<"\n 3. Bus seat details";
cout<<"\n 4. Booking record";
cout<<"\n 5. Search booking record";
cout<<"\n 6. Update booking record";
cout<<"\n 7. Delete booking record";
cout<<"\n 8. EXIT";
cout<<"\n\n Enter your choice :";
cin>>choice;
switch(choice)
{
case 1:
    view_bus();
break;
case 2:
    route_bus();
break;
case 3:
    seat_detail_bus();
break;
case 4:
    booking();
break;
case 5:
    search_booking();
break;
case 6:
	update_booking();
break;
case 7:
	del_booking();
break;
case 8:
	cout<<"\n\nYou have been successfully logged out. Thank you for visiting!";
	exit(0);
default:
cout<<"\n\n Invalid choice...Please try again...";
}
getch();
goto p;
}

void bus::new_bus()
{
p:
system("cls");
fstream file;
string t_no,tb_name,td_name;
int t_seats,found=0;
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
cout<<"\n\n Bus no:";
cin>>b_no;
cout<<"\n\n Bus name :";
cin>>b_name;
cout<<"\n\n Total seats :";
cin>>b_seats;
cout<<"\n\n Driver name :";
cin>>d_name;
file.open("bus.txt",ios::in);
if(!file)
{
file.open("bus.txt",ios::app|ios::out);
file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
file.close();
}
else
{
file>>t_no>>tb_name>>t_seats>>td_name;
while(!file.eof())
{
if(b_no==t_no)
{
found++;
}
file>>t_no>>tb_name>>t_seats>>td_name;
}
file.close();
if(found==0)
{
  file.open("bus.txt",ios::app|ios::out);
  file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
  file.close();
}
else
{
cout<<"\n\n Duplicate record found...";
getch();
goto p;
}
cout<<"\n\n New bus inserted successfully!";
}

}

void bus::view_bus()
{
g:
system("cls");
int option;
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
cout<<"\n\n 1. Single bus view";
cout<<"\n 2. All buses view";
cout<<"\n 3. Go back";
cout<<"\n\n Enter your choice :";
cin>>option;
switch(option)
{
case 1:
view_single_bus();
break;
case 2:
view_all_bus();
break;
case 3:
user_menu();
default:
cout<<"\n\n Invalid choice...Please try again...";

}
getch();
goto g;

}

void bus::view_single_bus()
{
system("cls");
string t_no;
fstream file;
int found=0;
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
cout<<"\n\n Bus no :";
cin>>t_no;
file.open("bus.txt",ios::in);
if(!file)
{
cout<<"\n\n File openning error.";
}
else
{
  file>>b_no>>b_name>>b_seats>>d_name;
  while(!file.eof())
  {
  if(t_no == b_no)
  {
  system("cls");
  cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
  cout<<"\n BUS NO \tBUS NAME \tNO. OF SEATS \tDRIVER NAME";
  cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
  found++;
  }
  file>>b_no>>b_name>>b_seats>>d_name;
  }
  file.close();
  if(found==0)
  {
  cout<<"\n\n Invalid bus no";
  }
}
}

void bus::view_all_bus()
{
system("cls");
fstream file;
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
file.open("bus.txt",ios::in);
if(!file)
{
cout<<"\n\n File openning error.";
}
else
{
system("cls");
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
  cout<<"\n\nBUS NO \tBUS NAME \tNO. OF SEATS \tDRIVER NAME";
  file>>b_no>>b_name>>b_seats>>d_name;
  while(!file.eof())
  {
 
 
 
  cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
 
 
  file>>b_no>>b_name>>b_seats>>d_name;
  }
  file.close();  
}

}

void bus::update_bus()
{
system("cls");
fstream file,file1;
string t_no,no,t_name,td_name;
int t_seats,found=0;
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
file.open("bus.txt",ios::in);
if(!file)
{
cout<<"\n\n File openning error ";
}
else
{
cout<<"\n\n Bus no:";
cin>>t_no;
file1.open("bus1.txt",ios::app|ios::out);
file>>b_no>>b_name>>b_seats>>d_name;
while(!file.eof())
{
if(t_no == b_no)
{
cout<<"\n\n New Bus no:";
cin>>no;
cout<<"\n\n Bus name :";
cin>>t_name;
cout<<"\n\n No. of seats";
cin>>t_seats;
cout<<"\n\n Driver name :";
cin>>td_name;
file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<"\n";
cout<<"\n\n Updated bus record successfully";
found++;
}
else
{
file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
}
file>>b_no>>b_name>>b_seats>>d_name;
}
file.close();
file1.close();
remove("bus.txt");
rename("bus1.txt","bus.txt");
if(found==0)
{
cout<<"\n\n Bus no. is invalid";
}
}

}

void bus::route_bus()
{
system("cls");
p:
int choice;
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
cout<<"\n\n 1. 1st bus route details";
cout<<"\n 2. 2nd route bus details";
cout<<"\n 3. 3rd bus route details";
cout<<"\n 4. 4th bus route details";
cout<<"\n 5. 5th bus route details";
cout<<"\n 6. Go back";
cout<<"\n\n Enter your choice";
   cin>>choice;
   switch(choice)
   {
    case 1:
    cout<<"\n From Pune to Mumbai";
    cout<<"\n9:00 am......................10:00 am";
    cout<<"\n From Swargate to Lonavla";
    cout<<"\n9:00 am......................11:00 am";
    cout<<"\n From Lonavala to Mumbai";
    cout<<"\n11:00 am.....................1:00 pm";
    break;
    case 2:
   cout<<"\n From Pune to Nashik";
    cout<<"\n9:00 am......................10:00 am";
    cout<<"\n From Swargate to Nagar";
    cout<<"\n9:00 am......................11:00 am";
    cout<<"\n From Nagar to Nashik";
    cout<<"\n11:00 am.....................1:00 pm";
    break;
    case 3:
   cout<<"\n From Pune to Dhule";
    cout<<"\n9:00 am......................10:00 am";
    cout<<"\n From Swargate to Nashik";
    cout<<"\n9:00 am......................11:00 am";
    cout<<"\n From Nashik to Dhule";
    cout<<"\n11:00 am.....................1:00 pm";
    break;
    case 4:
   cout<<"\n From Pune to Kolhapur";
    cout<<"\n9:00 am......................10:00 am";
    cout<<"\n From Swargate to Satara";
    cout<<"\n9:00 am......................11:00 am";
    cout<<"\n From Satara to Kolhapur";
    cout<<"\n11:00 am.....................1:00 pm";
    break;
    case 5:
    cout<<"\n From Pune to Dapoli";
    cout<<"\n9:00 am......................10:00 am";
    cout<<"\n From Swargate to Lonavala";
    cout<<"\n9:00 am......................11:00 am";
    cout<<"\n From Lonavala to Dapoli";
    cout<<"\n11:00 am.....................1:00 pm";
    break;
    case 6:
    user_menu();
    default:
    cout<<"\n\n Invalid choice...Please try again...";
}
getch();
goto p;
}
void bus::seat_detail_bus()
{
system("cls");
fstream file,file1;
string t_no,s_b_no,s_no;
int count=0,found=0;
cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
file.open("bus.txt",ios::in);
file1.open("seat.txt",ios::in);

if(!file || !file1)
{
	cout<<"\n\n File openning error";
}
else
{
	cout<<"\n\n Bus no :";
	cin>>t_no;
	file1>>s_b_no>>s_no;
	while(!file1.eof())
	{
		if(t_no == s_b_no)
		{
			count++;
		}
		file1>>s_b_no>>s_no;
	}
	file1.close();
	file>>b_no>>b_name>>b_seats>>d_name;
	while(!file.eof())
	{
		if(t_no == b_no)
		{
			system("cls");
			cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
			cout<<"\n\n Total no. of seats :"<<b_seats;
			cout<<"\n\n Reserved no. of seats :"<<count;
			cout<<"\n\n Empty no. of seats :"<<b_seats-count;
			found++;
		}
		file>>b_no>>b_name>>b_seats>>d_name;
	}
	file.close();
	if(found == 0)
	{
		cout<<"\n\n Bus no. Invalid.";
	}
}

}

void bus::booking()
{
	p:
	system("cls");
	fstream file;
	string t_no,s_b_no,customer_name,phone,from,to;
	int found =0,s_no,seats,count=0,s_s_no,ss_no[25],i=0,s_amount,total_amount=0,r_amount;
	char x;
	cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File openning error";
	}
	else
	{
		cout<<"\n\n Bus no :";
		cin>>t_no;
		file.close();
		file.open("seat.txt",ios::in);
		if(file)
		{
		file>>s_b_no>>s_s_no;
		while(!file.eof())
		{
			if(t_no == s_b_no)
			{
				count++;
			}
			file>>s_b_no>>s_s_no;
		}
		file.close();
    	}
		file.open("bus.txt",ios::in);
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no == b_no)
			{
				seats = b_seats;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		if(seats-count == 0)
		{
			cout<<"\n\n All Seats of this bus is already reserved";
		}
		else if(found == 1)
		{
			do{
				h:
				cout<<"\n\n Seat no :";
				cin>>s_no;
				if(s_no > seats)
				{
					cout<<"\n\n Seat No. is invalid. Please try again";
					goto h;
				}
					file.open("seat.txt",ios::in);
				if(!file)
				{
				   file.open("seat.txt",ios::app|ios::out);
				   file<<t_no<<" "<<s_no<<"\n";
				   file.close();
				}
				else
				{
					file>>s_b_no>>s_s_no;
					while(!file.eof())
					{
						if(t_no == s_b_no && s_no == s_s_no)
						{
							cout<<"\n\n Seat is already reserved plaese try again";
							goto h;
						}
						file>>s_b_no>>s_s_no;
					}
					file.close();
					file.open("seat.txt",ios::app|ios::out);
                    file<<t_no<<" "<<s_no<<"\n";
				   file.close();	
				}
				ss_no[i] = s_no;
				i++;
				cout<<"\n\n Booking another seat (Y,N) :";
				cin>>x;
			}while(x == 'Y' || x == 'y' );
			system("cls");
			cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
			cout<<"\n\n Customer name :";
			cin>>customer_name;
			cout<<"\n\n Phone number :";
			cin>>phone;
			cout<<"\n\n From :";
			cin>>from;
			cout<<"\n\n To :";
			cin>>to;
			cout<<"\n\n Single amount :";
			cin>>s_amount;
			total_amount = s_amount*i;
			cout<<"\n\n Total amount : "<<total_amount;
			cout<<"\n\n Receive Amount :";
			cin>>r_amount;
			file.open("customer.txt",ios::app|ios::in);
			file<<customer_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<"\n";
			file.close();
			system("cls");
				cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
				cout<<"\n\n\t\t***************************************************************";
	            cout<<"\n\n\t\t__________________Booking Information________________________";
	            cout<<"\n\n\t\t***************************************************************";
	            cout<<"\n\n\t\tCustomer name :                 "<<customer_name;
	            cout<<"\n\n\t\tFrom :                          "<<from;
	            cout<<"\n\n\t\tTo :                            "<<to;
	            cout<<"\n\n\t\tTotal seats :                   "<<i;
	            cout<<"\n\n\t\tReserved seats :                  ";
	            for(int a=0;a<i;a++)
	            {
	            	if( a != 0)
	            	cout<<",";
	            	cout<<ss_no[a];
				}
				cout<<"\n\n\t\tSingle seat amount : "<<s_amount;
				cout<<"\n\n\t\tTotal amount :       "<<total_amount;
				cout<<"\n\n\t\tReceieved amount :   "<<r_amount;
	            cout<<"\n\n\t\tReturn amount :      "<<r_amount-total_amount;
	            cout<<"\n\n\t\t***************************************************************";
	            cout<<"\n\n\t\t    Thank you for booking! Take safety measures for Covid-19.";
	            cout<<"\n\n\t\t    Happy journey!";
	            cout<<"\n\n\t\t***************************************************************";
	}
		else
		{
			cout<<"\n\n Bus no. is Invalid. Please try again";
			getch();
			goto p;
		}
	
	
}
}

void bus::renew_bus()
{
	system("cls");
	fstream file;
	char x;
		cout<<"\n\t\t____________________Gold BUS AGENCY_____________________";
		file.open("seat.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File openning error";
		}
		else
		{
			cout<<"\n\n Do you want renew all seats (Y,N)";
			cin>>x;
			if(x == 'Y' || x == 'y')
			{
				remove("seat.txt");
				cout<<"\n\n\t\t All seats rreservation renewed.";
			}
			else
			{
				cout<<"\n\n\t\t All seats reservation is saved.";
			}
		}
}

void bus::update_booking()
{
	system("cls");
	fstream file,file1;
	int t_seats,t_amo,found=0,del_seats,i=0;
	string name,no,phone,t_phone,del_no;
		cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
		file.open("customer.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File openning error";
		}
		else
		{
			cout<<"\n\nEnter your phone number : ";
			cin>>t_phone;
			file>>name>>no>>phone>>t_seats>>t_amo;
			while(!file.eof())
			{
				if(t_phone == phone)
				{
				   	file.close();
				   	file.open("customer.txt",ios::in);
				   	file1.open("customer1.txt",ios::app|ios::out);
				   	file>>name>>no>>phone>>t_seats>>t_amo;
				   	while(!file.eof())
				   	{
				   		if(t_phone == phone)
				   		{
				   			del_no = no;
				   			del_seats =  t_seats;
						}
				   		if(t_phone != phone)
				   		{
				   		    file<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
						}
				   		file>>name>>no>>phone>>t_seats>>t_amo;
					}
					file.close();
					file1.close();
					remove("customer.txt");
					rename("customer1.txt","customer.txt");
					file.open("seat.txt",ios::in);
					file1.open("seat1.txt",ios::app|ios::out);
					file>>no>>t_seats;
					while(!file.eof())
					{
						if(!(del_no == no && i < del_seats))
						{
							file1<<no<<" "<<t_seats<<"\n";
						}
						file>>no>>t_seats;
					}
					file.close();
					file1.close();
					remove("seat.txt");
					rename("seat1.txt","seat.txt");
					booking();
					cout<<"\n\nUpdated your record successfully.";
					found++;
				   	goto h;
				}
				file>>name>>no>>phone>>t_seats>>t_amo;
			}
			file.close();
			h:
				if(found == 0)
				{
					cout<<"\n\n Phone number is invalid";
				}
		}
}

void bus::del_booking()
{
	system("cls");
	fstream file,file1;
	int t_seats,t_amo,found=0,del_seats,i=0;
	string name,no,phone,t_phone,del_no;
		cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
		file.open("customer.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File openning error";
		}
		else
		{
			cout<<"\n\nEnter your phone number : ";
			cin>>t_phone;
			file>>name>>no>>phone>>t_seats>>t_amo;
			while(!file.eof())
			{
				if(t_phone == phone)
				{
				   	file.close();
				   	file.open("customer.txt",ios::in);
				   	file1.open("customer1.txt",ios::app|ios::out);
				   	file>>name>>no>>phone>>t_seats>>t_amo;
				   	while(!file.eof())
				   	{
				   		if(t_phone == phone)
				   		{
				   			del_no = no;
				   			del_seats =  t_seats;
						}
				   		if(t_phone != phone)
				   		{
				   		    file<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
						}
				   		file>>name>>no>>phone>>t_seats>>t_amo;
					}
					file.close();
					file1.close();
					remove("customer.txt");
					rename("customer1.txt","customer.txt");
					file.open("seat.txt",ios::in);
					file1.open("seat1.txt",ios::app|ios::out);
					file>>no>>t_seats;
					while(!file.eof())
					{
						if(!(del_no == no && i < del_seats))
						{
							file1<<no<<" "<<t_seats<<"\n";
						}
						file>>no>>t_seats;
					}
					file.close();
					file1.close();
					remove("seat.txt");
					rename("seat1.txt","seat.txt");
					cout<<"\n\nDeleted booking record successfully";
					found++;
				   	goto h;
				}
				file>>name>>no>>phone>>t_seats>>t_amo;
			}
			file.close();
			h:
				if(found == 0)
				{
					cout<<"\n\n Phone number is invalid";
				}
		}
}

void bus::search_booking()
{
	system("cls");
	fstream file;
	string name,no,phone,t_name;
	int t_seats,t_amo,found=0;
		cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
		file.open("customer.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File oprnning error";
	    }
	    else
	    {
	    	cout<<"\n\n Customer Name :";
	    	cin>>t_name;
	    	file>>name>>no>>phone>>t_seats>>t_amo;
	    	while(file.eof())
	    	{
	    		if(t_name == name)
	    		{
	    			if(found == 0)
	    			{
	    				system("cls");
	    			cout<<"\n\t\t____________________GOLD BUS AGENCY_____________________";
	    		    }
	    		    cout<<"\n\n\n Customer name :"<<name;
	    		    cout<<"\n\n Bus no :         "<<no;
	    		    cout<<"\n\n Phone number :   "<<phone;
	    		    cout<<"\n\n Reserved seats : "<<t_seats;
	    		    cout<<"\n\n Total amount :   "<<t_amo;
	    		    cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	    		    found++;
				}
	    		file>>name>>no>>phone>>t_seats>>t_amo;
			}
			file.close();
			if(found == 0)
			{
				cout<<"\n\n Customer name is Invalid.";
			}
		}
	
}


main()
{
	bus b;
	b.controll();
}




