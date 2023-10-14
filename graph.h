#ifndef GRAPH_H
#define GRAPH_H
#include "matrix.h"
#include <QPainter>
#include <QColor>

class Graph
{
public:
    Graph();
    Graph(const QString &);

protected:
    Matrix<qint16> graphMatrix;

};

#endif // GRAPH_H
