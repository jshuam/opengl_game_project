#pragma once

#include "..\interfaces\IRenderer.hpp"

class BatchRenderer : public IRenderer
{
public:
	BatchRenderer() = default;

	void render() const;
	void addBatch(Texture batchKey, std::vector<GUID> batch);

private:
	std::unordered_map<Texture, std::vector<GUID>> m_batches;
};
