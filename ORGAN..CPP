#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
class patient
{
 private:
   long int patientid;
   char patientname[40];
   char bloodgroup1[20];
   int  age;
   char gender[20],nationality[50];
   int  noorg;
   char organ2[20];
 public:
   void enterddetails();
   char *retbloodgroup1()
    {
      return bloodgroup1;
    }
   long retpatientid()
    {
      return patientid;
    }
    char *retorgan2()
    {
      return organ2;
    }
   void displaypatient(int r)
    {
      gotoxy(10,r);

      cout<<patientid;
      gotoxy(20,r);
      cout<<patientname;
      cout<<endl;
   }
   void displayspepatient()
    {
      clrscr();
      gotoxy(25,5);
      cout<<"QATAR ORGAN DONATION CENTER";
      gotoxy(25,6);
      cout<<"***************************";
      gotoxy(25,8);
      cout<<"    PATIENT DETAILS    ";
      gotoxy(15,10);
      cout<<"PATIENT ID   : ";
      cout<<patientid;
      gotoxy(15,12);
      cout<<"PATIENT NAME : ";
      gotoxy(15,14);
      cout<<patientname;
      cout<<organ2<<"\t";
   }
};
void patient::enterddetails()
   {
     gotoxy(10,8);
     cout<<"ENTER ID : ";
     cin>>patientid;
     gotoxy(10,10);
     cout<<"ENTER THE FULLNAME : ";
     gets(patientname);
     gotoxy(10,11);
     cout<<"ENTER THE GENDER : ";
     gets(gender);
     gotoxy(10,12);
     cout<<"ENTER THE AGE : ";
     cin>>age;
     gotoxy(10,13);
     cout<<"ENTER THE NATIONALITY : ";
     gets(nationality);
     gotoxy(10,14);
     cout<<"ENTER THE BLOODGROUP : ";
     gets(bloodgroup1);
     gotoxy(10,15);
     cout<<"\n how many organs you want to recieve : ";
     cin>>noorg;
     for (int i=0;i<noorg;i++)
       {
	cout<<"ENTER THE ORGAN "<<i+1<<" : ";
	gets(organ2);
       }
  }

void addpatient()
   {
     clrscr();
     gotoxy(25,5);
     cout<<"QATAR ORGAN DONATION CENTER";
     gotoxy(25,6);
     cout<<"***************************";
     gotoxy(25,8);
     cout<<"  ADDING PATIENT MENU  ";
     fstream x;
     x.open("patient.dat",ios::app|ios::binary);
     patient p;
     p.enterddetails();
     x.write((char *)&p,sizeof(p));
     x.close();
   }
void displayallpatients()
   {
     gotoxy (10,10);
     cout<<"PATIENT ID : ";
     gotoxy (20,10);
     cout<<"PATIENT NAME : ";
     fstream x;
     x.open("patient.dat",ios::in|ios::binary);
     patient p;
     int r=11;
     while(x.read((char *)&p,sizeof(p)))
      {
	p.displaypatient(r);
	r++;
      }
     x.close();
   }
void displaypatientid()
   {
     clrscr();
     gotoxy(25,5);
     cout<<"QATAR ORGAN DONATION CENTER";
     gotoxy(25,6);
     cout<<"***************************";
     gotoxy(25,8);
     cout<<"   DISPLAY MENU   ";
     fstream x;
     int di;
     gotoxy(10,14);
     cout<<"\n Enter the patient id to be displayed : ";
     cin>>di;
     x.open("patient.dat",ios::in|ios::binary);
     patient p;
     while(x.read((char *)&p,sizeof(p)))
       {
	 p.displayspepatient();
       }
     x.close();
   }
void modifypatient()
  {
    clrscr();
    int id;
    fstream x;
    x.open("donor.dat",ios::binary);
    gotoxy(25,5);
    cout<<"QATAR ORGAN DONATION CENTER";
    gotoxy(25,6);
    cout<<"*******************************";
    gotoxy(25,8);
    cout<<"     MODIFYING THE RECORD";
    gotoxy(25,9);
    cout<<" ******************* ";
    gotoxy(10,10);
    cout<<"ENTER THE ID TO BE MODIFIED : ";
    cin>>id;
    patient p;
    while(x.read((char*)&p,sizeof(p)))
      {
	if(id==p.retpatientid())
	 {
	   p.enterddetails();
	   x.seekp(-1*(sizeof(p),ios::cur));
	   x.write((char*)&p,sizeof(p));
	 }
      }
    x.close();
  }
void deletepatient()
  {
     int n;
     patient p;
     ofstream y;
     ifstream x;
     x.open("patient.dat",ios::binary);
     y.open("temp.dat",ios::binary);
     while(x.read((char*)&p,sizeof(p)))
      {
       if(p.retpatientid()==n)
       y.write((char*)&p,sizeof(p));
      }
     x.close();
     y.close();
     remove("patient.dat");
     rename("temp.dat","patient.dat") ;
  }
