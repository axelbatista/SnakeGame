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
#include "windows.h"
#include "SpriteCodex.h"

bool gameIsOver = false;

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	bd(Snake{ Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 }),
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
		if (wnd.kbd.KeyIsPressed('D')) {
			if (vel.x != -20) 
				vel = { 20,0 };
		}
		else if (wnd.kbd.KeyIsPressed('A')) {			//toggle movement
			if (vel.x != 20) 
			vel = { -20,0 };
		}
		else if (wnd.kbd.KeyIsPressed('S')) {
			if (vel.y != -20)
				vel = { 0,20 };
		}
		else if (wnd.kbd.KeyIsPressed('W')) {
			if (vel.y != 20) 
			vel = { 0,-20 };
		}
		if (snekMoveCounter >= period) {
			bd.change(vel);
			snekMoveCounter = 0;
		}
		if (fd.isCollided(bd.getStart())) {
			bd.grow();								//reinitialize with a copy assignment.
			fd = Food(bd);
			if (period > 5.0f)
				period -= 0.5f;
		}
		snekMoveCounter++;
	}
}

void Game::ComposeFrame()
{
	if (gameIsOver)
		SpriteCodex::DrawGameOver(350, 250, gfx);
	else {
		bd.show1(brd);
		fd.draw(brd);
	}
}
