//
// Created by 32117 on 2025/1/11.
//
#include "manager.h"
#include "boss.h"
#include "iostream"

Boss::Boss(int id,string name,int dId) {
    m_Id=id;
    m_Name=name;
    m_DeptId=dId;
}

void Boss::show_info() {
    cout<<"职工编号: "<< m_Id<<"\t职工姓名: "<< m_Name<<"\t岗位: "<< this->showDeptName()<<"\t岗位职责：管理公司"<<endl;
}

string Boss::showDeptName() {
    return string("老板");
}