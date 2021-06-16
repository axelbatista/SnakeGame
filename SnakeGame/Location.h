#pragma once

struct Location {
	int x;
	int y;
	bool operator== (const Location& l) {
		return x == l.x && y == l.y;
	}
};