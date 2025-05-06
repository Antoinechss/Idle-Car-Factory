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
        popularity();
    }

    void reset_market(){
        sell_rate = 0;
        sell_price = 0;
        popularity = 0;

        std::cout << "Resetting market values" << std::endl;
    }
    
    void reset_wallet(){
        budget = 0;

        std::cout << "Creating a new empty wallet" << std::endl;
    }

    void set_sell_price(double price) {
        sell_price = price;
    }

    void set_sell_rate() {
        /*
        Define sell rate as a function of price 
        */
        sell_rate = popularity / sell_price;
    }
}