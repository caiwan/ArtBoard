#include "application.h"

class WindowsApplication : public ArtBoard::Application {
public:
	WindowsApplication(int argc, char **argv) : ArtBoard::Application(argc, argv) {
	}
};

int main(int argc, char **argv)
{
	Q_INIT_RESOURCE(resources);
	WindowsApplication a(argc, argv);
	return a.Execute();
}
