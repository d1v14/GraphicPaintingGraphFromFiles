#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include "graph.h"
#include <math.h>
class WeightedGraph : public Graph
{
public:
    WeightedGraph();
    void changeActiveNumber(int);
    void view(QPainter&, const QPoint&) const;
    void fillGraph(const QString &);
private:
    std::size_t activeNum;
};

#endif // WEIGHTEDGRAPH_H
