#include "manufacture.h"
#include "utils.h"
#include <Imagine/Graphics.h>
using namespace Imagine;

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
int main()
{
    endGraphics();
    srand(100);
    auto lastTime = std::chrono::high_resolution_clock::now();
    std::cout << "Welcome to the Car Factory Idle Game!" << std::endl;
    std::cout << "Start building now" << std::endl;

    std::vector<int> budgetHistory; // To store the evolving budget

    Factory factory;
    openWindow(1400, 800, "Imagine++ Window");

    auto gameStartTime = std::chrono::high_resolution_clock::now();

    int rounds_count = 0;
    int gap_round = 1000000;
    double max_funds = factory.wallet.budget;

    while (true) {
        clearWindow(); // Clear previous frame

        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = currentTime - gameStartTime;
        float delta_time = elapsed.count(); // Elapsed time in seconds
        lastTime = currentTime;

        factory.wallet.update_sell_rate();


        const std::string components[5] = {"electronics", "engine", "frame", "glass", "wheel"};

        // #############################################################################################
        // ######################################### ESTHETICS #########################################
        // #############################################################################################

        // -------------- Background ----------------

        fillRect(0, 0, 1400, 800, Color(232, 237, 223)); // Background

        // -------------- Header ----------------

        fillRect(0, 0, 1400, 50, Color(51, 53, 51)); // Header
        drawString(50, 35, "IDLE CAR FACTORY", Color(245, 203, 92), 30);
        int minutes = static_cast<int>(delta_time) / 60;
        int seconds = static_cast<int>(delta_time) % 60;

        std::ostringstream oss_elapsed;
        oss_elapsed << "Game duration :     " << std::setw(2) << std::setfill('0') << minutes << ":"
                    << std::setw(2) << std::setfill('0') << seconds;

        drawString(500, 35, oss_elapsed.str(), WHITE, 30);

        int resetButtonW = 100;
        int resetButtonH = 40;
        int resetButtonX = 1400 - resetButtonW - 50;
        int resetButtonY = 5;

        fillRect(resetButtonX, resetButtonY, resetButtonW, resetButtonH, Color(245, 203, 92));
        drawString(resetButtonX + 22, resetButtonY + 27, "RESET", WHITE, 20);

        // -------------- Manufacture ----------------

        fillRect(50, 100, 500, 460, Color(255, 255, 255));
        drawString(234, 85, "MANUFACTURE", BLACK, 20);

        //car inventory
        std::ostringstream oss_car_inventory;
        oss_car_inventory << "Unsold Inventory: " << factory.car_inventory << " Cars";
        drawString(85, 140, oss_car_inventory.str(), BLACK, 23);

        // Build Car
        int buildButtonX = 100;
        int buildButtonY = 160;
        int buildButtonW = 175;
        int buildButtonH = 40;
        if (factory.can_build_car()) {
            fillRect(buildButtonX, buildButtonY, buildButtonW, buildButtonH, GREEN);
        } else {
            fillRect(buildButtonX, buildButtonY, buildButtonW, buildButtonH, RED);
        }

        drawString(buildButtonX + 50, buildButtonY + 30, "Build Car", WHITE, 20);

        // Buy and Build Car
        int buyandbuildButtonX = 325;
        int buyandbuildButtonY = 160;
        int buyandbuildButtonW = 175;
        int buyandbuildButtonH = 40;

        if (factory.can_buy_car()) {
            fillRect(buyandbuildButtonX,
                     buyandbuildButtonY,
                     buyandbuildButtonW,
                     buyandbuildButtonH,
                     GREEN); // Enough money
        } else {
            fillRect(buyandbuildButtonX,
                     buyandbuildButtonY,
                     buyandbuildButtonW,
                     buyandbuildButtonH,
                     RED);
        }
        drawString(buyandbuildButtonX + 50, buyandbuildButtonY + 30, "Buy & Build", WHITE, 20);

        // Materials display
        int y_offset = 300;
        for (const auto &item : factory.inventory) {
            std::ostringstream oss_inventory;
            oss_inventory << item.first << ": " << item.second.first
                          << " USD, Quantity: " << item.second.second;
            drawString(70, y_offset, oss_inventory.str(), BLACK, 20);
            y_offset += 60;
        }
        std::ostringstream oss_buy_price;
        oss_buy_price << "Buy all price : " << factory.car_build_price;
        drawString(70, y_offset, oss_buy_price.str(), BLACK, 20);

        // Buy material buttons
        int buy1buttonX = 400;
        int buy1buttonY_start = 280;
        int buy1buttonW = 115;
        int buy1buttonH = 30;
        int gap = 60;

        int by;

        int j = 0;
        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN); // Enough money
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED); // Not enough money
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (a)", BLACK, 20);
        j+=1;

        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN); // Enough money
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED); // Not enough money
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (z)", BLACK, 20);
        j+=1;

        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN); // Enough money
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED); // Not enough money
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (e)", BLACK, 20);
        j+=1;

        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN); // Enough money
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED); // Not enough money
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (r)", BLACK, 20);
        j+=1;

        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN); // Enough money
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED); // Not enough money
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (t)", BLACK, 20);


        // -------------- Budget box and graph ----------------

        int graphX = 630;
        int graphY = 120;
        int graphW = 260;
        int graphH = 150;
        fillRect(600, 100, 300, 300, Color(255, 255, 255));
        drawString(720, 85, "FUNDS", BLACK, 20);
        drawString(610,200, "$", BLACK, 15);
        drawString(740,290, "time", BLACK, 15);



        // -------------- Boosters ----------------

        fillRect(600, 450, 300, 450, Color(255, 255, 255));
        drawString(702, 435, "BOOSTERS", BLACK, 20);

        //Build Max Cars button
        int buildmaxButtonX = 650;
        int buildmaxButtonY = 490;
        int buildmaxButtonW = 210;
        int buildmaxButtonH = 40;
        fillRect(buildmaxButtonX, buildmaxButtonY, buildmaxButtonW, buildmaxButtonH, BLUE);
        drawString(buildmaxButtonX + 20, buildmaxButtonY + 30, "Buy and build max (m)", WHITE, 20);

        // -------------- Market Overview ----------------

        fillRect(950, 100, 400, 400, Color(36, 36, 35));
        for (int i = 1; i <= 5; i++) {
            int y = 100 + i * (400 / 6);
            drawLine(970, y, 1330, y, WHITE);
        }
        drawString(1060, 85, "MARKET OVERVIEW", BLACK, 20);

        int marketstartY = 138;
        int marketX = 970;

        std::ostringstream oss_budget;
        oss_budget << "Funds ($):            " << factory.wallet.budget;
        drawString(marketX, marketstartY, oss_budget.str(), WHITE, 20);
        marketstartY += 66;

        std::ostringstream oss_popularity;
        oss_popularity << "Popularity:            " << factory.wallet.popularity;
        drawString(marketX, marketstartY, oss_popularity.str(), WHITE, 20);
        marketstartY += 66;

        std::ostringstream oss_sell_rate;
        oss_sell_rate << "Sell rate:            " << factory.wallet.sell_rate;
        drawString(marketX, marketstartY, oss_sell_rate.str(), WHITE, 20);
        marketstartY += 66;

        std::ostringstream oss_total_volume_built;
        oss_total_volume_built << "Total volume built :            " << factory.total_volume_built;
        drawString(marketX, marketstartY, oss_total_volume_built.str(), WHITE, 20);
        marketstartY += 66;

        //TO DO A WORKING ONE
        std::ostringstream oss_earning_rate;
        oss_earning_rate << "Earned/sec :            " << factory.wallet.earning_rate;
        drawString(marketX, marketstartY, oss_earning_rate.str(), WHITE, 20);
        marketstartY += 66;

        //TO DO A WORKING ONE
        std::ostringstream oss_cars_sold_per_sec;
        oss_cars_sold_per_sec << "Cars sold/sec :            " << factory.wallet.cars_sold_per_sec;
        drawString(marketX, marketstartY, oss_cars_sold_per_sec.str(), WHITE, 20);

        // Sell Rate Graph
        fillRect(950, 550, 400, 230, Color(255, 255, 255));

        // -------------- Setting sell price ----------------

        // Display sell price

        std::ostringstream oss_sell_price;
        oss_sell_price << "Sell Price ($): " << factory.wallet.sell_price;
        drawString(950, 530, oss_sell_price.str(), BLACK, 20);

        // +/- buttons

        int price_up_buttonW = 40;
        int price_up_buttonH = 30;
        int price_up_buttonY = 507;
        int price_up_buttonX = 1270;

        int price_down_buttonX = 1215;
        int price_down_buttonY = price_up_buttonY;
        int price_down_buttonW = price_up_buttonW;
        int price_down_buttonH = price_up_buttonH;

        fillRect(price_down_buttonX, price_down_buttonY, price_down_buttonW, price_down_buttonH, RED);
        drawString(price_down_buttonX + price_down_buttonW / 2 - 6,
                   price_down_buttonY + price_down_buttonH / 2 + 7,
                   "-",
                   WHITE,
                   22); // Larger font

        fillRect(price_up_buttonX, price_up_buttonY, price_up_buttonW, price_up_buttonH, GREEN);
        drawString(price_up_buttonX + price_up_buttonW / 2 - 6,
                   price_up_buttonY + price_up_buttonH / 2 + 7,
                   "+",
                   WHITE,
                   22); // Larger font

        // #############################################################################################
        // ######################################### FUNCTIONAL ########################################
        // #############################################################################################

        // Displaying budget evolution in graph

        rounds_count ++;
        bool UPDATE_GRAPH = rounds_count % gap_round == 0;

        budgetHistory.push_back(factory.wallet.budget);
        if (budgetHistory.size() > 50) // Optional: limit graph length
            budgetHistory.erase(budgetHistory.begin());

        factory.wallet.drawBudgetGraph(budgetHistory, graphX, graphY, graphW, graphH, max_funds);
        int key = keyboard();
        //Reset Button
        if (key == int('w')) {
            factory.wallet.reset_wallet();
            factory.wallet.reset_market();
            factory.reset_factory();
        }

        // Material purchase
        int i = 0;
        if (key == int('a')) {
            factory.buy(components[i]);
        }
        i+=1;
        if (key == int('z')) {
        factory.buy(components[i]);
        }
        i+=1;
        if (key == int('e')) {
            factory.buy(components[i]);
        }
        i+=1;
        if (key == int('r')) {
            factory.buy(components[i]);
        }
        i+=1;
        if (key == int('t')) {
            factory.buy(components[i]);
        }
        i+=1;

        // Build Car
        if (key == int('b')) {
            factory.build_car();
        }

        // Buy and Build max Cars possible
        if (key == int('m')) {
            while (factory.can_buy_car()) {
                factory.buy_and_build_car();
            }
            std::cout << "tried to buy and build max" << std::endl;
        }

        // Buy and build
        if (key == SPACE) {
            factory.buy_and_build_car();
        }

        // Modify sell price
        if (key == UP) {
            factory.wallet.set_sell_price(factory.wallet.sell_price + 100);
        } else if (key == DOWN && factory.wallet.sell_price > 100) {
            factory.wallet.set_sell_price(factory.wallet.sell_price - 100);
        }        
        bool UPDATE_POPULARITY = rounds_count % 200 == 0;
        if (UPDATE_POPULARITY){
            factory.wallet.update_popularity();
        }
        factory.wallet.update_sell_rate();

        // Selling cars according to demand

        float cars_to_sell = factory.wallet.sell_rate * 0.05;
        factory.wallet.cars_sold_buffer += cars_to_sell;
        while (factory.wallet.cars_sold_buffer >= 1.0f && factory.car_inventory > 0) {
            factory.sell_car(); // fonction qui vend 1 voiture et ajoute l'argent
            factory.wallet.cars_sold_buffer -= 1.0f;
            factory.wallet.earning_buffer += factory.wallet.sell_price;
        }
        factory.wallet.earning_rate = factory.wallet.earning_buffer * 0.05;

        // Close game
        if (key == Escape){
            break;
        }
        if (factory.wallet.budget > max_funds){
            max_funds = factory.wallet.budget;
        }
        milliSleep(50);
    }

    return 0;
}
