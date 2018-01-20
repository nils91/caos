/*
 * Color.class.h
 *
 *  Created on: 10.12.2017
 *      Author: Nils
 */

#ifndef COLOR_CLASS_H_
#define COLOR_CLASS_H_

namespace caos
{
  class Color
  {
  private:
    unsigned int r, g, b;
  public:
    Color (unsigned int r, unsigned int g, unsigned int b);
    void
    set_r (unsigned int r);
    unsigned int
    get_r (void);
    void
    set_g (unsigned int g);
    unsigned int
    get_g (void);
    void
    set_b (unsigned int b);
    unsigned int
    get_b (void);
  };
}

#endif /* COLOR_CLASS_H_ */
