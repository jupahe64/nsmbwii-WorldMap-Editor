#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QtEndian>

#include <FileFormats/filehelper.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("nsmbwii Worldmap Editor");
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::actionOpen);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::actionSave);

    connect(ui->actionWorld_1, &QAction::triggered, this, &MainWindow::actionWorld1);
    connect(ui->actionWorld_2, &QAction::triggered, this, &MainWindow::actionWorld2);
    connect(ui->actionWorld_3, &QAction::triggered, this, &MainWindow::actionWorld3a);
    connect(ui->actionWorld_3_Part_2, &QAction::triggered, this, &MainWindow::actionWorld3b);
    connect(ui->actionWorld_4, &QAction::triggered, this, &MainWindow::actionWorld4);
    connect(ui->actionWorld_5, &QAction::triggered, this, &MainWindow::actionWorld5);
    connect(ui->actionWorld_6, &QAction::triggered, this, &MainWindow::actionWorld6);
    connect(ui->actionWorld_7, &QAction::triggered, this, &MainWindow::actionWorld7);
    connect(ui->actionWorld_8, &QAction::triggered, this, &MainWindow::actionWorld8);
    connect(ui->actionWorld_9, &QAction::triggered, this, &MainWindow::actionWorld9);
    qDebug() << "window opened";
    mapId = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionOpen()
{
    fileName = QFileDialog::getExistingDirectory(this,
            tr("Open the Worldmap folder"));

    QFile file(fileName+"/RouteInfo.arc");
    if (!file.open(QIODevice::ReadOnly)) return;
    qDebug() << "successfully loaded RouteInfo!" << endl;

    unpackedCSVs = FileHelper::unpackCSVsFromU8(file);

    file.close();

    loadPoints(unpackedCSVs.value("W1/pointW1.csv"),0);
    loadPoints(unpackedCSVs.value("W2/pointW2a.csv"),1);
    loadPoints(unpackedCSVs.value("W3/pointW3a.csv"),2);
    loadPoints(unpackedCSVs.value("W3/pointW3b.csv"),3);
    loadPoints(unpackedCSVs.value("W4/pointW4.csv"),4);
    loadPoints(unpackedCSVs.value("W5/pointW5.csv"),5);
    loadPoints(unpackedCSVs.value("W6/pointW6a.csv"),6);
    loadPoints(unpackedCSVs.value("W7/pointW7.csv"),7);
    loadPoints(unpackedCSVs.value("W8/pointW8.csv"),8);
    loadPoints(unpackedCSVs.value("W9/pointW9.csv"),9);

    loadRoute(unpackedCSVs.value("W1/routeW1.csv"),0);
    loadRoute(unpackedCSVs.value("W2/routeW2a.csv"),1);
    loadRoute(unpackedCSVs.value("W3/routeW3a.csv"),2);
    loadRoute(unpackedCSVs.value("W3/routeW3b.csv"),3);
    loadRoute(unpackedCSVs.value("W4/routeW4.csv"),4);
    loadRoute(unpackedCSVs.value("W5/routeW5.csv"),5);
    loadRoute(unpackedCSVs.value("W6/routeW6a.csv"),6);
    loadRoute(unpackedCSVs.value("W7/routeW7.csv"),7);
    loadRoute(unpackedCSVs.value("W8/routeW8.csv"),8);
    loadRoute(unpackedCSVs.value("W9/routeW9.csv"),9);

    loadWorldMapBones(file, fileName+"/CS_W1.arc", 0);
    loadWorldMapBones(file, fileName+"/CS_W2.arc", 1);
    loadWorldMapBones(file, fileName+"/CS_W3.arc", 2);
    loadWorldMapBones(file, fileName+"/CS_W3.arc", 3,1);
    loadWorldMapBones(file, fileName+"/CS_W4.arc", 4);
    loadWorldMapBones(file, fileName+"/CS_W5.arc", 5);
    loadWorldMapBones(file, fileName+"/CS_W6.arc", 6);
    loadWorldMapBones(file, fileName+"/CS_W7.arc", 7);
    loadWorldMapBones(file, fileName+"/CS_W8.arc", 8);
    loadWorldMapBones(file, fileName+"/CS_W9.arc", 9);

    loadWorldMap();
}

