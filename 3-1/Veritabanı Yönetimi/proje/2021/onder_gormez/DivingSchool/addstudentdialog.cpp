#include "addstudentdialog.h"
#include "ui_addstudentdialog.h"
#include <QDebug>

AddStudentDialog::AddStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AddStudentDialog::onButtonBoxAccepted);
}

AddStudentDialog::~AddStudentDialog()
{
    delete ui;
}


void AddStudentDialog::onButtonBoxAccepted()
{
    qDebug() << "Merhaba";
}
