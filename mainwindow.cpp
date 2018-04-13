#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include <QMessageBox>
#include <QFileDialog>
#include <QSysInfo>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir yolum("/usr/share/plymouth/themes/");
    yolum.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    temalar = yolum.entryList();
    ui->listWidget->addItems(temalar);
    ui->comboBox->addItems(temalar);
    ui->isletimsistemi->setText("İşletim Sisteminiz:"+ QSysInfo::productType());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listelebuton_clicked()
{
    QDir yolum("/usr/share/plymouth/themes/");
    yolum.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    temalar = yolum.entryList();
    ui->listWidget->clear();
    ui->listWidget->addItems(temalar);
    ui->comboBox->clear();
    ui->comboBox->addItems(temalar);
    QMessageBox::information(this, "Aylinux Plymouth","Tema listesi güncellendi.");
}


void MainWindow::on_commandLinkButton_clicked()
{
    /* Tema kurulumu */
    QString tema = ui->comboBox->currentText();
    ui->progressBar->setValue(20);
    ui->label_5->setPixmap(QPixmap("/opt/Aylinux-Plymouth/resimler/" + tema + ".png") );
    ui->progressBar->setValue(30);
    QString girisyoneticisi = ui->comboBox_2->currentText();
    ui->progressBar->setValue(40);
    QProcess::execute("sudo systemctl enable " + girisyoneticisi + "-plymouth.service ");
    ui->progressBar->setValue(50);
    QProcess::execute("sudo plymouth-set-default-theme -R " + tema);
    ui->progressBar->setValue(100);
    QMessageBox::information(this, "Aylinux Plymouth", tema + " teması Başarıyla Kuruldu.");
    ui->progressBar->setValue(0);
    }
    /* cok elzem degil ama sync() cogu zaman faydalidir */
    /* usb flash bellegi serbest birakalim */
void MainWindow::on_commandLinkButton_2_clicked()
{
    QMessageBox::information(this, "Aylinux Plymouth","Cihan Alkan tarafından Aylinux için hazırlanmıştır.");

}

void MainWindow::on_comboBox_currentTextChanged(const QString)
{
    ui->label_5->setPixmap("/opt/Aylinux-Plymouth/resimler/" + ui->comboBox->currentText() + ".png");
}

void MainWindow::on_commandLinkButton_3_clicked()
{
     QProcess::execute("sudo plymouthd");
     QMessageBox::information(this, "Aylinux Plymouth"," Ctrl+Alt+F7 ile geri dönebilirsiniz.");
     QProcess::execute("sudo plymouth --show-splash");
     QMessageBox::information(this, "Aylinux Plymouth", " Tema testi sona erdi.");
     QProcess::execute("sudo plymouth --quit");
}
