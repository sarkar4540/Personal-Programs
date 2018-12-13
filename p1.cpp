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
 * File:   p1.cpp
 * Author: Aniruddha Sarkar
 *
 * Created on 2 November, 2018, 12:05 AM
 */

#include <iostream>

using namespace std;

/*
 * To find the GCD of 3 numbers
 */
int gcd(int a, int b, int c){
    int i;
    for(i=(a<b&&a<c)?a:(b<a&&b<c)?b:c;i>1;i--){
        if(a%i==0&&b%i==0&&c%i==0)return i;
    }
    return 1;
}

int main(int argc, char** argv) {
    int a,b,c;
    cout<<"Enter 3 numbers for GCD calculation: ";
    cin>>a>>b>>c;
    cout<<"\nThe GCD of "<<a<<", "<<b<<" and "<<c<<" is "<<gcd(a,b,c)<<"\n";
    return 0;
}

