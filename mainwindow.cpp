#include "mainwindow.h"
#include "hakkinda.h"
#include "ui_mainwindow.h"
#include "QFile"
#include <QMessageBox>
#include <QFileDialog>
#include <QSysInfo>
#include <QIcon>
#include <QListWidgetItem>
#include <QIODevice>
#include <QTextStream>
#include <QImage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir yolum("/usr/share/plymouth/themes/");
    yolum.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    QIcon simge("/usr/share/aylinux-plymouth/aylinux.png");
    temalar = yolum.entryList();
    QListWidgetItem *deneme=new QListWidgetItem();
    deneme->setIcon(QIcon("/usr/share/aylinux-plymouth/aylinux.png"));
//    ui->listWidget->addItems(deneme);

    // Add an item to list widget.
    //    QListWidgetItem *item = new QListWidgetItem();
    //    item->setSizeHint(QSize(50, 50));
   // ui->listWidget->addItem(item);

    // ui->listWidget->addItems(deneme,temalar);
    ui->isletimsistemi->setText("İşletim Sisteminiz: "+ QSysInfo::productType());

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
    ui->label_5->setPixmap(QPixmap("/usr/share/aylinux-plymouth/bilgi.png"));
    QMessageBox::information(this, "Aylinux Plymouth","Tema listesi güncellendi.");
}


void MainWindow::on_commandLinkButton_clicked()
{
    if (ui->listWidget->currentItem())

{
    /* Tema kurulumu */
    QString tema = ui->listWidget->currentItem()->text();
    ui->progressBar->setValue(20);
//    ui->label_5->setPixmap(QPixmap("/usr/share/plymouth/themes/" + tema + "/" + tema + ".png") );
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
else
        {
       QMessageBox::information(this, "Aylinux Plymouth"," Lütfen kurmak için bir tema seçiniz");
         }
}
void MainWindow::on_commandLinkButton_2_clicked()
{
    Hakkinda hakkinda;
    hakkinda.setModal(true);
    hakkinda.show();
    hakkinda.exec();
}

void MainWindow::on_commandLinkButton_3_clicked()
{
    if (ui->listWidget->currentItem())
{
    QProcess::execute("mv -f /etc/plymouth/plymouthd.conf /etc/plymouth/plymouthd.yedek");
     QFile confyaz("/etc/plymouth/plymouthd.conf");
    QString tema = ui->listWidget->currentItem()->text();
    std::string str = tema.toStdString();
    const char* secilitema = str.c_str();
 //   QTextStream text_stream(&confyaz);
     if (confyaz.open(QIODevice::WriteOnly)) {
         confyaz.write("#Aylinux Plymount Tema Ayarlama Uygulaması tarafından otomatik oluşturulmuştur.\n");
         confyaz.write("[Daemon]\n");
         confyaz.write("Theme=");
         confyaz.write (secilitema);
         confyaz.write ("\nShowDelay=5");
         confyaz.close();
     }
 QProcess::execute("sudo plymouthd");
     QMessageBox::information(this, "Aylinux Plymouth"," Ctrl+Alt+F7 ile geri dönebilirsiniz.");
     QProcess::execute("sudo plymouth --show-splash");
     QMessageBox::information(this, "Aylinux Plymouth", " Tema testi sona erdi.");
     QProcess::execute("sudo plymouth --quit");
     QProcess::execute("sudo mv -f /etc/plymouth/plymouthd.yedek /etc/plymouth/plymouthd.conf");
}
    else
            {
           QMessageBox::information(this, "Aylinux Plymouth"," Lütfen test etmek için bir tema seçiniz");
             }
    }

void MainWindow::on_listWidget_itemSelectionChanged()
  {
 QFile resimyokmu("/usr/share/plymouth/themes/" + ui->listWidget->currentItem()->text() + "/" + ui->listWidget->currentItem()->text() + ".png");

if(!resimyokmu.exists())
{
    ui->label_5->setPixmap(QPixmap("/usr/share/aylinux-plymouth/resimyok.png"));
}
    else
{
    ui->label_5->setPixmap("/usr/share/plymouth/themes/" + ui->listWidget->currentItem()->text() + "/" + ui->listWidget->currentItem()->text() + ".png");
}
}
