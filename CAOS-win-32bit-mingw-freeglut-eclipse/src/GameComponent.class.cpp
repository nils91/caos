/*
 * GameComponent.class.cpp
 *
 *  Created on: 11.12.2017
 *      Author: Nils
 */

#include "GameComponent.class.h"

namespace caos
{

GameComponent::GameComponent()
{
	active = TRUE;
	visible = TRUE;

}

GameComponent::~GameComponent()
{
	// TODO Auto-generated destructor stub
}
void GameComponent::pre_init(void)
{
	init();
}
void GameComponent::pre_update(float dtime)
{
	if (active)
	{
		update(dtime);
	}
}
void GameComponent::pre_draw(float dtime)
{
	if (visible)
	{
		draw(dtime);
	}
}

void GameComponent::pre_on_reshape(GLsizei w, GLsizei h)
{
	on_reshape(w, h);
}
void GameComponent::pre_on_keyboard(unsigned char key, int x, int y)
{
	on_keyboard(key, x, y);
}
void GameComponent::pre_on_mouse(int button, int state, int x, int y)
{
	on_mouse(button, state, x, y);
}
void GameComponent::pre_on_mousemove(int x, int y)
{
	on_mousemove(x, y);
}
void GameComponent::pre_on_timer(int value)
{
	on_timer(value);
}
void GameComponent::pre_on_idle(void)
{
	on_idle();
}
void GameComponent::pre_on_mousewindowtransition(int state)
{
	on_mousewindowtransition(state);
}

void GameComponent::set_active(bool state)
{
	active = state;
}
void GameComponent::set_visible(bool state)
{
	visible = state;
}
void GameComponent::init(void){

}
void GameComponent::update(float dtime){

}
void GameComponent::draw(float dtime){

}
void GameComponent::on_reshape(GLsizei w, GLsizei h)
{
}
void GameComponent::on_keyboard(unsigned char key, int x, int y)
{
}
void GameComponent::on_mouse(int button, int state, int x, int y)
{
}
void GameComponent::on_mousemove(int x, int y)
{
}
void GameComponent::on_timer(int value)
{
}
void GameComponent::on_idle(void)
{
}
void GameComponent::on_mousewindowtransition(int state)
{
}

} /* namespace caos */
