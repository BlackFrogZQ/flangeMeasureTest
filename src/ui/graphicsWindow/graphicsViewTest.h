#pragma once
#include <QGraphicsView>
#include <QWheelEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QPoint>
#include <QScrollBar>

class ImageView : public QGraphicsView
{
    Q_OBJECT
public:
    ImageView(QWidget *parent = nullptr);
    void loadImage(const QImage &img);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mousePressEventOrig(QMouseEvent *event);

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem;
    bool panning;
    QPoint lastPanPoint;
};
