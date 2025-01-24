#pragma once
#include <stdexcept>

namespace Library_Manager
{
#define DECLARE_NEW_EXCEPTION_CLASS(classname) \
class classname : public std::runtime_error\
{\
public:\
	classname();\
};

#define IMPLEMENT_NEW_EXCEPTION_CLASS(classname, message) \
classname::classname()\
	: std::runtime_error(message)\
{\
}

	DECLARE_NEW_EXCEPTION_CLASS(UnknownCommandException);
}