#pragma once
#include "Location.h"
#include "Board.h"

class Snake {
	Location spot;
	Color c;
public:
	Snake() = default;
	Snake(int pos, int pos2) : spot{ pos,pos2 }, c{ Colors::Green } {}
	void show(const Board& b) const;
	Location& getSpot();
	const Location getSpot1() const;
	bool touched(const Snake& snek) const;
	const Color getColor() const;
};


class Body {
	static constexpr int size = 100;
	Snake segments[size];
	int current;
public:
	Body() : current{ 0 } {};
	void grow();
	void show1(const Board& b);
	void change(const Location vel, Snake& snake);
	void collided(const Snake& snek) const;
	bool checkAvailable(int x, int y) const;
};