#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "librarydata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_tambahBukuButton_clicked();
    void on_hapusBukuButton_clicked();
    void on_cariBukuButton_clicked();
    void on_resetBukuButton_clicked();
    void on_tambahUserButton_clicked();
    void on_hapusUserButton_clicked();
    void on_resetUserButton_clicked();
    void on_refreshPeminjamanButton_clicked();

private:
    Ui::AdminWindow *ui;
    LibraryData* libraryData;
};

#endif // ADMINWINDOW_H
