
#ifndef __SHAPE_HPP_INCLUDED__
#define __SHAPE_HPP_INCLUDED__

#include <string>
#include <array>
#include <glm/glm.hpp> // TMP?
#include <glm/gtc/matrix_transform.hpp> // TMP?
#include <glm/ext.hpp> // TMP?
#include "glpp/shader_stage.hpp"





const std::array<glm::vec2, 3> Triangle = 
    {
        glm::vec2(0.0f, -0.5f),
        glm::vec2(-0.5f, 0.5f),
        glm::vec2(0.5f, 0.5f)
    };

const std::array<glm::vec2, 4> Rectangle =
    {
        glm::vec2(-0.5f, 0.5f),
        glm::vec2(-0.5f, -0.5f),
        glm::vec2(0.5f, -0.5f),
        glm::vec2(0.5f, 0.5f)
    };



struct PolygonShaderStage
{
    static std::string VERTEX;
    static std::string FRAGMENT;
};




/*
    FIX: Add "const" to VERTEX and FRAGMANT, also for RectangleShaderStage.
*/
struct CircleShaderStage
{
    static std::string VERTEX;
    static std::string FRAGMENT;
};





struct RectangleShaderStage
{
    static std::string VERTEX;
    static std::string FRAGMENT;
};



#endif
