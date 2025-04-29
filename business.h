#pragma once

#include <iostream>
#include <string>
class Wallet{
    // attributes
    double budget;
public :
    void reset_wallet();
    void update_budget(double cashflow);
};

class Market{
    // attributes
    double sell_price;
    double sell_rate;
public :
    void reset_market();
};
