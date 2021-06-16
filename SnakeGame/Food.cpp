#include "Food.h"
#include <random>
#include <ctime>
#include "Graphics.h"

Food::Food(const Body& bd) : c{ 255,255,255 }
{
	int x = 20;
	int y = 20;
	do {
		std::mt19937 mx{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
		std::uniform_int_distribution<int> choice(0, 39);
		x *= choice(mx);
		std::uniform_int_distribution<int> choice1(0, 29);
		y *= choice1(mx);
	} while (bd.checkAvailable(x,y));
	spot = { x,y };
}

bool Food::isCollided(const Snake snake) const
{
	return spot.x == snake.getSpot1().x && spot.y == snake.getSpot1().y;
}

void Food::draw(const Board& b)
{
	b.draw(spot, c);
}


