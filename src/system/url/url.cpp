#include "url.h"
#include "scheme/locationFileScheme.h"
#include <QDesktopServices>
namespace TIGER_Url
{
    void initBSUrlScheme()
    {
        auto pUrlLocationFileScheme = new CBSUrlLocationFileScheme;
        QDesktopServices::setUrlHandler(pUrlLocationFileScheme->getScheme(),pUrlLocationFileScheme,pUrlLocationFileScheme->getUrlSlotFunName().toStdString().data());
    }
}