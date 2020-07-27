/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Move.h"
#include "windows.h"
#include "SpriteCodex.h"

bool gameIsOver = false;
bool bodStarted = false;

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	snek(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2, brd),
	bd(),
	fd(bd)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameIsOver) {
		fd.draw(brd);
		if (wnd.kbd.KeyIsPressed('D')) {
			if (snekMoveCounter >= period) {
				bd.change(1, 0,snek);
				snekMoveCounter = 0;
				bd.collided(snek);
			}
		}
		else if (wnd.kbd.KeyIsPressed('A')) {
			if (snekMoveCounter >= period) {
				bd.change(-1, 0,snek);
				snekMoveCounter = 0;
				bd.collided(snek);
			}
		}
		else if (wnd.kbd.KeyIsPressed('S')) {
			if (snekMoveCounter >= period) {
				bd.change(0, 1,snek);
				snekMoveCounter = 0;
				bd.collided(snek);
			}
		}
		else if (wnd.kbd.KeyIsPressed('W')) {
			if (snekMoveCounter >= period) {
				bd.change(0, -1,snek);
				snekMoveCounter = 0;
				bd.collided(snek);
			}
		}
		snek.show(brd);
		if (fd.isCollided(snek)) {
			bd.grow();
			bodStarted = true;
			fd = Food(bd);
			if (period > 2.0)
				period -= 1.0f;
		}
		if (bodStarted)
			bd.show1(brd);
		snekMoveCounter++;
	}
}

void Game::ComposeFrame()
{
	if (gameIsOver)
		SpriteCodex::DrawGameOver(350, 250, gfx);
}
