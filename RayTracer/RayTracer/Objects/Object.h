#pragma once
#include "../Math/Ray.h" 
#include "../Renderer/Material.h" 
#include <memory> 

class Material;

class Object
{
public:
	Object() = default;
	Object(std::unique_ptr<Material> material) : m_material{ std::move(material) } {}
		//<initialize m_material with material, use std::move to transfer
		//ownership of the material unique pointer to m_material>{}

	virtual bool Hit(const Ray& ray, float min, float max, RaycastHit& hit) = 0;

	const Material* material() { return m_material.get(); }

protected:
	std::unique_ptr<Material> m_material;
};