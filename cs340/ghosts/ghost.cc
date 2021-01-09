// ghost.cc
// M. Anthony Kapolka
// CS 340
// vers 1.5
// Mon Oct 19 19:48:40 EDT 2009


using namespace std;

#include <iostream>
#include "ghost.h"
#include "player.h"
#include "randplayer.h"

endcode ghostgame::wincheck(owner p, ghostboard B)
{
	// did player p win or lose?

     int good, bad;     

     B.getcapture(p, good, bad); // count of opponents's pieces captured

     if (bad == 4)	// I've gotten his 4 bad ghosts - loss for me
	return badloss;

     if (good == 4)     // I've gotten his 4 good ghosts - win for me
	return goodwin;

 // see if my opponent can win on his/her next turn.

     if (p == playerB)   // player B
        {
           // square 0,0 and square 0,5

           if ((B.getsq(0,0).getowner() == playerB)
                && (B.getsq(0,0).getcolor() == blue))
              return gotout;

           if ((B.getsq(0,5).getowner() == playerB)
                && (B.getsq(0,5).getcolor() == blue))
              return gotout;

        }
     else                // player A
        {
           // square 5,0 and square 5,5

           if ((B.getsq(5,0).getowner() == playerA)
                && (B.getsq(5,0).getcolor() == blue))
              return gotout;

           if ((B.getsq(5,5).getowner() == playerA)
                && (B.getsq(5,5).getcolor() == blue))
              return gotout;

        }


     return notoveryet;
}

ghostgame::ghostgame(player * PA, player * PB)
{
	endcode code;

	PA->setup(B);
	PB->setup(B);
	B.display();

	gameover = false;

	while (!gameover)
 	 { 
		int x1, x2, y1, y2;

		PA->move(B, x1, y1, x2, y2);  // gets move in (x1,y1) -> (x2,y2)
		
		if (B.move(x1,y1, x2,y2, playerA))
	         {	
		    B.display();

		    // did A get a piece that ends game?
		    code = wincheck(playerB, B);
		    if (code)
		     endgame(playerA, code);

		    else // B's move
		     {
                      PB->move(B, x1,y1, x2, y2); 
		      if (!(B.move(x1,y1, x2,y2, playerB)))
		        {
			   endgame(playerB, badmove);
			}
		      else
		        {  code = wincheck(playerA, B);
		           if (code) endgame(playerB, code);
			}

		     } // end else B's move
		 }
		else
		 {
		    endgame(playerA, badmove);
		 }

		B.display();

	 } // end while
}

void ghostgame::endgame(owner l, endcode reason)
{
	cout << endl;

	cout << "Player";

	if (l == playerA) cout << " A ";
	  else  cout << " B ";


	switch (reason)
	{
	  case badstart:
			   cout << "loses: bad starting board configuration.";
			   break;

	  case badmove:
			   cout << "losses: bad move requested.";
			   break;

	  case goodwin:
			   cout << "wins: captures all opponents good ghosts.";
			   break;

	  case badloss:
			   cout << "loses: captures all opponents bad ghosts.";
			   break;
	  case gotout:
			   cout << "loses: opponents good ghost will exit.";
			   break;

	}

	cout << endl;

	gameover = true; // should throw an exception, eh?
}

/*int main()
{
	player * A = new randplayer(playerA);
	player * B = new randplayer(playerB);

	ghostgame G(A,B);

} */
