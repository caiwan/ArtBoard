#include "Application.h"
#include "MainWindow.h"

#include "Editor.h"

using namespace ArtBoard;

Application* Application::s_self;

Application::Application(int argc, char **argv) :
	m_qapp(argc, argv)
{
	if (s_self) {
		// app is already inited, halt
		exit(1);
	}

    QApplication::setOrganizationDomain("hu.caiwan.artboard");
    QApplication::setOrganizationName("Caiwan");
    QApplication::setApplicationName("ArtBoard");

	// do init sequence here
	s_self = this;
}

Application::~Application() {
	s_self = nullptr;
}

int Application::Execute()
{
	Editor editor;
	MainWindow mw(nullptr);

	// mw.SetEditor(&editor);
    // editor.SetView(&mw);
	mw.show();

	// mw.setCentralWidget(&view);

	return QApplication::exec();
}
