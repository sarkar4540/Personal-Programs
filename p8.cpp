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
 * File:   p8.cpp
 * Author: ani
 *
 * Created on 14 December, 2018, 12:35 AM
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * A class Cube to merge to cubes by volume and demonstrate friend functions and global variable.
 */

int edit_count=0;

class Cube{
private:
    float edge;
public:
    friend void merge(Cube&,Cube&);//Friend Function Definition
    void printEdge(){
        cout<<"The current edge is: "<<edge<<endl;
    }
    Cube(float edge){
        this->edge=edge;
    }
};
/**
 * Add cubes by volume
 * @param cube the cube to be added to
 * @param cube1 the cube to be added
 */
void merge(Cube& cube,Cube& cube1){
    //accessing private variables (edges) of cubes
    cube.edge=pow(pow(cube.edge,3)+pow(cube1.edge,3),1.0/3);  
    //accessing global variable
    ::edit_count++;                                            
}

int main(int argc, char** argv) {
    Cube cube(0);
    float k=-1;
    while(k!=0){
        cout<<"Enter the edge of the cube to be added, else 0 to exit:";
        cin>>k;
        if(k>0){
            Cube cube1(k);
            merge(cube,cube1);
            cube.printEdge(); 
        }
    }
    cout<<"\nTotal additions: "<<edit_count<<endl;
    return 0;
}

