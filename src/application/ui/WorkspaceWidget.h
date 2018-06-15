#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QWidget>

namespace Ui
{
    class WorkspaceWidget;
}

namespace ArtBoard
{
    

class WorkspaceWidget  : public QWidget
{
    Q_OBJECT

public:
    explicit WorkspaceWidget(QWidget* parent = nullptr);
    ~WorkspaceWidget();

    void SetGraphicsScene(QGraphicsScene* scene) const;

private:
    Ui::WorkspaceWidget* ui;
};

}
#endif // WORKSPACE_H
