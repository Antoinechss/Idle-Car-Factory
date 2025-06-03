#pragma once

#include "business.h"

#include <iostream>
#include <list>
#include <map>
#include <string>

class Factory {
public:
    Wallet wallet;

    std::map<std::string, std::pair<double, int>> inventory; // component -> {unit price, quantity}
    int car_inventory;         // Number of finished cars in stock
    int total_volume_built;    // Total number of cars produced
    int car_built_per_sec;     // Not used yet, placeholder
    float car_build_price;     // Current build cost of one car

    // Constructor
    Factory();

    // Reset factory stock and wallet
    void reset_factory();

    // Actions
    void buy(const std::string& component);
    void build_car();
    void sell_car();
    void buy_and_build_car();

    // Status checks
    bool can_build_car();
    bool can_buy_car();

    // Update calculated price
    void update_build_price();
};
