#include<iostream>
#include<cmath>
#include<typeinfo>
#include<fstream>    
#include<chrono>
#include<ctime>
#include<vector>
#include"tasks.h"
#include"terminal.h"

static char if_line[256];
static char ss_name[256];
static char ss_time[64];


void setup();


int main ()
    {
        std::cout << "Hello world" << std::endl;
        setup();
        exit;
    }   

void setup()
    {
    v_structTask.reserve(6);
    std::ifstream if_listFile("list");

    if (if_listFile.is_open()){
        std::cout << "File open :) \n";
        while (if_listFile.getline(if_line, 514)){ // Loops untill reached EOL;
 
            std::stringstream ss_line(if_line);
                if(ss_line.peek() == '"'){
                ss_line.seekg(1,ss_line.beg);
                ss_line.getline(ss_name, 256, '"');
                std::clog << "The name extracted from sstream is: " << ss_name << std::endl;
                ss_line.getline(ss_time,64);
                int intTime = std::stoi(ss_time);
                std::clog << "The time extracted from sstream is: " << static_cast<time_t>(intTime) << std::endl;

                v_structTask.push_back(structTask(ss_name,static_cast<time_t>(intTime)));
                } 
            else{
            std::cout << "Line corrupted" << std::endl;
            }
        }
        if_listFile.close();
    }
    else{
        std::cerr<< "File corrupted :( \n";
    }

        PageMain();
    return;
    }