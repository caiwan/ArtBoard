#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDragEnterEvent>
#include<QDragLeaveEvent>
#include <QMimeData>


using namespace ArtBoard;

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAcceptDrops(true);
    //setAttribute(Qt::WA_AcceptDrops, false);
    //setAttribute(Qt::WA_AcceptDrops, true);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::dragEnterEvent(QDragEnterEvent* event)
{
    const QMimeData* mime = event->mimeData();

    if (mime->hasUrls() || checkMimeIsImage(mime)) { event->acceptProposedAction(); }
}

void MainWindow::dragMoveEvent(QDragMoveEvent* event)
{
    const QMimeData* mime = event->mimeData();

    if ((mime->hasUrls() || mime->hasImage()) && event->answerRect().intersects(centralWidget()->geometry())) { event->acceptProposedAction(); }
}


void MainWindow::dropEvent(QDropEvent* event)
{
    const QMimeData* mime = event->mimeData();

    if (mime->hasUrls() || checkMimeIsImage(mime))
    {
        QUrlList urls = mime->urls();
        UriListDroppedEvent(urls);
    }
    else
    {
        return;
    }

    event->acceptProposedAction();
}

bool MainWindow::checkMimeIsImage(const QMimeData* mime)
{
    return
        mime->hasFormat("image/jpeg")
        || mime->hasFormat("image/png")
        || mime->hasFormat("image/gif")
        || mime->hasFormat("image/tiff")
        || mime->hasFormat("image/bmp")
        ;
}
