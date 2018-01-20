/*
 * engine.cpp
 *
 *  Created on: 10.12.2017
 *      Author: Nils
 */
//Includes for OpenGL
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

//Includes for C libs
#include <stdio.h>
#include <math.h>

//c++ includes
#include <iostream>
#include <string>
#include <chrono>

//own include
#include "engine.h"
#include "Game.class.h"
#include "SampleGame.class.h"

//defines

//window
#define H 600
#define W 800

#define FULLSCREEN 0

#define TITLE "CAOS"

#define FPS 60 //defines how often the engine tries to call draw per second (Values higher than the monitor refresh rate make no sense and are ignored by opengl/glut anyway)
#define SIMULATION_TIMESTEP_MULTIPLY 1 //FPS*SIMULATION_TIMESTEP_MULTIPLY defines how often the engine tries to call update per second (recommended value is 1, because doesnt work sometimes)(sometimes falls back to the drawing speed, so make extra sure to include dtime in your update calculations)

#define TIMER_DRAW 0
#define TIMER_UPDATE 1



int main(int argc, char** argv)
{
	return caos::init(argc, argv);
}

namespace caos
{
int fps_timestep; //containes the actual time in ms calculated between calls to draw
int simulation_timestep;//contains the actual time in ms calculated between calls to update

unsigned long last_update_time;
unsigned long last_draw_time;

Game *game;

int init(int argc, char** argv)
{
	fps_timestep = 1000.0 / FPS;
	simulation_timestep = 1000.0 / (FPS * SIMULATION_TIMESTEP_MULTIPLY);

	init_game(argc, argv);
	init_glut(argc, argv);
	init_window(argc, argv);
	init_gl(argc, argv);
	init_glut_callbacks();
	init_game_post();
	init_glut_post();

	return 0;
}
void init_glut(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
}
void init_glut_callbacks()
{
	//setup all the glut callbacks
	glutEntryFunc(mouseentry_callback);
	glutIdleFunc(idle_callback);
	glutReshapeFunc(reshape_callback);
	glutDisplayFunc(display_callback);
	glutKeyboardFunc(keyboard_callback);
	glutMouseFunc(mouse_callback);
	glutMotionFunc(mousemotion_callback);
	glutTimerFunc(fps_timestep, timer_callback, TIMER_DRAW);
	glutTimerFunc(simulation_timestep, timer_callback, TIMER_UPDATE);
	atexit(exit_callback);
}
void init_glut_post()
{
	glutMainLoop();
}
void init_gl(int argc, char** argv)
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_FLAT);
}
void init_window(int argc, char** argv)
{
	int screen_h = glutGet(GLUT_SCREEN_HEIGHT);
	int screen_w = glutGet(GLUT_SCREEN_WIDTH);
	int pos_y = screen_h / 2.0 - H / 2.0;
	int pos_x = screen_w / 2.0 - W / 2.0;
	glutInitWindowPosition(pos_x, pos_y);
	glutInitWindowSize( W, H);

	glutCreateWindow( TITLE);
	if (FULLSCREEN)
	{
		glutFullScreen();
	}
}
void init_game(int argc, char** argv){
	game=new SampleGame();
}
void init_game_post(){
	game->pre_init();
}
void reshape_callback(GLsizei w, GLsizei h)
{
	game->pre_on_reshape(w,h);

	glutPostRedisplay();
}
void keyboard_callback(unsigned char key, int x, int y)
{
	game->pre_on_keyboard(key,x,y);
}
void mouse_callback(int button, int state, int x, int y)
{
	game->pre_on_mouse(button,state,x,y);
}
void mousemotion_callback(int x, int y)
{
	game->pre_on_mousemove(x,y);
}
void display_callback()
{
	glutSwapBuffers();
}
//returns number of microseconds since epoch
unsigned long get_microseconds()
{
	auto new_timepoint = std::chrono::steady_clock::now();
	auto new_timepoint_epoch = new_timepoint.time_since_epoch();
	auto new_timepoint_microseconds = std::chrono::duration_cast<
			std::chrono::microseconds>(new_timepoint_epoch);
	unsigned long epoch_long = new_timepoint_microseconds.count();
	return epoch_long;
}
void timer_callback(int value)
{
	game->pre_on_timer(value);
	unsigned long now = get_microseconds();

	if (value == TIMER_UPDATE)
	{
		glutTimerFunc(simulation_timestep, timer_callback, TIMER_UPDATE);
		update((now-last_update_time)/1000.0);
		last_update_time=now;
	}
	else if (value == TIMER_DRAW)
	{
		glutTimerFunc(fps_timestep, timer_callback, TIMER_DRAW);
		draw((now-last_draw_time)/1000.0);
		last_draw_time=now;
	}
}
void idle_callback()
{
	game->pre_on_idle();
}
void draw(float dtime)
{

	game->pre_draw(dtime);

	glutPostRedisplay();
}
void update(float dtime)
{
	game->pre_update(dtime);
}
void mouseentry_callback(int state)
{
	game->pre_on_mousewindowtransition(state);
}
void exit_callback()
{
	delete game;
}

}

