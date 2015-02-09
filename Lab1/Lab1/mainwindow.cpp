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

    scene = new Scene(this);


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    item = new GeomItem(0.0f, 0.0f);
    scene->addItem(item);

    scene->changeParams(100, 10, QColor(255, 0, 0));

}

MainWindow::~MainWindow()
{
    delete item;
    delete ui;
}
