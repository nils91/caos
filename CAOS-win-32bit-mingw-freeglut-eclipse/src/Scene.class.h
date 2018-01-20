/*
 * Scene..class.h
 *
 *  Created on: 11.12.2017
 *      Author: Nils
 */

#ifndef SCENE_CLASS_H_
#define SCENE_CLASS_H_

//Includes for OpenGL
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

//c++ includes
#include <vector>

//own includes
#include "Scene.class.h"
#include "GameComponent.class.h"

namespace caos
{

class Scene
{
private:

protected:
	std::vector<GameComponent *> game_components;
	virtual void init_components(void)=0;
	virtual void init(void)=0;
	virtual void update(float dtime)=0;
	virtual void draw(float dtime)=0;

	virtual void on_reshape(GLsizei w, GLsizei h);
	virtual void on_keyboard(unsigned char key, int x, int y);
	virtual void on_mouse(int button, int state, int x, int y);
	virtual void on_mousemove(int x, int y);
	virtual void on_timer(int value);
	virtual void on_idle(void);
	virtual void on_mousewindowtransition(int state);


	void add_game_component(GameComponent * game_component);
	void delete_game_component(GameComponent * game_component);
public:
	Scene();
	virtual ~Scene();

	void pre_init(void);
	void pre_update(float dtime);
	void pre_draw(float dtime);

	void pre_on_reshape(GLsizei w, GLsizei h);
	void pre_on_keyboard(unsigned char key, int x, int y);
	void pre_on_mouse(int button, int state, int x, int y);
	void pre_on_mousemove(int x, int y);
	void pre_on_timer(int value);
	void pre_on_idle(void);
	void pre_on_mousewindowtransition(int state);
};

} /* namespace caos */

#endif /* SCENE_CLASS_H_ */
