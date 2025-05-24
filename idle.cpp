#include "manufacture.h"
#include "utils.h"
#include "graphics.h"
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

    Factory factory;
    openWindow(1400, 800, "Imagine++ Window");

    auto gameStartTime = std::chrono::high_resolution_clock::now();

    bool auto_build_active = false; // disengaging auto build at initialization
    auto last_autobuild_time = std::chrono::high_resolution_clock::now();

    std::vector<int> budgetHistory; // Storing evolving budget
    int rounds_count = 0;
    int gap_round = 1000000;
    double max_funds = factory.wallet.budget;

    const std::string components[5] = {"electronics", "engine", "frame", "glass", "wheel"};

    while (true) {

        clearWindow(); // Clear previous frame

        // Dealing with time initialization and tracking :

        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = currentTime - gameStartTime;
        float delta_time = elapsed.count(); // Elapsed time in seconds
        lastTime = currentTime;

        factory.wallet.update_sell_rate();

        Display_background();


        // -------------- CARS : ----------------

        // Unsold car inventory
        std::ostringstream oss_car_inventory;
        oss_car_inventory << "Unsold Inventory: " << factory.car_inventory << " Cars";
        drawString(85, 140, oss_car_inventory.str(), BLACK, 23);

        // Build Car
        if (factory.can_build_car()) {
            fillRect(buildButtonX, buildButtonY, buildButtonW, buildButtonH, GREEN);
        } else {
            fillRect(buildButtonX, buildButtonY, buildButtonW, buildButtonH, RED);
        }
        drawString(buildButtonX + (buildButtonW - 130) / 2, buildButtonY + (buildButtonH + 20) / 2, "Build Car (b)", WHITE, 20);

        // Buy and Build Car
        if (factory.can_buy_car()) {
            fillRect(buyandbuildButtonX,
                     buyandbuildButtonY,
                     buyandbuildButtonW,
                     buyandbuildButtonH,
                     GREEN);
        } else {
            fillRect(buyandbuildButtonX,
                     buyandbuildButtonY,
                     buyandbuildButtonW,
                     buyandbuildButtonH,
                     RED);
        }
        drawString(buyandbuildButtonX + (buyandbuildButtonW - 170) / 2, buyandbuildButtonY + (buyandbuildButtonH + 20) / 2, "Buy & Build (Space)", WHITE, 20);


        // -------------- MATERIALS : ----------------

        // Materials inventory and price
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

        // Buy material
        int buy1buttonX = 400;
        int buy1buttonY_start = 280;
        int buy1buttonW = 115;
        int buy1buttonH = 30;
        int gap = 60;
        int by;

        int j = 0;
        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN);
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED);
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (a)", BLACK, 20);
        j+=1;

        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN);
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED);
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (z)", BLACK, 20);
        j+=1;

        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN);
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED);
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (e)", BLACK, 20);
        j+=1;

        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN);
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED);
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (r)", BLACK, 20);
        j+=1;

        by = buy1buttonY_start + j * gap;
        if (factory.wallet.budget >= factory.inventory[components[j]].first) {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, GREEN);
        } else {
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH, RED);
        }
        drawString(buy1buttonX + 15, by + 22, "Buy x1 (t)", BLACK, 20);


        // -------------- BOOSTERS : ----------------

        if (factory.total_volume_built > 50){
            Display_buildmaxcar_booster();
        }

        if (factory.total_volume_built > 100){
            Display_buymoreqty_booster();
        }

        if (factory.total_volume_built > 200){
            Display_maxmarketing_booster();
        }

        if (factory.total_volume_built > 300 && auto_build_active == false){
            Display_autobuild_inactive_booster();
        }
        if (factory.total_volume_built > 300 && auto_build_active == true){
            Display_autobuild_active_booster();
        }

        // -------------- MARKET OVERVIEW : ----------------

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

        std::ostringstream oss_earning_rate;
        oss_earning_rate << "Earned/sec :            " << factory.wallet.earning_rate;
        drawString(marketX, marketstartY, oss_earning_rate.str(), WHITE, 20);
        marketstartY += 66;

        //TO DO A WORKING ONE
        std::ostringstream oss_cars_sold_per_sec;
        oss_cars_sold_per_sec << "Retirer ça car égal a sell rate :            " << factory.wallet.cars_sold_per_sec;
        drawString(marketX, marketstartY, oss_cars_sold_per_sec.str(), WHITE, 20);

        // Display sell price (+/- buttons implemented in graphics.cpp)
        std::ostringstream oss_sell_price;
        oss_sell_price << "Sell Price ($): " << factory.wallet.sell_price;
        drawString(950, 530, oss_sell_price.str(), BLACK, 20);



        // --------------------------
        // USER INTERACTION
        // --------------------------

        // -------------- BUDGET GRAPH : ----------------

        rounds_count ++;
        bool UPDATE_GRAPH = rounds_count % gap_round == 0;
        budgetHistory.push_back(factory.wallet.budget);
        if (budgetHistory.size() > 50)
            budgetHistory.erase(budgetHistory.begin());

        factory.wallet.drawBudgetGraph(budgetHistory, graphX, graphY, graphW, graphH, max_funds);
        int key = keyboard();
        //Reset Button
        if (key == int('w')) {
            factory.wallet.reset_wallet();
            factory.wallet.reset_market();
            factory.reset_factory();
        }

        // -------------- MATERIALS PURCHASE : ----------------

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

        // -------------- CARS BUILD : ----------------

        if (key == int('b')) {
            factory.build_car();
        }
        if (key == SPACE) {
            factory.buy_and_build_car();
        }

        // -------------- MODIFY SELL PRICE : ----------------

        if (key == UP) {
            factory.wallet.set_sell_price(factory.wallet.sell_price + 100);
        } else if (key == DOWN && factory.wallet.sell_price > 100) {
            factory.wallet.set_sell_price(factory.wallet.sell_price - 100);
        }
        bool UPDATE_POPULARITY = rounds_count % 100 == 0;
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
        }
        factory.wallet.earning_rate = factory.wallet.sell_rate * factory.wallet.sell_price;


        // -------------- BOOSTERS : ----------------

        // Buy and build max cars
        if (key == int('m')) {
            while (factory.can_buy_car()) {
                factory.buy_and_build_car();
            }
        }

        // buy four pieces of each component
        if (key == int('f')) {
            // TODO
        }

        // Engage / disengage autobuild
        if (key == int('o')) {
            auto_build_active = !auto_build_active;
        }

        // Running auto build fonction
        if (auto_build_active) {
            auto now = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> elapsed_autobuild = now - last_autobuild_time;

            if (elapsed_autobuild.count() >= 5.0f) {
                if (factory.can_build_car()) {
                    factory.build_car();
                }
                last_autobuild_time = now;
            }
        }

        // Upgrade autobuild
        if (key == int('u')) {
            // add 0.1 car per second
            // price = 10.000
            // TODO
        }

        // Max Marketing
        if (key == int('k')) {
            // set popularity to 100 for 30 secs
            // TODO
        }


        // -------------- CLOSE GAME : ----------------
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