void MainWindow::actionSave()
{
    QDir dir(fileName);
    dir.mkdir("Extracted_CSVs");
    int fileid = 0;
    foreach (Csv *csv, unpackedCSVs.values()) {
        QFile dest(fileName+QString("/Extracted_CSVs/csv")+QString::number(fileid++)+QString(".csv"));
        if (!dest.open(QIODevice::ReadWrite|QIODevice::Truncate)){
            qDebug() << "file couldn't be created";
        }
        csv->write(dest);
        qDebug() << dest.pos();
        dest.resize(dest.pos());
        qDebug() << dest.size();
        dest.close();
    }
}



void MainWindow::loadWorldMap()
{
    ui->listPoints->clear();
    ui->listPaths->clear();
    foreach (QString key, maps[mapId].m_wayPoints.keys()) {
        ui->listPoints->addItem(key);
    }
    foreach (QString key, maps[mapId].m_routePaths.keys()) {
        ui->listPaths->addItem(key);
    }
    ui->openGLWidget->setActiveMap(&maps[mapId],mapId);
    ui->shapeView->setActiveMap(&maps[mapId]);
}

void MainWindow::on_listPoints_currentTextChanged(const QString &currentText)
{
    ui->listEvents->clear();
    ui->listExitAnims->clear();
    ui->listSecretExitAnims->clear();
    ui->listIndirectConnections->clear();

    if (!maps[mapId].m_wayPoints.contains(currentText))
        return;

    ui->openGLWidget->setSelectedPoint(currentText);

    ui->comboBoxRepresentation->setCurrentIndex(maps[mapId].m_wayPoints[currentText]->m_representation);

    ui->valX->setValue(maps[mapId].m_wayPoints[currentText]->x);
    ui->valY->setValue(maps[mapId].m_wayPoints[currentText]->y);
    ui->valZ->setValue(maps[mapId].m_wayPoints[currentText]->z);

    foreach (QString entry, maps[mapId].m_wayPoints[currentText]->m_events) {
        ui->listEvents->addItem(entry);
    }

    foreach (QString entry, maps[mapId].m_wayPoints[currentText]->m_exitAnims) {
        ui->listExitAnims->addItem(entry);
    }

    foreach (QString entry, maps[mapId].m_wayPoints[currentText]->m_secretExitAnims) {
        ui->listSecretExitAnims->addItem(entry);
    }

    foreach (QString entry, maps[mapId].m_wayPoints[currentText]->m_indirectConnections) {
        ui->listIndirectConnections->addItem(entry);
    }
    qDebug() << "selected: " << currentText;
}

void MainWindow::on_listPaths_currentTextChanged(const QString &currentText)
{
    ui->shapeView->setSelectedPath(currentText);
}

void MainWindow::on_listPoints_itemDoubleClicked(QListWidgetItem *item)
{
    ui->openGLWidget->setFocus(
                maps[mapId].m_wayPoints[item->text()]->x,
                maps[mapId].m_wayPoints[item->text()]->y,
                maps[mapId].m_wayPoints[item->text()]->z
                );
}

void MainWindow::on_listExitAnims_itemDoubleClicked(QListWidgetItem *item)
{
    ui->tabWidget->setCurrentIndex(1);
    ui->listPaths->setCurrentItem(
                ui->listPaths->findItems(item->text(),Qt::MatchExactly).first()
                );
}

void MainWindow::on_listSecretExitAnims_itemDoubleClicked(QListWidgetItem *item)
{
    ui->tabWidget->setCurrentIndex(1);
    ui->listPaths->setCurrentItem(
                ui->listPaths->findItems(item->text(),Qt::MatchExactly).first()
                );
}
