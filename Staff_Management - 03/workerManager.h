#pragma once
#include <iostream>
#include "worker.h"
#include <vector>
#include <fstream>

using namespace std;

class WorkManager
{
public:
    int m_EmpNum=0;
    vector<Worker*> pworker;
    WorkManager();
    void Show_Menu();
    void Add_Emp();
    void Show_Staff();
    void Delete_Emp();
    void Modify_EmpInfo();
    void Search_Emp(int ID);
    void Search_Emp(string name);
    void Search_Emp(int DeptID,int);
    void Sort_Emp();
    void Clear_Info();
    void save();
    void EmpInfo_Init();


    ~WorkManager();
};

