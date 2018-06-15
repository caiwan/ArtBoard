#pragma once 

#include <QList>
#include <QUrl>
#include "model/Workspace.h"

typedef QList<QUrl> QUrlList;

namespace ArtBoard
{
    class Editor;

    class WorkspaceController;

	class EditorView{
    public:

        void UriListDroppedEvent(const QUrlList &urlList);
        
	    /*void SaveEvnet();
        void OpenEvent();
        void NewEvent();
        void CloseEvent();*/

    private :
        Editor * m_editor;
    };

	class  Editor
	{
	public:
		Editor();

        // load/save
        //void Save();
        //void Load();
        void New();

        // workspace
        void AddImageToWorkspace(const QUrl &url);

	private:
        EditorView m_view;

        Workspace* m_workspace;
        bool m_isDirty;
	};

}
