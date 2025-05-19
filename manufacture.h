#pragma once

#include "business.h"

#include <iostream>
#include <list>
#include <map>
#include <string>

class Factory
{
public:
    Wallet wallet;

    std::map<std::string, std::pair<double, int>> inventory;
    // Initializing components price and stock

    int car_inventory; // number of cars available for sale
    int total_volume_built;
    int car_built_per_sec;
    float car_build_price;
    // Constructor
    Factory();

    void reset_factory();
    void buy(const std::string &component);
    void build_car();
    void sell_car();
    bool can_build_car();
    void buy_and_build_car();
    void update_build_price();
    bool can_buy_car();
};
