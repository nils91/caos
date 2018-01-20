/*
 * GameComponent.class.h
 *
 *  Created on: 11.12.2017
 *      Author: Nils
 */

#ifndef GAMECOMPONENT_CLASS_H_
#define GAMECOMPONENT_CLASS_H_


//Includes for OpenGL
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace caos
{

class GameComponent
{
protected:
	bool active, visible;

	virtual void init(void);
	virtual void update(float dtime);
	virtual void draw(float dtime);

	virtual void on_reshape(GLsizei w, GLsizei h);
	virtual void on_keyboard(unsigned char key, int x, int y);
	virtual void on_mouse(int button, int state, int x, int y);
	virtual void on_mousemove(int x, int y);
	virtual void on_timer(int value);
	virtual void on_idle(void);
	virtual void on_mousewindowtransition(int state);
public:
	GameComponent();
	virtual ~GameComponent();

	void set_active(bool state);
	void set_visible(bool state);

	virtual void pre_init(void);
	virtual void pre_update(float dtime);
	virtual void pre_draw(float dtime);

	virtual void pre_on_reshape(GLsizei w, GLsizei h);
	virtual void pre_on_keyboard(unsigned char key, int x, int y);
	virtual void pre_on_mouse(int button, int state, int x, int y);
	virtual void pre_on_mousemove(int x, int y);
	virtual void pre_on_timer(int value);
	virtual void pre_on_idle(void);
	virtual void pre_on_mousewindowtransition(int state);
};

} /* namespace caos */

#endif /* GAMECOMPONENT_CLASS_H_ */
