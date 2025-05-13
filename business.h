#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>



class Wallet
{
public:
    double budget;
    double sell_rate;
    double sell_price;
    double popularity;
    double cars_sold_buffer;

    Wallet();

    void reset_market();
    void reset_wallet();
    void set_sell_price(double price);
    void update_sell_rate();
    void update_popularity();
};
