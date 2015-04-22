#include "Player.h"


Player::Player(unsigned short _ID){

	ID_val = _ID;

}


Player::~Player(){



}


std::string Player::Describe(){
	return "This is a player object.\n";
}