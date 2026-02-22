//Factory Method Design pattern is a creational design pattern gives you interface
//for creating objects at runtime, Without exposing the creation logic to the client
//
// Advantages:
// - Loose coupling: Client code doesn't depend on concrete classes, only the interface
// - Easy to extend: Add new object types without modifying existing code (Open/Closed Principle)
// - Centralized object creation logic for easier maintenance and testing
//
// Disadvantages:
// - Adds extra classes and interfaces, increasing code complexity
// - Slight performance overhead from factory method calls
// - Overkill for simple projects with only one object type

#include<iostream>

// Abstract base class (Product) - defines the interface for objects to be created
class Food{
public:
    virtual void status()=0;
};

class Pizza: public Food{
public:
    Pizza(){
        std::cout<<"Pizza getting ready"<<std::endl;
    }
    void status(){
        std::cout<<"Pizza ready..."<<std::endl;
    }
};

class Burger: public Food{
public:
    Burger(){
        std::cout<<"Burger getting ready"<<std::endl;
    }
    void status(){
        std::cout<<"Burger ready..."<<std::endl;
    }
};

// Factory Method - creates and returns objects based on parameter, hiding instantiation logic from client
Food* createObj(int n){
    if(n==1){
        return new Pizza();
    }
    else if(n==2){
        return new Burger();
    }
    else{
        return nullptr;
    }
}

int main(){
    // Client uses the factory method to create objects without needing to know the concrete classes
    std::cout<<"You are going to create objects in run time:"<<std::endl;
    std::cout<<"Enter 1 for creating Pizza class 2 for creating Burger class"<<std::endl;
    int n;
    std::cin>>n;
    Food* obj = createObj(n);
    if(obj){
        std::cout<<"Invoking status function of the object"<<std::endl;
        obj->status();
        delete obj;
    }
    else{
        std::cout<<"Invalid input, no object created"<<std::endl;
    }
    return 0;
}