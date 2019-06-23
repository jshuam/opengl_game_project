#pragma once

#include "../GLDrawable.hpp"

class VertexBuffer : public GLDrawable
{
public:
    VertexBuffer(unsigned int dataSize, const void* data, int size, unsigned int type, bool normalized, unsigned int drawFlag);

    virtual void bind() const override;
    virtual void unbind() const override;

    void attribPointer(unsigned int index) const;
    void modifyBuffer(unsigned int dataSize, const void* data) const;

private:
    int m_size;
    unsigned int m_type;
    bool m_normalized;
};
