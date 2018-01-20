/*
 * Sample.cpp
 *
 *  Created on: 10.12.2017
 *      Author: Nils
 */
//Includes for OpenGL
#include "SampleGame.class.h"
#include "SampleScene.class.h"

#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Game.class.h"

namespace caos
{

SampleGame::SampleGame():Game()
{


}

SampleGame::~SampleGame()
{
	for (unsigned int i = 0; i < all_scenes.size(); i++)
		{
			delete all_scenes[i];
		}
}

void SampleGame::init_scenes(){
	SampleScene *scene=new SampleScene();
	all_scenes.push_back(scene);
	active_scene=scene;
}
void SampleGame::init(){

}
void SampleGame::update(float dtime){

}
void SampleGame::draw(float dtime){

}
void SampleGame::on_reshape(GLsizei w, GLsizei h){



}
void SampleGame::on_keyboard(unsigned char key, int x, int y){

}

} /* namespace caos */
