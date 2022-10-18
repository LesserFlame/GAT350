#pragma once 
#include "Resource/Resource.h" 
#include "Math/MathUtils.h" 
#include "rapidjson/rapidjson.h"
#include <vector> 
#include <memory> 

namespace neu
{
	class Texture;
	class Program;

	class Material : public Resource
	{
	public:
		virtual bool Create(std::string filename, ...) override;

		void Bind();

		std::shared_ptr<Program> GetProgram() { return m_program; }

		//bool Get(const rapidjson::Value& value, const std::string& name, glm::vec2& data);
		//bool Get(const rapidjson::Value& value, const std::string& name, glm::vec3& data);
		//bool Get(const rapidjson::Value& value, const std::string& name, glm::vec4& data);


	public:
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
		float shininess = 0;

	private:
		std::shared_ptr<Program> m_program;
		std::vector<std::shared_ptr<Texture>> m_textures;
	};
}