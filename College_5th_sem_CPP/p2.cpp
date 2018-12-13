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
 * File:   p2.cpp
 * Author: Aniruddha Sarkar
 *
 * Created on 2 November, 2018, 12:23 AM
 */

#include <iostream>

using namespace std;

/*
 * To find the prime numbers within a range provided by user.
 */

class PrimeRange{
public :
    
    void setBounds(int a,int b){
        this->l=a>b?a:b;
        this->s=b>a?a:b;
    }
    
    void print(){
        int i;
        cout<<"[ ";
        for(i=s;i<=l;i++){
            if(this->isPrime(i))cout<<i<<", ";
        }
        cout<<"]\n";
    }
protected:
    int s;
    int l;
    
    bool isPrime(int n){
        int i;
        for(i=2;i<n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
};

int main() {
    PrimeRange pr;
    int a,b;
    cout<<"\nEnter the upper and lower bounds for Prime Range:";
    cin>>a>>b;
    pr.setBounds(a,b);
    pr.print();
    return 0;
}

