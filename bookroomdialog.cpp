#include "bookroomdialog.h"
#include "ui_bookroomdialog.h"

BookRoomDialog::BookRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookRoomDialog)
{
    ui->setupUi(this);
    this->setFixedSize(920,620);

}

void BookRoomDialog:: readData()
{
    qDebug()<<"BookRoomDialog:readData";
    std::vector<int>rooms = Hotel::getInstance()->getRoomList("y");
    this->ui->cmbRoomList->clear();

    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        this->ui->cmbRoomList->addItem(QString::number(*it));
    }
}

BookRoomDialog::~BookRoomDialog()
{
    delete ui;
}

void BookRoomDialog::on_btnCancel_clicked()
{
    this->hide();
}

void BookRoomDialog::on_btnSubmit_clicked()
{
    //call hotel's book room
    int  roomno = ui->cmbRoomList->currentText().toInt();
    QString name = ui->txtName->text();
    QString contactno = ui->txtContactNumber->text();
    QString address = ui->txtAddress->toPlainText();
    QString govtid = ui->txtIdProof->text();

    if(roomno < 1)
    {
            QMessageBox::information(
            this,
            tr("Warning!"),
            tr("We are sold out. No room is available") );
            return;
     }

    int ret = Hotel::getInstance()->BookRoom(roomno, name, contactno, govtid, address);

    QString msg = "";
    ret==0?msg="Success!":"Failure!";

    this->hide();

    if(ret == 0)
    {
        QMessageBox::information(
        this,
        tr("Success!"),
        tr("Room has been booked! Please ask for CIN from customer") );
    }
}
