
#ifndef __COMPONENT_HPP_INCLUDED__
#define __COMPONENT_HPP_INCLUDED__

#include <cstdint>
#include <string>

#include "enetpp/packet.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "protocol.hpp"
#include "chunk.hpp"


enum ComponentType: std::uint8_t
{
    TRANSFORM_COMPONENT,
    SHAPE_COMPONENT
};


struct SignComponent
{
    std::string name;
    std::string pass;
};

struct GeneralComponent
{
    std::string name;
    float viewScaling;
    glm::ivec2 chunkPosition;
};

struct NetworkComponent
{
    enetpp::Peer peer;

    NetworkComponent(enetpp::Peer peer): peer(peer) {}
};

struct TransformComponent
{
    glm::vec2 position;
    float rotation;
    glm::vec2 scaling;
};

struct ShapeComponent
{
    ShapeType type;
};




/*
struct GeneralComponent
{
    std::string name;

    GeneralComponent(std::string name): name(name) {}
};

struct PositionComponent
{
    float vertical;
    float horizontal;

    PositionComponent(): vertical(0), horizontal(0) {}
    PositionComponent(float vertical, float horizontal) : vertical(vertical), horizontal(horizontal) {}
}

struct RotationComponent
{
    float angle;

    RotationComponent(float angle): angle(angle) {}
}

struct VelocityComponent
{
    float vertical;
    float horizontal;

    VelocityComponent(): vertical(0), horizontal(0) {}
    VelocityComponent(float vertical, float horizontal) : vertical(vertical), horizontal(horizontal) {}
}

struct CircleComponent
{
    float radius;

    CircleComponent(float radius): radius(radius) {}
};

struct RectangleComponent
{
    float width;
    float height;

    RectangleComponent(float width, float height): width(width), height(height) {}
};
*/


/*
struct Author
{
    std::string name;
    std::string key;
    std::uint8_t tries;

    Author(): name() {}
};

struct Position
{
    glm::vec2 position;

    Position(): position() {}
    Position(float x, float y): position(x, y) {}
    Position(glm::vec2 position): position(position) {}
};

struct Rotation
{
    float angle;

    Rotation(): angle(0.0f) {}
    Rotation(float angle): angle(angle) {}
};

struct Velocity
{
    glm::vec2 velocity;

    Velocity(): velocity() {}
    Velocity(float x, float y): velocity(x, y) {}
    Velocity(glm::vec2 velocity): velocity(velocity) {}
};

struct Shape
{
    ShapeType type;
    float size;

    Shape(ShapeType type, float size): type(type), size(size) {}
};

struct Parent
{

};

struct Owner
{

};

struct Text
{

};

*/



/*

struct BbbComponent
{
    float a;
    float b;
    float c;
};

enetpp::Packet& operator <<(enetpp::Packet& packet, const BbbComponent& bbbComponent)
{
    packet << bbbComponent.a << bbbComponent.c;

    return(packet);
}





struct NameComponent
{
    std::string name;
};

*/

/*
namespace Component
{


    struct Type
    {
        enum B: std::uint8_t
        {
            NONE = 0,
            POSITION = 1 << 0,
            ROTATION = 1 << 1,
            VELOCITY = 1 << 2,
            CIRCLE = 1 << 3
        };
    };


    struct Base
    {

    };

    struct Position: Base
    {
        Position(float x, float y);

        float vertical;
        float horizontal;
    };

    struct Rotation: Base
    {
        float angle;
    };

    struct Velocity: Base
    {
        float vertical;
        float horizontal;
    };

    struct Circle: Base
    {
        float radius;
    };
};*/

#endif
