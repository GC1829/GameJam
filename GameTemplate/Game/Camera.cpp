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
	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 2600.0f, 100.0f });
	MainCamera().Update();

	return true;
}

void Camera::Update()
{

}