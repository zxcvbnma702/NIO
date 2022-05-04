#include "NIO.h"

class Box : public NIO::Application
{
public:
	Box() 
	{

	}
	~Box()
	{

	}

private:

};

NIO::Application* NIO::CreateApplication()
{
	return new Box();
}