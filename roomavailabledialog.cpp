#include "roomavailabledialog.h"
#include "ui_roomavailabledialog.h"
#include <QDebug>

RoomAvailableDialog::RoomAvailableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomAvailableDialog)
{
    ui->setupUi(this);
    this->setFixedSize(920,620);
    qDebug()<<"In RoomAvailableDialog()";

}

void RoomAvailableDialog::readData()
{
    qDebug()<<"in readData()";

    std::vector<int>rooms = Hotel::getInstance()->getRoomList("y");
    ui->lblinfo->setStyleSheet("QLabel { background-color : black; color : rgb(0, 150, 0); }");

    std::vector<int>temprooms =  {101, 102, 103, 104, 105, 201, 202, 203, 204, 205};

    //set default color to all
    for(std::vector<int>::iterator it = temprooms.begin(); it!=temprooms.end(); it++ )
    {
        //Put logic to change color of Labels
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            ptr->setStyleSheet("QLabel { background-color : black; color : red; }");
        }

    }

    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        //Put logic to change color of Labels
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            //pLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");

            ptr->setStyleSheet("QLabel { background-color : black; color : rgb(0, 150, 0); }");
        }

    }
}

RoomAvailableDialog::~RoomAvailableDialog()
{
    qDebug()<<"Deleting RoomAvailableDialog";
    delete ui;
}

void RoomAvailableDialog::on_pushButton_clicked()
{
    this->hide();
}
