#include "Snake.h"


extern bool gameIsOver;			//gameIsOver from game.cpp
								//is for the state of the game.

void Body::show1(const Board& b) {
		for (const auto& each : segments) {
			if (each.getState()) 
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
	segments[0].getSpot().x += vel.x;			//main work. Every next segmented part of the snake takes the previous position of the body part
	segments[0].getSpot().y += vel.y;			//that came before, so we can do that by transversing the body backwards. Pretty common to do.
	collided(segments[0]);						//this segments[0] part is for moving the head of the snake which isn't included in the loop above.
}												//this lets us update the rest of the body.

void Body::collided(const Snake snek) const
{
	for (int i = 1; i < segments.size(); i++) {
		if (segments[i].touched(snek))
			gameIsOver = true;
	}
}

bool Body::checkAvailable(int x, int y) const
{
	for (int i = 0, xP = segments[i].getSpot1().x; i < segments.size() && xP >= 0 && xP <= 780; i++) {
		if (x == xP && segments[i].getSpot1().y == y)
			return true;										//don't have the food respawn inside the body of the snake.

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

const bool Snake::getState() const
{
	return activated;
}


void Body::grow()
{
	segments.emplace_back(segments[current++]);			//fine. Supposing this saved me from doing work in the loop where we update the values.
}														//incase you're wondering as to why it looks kinda weird.





