class donor
{
 private:
   long int donorid;
   char donorname[40];
   char bloodgroup2[20];
   int age;
   char gender[20],nationality[50];
   char prehistory;
   char detailsofprehistory[50];
   int noorg;
   char organ1[10][20];
 public:
   void enterddetails();
   void displayspedonor();
   char *retbloodgroup2()
    {
      return bloodgroup2;
    }
   long retdonorid()
    {
      return donorid;
    }
   void displaydonor(int r)
    {
      gotoxy(10,r);

      cout<<donorid;
      gotoxy(20,r);
      cout<<donorname;
      cout<<endl;
   }
 };
void donor::displayspedonor()
   {
      clrscr();
      gotoxy(25,5);
      cout<<"QATAR ORGAN DONATION CENTER";
      gotoxy(25,6);
      cout<<"***************************";
      gotoxy(25,8);
      cout<<"       DONOR DETAILS";
      gotoxy(15,10);
      cout<<"DONOR ID   : ";
      cout<<donorid;
      gotoxy(15,12);
      cout<<"DONOR NAME : ";
      gotoxy(15,14);
      cout<<donorname;

      for (int i=0;i<noorg;i++)
	cout<<organ1[i]<<"\t";
	cout<<endl;

   }
void donor::enterddetails()
   {
     gotoxy(15,8);
     cout<<"ENTER ID : ";
     cin>>donorid;
     gotoxy(15,10);
     cout<<"ENTER THE FULLNAME : ";
     gets(donorname);
     gotoxy(15,12);
     cout<<"ENTER THE GENDER : ";
     gets(gender);
     gotoxy(15,14);
     cout<<"ENTER THE AGE : ";
     cin>>age;
     gotoxy(15,16);
     cout<<"ENTER THE NATIONALITY : ";
     gets(nationality);
     gotoxy(15,18);
     cout<<"ENTER THE BLOODGROUP : ";
     gets(bloodgroup2);
     gotoxy(15,20);
     cout<<"ENTER Y FOR PREVIOUS MEDICAL HISTORY ELSE ENTER N : ";
     cin>>prehistory;
     if(prehistory=='Y')
       {
	 cout<<"ENTER THE HISTORY DETAILS";
	 gets(detailsofprehistory);
       }
    cout<<"\n how many organs you want to donate";
    cin>>noorg;
    for (int i=0;i<noorg;i++)
       {
	cout<<"ENTER THE ORGAN "<<i+1<<" : ";
	gets(organ1[i]);
       }
  }

void adddonor()
   {
     clrscr();
     gotoxy(25,5);
     cout<<"QATAR ORGAN DONATION CENTER";
     gotoxy(25,6);
     cout<<"***************************";
     gotoxy(25,8);
     cout<<"       ADDING DONOR MENU";
     fstream x;
     x.open("donor.dat",ios::app|ios::binary);
     donor d;
     d.enterddetails();
     x.write((char *)&d,sizeof(d));
     x.close();
   }
void displayalldonors()
   {
     clrscr();
     gotoxy (15,10);
     cout<<"DONOR ID";
     gotoxy (15,12);
     cout<<"DONOR NAME";
     fstream x;
     x.open("donor.dat",ios::in|ios::binary);
     donor d;
     int r=0;
     while(x.read((char *)&d,sizeof(d)))
       {
	  d.displaydonor(r);
	  r++;
       }
     x.close();
  }
void displaydonorid()
  {
    clrscr();
    gotoxy(25,5);
    cout<<"QATAR ORGAN DONATION CENTER";
    gotoxy(25,6);
    cout<<" *************************** ";
    gotoxy(25,8);
    cout<<"       DISPLAY MENU   ";
    fstream x;
    int di;
    gotoxy(15,12);
    cout<<"\n Enter the donor id to be displayed";
    cin>>di;
    x.open("donor.dat",ios::in|ios::binary);
    donor d;
    while(x.read((char *)&d,sizeof(d)))
      {
	d.displayspedonor();
      }
    x.close();
  }
void deletedonor()
  {
    clrscr();
    int id;
    ifstream x;
    ofstream y;
    x.open("donor.dat",ios::binary);
    y.open("temp.dat",ios::binary);
    gotoxy(25,5);
    cout<<"QATAR ORGAN DONATION CENTER";
    gotoxy(25,6);
    cout<<" ****************************** ";
    gotoxy(25,8);
    cout<<"DELETING THE RECORD";
    gotoxy(25,9);
    cout<<" ******************** ";
    gotoxy(15,15);
    cout<<"ENTER THE ID TO BE IDENTIFIED";
    cin>>id;
    donor d;
    while(x.read((char*)&d,sizeof(d)))
     {
       if(id!=d.retdonorid())
	 {
	    y.write((char*)&d,sizeof(d));
	 }
     }
    remove("donor.dat");
    rename("temp.dat","donor.dat");
    x.close();
    y.close();
  }
