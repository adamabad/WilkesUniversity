// adamplayer.h
// M. Anthony Kapolka
// Edited by: Adam Abad
// Date: Nov 22, 2019
// CS 340
// vers 1.0
// Wed Feb 25 01:30:35 EST 1998

#ifndef adamplayer_h
#define adamplayer_h

#include "board.h"
#include "player.h"

class adamplayer : public player {
	public:
		adamplayer(owner p);
		virtual void setup(ghostboard & B);
		virtual void move(ghostboard B, int & X1, int & Y1, int & X2, int & Y2);
		owner whoiam;
private:
};
#endif
