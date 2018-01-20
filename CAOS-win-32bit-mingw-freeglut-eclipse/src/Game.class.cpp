/*
 * Game.class.cpp
 *
 *  Created on: 10.12.2017
 *      Author: Nils
 */
//Includes for OpenGL
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

//own include
#include "Game.class.h"
namespace caos
{
Game::Game()
{
	active_scene = NULL;
}
Game::~Game()
{

}
void Game::pre_init(void)
{
	init_scenes();
	if (active_scene != NULL)
	{
		active_scene->pre_init();
	}
	init();
}
void Game::pre_update(float dtime)
{
	if (active_scene != NULL)
	{
		active_scene->pre_update(dtime);
	}

	update(dtime);

}
void Game::pre_draw(float dtime)
{
	if (active_scene != NULL)
	{
		active_scene->pre_draw(dtime);
	}
	draw(dtime);

}

void Game::pre_on_reshape(GLsizei w, GLsizei h)
{
	if (active_scene != NULL)
	{
		active_scene->pre_on_reshape(w, h);
	}
	on_reshape(w, h);
}
void Game::pre_on_keyboard(unsigned char key, int x, int y)
{
	if (active_scene != NULL)
	{
		active_scene->pre_on_keyboard(key, x, y);
	}
	on_keyboard(key, x, y);
}
void Game::pre_on_mouse(int button, int state, int x, int y)
{
	if (active_scene != NULL)
	{
		active_scene->pre_on_mouse(button, state, x, y);
	}
	on_mouse(button, state, x, y);
}
void Game::pre_on_mousemove(int x, int y)
{
	if (active_scene != NULL)
	{
		active_scene->pre_on_mousemove(x, y);
	}
	on_mousemove(x, y);
}
void Game::pre_on_timer(int value)
{
	if (active_scene != NULL)
	{
		active_scene->pre_on_timer(value);
	}
	on_timer(value);
}
void Game::pre_on_idle(void)
{
	if (active_scene != NULL)
	{
		active_scene->pre_on_idle();
	}
	on_idle();
}
void Game::pre_on_mousewindowtransition(int state)
{
	if (active_scene != NULL)
	{
		active_scene->pre_on_mousewindowtransition(state);
	}
	on_mousewindowtransition(state);
}
void Game::on_reshape(GLsizei w, GLsizei h)
{
}
void Game::on_keyboard(unsigned char key, int x, int y)
{
}
void Game::on_mouse(int button, int state, int x, int y)
{
}
void Game::on_mousemove(int x, int y)
{
}
void Game::on_timer(int value)
{
}
void Game::on_idle(void)
{
}
void Game::on_mousewindowtransition(int state)
{
}
}

