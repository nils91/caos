/*
 * SampleScene.class.h
 *
 *  Created on: 13.12.2017
 *      Author: Nils
 */

#ifndef SAMPLESCENE_CLASS_H_
#define SAMPLESCENE_CLASS_H_

#include "Scene.class.h"

namespace caos
{

class SampleScene: public Scene
{
private:
	void on_reshape(GLsizei w, GLsizei h);
	void init_components(void);
		void init(void);
		void update(float dtime);
		void draw(float dtime);
public:
	SampleScene();
	virtual ~SampleScene();
};

} /* namespace caos */

#endif /* SAMPLESCENE_CLASS_H_ */
