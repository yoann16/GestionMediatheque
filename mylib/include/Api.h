#pragma once
#include "Interpreter.h"
namespace Library_Manager
{
	class API
	{
	public:
		void  cmd_init();
		void cmd_input();
	private:
		Interpreter& getInterpreter();
	};
}

