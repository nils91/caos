/*
 * engine.h
 *
 *  Created on: 10.12.2017
 *      Author: Nils
 */

#ifndef ENGINE_H_
#define ENGINE_H_

//Includes for OpenGL
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace caos
{
int init(int argc, char** argv);
void init_game(int argc, char** argv);
void init_game_post(void);
void init_glut(int argc, char** argv);
void init_glut_callbacks(void);
void init_glut_post(void);
void init_gl(int argc, char** argv);
void init_window(int argc, char** argv);
void reshape_callback(GLsizei w, GLsizei h);
void keyboard_callback(unsigned char key, int x, int y);
void mouse_callback(int button, int state, int x, int y);
void mousemotion_callback(int x, int y);
void display_callback();
void timer_callback(int value);
void idle_callback(void);
void draw(float dtime);
void update(float dtime);
void mouseentry_callback(int state);
void exit_callback(void);
unsigned long get_microseconds(void);//returns number of microseconds since epoch
}

#endif /* ENGINE_H_ */
