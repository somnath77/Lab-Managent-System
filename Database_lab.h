#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include<windows.h>
#include"machineDb.h"
#include"projectDb.h"
#include<sstream>
using namespace std;
void Dbmenu()
{
	system("cls");
	system("color e4");

	int opt;

	while(1)
	{
		cout<<"\n >>>>>>>>>>>>>>>>>>>>>> Database LAB MANAGEMENT <<<<<<<<<<<<<<<<<<";
		cout<<"\n\t\t\t 1.Machine management";
		cout<<"\n\t\t\t 2.Student management";
		cout<<"\n\t\t \t3.Exit \t\t\t\t"<<__DATE__<<","<<__TIME__;
		cout<<"\n\t\t\t CHOOSE OPTION :";

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

		if(opt==3)
        {
		    system("cls");
		    system("color f0");
		    break;
		}
		switch(opt)
		{
			case 1:
				system("cls");
				MmenuDB();
				//cout<<"\n ";
				break;
			case 2:
				system("cls");
				SmenuDB(); break;
            default:
                cout<<"\n Invalid input.select valid option.";
		}
	}
	//return 0;
}
