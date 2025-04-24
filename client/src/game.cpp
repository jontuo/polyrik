
#include "game.hpp"

Game::Game()
{

}

Game::~Game()
{

}

void Game::start()
{
    
}

/*
#define GLM_FORCE_RADIANS

#include "game.hpp"
#include "setting.hpp"
#include "enetpp/peer.hpp"
#include <iostream>
#include "enetpp/event.hpp"
#include "enetpp/packet.hpp"
#include "protocol.hpp"

#include <glm/glm.hpp> // TMP?
#include <glm/gtc/matrix_transform.hpp> // TMP?
#include <glm/ext.hpp> // TMP?
#include "glpp/shader_stage.hpp"
#include "component.hpp" // TMP

const float PI = glm::pi<float>();
const float HALF_PI = glm::half_pi<float>();
const float QUARTER_PI = glm::quarter_pi<float>();



Game::Game():
    vertexBuffer(GL_ARRAY_BUFFER, GL_DYNAMIC_DRAW),
    vertexArray(),
    shaderProgram(),
    viewMatrixUniform(),
    projectionMatrixUniform(),
    enet(),
    host(PEER_LIMIT, CHANNEL_LIMIT, INCOMING_BANDWIDTH_LIMIT, OUTGOING_BANDWIDTH_LIMIT),
    world()
{

    projectionMatrix = glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, -1.0f, 1.0f);
    projectionMatrix = projectionMatrix;
    //viewMatrix = glm::translate(viewMatrix, glm::vec3(110.0f, 110.0f, 0.0f));
    //viewMatrix = glm::scale(viewMatrix, glm::vec3(2.0f, 2.0f, 1.0f));

    ShaderStage vertexShaderStage(GL_VERTEX_SHADER);
    vertexShaderStage.setSource(PolygonShaderStage::VERTEX);
    vertexShaderStage.compile();
    shaderProgram.attachStage(vertexShaderStage.getHandle());
    ShaderStage fragmentShaderStage(GL_FRAGMENT_SHADER);
    fragmentShaderStage.setSource(PolygonShaderStage::FRAGMENT);
    fragmentShaderStage.compile();
    shaderProgram.attachStage(fragmentShaderStage.getHandle());
    shaderProgram.link();

    viewMatrixUniform.setLocation(shaderProgram.getHandle(), "viewMatrix");
    projectionMatrixUniform.setLocation(shaderProgram.getHandle(), "projectionMatrix");
    shaderProgram.bind();
    viewMatrixUniform.setData(glm::value_ptr(viewMatrix));
    projectionMatrixUniform.setData(glm::value_ptr(projectionMatrix));
    shaderProgram.unbind();

    vertexBuffer.bind();
    vertexBuffer.setData(nullptr, 0);
    vertexBuffer.unbind();

    vertexArray.bind();
    vertexBuffer.bind();
    vertexArray.enableAttribute(0);
    vertexArray.setFloatingAttribute(0, 2, GL_FLOAT, false, sizeof(Vertex), (void*)(0));
    //vertexArray.enableAttribute(1);
    //vertexArray.setFloatingAttribute(1, 3, GL_UNSIGNED_BYTE, true, sizeof(Vertex), (void*)(sizeof(float) * 2));
    vertexBuffer.unbind();
    vertexArray.unbind();



    world.entityRegistry.prepare<Body, Shape>();
    vertices.reserve(10000);





    //world.test();





    GLenum err = glGetError();
    if(err != GL_NO_ERROR)
    {
        std::cout << "gL ERROR" << std::endl;
    }


}

Game::~Game()
{
}

void Game::processInput(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.scancode == SDL_SCANCODE_W)
        {
            //viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 10.0f, 0.0f));
        }
        if(event.key.keysym.scancode == SDL_SCANCODE_S)
        {
            //viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, -10.0f, 0.0f));
        }
        if(event.key.keysym.scancode == SDL_SCANCODE_A)
        {
            //viewMatrix = glm::translate(viewMatrix, glm::vec3(10.0f, 0.0f, 0.0f));
        }
        if(event.key.keysym.scancode == SDL_SCANCODE_D)
        {
            //viewMatrix = glm::translate(viewMatrix, glm::vec3(-10.0f, 0.0f, 0.0f));
        }
        if(event.key.keysym.scancode == SDL_SCANCODE_F1)
        {

            EntityIdentifier entityIdentifier = world.entityRegistry.create();
            enetpp::Peer& entityPeer = world.entityRegistry.attach<enetpp::Peer>(entityIdentifier, host.connect(enetpp::Address(SERVER_HOST, SERVER_PORT), CHANNEL_LIMIT, 0));
            //entityPeer.setUserData(reinterpret_cast<void*>(static_cast<std::uintptr_t>(entityIdentifier)));

            //std::cout << " 0: CONNECTING" << std::endl;
        }
        if(event.key.keysym.scancode == SDL_SCANCODE_F2)
        {
            enetpp::Peer& entityPeer = world.entityRegistry.get<enetpp::Peer>();
            std::uint8_t authorizeType = AUTHOR_PACKET;
            enetpp::Packet authorizePacket(&authorizeType, sizeof(authorizeType), ENET_PACKET_FLAG_RELIABLE);
            std::string entityName = "Iderik";
            authorizePacket << entityName;
            entityPeer.quePacket(DEFAULT_CHANNEL, authorizePacket);

            std::cout << " 0: AUTHORIZING   as " << entityName  << std::endl;
        }
        if(event.key.keysym.scancode == SDL_SCANCODE_F4)
        {
            enetpp::Peer& peer = world.entityRegistry.get<enetpp::Peer>();
            std::uint8_t packetType = STOP_PACKET;
            enetpp::Packet packet(&packetType, sizeof(packetType), ENET_PACKET_FLAG_RELIABLE);
            peer.quePacket(DEFAULT_CHANNEL, packet);
            peer.disconnect(0);
            std::cout << " 0: DISCONNECTING" << std::endl;
        }
    }
}

void Game::processNetwork()
{
    enetpp::Event event;
    while(host.service(event) == true)
    {
        switch(event.getType())
        {
            case ENET_EVENT_TYPE_CONNECT:
            {
                std::cout << " 0: CONNECTED" << std::endl;
                break;
            }
            case ENET_EVENT_TYPE_RECEIVE:
            {
                enetpp::Packet packet = event.getPacket();

                std::uint8_t packetType;
                packet >> packetType;
                switch(packetType)
                {
                    case CREATE_PACKET:
                    {
                        
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
                std::cout << " 0: DISCONNECTED" << std::endl;
                break;
            }
            case ENET_EVENT_TYPE_NONE:
            {
                break;
            }
        }
    }
}

void Game::update()
{

}

void Game::render()
{
    //GLint first[2] = {0, 3};
    //GLsizei count[2] = {3, 5};

    vertices.clear();
    verticesCount.clear();
    verticesOffset.clear();
    GLint verticesCurrentOffset = 0;


    auto entities = world.entityRegistry.persistent<Body, Shape>();
    for(auto entity: entities)
    {
        Body& body = entities.get<Body>(entity);
        Shape& shape = entities.get<Shape>(entity);

        for(const Vertex& vertex: shape.vertices)
        {
            glm::vec4 a = body.transformation * glm::vec4(vertex.position, 0.0f, 1.0f);
            vertices.push_back(Vertex(glm::vec2(a)));

        }

        verticesOffset.push_back(verticesCurrentOffset);
        verticesCurrentOffset += shape.vertices.size();
        verticesCount.push_back(shape.vertices.size());
    }

    vertexBuffer.bind();
    vertexBuffer.setData(&vertices[0], vertices.size() * sizeof(Vertex));
    vertexBuffer.unbind();

}

void Game::draw()
{

    vertexArray.bind();
    shaderProgram.bind();

    glMultiDrawArrays(GL_TRIANGLE_FAN, verticesOffset.data(), verticesCount.data(), verticesOffset.size());
    
    shaderProgram.unbind();
    vertexArray.unbind();

}
*/