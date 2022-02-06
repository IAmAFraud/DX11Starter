#pragma once
#include "Mesh.h"
#include "Transform.h"
#include <memory>
class Entity
{
	public:
		Entity(std::shared_ptr<Mesh> _mesh);

		std::shared_ptr<Mesh> GetMesh();
		Transform* GetTransform();

	private:
		Transform transform;
		std::shared_ptr<Mesh> mesh;
};

