//
// Created by 32117 on 2025/1/11.
//

#ifndef STAFF_MANAGEMENT___01_WORKER_H
#define STAFF_MANAGEMENT___01_WORKER_H
#include <iostream>
using namespace std;
#define FILENAME "worker_info.txt"
class Worker{
public:
    virtual void show_info()=0;
    virtual string showDeptName()=0;
    int m_Id;
    string  m_Name;
    int m_DeptId;
};




#endif //STAFF_MANAGEMENT___01_WORKER_H
