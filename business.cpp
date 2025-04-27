#include <iostream>
#include <string>

class Wallet
{
    public :
    // attributes 
        float budget;
        
        std::string reset_wallet(){
            /*
            Setting gains to 0 for initialing a new game 
            */ 
                budget = 0
                std::cout << "resetting wallet" << std::endl;
            }

}

class Market 
{
    public :
    // attributes 
        float sell_price;
        float demand_rate; 

        std::string reset_wallet(){
            /*
            Reseting market for initialing a new game 
            */ 
                sell_price = 0
                std::cout << "Resetting Market" << std::endl;
            }

}