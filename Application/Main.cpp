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
	auto scene = neu::g_resources.Get<neu::Scene>("scenes/texture.scn");

	glm::vec3 pos = {0, 0, 0};
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

		//auto actor = scene->GetActorFromName("Light");
		//if (actor)
		//{
			// move light using sin wave 
		//	actor->m_transform.position = pos;
		//}

		auto material = neu::g_resources.Get<neu::Material>("Materials/lava.mtrl");
		if (material) 
		{
			material->uv_offset.x += neu::g_time.deltaTime / 100;
			material->uv_offset.y += neu::g_time.deltaTime / 200;
		}

		ImGui::Begin("Hello!");
		ImGui::Button("Press Me!");
		ImGui::SliderFloat3("Position", &pos[0], -5.0f, 5.0f);

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