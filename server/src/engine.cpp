
#include "engine.hpp"
#include <iostream>
#include "time.hpp"
#include "setting.hpp"
#include "enetpp/event.hpp"
#include "component.hpp"
#include "protocol.hpp"

Engine::Engine():
    game()
{




    run = true;
}




Engine::~Engine()
{
}

void Engine::start()
{   
    unsigned long int stepTime = 33333;
    unsigned long int realTime = 0;
    unsigned long int lastTime = Time::getMicro();
    deltaTime = 0;
    unsigned long int bufferTime = 0; // Time
    unsigned long int elapsedTime = 0;

    while(run == true)
    {
        realTime = Time::getMicro();
        deltaTime = realTime - lastTime;
        lastTime = realTime;
        bufferTime = bufferTime + deltaTime;
        elapsedTime = elapsedTime + deltaTime;

        process();
        
        while(bufferTime > stepTime)
        {
            update();
            
            bufferTime = bufferTime - stepTime;
        }

        //render();
        //draw();


        if(elapsedTime > (10 * 1000000))
        {
            run = false;
        }
    }
}

void Engine::stop()
{
    run = false;
}

void Engine::process()
{
    game.process();
}

void Engine::update()
{
    game.update();
}

