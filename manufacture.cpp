#include <iostream>
#include <string>
#include <map>
#include <list>

class Factory
{
public : 
    // attributs 
    auto components = std::list<std::string>{
        "wheel",
        "electronics",
        "glass",
        "frame",
        "engine"
    };
    auto component_inventory;
    int car_inventory;

    // Constructor 

    Factory();

    std::string reset_factory(){
    /*
    Setting inventory to 0 for initialing a new game 
    */ 
        for (auto component : components){
            component_inventory[component] = 0
        }
        car_inventory = 0
        std::cout << "resetting factory" << std::endl;
    }

    // Method to buy components

    void buy(std::string component){
        component_inventory[component] += 1
        // deduce from budget 
    }
    
    void build_car(){
    /*
    Building a car    
    */ 
        // checking for available components 
        if (component_inventory["wheel"] < 4 || 
            component_inventory["electronics"] < 1 || 
            component_inventory["glass"] < 6 || 
            component_inventory["frame"] < 1 || 
            component_inventory["engine"] < 1){
                std::cout << "insufficient inventory" << std::endl;
            }

        else {
            component_inventory["wheel"] -= 4;
            component_inventory["electronics"] -= 1;
            component_inventory["glass"] -= 6;
            component_inventory["frame"] -= 1;
            component_inventory["engine"] -= 1;
            car_inventory += 1;
        }
    }

}

int main() {
    return 0;
    };


