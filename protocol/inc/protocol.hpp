
#ifndef __PROTOCOL_HPP_INCLUDED__
#define __PROTOCOL_HPP_INCLUDED__

#include <cstdint>
#include "enetpp/packet.hpp"




/*
    From client to server:

    REGISTER    - Register an account.
    AUTHORIZE


    
    COMMAND
    MOVE
    SPIN
    FIRE
    
    From server to client:


    

    SPAWN
    DESPAWN
    ATTACH
    DETACH
    MESSAGE
    POSITION
    ROTATION
    

*/



enum ChannelType: std::uint8_t
{
    DEFAULT_CHANNEL,
    STEP_CHANNEL
};


enum PacketType: std::uint8_t
{
    SIGN_PACKET,
    CREATE_PACKET,
    DESTROY_PACKET,
    ATTACH_PACKET,
    DETACH_PACKET
};

enum ShapeType: std::uint8_t
{
    TRIANGLE_SHAPE,
    RECTANGLE_SHAPE
};





// Move these to component.hpp
/*enetpp::Packet& operator <<(enetpp::Packet& packet, const TestComponent& testComponent)
{
    return(packet << testComponent.radius << testComponent.health);
}

enetpp::Packet& operator >>(enetpp::Packet& packet, TestComponent& testComponent)
{
    std::uint8_t type;
    return(packet >> testComponent.radius >> testComponent.health);
}*/




// Not sure how this is supposed to be designed yet.

















#endif
