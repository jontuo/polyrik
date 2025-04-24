
#include "game.hpp"
#include <iostream>
#include "exception.hpp"
#include "enetpp/exception.hpp"

int main(int argc, char* argv[])
{
    std::cout << "START" << std::endl;

    try
    {
        Game game;
        game.start();
    }
    catch(Exception& exception)
    {
        std::cout << "FATAL a" << exception.getReason() << std::endl;
    }
    catch(enetpp::Exception& exception)
    {
        std::cout << "FATAL " << exception.getReason() << std::endl;
    }

    std::cout << "STOP" << std::endl;

    return(0);
};