void modifydonor()
  {
    clrscr();
    int id;
    fstream x,y;
    x.open("donor.dat",ios::in|ios::binary);
    y.open("temp.dat",ios::out|ios::binary);
    gotoxy(25,5);
    cout<<"QATAR ORGAN DONATION CENTER";
    gotoxy(25,6);
    cout<<"*******************************";
    gotoxy(25,8);
    cout<<" MODIFYING THE RECORD ";
    gotoxy(25,9);
    cout<<" ******************* ";
    gotoxy(15,15);
    cout<<"ENTER THE ID TO BE MODIFIED";
    cin>>id;
    donor d;
    char ch1;
    while(x.read((char*)&d,sizeof(d)))
      {
	if(id!=d.retdonorid())
	 {
	   y.write((char *)&d,sizeof(d));
	 }
	else
	 {
	   d.displayspedonor();
	   cout<<"Do you want to modify this record Y/N";
	   cin>>ch1;
	   if (ch1=='Y' ||ch1=='y')
	     {
	       clrscr();
	       gotoxy(20,10);
	       cout<<"MODIFY";
	       d.enterddetails();
	       y.write((char*)&d,sizeof(d));
	     }
	   else
	       y.write((char*)&d,sizeof(d));
	  }
  }
    x.close();
    y.close();
    remove("donor.dat");
    rename("temp.dat","donor.dat");
  }
void compatibility()
{
donor obj;
patient p;
if(p.retbloodgroup1==obj.retbloodgroup2)
  cout<<"You are compatible to donate blood";
else
  cout<<"You are not compatible to donate blood";
}
void main()
  {
    int ch1=0,ch2=0,ch3=0;
    do
     {
       clrscr();
       gotoxy(25,5);
       cout<<"QATAR ORGAN DONATION CENTER";
       gotoxy(25,6);
       cout<<"***************************";
       gotoxy(25,8);
       cout<<"        MAIN MENU       ";
       gotoxy(15,10);
       cout<<"1. Donor Menu ";
       gotoxy(15,13);
       cout<<"2. Patient Menu ";
       gotoxy(15,16);
       cout<<"3. EXIT ";
       gotoxy(15,19);
       cout<<"Enter your choice : ";
       cin>>ch1;
       switch(ch1)
	 {
	   case 1:
	   do
	    {
	       clrscr();
	       gotoxy(25,5);
	       cout<<"QATAR ORGAN DONATION CENTER";
	       gotoxy(25,6);
	       cout<<"**************************"<<endl;
	       cout<<"    DONOR MENU   ";
	       gotoxy(15,10);
	       cout<<"1. ADD A DONOR ";
	       gotoxy(15,12);
	       cout<<"2. DISPLAY ALL DONORS ";
	       gotoxy(15,14);
	       cout<<"3. DISPLAY SPECIFIC DONORS";
	       gotoxy(15,16);
	       cout<<"4. MODIFY SPECIFIC DONOR ";
	       gotoxy(15,18);
	       cout<<"5. DELETE A DONOR RECORD ";
	       gotoxy(15,20);
	       cout<<"6.EXIT ";
	       gotoxy(15,22);
	       cout<<" ENTER YOUR CHOICE ";
	       cin>>ch2;
	       switch(ch2)
		{
		 case 1:adddonor();
			break;
		 case 2:displayalldonors();
			break;
		 case 3:displaydonorid();
			break;
		 case 4:modifydonor();
			break;
		 case 5:deletedonor();
			break;
		 case 6:exit(0);
		}
	    } while(ch2<=6);
	       break;
	   case 2:
	   do
	    {
	       clrscr();
	       gotoxy(25,5);
	       cout<<"qatar organ donation center";
	       gotoxy(25,6);
	       cout<<"**************************";
	       gotoxy(25,8);
	       cout<<"     patient menu   ";
	       gotoxy(15,10);
	       cout<<"1. add a patient";
	       gotoxy(15,12);
	       cout<<"2. display all patients ";
	       gotoxy(15,14);
	       cout<<"3. display specific patients";
	       gotoxy(15,16);
	       cout<<"4.modify a patient";
	       gotoxy(15,18);
	       cout<<"5.delete a patient";
	       gotoxy(15,20);
	       cout<<"6.exit";
	       gotoxy(15,22);
	       cout<<"enter your choice ";
	       cin>>ch3;
	       switch(ch3)
		 {
		  case 1:addpatient();
			 break;
		  case 2:displayallpatients();
			 break;
		  case 3:displaypatientid();
			 break;
		  case 4:modifypatient();
			 break;
		  case 5:deletepatient();
			 break;
		  case 6:compatibility();
		  case 7:exit(0);
		  }
	    }while(ch3<=7);
	      break;
	   case 3:exit(0);
	 }
       }while(ch1<=3);
    getch();
  }



