#include "graph.h"
#include <stdexcept>
#include <QStringList>
#include <math.h>
#include <QDebug>

Graph::Graph()
{
    ;
}

Graph::Graph(const QString &data)
{
    QStringList rows = data.split("\n");
    int rows_size = rows.size();

    Matrix<qint16> matrix(rows_size);

    for(int i = 0; i< rows_size; i++){
        QStringList elems = rows[i].split(" ");
        for(int j=0; j<rows_size; j++)
           matrix[i][j] = elems[j].toShort();

    }

    graphMatrix = matrix;
}



