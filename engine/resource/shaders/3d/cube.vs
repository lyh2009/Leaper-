#version 450 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in float a_TexIndex;
layout(location = 4) in vec3 a_Normal;
layout(location = 5) in int a_EntityID;

out vec3 v_Position;
out vec4 v_Color;
out vec2 v_TexCoord;
out flat float v_TexIndex;
out flat int v_EntityID;
out vec3 v_Normal;

uniform mat4 u_ViewProjection;

void main() {
  v_Normal = a_Normal;

  v_Position = a_Position;
  v_TexCoord = a_TexCoord;
  v_Color = a_Color;
  v_TexIndex = a_TexIndex;
  v_EntityID = a_EntityID;

  gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}