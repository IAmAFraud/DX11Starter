#include "Entity.h"

/// <summary>
/// Constructor for Entity. Takes a mesh pointer and creates its own transform
/// </summary>
Entity::Entity(std::shared_ptr<Mesh> _mesh) : transform()
{
    mesh = _mesh;
}

/// <summary>
/// Returns the mesh shared pointer
/// </summary>
std::shared_ptr<Mesh> Entity::GetMesh()
{
    return mesh;
}


/// <summary>
/// Returns a pointer to this entities transform
/// </summary
Transform* Entity::GetTransform()
{
    return &transform;
}
