#pragma once
#include <QGraphicsView>
// 中键按住视图移动、双击复原
namespace TIGER_Graphics
{
    class CGraphicsView : public QGraphicsView
    {
        Q_OBJECT
    public:
        CGraphicsView(QWidget *parent = nullptr);
        CGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);
        virtual ~CGraphicsView();
        void setBorder(double p_scale = 0.92);
        void resetView();
        void viewScale(const QPoint &p_viewPoint, const double &p_scale);
        void setDefineSceneRect(QRectF p_sceneRect, bool p_resetView = true);
        void setPointColor(QColor color = Qt::red);
        // 坐标系为Scene下
        void showPoints(QList<QPointF> p_features, QPointF p_offset = QPointF(0, 0));
        QList<QPointF> getShowPoints() const;
        void clearPoints();
        double getScale() const;

    signals:
        void sigViewChange();

    protected:
        void viewOffset(const QPointF &p_sceneOffset, QRectF p_sceneRect = QRectF());
        void drawPoints(QPainter *painter, QList<QPointF> p_points, QColor color);

    protected:
        // button返回"发生此事件的那个按钮"，buttons返回"发生此事件时处于按下状态的那些按钮"
        virtual void wheelEvent(QWheelEvent *p_event) override;
        virtual void mousePressEvent(QMouseEvent *p_event) override;
        virtual void resizeEvent(QResizeEvent *p_event) override;
        virtual void mouseDoubleClickEvent(QMouseEvent *p_event) override;

        // QGraphicsView事件传递机制与普通窗口不一致，某些事件需手动调用 p_event->ignore()，才能传递到父窗口;
        virtual void mouseReleaseEvent(QMouseEvent *p_event) override;
        virtual void mouseMoveEvent(QMouseEvent *p_event) override;
        virtual void drawForeground(QPainter *painter, const QRectF &rect) override;
        virtual void paintEvent(QPaintEvent *event) override;

    protected:
        QPoint m_lastPos;
        bool m_isMoving;
        double m_border;
        double m_scale;
        QList<QPointF> m_features;
        QColor m_featureColor;
        // 场景最初大小
        QRectF m_sceneRect;
    };
};
