#pragma once
#include "Location.h"
#include "Board.h"
#include "Food.h"

class Snake {
	Location spot;
	Color c;
public:
	Snake() = default;
	Snake(int pos, int pos2, const Board& b) : spot{ pos,pos2 }, c{ 255,0,0 } {
	}
	Snake(int pos, int pos2) : spot{pos, pos2}, c(255,0,0) {}
	void show(const Board& b) const;
	Location& getSpot();
	const Location getSpot1() const;
	bool touched(const Snake& snek) const;
};


class Body {
	static constexpr int size = 100;
	Snake segments[size];
	int current = 0;
public :
	Body() = default;
	void grow();
	void show1(const Board& b);
	void change(int x, int y,Snake& snake);
	void collided(const Snake& snek) const;
	bool checkAvailable(int x, int y) const;
};