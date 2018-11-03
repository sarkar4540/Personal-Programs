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
 * File:   nvp2.cpp
 * Author: Aniruddha Sarkar
 *
 * Created on 4 November, 2018, 1:10 AM
 */

#include <iostream>

using namespace std;

/**
 * Searches for a function definition in the code.
 * @param name
 * @param code
 * @return 
 */
int FindFunctionDefn(const char* name,const char* code){
    int line_count=0;
    char* tname,* tcode,* tcode2;
    tcode=(char *) code;
    do{
        if(*tcode==*name){
            //Following will check the name against the code
            tname=(char *)name;
            tcode2=tcode;
            do{
                if(*tname!=*tcode2){
                    break;
                }
                tname++;
                tcode2++;
            }while(*tname!='\0'&&*tcode2!='\0');
            
            if(*tname=='\0'){
                //Following will check if semicolon(;) occurs first or brace open ({) after name is matched
                do{
                    if(*tcode2=='{'){
                        return line_count+1;
                    }
                    else if(*tcode2==';')break;
                    tcode2++;
                }while(*tcode2!='\0');
            }
        }
        else if(*tcode=='\n'){
            line_count++;
            
        }
        tcode++;
    }while(*tcode!='\0');
    return 0;
}
int main(int argc, char** argv) {
    char strFunctionName[] = "func2"; 
    char strSourceCode[] = "int func1(){ return 0; }\n int func2(){ return 1; }\nint main(int argc, char*argv[]){ return func2(); }\n"; 
    int c=FindFunctionDefn( strFunctionName, strSourceCode );
    
    //Formatted code and print
    int ln=1,i=0;
    char *d=&strSourceCode[0];
    cout<<"____________________________________________________________________";
    do{
        if(*d=='\n'||i==0){
            if(ln==c)cout<<"\n["<<ln<<"] --> ";
            else cout<<"\n["<<ln<<"]      ";
            ln++;
        }
        if(*d!='\n')cout<<*d;
        d++;
        i++;
        
    }while(*d!='\0');
    cout<<"\n____________________________________________________________________";
    cout<<"\nCharacter Count:"<<i<<"\nFound at:"<<c<<"\n";
    
    return 0;
}

