// ghost.h - this *plays* the game.
// M. Anthony Kapolka
// CS 340
// vers 1.0
// Wed Feb 25 01:30:35 EST 1998

#ifndef ghost_h
#define ghost_h

#include "board.h"
#include "player.h"

enum endcode { notoveryet, badstart, badmove, goodwin, badloss, gotout };

class ghostgame 
{

	public:

		ghostgame();
		ghostgame(player * PA, player * PB);

	private:

	  void    endgame(owner, endcode);

	  endcode wincheck(owner, ghostboard);

	ghostboard B;

	bool	gameover;	// should throw exceptions, eh?


};  // end ghostgame

#endif
