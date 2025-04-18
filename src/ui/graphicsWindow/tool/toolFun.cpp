#include "toolFun.h"
#include <QApplication>
namespace TIGER_GraphicsTool
{
    void setOverrideCursor(const QCursor &p_cursor)
    {
        QApplication::setOverrideCursor(p_cursor);
    }

    void restoreOverrideCursor()
    {
        QApplication::restoreOverrideCursor();
    }
}
