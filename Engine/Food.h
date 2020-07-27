#pragma once
#include "Location.h"
#include "Snake.h"

class Food {
	Location spot;
	Color c;
public:
	Food(const Body& bd);
	bool isCollided(const Snake& snake) const;
	void draw(const Board& b);
};