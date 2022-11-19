#include "Engine.h"
#include <iostream>

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
	neu::g_gui.Initialize(neu::g_renderer);

	// load scene 
	auto scene = neu::g_resources.Get<neu::Scene>("scenes/cubemap.scn");

	glm::vec3 rot = {0, 0, 0};
	float ri = 1;
	float interpolation = 0.5f;
	bool quit = false;
	while (!quit)
	{
		neu::Engine::Instance().Update();
		neu::g_gui.BeginFrame(neu::g_renderer);
		if (neu::g_inputSystem.GetKeyState(neu::key_escape) == neu::InputSystem::KeyState::Pressed) quit = true;
		

		//auto actor = scene->GetActorFromName("Ogre");
		//if (actor)
		//{
			//actor->m_transform.rotation.x += neu::g_time.deltaTime * 90.0f;
			//actor->m_transform.rotation.y += neu::g_time.deltaTime * 90.0f;
			//actor->m_transform.rotation.z += neu::g_time.deltaTime * 90.0f;
		//}

		auto actor = scene->GetActorFromName("Skeleton");
		if (actor)
		{
			actor->m_transform.rotation = math::EulerToQuaternion(rot);
		}

		//auto actor = scene->GetActorFromName("Light");
		//if (actor)
		//{
		//	// move light using sin wave 
		//	//actor->m_transform.position = pos;
		//}

		auto material = neu::g_resources.Get<neu::Material>("Materials/lava.mtrl");
		if (material) 
		{
			material->uv_offset.x += neu::g_time.deltaTime / 100;
			material->uv_offset.y += neu::g_time.deltaTime / 200;
		}

		auto program = neu::g_resources.Get<neu::Program>("shaders/fx/reflection_refraction.prog");
		if (program)
		{
			program->Use();
			program->SetUniform("interpolation", interpolation);
			program->SetUniform("ri", ri);
		}

		ImGui::Begin("Transform!");
		ImGui::DragFloat3("Rotation", &rot[0]);
		ImGui::DragFloat("Refraction", &ri, 0.01f, 1, 3);
		ImGui::DragFloat("Interpolation", &interpolation, 0.01f, 0, 1);

		ImGui::End();

		scene->Update();

		neu::g_renderer.BeginFrame();

		scene->PreRender(neu::g_renderer);
		scene->Render(neu::g_renderer);

		//scene->Draw(neu::g_renderer);
		neu::g_gui.Draw();

		neu::g_renderer.EndFrame();
		neu::g_gui.EndFrame();
	}

	scene->RemoveAll();

	neu::Engine::Instance().Shutdown();

	return 0;
}