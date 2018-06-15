#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Editor.h"
#include <qmimedata.h>

namespace Ui {
class MainWindow;
}

class QMimeData;

namespace ArtBoard
{

    class MainWindow : public QMainWindow, public EditorView
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    protected:
        void dragEnterEvent(QDragEnterEvent* event) override;
        void dragMoveEvent(QDragMoveEvent* event) override;
        void dropEvent(QDropEvent* event) override;

    private:
        static bool checkMimeIsImage(const QMimeData* mime);
        Ui::MainWindow *ui;
    };

}
#endif // MAINWINDOW_H
