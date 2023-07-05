#include "Nebulon.h"
#include "Nebulon/Core/Log.h"

class Sandbox : public Nebulon::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox() = default;
};

int main()
{
	std::unique_ptr<Sandbox> app = std::make_unique<Sandbox>();
}