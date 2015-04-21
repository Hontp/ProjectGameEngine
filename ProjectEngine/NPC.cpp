#include "NPC.h"


NPC::NPC(unsigned short ID){

	ID_val = ID;

}


NPC::~NPC(){



}


std::string NPC::Describe(){
	return "This is a NPC object.\n";
}