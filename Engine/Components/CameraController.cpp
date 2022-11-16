#include "CameraController.h" 
#include "Engine.h" 

namespace neu
{
	void CameraController::Update()
	{
		// update transform 

		if (g_inputSystem.GetKeyState(key_a) == InputSystem::KeyState::Held)
			m_owner->m_transform.position.x -= speed * g_time.deltaTime;
		if (g_inputSystem.GetKeyState(key_d) == InputSystem::KeyState::Held)
			m_owner->m_transform.position.x += speed * g_time.deltaTime;

		if (g_inputSystem.GetKeyState(key_w) == InputSystem::KeyState::Held)
			m_owner->m_transform.position.y += speed * g_time.deltaTime;
		if (g_inputSystem.GetKeyState(key_s) == InputSystem::KeyState::Held)
			m_owner->m_transform.position.y -= speed * g_time.deltaTime;

		if (g_inputSystem.GetKeyState(key_q) == InputSystem::KeyState::Held)
			m_owner->m_transform.position.z -= speed * g_time.deltaTime;
		if (g_inputSystem.GetKeyState(key_e) == InputSystem::KeyState::Held)
			m_owner->m_transform.position.z += speed * g_time.deltaTime;
	}

	bool CameraController::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool CameraController::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}

}