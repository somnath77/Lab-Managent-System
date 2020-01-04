#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include<windows.h>
#include"CCF_lab.h"
#include"Database_lab.h"
#include"Advanced_lab.h"
#include<sstream>
using namespace std;
int main()
{
	system("cls");
	system("color f0");

	int opt;

	while(1)
	{

		cout<<"\n >>>>>>>>>>>>>>>>>>>>>> LAB MANAGEMENT SYSTEM <<<<<<<<<<<<<<<<<<";
		cout<<"\n\n\n\t\t\t 1.CCF Lab management";
		cout<<"\n\t\t\t 2.Advanced Lab management";
		cout<<"\n\t\t\t 3.Database Lab management";
		cout<<"\n\t\t \t4.Exit \t\t\t\t"<<__DATE__<<","<<__TIME__;
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


		if(opt==4)
            break;
		switch(opt)
		{
			case 1:
				system("cls");
				Ccfmenu();
				//cout<<"\n ";
				break;
			case 2:
				system("cls");
				Advmenu();
				break;
            case 3:
				system("cls");
				Dbmenu();
				break;
            default:
                cout<<"\n Invalid input.select valid option.";
		}
	}
	return 0;
}
