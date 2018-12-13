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
 * File:   p5.cpp
 * Author: ani
 *
 * Created on 13 December, 2018, 9:09 PM
 */

#include <iostream>

using namespace std;

/*
 * A Counter class to demonstrate inline and static function/variable.
 */


class Counter{
private :
    static int c;             //static variable
public:            
    static void count(int n);   //static function
    void print();
};

int Counter::c=0;
void Counter::count(int n){
    Counter::c+=n;
}

inline void Counter::print()    //inline function
{
    cout<<c<<endl;
}

int main(int argc, char** argv) {
    int k=-1;
    Counter counter;
    cout<<"Enter any number to count and 0 to exit (separated by whitespace):\n";
    while(k!=0){
        cin>>k;
        if(k>0)Counter::count(k);
    }
    counter.print();
    return 0;
}

