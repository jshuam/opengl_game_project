#pragma once

#include "../gl/drawables/Texture.hpp"
#include "../interfaces/IRenderer.hpp"

namespace std
{
template <>
struct hash<Texture>
{
    size_t operator()(const Texture& texture) const
    {
        std::hash<unsigned int> hasher;
        auto hashTextureId = hasher(texture.getGlObjectId());

        hashTextureId ^= 0x9e3779b9 + (hashTextureId << 6) + (hashTextureId >> 2);
        return hashTextureId;
    }
};
} // namespace std

class BatchRenderer : public IRenderer
{
public:
    BatchRenderer() = default;

    virtual void render() override;
    void addBatch(Texture batchKey, std::vector<uuid_t> batch);

private:
    std::unordered_map<Texture, std::vector<uuid_t>> m_batches;

    float passedTime = 0;
    int index = 0;
    static constexpr float spriteWidths[6] = { 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f };
};
