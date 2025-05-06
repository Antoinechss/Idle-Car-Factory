#include "business.h"

class Wallet 
{
    public : 
    double budget 
    double sell_

    Wallet() {
        reset_market();
        reset_wallet();
        set_sell_price();
        set_sell_rate(); 
    }

    void reset_market(){

    }
}


Wallet::Wallet(){
    /*
    Setting gains to 0 for initializing a new game
    */
    budget = 0;
    std::cout << "creating a wallet" << std::endl;
}

void Wallet::update_budget(double cashflow){
    budget = budget + cashflow;
}

double Wallet::get_budget() const {
    return budget;
}

Market::Market(){
    /*
    Reseting market for initialing a new game
    */
    sell_price = 0;//to change
    sell_rate = 0;//to change
    std::cout << "Creating a new Market" << std::endl;
}


void Market::set_sell_price(double price) {
    sell_price = price;
}

void Market::set_sell_rate(double rate) {
    sell_rate = rate;
}

double Market::get_sell_price() const {
    return sell_price;
}

double Market::get_sell_rate() const {
    return sell_rate;
}
