#include "Game.h" 

using namespace sf;
using namespace std;

int main() {
    //Init Game engine 
    Game game; 
    
    //Game loop 
    while (game.running() && !game.getEndGame()) { 
        //Update 
        game.update(); 

        //Render 
        game.render(); 
    } 
    
    //End of application 
    return 0;
}