#include"terminal.h"

static int capacity;
static int size;

static char if_line[256];
static char ss_name[256];
static char ss_time[64];

static int colLeft = 35;
static int colMid = 10;
static int colRight = 35;

static int fileCharCount;
static std::string currentPeak;



int currentPage = 0;
void PageMain()
    {

    static char x;
    autoCout("MAIN PAGE", '-', '/');
    std::cout   << std::setw(80) << std::right << "Default page" << std::endl << std::endl

                << std::setw(1) << std::left << "1" << std::setw(79) << std::right << "|CREATE TASK PAGE|" << std::endl
                << std::setw(80) << std::right << "Create new task" << std::endl << std::endl

                << std::setw(1) << std::left << "2" << std::setw(79) << std::right << "|EDIT TASK PAGE|" << std::endl
                << std::setw(80) << std::right << "Edit/Delete/Complete a task" << std::endl << std::endl

                << std::setw(1) << std::left << "3" << std::setw(79) << std::right << "|Display TASK|" << std::endl
                << std::setw(80) << std::right << "Show all tasks" << std::endl

                << std::setw(1) << std::left << "4" << std::setw(79) << std::right << "|SAVE|" << std::endl
                << std::setw(80) << std::right << "Saves data to list file" << std::endl;

    autoCout("MAIN PAGE", '-', '/');
    std::cout << "Please choose a page(0,1,2| Default 0):";
    std::cin >> x;
    std::cout << x;
    std::cin.ignore();
    std::cout << std::endl;
    
            
    switch (x)
        {
    case '0':
        currentPage = 0;
        PageMain();
        break;
    case '1':
        currentPage = 1;
        PageCreate();
        break;
    case '2':
        currentPage = 2;
        PageEdit();
        break;              
    case '3':
        currentPage = 3;
        PageShow();
        break;
    case '4':
        currentPage = 4;
        saveToFile();
        break;
    default:
        std::cout << "Invalid input.";
        std::cout << x;
        break;
        }
    return;
    }

void PageCreate(){
    static std::string name;
    autoCout("Create new task", '-', '/');
    std::cout << "What would be the name of your task?" << "\n" << "Enter the name:";
    while (true)
    {
        getline(std::cin, name); 
        std::cout << name << "\n";void autoCout(std::string textLeft, std::string textMid, std::string textRight);

        if (name.empty())
            {
            std::cout << "Name can't be empty, please enter the name:";
            }
            
            v_structTask.push_back(structTask(name));
            std::cout << "The name u entered is: " << v_structTask.back().name << ".\n";
            PageShow();
            break;
            
        }
    }
        
  
    
void PageEdit(){
    autoCout("Tasks", '-', '/');
    for (size_t i = 0; i < v_structTask.size(); i++)
    {
        static tm *s_tm = localtime(&v_structTask[i].timeCreated);
        char taskTime[256] = "%c %Z";
        strftime(taskTime, sizeof(taskTime), "%m:%d:%Y", s_tm);
        autoCout(std::to_string(i), v_structTask[i].name, taskTime);
        std::cout << v_structTask[i].timeCreated << std::endl;
    }
    std::cout << "Which task would you like to edit: ";
    static int taskNum;
    while (std::cin.fail()){
                    std::cout<<"Please enter and integer(ie 1,2,3 ...):";
                    std::cin >> taskNum;
        }
    if (std::cin >> taskNum)
    {
        if (taskNum)
        {
            std::cout << "Would you like to edit or delete task?" << std::endl;
            std::cout << "Edit = 1, Delete = 2" << std::endl;
            static int editOrDelete;
            std::cin >> editOrDelete;
            while (std::cin.fail() || editOrDelete < 1 || editOrDelete > 2){
                std::cout<<"Please enter either 1 or 2";
                std::cin >> editOrDelete;
            }

            
            switch (editOrDelete)
            {
            case 1:
                std::cin.ignore();
                std::cout << "Please enter the new task::";
                getline(std::cin, v_structTask[taskNum].name);
                v_structTask[taskNum].timeCreated = time(0);
                autoCout(v_structTask[taskNum].name, " ", formatTime(v_structTask[taskNum].timeCreated));
                break;

            case 2:
                v_structTask.erase(v_structTask.begin() + taskNum);
                std::cin.ignore();
                std::cout << "Task deleted successfully :) \n";
                break;

            default:
                std::cout << "ERROR:::::::: \n";
                break;
            }
        }
        
    }
    PageShow();
}

void autoCout(std::string header, char fill, char edges){
    static float width;
    width = 80;
    static int stringWidth = header.length();
    width = (width - stringWidth) / 2;
    std::cout << std::setfill(fill) << std::setw(std::floor(width)) << std::left << edges << std::setw(stringWidth) << header << std::setw(std::ceil(width)) << std::right << edges << std::setfill(' ') << std::endl;
}

void autoCout(std::string textLeft, std::string textMid, std::string textRight){
    std::cout   << std::setw(colLeft) << std::left << textLeft 
                << std::setw(colMid) << std::left << textMid
                << std::setw(colRight) << std::right << textRight
                << std::endl;
}

void PageShow(){
    autoCout("Tasks", '-', '/');
    for (size_t i = 0; i < v_structTask.size(); i++)
    {
        autoCout(v_structTask[i].name, " ",formatTime(v_structTask[i].timeCreated));
        std::cout << v_structTask.size()  << std::endl;
    }
    saveToFile();
    return;
}

std::string formatTime(time_t toFormat, char formatOfTime[64]){
    static tm *s_tm = localtime(&toFormat);
    char formattedTime[256];
    strftime(formattedTime, sizeof(formattedTime), formatOfTime, s_tm);
    return formattedTime;


}

std::string formatTime(time_t toFormat){
    static tm *s_tm = localtime(&toFormat);
    char formattedTime[256];
    strftime(formattedTime, sizeof(formattedTime), "%m:%d:%Y", s_tm);
    return formattedTime;
}

void saveToFile(){
    std::ofstream of_listFile("list",std::ofstream::trunc);
    if (of_listFile.bad()){
        std::cerr << "Could not open file :(\n";
        return;
    }

    for (unsigned int i = 0; i < v_structTask.size(); i++)
    {
        of_listFile << '"' << v_structTask[i].name << '"' << v_structTask[i].timeCreated << std::endl;
    }
    std::clog << "Data saved sucessfully :) \n";
    return;
}