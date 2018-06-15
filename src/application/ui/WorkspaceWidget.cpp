#include "ui_WorkspaceWidget.h"
#include  "WorkspaceWidget.h"

using namespace ArtBoard;

WorkspaceWidget::WorkspaceWidget(QWidget* parent) : QWidget(parent)
    , ui(new Ui::WorkspaceWidget)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

WorkspaceWidget::~WorkspaceWidget() { delete ui; }

void WorkspaceWidget::SetGraphicsScene(QGraphicsScene* scene) const {
    this->ui->graphicsView->setScene(scene);
    //scene->set
}
