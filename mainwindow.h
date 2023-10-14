#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "graphWindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "weightedgraph.h"

class TMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TMainWindow(QWidget *parent = nullptr);
    void updateGraphWindow();
    bool checkData(const QString &data);

public slots:
    void openFile();
    void changeActive();

private:
    GraphWindow* graphWindow;
    QPushButton* loadGraph;
    QLabel* error;
    QLabel* newNumberLabel;
    QLabel* changeStatus;
    WeightedGraph graph;
    QLabel* label;
    QLabel* status;
    QLineEdit* newNumber;
    QPushButton* changeActiveButton;

};

#endif // MAINWINDOW_H
