/*
#ifndef __COMPONENT_HPP_INCLUDED__
#define __COMPONENT_HPP_INCLUDED__

#include <string>

#include "shape.hpp"

#include <glm/glm.hpp> // TMP?
#include <glm/gtc/matrix_transform.hpp> // TMP?
#include <glm/ext.hpp> // TMP?
#include "glpp/shader_stage.hpp"
*/


/*

    Client should not have parent or owner components.


*/


/*



enum ComponentType
{
    BODY_COMPONENT,
    SHAPE_COMPONENT
};


struct BodyComponent
{
    glm::mat4 transformation;


    void translate(glm::vec2 position)
    {
        transformation = glm::translate(transformation, glm::vec3(position, 0.0f));
    }

    void rotate(float angle, glm::vec2 offset = glm::vec2(0.0f, 0.0f))
    {
        transformation = glm::rotate(transformation, angle, glm::vec3(offset, 1.0));
        //transformation = glm::rotate(transformation, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    }

    void scale(float factor)
    {
        transformation = glm::scale(transformation, glm::vec3(factor, factor, 1.0f));
    }

    void scale(glm::vec2 factor)
    {
        transformation = glm::scale(transformation, glm::vec3(factor, 1.0f));
    }
};

enetpp::Packet& oeprator>>()




struct Vertex
{
    glm::vec2 position;

    Vertex(glm::vec2 position): position(position) {}
};

struct ShapeComponent
{
    std::vector<Vertex> vertices;


    ShapeComponent()
    {
    }

    void addVertex(Vertex vertex)
    {
        vertices.emplace_back(vertex);
    }

    void setColor() {}


};



struct TextComponent
{
    std::string text;
};







*/

/*
    FIX: Move the matrix to other component, so one component
    for physics and one for rendering. May be helping interpolation.
*/
/*
struct TransformComponent
{
    glm::vec2 position;
    // ? rotation
    glm:vec2 scale;
    glm::mat4 matrix;
};
*/











    // Triangle
    //barrelShape.vertices.push_back(glm::vec2(0.0f, -0.5f));
    //barrelShape.vertices.push_back(glm::vec2(-0.5f, 0.5f));
    //barrelShape.vertices.push_back(glm::vec2(0.5f, 0.5f));

    // Square
    //barrelShape.vertices.push_back(glm::vec2(-0.5f, -0.5f));
    //barrelShape.vertices.push_back(glm::vec2(0.0f, -0.5f));
    //barrelShape.vertices.push_back(glm::vec2(0.0f, -0.5f));
    //barrelShape.vertices.push_back(glm::vec2(0.0f, -0.5f));
    //barrelShape.vertices.push_back(glm::vec2(0.0f, -0.5f));
    //barrelShape.vertices.push_back(glm::vec2(0.0f, -0.5f));

//https://www.khronos.org/opengl/wiki/Vertex_Rendering#Primitive_Restart
//https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glMultiDrawArrays.xhtml


