//Abstract Factory Design pattern is an abstraction to factory design pattern
//which helps in creating family of related objects (factory of factories) at runtime
//
// Advantages:
// - Ensures related objects are created together (consistency across product families)
// - Easy to swap between different families of products without client code changes
// - Isolates client code from concrete classes
//
// Disadvantages:
// - More complex with multiple abstract interfaces and concrete factories
// - Adding new product types requires changes to all factory implementations
// - Overkill for simple applications with few product families

#include<iostream>

class Food{
public:
    virtual void status()=0;
};

// Abstract Product families
class Pizza: public Food{
public:
    virtual void status()=0;
};

class Burger: public Food{
public:
    virtual void status()=0;
};

class VegPizza: public Pizza{
public:
    VegPizza(){
        std::cout<<"Veg Pizza getting ready"<<std::endl;
    }
    void status(){
        std::cout<<"Veg Pizza ready..."<<std::endl;
    }
};
// Concrete Products for Veg family// Concrete Products for NonVeg family
class NonVegPizza: public Pizza{
public:
    NonVegPizza(){
        std::cout<<"Non Veg Pizza getting ready"<<std::endl;
    }
    void status(){
        std::cout<<"Non Veg Pizza ready..."<<std::endl;
    }
};

// Concrete Products for Veg family (continued)
class VegBurger: public Burger{
public:
    VegBurger(){
        std::cout<<"Veg Burger getting ready"<<std::endl;
    }
    void status(){
        std::cout<<"Veg Burger ready..."<<std::endl;
    }
};

// Concrete Products for NonVeg family (continued)
class NonVegBurger: public Burger{
public:
    NonVegBurger(){
        std::cout<<"Non Veg Burger getting ready"<<std::endl;
    }
    void status(){
        std::cout<<"Non Veg Burger ready..."<<std::endl;
    }
};

// Abstract Factory - declares methods for creating product families
class FoodFactory{
public:
    virtual Pizza* createPizza()=0;
    virtual Burger* createBurger()=0;
};
 
// Concrete Factory 1 - creates NonVeg family of products
class NonVegFactory: public FoodFactory{
public:
    Pizza* createPizza(){
        return new NonVegPizza();
    }
    Burger* createBurger(){
        return new NonVegBurger();
    }
};

// Concrete Factory 2 - creates Veg family of products
class VegFactory: public FoodFactory{
public:
    Pizza* createPizza(){
        return new VegPizza();
    }
    Burger* createBurger(){
        return new VegBurger();
    }
};

// Factory selector - returns appropriate concrete factory based on type
FoodFactory* createObj(int n){
    if(n==1){
        return new NonVegFactory();
    }
    else if(n==2){
        return new VegFactory();
    }
    else{
        return nullptr;
    }
}

int main(){
    // Client works with abstract factory and products, not concrete classes
    std::cout<<"You are going to create objects in run time:"<<std::endl;
    std::cout<<"Enter 1 for NonVeg, 2 for Veg"<<std::endl;
    int n;
    std::cin>>n;
    FoodFactory* obj = createObj(n);
    std::cout<<"Calling createPizza"<<std::endl;
    if(obj){
        Pizza* pizza = obj->createPizza();
        pizza->status();
        std::cout<<"Calling createBurger"<<std::endl;
        Burger* burger = obj->createBurger();
        burger->status();
        delete pizza;
        delete burger;
        delete obj;
    }
    else{
        std::cout<<"Invalid input"<<std::endl;
    }
    
    return 0;
}