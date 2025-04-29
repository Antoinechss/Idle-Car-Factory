#include "manufacture.h"


Factory::Factory(){
    /*
    Setting inventory to 0 for initialing a new game
    */
    for (auto& component : component_inventory) {
        component.second = 0;
    }
    car_inventory = 0;
    std::cout << "creating a reset factory" << std::endl;
}
bool Factory:: insufficient_Inventory(){
    return component_inventory.at("wheel") < 4 ||
           component_inventory.at("electronics") < 1 ||
           component_inventory.at("glass") < 6 ||
           component_inventory.at("frame") < 1 ||
           component_inventory.at("engine") < 1;
}

void Factory::build_car(){
/*
Building a car
*/
    // checking for available components
    if (insufficient_Inventory()){
        std::cout << "insufficient inventory, get some more components !" << std::endl;
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

void Factory::buy(const std::string &component, double price){
    component_inventory[component] += 1;
    // deduce from budget
    wallet.update_budget(-price);
}

