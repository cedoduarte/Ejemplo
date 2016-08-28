/**************************************************************************
**
** Author: Carlos Enrique Duarte Ortiz
** Company: DuarteCorporation Tutoriales
** WebPage: https://www.youtube.com/c/duartecorporationtutoriales
**
**************************************************************************/
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_explorarToolButton_clicked()
{
    auto carpeta = QFileDialog::getExistingDirectory(this);
    if (carpeta.isEmpty()) {
        return;
    }
    ui->carpetaLineEdit->setText(carpeta);
    QDir dir(carpeta);
    for (uint x = 0; x < dir.count(); ++x) {
        auto archivo = dir[x];
        if (archivo.endsWith(".dll")) {
            if (archivo.startsWith("lib")) {
                archivo = archivo.mid(3);
            }
            archivo = archivo.mid(0, archivo.size() - QString(".dll").size());
            ui->textBrowser->append("-l" + archivo + " \\");
        }
    }
}
