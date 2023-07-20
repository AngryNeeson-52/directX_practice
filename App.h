#pragma once

#include "Window.h"
#include "SudalTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include "Model.h"
#include <set>
#include "TestPlane.h"
#include "TestCube.h"
#include "ScriptCommander.h"
#include "Stencil.h"
#include "FrameCommander.h"
#include "Material.h"

class App
{
public:
	App(const std::string& commandLine = "");

	int Go();
	~App();

private:
	void DoFrame();
	void ShowImguiDemoWindow();

private:
	std::string commandLine;
	bool showDemoWindow = false;
	ImguiManager imgui;
	Window wnd;
	SudalTimer timer;
	ScriptCommander scriptCommander;
	FrameCommander fc{wnd.Gfx()};

	float speed_factor = 1.0f;
	Camera cam;
	PointLight light;


	Model sponza{ wnd.Gfx(), "models\\Sponza\\sponza.obj", 1.0f / 20.0f };

	TestCube cube{wnd.Gfx(), 4.0f};
	TestCube cube2{ wnd.Gfx(), 4.0f };
};