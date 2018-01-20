/*
 * Color.class.cpp
 *
 *  Created on: 10.12.2017
 *      Author: Nils
 */
#include "Color.class.h"

namespace caos
{
  Color::Color (unsigned int r, unsigned int g, unsigned int b)
  {
    this->r = r;
    this->g = g;
    this->b = b;
  }

  void
  Color::set_r (unsigned int r)
  {
    this->r = r;
  }
  unsigned int
  Color::get_r ()
  {
    return r;
  }
  void
  Color::set_g (unsigned int g)
  {
    this->g = g;
  }
  unsigned int
  Color::get_g ()
  {
    return g;
  }
  void
  Color::set_b (unsigned int b)
  {
    this->b = b;
  }
  unsigned int
  Color::get_b ()
  {
    return b;
  }
}

