#include "business.h"
#include <Imagine/Graphics.h>
using namespace Imagine;
Wallet::Wallet()
{
    reset_wallet();
    reset_market();
    cars_sold_buffer;
}

void Wallet::reset_market()
{
    sell_rate = 0;
    sell_price = 0;
    popularity = 0;
    cars_sold_buffer = 0;
    earning_buffer = 0;
    earning_rate = 0;
    update_popularity();
    std::cout << "Resetting market values" << std::endl;
}

void Wallet::reset_wallet()
{
    budget = 0;

    std::cout << "Creating a new empty wallet" << std::endl;
}

void Wallet::set_sell_price(double price)
{
    sell_price = price;
}

void Wallet::update_popularity()
{
    popularity = rand() % 101;
}

void Wallet::update_sell_rate()
{
    sell_rate = popularity / sell_price;
}

void Wallet::drawBudgetGraph(const std::vector<int>& history, int graphX, int graphY, int graphW, int graphH) {
    // Clear graph area
    fillRect(graphX, graphY, graphW, graphH, Color(255, 255, 255));
    drawRect(graphX, graphY, graphW, graphH, BLACK); // Optional border

    int n = history.size();
    if (n < 2) return;

    for (int i = 1; i < n; ++i) {
        int x1 = graphX + (i - 1) * graphW / (n - 1);
        int y1 = graphY + graphH - (history[i - 1] * graphH / 10000);
        int x2 = graphX + i * graphW / (n - 1);
        int y2 = graphY + graphH - (history[i] * graphH / 10000);

        drawLine(x1, y1, x2, y2, BLUE);

        for (int i = 1; i <= 4; i++) {
            int y = graphY + i * graphH / 5;
            drawLine(graphX, y, graphX + graphW, y, Color(200, 200, 200));
        }
    }
}
