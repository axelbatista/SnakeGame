#include "Snake.h"


extern bool gameIsOver;

void Body::show1(const Board& b) {
		for (const auto& each : segments) {
			b.draw(each.getSpot1(), each.getColor());
		}
}

void Body::change(const Location vel)
{ 
	for (int i = segments.size() - 1; i > 0; i--) {
					segments[i] = segments[i - 1];
	}
	if (segments[0].getSpot1().x + vel.x > 780 || segments[0].getSpot1().x + vel.x < 0 || segments[0].getSpot1().y + vel.y < 0 || segments[0].getSpot1().y + vel.y> 580) {
		gameIsOver = true;
		return;
	}
	segments[0].getSpot().x += vel.x;
	segments[0].getSpot().y += vel.y;
	collided(segments[0]);
}

void Body::collided(const Snake& snek) const
{
	for (int i = 1; i < segments.size(); i++) {
		if (segments[i].touched(snek))
			gameIsOver = true;
	}
}

bool Body::checkAvailable(int x, int y) const
{
		if (segments.size() == current) {
			for (int i = 0, xP = segments.at(i).getSpot1().x; i < segments.size() && xP >= 0 && xP <= 780; i++) {
				if (x == xP && segments.at(i).getSpot1().y == y)
					return true;
			}
	}
	return false;
}

const Snake& Body::getStart()
{
	return segments[0];
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

const Color Snake::getColor() const
{
	return c;
}


void Body::grow()
{
	current++;
	segments.emplace_back(segments[current - 1]);
}





















