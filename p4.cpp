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
 * File:   p4.cpp
 * Author: Aniruddha Sarkar
 *
 * Created on 2 November, 2018, 1:15 AM
 */

#include <iostream>

using namespace std;

/*
 * To find the permutation and combination, given n and r.
 */
class Permutation{
public:
    Permutation(int n=0,int r=0){
        this->n=n;
        this->r=r;
    }
    void setValues(int n,int r){
        this->r=r;
        this->n=n;
    }
    float compute(){
        return (float)this->getFactorial(n)/this->getFactorial(n-r);
    }
private:
    int n,r;
    int getFactorial(int n){
        int f=1;
        while(n>=2)
            f*=n--;
        return f;
    }
};

class Combination{
public:
    Combination(int n=0,int r=0){
        this->n=n;
        this->r=r;
    }
    void setValues(int n,int r){
        this->r=r;
        this->n=n;
    }
    float compute(){
        return (float)this->getFactorial(n)/(this->getFactorial(n-r)*this->getFactorial(r));
    }
private:
    int n,r;
    int getFactorial(int n){
        int f=1;
        while(n>=2)
            f*=n--;
        return f;
    }
};
int main(int argc, char** argv) {
    int n,r;
    Permutation p;
    Combination c;
    cout<<"Enter n and r (of nPr and nCr):";
    cin>>n>>r;
    p.setValues(n,r);
    c.setValues(n,r);
    cout<<"nPr = "<<p.compute()<<endl;
    cout<<"nCr = "<<c.compute()<<endl;
    return 0;
}

