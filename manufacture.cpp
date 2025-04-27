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

    // Method buy 

    void buy(std::string component){
        component_inventory[component] += 1
        // deduce from budget 
    }
    
    // Method build car 
    void build_car(){
        // checking for enough inventory 
        
        // building car 
        // removing inventory 
    }

}

int main() {
    return 0;
    };


