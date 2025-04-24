
#include "game.hpp"
#include <iostream>
#include "setting.hpp"
#include "enetpp/address.hpp"
#include "protocol.hpp"
#include "component.hpp"
#include "type.hpp"


Game::Game():
    enet(),
    host(enetpp::Address(SERVER_HOST, SERVER_PORT), PEER_LIMIT, CHANNEL_LIMIT, INCOMING_BANDWIDTH_LIMIT, OUTGOING_BANDWIDTH_LIMIT),
    world()
{


}




Game::~Game()
{
}

/*void World::testy()
{



    EntityIdentifier aIdentifier = world.entityRegistry.create();
    TransformComponent& aTransform = world.entityRegistry.assign<TransformComponent>(aIdentifier, glm::vec2(100.0f, 100.0f));
    ShapeComponent& aShape = world.entityRegistry.assign<ShapeComponent>(aIdentifier, TRIANGLE_SHAPE);

    EntityIdentifier bIdentifier = world.entityRegistry.create();
    TransformComponent& bTransform = world.entityRegistry.assign<TransformComponent>(bIdentifier, glm::vec2(150.0f, 100.0f));
    ShapeComponent& bShape = world.entityRegistry.assign<ShapeComponent>(bIdentifier, TRIANGLE_SHAPE);

    EntityIdentifier cIdentifier = world.entityRegistry.create();
    TransformComponent& cTransform = world.entityRegistry.assign<TransformComponent>(cIdentifier, glm::vec2(200.0f, 100.0f));
    ShapeComponent& cShape = world.entityRegistry.assign<ShapeComponent>(cIdentifier, TRIANGLE_SHAPE);




}*/

void Game::process()
{
    enetpp::Event event;
    while(host.service(event) == true)
    {
        switch(event.getType())
        {
            case ENET_EVENT_TYPE_CONNECT:
            {

                Entity entity = world.entityRegistry.create();
                
                NetworkComponent& entityNetwork = world.entityRegistry.assign<NetworkComponent>(entity, event.getPeer());
                entityNetwork.peer.setUserData(reinterpret_cast<void*>(static_cast<std::uintptr_t>(entity)));

                TransformComponent& entityTransform = world.entityRegistry.assign<TransformComponent>(entity);
                entityTransform.position = glm::vec2(150.0f, 200.0f);
                entityTransform.rotation = 0.0f;
                entityTransform.scaling = glm::vec2(2.0f, 2.0f);

                ShapeComponent& entityShape = world.entityRegistry.assign<ShapeComponent>(entity);
                entityShape.type = TRIANGLE_SHAPE;
                
                // How do know which entities are newly created or updated? send to which clients?


                //std::cout << " " << entity << ": CONNECT from " << entityNetwork.peer.getAddress().getHost() << std::endl;
                break;
            }
            case ENET_EVENT_TYPE_RECEIVE:
            {
                enetpp::Peer peer = event.getPeer();
                enetpp::Packet packet = event.getPacket();

                std::uint8_t packetType;
                packet >> packetType;
                switch(packetType)
                {
                    case SIGN_PACKET:
                    {
                        Entity entity = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(peer.getUserData()));
                        SignComponent& entitySign = world.entityRegistry.assign<SignComponent>(entity);
                        packet >> entitySign.name;

                        std::cout << " " << entity << ": AUTHORIZE as " << entitySign.name << std::endl;
                        
                        break;
                    }

                    default:
                    {
                        std::cout << "unknown packet type" << std::endl;
                        break;
                    }

                }

                packet.destroy();

                break;
            }
            case ENET_EVENT_TYPE_DISCONNECT:
            {
                //enetpp::Peer peer = event.getPeer();
                //std::uint32_t entityIdentifier = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(peer.getUserData()));


                std::cout << " 0: DISCONNECTED" << std::endl;
                break;
            }
            case ENET_EVENT_TYPE_NONE:
            {
                std::cout << " EVENT UNKNOWN" << std::endl;
                break;
            }
        }
    }





    /*enetpp::Peer peer = event.getPeer();
    std::uint32_t entityIdentifier = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(peer.getUserData()));

    std::cout << " " << entityIdentifier << ": " << peer.getAddress().getHost() << "\t";

    enetpp::Packet packet = event.getPacket();
    std::uint8_t packetType;
    packet >> packetType;
    switch(packetType)
    {
        case PacketType::AUTHORIZE:
        {
            GeneralComponent& entityGeneral = registry.get<GeneralComponent>(entityIdentifier);
            packet >> entityGeneral.name;

            std::cout << "AUTHORIZE\tas " << entityGeneral.name << std::endl; 

            break;
        }
        default:
        {
            std::cout << "event packet type error" << std::endl;
            break;
        }
    }*/

}

