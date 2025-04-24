
#include "world.hpp"


World::World(): spawnPosition(50.0f, 50.0f)
{

    chunks[glm::ivec2(50, 50)] = Chunk();

}

World::~World()
{
    
}

Chunk& World::getChunkAt(glm::ivec2& position)
{
    return(chunks.at(position));
}

Chunk& World::getChunkOf(glm::ivec2& position)
{
    return(chunks.at(position)); // FIX!!!
}
