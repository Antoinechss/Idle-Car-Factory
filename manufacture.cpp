#include "manufacture.h"
#include <iostream>

Factory::Factory()
{
    inventory["wheel"] = {1000.0, 0};
    inventory["engine"] = {2000.0, 0};
    inventory["glass"] = {500.0, 0};
    inventory["electronics"] = {10.0, 0};
    inventory["frame"] = {500.0, 0};

    car_inventory = 0;
    total_volume_built = 0;

    car_build_price = 4 * inventory["wheel"].first
                      + inventory["electronics"].first
                      + 6 * inventory["glass"].first
                      + inventory["frame"].first
                      + inventory["engine"].first;

    wallet.budget = 100000;
}

void Factory::reset_factory()
{
    inventory["wheel"] = {1000.0, 0};
    inventory["engine"] = {2000.0, 0};
    inventory["glass"] = {500.0, 0};
    inventory["electronics"] = {10.0, 0};
    inventory["frame"] = {500.0, 0};

    car_inventory = 0;
    total_volume_built = 0;

    car_build_price = 4 * inventory["wheel"].first
                      + inventory["electronics"].first
                      + 6 * inventory["glass"].first
                      + inventory["frame"].first
                      + inventory["engine"].first;

    wallet.reset_market();
    wallet.budget = 100000;

    std::cout << "Resetting factory" << std::endl;
}

void Factory::buy(const std::string& component)
{
    // Achat d'un composant si le budget le permet
    if (wallet.budget < inventory[component].first) {
        std::cout << "Insufficient funds" << std::endl;
    } else {
        inventory[component].second += 1;
        wallet.budget -= inventory[component].first;
    }
}

bool Factory::can_build_car()
{
    // Vérifie les composants nécessaires
    return !(inventory["wheel"].second < 4
             || inventory["electronics"].second < 1
             || inventory["glass"].second < 6
             || inventory["frame"].second < 1
             || inventory["engine"].second < 1);
}

bool Factory::can_buy_car()
{
    // Vérifie si assez de budget pour acheter tous les composants
    update_build_price();
    return wallet.budget >= car_build_price;
}

void Factory::build_car()
{
    if (can_build_car()) {
        inventory["wheel"].second       -= 4;
        inventory["electronics"].second -= 1;
        inventory["glass"].second       -= 6;
        inventory["frame"].second       -= 1;
        inventory["engine"].second      -= 1;

        car_inventory       += 1;
        total_volume_built  += 1;

        std::cout << "Car built!" << std::endl;
    } else {
        std::cout << "Insufficient inventory" << std::endl;
    }
}

void Factory::buy_and_build_car()
{
    if (can_buy_car()) {
        car_inventory       += 1;
        total_volume_built  += 1;
        wallet.budget       -= car_build_price;

        std::cout << "Car built!" << std::endl;
    } else {
        std::cout << "Insufficient budget" << std::endl;
    }
}

void Factory::update_build_price()
{
    car_build_price = 4 * inventory["wheel"].first
                      + inventory["electronics"].first
                      + 6 * inventory["glass"].first
                      + inventory["frame"].first
                      + inventory["engine"].first;
}

void Factory::sell_car()
{
    if (car_inventory > 0) {
        car_inventory -= 1;
        wallet.budget += wallet.sell_price;
    }
}
