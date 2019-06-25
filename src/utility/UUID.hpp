#pragma once

#include <uuid/uuid.h>

struct UUID
{
    uuid_t uuid;
    UUID() = default;
    UUID(const UUID& other) { uuid_copy(uuid, other.uuid); }
    UUID(const uuid_t other) { uuid_copy(uuid, other); }
    void generateInplace() { uuid_generate(uuid); }
    static UUID generate()
    {
        UUID uuidContainer;
        uuid_generate(uuidContainer.uuid);
        return uuidContainer;
    }
    bool operator<(const UUID& other) const { return uuid_compare(uuid, other.uuid) < 0; }
    bool operator==(const UUID& other) const { return uuid_compare(uuid, other.uuid) == 0; }
    bool operator>(const UUID& other) const { return uuid_compare(uuid, other.uuid) > 0; }
};