/*
 * SampleGameComponent.h
 *
 *  Created on: 13.12.2017
 *      Author: Nils
 */

#ifndef SAMPLEGAMECOMPONENT_H_
#define SAMPLEGAMECOMPONENT_H_

#include "GameComponent.class.h"

namespace caos
{

class SampleGameComponent: public GameComponent
{
private:
	void init(void);
		void update(float dtime);
		void draw(float dtime);
public:
	SampleGameComponent();
	virtual ~SampleGameComponent();
};

} /* namespace caos */

#endif /* SAMPLEGAMECOMPONENT_H_ */
