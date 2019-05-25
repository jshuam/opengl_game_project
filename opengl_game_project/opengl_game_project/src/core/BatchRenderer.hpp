#pragma once

#include "..\interfaces\IRenderer.hpp"
#include "..\gl\drawables\Texture.hpp"

namespace std
{
	template <> struct hash<Texture>
	{
		size_t operator()(const Texture& texture) const
		{
			std::hash<unsigned int> hasher;
			auto hashTextureId = hasher(texture.getGlObjectId());

			hashTextureId ^= 0x9e3779b9 + (hashTextureId << 6) + (hashTextureId >> 2);
			return hashTextureId;
		}
	};
}

class BatchRenderer : public IRenderer
{
public:
	BatchRenderer() = default;

	virtual void render() override;
	void addBatch(Texture batchKey, std::vector<GUID> batch);

private:
	std::unordered_map<Texture, std::vector<GUID>> m_batches;

	float passedTime = 0;
	int index = 0;
	static constexpr float spriteWidths[4] = {1.0f, 2.0f, 3.0f, 4.0f};
};
