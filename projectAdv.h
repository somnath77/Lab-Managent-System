#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<sstream>

using namespace std;
//>>>>>>>>>>>>>>>>>>>>>>>>class student<<<<<<<<<<<<<<<<<<<<<<<<
class studentAdv
{
	int rno;
	char nm[20];
	char cls[10];
    char date[15];
    char timein[10];
    char labCourse[20];
    char duration[10];
	public:
	    char timeout[10];
	studentAdv()
	{
		rno=0;
		nm[0]=0;
		cls[0]=0;
		date[0]=0;
		timein[0]=0;
		timeout[0]=0;
        labCourse[0]=0;
        duration[0]=0;
	}
	~studentAdv(){}
	void setData(int);
	void display();
	int getNo() { return rno;}
	char *getName() { return nm;}
	char *getClass() { return cls;}
	char *getDate() { return date;}
	char *getTimeIn() { return timein;}
	char *getTimeOut() { return timeout;}
	char *getCourse() { return labCourse;}
	char *getDuration() { return duration;}
}sAdv;
void studentAdv::setData(int a)
{
	rno=a;
	cout<<"\n Enter name:";
	scanf(" %[^\n\t]%*c",nm);
	cout<<"\n Enter class:";
	scanf(" %[^\n\t]%*c",cls);
	cout<<"\n Enter arrival Time(HH:MM:SS):";
	scanf(" %[^\n\t]%*c",timein);
	cout<<"\n Enter Date(Date must be in the form DD/MM/YYYY):";
	scanf(" %[^\n\t]%*c",date);
	int opt1;
	cout<<"Entering For practical press :1 or press :0 =";
	cin>>opt1;
	if(opt1<0 || opt1>1)
        cout<<"\n Invalid input.";
	 if(opt1==1)
     {
        cout<<"\n Enter name of lab course :";
        scanf(" %[^\n\t]%*c",labCourse);
        cout<<"\n Enter duration  of lab course in hours :";
        scanf(" %[^\n\t]%*c",duration);
     }
     else
     {
         labCourse[0]=0;
        duration[0]=0;
     }
}

