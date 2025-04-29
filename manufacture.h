#pragma once

#include "business.h"

#include <iostream>
#include <string>
#include <map>
#include <list>

class Factory
{
    // attributs

public :
    std::unordered_map<std::string, int> component_inventory = {
        {"wheel", 0},
        {"electronics", 0},
        {"glass", 0},
        {"frame", 0},
        {"engine", 0}
    };
    int car_inventory;
    Wallet wallet;
    // Constructor
    Factory();
    bool insufficient_Inventory();
    void build_car();

    // Method to buy components
    void buy(const std::string& component, double price);


};
