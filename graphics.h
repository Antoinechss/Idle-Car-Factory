#pragma once

void Display_background();
void Display_buildmaxcar_booster();
void Display_buymoreqty_booster();
void Display_maxmarketing_booster();
void Display_autobuild_inactive_booster();
void Display_autobuild_active_booster();
void Display_autobuild_upgrade_booster();

// -------------- Header ----------------

const int resetButtonW = 100;
const int resetButtonH = 40;
const int resetButtonX = 1400 - resetButtonW - 50;
const int resetButtonY = 5;

// -------------- Manufacture ----------------

// Build Car
const int buildButtonX = 100;
const int buildButtonY = 160;
const int buildButtonW = 175;
const int buildButtonH = 40;

// Buy and Build Car
const int buyandbuildButtonX = 325;
const int buyandbuildButtonY = 160;
const int buyandbuildButtonW = 175;
const int buyandbuildButtonH = 40;

// -------------- Boosters ----------------


//Build Max Cars button
const int buildmaxButtonX = 650;
const int buildmaxButtonY = 490;
const int buildmaxButtonW = 210;
const int buildmaxButtonH = 40;

// -------------- Market Overview ----------------



// -------------- Budget box and graph ----------------

const int graphX = 630;
const int graphY = 120;
const int graphW = 260;
const int graphH = 150;


// +/- buttons

const int price_up_buttonW = 40;
const int price_up_buttonH = 30;
const int price_up_buttonY = 507;
const int price_up_buttonX = 1270;

const int price_down_buttonX = 1215;
const int price_down_buttonY = price_up_buttonY;
const int price_down_buttonW = price_up_buttonW;
const int price_down_buttonH = price_up_buttonH;

