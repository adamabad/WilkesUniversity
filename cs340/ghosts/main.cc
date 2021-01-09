//example main.cc


using namespace std;

#include <iostream>
#include "randplayer.h"
#include "player.h"
#include "ghost.h"
#include "board.h"
#include "adamplayer.h"

int main()
{

  owner w;
  endcode r;
 
  randplayer * j =new randplayer(playerB);
  adamplayer * k= new adamplayer(playerA);

  // instead replace k by saying: 
  // yourrandplayer * k= new yourrandplayer(playerB);

  ghostgame G(k, j);

  return 0;
}




































