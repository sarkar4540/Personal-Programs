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
 * File:   p7.cpp
 * Author: ani
 *
 * Created on 14 December, 2018, 12:22 AM
 */

#include <iostream>

using namespace std;

/*
 * A Max Class to demonstrate nesting of member functions and finding the maximum of two numbers.
 */

class Max{
private:
    int a,b;
public:
    int getMax();
    Max(int a,int b){
        this->a=a;
        this->b=b;
    }
    void print(){
        cout<<"Maximum: "<<getMax();//Used previously declared getMax() member function.
    }
};

int Max::getMax(){
    return a>b?a:b;
}
int main(int argc, char** argv) {
    Max* max;
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    max=new Max(a,b);
    max->print();
    return 0;
}

