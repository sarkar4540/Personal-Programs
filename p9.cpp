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
 * File:   p9.cpp
 * Author: ani
 *
 * Created on 14 December, 2018, 1:19 AM
 */

#include <iostream>

using namespace std;

/*
 * To find maximum and add three numbers and demonstrate function/variable pointers.
 */

int *a,*b,*c;

int add(){
    return *a+*b+*c;
}

int max(){
    return (*a>*b)?*a:(*b>*c)?*b:*c;
}
int main(int argc, char** argv) {
    int (*fun)();                   //Declaring Function pointer
    int p,q,r;
    cout<<"Enter three numbers:";
    cin>>p>>q>>r;
    
    a=&p;                           //Assigning a, b and c
    b=&q;
    c=&r;
    
    fun=add;                        //Assigning add function
    
    cout<<"Sum: "<< (*fun)()<<endl; //Calling Function using Pointer
    
    fun=max;                        //Assigning max function
    
    cout<<"Max: "<< (*fun)()<<endl; //Calling Function using pointer
    return 0;
}

