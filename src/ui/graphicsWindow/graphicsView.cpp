#include "graphicsView.h"
#include "tool/toolFun.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QApplication>
#include <QMouseEvent>
namespace TIGER_Graphics
{
    CGraphicsView::CGraphicsView(QWidget *parent)
        : QGraphicsView(parent),
          m_isMoving(false),
          m_border(0.92),
          m_scale(1.0)
    {
        setStyleSheet("QGraphicsView{background: transparent;border:0px};");
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        setDragMode(QGraphicsView::NoDrag);
        setCacheMode(QGraphicsView::CacheBackground);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setResizeAnchor(QGraphicsView::AnchorUnderMouse);
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        setOptimizationFlag(QGraphicsView::DontSavePainterState);
        setPointColor();
    }

    CGraphicsView::CGraphicsView(QGraphicsScene *scene, QWidget *parent)
        : QGraphicsView(scene, parent),
          m_isMoving(false),
          m_border(0.92),
          m_scale(1.0)
    {
        setStyleSheet("QGraphicsView{background: transparent;border:0px};");
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        setDragMode(QGraphicsView::NoDrag);
        setCacheMode(QGraphicsView::CacheBackground);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setResizeAnchor(QGraphicsView::AnchorUnderMouse);
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        setOptimizationFlag(QGraphicsView::DontSavePainterState);
        m_sceneRect = scene->sceneRect();
        setPointColor();
    }

    CGraphicsView::~CGraphicsView()
    {
    }

    void CGraphicsView::setBorder(double p_scale)
    {
        m_border = p_scale;
    }

    void CGraphicsView::setDefineSceneRect(QRectF p_sceneRect, bool p_resetView)
    {
        m_sceneRect = p_sceneRect;
        if (p_resetView)
        {
            resetView();
        }
    }

    void CGraphicsView::showPoints(QList<QPointF> p_features, QPointF p_offset)
    {
        m_features = p_features;
        for (auto &p : m_features)
        {
            p += p_offset;
            p = QPointF(qRound(p.x()), qRound(p.y()));
        }
    }

    QList<QPointF> CGraphicsView::getShowPoints() const
    {
        return m_features;
    }

    void CGraphicsView::clearPoints()
    {
        m_features.clear();
    }

    double CGraphicsView::getScale() const
    {
        return m_scale;
    }

    void CGraphicsView::setPointColor(QColor color)
    {
        m_featureColor = color;
    }

    void CGraphicsView::viewScale(const QPoint &p_viewPoint, const double &p_scale)
    {
        {
            auto size = this->mapToScene(this->rect()).boundingRect().size() / p_scale;
            if ((size.width() < 10 || size.height() < 10) && p_scale > 1)
            {
                return;
            }
            if ((this->width() / m_sceneRect.width()) < (this->height() / m_sceneRect.height()) && size.width() > (2 * m_sceneRect.width()) && p_scale < 1)
            {
                return;
            }

            if (size.height() > (2 * m_sceneRect.height()) && p_scale < 1)
            {
                return;
            }
        }

        m_scale *= p_scale;
        QPointF scenePos = this->mapToScene(p_viewPoint);
        QGraphicsView::scale(p_scale, p_scale);
        QPointF scaleScenePos = this->mapToScene(p_viewPoint);
        // 调整scene，使得scene和view一直，主要是为了排除掉scroll
        auto rect = this->mapToScene(this->rect()).boundingRect();
        // 获取缩放前后的坐标差值，即为需要进行move的位移
        viewOffset(scaleScenePos - scenePos, rect);
    }

    void CGraphicsView::viewOffset(const QPointF &p_sceneOffset, QRectF p_sceneRect)
    {
        if (p_sceneRect.isEmpty())
        {
            p_sceneRect = this->sceneRect();
        }

        this->setSceneRect(p_sceneRect.x() - p_sceneOffset.x(), p_sceneRect.y() - p_sceneOffset.y(),
                           p_sceneRect.width(), p_sceneRect.height());
        emit sigViewChange();
    }

    void CGraphicsView::resetView()
    {
        if (m_sceneRect.isEmpty())
        {
            if (scene()->sceneRect().isEmpty())
            {
                return;
            }
            m_sceneRect = scene()->sceneRect();
        }
        QGraphicsView::resetTransform();
        this->setSceneRect(m_sceneRect);
        m_scale = qMin(this->width() / m_sceneRect.width(), this->height() / m_sceneRect.height()) * m_border;
        QGraphicsView::scale(m_scale, m_scale);
        viewport()->update();
        emit sigViewChange();
    }