/*                    │19:34:59       iderik : is it possible to draw two polygons at different locations using glDrawArrays with GL_TRIANGLE_FAN or _STRIP? how do gl know when the next polygon begins?                      │ Croepha
                    │19:35:39              : drawing both polygons with only 1 glDrawArrays                                                                                                                                  │ cschield_
                    │19:36:08    mangelis_ : primitive restart                                                                                                                                                               │ Cyp_
                    │19:36:49              : https://www.khronos.org/opengl/wiki/Vertex_Rendering#Primitive_Restart                                                                                                          │ d3x0r
                    │19:37:11       iderik : mangelis_: thanks, yep i found it                                                                                                                                               │ dahlia
                    │19:40:11              : i wish to draw lots of convex polygons (triangle, rect, penta, hexa, etc). should i draw them all with the same drawing call and primitive (GL_TRIANGELS?) or seperate them? i  │ daniels
                    │                        guess 5-6 glDrawArrays each frame isnt that bad                                                                                                                                 │ DannyFritz
                    │19:43:05    mangelis_ : it's probably not bad                                                                                                                                                           │ DarkUranium
                    │19:43:17              : you can do it like, or multidrawarrays                                                                                                                                          │ dau
                    │19:43:21              : or primitive restart etc                                                                                                                                                        │ dav1d
                    │19:45:12       iderik : ill go with seperated draws, fits nicely with how i store vertices too, so i can use std::array instead of std::vector 
using Orientation = float;


struct Direction
{
    enum Bit: std::uint8_t
    {
        NONE = 0,
        NORTH = 1 << 0,
        EAST = 1 << 1,
        NORTH_EAST = 1 << 2,
        SOUTH = 1 << 3,
        SOUTH_EAST = 1 << 4,
        WEST = 1 << 5,
        SOUTH_WEST = 1 << 6,
        NORTH_WEST = 1 << 7
    };
};

struct Action
{
    enum Bit: std::uint8_t
    {
        NONE = 0,
        PRIMARY_FIRE = 1 << 0,
        SECONDARY_FIRE = 1 << 1
    };
};











struct PositionComponent
{
    float vertical;
    float horizontal;

    PositionComponent(): vertical(0), horizontal(0) {}
    PositionComponent(float vertical, float horizontal) : vertical(vertical), horizontal(horizontal) {}
};

struct RotationComponent
{
    float angle;

    RotationComponent(float angle): angle(angle) {}
};

struct Position
{
    float vertical;
    float horizontal;
};

struct CircleComponent
{
    float radius;
    std::array<Position, 6> vertices;

    CircleComponent(float radius)
    {
        setRadius(radius);
    }

    void setRadius(float radius)
    {
        this->radius = radius;

        vertices[0] = {-radius, -radius};
        vertices[1] = {radius, -radius};
        vertices[2] = {radius, radius};
        vertices[3] = {-radius, -radius};
        vertices[4] = {radius, radius};
        vertices[5] = {-radius, radius};
    }
};


struct RectangleComponent
{
    float width;
    float height;
    //borderColor;
    //bajsColor;
    std::array<RectangleVertex, 6> vertices;

    RectangleComponent(float width, float height)
    {
        setSize(width, height);
    }

    void setSize(float width, float height)
    {
        setWidth(width);
        setHeight(height);
    }

    void setWidth(float width)
    {
        this->width = width;

        vertices[0].localVertical = width / -2.0f;
        vertices[1].localVertical = width / 2.0f;
        vertices[2].localVertical = width / 2.0f;
        vertices[3].localVertical = width / -2.0f;
        vertices[4].localVertical = width / 2.0f;
        vertices[5].localVertical = width / -2.0f;
    }

    void setHeight(float height)
    {
        this->height = height;

        vertices[0].localHorizontal = height / -2.0f;
        vertices[1].localHorizontal = height / -2.0f;
        vertices[2].localHorizontal = height / 2.0f;
        vertices[3].localHorizontal = height / -2.0f;
        vertices[4].localHorizontal = height / 2.0f;
        vertices[5].localHorizontal = height / 2.0f;
    }
};

struct InteractCompoent
{
    Direction direction;
    Orientation orientation;
    Action action;
};

struct ParentComponent
{
    std::uint32_t entityIdentifier;

    ParentComponent(std::uint32_t entityIdentifier): entityIdentifier(entityIdentifier) {}
};






glm::vec2 bajsPosition = parentMatrix * parentVertices[0];


glm::vec2 kissPosition = parentMatrix * childMatrix * childVertices[0];






std::string name;
std::array<float, 3> borderColor;


struct Tra
{
    glm::mat4 transform;

    void translate(glm::vec2 translation)
    {

    }

    void rotate()
};





struct Circle
{

};

struct Polygon
{

};


struct Camera
{

};




















struct Shape
{

};






*/











/*

struct AaaComponent
{
    float a;
    float c;
    float d;
};

enetpp::Packet& operator >>(enetpp::Packet& packet, AaaComponent& aaaComponent)
{
    packet >> aaaComponent.a >> aaaComponent.c;

    return(packet);
}





struct GeneralComponent
{
    std::string name;

    GeneralComponent(std::string name): name(name) {}
};





struct PositionComponent
{
    float vertical;
    float horizontal;
};

struct RotationComponent
{
    float angle;
};

struct CircleComponent
{
    float radius;
};*/

//#endif
