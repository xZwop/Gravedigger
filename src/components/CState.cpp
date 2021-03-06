#include "CState.hpp"


CState::CState(GameObject* _parent,
	       const sf::Int32 _moduloTime): CComponent(_parent) {
  moduloTime = _moduloTime;
}

std::string CState::getState() {
  return state;
}

sf::Int32 CState::getElapsedSum() {
  return elapsedSum;
}

sf::Int32 CState::getModuloTime() {
  return moduloTime;
}

void CState::setState(const std::string _state) {
  state = _state;
  AAnimation * animation = getAnimation(state);
  setModuloTime(animation->getModuloTime());
  setElapsedSum(sf::Int32(0));
}

AAnimation * CState::getAnimation(const std::string name) {
  std::map<std::string, AAnimation *>::iterator it;
  it = animations.find(name);
  if ( it !=  animations.end() ) {
    return it->second;
  } else {
    return NULL;
  }
}

void CState::delAnimation(const std::string name) {
  std::map<std::string, AAnimation *>::iterator it = animations.find(name);
  if ( it != animations.end() ) {
    animations.erase(it);
  } // else nothing, considered as delete                             
}

void CState::addAnimation(const std::string name, AAnimation * animation) {
  animations[name] = animation;
}

void CState::setElapsedSum(const sf::Int32 _elapsedSum) {
  elapsedSum = _elapsedSum;
}

void CState::setModuloTime(const sf::Int32 _moduloTime) {
  moduloTime = _moduloTime;
}

void CState::update(sf::Int32 elapsed) {
  // increment time, call the current state
  setElapsedSum( elapsed + getElapsedSum() );
  getAnimation(getState())->execute(getElapsedSum());
}
