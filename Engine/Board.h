#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Board {
	Graphics *gfx;
	static constexpr int dimension = 20;
public:
	Board(Graphics& gfx_) : gfx{&gfx_} {}
	void draw(const Location& spot, const Color& c) const;
};