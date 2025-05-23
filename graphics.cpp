#include "graphics.h"
#include <Imagine/Graphics.h>
using namespace Imagine;

// #############################################################################################
// ######################################### ESTHETICS #########################################
// #############################################################################################

int buttonSpacing = 20; // espace vertical entre chaque booster
int buttonStartX = buildmaxButtonX;
int buttonStartY = buildmaxButtonY;

void Display_buildmaxcar_booster(){
    int y = buttonStartY + 0 * buttonSpacing;
    fillRect(buttonStartX, y, buildmaxButtonW, buildmaxButtonH, BLUE);
    drawString(buttonStartX + 20, y + 30, "Buy and build max (m)", WHITE, 20);
}

void Display_buymoreqty_booster(){
    int y = buttonStartY + 1 * buttonSpacing;
    fillRect(buttonStartX, y, buildmaxButtonW, buildmaxButtonH, BLUE);
    drawString(buttonStartX + 20, y + 30, "Buy x4 components (f)", WHITE, 20);
}

void Display_maxmarketing_booster(){
    int y = buttonStartY + 2 * buttonSpacing;
    fillRect(buttonStartX, y, buildmaxButtonW, buildmaxButtonH, BLUE);
    drawString(buttonStartX + 20, y + 30, "Marketing (k)", WHITE, 20);
}

void Display_autobuild_active_booster(){
    int y = buttonStartY + 3 * buttonSpacing;
    fillRect(buttonStartX, y, buildmaxButtonW, buildmaxButtonH, GREEN);
    drawString(buttonStartX + 20, y + 30, "Auto build (o)", WHITE, 20);
    y = buttonStartY + 4 * buttonSpacing - 10;
    fillRect(buttonStartX, y, buildmaxButtonW, buildmaxButtonH, BLUE);
    drawString(buttonStartX + 20, y + 30, "Upgrade (u)", WHITE, 20);
}

void Display_autobuild_inactive_booster(){
    int y = buttonStartY + 3 * buttonSpacing;
    fillRect(buttonStartX, y, buildmaxButtonW, buildmaxButtonH, GREY);
    drawString(buttonStartX + 20, y + 30, "Auto build (o)", WHITE, 20);
    y = buttonStartY + 4 * buttonSpacing - 10;
    fillRect(buttonStartX, y, buildmaxButtonW, buildmaxButtonH, BLUE);
    drawString(buttonStartX + 20, y + 30, "Upgrade (u)", WHITE, 20);
}

void Display_background(){

    // -------------- Background ----------------

    fillRect(0, 0, 1400, 800, Color(232, 237, 223)); // Background

    // -------------- Header ----------------

    fillRect(0, 0, 1400, 50, Color(51, 53, 51)); // Header
    drawString(50, 35, "IDLE CAR FACTORY", Color(245, 203, 92), 30);

    fillRect(resetButtonX, resetButtonY, resetButtonW, resetButtonH, Color(245, 203, 92));
    drawString(resetButtonX + 22, resetButtonY + 27, "RESET", WHITE, 20);

    // -------------- Manufacture ----------------

    fillRect(50, 100, 500, 460, Color(255, 255, 255));
    drawString(234, 85, "MANUFACTURE", BLACK, 20);


    // -------------- Budget box and graph ----------------

    fillRect(600, 100, 300, 300, Color(255, 255, 255));
    drawString(720, 85, "FUNDS", BLACK, 20);
    drawString(610,200, "$", BLACK, 15);
    drawString(740,290, "time", BLACK, 15);

    // -------------- Boosters ----------------

    fillRect(600, 450, 300, 450, Color(255, 255, 255));
    drawString(702, 435, "BOOSTERS", BLACK, 20);

    // -------------- Market Overview ----------------

    fillRect(950, 100, 400, 400, Color(36, 36, 35));
    for (int i = 1; i <= 5; i++) {
        int y = 100 + i * (400 / 6);
        drawLine(970, y, 1330, y, WHITE);
    }
    drawString(1060, 85, "MARKET OVERVIEW", BLACK, 20);


    // Sell Rate Graph
    fillRect(950, 550, 400, 230, Color(255, 255, 255));

    // -------------- Setting sell price ----------------

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

}











