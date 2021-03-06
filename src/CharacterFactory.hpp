#ifndef __CHARACTERFACTORY_H__
#define __CHARACTERFACTORY_H__

#include <SFML/System.hpp>
#include <iostream>
#include <string>

#include "Character.hpp"
#include "CPosition.hpp"
#include "CSprite.hpp"
#include "CSpeed.hpp"
#include "CAcceleration.hpp"
#include "CState.hpp"

#include "AAnimation.hpp"
#include "AStand.hpp" 
#include "ALeft.hpp"
#include "ARight.hpp"

/**
 ** Factory which initialize a character and all its components.
 **/
class CharacterFactory {

private:

public:

  CharacterFactory();

  Character* get(const std::string name);

};

#endif
