/*
 * SampleScene.class.cpp
 *
 *  Created on: 13.12.2017
 *      Author: Nils
 */

#include "SampleScene.class.h"
#include "SampleGameComponent.h"

namespace caos
{

SampleScene::SampleScene()
{
	// TODO Auto-generated constructor stub

}

SampleScene::~SampleScene()
{
	for(unsigned int i=0;i<game_components.size();i++){
		delete game_components[i];
	}
}
void SampleScene::on_reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 200.0);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(0.0, 0.0, -50.0);
}
void SampleScene::init_components(){
	SampleGameComponent *component=new SampleGameComponent();
	add_game_component(component);
}
void SampleScene::init(){

}
void SampleScene::update(float dtime){

}
void SampleScene::draw(float dtime){

}


} /* namespace caos */
