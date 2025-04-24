
#ifndef __GAME_HPP_INCLUDED__
#define __GAME_HPP_INCLUDED__


class Game
{
public:
    Game();
    ~Game();

    void start();

private:



};

#endif


/*
#ifndef __GAME_HPP_INCLUDED__
#define __GAME_HPP_INCLUDED__


#include "world.hpp"
#include "enetpp/enet.hpp"
#include "enetpp/host.hpp"
#include <SDL2/SDL.h>
#include "glpp/vertex_buffer.hpp"
#include "glpp/vertex_array.hpp"
#include "glpp/shader_program.hpp"
#include "glpp/uniform_variable.hpp"
#include <vector>
#include "shape.hpp"
#include <glm/glm.hpp> // TMP?
#include "component.hpp"

class Game
{
public:
    Game();
    ~Game();

    void processInput(SDL_Event& input);
    void processNetwork();
    void update();
    void render();
    void draw();




private:

    VertexBuffer vertexBuffer;
    VertexArray vertexArray;
    ShaderProgram shaderProgram;

    std::vector<Vertex> vertices;
    std::vector<GLint> verticesOffset;
    std::vector<GLsizei> verticesCount;

    //VertexBuffer circleVertexBuffer;
    //VertexArray circleVertexArray;
    //ShaderProgram circleShaderProgram;
    //std::vector<CircleVertex> circleVertices;

    //VertexBuffer rectangleVertexBuffer;
    //VertexArray rectangleVertexArray;
    //ShaderProgram rectangleShaderProgram;
    //std::vector<RectangleVertex> rectangleVertices;

    UniformVariable viewMatrixUniform;
    UniformVariable projectionMatrixUniform;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    



    enetpp::Enet enet;
    enetpp::Host host;
    World world;
   




};

#endif
*/