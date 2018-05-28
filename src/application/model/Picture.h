#pragma once 

#include <QSizeF>
#include <QPointF>

class QPixmap;

#include "ModelPredefs.h"

namespace ArtBoard
{
class Picture{
    public:

// ... 

    private:
QPixmap* m_pixmap;

QPointF m_offset;
QSizeF m_zoom;
QPointF m_position;

};
}
