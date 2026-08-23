#pragma once
#include<iomanip>
#include<iostream>
#include<cmath>
#include<typeinfo>
#include<fstream>    
#include<chrono>
#include<ctime>
#include<string>
#include<sstream>
#include<vector>
#include "tasks.h"

enum e_page: u_char{
    def = 0,
    list,
    edit,
};
void PageMain();
void PageList();
void PageCreate();
void PageEdit();
void PageDone();
void PageShow();

void autoCout(std::string header, char fill, char edges);
void autoCout(std::string textLeft, std::string textMid, std::string textRight);

std::string formatTime(time_t toFormat, char formatOfTime[64]);
std::string formatTime(time_t toFormat);

void saveToFile();