
#include "world.hpp"
#include "component.hpp"
#include <iostream>

World::World()
{

}

World::~World()
{
    
}

/*
EntityIdentifier World::test()
{
    EntityIdentifier identifier = entityRegistry.create();

    Body& body = entityRegistry.assign<Body>(identifier);
    body.translate(glm::vec2(100.0f, 100.0f));
    body.rotate(0.0f);
    body.scale(20.0f);

    Shape& shape = entityRegistry.assign<Shape>(identifier);
    shape.addVertex(Vertex(glm::vec2(-0.2f, 0.5f)));
    shape.addVertex(Vertex(glm::vec2(-0.25f, -0.5f)));
    shape.addVertex(Vertex(glm::vec2(0.25f, -0.5f)));
    shape.addVertex(Vertex(glm::vec2(0.2f, 0.5f)));



    return(identifier);
}*/