void studentAdv::display()
{
	ifstream file("stuAdv.dat",ios::in|ios::binary);
	while(file.read((char*)&sAdv,sizeof(sAdv)))
    {
		cout<<"\n"<<setw(3)<<"  "<<rno<<"\t"<<setiosflags(ios::left)<<setw(20)<< nm<<"\t "<<setw(8)<< cls<<"\t "<<setw(8)<<date<<"\t "<<setw(8)<<timein<<"\t "<<setw(20)<<labCourse<<"\t "<<setw(10)<<duration;
		cout<<"\n_____________________________________________________________________________________________________________________________________";
    }
	file.close();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fns to manupulate stu data<<<<<<<<<<<<<<<<<<<
//fn declarations

void addAdv()
{

	ofstream fout("stuAdv.dat",ios::out|ios::app|ios::binary);
	ifstream file("stuAdv.dat",ios::in|ios::binary);
	//ofstream f1("temp1.dat",ios::out|ios::app|ios::binary);
   // cout<<"NOTE: Only CSE students are allowed in Lab.\n";
	int no;
	cout<<"\n Enter roll no:";
	cin>>no;
	int flg=0;
	while(file.read((char*)&sAdv,sizeof(sAdv)))
	{
		if(sAdv.getNo()==no)
		{	cout<<"\n Data already exist.";
			flg=1;
			break;
		}
	}
	if(flg==0)
	{
	    	//file.seekg(0);

            sAdv.setData(no);
            fout.write((char*)&sAdv,sizeof(sAdv));
			/*while(file.read((char*)&s,sizeof(s)))
            {
                f1.write((char*)&s,sizeof(s));
            }
            file.close();
            //f1.close();
            fout.close();
            remove("stu.dat");
            rename("temp1.dat","stu.dat");*/
            cout<<"\n Data has been added successfully.\n\n";
    }
    fout.close();
    file.close();

}


void DeleteAdv()
{
	int no,flg=0;
	ifstream file("stuAdv.dat",ios::in|ios::binary);
	ofstream f1("trashAdv.dat",ios::out|ios::binary|ios::app);
	ofstream f2("tempAdv.dat",ios::out|ios::app|ios::binary);
	cout<<"\n Enter roll no to delete data:";
	 cin>>no;
	while(file.read((char*)&sAdv,sizeof(sAdv)))
	{
			if(sAdv.getNo()==no)
			{
			    cout<<"\n Enter exit Time(HH:MM:SS):";
                scanf(" %[^\n\t]%*c",sAdv.timeout);
				f1.write((char*)&sAdv,sizeof(sAdv));
				flg=1;
			}
			else
				f2.write((char*)&sAdv,sizeof(sAdv));
	}
	file.close();
	f2.close();
	f1.close();
	remove("stuAdv.dat");
	rename("tempAdv.dat","stuAdv.dat");
	if(flg==1)
        cout<<"\n Data has been successfully deleted.\n\n";
    else
        cout<<"\n Data doesn't exist.\n\n";
}

void searchNoAdv()
{

	int no,flg=0;
	cout<<"\n Enter roll no to search:";
	cin>>no;
	ifstream file("stuAdv.dat",ios::in|ios::binary);
	while(file.read((char*)&sAdv,sizeof(sAdv)))
	{
		if(sAdv.getNo()==no)
		{
    cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
    cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(3)<<"  "<<sAdv.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sAdv.getName()<<"\t "<<setw(8)<< sAdv.getClass()<<"\t "<<setw(8)<<sAdv.getDate()<<"\t "<<setw(8)<<sAdv.getTimeIn()<<"\t "<<setw(20)<<sAdv.getCourse()<<"\t "<<setw(16)<<sAdv.getDuration()<<"\n\n";

			flg=1;
			break;
		}

	}
	if(flg==0)
	{
			cout<<"\n Data doesn't exist.\n\n";
	}
	file.close();
}

void searchNmAdv()
{
	char name[15];
	int flg=0;
	cout<<"\n Enter name to search:";
	scanf(" %[^\n\t]%*c",name);
	ifstream file("stuAdv.dat",ios::in|ios::binary);
	while(file.read((char*)&sAdv,sizeof(sAdv)))
	{
		if(strcmp(sAdv.getName(),name)==0)
		{
			cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sAdv.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sAdv.getName()<<"\t "<<setw(8)<< sAdv.getClass()<<"\t "<<setw(8)<<sAdv.getDate()<<"\t "<<setw(8)<<sAdv.getTimeIn()<<"\t "<<setw(20)<<sAdv.getCourse()<<"\t "<<setw(16)<<sAdv.getDuration()<<"\n\n";

			flg=1;
			break;
		}

	}
	if(flg==0)
	{
			cout<<"\n Data doesn't exist.\n\n";

	}

	file.close();
}
void trashAdv()
{
	cout<<"\n==============================================================================================================================================";
	cout<<"\n                                                                ** Previous data **";
	cout<<"\n----------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(8)<<" \t Exit Time"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
	cout<<"\n==============================================================================================================================================";
	ifstream file("trashAdv.dat",ios::in|ios::binary);
	while(file.read((char*)&sAdv,sizeof(sAdv)))
    {
                cout<<"\n"<<setw(3)<<"  "<<sAdv.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sAdv.getName()<<"\t "<<setw(8)<< sAdv.getClass()<<"\t "<<setw(8)<<sAdv.getDate()<<"\t "<<setw(8)<<sAdv.getTimeIn()<<"\t "<<setw(8)<<sAdv.getTimeOut()<<" \t  "<<setw(20)<<sAdv.getCourse()<<"\t "<<setw(16)<<sAdv.getDuration();
                cout<<"\n_______________________________________________________________________________________________________________________________________________";
    }
	cout<<"\n===============================================================================================================================================\n\n";
	file.close();
}
void searchPrevAdv()
{
	int no,flg=0;
	cout<<"\n Enter roll no to search:";
	cin>>no;
	ifstream file("trashAdv.dat",ios::in|ios::binary);
	while(file.read((char*)&sAdv,sizeof(sAdv)))
	{
		if(sAdv.getNo()==no)
		{
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(8)<<" \t Exit Time"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sAdv.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sAdv.getName()<<"\t "<<setw(8)<< sAdv.getClass()<<"\t "<<setw(8)<<sAdv.getDate()<<"\t "<<setw(8)<<sAdv.getTimeIn()<<"\t "<<setw(8)<<sAdv.getTimeOut()<<" \t  "<<setw(20)<<sAdv.getCourse()<<"\t "<<setw(16)<<sAdv.getDuration()<<"\n\n";

			flg=1;
			break;
		}

	}
	if(flg==0)
	{
			cout<<"\n Data doesn't exist.\n\n";
	}
	file.close();
}
void searchByDateAdv()
{
	char date[15];
	int flg=0;int cnt=0;
	cout<<"\n Enter date to see data:";
	scanf(" %[^\n\t]%*c",date);
	ifstream file("trashAdv.dat",ios::in|ios::binary);
	while(file.read((char*)&sAdv,sizeof(sAdv)))
	{
		if(strcmp(sAdv.getDate(),date)==0)
		{
		    if(cnt==0)
            {
                cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
                cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            }
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sAdv.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sAdv.getName()<<"\t "<<setw(8)<< sAdv.getClass()<<"\t "<<setw(8)<<sAdv.getDate()<<"\t "<<setw(8)<<sAdv.getTimeIn()<<"\t "<<setw(20)<<sAdv.getCourse()<<"\t "<<setw(16)<<sAdv.getDuration();
            cnt++;
			flg=1;

		}

	}
	if(flg==0)
	{
			cout<<"\n Data doesn't exist.\n\n";

	}

	file.close();
}
int countAdv()
{
    int cnt=0;
    ifstream file("stuAdv.dat",ios::in|ios::binary);
	while(file.read((char*)&sAdv,sizeof(sAdv)))
		{
		    cnt++;
		}
	return cnt;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  menu   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SmenuAdv()
{
	int opt,d,no;
	while(1)
	{

		cout<<"\n>>>>>>>>>>>>>>>>>>>>> student menu<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

		cout<<"\n\t\t\t1.Add entry";
		cout<<"\n\t\t\t2.Delete entry";
		cout<<"\n\t\t\t3.Display all ";
		cout<<"\n\t\t\t4.search by roll no";
		cout<<"\n\t\t\t5.search by name";
		cout<<"\n\t\t\t6.Previous data";
		cout<<"\n\t\t\t7.No. of Students in lab:";
		cout<<"\n\t\t\t8.Search in previous data";
		cout<<"\n\t\t\t9.See data of a date";
		cout<<"\n\t\t\t10.Exit";
		cout<<"\n\t\t\t Select option:";

		string line;
		while(getline (cin,line))
        {
            stringstream ss(line);
            if(ss >> opt)
            {
                if(ss.eof())
                    break;
            }
            cout<<"\n Invalid input. Enter valid option.";
        }

		if(opt==10)
		{
		    system("cls");
		    break;
		}
		switch(opt)
		{
			case 1:  addAdv(); break;
			case 2:  DeleteAdv();  break;
			case 3:
				cout<<"\n=====================================================================================================================================";
				cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "  Class "<<"\t "<<setw(8)<<"\t  Date \t"<<setw(8)<<"      Arrival Time\t"<<setw(20)<<"   Course Name"<<setw(15)<<"    Pract Duration ";
				cout<<"\n=====================================================================================================================================";
				sAdv.display();
				cout<<"\n=====================================================================================================================================\n\n";
				break;
			case 4:  searchNoAdv(); break;
			case 5:  searchNmAdv(); break;
			case 6:  trashAdv();  break;
			case 7:  cout<<"\n No. of Students in lab:"<<countAdv();  break;
			case 8:  searchPrevAdv(); break;
			case 9:  searchByDateAdv(); break;
			default:
                cout<<"\n Invalid input.select valid option.\n\n";
		}
	}
}

