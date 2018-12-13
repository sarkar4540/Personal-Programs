/*
 * Copyright 2018 Aniruddha Sarkar.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   p6.cpp
 * Author: ani
 *
 * Created on 13 December, 2018, 11:58 PM
 */

#include <iostream>

using namespace std;

/*
 * An Employee Class that can calculate bonus based upon the following condition:
 * If service is period less than 10 years then bonus is 5% of the basic pay
 * and if the service period is less than 20 years then bonus is 15% of the basic pay,
 * else bonus is 25% of the basic pay,
 * also how many employees are getting bonus greater than 10%
 */

class Employee{
private:
    char * n;
    int cy,jy;
    float b;
    int getPercentage(){
        return (cy-jy)<10?5:(cy-jy)<20?10:15;
    }
public:
    Employee(char* name, int current_year, int joining_year, float basic_pay){
        n=name;
        cy=current_year;
        jy=joining_year;
        b=basic_pay;
    }
    float getBonus(){
        return b*getPercentage()/100;
    }
    bool getBonusMoreThan10Percent(){
        return getPercentage()>=10;
    }
    
};
int main(int argc, char** argv) {
    char name[20];
    int current_year,joining_year;
    float basic_pay;
    Employee* employee;
    cout<<"Enter the Name of the Employee:";
    cin>>name;
    cout<<"Enter "<<name<<"'s Joining Year:";
    cin>>joining_year;
    cout<<"Enter "<<name<<"'s Basic Pay:";
    cin>>basic_pay;
    cout<<"Enter Current Year:";
    cin>>current_year;
    employee=new Employee(name,current_year,joining_year,basic_pay);
    cout<<"\n"<<name<<"'s bonus is "<<employee->getBonus()<<" .\n";
    if(employee->getBonusMoreThan10Percent())cout<<name<<"'s bonus is more than 10%.\n";
    return 0;
}

