#include "ALeft.hpp"

ALeft::ALeft(Character * _parent,
	     const sf::Int32 _moduloTime) : AAnimation(_parent,_moduloTime) {
}

void ALeft::execute(const sf::Int32 elapsed) {
  // TODO: Verif' they are existing components
  // #1 get all components
  CSpeed * speed;
  speed = (CSpeed *) parent->getComponent("Speed");
  CAcceleration * acceleration;
  acceleration = (CAcceleration *) parent->getComponent("Acceleration");
  CPosition * position;
  position = (CPosition *) parent->getComponent("Position");

  if (speed->getHSpeed() > 1.2) {
    // #2a go back to 0
    speed->setHSpeed((speed->getHSpeed())-((float)(speed->getHSpeed())/8.0));
    position->setX((position->getX())+(speed->getHSpeed()));
  } else {
    // #2b increase speed
    speed->setHSpeed((speed->getHSpeed())-(acceleration->getHAcceleration()));
    position->setX((position->getX())+(speed->getHSpeed()));
  }  
  // #3 change sprites TODO
  // example : if elapsed > modulotime/2 then ...
}
