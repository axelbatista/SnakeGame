#pragma once
#include "Location.h"
#include "Board.h"
#include <vector>

class Snake {
	Location spot;
	Color c = Colors::Red;
	bool activated;
public:
	Snake() = default;
	Snake(int pos, int pos2) : spot{ pos,pos2 }, c{ Colors::Green }, activated{ true } {}
	void show(const Board& b) const;
	Location& getSpot();
	const Location getSpot1() const;
	bool touched(const Snake& snek) const;
	const Color getColor() const;
	const bool getState() const;
};


class Body {
	std::vector<Snake> segments;
	int current = 0;
public:
	Body(Snake snek) : current{ 0 } {
		segments.emplace_back(snek);
	}
	void grow();
	void show1(const Board& b);
	void change(const Location vel);
	void collided(const Snake snek) const;
	bool checkAvailable(int x, int y) const;
	const Snake& getStart();
};