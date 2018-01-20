/*
 * SampleGameComponent.cpp
 *
 *  Created on: 13.12.2017
 *      Author: Nils
 */

#include "SampleGameComponent.h"

namespace caos
{

SampleGameComponent::SampleGameComponent()
{
	// TODO Auto-generated constructor stub

}

SampleGameComponent::~SampleGameComponent()
{
	// TODO Auto-generated destructor stub
}
void SampleGameComponent::init(){

}
void SampleGameComponent::update(float dtime){

}
void SampleGameComponent::draw(float dtime){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glClearColor(0, 0, 0, 0);
			glColor3f(0.5f,.5f,.5f);
			glLoadIdentity();
			glTranslatef(0.0, 0.0, -50.0);
			glRotatef(0,1,0,0);
			glutWireSphere(10, 32, 32);
}

} /* namespace caos */
