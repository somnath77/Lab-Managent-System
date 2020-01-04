#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<sstream>
using namespace std;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   class creation   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class machineAdv
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
}mAdv;

void machineAdv::set(int a)
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
void AddAdv()
{
	int no,flg=0;
	cout<<"\n Enter machine no:";
	cin>>no;
	ifstream in("machAdv.dat",ios::in|ios::binary);
	ofstream out("machAdv.dat",ios::out|ios::app|ios::binary);
	while(in.read((char*)&mAdv,sizeof(mAdv)))
	{
		if(mAdv.getNo()==no)
		{
			cout<<"\n Data already exist.\n";
			flg=1;
			break;
		}
	}
	if(flg==0)
	{
		mAdv.set(no);
		out.write((char*)&mAdv,sizeof(mAdv));
		//m.cnt++;
		cout<<"\n Data has been added succesfully.\n";
	}
	out.close();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  display fn  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void machineAdv::display()
{
	ifstream fin("machAdv.dat",ios::in|ios::binary);
			//cout<<"\n No \t os\tworkc\tacces";
	while(fin.read((char*)&mAdv,sizeof(mAdv)))
	{
		cout<<"\n\t"<<setiosflags(ios::left)<<setw(10)<<No<<"\t "<<setw(10)<<os<<"\t    "<<setw(10)<<workc<<"\t  "<<setw(10)<<acces<<"\t    "<<setw(10)<<netcon";
	}
	fin.close();
}
int McountAdv()
{
    int cnt=0;
    ifstream fin("machAdv.dat",ios::in|ios::binary);
	while(fin.read((char*)&mAdv,sizeof(mAdv)))
        cnt++;
    fin.close();
    return cnt;
}






//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  delete fn   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void machineAdv::Delete()
{

	ifstream in("machAdv.dat",ios::in|ios::binary);
	//ofstream in("machAdv.dat",ios::out|ios::app|ios::binary);
	ofstream out("tempAdv.dat",ios::out|ios::app|ios::binary);
	int no,flg=0;
	cout<<"\n Enter machine no to delete data:";
	cin>>no;
	while(in.read((char*)&mAdv,sizeof(mAdv)))
	{
		if(mAdv.getNo()==no)
		{
			flg=1;
			continue;
		}
		else
			out.write((char*)&mAdv,sizeof(mAdv));
	}
	if(flg==1)
	{
		in.close();
		out.close();
		remove("machAdv.dat");
		rename("tempAdv.dat","machAdv.dat");
		cout<<"\n Data has been deleted successfully.\n\n";
	//	cnt--;
	}
	else
		 	cout<<"\n Data doesn't exist\n\n";
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>     fn to update working conition <<<<<<<<<<<<<<<<<<<<<<<<
void machineAdv::update()
{

	ifstream in("machAdv.dat",ios::in|ios::binary);
	//ofstream in("machAdv.dat",ios::out|ios::app|ios::binary);
	ofstream out("tempAdv.dat",ios::out|ios::app|ios::binary);
	int no,flg=0;
	cout<<"\n Enter machine no to update data:\n\n";
	cin>>no;
	while(in.read((char*)&mAdv,sizeof(mAdv)))
	{
		if(mAdv.getNo()==no)
		{
			mAdv.set(no);
			out.write((char*)&mAdv,sizeof(mAdv));
			flg=1;
			continue;
		}
		else
			out.write((char*)&mAdv,sizeof(mAdv));
	}
	if(flg==1)
	{
		in.close();
		out.close();
		remove("machAdv.dat");
		rename("tempAdv.dat","machAdv.dat");
		cout<<"\n Data has been updated successfully.\n\n";
	}
	else
		 	cout<<"\n Data doesn't exist \n\n";
}





//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  main fn  ,<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void MmenuAdv()
{
	//cout<<"\n NO. of objects:"<<m.count;

	int opt,d;
	while(1)
	{
	    system("cls");
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
            cout<<"\n Invalid input. Enter valid option.\n\n";
        }

		if(opt==6)
		{
		    system("cls");
		    break;
		}

		switch(opt)
		{
			case 1:  AddAdv(); break;
			case 2:  mAdv.Delete();  break;
			case 3:
				cout<<"\n============================================================================================";
				cout<<"\n\t"<<setw(10)<<"machine.no"<<"\t"<<setw(10)<<"Oper.systm"<<"\t"<<setw(10)<<"workcon"<<"\t"<<setw(10)<<"accesorie"<<"\t"<<setw(10)<<"Net con";
				cout<<"\n--------------------------------------------------------------------------------------------";
				mAdv.display();
				cout<<"\n=============================================================================================\n\n";
				break;
			case 4:
				mAdv.update();
				break;
			case 5:
				cout<<"\n Machine cnt:"<<McountAdv();
				break;
            default:
                 cout<<"\n Invalid input. select valid option\n\n";
                break;
		}
		system("pause");
	}
	//return 0;
}
