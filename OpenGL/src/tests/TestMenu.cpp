#include "TestMenu.h"

#include "Renderer.h"
#include "imgui/imgui.h"

namespace test {
	TestMenu::TestMenu()
		: testCC(), window(true), t(Menu)
	{
	}
	TestMenu::~TestMenu()
	{
	}
	void TestMenu::OnUpdate(float deltaTime)
	{
	}
	void TestMenu::OnRender()
	{
		

	}
	void TestMenu::OnImGuiRender()
	{
		ImGui::Text("Test Menu");
		if (ImGui::Button("Clear Color", ImVec2(150.0f, 50.0f)))
			t = TestCC;

		// Set new Test Window
		switch (t)
		{
			case TestCC:
				this->ClearColorTest();
		}

	}

	// Make new Window for Clear Color test
	void TestMenu::ClearColorTest()
	{
		ImGui::Begin("Clear Color Test", &window);
		testCC.OnUpdate(0.0f);
		testCC.OnRender();
		testCC.OnImGuiRender();
		if (ImGui::Button("Close Me") || window == false)
		{
			t = Menu;
			window = true;
		}
		ImGui::End();
	}
}