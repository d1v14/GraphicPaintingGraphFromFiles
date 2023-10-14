#include "GraphWindow.h"
#include <QVBoxLayout>
GraphWindow::GraphWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300,300);
}

void GraphWindow::updateGraph(const WeightedGraph &graph)
{
    this->graph = graph;
    repaint();
}

void GraphWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPoint center(height()/2,width()/2);
    graph.view(painter,center);

    painter.end();
}


