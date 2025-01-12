#pragma once

#include "../buffers.h"
#include "../shader.h"
#include "../vertex_array.h"
#include "assimp/material.h"
#include "core/base.h"
#include "function/render/texture.h"
#include "function/render/uniform_buffer.h"
#include <cstdint>
#include <vector>

namespace Leaper
{
    enum class TextureType
    {
        Diffuse  = 0,
        Specular = 1,
        Normals  = 2,
    };

    class Mesh
    {
    public:
        struct MeshVertex
        {
            glm::vec3 position;
            glm::vec3 normal;
            glm::vec2 texcoord;
        };

        struct MeshTexture
        {
            Leaper::Ref<Texture> texture = nullptr;
            std::string path;
            TextureType type;
        };

        Mesh(std::vector<MeshVertex> vertices, std::vector<uint32_t> indices, std::vector<MeshTexture> textures);
        void Render(glm::mat4& trans, Ref<Shader> shader, int entity_id = -1);

    private:
        void Init();

        std::vector<MeshVertex> m_verteices;
        std::vector<uint32_t> m_indices;
        std::vector<MeshTexture> m_textures;
        Leaper::Ref<VertexBuffer> m_vertex_buffer;
        Leaper::Ref<VertexArray> m_vertex_array;
        Leaper::Ref<IndexBuffer> m_index_buffer;
        Leaper::Ref<Shader> m_shader;
        // Ref<UniformBuffer> m_uniform_buffer;
        Ref<Texture> m_white_texture;
    };
}  // namespace Leaper