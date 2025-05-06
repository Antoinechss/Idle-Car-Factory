#include "manufacture.h"

#include <iostream>
#include <string>

int main(){
    std::cout << "Welcome to the Car Factory Idle Game!" << std::endl;
    std::cout << "Start building now" << std::endl;

    // CREATING A NEW GAME WITH REINITIALIZED PARAMETERS

    Factory factory;
    Wallet wallet; 

    factory.reset_factory();
    wallet.reset_market();
    wallet.reset_wallet();

    // Define sell_price and sell_rate
    wallet.set_sell_price(20000.0); // car price
    wallet.set_sell_rate(0.1);

    return 0;
}
