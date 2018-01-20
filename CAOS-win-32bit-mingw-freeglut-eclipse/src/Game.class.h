/*
 * Game.class.h
 *
 *  Created on: 10.12.2017
 *      Author: Nils
 */

#ifndef GAME_CLASS_H_
#define GAME_CLASS_H_

//Includes for OpenGL
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

//c++ includes
#include <vector>

//own includes
#include "Scene.class.h"

namespace caos
{
class Game
{
protected:
	std::vector<Scene *> all_scenes;
	Scene * active_scene;
	virtual void init_scenes(void)=0;
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
public:
	Game();
	virtual ~Game();

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
}

#endif /* GAME_CLASS_H_ */
