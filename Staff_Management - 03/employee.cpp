//
// Created by 32117 on 2025/1/11.
//
#include "employee.h"

Employee::Employee(int id, std::string name, int dId) {
    m_Id=id;
    m_Name=name;
    m_DeptId=dId;
}

void Employee::show_info() {
    cout<<"职工编号: "<< m_Id<<"\t职工姓名: "<< m_Name<<"\t岗位: "<< this->showDeptName()<<"\t岗位职责：完成经历交给的任务"<<endl;
}

string Employee::showDeptName(){
    return string("员工");
}








