#pragma once

#include "Test.h"
#include "TestClearColor.h"

enum TestCase
{
	Menu = 0,
	TestCC = 1
};


namespace test {

	class TestMenu : public Test
	{
	public:
		TestMenu();
		~TestMenu();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		TestClearColor testCC;
		bool window;
		TestCase t;

		void ClearColorTest();
	};
}
