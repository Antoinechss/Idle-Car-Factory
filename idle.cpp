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

    bool auto_build_active = false;
    auto last_autobuild_time = std::chrono::high_resolution_clock::now();

    bool maxMarketingActive = false;
    float maxMarketingStartTime = 0.0f;
    const float maxMarketingDuration = 30.0f;

    std::vector<int> budgetHistory;
    int rounds_count = 0;
    int gap_round = 1000000;
    double max_funds = factory.wallet.budget;

    const std::string components[5] = {"electronics", "engine", "frame", "glass", "wheel"};
    double autobuild_gap = 5.0f;

    while (true) {

        clearWindow();

        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = currentTime - gameStartTime;
        float delta_time = elapsed.count();
        lastTime = currentTime;

        factory.wallet.update_sell_rate();
        Display_background();

        std::ostringstream oss_game_time;
        oss_game_time << "Game time : " << delta_time;
        drawString(700, 35, oss_game_time.str(), Color(245, 203, 92), 30);

        // ----- CARS -----

        std::ostringstream oss_car_inventory;
        oss_car_inventory << "Unsold Inventory: " << factory.car_inventory << " Cars";
        drawString(85, 140, oss_car_inventory.str(), BLACK, 23);

        fillRect(buildButtonX, buildButtonY, buildButtonW, buildButtonH,
                 factory.can_build_car() ? GREEN : RED);
        drawString(buildButtonX + (buildButtonW - 130) / 2,
                   buildButtonY + (buildButtonH + 20) / 2,
                   "Build Car (b)", WHITE, 20);

        fillRect(buyandbuildButtonX, buyandbuildButtonY,
                 buyandbuildButtonW, buyandbuildButtonH,
                 factory.can_buy_car() ? GREEN : RED);
        drawString(buyandbuildButtonX + (buyandbuildButtonW - 170) / 2,
                   buyandbuildButtonY + (buyandbuildButtonH + 20) / 2,
                   "Buy & Build (Space)", WHITE, 20);

        // ----- MATERIALS -----

        int y_offset = 300;
        for (const auto& item : factory.inventory) {
            std::ostringstream oss_inventory;
            oss_inventory << item.first << ": " << item.second.first
                          << " USD, Quantity: " << item.second.second;
            drawString(70, y_offset, oss_inventory.str(), BLACK, 20);
            y_offset += 60;
        }

        std::ostringstream oss_buy_price;
        oss_buy_price << "Buy all price : " << factory.car_build_price;
        drawString(70, y_offset, oss_buy_price.str(), BLACK, 20);

        int buy1buttonX = 400;
        int buy1buttonY_start = 280;
        int buy1buttonW = 115;
        int buy1buttonH = 30;
        int gap = 60;

        std::string shortcutKeys = "azert";

        for (int j = 0; j < 5; ++j) {
            int by = buy1buttonY_start + j * gap;
            fillRect(buy1buttonX, by, buy1buttonW, buy1buttonH,
                     factory.wallet.budget >= factory.inventory[components[j]].first ? GREEN : RED);
            drawString(buy1buttonX + 15, by + 22,
                       "Buy x1 (" + std::string(1, shortcutKeys[j]) + ")",
                       BLACK, 20);
        }

        // ----- BOOSTERS -----

        if (factory.total_volume_built > 0) {
            Display_buildmaxcar_booster();
            Display_maxmarketing_booster();
            Display_autobuild_upgrade_booster();
            if (auto_build_active)
                Display_autobuild_active_booster();
            else
                Display_autobuild_inactive_booster();
        }

        if (maxMarketingActive && delta_time - maxMarketingStartTime >= maxMarketingDuration) {
            maxMarketingActive = false;
            factory.wallet.update_popularity();
        }

        // ----- MARKET OVERVIEW -----

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

        std::ostringstream oss_sell_price;
        oss_sell_price << "Sell Price ($): " << factory.wallet.sell_price;
        drawString(950, 530, oss_sell_price.str(), BLACK, 20);

        // ----- USER INTERACTION -----

        rounds_count++;
        bool UPDATE_GRAPH = rounds_count % gap_round == 0;
        budgetHistory.push_back(factory.wallet.budget);
        if (budgetHistory.size() > 50)
            budgetHistory.erase(budgetHistory.begin());
        factory.wallet.drawBudgetGraph(budgetHistory, graphX, graphY, graphW, graphH, max_funds);

        int key = keyboard();

        // Wallet reset
        if (key == int('w')) {
            factory.wallet.reset_wallet();
            factory.wallet.reset_market();
            factory.reset_factory();
        }

        // Material purchase (azert)
        int i = 0;
        if (key == int('a')) factory.buy(components[i]);
        i++;
        if (key == int('z')) factory.buy(components[i]);
        i++;
        if (key == int('e')) factory.buy(components[i]);
        i++;
        if (key == int('r')) factory.buy(components[i]);
        i++;
        if (key == int('t')) factory.buy(components[i]);

        // Car actions
        if (key == int('b')) factory.build_car();
        if (key == SPACE) factory.buy_and_build_car();

        // Price adjustment
        if (key == UP) factory.wallet.set_sell_price(factory.wallet.sell_price + 100);
        if (key == DOWN && factory.wallet.sell_price > 100)
            factory.wallet.set_sell_price(factory.wallet.sell_price - 100);

        // Periodic popularity update
        bool UPDATE_POPULARITY = rounds_count % 100 == 0;
        if (UPDATE_POPULARITY)
            factory.wallet.update_popularity();

        // Selling loop
        float cars_to_sell = factory.wallet.sell_rate * 0.05f;
        factory.wallet.cars_sold_buffer += cars_to_sell;
        while (factory.wallet.cars_sold_buffer >= 1.0f && factory.car_inventory > 0) {
            factory.sell_car();
            factory.wallet.cars_sold_buffer -= 1.0f;
        }
        factory.wallet.earning_rate = factory.wallet.sell_rate * factory.wallet.sell_price;

        // Boosters
        if (key == int('m')) {
            while (factory.can_buy_car())
                factory.buy_and_build_car();
        }

        if (key == int('k')) {
            if (factory.wallet.budget > 1000) {
                factory.wallet.budget -= 1000;
                factory.wallet.popularity = 100.0f;
                maxMarketingActive = true;
                maxMarketingStartTime = delta_time;
            } else {
                std::cout << "insufficient budget" << std::endl;
            }
        }

        // Autobuild toggle and upgrade
        std::ostringstream oss_autobuild_gap;
        oss_autobuild_gap << "Autobuild rate : " << autobuild_gap;
        drawString(400, 760, oss_autobuild_gap.str(), BLACK, 20);

        if (key == int('o'))
            auto_build_active = !auto_build_active;

        if (auto_build_active) {
            auto now = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> elapsed_autobuild = now - last_autobuild_time;
            if (elapsed_autobuild.count() >= autobuild_gap && factory.can_buy_car()) {
                factory.buy_and_build_car();
                last_autobuild_time = now;
            }
        }

        if (key == int('u')) {
            if (factory.wallet.budget > 1000) {
                autobuild_gap = autobuild_gap / 1.05;
            } else {
                std::cout << "not enough budget" << std::endl;
            }
        }

        if (key == Escape)
            break;

        if (factory.wallet.budget > max_funds)
            max_funds = factory.wallet.budget;

        milliSleep(50);
    }

    return 0;
}
