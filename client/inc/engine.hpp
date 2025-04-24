/*
#ifndef __ENGINE_HPP_INCLUDED__
#define __ENGINE_HPP_INCLUDED__

#include "game.hpp"
#include "gui.hpp"
#include "window.hpp"


class Engine
{
public:
    Engine();
    ~Engine();

    void start();
    void stop();

private:

    Window window;
    Game game;
    Gui gui;



    bool run;
    unsigned long int deltaTime;

    




    void process();
    void update();
    void render();
    void draw();


};

#endif
*/