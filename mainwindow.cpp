#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1920,980);

    ptrRoomAvailableDlg = new RoomAvailableDialog(this);
    ptrCheckOutDlg = new CheckOutDialog(this);
    ptrRoomBookingDlg = new BookRoomDialog(this);
    ptrTransaction = new transaction(this);

    QPixmap pm("C:/Users/admin/Desktop/cpp/Hotel_Management_in_QT/background4.jpg");

    ui->imgLabel->setPixmap(pm);
      ui->imgLabel_2->setPixmap(pm);
    ui->imgLabel->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    qDebug()<<"MainWindow: Deleting";
    delete ui;
    delete ptrRoomBookingDlg;
    delete ptrCheckOutDlg;
    delete ptrRoomAvailableDlg;
    delete ptrTransaction;
}

void MainWindow::on_btnRoomBooking_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": In Room Booking";
    ptrRoomBookingDlg->readData();
    ptrRoomBookingDlg->show();

    if(ptrRoomBookingDlg->isVisible())
        qDebug()<<"New Window is visible";
    else
        qDebug()<<"New Window is not visible";
    //myHotel.BookRoom();
}

void MainWindow::on_btnRoomCheckout_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": In Room Checkout";
    ptrCheckOutDlg->readData();
    ptrCheckOutDlg->show();
}

void MainWindow::on_btnCheckAvailability_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": In Check Availability";
    ptrRoomAvailableDlg->readData();
    ptrRoomAvailableDlg->show();
}

void MainWindow::on_bntTransaction_clicked()
{
    ptrTransaction->readData();
    ptrTransaction->show();
}
