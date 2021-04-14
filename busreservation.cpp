#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

using namespace std;
static int p = 0;

class a

{

  char busid[10], arrival[10], depart[10], from[10], to[10], actype[10],seat[8][4][10];

public:

  void details();                                 //to enter the details;
  void displaybus();                             //to display available buses;
  void reserveseat();                           //to reserve the seat;
  void empty();                                //to initiallize all bus seat are vaccant;
  void displayavailableseats();               //to display available seats;
  void displayreservedseats(int i);          //to pass data regarding reserved seat to display seat;
 
}

bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void a::details()

{

  cout<<"\nEnter the Bus ID: ";

  cin>>bus[p].busid;
 
  cout<<"\nWhether AC or Non-AC:";
 
  cin>>bus[p].actype;

  cout<<"\nArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom:";

  cin>>bus[p].from;

  cout<<"\nTo:";

  cin>>bus[p].to;

 bus[p].empty();

  p++;

}

void a::reserveseat()

{

  int seat;  // Enter seat number between 1 to 32;

  char number[5];

  top:

  cout<<"Bus ID: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busid, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32) //Can't allocate as there are only 32 seats
    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];
        cout<<"\nYour seat has been reserved.";

        break;

      }

    else

      cout<<"The seat number is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus ID.\n";

      goto top;

    }

  }

void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}


void a::displayavailableseats()

{

  int n;

  char number[10];

  cout<<"Enter bus ID: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busid, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');
  cout<<"\nBus no: \t"<<bus[n].busid

  <<"\nAC or Non-AC: \t"<<bus[n].actype<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].displayreservedseats(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus ID: ";

}

void a::displayreservedseats(int l)
{

  int s=0,h=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          h++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<h<<" seats empty in Bus No: "<<bus[l].busid;

 }

void a::displaybus()

{

  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"\nBus ID:"<<bus[n].busid<<"\tAC or Non-AC:"<<bus[n].actype<<"\t\tArrival time:"<<bus[n].arrival<<"\tDeparture Time:"

    <<bus[n].depart<<"\nFrom:"<<bus[n].from<<"\t\tTo:"<<bus[n].to<<"\n";
    cout<<endl;

    vline('_');

  }

}
int main()
{
  char uname[50];
  char pass[20];
  cout<<"~~~~~~SIGN UP~~~~~~";
  cout<<"\nEnter User Name: ";
  cin>>uname;
  cout<<"\nEnter Password: ";
  cin>>pass;
  cout<<"\nYou successfully logged in!"<<endl;
  int choice;
  vline('-');

  cout<<"\n\t\t\t\t****Gold Bus Travel Agency****"<<endl<<endl;
  vline('-');
  while(1)
  {
 
  cout<<endl;
  vline('*');
  cout<<"\n\n";
 
  cout<<"Select the choice number.\n";
  cout<<"1.Enter the bus Details:\n"<<"2.Buses Available:\n"

  <<"3.Show the available seats in a bus:\n"

  <<"4.Reserve seat: \n"

  <<"5.Exit";
  cout<<endl;
  vline('*');
  cout<<"\nEnter your choice:";

  cin>>choice;
 
  switch(choice)

  {

    case 1:  bus[p].details();

      break;

    case 2:  bus[0].displaybus();

      break;

    case 3:  bus[0].displayavailableseats();

      break;

    case 4:  bus[p].reserveseat();

      break;

    case 5: {
      cout<<"Successfully Logged out from the Application. Visit Again!"<<endl<<"<Thanks You :)"<<endl;
      exit(0);
    };

  }

}

return 0;

}


