/*
 * CompositeGameComponent.class.h
 *
 *  Created on: 11.12.2017
 *      Author: Nils
 */

#ifndef COMPOSITEGAMECOMPONENT_CLASS_H_
#define COMPOSITEGAMECOMPONENT_CLASS_H_

//Includes for OpenGL
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

//c++ includes
#include <vector>

//own includes
#include "GameComponent.class.h"

namespace caos
{

class CompositeGameComponent:
		public GameComponent
{
private:
	virtual void init_components(void)=0;
protected:
	std::vector<GameComponent *> game_components;
public:
	CompositeGameComponent();
	virtual ~CompositeGameComponent();

	void add_game_component(GameComponent * game_component);
	void delete_game_component(GameComponent * game_component);

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

#endif /* COMPOSITEGAMECOMPONENT_CLASS_H_ */
