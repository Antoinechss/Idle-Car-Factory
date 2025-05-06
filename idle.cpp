#include "manufacture.h"
#include <Imagine/Graphics.h>
using namespace Imagine;

#include <iostream>
#include <string>
#include <sstream>  // pour std::ostringstream

int main(){
    std::cout << "Welcome to the Car Factory Idle Game!" << std::endl;
    std::cout << "Start building now" << std::endl;

    // CREATING A NEW GAME WITH REINITIALIZED PARAMETERS

    Factory factory;
    openWindow(800, 800, "Imagine++ Window");
    while (true) {
        std::ostringstream oss;
        oss << "Budget: $" << factory.wallet.budget;
        drawString(20, 20, oss.str(), BLACK, 20);
    }





    click(); // attend un clic de souris

    return 0;
}
