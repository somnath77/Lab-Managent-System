#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include<windows.h>
#include"machineAdv.h"
#include"projectAdv.h"
#include<sstream>
using namespace std;
void Advmenu()
{
	system("cls");
	system("color e4");

	int opt;

	while(1)
	{
		cout<<"\n >>>>>>>>>>>>>>>>>>>>>> Advanced LAB MANAGEMENT <<<<<<<<<<<<<<<<<<";
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
            cout<<"\n Invalid input. Enter valid option...\n\n";
        }

		if(opt==3)
		{
		    system("cls");
		    system("color f0");
		    break;
		}
		/*if(opt<'48'||opt>'57')
        {
            cout<<"nn";
            break;
        }*/

		switch(opt)
		{
			case 1:
				system("cls");
				MmenuAdv();
				//cout<<"\n ";
				break;
			case 2:
				system("cls");
				SmenuAdv(); break;
            default:
                cout<<"\n Invalid input.select valid option.\n\n";
		}
	}
	//return 0;
}
