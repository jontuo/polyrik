
#ifndef __ENGINE_HPP_INCLUDED__
#define __ENGINE_HPP_INCLUDED__

#include "game.hpp"



class Engine
{
public:
    Engine();
    ~Engine();

    void start();
    void stop();

private:

    Game game;


    bool run;
    unsigned long int deltaTime;

    




    void process();
    void update();

};

#endif
