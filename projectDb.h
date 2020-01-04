#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<sstream>

using namespace std;
//>>>>>>>>>>>>>>>>>>>>>>>>class student<<<<<<<<<<<<<<<<<<<<<<<<
class studentDB
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
	studentDB()
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
	~studentDB(){}
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
}sDB;
void studentDB::setData(int a)
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

void studentDB::display()
{
	ifstream file("stuDb.dat",ios::in|ios::binary);
	while(file.read((char*)&sDB,sizeof(sDB)))
    {
		cout<<"\n"<<setw(3)<<"  "<<rno<<"\t"<<setiosflags(ios::left)<<setw(20)<< nm<<"\t "<<setw(8)<< cls<<"\t "<<setw(8)<<date<<"\t "<<setw(8)<<timein<<"\t "<<setw(20)<<labCourse<<"\t "<<setw(10)<<duration;
		cout<<"\n_____________________________________________________________________________________________________________________________________";
    }
	file.close();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fns to manupulate stu data<<<<<<<<<<<<<<<<<<<
//fn declarations

void addDB()
{

	ofstream fout("stuDb.dat",ios::out|ios::app|ios::binary);
	ifstream file("stuDb.dat",ios::in|ios::binary);
	//ofstream f1("tempDb.dat",ios::out|ios::app|ios::binary);
    cout<<"NOTE: Only CSE students are allowed in Lab.\n";
	int no;
	cout<<"\n Enter roll no:";
	cin>>no;
	int flg=0;
	while(file.read((char*)&sDB,sizeof(sDB)))
	{
		if(sDB.getNo()==no)
		{	cout<<"\n Data already exist.";
			flg=1;
			break;
		}
	}
	if(flg==0)
	{
	    	//file.seekg(0);

            sDB.setData(no);
            fout.write((char*)&sDB,sizeof(sDB));
			/*while(file.read((char*)&s,sizeof(s)))
            {
                f1.write((char*)&s,sizeof(s));
            }
            file.close();
            //f1.close();
            fout.close();
            remove("stu.dat");
            rename("temp1.dat","stu.dat");*/
            cout<<"\n Data has been added successfully.";
    }
    fout.close();
    file.close();

}


void DeleteDB()
{
	int no,flg=0;
	ifstream file("stuDb.dat",ios::in|ios::binary);
	ofstream f1("trashDb.dat",ios::out|ios::binary|ios::app);
	ofstream f2("tempDb.dat",ios::out|ios::app|ios::binary);
	cout<<"\n Enter roll no to delete data:";
	 cin>>no;
	while(file.read((char*)&sDB,sizeof(sDB)))
	{
			if(sDB.getNo()==no)
			{
			    cout<<"\n Enter exit Time(HH:MM:SS):";
                scanf(" %[^\n\t]%*c",sDB.timeout);
				f1.write((char*)&sDB,sizeof(sDB));
				flg=1;
			}
			else
				f2.write((char*)&sDB,sizeof(sDB));
	}
	file.close();
	f2.close();
	f1.close();
	remove("stuDb.dat");
	rename("tempDb.dat","stuDb.dat");
	if(flg==1)
        cout<<"\n Data has been successfully deleted.";
    else
        cout<<"\n Data doesn't exist";
}

void searchNoDB()
{

	int no,flg=0;
	cout<<"\n Enter roll no to search:";
	cin>>no;
	ifstream file("stuDb.dat",ios::in|ios::binary);
	while(file.read((char*)&sDB,sizeof(sDB)))
	{
		if(sDB.getNo()==no)
		{
    cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
    cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(3)<<"  "<<sDB.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sDB.getName()<<"\t "<<setw(8)<< sDB.getClass()<<"\t "<<setw(8)<<sDB.getDate()<<"\t "<<setw(8)<<sDB.getTimeIn()<<"\t "<<setw(20)<<sDB.getCourse()<<"\t "<<setw(16)<<sDB.getDuration();

			flg=1;
			break;
		}

	}
	if(flg==0)
	{
			cout<<"\n Data doesn't exist.";
	}
	file.close();
}

void searchNmDB()
{
	char name[15];
	int flg=0;
	cout<<"\n Enter name to search:";
	scanf(" %[^\n\t]%*c",name);
	ifstream file("stuDb.dat",ios::in|ios::binary);
	while(file.read((char*)&sDB,sizeof(sDB)))
	{
		if(strcmp(sDB.getName(),name)==0)
		{
			cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sDB.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sDB.getName()<<"\t "<<setw(8)<< sDB.getClass()<<"\t "<<setw(8)<<sDB.getDate()<<"\t "<<setw(8)<<sDB.getTimeIn()<<"\t "<<setw(20)<<sDB.getCourse()<<"\t "<<setw(16)<<sDB.getDuration();

			flg=1;
			break;
		}

	}
	if(flg==0)
	{
			cout<<"\n Data doesn't exist.";

	}

	file.close();
}
void trashDB()
{
	cout<<"\n==============================================================================================================================================";
	cout<<"\n                                                                ** Previous data **";
	cout<<"\n----------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(8)<<" \t Exit Time"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
	cout<<"\n==============================================================================================================================================";
	ifstream file("trashDb.dat",ios::in|ios::binary);
	while(file.read((char*)&sDB,sizeof(sDB)))
    {
                cout<<"\n"<<setw(3)<<"  "<<sDB.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sDB.getName()<<"\t "<<setw(8)<< sDB.getClass()<<"\t "<<setw(8)<<sDB.getDate()<<"\t "<<setw(8)<<sDB.getTimeIn()<<"\t "<<setw(8)<<sDB.getTimeOut()<<" \t  "<<setw(20)<<sDB.getCourse()<<"\t "<<setw(16)<<sDB.getDuration();
                cout<<"\n_______________________________________________________________________________________________________________________________________________";
    }
	cout<<"\n===============================================================================================================================================";
	file.close();
}
void searchPrevDB()
{
	int no,flg=0;
	cout<<"\n Enter roll no to search:";
	cin>>no;
	ifstream file("trashDb.dat",ios::in|ios::binary);
	while(file.read((char*)&sDB,sizeof(sDB)))
	{
		if(sDB.getNo()==no)
		{
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(8)<<" \t Exit Time"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sDB.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sDB.getName()<<"\t "<<setw(8)<< sDB.getClass()<<"\t "<<setw(8)<<sDB.getDate()<<"\t "<<setw(8)<<sDB.getTimeIn()<<"\t "<<setw(8)<<sDB.getTimeOut()<<" \t  "<<setw(20)<<sDB.getCourse()<<"\t "<<setw(16)<<sDB.getDuration();

			flg=1;
			break;
		}

	}
	if(flg==0)
	{
			cout<<"\n Data doesn't exist.";
	}
	file.close();
}
void searchByDateDB()
{
	char date[15];
	int flg=0;int cnt=0;
	cout<<"\n Enter date to see data:";
	scanf(" %[^\n\t]%*c",date);
	ifstream file("trashDb.dat",ios::in|ios::binary);
	while(file.read((char*)&sDB,sizeof(sDB)))
	{
		if(strcmp(sDB.getDate(),date)==0)
		{
		    if(cnt==0)
            {
                cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
                cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            }
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sDB.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sDB.getName()<<"\t "<<setw(8)<< sDB.getClass()<<"\t "<<setw(8)<<sDB.getDate()<<"\t "<<setw(8)<<sDB.getTimeIn()<<"\t "<<setw(20)<<sDB.getCourse()<<"\t "<<setw(16)<<sDB.getDuration();
            cnt++;
			flg=1;

		}

	}
	if(flg==0)
	{
			cout<<"\n Data doesn't exist.";

	}

	file.close();
}
int countDB()
{
    int cnt=0;
    ifstream file("stuDb.dat",ios::in|ios::binary);
	while(file.read((char*)&sDB,sizeof(sDB)))
		{
		    cnt++;
		}
	return cnt;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  menu   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SmenuDB()
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
			case 1:  addDB(); break;
			case 2:  DeleteDB();  break;
			case 3:
				cout<<"\n=====================================================================================================================================";
				cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "  Class "<<"\t "<<setw(8)<<"\t  Date \t"<<setw(8)<<"      Arrival Time\t"<<setw(20)<<"   Course Name"<<setw(15)<<"    Pract Duration ";
				cout<<"\n=====================================================================================================================================";
				sDB.display();
				cout<<"\n=====================================================================================================================================";
				break;
			case 4:  searchNoDB(); break;
			case 5:  searchNmDB(); break;
			case 6:  trashDB();  break;
			case 7:  cout<<"\n No. of Students in lab:"<<countDB();  break;
			case 8:  searchPrevDB(); break;
			case 9:  searchByDateDB(); break;
			default:
                cout<<"\n Invalid input.select valid option.";
		}
	}
}

