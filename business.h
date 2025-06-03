#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class Wallet {
public:
    // --- Data ---
    double budget;
    double sell_rate;
    double sell_price;
    double popularity;
    double cars_sold_buffer;
    double cars_sold_per_sec;
    double earning_buffer;
    double earning_rate;

    // --- Constructor ---
    Wallet();

    // --- Market & Wallet Controls ---
    void reset_market();
    void reset_wallet();
    void set_sell_price(double price);

    // --- Updates ---
    void update_sell_rate();
    void update_popularity();

    // --- UI / Graph ---
    void drawBudgetGraph(
        const std::vector<int>& history,
        int graphX, int graphY,
        int graphW, int graphH,
        int max_funds
        );
};
