#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include "weightedgraph.h"
class GraphWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWindow(QWidget *parent = nullptr);
    void updateGraph(const WeightedGraph& graph);

protected:
    void paintEvent(QPaintEvent *event);

private:
    WeightedGraph graph;
};

#endif // GRAPHWINDOW_H
