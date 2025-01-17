//
// Created by 32117 on 2025/1/11.
//

#ifndef STAFF_MANAGEMENT___01_MANAGER_H
#define STAFF_MANAGEMENT___01_MANAGER_H
#include <iostream>
#include "worker.h"
using namespace std;



class Manager: public Worker{
public:
    Manager(int id,string name,int dId);
    virtual void show_info();
    virtual string showDeptName();
};


#endif //STAFF_MANAGEMENT___01_MANAGER_H
