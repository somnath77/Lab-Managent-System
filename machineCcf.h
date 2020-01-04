#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<sstream>
//#include<conio.h>
using namespace std;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   class creation   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class machineCcf
{

		int No;
		char os[10];
		char workc[10];
		char acces[10];
		char netcon[10];
	//	static int cnt;
	public:
		int getNo()  { return No; }
		void set(int);
		void Delete();
		void display();
		void update();
}mCcf;

void machineCcf::set(int a)
{
	No=a;
	cout<<"\n Enter operating systeam installed(windows/ubuntu/both):";
	cin>>os;
	cout<<"\nEnter working condition(good/bad) :";
	cin>>workc;
	cout<<"\n Are accessories present ?(yes/no):";
	cin>>acces;
	cout<<"\nIs Internet conection there?(yes/no):";
	cin>>netcon;

}
//<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  add fn  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void AddCcf()
{
	int no,flg=0;
	cout<<"\n Enter machine no:";
	cin>>no;
	ifstream in("machCcf.dat",ios::in|ios::binary);
	ofstream out("machCcf.dat",ios::out|ios::app|ios::binary);
	while(in.read((char*)&mCcf,sizeof(mCcf)))
	{
		if(mCcf.getNo()==no)
		{
			cout<<"\n Data already exist.\n";
			flg=1;
			break;
		}
	}
	if(flg==0)
	{
		mCcf.set(no);
		out.write((char*)&mCcf,sizeof(mCcf));
		//m.cnt++;
		cout<<"\n Data has been added succesfully.\n";
	}
	out.close();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  display fn  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void machineCcf::display()
{
	ifstream fin("machCcf.dat",ios::in|ios::binary);
			//cout<<"\n No \t os\tworkc\tacces";
	while(fin.read((char*)&mCcf,sizeof(mCcf)))
	{
		cout<<"\n\t"<<setiosflags(ios::left)<<setw(10)<<No<<"\t "<<setw(10)<<os<<"\t    "<<setw(10)<<workc<<"\t  "<<setw(10)<<acces<<"\t    "<<setw(10)<<netcon;
	}
	fin.close();
}
int McountCcf()
{
    int cnt=0;
    ifstream fin("machCcf.dat",ios::in|ios::binary);
	while(fin.read((char*)&mCcf,sizeof(mCcf)))
        cnt++;
    fin.close();
    return cnt;
}






//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  delete fn   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void machineCcf::Delete()
{

	ifstream in("machCcf.dat",ios::in|ios::binary);
	//ofstream in("machCcf.dat",ios::out|ios::app|ios::binary);
	ofstream out("tempCcf.dat",ios::out|ios::app|ios::binary);
	int no,flg=0;
	cout<<"\n Enter machine no to delete data:";
	cin>>no;
	while(in.read((char*)&mCcf,sizeof(mCcf)))
	{
		if(mCcf.getNo()==no)
		{
			flg=1;
			continue;
		}
		else
			out.write((char*)&mCcf,sizeof(mCcf));
	}
	if(flg==1)
	{
		in.close();
		out.close();
		remove("machCcf.dat");
		rename("tempCcf.dat","machCcf.dat");
		cout<<"\n Data has been deleted successfully.";
	//	cnt--;
	}
	else
		 	cout<<"\n Data doesn't exist";
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>     fn to update working conition <<<<<<<<<<<<<<<<<<<<<<<<
void machineCcf::update()
{

	ifstream in("machCcf.dat",ios::in|ios::binary);
	//ofstream in("machCcf.dat",ios::out|ios::app|ios::binary);
	ofstream out("tempCcf.dat",ios::out|ios::app|ios::binary);
	int no,flg=0;
	cout<<"\n Enter machine no to update data:";
	cin>>no;
	while(in.read((char*)&mCcf,sizeof(mCcf)))
	{
		if(mCcf.getNo()==no)
		{
			mCcf.set(no);
			out.write((char*)&mCcf,sizeof(mCcf));
			flg=1;
			continue;
		}
		else
			out.write((char*)&mCcf,sizeof(mCcf));
	}
	if(flg==1)
	{
		in.close();
		out.close();
		remove("machCcf.dat");
		rename("tempCcf.dat","machCcf.dat");
		cout<<"\n Data has been updated successfully.";
	}
	else
		 	cout<<"\n Data doesn't exist";
}





//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  main fn  ,<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void MmenuCcf()
{
	//cout<<"\n NO. of objects:"<<m.count;

	int opt,d;
	while(1)
	{
		cout<<"\n>>>>>>>>>>>>>>>>>>>>> Machine menu<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
		cout<<"\n\t\t\t1.Add data";
		cout<<"\n\t\t\t2.Delete data";
		cout<<"\n\t\t\t3.Display all data ";
		cout<<"\n\t\t\t4.Update working condition";
		cout<<"\n\t\t\t5.Machine count";
		cout<<"\n\t\t\t6.Exit";
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

		if(opt==6)
		{
		    system("cls");
		    break;
		}
		switch(opt)
		{
			case 1:  AddCcf(); break;
			case 2:  mCcf.Delete();  break;
			case 3:
				cout<<"\n============================================================================================";
				cout<<"\n\t"<<setw(10)<<"machine.no"<<"\t"<<setw(10)<<"Oper.systm"<<"\t"<<setw(10)<<"workcon"<<"\t"<<setw(10)<<"accesorie"<<"\t"<<setw(10)<<"Net con";
				cout<<"\n--------------------------------------------------------------------------------------------";
				mCcf.display();
				cout<<"\n=============================================================================================";
				break;
			case 4:
				mCcf.update();
				break;
			case 5:
				cout<<"\n Machine cnt:"<<McountCcf();
				break;
            default:
                cout<<"\n Invalid input.select valid option.";
		}
	}
	//return 0;
}
