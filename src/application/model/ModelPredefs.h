#pragma once
#include <memory>
#include <vector>

namespace ArtBoard
{

class Workspace;
typedef std::shared_ptr<Workspace> WorkspacePtr;

class Page;
typedef std::shared_ptr<Page> PagePtr;
typedef std::vector<PagePtr> PageList;

class Picture;
typedef std::shared_ptr<Picture> PicturePtr;
typedef std::vector<PicturePtr> PictureList;

} // namespace ArtBoard