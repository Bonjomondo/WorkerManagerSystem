//
// Created by 32117 on 2025/1/11.
//

#ifndef STAFF_MANAGEMENT___01_BOSS_H
#define STAFF_MANAGEMENT___01_BOSS_H

#include <iostream>
#include "worker.h"
using namespace std;

class Boss: public Worker{
public:
    Boss(int id,string name,int dId);
    virtual void show_info();
    virtual string showDeptName();
};

#endif //STAFF_MANAGEMENT___01_BOSS_H