    void CGraphicsView::wheelEvent(QWheelEvent *p_event)
    {
        if (!m_isMoving && p_event->buttons() == Qt::NoButton)
        {
            constexpr double cScale = 0.9;
            constexpr double cScaleZoom = 2 - cScale;
            double scale = (p_event->delta() < 0 ? cScale : cScaleZoom);
            viewScale(p_event->pos(), scale);
        }
        // QGraphicsView::wheelEvent(p_event);
    }

    void CGraphicsView::mousePressEvent(QMouseEvent *p_event)
    {
        if ((p_event->button() & Qt::MidButton) && (!m_isMoving))
        {
            TIGER_GraphicsTool::setOverrideCursor(Qt::ClosedHandCursor);
            m_isMoving = true;
            m_lastPos = p_event->pos();
            return;
        }
        QGraphicsView::mousePressEvent(p_event);
        QApplication::sendEvent(this->parentWidget(), p_event);
    }

    void CGraphicsView::mouseReleaseEvent(QMouseEvent *p_event)
    {
        if (m_isMoving && p_event->button() & Qt::MiddleButton)
        {
            TIGER_GraphicsTool::restoreOverrideCursor();
            m_isMoving = false;
            return;
        }
        QGraphicsView::mouseReleaseEvent(p_event);
        QApplication::sendEvent(this->parentWidget(), p_event);
    }

    void CGraphicsView::mouseMoveEvent(QMouseEvent *p_event)
    {
        QPoint movPos = p_event->pos();
        if (movPos.x() < 0 || movPos.x() >= this->width() || movPos.y() < 0 || movPos.y() >= this->height())
        {
            return;
        }
        if ((p_event->buttons() == Qt::MouseButtons(Qt::MiddleButton)) && m_isMoving)
        {
            QPointF dis = this->mapToScene(movPos) - this->mapToScene(m_lastPos);
            m_lastPos = movPos;
            viewOffset(dis);
            return;
        }
        QGraphicsView::mouseMoveEvent(p_event);
        QApplication::sendEvent(this->parentWidget(), p_event);
    }

    void CGraphicsView::resizeEvent(QResizeEvent *p_event)
    {
        QGraphicsView::resizeEvent(p_event);
        resetView();
    }

    void CGraphicsView::mouseDoubleClickEvent(QMouseEvent *p_event)
    {
        QGraphicsView::mouseDoubleClickEvent(p_event);
        if ((p_event->buttons() & Qt::MiddleButton) && (!m_isMoving))
        {
            resetView();
        }
    }
    void CGraphicsView::drawPoints(QPainter *painter, QList<QPointF> p_points, QColor color)
    {
        if (p_points.isEmpty())
        {
            return;
        }
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->resetTransform();

        QVector<QPointF> drawPoints = p_points.toVector();
        for (auto &p : drawPoints)
        {
            p = viewportTransform().map(p);
        }

        QPolygonF polygon;
        polygon.append(drawPoints);
        auto polygonRect = polygon.boundingRect();
        const double cMin = 5;
        if (polygonRect.width() < cMin || polygonRect.height() < cMin)
        {
            polygonRect.setWidth(qMax(cMin, polygonRect.width()));
            polygonRect.setHeight(qMax(cMin, polygonRect.height()));
            painter->fillRect(polygonRect, color);
        }
        else
        {
            auto rect = mapToScene(QRect(0, 0, 1, 1)).boundingRect();
            m_scale < 1.0 ? painter->setPen(QPen(color, 2)) : painter->setPen(QPen(color, 1.0 / qMin(rect.width(), rect.height())));
            painter->drawPoints(drawPoints.data(), drawPoints.size());
        }
        painter->restore();
    }

    void CGraphicsView::drawForeground(QPainter *painter, const QRectF &rect)
    {
        QGraphicsView::drawForeground(painter, rect);
        drawPoints(painter, m_features, m_featureColor);
    }

    void CGraphicsView::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this->viewport());
        painter.drawTiledPixmap(this->viewport()->rect(), QPixmap(":/res/graphics/background.png"));
        QGraphicsView::paintEvent(event);
    }
};
