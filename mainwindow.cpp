#include "mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <stdexcept>
#include <QSizePolicy>

TMainWindow::TMainWindow(QWidget *parent) : QWidget(parent)
{
    resize(600,700);
    graphWindow = new GraphWindow(this);
    graphWindow->setGeometry(120,200,300,300);
    loadGraph = new QPushButton("Load file",this);
    label = new QLabel("Oriented graph",this);
    newNumber = new QLineEdit(this);
    changeActiveButton = new QPushButton("Change",this);
    error = new QLabel("No file loaded",this);
    newNumberLabel = new QLabel(this);
    changeStatus = new QLabel(this);
    QFont font;
    font.setPixelSize(20);
    label->setFont(font);
    label->setGeometry(0,50,600,50);
    label->setAlignment(Qt::AlignCenter);
    loadGraph->setGeometry(250,100,100,50);
    error->setFont(font);
    error->setGeometry(0,150,600,50);
    error->setAlignment(Qt::AlignCenter);
    newNumberLabel->setFont(font);
    newNumberLabel->setText("Choose new active number:");
    newNumberLabel->setGeometry(30,200,250,50);
    newNumber->setGeometry(300,210,100,30);
    changeActiveButton->setGeometry(420,210,100,30);

    graphWindow->setGeometry(150,300,200,400);

    changeStatus->setFont(font);
    changeStatus->setAlignment(Qt::AlignCenter);
    changeStatus->setGeometry(0,250,600,50);

    connect(loadGraph,SIGNAL(clicked()),this,SLOT(openFile()));
    connect(changeActiveButton,SIGNAL(clicked()),this,SLOT(changeActive()));


}

void TMainWindow::changeActive(){
    try {
        graph.changeActiveNumber(newNumber->text().toInt());
        updateGraphWindow();
    }  catch (const std::logic_error& exc) {
        changeStatus->setText("Can't change active number");
        return;
    }
    changeStatus->setText("Active number was changed");

}

void TMainWindow::openFile()
{
    QFileDialog file_dialog;
    QString path = file_dialog.getOpenFileName(this, tr("Open graph"), QString(), tr("Text files (*.txt)"));
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        error->setText("Error: Can't open file");
        return;
    }

    QString data = file.readAll();
    if(data.isEmpty()){
        error->setText(QString("Error: ") + " File is empty!");
        return;
    }

    if (checkData(data)){
        error->setText(QString("Error: Row number and column number are not equal"));
        return;
    }


    graph.fillGraph(data);
    updateGraphWindow();
    error->setText("File opened successfully");
}
void TMainWindow::updateGraphWindow()
{
    graphWindow->updateGraph(graph);
}

bool TMainWindow::checkData(const QString &data)
{
    QStringList rows = data.split("\n");
    int rows_size = rows.size();

    Matrix<qint16> matrix(rows_size);

    for(int i = 0; i< rows_size; i++){
        QStringList elems = rows[i].split(" ");
        if(elems.size()!=rows_size){
            return true;
        }
    }
    return false;
}
