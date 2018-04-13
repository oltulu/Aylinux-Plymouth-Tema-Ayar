#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDir>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_listelebuton_clicked();

    void on_commandLinkButton_clicked();

    void on_listWidget_activated(const QModelIndex &index);

    void on_listelebuton_clicked(bool checked);

    void on_commandLinkButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString);

    void on_commandLinkButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QStringList temalar;
};

#endif // MAINWINDOW_H
