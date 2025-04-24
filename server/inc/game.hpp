
#ifndef __GAME_HPP_INCLUDED__
#define __GAME_HPP_INCLUDED__

#include "world.hpp"
#include "enetpp/enet.hpp"
#include "enetpp/host.hpp"



class Game
{
public:
    Game();
    ~Game();


    void process();
    void update();
    
private:

    enetpp::Enet enet;
    enetpp::Host host;
    World world;   



};

#endif
