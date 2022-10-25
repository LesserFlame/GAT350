#include "Engine.h"
#include <iostream>

float vertices[] = {
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
};

int main(int argc, char** argv)
{
	LOG("Application Started...");
	neu::InitializeMemory();
	neu::SetFilePath("../Assets");

	neu::Engine::Instance().Initialize();
	neu::Engine::Instance().Register();
	LOG("Engine Initialized...");

	neu::g_renderer.CreateWindow("Neumont", 800, 600);
	LOG("Window Initialized...");

	// load scene 
	auto scene = std::make_unique<neu::Scene>();

	rapidjson::Document document;
	bool success = neu::json::Load("scenes/basic.scn", document);
	if (!success)
	{
		LOG("error loading scene file %s.", "scenes/basic.scn");
	}
	else
	{
		scene->Read(document);
		scene->Initialize();
	}

	//std::shared_ptr<neu::Material> material = neu::g_resources.Get<neu::Material>("materials/cow.mtrl");
	//material->Bind();

	//material->GetProgram()->SetUniform("scale", 0.5f);
	//glm::mat4 model{ 1 };
	//glm::mat4 projection = glm::perspective(45.0f, neu::g_renderer.GetWidth() / (float)neu::g_renderer.GetHeight(), 0.01f, 100.0f);
	//mx = glm::scale(glm::vec3{ 0.5, 0.5, 0.5 });

	//glm::vec3 cameraPosition = glm::vec3{ 0, 0, 7 };

	//std::vector<neu::Transform> transforms;
	//for (size_t i = 0; i < 100; i++)
	//{
		//transforms.push_back({ { neu::randomf(-100, 100), neu::randomf(-10, 10), neu::randomf(-10, 10)}, {neu::randomf(360), neu::randomf(360), neu::randomf(360)} });
	//}

	//auto m = neu::g_resources.Get<neu::Model>("models/spot.obj");
	//auto m = neu::g_resources.Get<neu::Model>("models/spamton.obj");

	bool quit = false;
	while (!quit)
	{
		neu::Engine::Instance().Update();
		if (neu::g_inputSystem.GetKeyState(neu::key_escape) == neu::InputSystem::KeyState::Pressed) quit = true;
		
		scene->Update();

		//if (neu::g_inputSystem.GetKeyState(neu::key_left) == neu::InputSystem::KeyState::Held) cameraPosition.x += 10 * neu::g_time.deltaTime;
		//if (neu::g_inputSystem.GetKeyState(neu::key_right) == neu::InputSystem::KeyState::Held) cameraPosition.x -= 10 * neu::g_time.deltaTime;
		//if (neu::g_inputSystem.GetKeyState(neu::key_down) == neu::InputSystem::KeyState::Held) cameraPosition.y += 10 * neu::g_time.deltaTime;
		//if (neu::g_inputSystem.GetKeyState(neu::key_up) == neu::InputSystem::KeyState::Held) cameraPosition.y -= 10 * neu::g_time.deltaTime;


		 
		//glm::mat4 view = glm::lookAt(cameraPosition, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 });
		//glm::mat4 view = glm::lookAt(cameraPosition, cameraPosition + glm::vec3{ 0, 0, -1 }, glm::vec3{ 0, 1, 0 });
		//material->GetProgram()->SetUniform("scale", std::sin(neu::g_time.time * 3));
		//model = glm::eulerAngleXYZ(neu::g_time.time, neu::g_time.time, neu::g_time.time);


		neu::g_renderer.BeginFrame();

		scene->Draw(neu::g_renderer);

		//glm::mat4 mvp = projection * view * model;
		//material->GetProgram()->SetUniform("mvp", mvp);

		//m->m_vertexBuffer.Draw();
		/*for (size_t i = 0; i < transforms.size(); i++)
		{
			transforms[i].rotation += glm::vec3{ 0, 90 * neu::g_time.deltaTime, 0 };
			glm::mat4 mvp = projection * view * (glm::mat4)transforms[i];
			material->GetProgram()->SetUniform("mvp", mvp);
			vb->Draw();
		}

		vb->Draw();*/

		neu::g_renderer.EndFrame();
	}

	scene->RemoveAll();

	neu::Engine::Instance().Shutdown();

	return 0;
}