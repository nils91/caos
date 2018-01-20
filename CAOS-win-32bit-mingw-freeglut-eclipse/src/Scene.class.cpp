/*
 * Scene..class.cpp
 *
 *  Created on: 11.12.2017
 *      Author: Nils
 */

#include "Scene.class.h"

namespace caos
{
Scene::Scene()
{

}
Scene::~Scene()
{
}

void Scene::add_game_component(GameComponent * game_component)
{
	game_components.push_back(game_component);
}
void Scene::delete_game_component(GameComponent * game_component)
{
	std::vector<GameComponent *> tmp_vector;
	while (!game_components.empty())
	{
		GameComponent* game_component_to_look_at = game_components.back();
		game_components.pop_back();
		if (game_component_to_look_at != game_component)
		{
			tmp_vector.push_back(game_component_to_look_at);
		}
		else
		{
			break;
		}
	}
	while (!tmp_vector.empty())
	{
		game_components.push_back((GameComponent*) tmp_vector.back());
		tmp_vector.pop_back();
	}
}

void Scene::pre_init(void)
{
	init_components();
	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_init();
	}
	init();
}
void Scene::pre_update(float dtime)
{

	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_update(dtime);
	}
	update(dtime);

}
void Scene::pre_draw(float dtime)
{

	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_draw(dtime);
	}
	draw(dtime);

}

void Scene::pre_on_reshape(GLsizei w, GLsizei h)
{
	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_on_reshape(w, h);
	}
	on_reshape(w, h);
}
void Scene::pre_on_keyboard(unsigned char key, int x, int y)
{
	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_on_keyboard(key, x, y);
	}
	on_keyboard(key, x, y);
}
void Scene::pre_on_mouse(int button, int state, int x, int y)
{
	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_on_mouse(button, state, x, y);
	}
	on_mouse(button, state, x, y);
}
void Scene::pre_on_mousemove(int x, int y)
{
	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_on_mousemove(x, y);
	}
	on_mousemove(x, y);
}
void Scene::pre_on_timer(int value)
{
	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_on_timer(value);
	}
	on_timer(value);
}
void Scene::pre_on_idle(void)
{
	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_on_idle();
	}
	on_idle();
}
void Scene::pre_on_mousewindowtransition(int state)
{
	for (unsigned int i = 0; i < game_components.size(); i++)
	{
		game_components[i]->pre_on_mousewindowtransition(state);
	}
	on_mousewindowtransition(state);
}

void Scene::on_reshape(GLsizei w, GLsizei h)
{
}
void Scene::on_keyboard(unsigned char key, int x, int y)
{
}
void Scene::on_mouse(int button, int state, int x, int y)
{
}
void Scene::on_mousemove(int x, int y)
{
}
void Scene::on_timer(int value)
{
}
void Scene::on_idle(void)
{
}
void Scene::on_mousewindowtransition(int state)
{
}

} /* namespace caos */
