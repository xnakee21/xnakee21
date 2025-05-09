#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "adminwindow.h"
#include "userwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    libraryData = LibraryData::getInstance();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString user = ui->usernameEdit->text();
    QString pass = ui->passwordEdit->text();
    bool isAdmin = false;

    if (libraryData->getDataList()->validasiUser(user, pass, isAdmin)) {
        if (isAdmin) {
            AdminWindow *admin = new AdminWindow();
            admin->show();
        } else {
            UserWindow *userWindow = new UserWindow(user);
            userWindow->show();
        }
        this->close();
    } else {
        QMessageBox::warning(this, "Login Gagal", "Username atau password salah.");
    }
}
