#include "Snake.h"

extern bool gameIsOver;
extern bool bodStarted;

void Snake::show(const Board& b) const
{
	b.draw(spot, c);
}

void Body::show1(const Board& b) {
	for (const auto &each : segments) {
		int one = each.getSpot1().x;
		if (one >= 0 && one <= 780)
			b.draw(each.getSpot1(), { 0,255,0 });
	}
}

void Body::change(int x, int y,Snake& snake)
{ 
	if (bodStarted) {
		for (int i = current - 1; i >= 0; i--) {
			if (i == 0)
				segments[0] = snake;
			else
			segments[i] = segments[i - 1];
		}
	}
	if (snake.getSpot1().x + x > 780 || snake.getSpot1().x + x < 0 || snake.getSpot1().y + y < 0 || snake.getSpot1().y + y> 580) {
		gameIsOver = true;
		return;
	}
	snake.getSpot().x += (x*20);
	snake.getSpot().y += (y*20);
}

void Body::collided(const Snake& snek) const
{
	for (const auto &each : segments) {
		if (each.touched(snek))
			gameIsOver = true;
	}
}

bool Body::checkAvailable(int x, int y) const
{
	for (int i = 0, xP = segments[i].getSpot1().x; i < current && xP >= 0 && xP <= 780; i++) {
		if (x == xP && segments[i].getSpot1().y == y)
			return true;
	}
	return false;
}

Location& Snake::getSpot()
{
	return spot;
}

const Location Snake::getSpot1() const {
	return spot;
}

bool Snake::touched(const Snake& snek) const
{
	return spot.x == snek.spot.x && spot.y == snek.spot.y;
}

void Body::grow()
{
	if (current + 1 <= size) {
		current++;
	}
}





















