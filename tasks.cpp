#include "tasks.h"



structTask::structTask(std::string nameInput)
{   
    id = v_structTask.size();
    timeCreated = time(0);
    name = nameInput;
    if (v_structTask.capacity() == v_structTask.size())
            {
                v_structTask.reserve(v_structTask.capacity() + 6);
            }
    
}
structTask::structTask()
{
    id = v_structTask.size();
    name = "";
    if (v_structTask.capacity() == v_structTask.size())
            {
                v_structTask.reserve(v_structTask.capacity() + 6);
            }
    
}
structTask::structTask(std::string nameInput, time_t time){
    id = v_structTask.size();
    timeCreated = time;
    name = nameInput;
    
    if (v_structTask.capacity() == v_structTask.size())
            {
                v_structTask.reserve(v_structTask.capacity() + 6);
            }
}

std::vector<structTask> v_structTask;