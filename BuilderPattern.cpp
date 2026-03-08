
// Builder Design Pattern
// Separates the construction of a complex object from its representation, allowing step-by-step creation.
// Example: Building different types of houses (wooden, brick) using the same construction process but different builders 
// without defining multiple constructors with many parameters.
//
// Advantages:
// - Flexible: build different representations using the same process
// - Stepwise construction, easy to customize
// - Avoids telescoping constructor anti-pattern (constructors with many parameters)
//
// Disadvantages:
// - More classes/code required
// - Can be overkill for simple objects
//
// Note: A Director class can be used to orchestrate the build steps, but here builders are used directly.

#include <iostream>
#include <memory>
class House{
    // Product class: House is built step-by-step by Builder
    private:
        int m_windows;
        int m_brickType;
        int m_woodType;      
    public:
        void setWindows(int windows){
            m_windows=windows;
        }
        void setBrickType(int brickType){
            m_brickType=brickType;
        }
        void setWoodType(int woodType){
            m_woodType=woodType;
        }
        void display(){
            std::cout<<"House with "<<m_windows<<" windows, brick type: "<<m_brickType<<" wood type: "<<m_woodType<<std::endl;
        }
};

class Builder{
    // Abstract Builder: defines steps for building a House
    public:
        virtual void setWindows()=0;
        virtual void setBrickType(){}; //not applicable for wood house
        virtual void setWoodType(){}; //not applicable for brick house
        virtual void buildHouse()=0;
    protected:
        House* house;
};

class WoodHouseBuilder: public Builder{
    // Concrete Builder: builds a Wood House
    private:
        void setWindows(){
            house->setWindows(0);//set windows for wood house
        }
        void setWoodType(){
            house->setWoodType(0);//set wood type for wood house
        }
    public:
        void buildHouse(){
            house = new House();
            setWindows();
            setWoodType();
            house->display();
        }
};

class BrickHouseBuilder: public Builder{
    // Concrete Builder: builds a Brick House
    private:
        void setWindows(){
            house->setWindows(1);//set windows for brick house
        }
        void setBrickType(){
            house->setBrickType(1);//set brick type for brick house
        }
    public:
        void buildHouse(){
            house = new House();
            setWindows();
            setBrickType();
            house->display();
        }
};

int main(){
    // Client uses builders directly (no Director class)
    std::unique_ptr<Builder> woodBuilder = std::make_unique<WoodHouseBuilder>();
    woodBuilder->buildHouse();
    std::unique_ptr<Builder> brickBuilder = std::make_unique<BrickHouseBuilder>();
    brickBuilder->buildHouse();
    return 0;
}