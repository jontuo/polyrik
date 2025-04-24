/*
#include "engine.hpp"
#include <iostream>
#include "time.hpp"
#include "setting.hpp"
#include "enetpp/peer.hpp"
#include "enetpp/event.hpp"
#include "enetpp/address.hpp"
#include "protocol.hpp"
#include "component.hpp"
#include <SDL2/SDL.h>

Engine::Engine():
    window(),
    game(),
    gui()
{


    std::string entityName = "Iderik";
    std::uint32_t entityIdentifier = registry.create();
    GeneralComponent& entityGeneral = registry.assign<GeneralComponent>(entityIdentifier, entityName);
    enetpp::Peer& entityPeer = registry.attach<enetpp::Peer>(entityIdentifier, host.connect(enetpp::Address(SERVER_ADDRESS, SERVER_PORT), 2, 0));
    entityPeer.setUserData(reinterpret_cast<void*>(static_cast<std::uintptr_t>(entityIdentifier)));







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
    deltaTime = 1;
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

        render();
        draw();
    }
}

void Engine::stop()
{
    run = false;
}

void Engine::process()
{
    SDL_Event inputEvent;
    while(SDL_PollEvent(&inputEvent))
    {
        game.processInput(inputEvent);

        if(inputEvent.type == SDL_QUIT)
        {
            stop();
            break;
        }
    }

    game.processNetwork();

    gui.process();
}

void Engine::update()
{
    game.update();
    gui.update();
}

void Engine::render()
{
    game.render();
    gui.render();
}

void Engine::draw()
{
    window.clear();
    game.draw();
    gui.draw();
    window.swap();
}

*/