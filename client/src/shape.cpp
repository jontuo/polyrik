
#include "shape.hpp"

std::string PolygonShaderStage::VERTEX = R"(

#version 330 core

layout(location = 0) in vec2 localPosition;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main ()
{   
    gl_Position = projectionMatrix * viewMatrix * vec4(localPosition, 0.0, 1.0);
}

)";

std::string PolygonShaderStage::FRAGMENT = R"(

#version 330 core

out vec4 FragColor;

void main ()
{
    FragColor = vec4(1.0f, 0.0f, 0.2f, 1.0f);
}

)";

std::string CircleShaderStage::VERTEX = R"(

#version 330 core

layout(location = 0) in vec2 localPosition;
layout(location = 1) in vec2 worldPosition;
layout(location = 2) in float radius;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;


out vec2 screenPosition;
out float radius_;

void main ()
{   

    gl_Position = projectionMatrix * viewMatrix * vec4(worldPosition + localPosition, 0.0, 1.0);
    screenPosition = (viewMatrix * vec4(worldPosition, 0.0, 1.0)).xy;
    radius_ = radius;
}

)";

std::string CircleShaderStage::FRAGMENT = R"(

#version 330 core

layout(origin_upper_left) in vec4 gl_FragCoord;
in vec2 screenPosition;
in float radius_;

out vec4 FragColor;



void main ()
{
    if(length(gl_FragCoord.xy - (screenPosition)) > radius_)
    {
        discard;
        //FragColor = vec4(1.0f, 1.0f, 0.2f, 1.0f);
    }
    else
    {
        FragColor = vec4(1.0f, 0.0f, 0.2f, 1.0f);
    }
}

)";

std::string RectangleShaderStage::VERTEX = R"(

#version 330 core

layout(location = 0) in vec2 localPosition;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main ()
{   
    gl_Position = projectionMatrix * viewMatrix * vec4(localPosition, 0.0, 1.0);
}

)";

std::string RectangleShaderStage::FRAGMENT = R"(

#version 330 core

in vec3 color;

out vec4 FragColor;



void main ()
{
    FragColor = vec4(0.5f, 0.5f, 0.5f, 1.0f);
}

)";