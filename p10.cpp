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
 * File:   p10.cpp
 * Author: ani
 *
 * Created on 14 December, 2018, 1:39 AM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

void isSquare(const int& a,const int& b, bool& result){
    result=(a==b*b)||(b==a*a);
}

class NumberSquare{
private:
    int a,b;
public:
    NumberSquare(int a,int b){
        this->a=a;
        this->b=b;
    }
    bool contains(int a){                   //Call by value
        return (a==this->a||a==this->b);
    }
    void isSquareOfAnother(bool& result){   //Call by reference
        isSquare(a,b,result);
    }
};

int main(int argc, char** argv) {
    int a,b;
    bool result;
    cout<<"Enter two numbers:\n";
    cin>>a>>b;
    NumberSquare ns(a,b);
    cout<<"Is one number 5? "<<(ns.contains(5)?"yes":"no")<<endl;    //contains(int) is called by value
    ns.isSquareOfAnother(result);                   //isSquareofAnother(bool) is called by reference
    cout<<"Is one number square of another? "<<(result?"yes":"no")<<endl;  
    return 0;
}

