/*
 * Sample.h
 *
 *  Created on: 10.12.2017
 *      Author: Nils
 */

#ifndef SAMPLEGAME_CLASS_H_
#define SAMPLEGAME_CLASS_H_


//Includes for OpenGL
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Game.class.h"

namespace caos
{

class SampleGame: public Game
{
public:
	SampleGame();
	virtual ~SampleGame();

	void init_scenes(void);
	void init(void);
	void update(float dtime);
	void draw(float dtime);

	void on_reshape(GLsizei w, GLsizei h);
	  void on_keyboard(unsigned char key, int x, int y);
};

} /* namespace caos */

#endif /* SAMPLEGAME_CLASS_H_ */
