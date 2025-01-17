#include "workerManager.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkManager::WorkManager() {
}

WorkManager::~WorkManager()
{
    for(auto worker:pworker){
        delete worker;
    }
    pworker.clear();
}

void WorkManager::Show_Menu()
{
    cout << "Welcome to the Employee Management System!" << endl;
    cout << "0. Exit the management program" << endl;
    cout << "1. Add employee information" << endl;
    cout << "2. Display employee information" << endl;
    cout << "3. Delete resigned employee" << endl;
    cout << "4. Modify employee information" << endl;
    cout << "5. Search for employee information" << endl;
    cout << "6. Sort by employee ID" << endl;
    cout << "7. Clear all records" << endl;
}
void WorkManager::Add_Emp() {
    cout<<"输入添加职工数量"<<endl;
    int addNum=0;
    cin>>addNum;
    if(addNum<=0){
        cout<<"invalid input"<<endl;
        return;
    }
    while (addNum--){
        int id;
        string name;
        int dselect;
        cout<<"input id:"<<endl;
        cin>>id;
        cout<<"input name:"<<endl;
        cin>>name;
        cout<<"input dselect:"<<endl;
        cout<<"1、ordinary employee"<<endl;
        cout<<"2、manager"<<endl;
        cout<<"3、boss"<<endl;
        cin>>dselect;
        Worker *worker=NULL;
        switch (dselect) {
            case  1:
                worker=new Employee(id,name,dselect);
                pworker.push_back(worker);
                break;
            case  2:
                worker=new Manager(id,name,dselect);
                pworker.push_back(worker);
                break;
            case  3:
                worker=new Boss(id,name,dselect);
                pworker.push_back(worker);
                break;
            default:
                cout<<"invalid input"<<endl;
                continue;
        }
        m_EmpNum++;
        save();
    }
}

void WorkManager::Show_Staff() {
//    for (auto it=pworker.begin();it!=pworker.end();it++) {
//        (*it)->show_info();
//    }
    string line;
    fstream fs(FILENAME);
    if(!fs){
        cout<<"failed to open file"<<endl;
    } else{
        while (getline(fs,line)){
            cout<<line<<endl;
        }
    }
    fs.close();
}

void WorkManager::Delete_Emp() {
    cout<<"please enter the employee ID you want to delete"<<endl;
    int ID;
    cin>>ID;
    for (auto it=pworker.begin(); it!=pworker.end() ; ++it) {
        if((*it)->m_Id==ID){
            pworker.erase(it);
            cout<<"The employee with ID :"<<ID<<" has been deleted successfully"<<endl;
            save();
            return;
        }
    }
    save();
    cout<<"The employee with ID:"<<ID<<" was not found"<<endl;
}

void WorkManager::Modify_EmpInfo() {
    cout<<"input the employee ID you want to modify"<<endl;
    int ID;
    cin>>ID;
    for (auto it=pworker.begin(); it!=pworker.end() ; ++it) {
        if((*it)->m_Id==ID){
            cout<<"input new name: "<<endl;
            cin>>(*it)->m_Name;
            cout<<"1、ordinary employee"<<endl;
            cout<<"2、manager"<<endl;
            cout<<"3、boss"<<endl;
            cout<<"input new DeptId"<<endl;
            cin>>(*it)->m_DeptId;
            cout<<"The employee with ID: "<<ID<<" has been modified successfully"<<endl;
            save();
            return;
        }
    }
    cout<<"The employee with ID: "<<ID<<"was not found"<<endl;
}

void WorkManager::Search_Emp(int ID){
    for (auto it=pworker.begin(); it!=pworker.end() ; ++it) {
        if((*it)->m_Id==ID){
            (*it)->show_info();
            return;
        }
    }
    cout<<"The employee with ID:"<<ID<<" was not found"<<endl;
}
void WorkManager::Search_Emp(string name){
    int flag=0;
    for (auto it=pworker.begin(); it!=pworker.end() ; ++it) {
        if((*it)->m_Name==name){
            (*it)->show_info();
            flag=1;
        }
    }
    if(!flag)
        cout<<"The employee with ID:"<<name<<" was not found"<<endl;
}
void WorkManager::Search_Emp(int DeptID,int){
    int flag=0;
    for (auto it=pworker.begin(); it!=pworker.end() ; ++it) {
        if((*it)->m_DeptId==DeptID){
            (*it)->show_info();
            flag=1;
        }
    }
    if(!flag)
        cout<<"The employee with ID:"<<DeptID<<" was not found"<<endl;
}
void WorkManager::Sort_Emp(){
    sort(pworker.begin(),pworker.end(),[](Worker* a,Worker *b){
        return a->m_Id<b->m_Id;
    });
    save();
    cout<<"Employees have been sorted by ID."<<endl;
}
void WorkManager::Clear_Info(){
    pworker.clear();
    save();
    cout<<"All employee records have been cleared."<<endl;
}

void WorkManager::save() {
//    fs.seekg(0,ios::beg);
//    for(int i=0;i<m_EmpNum;i++){
//        fs<<pworker[i]->m_Id<<' '<<pworker[i]->m_Name<<' '<<pworker[i]->m_DeptId<<endl;
//    }

    ofstream ofs(FILENAME,ios::out|ios::trunc);
    for(auto worker:pworker){
        ofs<<worker->m_Id<<' '<<worker->m_Name<<' '<<worker->m_DeptId<<endl;
    }
    ofs.close();
}

void WorkManager::EmpInfo_Init() {
    fstream fs(FILENAME);
    if(!fs.is_open()){
        cout<<"failed to open file"<<endl;
    }else{
        string line;
        while (getline(fs,line)){
            stringstream ss(line);
            int id,deptId;
            string name;
            ss>>id>>name>>deptId;
            Worker *worker=NULL;
            switch (deptId) {
                case 1:
                    worker=new Employee(id,name,deptId);
                    break;
                case 2:
                    worker=new Manager(id,name,deptId);
                    break;
                case 3:
                    worker=new Boss(id,name,deptId);
                    break;
//                default:
            }
            pworker.push_back(worker);
        }
    }
    fs.close();
}
