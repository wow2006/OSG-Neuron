/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 27 17:06:09 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRest;
    QAction *actionPreference;
    QAction *actionAbout_Us;
    QAction *actionHelp;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_StudyLoad;
    QPushButton *pushButton_StudyReset;
    QSpinBox *spinBox_StudySpeed;
    QLabel *label;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_SimLoad;
    QPushButton *pushButton_SimReset;
    QSpinBox *spinBox_SimSpeed;
    QLabel *label_2;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_7;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QLineEdit *lineEdit_preNeuron;
    QLabel *label_13;
    QLabel *label_10;
    QLineEdit *lineEdit_Start;
    QPushButton *pushButton_Genrate;
    QLineEdit *lineEdit_numNeuron;
    QLabel *label_11;
    QLineEdit *lineEdit_numTime;
    QLineEdit *lineEdit_End;
    QLabel *label_12;
    QLabel *label_14;
    QPushButton *pushButton_Save;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *GLWidget;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeNeuron;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Play;
    QSlider *timeSlider;
    QSpinBox *spinBox_Time;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(980, 623);
        actionRest = new QAction(MainWindow);
        actionRest->setObjectName(QString::fromUtf8("actionRest"));
        actionPreference = new QAction(MainWindow);
        actionPreference->setObjectName(QString::fromUtf8("actionPreference"));
        actionAbout_Us = new QAction(MainWindow);
        actionAbout_Us->setObjectName(QString::fromUtf8("actionAbout_Us"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(243, 0));
        tabWidget->setMaximumSize(QSize(150, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 9, 221, 441));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        pushButton_StudyLoad = new QPushButton(verticalLayoutWidget);
        pushButton_StudyLoad->setObjectName(QString::fromUtf8("pushButton_StudyLoad"));

        gridLayout_2->addWidget(pushButton_StudyLoad, 0, 0, 1, 1);

        pushButton_StudyReset = new QPushButton(verticalLayoutWidget);
        pushButton_StudyReset->setObjectName(QString::fromUtf8("pushButton_StudyReset"));

        gridLayout_2->addWidget(pushButton_StudyReset, 2, 0, 1, 1);

        spinBox_StudySpeed = new QSpinBox(verticalLayoutWidget);
        spinBox_StudySpeed->setObjectName(QString::fromUtf8("spinBox_StudySpeed"));
        spinBox_StudySpeed->setValue( 1 );

        gridLayout_2->addWidget(spinBox_StudySpeed, 0, 2, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 221, 441));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        pushButton_SimLoad = new QPushButton(verticalLayoutWidget_2);
        pushButton_SimLoad->setObjectName(QString::fromUtf8("pushButton_SimLoad"));

        gridLayout_3->addWidget(pushButton_SimLoad, 0, 0, 1, 1);

        pushButton_SimReset = new QPushButton(verticalLayoutWidget_2);
        pushButton_SimReset->setObjectName(QString::fromUtf8("pushButton_SimReset"));

        gridLayout_3->addWidget(pushButton_SimReset, 2, 0, 1, 1);

        spinBox_SimSpeed = new QSpinBox(verticalLayoutWidget_2);
        spinBox_SimSpeed->setObjectName(QString::fromUtf8("spinBox_SimSpeed"));
        spinBox_SimSpeed->setValue( 1 );

        gridLayout_3->addWidget(spinBox_SimSpeed, 0, 2, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutWidget_3 = new QWidget(tab_3);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 221, 441));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_4->setHorizontalSpacing(2);
        gridLayout_4->setContentsMargins(10, -1, -1, -1);
        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        lineEdit_preNeuron = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_preNeuron->setObjectName(QString::fromUtf8("lineEdit_preNeuron"));

        gridLayout_4->addWidget(lineEdit_preNeuron, 1, 1, 1, 1);

        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 5, 0, 1, 1);

        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        lineEdit_Start = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_Start->setObjectName(QString::fromUtf8("lineEdit_Start"));

        gridLayout_4->addWidget(lineEdit_Start, 4, 1, 1, 1);

        pushButton_Genrate = new QPushButton(verticalLayoutWidget_3);
        pushButton_Genrate->setObjectName(QString::fromUtf8("pushButton_Genrate"));

        gridLayout_4->addWidget(pushButton_Genrate, 8, 0, 1, 1);

        lineEdit_numNeuron = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_numNeuron->setObjectName(QString::fromUtf8("lineEdit_numNeuron"));

        gridLayout_4->addWidget(lineEdit_numNeuron, 2, 1, 1, 1);

        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 3, 0, 1, 1);

        lineEdit_numTime = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_numTime->setObjectName(QString::fromUtf8("lineEdit_numTime"));

        gridLayout_4->addWidget(lineEdit_numTime, 6, 1, 1, 1);

        lineEdit_End = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_End->setObjectName(QString::fromUtf8("lineEdit_End"));

        gridLayout_4->addWidget(lineEdit_End, 5, 1, 1, 1);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 4, 0, 1, 1);

        label_14 = new QLabel(verticalLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 6, 0, 1, 1);

        pushButton_Save = new QPushButton(verticalLayoutWidget_3);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));

        gridLayout_4->addWidget(pushButton_Save, 8, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 7, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        tabWidget->addTab(tab_3, QString());

        mainLayout->addWidget(tabWidget);

        GLWidget = new QHBoxLayout();
        GLWidget->setSpacing(6);
        GLWidget->setObjectName(QString::fromUtf8("GLWidget"));

        mainLayout->addLayout(GLWidget);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        mainLayout->addItem(horizontalSpacer);

        treeNeuron = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("names"));
        treeNeuron->setHeaderItem(__qtreewidgetitem);
        treeNeuron->setObjectName(QString::fromUtf8("treeNeuron"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeNeuron->sizePolicy().hasHeightForWidth());
        treeNeuron->setSizePolicy(sizePolicy);
        treeNeuron->setMaximumSize(QSize(150, 16777215));

        mainLayout->addWidget(treeNeuron);


        verticalLayout->addLayout(mainLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Stop = new QPushButton(centralWidget);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));

        horizontalLayout_2->addWidget(pushButton_Stop);

        pushButton_Play = new QPushButton(centralWidget);
        pushButton_Play->setObjectName(QString::fromUtf8("pushButton_Play"));

        horizontalLayout_2->addWidget(pushButton_Play);

        timeSlider = new QSlider(centralWidget);
        timeSlider->setObjectName(QString::fromUtf8("timeSlider"));
        timeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(timeSlider);

        spinBox_Time = new QSpinBox(centralWidget);
        spinBox_Time->setObjectName(QString::fromUtf8("spinBox_Time"));

        horizontalLayout_2->addWidget(spinBox_Time);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 980, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionRest);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionPreference);
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_Us);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionRest->setText(QApplication::translate("MainWindow", "Reload", 0, QApplication::UnicodeUTF8));
        actionPreference->setText(QApplication::translate("MainWindow", "Preference", 0, QApplication::UnicodeUTF8));
        actionAbout_Us->setText(QApplication::translate("MainWindow", "About Us", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "To start Study section just click", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Load Button", 0, QApplication::UnicodeUTF8));
        pushButton_StudyLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        pushButton_StudyReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", " Speed:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Study", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "To start Simulate just click Load", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Button to read *.sim file", 0, QApplication::UnicodeUTF8));
        pushButton_SimLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        pushButton_SimReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", " Speed:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Simulation", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "To genrate *.sim file insert data", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "at next empty fields like default", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "num of neurons", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "End with", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Prefix neuron", 0, QApplication::UnicodeUTF8));
        pushButton_Genrate->setText(QApplication::translate("MainWindow", "Genrate", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "ranege of time", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Start with", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "num of take time", 0, QApplication::UnicodeUTF8));
        pushButton_Save->setText(QApplication::translate("MainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Genrator", 0, QApplication::UnicodeUTF8));
        pushButton_Stop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton_Play->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
