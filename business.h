#pragma once

#include <iostream>
#include <string>
class Wallet{
    // attributes
    double budget;
public :
    //constructeur d'un Wallet avec un budget initialisé à 0
    Wallet();
    void update_budget(double cashflow);
    double get_budget() const;
};

class Market{
    // attributes
    double sell_price;
    double sell_rate;

public :
    Market();
    void set_sell_price(double price);
    void set_sell_rate(double rate);
    double get_sell_price() const;
    double get_sell_rate() const;
};
