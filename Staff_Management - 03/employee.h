//
// Created by 32117 on 2025/1/11.
//
#ifndef STAFF_MANAGEMENT___01_EMPLOYEE_H
#define STAFF_MANAGEMENT___01_EMPLOYEE_H
#include "worker.h"

class Employee:public Worker{
public:
    Employee(int id,string name,int dId);
    virtual void show_info();
    virtual string showDeptName();

};


#endif //STAFF_MANAGEMENT___01_EMPLOYEE_H
