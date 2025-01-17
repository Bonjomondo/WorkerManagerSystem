//
// Created by 32117 on 2025/1/11.
//
#include "manager.h"
#include "iostream"

Manager::Manager(int id,string name,int dId) {
    m_Id=id;
    m_Name=name;
    m_DeptId=dId;
}

void Manager::show_info() {
    cout<<"职工编号: "<< m_Id<<"\t职工姓名: "<< m_Name<<"\t岗位: "<< this->showDeptName()<<"\t岗位职责：完成老板交给的任务，并下发给员工"<<endl;
}

string Manager::showDeptName() {
    return string("经理");
}
