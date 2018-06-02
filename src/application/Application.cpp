#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include <QDebug>

#include "Application.h"

#include "Editor.h"

using namespace ArtBoard;

Application *Application::s_self;

Application::Application(int argc, char **argv) : m_qapp(argc, argv)
{
	if (s_self)
	{
		// app is already inited, halt
		exit(1);
	}

	QApplication::setOrganizationDomain("hu.caiwan.artboard");
	QApplication::setOrganizationName("Caiwan");
	QApplication::setApplicationName("ArtBoard");

	// do init sequence here
	s_self = this;
}

Application::~Application()
{
	s_self = nullptr;
}

int Application::Execute()
{
	QQmlApplicationEngine engine;
	Editor editor;

	engine.load(QUrl(QLatin1String("qrc:/ui/MainWindow.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return QApplication::exec();
}
