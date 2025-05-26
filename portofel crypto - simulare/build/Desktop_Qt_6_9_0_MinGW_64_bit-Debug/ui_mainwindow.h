/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelBuget;
    QTableWidget *tableWidgetPortofoliu;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxMonede;
    QLabel *label_2;
    QLabel *labelPret;
    QLabel *label_3;
    QLineEdit *lineEditSuma;
    QPushButton *buttonCumpara;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonIstoric;
    QPushButton *buttonExport;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        labelBuget = new QLabel(centralwidget);
        labelBuget->setObjectName("labelBuget");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelBuget->setFont(font);

        verticalLayout->addWidget(labelBuget);

        tableWidgetPortofoliu = new QTableWidget(centralwidget);
        if (tableWidgetPortofoliu->columnCount() < 4)
            tableWidgetPortofoliu->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetPortofoliu->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetPortofoliu->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetPortofoliu->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetPortofoliu->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetPortofoliu->setObjectName("tableWidgetPortofoliu");
        tableWidgetPortofoliu->setColumnCount(4);

        verticalLayout->addWidget(tableWidgetPortofoliu);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxMonede = new QComboBox(groupBox);
        comboBoxMonede->setObjectName("comboBoxMonede");

        gridLayout->addWidget(comboBoxMonede, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        labelPret = new QLabel(groupBox);
        labelPret->setObjectName("labelPret");
        QFont font1;
        font1.setBold(true);
        labelPret->setFont(font1);

        gridLayout->addWidget(labelPret, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEditSuma = new QLineEdit(groupBox);
        lineEditSuma->setObjectName("lineEditSuma");

        gridLayout->addWidget(lineEditSuma, 2, 1, 1, 1);

        buttonCumpara = new QPushButton(groupBox);
        buttonCumpara->setObjectName("buttonCumpara");

        gridLayout->addWidget(buttonCumpara, 3, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonIstoric = new QPushButton(centralwidget);
        buttonIstoric->setObjectName("buttonIstoric");

        horizontalLayout->addWidget(buttonIstoric);

        buttonExport = new QPushButton(centralwidget);
        buttonExport->setObjectName("buttonExport");

        horizontalLayout->addWidget(buttonExport);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Portofel Cripto", nullptr));
        labelBuget->setText(QCoreApplication::translate("MainWindow", "Buget: 10000 RON", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPortofoliu->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Simbol", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetPortofoliu->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Cantitate", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetPortofoliu->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pre\310\233 Unitar", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetPortofoliu->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Valoare Total\304\203", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Cump\304\203r\304\203 Criptomonede", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Selecteaz\304\203 moneda:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pre\310\233 curent:", nullptr));
        labelPret->setText(QCoreApplication::translate("MainWindow", "0.00 RON", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Suma de investit (RON):", nullptr));
        buttonCumpara->setText(QCoreApplication::translate("MainWindow", "Cump\304\203r\304\203", nullptr));
        buttonIstoric->setText(QCoreApplication::translate("MainWindow", "Istoric Tranzac\310\233ii", nullptr));
        buttonExport->setText(QCoreApplication::translate("MainWindow", "Export Portofoliu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
