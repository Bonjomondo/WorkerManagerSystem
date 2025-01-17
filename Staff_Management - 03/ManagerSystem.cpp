#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main()
{
    Worker *worker;
    worker=new Employee(1,"zhang",1);
    worker->show_info();
    delete worker;

    worker=new Manager(2,"wnag",2);
    worker->show_info();
    delete worker;

    worker=new Boss(3,"zhao",3);
    worker->show_info();
    delete worker;

    WorkManager workermanager;
    workermanager.EmpInfo_Init();
    int command;
    while (1){
        workermanager.Show_Menu();
        cin >> command;
        switch (command)
        {
            case 0:
                cout<<"welcome to use next time"<<endl;
                return 0;
                break;
            case 1:
                workermanager.Add_Emp();// add employee infomation
                break;
            case 2:
                workermanager.Show_Staff();// display employee infomation
                break;
            case 3:
                workermanager.Delete_Emp();
                // delete resigned employees
                break;
            case 4:
                workermanager.Modify_EmpInfo();
                // modify employee infomation
                break;
            case 5:
                // find employee infomation
                int choice;
                cout<<"1、query by ID"<<endl;
                cout<<"2、query by name"<<endl;
                cout<<"2、query by DeptID"<<endl;
                cin>>choice;
                if(choice==1) {
                    cout << "please enter the employee ID you want to search" << endl;
                    int ID;
                    cin>>ID;
                    workermanager.Search_Emp(ID);
                } else if(choice==2) {
                    cout << "please enter the employee name you want to search" << endl;
                    string name;
                    cin >> name;
                    workermanager.Search_Emp(name);
                } else if(choice==3){
                    cout << "please enter the employee DepartmentID you want to search" << endl;
                    int DeptID;
                    cin>>DeptID;
                    workermanager.Search_Emp(DeptID,1);
                }
                break;
            case 6:
                workermanager.Sort_Emp();
                // sort by number
                break;
            case 7:
                workermanager.Clear_Info();
                // clear all documents
                break;
            default:
                cout << "instruction ignore" << endl;
        }
    }
}

