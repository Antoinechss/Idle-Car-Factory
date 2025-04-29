#include "business.h"

void Wallet::reset_wallet(){
    /*
    Setting gains to 0 for initializing a new game
    */
    budget = 0;
    std::cout << "resetting wallet" << std::endl;
}

void Wallet::update_budget(double cashflow){
    budget = budget + cashflow;
}

void Market::reset_market(){
    /*
    Reseting market for initialing a new game
    */
    sell_price = 0;
    std::cout << "Resetting Market" << std::endl;
}
