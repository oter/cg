#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->insertItems(0, QColor::colorNames());
    ui->comboBox->setCurrentIndex(0);

    scene = new QGraphicsScene(this);


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    item = new GeomItem(0.0f, 0.0f);
    scene->addItem(item);
}

MainWindow::~MainWindow()
{
    delete item;
    delete ui;
}
