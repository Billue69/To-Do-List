#pragma once
#include <string>
#include <chrono>
#include <vector>
#define _typeTime std::chrono::time_point<std::chrono::system_clock>


struct structTask
{  
    int id;
    
    std::string name;
    enum e_piority : u_char{
        high = 0, medium, low
    };
    e_piority piority = medium;
    std::string task;
    int taskWidth;
    bool isDone = false;

    time_t timeCreated, timePassed, timeDeleted;

    structTask();
    structTask(std::string nameInput);
    structTask(std::string nameInput, time_t time);
};

extern std::vector<structTask> v_structTask;