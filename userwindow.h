#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include "librarydata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserWindow; }
QT_END_NAMESPACE

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    UserWindow(QString username, QWidget *parent = nullptr);
    ~UserWindow();

private slots:
    void on_searchButton_clicked();
    void on_resetSearchButton_clicked();
    void on_pinjamBukuButton_clicked();
    void on_refreshPinjamButton_clicked();

private:
    Ui::UserWindow *ui;
    LibraryData* libraryData;
    QString currentUser;
};

#endif // USERWINDOW_H
