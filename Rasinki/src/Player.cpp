#include "Player.h"

Player::Player(ControlType type) {
	mControlType = type;
	mScore = 99; //Debug purposes
  mGold = 100; //Debug purposes
	mLives = 10;
	deltaScore = 0;
	clientInput = NULL;
}
void Player::scored(int points) {
	mScore += points;
	deltaScore += points;
	std::cout << "Player score: " << mScore << std::endl;
}
bool Player::IsKeyDown(OIS::KeyCode key) {
	if (mControlType == LOCAL)
		return Input::IsKeyDown(key);
	if (clientInput == NULL)
		return false;
	// clientInput->print();
	switch (key) {
		case OIS::KC_W:
			return clientInput->isKeyDownW;
		case OIS::KC_A:
			return clientInput->isKeyDownA;
		case OIS::KC_S:
			return clientInput->isKeyDownS;
		case OIS::KC_D:
			return clientInput->isKeyDownD;
	}
	return false;
}
void Player::loseHealth(){
	mLives--;
	std::cout<< "Player lost a life, current lives: " << mLives <<std::endl;
}
