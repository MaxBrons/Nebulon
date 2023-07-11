#include "Nebulon.h"
#include "Nebulon/Core/Log.h"


class NebulonApp : public Nebulon::Application
{
public:
	NebulonApp(const std::string& name = "Nebulon App", unsigned int width = 720, unsigned int height = 360)
		:Nebulon::Application(name, width, height)
	{
	}
	~NebulonApp() = default;
};

int main()
{
	std::unique_ptr<NebulonApp> app = std::make_unique<NebulonApp>();
	app->Run();
}