#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<sstream>

using namespace std;
//>>>>>>>>>>>>>>>>>>>>>>>>class student<<<<<<<<<<<<<<<<<<<<<<<<
class studentCcf
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
	studentCcf()
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
	~studentCcf(){}
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
}sCcf;
void studentCcf::setData(int a)
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

void studentCcf::display()
{
	ifstream file("stuCcf.dat",ios::in|ios::binary);
	while(file.read((char*)&sCcf,sizeof(sCcf)))
    {
		cout<<"\n"<<setw(3)<<"  "<<rno<<"\t"<<setiosflags(ios::left)<<setw(20)<< nm<<"\t "<<setw(8)<< cls<<"\t "<<setw(8)<<date<<"\t "<<setw(8)<<timein<<"\t "<<setw(20)<<labCourse<<"\t "<<setw(10)<<duration;
		cout<<"\n_____________________________________________________________________________________________________________________________________";
    }
	file.close();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fns to manupulate stu data<<<<<<<<<<<<<<<<<<<
//fn declarations

void addCcf()
{

	ofstream fout("stuCcf.dat",ios::out|ios::app|ios::binary);
	ifstream file("stuCcf.dat",ios::in|ios::binary);
	//ofstream f1("tempCcf.dat",ios::out|ios::app|ios::binary);
    cout<<"NOTE: Only CSE students are allowed in Lab.\n";
	int no;
	cout<<"\n Enter roll no:";
	cin>>no;
	int flg=0;
	while(file.read((char*)&sCcf,sizeof(sCcf)))
	{
		if(sCcf.getNo()==no)
		{	cout<<"\n Data already exist.";
			flg=1;
			break;
		}
	}
	if(flg==0)
	{
	    	//file.seekg(0);

            sCcf.setData(no);
            fout.write((char*)&sCcf,sizeof(sCcf));
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


void DeleteCcf()
{
	int no,flg=0;
	ifstream file("stuCcf.dat",ios::in|ios::binary);
	ofstream f1("trashCcf.dat",ios::out|ios::binary|ios::app);
	ofstream f2("tempCcf.dat",ios::out|ios::app|ios::binary);
	cout<<"\n Enter roll no to delete data:";
	 cin>>no;
	while(file.read((char*)&sCcf,sizeof(sCcf)))
	{
			if(sCcf.getNo()==no)
			{
			    cout<<"\n Enter exit Time(HH:MM:SS):";
                scanf(" %[^\n\t]%*c",sCcf.timeout);
				f1.write((char*)&sCcf,sizeof(sCcf));
				flg=1;
			}
			else
				f2.write((char*)&sCcf,sizeof(sCcf));
	}
	file.close();
	f2.close();
	f1.close();
	remove("stuCcf.dat");
	rename("tempCcf.dat","stuCcf.dat");
	if(flg==1)
        cout<<"\n Data has been successfully deleted.";
    else
        cout<<"\n Data doesn't exist";
}

void searchNoCcf()
{

	int no,flg=0;
	cout<<"\n Enter roll no to search:";
	cin>>no;
	ifstream file("stuCcf.dat",ios::in|ios::binary);
	while(file.read((char*)&sCcf,sizeof(sCcf)))
	{
		if(sCcf.getNo()==no)
		{
    cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
    cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(3)<<"  "<<sCcf.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sCcf.getName()<<"\t "<<setw(8)<< sCcf.getClass()<<"\t "<<setw(8)<<sCcf.getDate()<<"\t "<<setw(8)<<sCcf.getTimeIn()<<"\t "<<setw(20)<<sCcf.getCourse()<<"\t "<<setw(16)<<sCcf.getDuration();

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

void searchNmCcf()
{
	char name[15];
	int flg=0;
	cout<<"\n Enter name to search:";
	scanf(" %[^\n\t]%*c",name);
	ifstream file("stuCcf.dat",ios::in|ios::binary);
	while(file.read((char*)&sCcf,sizeof(sCcf)))
	{
		if(strcmp(sCcf.getName(),name)==0)
		{
			cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sCcf.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sCcf.getName()<<"\t "<<setw(8)<< sCcf.getClass()<<"\t "<<setw(8)<<sCcf.getDate()<<"\t "<<setw(8)<<sCcf.getTimeIn()<<"\t "<<setw(20)<<sCcf.getCourse()<<"\t "<<setw(16)<<sCcf.getDuration();

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
void trashCcf()
{
	cout<<"\n==============================================================================================================================================";
	cout<<"\n                                                                ** Previous data **";
	cout<<"\n----------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(8)<<" \t Exit Time"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
	cout<<"\n==============================================================================================================================================";
	ifstream file("trashCcf.dat",ios::in|ios::binary);
	while(file.read((char*)&sCcf,sizeof(sCcf)))
    {
                cout<<"\n"<<setw(3)<<"  "<<sCcf.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sCcf.getName()<<"\t "<<setw(8)<< sCcf.getClass()<<"\t "<<setw(8)<<sCcf.getDate()<<"\t "<<setw(8)<<sCcf.getTimeIn()<<"\t "<<setw(8)<<sCcf.getTimeOut()<<" \t  "<<setw(20)<<sCcf.getCourse()<<"\t "<<setw(16)<<sCcf.getDuration();
                cout<<"\n_______________________________________________________________________________________________________________________________________________";
    }
	cout<<"\n===============================================================================================================================================";
	file.close();
}
void searchPrevCcf()
{
	int no,flg=0;
	cout<<"\n Enter roll no to search:";
	cin>>no;
	ifstream file("trashCcf.dat",ios::in|ios::binary);
	while(file.read((char*)&sCcf,sizeof(sCcf)))
	{
		if(sCcf.getNo()==no)
		{
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(8)<<" \t Exit Time"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sCcf.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sCcf.getName()<<"\t "<<setw(8)<< sCcf.getClass()<<"\t "<<setw(8)<<sCcf.getDate()<<"\t "<<setw(8)<<sCcf.getTimeIn()<<"\t "<<setw(8)<<sCcf.getTimeOut()<<" \t  "<<setw(20)<<sCcf.getCourse()<<"\t "<<setw(16)<<sCcf.getDuration();

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
void searchByDateCcf()
{
	char date[15];
	int flg=0;int cnt=0;
	cout<<"\n Enter date to see data:";
	scanf(" %[^\n\t]%*c",date);
	ifstream file("trashCcf.dat",ios::in|ios::binary);
	while(file.read((char*)&sCcf,sizeof(sCcf)))
	{
		if(strcmp(sCcf.getDate(),date)==0)
		{
		    if(cnt==0)
            {
                cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
                cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "Class "<<"\t "<<setw(8)<<"\tDate \t "<<setw(8)<<" Arrival Time\t"<<setw(20)<<" \tCourse Name"<<setw(16)<<"Duration(Hours)";
            }
            cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(3)<<"  "<<sCcf.getNo()<<"\t"<<setiosflags(ios::left)<<setw(20)<< sCcf.getName()<<"\t "<<setw(8)<< sCcf.getClass()<<"\t "<<setw(8)<<sCcf.getDate()<<"\t "<<setw(8)<<sCcf.getTimeIn()<<"\t "<<setw(20)<<sCcf.getCourse()<<"\t "<<setw(16)<<sCcf.getDuration();
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
int countCcf()
{
    int cnt=0;
    ifstream file("stuCcf.dat",ios::in|ios::binary);
	while(file.read((char*)&sCcf,sizeof(sCcf)))
		{
		    cnt++;
		}
	return cnt;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  menu   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SmenuCcf()
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
			case 1:  addCcf(); break;
			case 2:  DeleteCcf();  break;
			case 3:
				cout<<"\n=====================================================================================================================================";
				cout<<setw(3)<<"\nRoll no  "<<setiosflags(ios::left)<<setw(20)<<"Name \t"<<setw(8)<< "  Class "<<"\t "<<setw(8)<<"\t  Date \t"<<setw(8)<<"      Arrival Time\t"<<setw(20)<<"   Course Name"<<setw(15)<<"    Pract Duration ";
				cout<<"\n=====================================================================================================================================";
				sCcf.display();
				cout<<"\n=====================================================================================================================================";
				break;
			case 4:  searchNoCcf(); break;
			case 5:  searchNmCcf(); break;
			case 6:  trashCcf();  break;
			case 7:  cout<<"\n No. of Students in lab:"<<countCcf();  break;
			case 8:  searchPrevCcf(); break;
			case 9:  searchByDateCcf(); break;
			default:
                cout<<"\n Invalid input.select valid option.";
		}
	}
}

