
#ifndef __WORLD_HPP_INCLUDED__
#define __WORLD_HPP_INCLUDED__

#include <cstdint>
#include "entt/entity/registry.hpp"
#include <glm/glm.hpp>
#include "chunk.hpp"
#include "type.hpp"
#include <unordered_map>
#include <glm/gtx/hash.hpp>



class World
{
public:
    World();
    ~World();

    Chunk& getChunkAt(glm::ivec2& position);
    Chunk& getChunkOf(glm::ivec2& position);
    
    entt::Registry<Entity> entityRegistry;
    std::unordered_map<glm::ivec2, Chunk> chunks; // Center position!
    glm::vec2 spawnPosition;

private:



};

#endif
