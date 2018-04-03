/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionWorld_1;
    QAction *actionWorld_2;
    QAction *actionWorld_3;
    QAction *actionWorld_3_Part_2;
    QAction *actionWorld_4;
    QAction *actionWorld_5;
    QAction *actionWorld_6;
    QAction *actionWorld_7;
    QAction *actionWorld_8;
    QAction *actionWorld_9;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    GLView *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QDockWidget *propertyPanel;
    QWidget *dockWidgetContents_4;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tabPoints;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listPoints;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnAddPoint;
    QPushButton *btnDeletePoint;
    QLabel *label;
    QComboBox *comboBoxRepresentation;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget_2;
    QWidget *tabEventsOnStep;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listEvents;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAddEvent;
    QPushButton *btnDeleteEvent;
    QWidget *tabAnimsOnExit;
    QVBoxLayout *verticalLayout;
    QListWidget *listExitAnims;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnAddExitAnim;
    QPushButton *btnDeleteExitAnim;
    QWidget *tabAnimsOnSecretExit;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listSecretExitAnims;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnAddSecretExitAnim;
    QPushButton *btnDeleteSecretExitAnim;
    QWidget *tabIndirectConnections;
    QVBoxLayout *verticalLayout_5;
    QListWidget *listIndirectConnections;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btnAddUnnconnectedPoint;
    QPushButton *btnDeleteUnconnectedPoint;
    QLabel *label_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *valX;
    QLabel *label_5;
    QDoubleSpinBox *valY;
    QLabel *label_6;
    QDoubleSpinBox *valZ;
    QWidget *tabPaths;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1065, 746);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionWorld_1 = new QAction(MainWindow);
        actionWorld_1->setObjectName(QStringLiteral("actionWorld_1"));
        actionWorld_2 = new QAction(MainWindow);
        actionWorld_2->setObjectName(QStringLiteral("actionWorld_2"));
        actionWorld_3 = new QAction(MainWindow);
        actionWorld_3->setObjectName(QStringLiteral("actionWorld_3"));
        actionWorld_3_Part_2 = new QAction(MainWindow);
        actionWorld_3_Part_2->setObjectName(QStringLiteral("actionWorld_3_Part_2"));
        actionWorld_4 = new QAction(MainWindow);
        actionWorld_4->setObjectName(QStringLiteral("actionWorld_4"));
        actionWorld_5 = new QAction(MainWindow);
        actionWorld_5->setObjectName(QStringLiteral("actionWorld_5"));
        actionWorld_6 = new QAction(MainWindow);
        actionWorld_6->setObjectName(QStringLiteral("actionWorld_6"));
        actionWorld_7 = new QAction(MainWindow);
        actionWorld_7->setObjectName(QStringLiteral("actionWorld_7"));
        actionWorld_8 = new QAction(MainWindow);
        actionWorld_8->setObjectName(QStringLiteral("actionWorld_8"));
        actionWorld_9 = new QAction(MainWindow);
        actionWorld_9->setObjectName(QStringLiteral("actionWorld_9"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        openGLWidget = new GLView(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setMouseTracking(true);

        horizontalLayout_5->addWidget(openGLWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1065, 22));
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        propertyPanel = new QDockWidget(MainWindow);
        propertyPanel->setObjectName(QStringLiteral("propertyPanel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(propertyPanel->sizePolicy().hasHeightForWidth());
        propertyPanel->setSizePolicy(sizePolicy);
        propertyPanel->setMinimumSize(QSize(496, 675));
        propertyPanel->setBaseSize(QSize(800, 0));
        propertyPanel->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        propertyPanel->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(dockWidgetContents_4);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabPoints = new QWidget();
        tabPoints->setObjectName(QStringLiteral("tabPoints"));
        verticalLayout_2 = new QVBoxLayout(tabPoints);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listPoints = new QListWidget(tabPoints);
        listPoints->setObjectName(QStringLiteral("listPoints"));

        verticalLayout_2->addWidget(listPoints);

        widget = new QWidget(tabPoints);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnAddPoint = new QPushButton(widget);
        btnAddPoint->setObjectName(QStringLiteral("btnAddPoint"));
        btnAddPoint->setEnabled(false);

        horizontalLayout_3->addWidget(btnAddPoint);

        btnDeletePoint = new QPushButton(widget);
        btnDeletePoint->setObjectName(QStringLiteral("btnDeletePoint"));
        btnDeletePoint->setEnabled(false);

        horizontalLayout_3->addWidget(btnDeletePoint);


        verticalLayout_2->addWidget(widget);

        label = new QLabel(tabPoints);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        comboBoxRepresentation = new QComboBox(tabPoints);
        comboBoxRepresentation->setObjectName(QStringLiteral("comboBoxRepresentation"));
        comboBoxRepresentation->setEnabled(true);

        verticalLayout_2->addWidget(comboBoxRepresentation);

        verticalSpacer = new QSpacerItem(20, 64, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget_2 = new QTabWidget(tabPoints);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        tabWidget_2->setFont(font);
        tabWidget_2->setStyleSheet(QStringLiteral(""));
        tabWidget_2->setTabPosition(QTabWidget::North);
        tabWidget_2->setTabShape(QTabWidget::Rounded);
        tabWidget_2->setIconSize(QSize(16, 16));
        tabWidget_2->setElideMode(Qt::ElideNone);
        tabWidget_2->setUsesScrollButtons(true);
        tabWidget_2->setDocumentMode(false);
        tabWidget_2->setTabsClosable(false);
        tabWidget_2->setMovable(false);
        tabWidget_2->setTabBarAutoHide(false);
        tabEventsOnStep = new QWidget();
        tabEventsOnStep->setObjectName(QStringLiteral("tabEventsOnStep"));
        verticalLayout_3 = new QVBoxLayout(tabEventsOnStep);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        listEvents = new QListWidget(tabEventsOnStep);
        listEvents->setObjectName(QStringLiteral("listEvents"));

        verticalLayout_3->addWidget(listEvents);

        widget_2 = new QWidget(tabEventsOnStep);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnAddEvent = new QPushButton(widget_2);
        btnAddEvent->setObjectName(QStringLiteral("btnAddEvent"));
        btnAddEvent->setEnabled(false);
        QFont font1;
        font1.setPointSize(13);
        btnAddEvent->setFont(font1);

        horizontalLayout_2->addWidget(btnAddEvent);

        btnDeleteEvent = new QPushButton(widget_2);
        btnDeleteEvent->setObjectName(QStringLiteral("btnDeleteEvent"));
        btnDeleteEvent->setEnabled(false);
        btnDeleteEvent->setFont(font1);

        horizontalLayout_2->addWidget(btnDeleteEvent);


        verticalLayout_3->addWidget(widget_2);

        tabWidget_2->addTab(tabEventsOnStep, QString());
        tabAnimsOnExit = new QWidget();
        tabAnimsOnExit->setObjectName(QStringLiteral("tabAnimsOnExit"));
        verticalLayout = new QVBoxLayout(tabAnimsOnExit);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listExitAnims = new QListWidget(tabAnimsOnExit);
        listExitAnims->setObjectName(QStringLiteral("listExitAnims"));

        verticalLayout->addWidget(listExitAnims);

        widget_4 = new QWidget(tabAnimsOnExit);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btnAddExitAnim = new QPushButton(widget_4);
        btnAddExitAnim->setObjectName(QStringLiteral("btnAddExitAnim"));
        btnAddExitAnim->setEnabled(false);
        btnAddExitAnim->setFont(font1);

        horizontalLayout_6->addWidget(btnAddExitAnim);

        btnDeleteExitAnim = new QPushButton(widget_4);
        btnDeleteExitAnim->setObjectName(QStringLiteral("btnDeleteExitAnim"));
        btnDeleteExitAnim->setEnabled(false);
        btnDeleteExitAnim->setFont(font1);

        horizontalLayout_6->addWidget(btnDeleteExitAnim);


        verticalLayout->addWidget(widget_4);

        tabWidget_2->addTab(tabAnimsOnExit, QString());
        tabAnimsOnSecretExit = new QWidget();
        tabAnimsOnSecretExit->setObjectName(QStringLiteral("tabAnimsOnSecretExit"));
        verticalLayout_4 = new QVBoxLayout(tabAnimsOnSecretExit);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        listSecretExitAnims = new QListWidget(tabAnimsOnSecretExit);
        listSecretExitAnims->setObjectName(QStringLiteral("listSecretExitAnims"));

        verticalLayout_4->addWidget(listSecretExitAnims);

        widget_5 = new QWidget(tabAnimsOnSecretExit);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        btnAddSecretExitAnim = new QPushButton(widget_5);
        btnAddSecretExitAnim->setObjectName(QStringLiteral("btnAddSecretExitAnim"));
        btnAddSecretExitAnim->setEnabled(false);

        horizontalLayout_7->addWidget(btnAddSecretExitAnim);

        btnDeleteSecretExitAnim = new QPushButton(widget_5);
        btnDeleteSecretExitAnim->setObjectName(QStringLiteral("btnDeleteSecretExitAnim"));
        btnDeleteSecretExitAnim->setEnabled(false);

        horizontalLayout_7->addWidget(btnDeleteSecretExitAnim);


        verticalLayout_4->addWidget(widget_5);

        tabWidget_2->addTab(tabAnimsOnSecretExit, QString());
        tabIndirectConnections = new QWidget();
        tabIndirectConnections->setObjectName(QStringLiteral("tabIndirectConnections"));
        verticalLayout_5 = new QVBoxLayout(tabIndirectConnections);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        listIndirectConnections = new QListWidget(tabIndirectConnections);
        listIndirectConnections->setObjectName(QStringLiteral("listIndirectConnections"));

        verticalLayout_5->addWidget(listIndirectConnections);

        widget_6 = new QWidget(tabIndirectConnections);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_8 = new QHBoxLayout(widget_6);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        btnAddUnnconnectedPoint = new QPushButton(widget_6);
        btnAddUnnconnectedPoint->setObjectName(QStringLiteral("btnAddUnnconnectedPoint"));
        btnAddUnnconnectedPoint->setEnabled(false);

        horizontalLayout_8->addWidget(btnAddUnnconnectedPoint);

        btnDeleteUnconnectedPoint = new QPushButton(widget_6);
        btnDeleteUnconnectedPoint->setObjectName(QStringLiteral("btnDeleteUnconnectedPoint"));
        btnDeleteUnconnectedPoint->setEnabled(false);

        horizontalLayout_8->addWidget(btnDeleteUnconnectedPoint);


        verticalLayout_5->addWidget(widget_6);

        tabWidget_2->addTab(tabIndirectConnections, QString());

        verticalLayout_2->addWidget(tabWidget_2);

        label_3 = new QLabel(tabPoints);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        widget_3 = new QWidget(tabPoints);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(14, 16777215));

        horizontalLayout_4->addWidget(label_4);

        valX = new QDoubleSpinBox(widget_3);
        valX->setObjectName(QStringLiteral("valX"));
        valX->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        valX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        valX->setProperty("showGroupSeparator", QVariant(false));
        valX->setMinimum(-32000);
        valX->setMaximum(32000);

        horizontalLayout_4->addWidget(valX);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(14, 16777215));

        horizontalLayout_4->addWidget(label_5);

        valY = new QDoubleSpinBox(widget_3);
        valY->setObjectName(QStringLiteral("valY"));
        valY->setStyleSheet(QStringLiteral("color: rgb(0, 94, 255);"));
        valY->setMinimum(-32000);
        valY->setMaximum(32000);

        horizontalLayout_4->addWidget(valY);

        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(14, 16777215));

        horizontalLayout_4->addWidget(label_6);

        valZ = new QDoubleSpinBox(widget_3);
        valZ->setObjectName(QStringLiteral("valZ"));
        valZ->setStyleSheet(QStringLiteral("color: rgb(0, 255, 0);"));
        valZ->setMinimum(-32000);
        valZ->setMaximum(32000);

        horizontalLayout_4->addWidget(valZ);


        verticalLayout_2->addWidget(widget_3);

        tabWidget->addTab(tabPoints, QString());
        tabPaths = new QWidget();
        tabPaths->setObjectName(QStringLiteral("tabPaths"));
        verticalLayout_6 = new QVBoxLayout(tabPaths);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_2 = new QLabel(tabPaths);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_2);

        tabWidget->addTab(tabPaths, QString());

        horizontalLayout->addWidget(tabWidget);

        propertyPanel->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), propertyPanel);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionWorld_1);
        toolBar->addAction(actionWorld_2);
        toolBar->addAction(actionWorld_3);
        toolBar->addAction(actionWorld_3_Part_2);
        toolBar->addAction(actionWorld_4);
        toolBar->addAction(actionWorld_5);
        toolBar->addAction(actionWorld_6);
        toolBar->addAction(actionWorld_7);
        toolBar->addAction(actionWorld_8);
        toolBar->addAction(actionWorld_9);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Meta+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Meta+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Extract CSVs", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Meta+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionWorld_1->setText(QApplication::translate("MainWindow", "World 1", Q_NULLPTR));
        actionWorld_2->setText(QApplication::translate("MainWindow", "World 2", Q_NULLPTR));
        actionWorld_3->setText(QApplication::translate("MainWindow", "World 3 Part 1", Q_NULLPTR));
        actionWorld_3_Part_2->setText(QApplication::translate("MainWindow", "World 3 Part 2", Q_NULLPTR));
        actionWorld_4->setText(QApplication::translate("MainWindow", "World 4", Q_NULLPTR));
        actionWorld_5->setText(QApplication::translate("MainWindow", "World 5", Q_NULLPTR));
        actionWorld_6->setText(QApplication::translate("MainWindow", "World 6", Q_NULLPTR));
        actionWorld_7->setText(QApplication::translate("MainWindow", "World 7", Q_NULLPTR));
        actionWorld_8->setText(QApplication::translate("MainWindow", "World 8", Q_NULLPTR));
        actionWorld_9->setText(QApplication::translate("MainWindow", "World 9", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        btnAddPoint->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        btnDeletePoint->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Representation", Q_NULLPTR));
        comboBoxRepresentation->clear();
        comboBoxRepresentation->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ToadHouse Green", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ToadHouse Yellow", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ToadHouse Red", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tower", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Castle", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Final Castle", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GhostHouse", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Anchor", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Warp Canon", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Peachs Castle", Q_NULLPTR)
        );
        btnAddEvent->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        btnDeleteEvent->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabEventsOnStep), QApplication::translate("MainWindow", "Events On Step", Q_NULLPTR));
        btnAddExitAnim->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        btnDeleteExitAnim->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabAnimsOnExit), QApplication::translate("MainWindow", "Exit Anims", Q_NULLPTR));
        btnAddSecretExitAnim->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        btnDeleteSecretExitAnim->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabAnimsOnSecretExit), QApplication::translate("MainWindow", "Secret Exit Anims", Q_NULLPTR));
        btnAddUnnconnectedPoint->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        btnDeleteUnconnectedPoint->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabIndirectConnections), QApplication::translate("MainWindow", "Indirect Connections", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Position", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "x:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "y:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "z:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabPoints), QApplication::translate("MainWindow", "Points", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nothing to see here!", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabPaths), QApplication::translate("MainWindow", "Paths", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
