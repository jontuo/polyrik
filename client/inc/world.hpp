
#ifndef __WORLD_HPP_INCLUDED__
#define __WORLD_HPP_INCLUDED__

#include <cstdint>
#include "entt/entity/registry.hpp"
#include <unordered_map>
//#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


using EntityIdentifier = std::uint32_t;




class World
{
public:
    World();
    ~World();

    
    entt::Registry<EntityIdentifier> entityRegistry;
    std::unordered_map<EntityIdentifier, EntityIdentifier> entityMap;

    //EntityIdentifier createPolygon(unsigned int faces, float factor, float angle, glm::vec2 position);
    EntityIdentifier test();

private:



};

#endif
