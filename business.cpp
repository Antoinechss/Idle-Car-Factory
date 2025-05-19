#include "business.h"

Wallet::Wallet()
{
    reset_wallet();
    reset_market();
    cars_sold_buffer;
}

void Wallet::reset_market()
{
    sell_rate = 0;
    sell_price = 0;
    popularity = 0;
    cars_sold_buffer = 0;
    earning_buffer = 0;
    earning_rate = 0;
    update_popularity();
    std::cout << "Resetting market values" << std::endl;
}

void Wallet::reset_wallet()
{
    budget = 0;

    std::cout << "Creating a new empty wallet" << std::endl;
}

void Wallet::set_sell_price(double price)
{
    sell_price = price;
}

void Wallet::update_popularity()
{
    popularity = rand() % 101;
}

void Wallet::update_sell_rate()
{
    sell_rate = popularity / sell_price;
}
