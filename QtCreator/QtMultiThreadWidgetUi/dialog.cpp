#include "boost/thread.hpp"
#include "myboostthread.h"
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);

  mThread = new MyThread(this);
  connect(mThread, SIGNAL(NumberChanged(int)), this,
          SLOT(onNumberChanged(int)));


}

Dialog::~Dialog() { delete ui; }

void Dialog::onNumberChanged(int number) {
  ui->label->setText(QString::number(number));
}

void Dialog::on_pushButton_clicked() {
    mThread->start(); }

void Dialog::on_pushButton_2_clicked() { mThread->Stop = true; }


void Dialog::on_pushButton_run_clicked()
{
    MyBoostThread *mythd = new MyBoostThread();
    mythd->changeNumber = (void(_stdcall *)(int))&changeLabel;

    connect(this, SIGNAL(changeLabel(int)), this, SLOT(onChangeLabel(int)), Qt::QueuedConnection);


    mythd->run();
    //boost::thread _thd(&mythd->run, *mythd);
    //_thd.join();
}

void Dialog::changeLabel(int num){
    int a =0;
    a = 1;
    emit onChangeLabel(num);
}

void Dialog::onChangeLabel(int num){
    int a =0;
    a = 1;
    ui->labelVar1->setText(QString::number(num));
}
