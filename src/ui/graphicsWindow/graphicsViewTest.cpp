#include "graphicsViewTest.h"

ImageView::ImageView(QWidget *parent) : QGraphicsView(parent), pixmapItem(nullptr)
{
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    this->setCacheMode(QGraphicsView::CacheNone);
}

void ImageView::loadImage(const QImage &img)
{
    scene->clear();
    pixmapItem = scene->addPixmap(QPixmap::fromImage(img));
    scene->setSceneRect(img.rect());
}

void ImageView::drawBackground(QPainter *painter, const QRectF &rect)
{
    const int gridSize = 10;
    const QColor light(220, 220, 220), dark(180, 180, 180);
    int xStart = int(rect.left()) - (int(rect.left()) % gridSize);
    int yStart = int(rect.top())  - (int(rect.top())  % gridSize);

    for (int y = yStart; y < rect.bottom(); y += gridSize) 
    {
        for (int x = xStart; x < rect.right(); x += gridSize) 
        {
            QRectF cell(x, y, gridSize, gridSize);
            bool isLight = (((x / gridSize) + (y / gridSize)) % 2) == 0;
            painter->fillRect(cell, isLight ? light : dark);
        }
    }
}

void ImageView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    constexpr double scaleFactor = 1.15;
    if (event->angleDelta().y() > 0)
    {
        scale(scaleFactor, scaleFactor);
    }
    else
    {
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
}

void ImageView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton)
    {
        setCursor(Qt::ClosedHandCursor);
        panning = true;
        lastPanPoint = event->pos();
        event->accept();
        return;
    }
    QGraphicsView::mousePressEvent(event);
}

void ImageView::mouseMoveEvent(QMouseEvent *event)
{
    if (panning)
    {
        QPointF delta = event->pos() - lastPanPoint;
        lastPanPoint = event->pos();
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
        event->accept();
        return;
    }
    QGraphicsView::mouseMoveEvent(event);
}

void ImageView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton && panning)
    {
        setCursor(Qt::ArrowCursor);
        panning = false;
        event->accept();
        return;
    }
    QGraphicsView::mouseReleaseEvent(event);
}

void ImageView::mousePressEventOrig(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton && pixmapItem)
    {
        QPointF scenePt = mapToScene(event->pos());
        QPoint imgPt = scenePt.toPoint();
        QImage img = pixmapItem->pixmap().toImage();
        if (img.rect().contains(imgPt))
        {
            QColor color = img.pixelColor(imgPt);
            qDebug() << "中键点击位置：" << imgPt << "颜色：" << color;
        }
    }
}