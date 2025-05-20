#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

class Wallet
{
public:
    double budget;
    double sell_rate;
    double sell_price;
    double popularity;
    double cars_sold_buffer;

    double cars_sold_per_sec;
    double earning_buffer;
    double earning_rate;
    Wallet();

    void reset_market();
    void reset_wallet();
    void set_sell_price(double price);
    void update_sell_rate();
    void update_popularity();
    void drawBudgetGraph(
        const std::vector<int> &history, int graphX, int graphY, int graphW, int graphH, int max_funds);
};
