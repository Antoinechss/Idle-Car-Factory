#include "business.h"

class Wallet 
{
    public : 
    double budget;
    double sell_rate;
    double sell_price;

    Wallet() {
        reset_market();
        reset_wallet();
        set_sell_price();
        set_sell_rate(); 
    }

    void reset_market(){
        sell_rate = 0;
        sell_price = 0;

        std::cout << "Resetting market values" << std::endl;
    }
    
    void reset_wallet(){
        budget = 0;

        std::cout << "Creating a new empty wallet" << std::endl;
    }

    void Market::set_sell_price(double price) {
        sell_price = price;
    }

    void Market::set_sell_rate() {
        // TODO : set sell rate as a function of sell price of car ;
    }
}