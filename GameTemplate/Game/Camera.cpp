#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
{
	
}

Camera::~Camera()
{

}

bool Camera::Start()
{
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 3000.0f, 100.0f });
	MainCamera().Update();
	/*m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");*/

	return true;
}

void Camera::Update()
{

}