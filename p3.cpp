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
 * File:   p3.cpp
 * Author: Aniruddha Sarkar
 *
 * Created on 2 November, 2018, 12:47 AM
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * To check whether palindrome or perfect, given a number.
 */

class PerfectNumber{
public:
    PerfectNumber(int n=0){
        this->n=n;
    }
    
    void setNumber(int n){
        this->n=n;
    }
    
    bool isPerfect(){
        int sum=0,i;
        for(i=1;i<this->n;i++){
            if(this->n%i==0)sum+=i;
        }
        return sum==this->n;
    }
protected:
    int n;
};

class PalindromeNumber{
public:
    PalindromeNumber(int n=0){
        this->n=n;
    }
    
    bool isPalindrome(){
        int n=this->countDigits(),i;
        for(i=0;i<n;i++){
            if(this->getNthDigit(i)!=this->getNthDigit(n-i-1))return false;
        }
        return true;
    }
    
    void setNumber(int n){
        this->n=n;
    }
    
protected:
    int n;
    
    int countDigits(){
        int i=0,n=this->n;
        while(n>0){
            i++;
            n/=10;
        }
        return i;
    }
    
    int getNthDigit(int n){
        return (this->n/(int)pow(10,n))%10;
    }
};

int main(int argc, char** argv) {
    PerfectNumber prn;
    PalindromeNumber pdn;
    int n;
    cout<<"Enter the number:";
    cin>>n;
    prn.setNumber(n);
    pdn.setNumber(n);
    cout<<"\n"<<n<<(prn.isPerfect()&&pdn.isPalindrome()?" is Perfect and Palindrome":
        prn.isPerfect()?" is Perfect but not Palindrome":
            pdn.isPalindrome()?" is Palindrome but not Perfect":
                " is neither Palindrome nor Perfect")<<endl;
    return 0;
}

