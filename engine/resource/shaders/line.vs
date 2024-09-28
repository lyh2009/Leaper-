#version 330 core

layout(location = 0) in vec3  a_Position;
layout(location = 1) in vec4  a_Color   ;
layout(location = 2) in int   a_EntityID;

out vec4 v_Color;
out flat int v_EntityID;


layout(std140, binding = 0) uniform Camera
{
	mat4 u_ViewProjection;
};

void main()
{
    v_Color = a_Color;
    v_EntityID = a_EntityID;

    gl_Position = u_ViewProjection * vec4(a_Position, 1.0f);
}