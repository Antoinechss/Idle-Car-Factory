#include "manufacture.h"
#include <Imagine/Graphics.h>
using namespace Imagine;

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::cout << "Welcome to the Car Factory Idle Game!" << std::endl;
    std::cout << "Start building now" << std::endl;

    Factory factory;
    openWindow(800, 800, "Imagine++ Window");

    while (true) {
        clearWindow(); // Clear previous frame

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

        int x, y;
        if (getMouse(x, y)) {
            // Handle material purchase buttons
            for (int i = 0; i < 5; i++) {
                int bx = buttonX;
                int by = buttonY_start + i * gap;
                if (x >= bx && x <= bx + buttonW && y >= by && y <= by + buttonH) {
                    factory.buy(components[i]);
                }
            }

            // Handle Build Car button
            if (x >= buildButtonX && x <= buildButtonX + buildButtonW &&
                y >= buildButtonY && y <= buildButtonY + buildButtonH) {
                factory.build_car();
            }
        }

        milliSleep(50);
    }

    return 0;
}
