#include "Editor.h"

#include <QUrl>

using namespace ArtBoard;

void EditorView::UriListDroppedEvent(const QUrlList& urlList) {
    for(QUrl url : urlList)
    {
        m_editor->AddImageToWorkspace(url);
    }
}

Editor::Editor(): m_workspace(nullptr)
    , m_isDirty(false) {
}

void Editor::New() {
    if (!m_workspace) {
        m_workspace = new Workspace();
    }
    
}

void ArtBoard::Editor::AddImageToWorkspace(const QUrl &url)
{
    if (url.isLocalFile())
    {
        //QFile file;
        //if(file.open(url, Qt::Mode_))
        //{
        //    
        //}
    } else
    {
        
    }
}
