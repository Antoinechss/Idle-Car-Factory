#include "manufacture.h"
#include <Imagine/Graphics.h>
using namespace Imagine;

#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

int main()
{
    srand(100);
    auto lastTime = std::chrono::high_resolution_clock::now();
    std::cout << "Welcome to the Car Factory Idle Game!" << std::endl;
    std::cout << "Start building now" << std::endl;

    Factory factory;
    openWindow(800, 800, "Imagine++ Window");

    while (true) {
        clearWindow(); // Clear previous frame

        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = currentTime - lastTime;
        float delta_time = elapsed.count(); // secondes
        lastTime = currentTime;

        // Display budget
        std::ostringstream oss_budget;
        oss_budget << "Budget: $" << factory.wallet.budget;
        drawString(20, 20, oss_budget.str(), BLACK, 20);

        // Display car inventory
        std::ostringstream oss_car_inventory;
        oss_car_inventory << "Car Inventory: " << factory.car_inventory << " Cars";
        drawString(20, 60, oss_car_inventory.str(), BLACK, 20);

        // Display sell price of cars
        std::ostringstream oss_sell_price;
        oss_sell_price << "Sell Price: $" << factory.wallet.sell_price;
        drawString(20, 400, oss_sell_price.str(), BLACK, 20);

        // Display materials inventory
        int y_offset = 100;
        for (const auto &item : factory.inventory) {
            std::ostringstream oss_inventory;
            oss_inventory << item.first
                          << ": " << item.second.first
                          << " USD, Quantity: " << item.second.second;
            drawString(20, y_offset, oss_inventory.str(), BLACK, 20);
            y_offset += 40;
        }

        // Update and display live popularity

        factory.wallet.update_popularity();
        std::ostringstream oss_popularity;
        oss_popularity << "Popularity :" << factory.wallet.popularity;
        drawString(20, 600, oss_popularity.str(), BLACK, 20);

        // Update and display sell rate

        factory.wallet.update_sell_rate();
        std::ostringstream oss_sell_rate;
        oss_sell_rate << "Sell Rate :" << factory.wallet.sell_rate;
        drawString(20, 700, oss_sell_rate.str(), BLACK, 20);

        // Draw price modification buttons

        int price_up_buttonX = 300;
        int price_up_buttonY = 380;
        int price_up_buttonW = 100;
        int price_up_buttonH = 30;
        fillRect(price_up_buttonX, price_up_buttonY, price_up_buttonW, price_up_buttonH, BLACK);
        drawString(price_up_buttonX + price_up_buttonW/2 - 20, price_up_buttonY + price_up_buttonH/2 + 5, "raise", WHITE, 20);

        int price_down_buttonX = 200;
        int price_down_buttonY = 380;
        int price_down_buttonW = 100;
        int price_down_buttonH = 30;
        fillRect(price_down_buttonX, price_down_buttonY, price_down_buttonW, price_down_buttonH, BLACK);
        drawString(price_down_buttonX + price_down_buttonW/2 - 25, price_down_buttonY + price_down_buttonH/2 + 5, "lower", WHITE, 20);


        // Draw buy material buttons
        int buttonX = 300;
        int buttonY_start = 75;
        int buttonW = 150;
        int buttonH = 30;
        int gap = 40;

        const std::string labels[5] = {
            "Buy electronics", "Buy engine", "Buy frame", "Buy glass", "Buy wheel"
        };

        const std::string components[5] = {
            "electronics", "engine", "frame", "glass", "wheel"
        };

        for (int i = 0; i < 5; i++) {
            int by = buttonY_start + i * gap;
            if (factory.wallet.budget >= factory.inventory[components[i]].first) {
                fillRect(buttonX, by, buttonW, buttonH, GREEN); // Enough money
            } else {
                fillRect(buttonX, by, buttonW, buttonH, RED); // Not enough money
            }
        }

        // Draw buy material labels
        drawString(310, 100, "Buy electronics", WHITE, 20);
        drawString(330, 140, "Buy engine", WHITE, 20);
        drawString(330, 180, "Buy frame", WHITE, 20);
        drawString(330, 220, "Buy glass", WHITE, 20);
        drawString(330, 260, "Buy wheel", WHITE, 20);

        // Draw Build Car button
        int buildButtonX = 470;
        int buildButtonY = 145;
        int buildButtonW = 200;
        int buildButtonH = 50;
        fillRect(buildButtonX, buildButtonY, buildButtonW, buildButtonH, BLUE);
        drawString(buildButtonX + 50, buildButtonY + 30, "Build Car", WHITE, 20);


        // Draw Build Car button
        int buildmaxButtonX = 470;
        int buildmaxButtonY = 100;
        int buildmaxButtonW = 200;
        int buildmaxButtonH = 50;
        fillRect(buildmaxButtonX, buildmaxButtonY, buildmaxButtonW, buildmaxButtonH, BLUE);
        drawString(buildmaxButtonX + 50, buildmaxButtonY + 30, "Build Max Cars", WHITE, 20);

        // Draw Buy and Build car button
        int buyandbuildButtonX = 470;
        int buyandbuildButtonY = 50;
        int buyandbuildButtonW = 200;
        int buyandbuildButtonH = 50;
        fillRect(buyandbuildButtonX, buyandbuildButtonY, buyandbuildButtonW, buyandbuildButtonH, BLUE);
        drawString(buyandbuildButtonX + 50, buyandbuildButtonY + 30, "Buy & Build Car", WHITE, 20);


        // -------------- PLAYER INTERACTION --------------

        int x, y;
        if (getMouse(x, y)) {
            // Material purchase
            for (int i = 0; i < 5; i++) {
                int bx = buttonX;
                int by = buttonY_start + i * gap;
                if (x >= bx && x <= bx + buttonW && y >= by && y <= by + buttonH) {
                    factory.buy(components[i]);
                }
            }

            // Build Car
            if (x >= buildButtonX && x <= buildButtonX + buildButtonW && y >= buildButtonY && y <= buildButtonY + buildButtonH) {
                factory.build_car();
            }

            // Build max Cars possible
            if (x >= buildmaxButtonX && x <= buildmaxButtonX + buildmaxButtonW &&
                y >= buildmaxButtonY && y <= buildmaxButtonY + buildmaxButtonH) {

                while (factory.can_build_car()) {
                    factory.build_car();
                }
            }

            // Buy and build
            if (x >= buyandbuildButtonX && x <= buyandbuildButtonX + buyandbuildButtonW &&
                y >= buyandbuildButtonY && y <= buyandbuildButtonY + buyandbuildButtonH) {
                factory.buy_and_build_car();
                }
            }

            // Modify sell price
            if (x >= price_down_buttonX && x <= price_down_buttonX + price_down_buttonW &&
                y >= price_down_buttonY && y <= price_down_buttonY + price_down_buttonH && factory.wallet.sell_price > 0) {
                factory.wallet.set_sell_price(factory.wallet.sell_price - 1000);
                factory.wallet.update_sell_rate();
            }
            else if (x >= price_up_buttonX && x <= price_up_buttonX + price_up_buttonW &&
                     y >= price_up_buttonY && y <= price_up_buttonY + price_up_buttonH) {
                factory.wallet.set_sell_price(factory.wallet.sell_price + 1000);
                factory.wallet.update_sell_rate();
            }

            // Selling cars according to demand

            float cars_to_sell = factory.wallet.sell_rate*delta_time;
            factory.wallet.cars_sold_buffer += cars_to_sell;

            while (factory.wallet.cars_sold_buffer >= 1.0f && factory.car_inventory > 0) {
                factory.sell_car();  // fonction qui vend 1 voiture et ajoute l'argent
                factory.wallet.cars_sold_buffer -= 1.0f;
            }

        milliSleep(50);
    }

    return 0;
}
