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
 * File:   nvp1.cpp
 * Author: sarkar4540@gmail.com
 *
 * Created on 3 November, 2018, 9:13 PM
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * Problem statement:
 * 
 * Implement a 3D vector class, providing a useful set of methods or functions for the class and any other 
 * related classes. Discuss the design choices you make in your implementation, please upload your code and 
 * design decisions either in google docs or post it in GitHub, bitbucket or any other code sharing 
 * platform.
 */

/*
 * 3D Vector class
 */
class Vector3D{
protected:
    double x,y,z;
public:
    Vector3D(double x=0,double y=0,double z=0){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    
    /**
     * Shifts the origin of the vector.
     * @param origin The origin is shifted using the components of this vector
     * @return the vector with shifted origin
     */
    Vector3D shiftOrigin(Vector3D origin){
        Vector3D v(this->x-origin.x,this->y-origin.y,this->z-origin.z);
        return v;
    }
    
    /**
     * Get the magnitude of the vector
     * @return the magnitude of the vector
     */
    double getMagnitude(){
        return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
    }
    
    /**
     * Get the x-component of the vector
     * @return x-component of the vector
     */
    double getXComponent(){
        return this->x;
    }
    
    /**
     * Get the y-component of the vector
     * @return y-component of the vector
     */
    double getYComponent(){
        return this->y;
    }
    
    /**
     * Get the x-component of the vector
     * @return x-component of the vector
     */
    double getZComponent(){
        return this->z;
    }
    
    /**
     * Multiplies the vector with a scalar quantity
     * @param s the scalar value
     * @return the product
     */
    Vector3D multiply(double s){
        Vector3D p(this->x*s,
        this->y*s,
        this->z*s);
        return p;
    }
    
    /**
     * Adds a vector with this vector.
     * @param vector the vector to be added.
     * @return the sum
     */
    Vector3D add(Vector3D vector){
        Vector3D s(this->x+vector.x,this->y+vector.y,this->z+vector.z);
        return s;
    }
    
    /**
     * Subtract a vector from this vector.
     * @param vector the vector to be subtracted.
     * @return the difference
     */    
    Vector3D subtract(Vector3D vector){
        Vector3D s(this->x-vector.x,this->y-vector.y,this->z-vector.z);
        return s;
    }
    
    /**
     * Returns the unit vector for this vector.
     * @return the unit vector
     */
    Vector3D getUnitVector(){
        double m=this->getMagnitude();
        Vector3D vector(this->x/m,this->y/m,this->z/m);
        return vector;
    }
    
    /**
     * Finds the dot product of this vector with the other
     * @param vector the vector to be multiplied with
     * @return the dot product
     */
    double dotMultiply(Vector3D vector){
        return this->x*vector.x+this->y*vector.y+this->z*vector.z;
    }
    
    /**
     * Finds the cross product of this vector with the other
     * @param vector the vector to be multiplied with
     * @return the cross product
     */
    Vector3D multiply(Vector3D vector){
        Vector3D p(this->y*vector.z+this->z+vector.y,this->y*vector.z+this->z+vector.y,this->y*vector.z+this->z+vector.y);
        return p;
    }
    
    /**
     * Finds the angle between this vector and another vector
     * @param vector the other vector
     * @return the angle in radians
     */
    double getAngleBetween(Vector3D vector){
        return acos(this->dotMultiply(vector)/(this->getMagnitude()*vector.getMagnitude()));
    }
    
    /**
     * Gets the vector of the plane on which this vector and another vector lies
     * @param vector the other vector
     * @return the plane on which two vectors lie.
     */
    Vector3D getCommonPlane(Vector3D vector){
        return this->multiply(vector);
    }
    
    /**
     * The overloaded Subtraction Operator
     * @param v
     * @return the difference
     */
    Vector3D operator - (Vector3D v){
        return this->subtract(v);
    }
    
    /**
     * The overloaded Addition Operator
     * @param v
     * @return the sum
     */
    Vector3D operator + (Vector3D v){
        return this->add(v);
    }
    
    /**
     * The overloaded Multiplication Operator
     * @param v
     * @return the cross product
     */
    Vector3D operator * (Vector3D v){
        return this->multiply(v);
    }
    
    /**
     * The overloaded << operator for use with output streams.
     */
    friend ostream& operator <<(ostream& output, Vector3D& value){
        output<<"<"<<value.x<<","<<value.y<<","<<value.z<<">";
    }
    
};