void Game::update()
{
    /*
        Loop entities with AuthorComponent:
            Assign transform and shape components.
            Find neighbour entities and send CreatePacket to them about this new entity.

        Loop entities with InteractComponent:
            Apply actions.

        Loop entities with PhysicsComponent:
            Blablabla
            Find neighbour entities and send BajsPacket to them about this new entity's state.

        what about having another registry for auth entities?
        add position and etc components to that entity in that registry
        send packet of that entity to all visible entities in the real registry
        move that or all authed entities to the real registry
    */



    auto view = world.entityRegistry.view<SignComponent, NetworkComponent>();
    for(auto entity: view)
    {
        SignComponent& entitySign = view.get<SignComponent>(entity);
        GeneralComponent& entityGeneral = world.entityRegistry.assign<GeneralComponent>(entity);
        entityGeneral.name = entitySign.name;

        TransformComponent& entityTransform = world.entityRegistry.assign<TransformComponent>(entity);
        entityTransform.position = glm::vec2(100.0f, 100.0f);
        entityTransform.rotation = 0.0f;
        entityTransform.scaling = glm::vec2(2.0f, 2.0f);

        ShapeComponent& entityShape = world.entityRegistry.assign<ShapeComponent>(entity);
        entityShape.type = TRIANGLE_SHAPE;

        std::uint8_t packetType = CREATE_PACKET;
        // Lets try and see if the same packet can be sent multiple times and not being destroyed after the first was sent.
        // Otherwise move this part inside the inner loop and recreate it every neighbour.
        enetpp::Packet entityPacket(&packetType, sizeof(packetType), ENET_PACKET_FLAG_RELIABLE);
        entityPacket << entityTransform.position.x << entityTransform.position.y << entityShape.type;

        NetworkComponent entityNetwork = view.get<NetworkComponent>(entity);
        Chunk& chunk = world.chunks.at(glm::ivec2(50, 50));
        for(Entity neighbour: chunk.entities)
        {
            if(world.entityRegistry.has<enetpp::Peer>(neighbour) == true)
            {
                NetworkComponent& neighbourNetwork = world.entityRegistry.get<NetworkComponent>(neighbour);
                neighbourNetwork.peer.quePacket(DEFAULT_CHANNEL, entityPacket);

                // How to know which components this entity has, so it knows which components to send?
                // Store a bitfield in General with ComponentType?
                TransformComponent& entityTransform = world.entityRegistry.assign<TransformComponent>(entity);
                ShapeComponent& entityShape = world.entityRegistry.assign<ShapeComponent>(entity);
                enetpp::Packet neighbourPacket(&packetType, sizeof(packetType), ENET_PACKET_FLAG_RELIABLE);
                neighbourPacket << entityTransform.position.x << entityTransform.position.y << entityShape.type;
                entityNetwork.peer.quePacket(DEFAULT_CHANNEL, neighbourPacket);
            }
        }
        chunk.entities.push_back(entity); // insert or emplace here?

    }
    world.entityRegistry.reset<SignComponent>();


}




