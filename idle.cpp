#include "manufacture.h"

#include <iostream>
#include <string>

int main(){
    std::cout << "Welcome to the Car Factory Idle Game!" << std::endl;
    std::cout << "Start building now" << std::endl;
    
    // Factory creation
    Factory factory;

    // Initial budget
    std::cout << "Initial budget of the factory: " << factory.wallet.get_budget() << " €" << std::endl;

    // Initial cars
    std::cout << "Number of cars you made: " << factory.car_inventory << std::endl;

    // Define sell_price and sell_rate
    Market market;
    market.set_sell_price(20000.0); // car price
    market.set_sell_rate(0.1);
    //affichage
    std::cout << "Car sell price: " << market.get_sell_price() << " €" << std::endl;
    std::cout << "Sell rate: " << market.get_sell_rate() * 100 << " %" << std::endl;


    //EXEMPLE DEVOLUTION, MERCI MISTRAL

    // Exemple d'achat de composants
    factory.buy("wheel");    // Achat d'une roue à 100 €
    factory.buy("electronics"); // Achat d'électronique à 500 €

    // Affichage du budget après achat de composants
    std::cout << "Budget après achat de composants: " << factory.wallet.get_budget() << " €" << std::endl;

    // Affichage de l'inventaire des composants après achat
    std::cout << "Inventaire des composants après achat:" << std::endl;
    for (const auto& component : factory.component_inventory) {
        std::cout << component.first << ": " << component.second << std::endl;
    }

    return 0;
}
