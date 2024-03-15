#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H

#include <QDialog>

namespace Ui {
class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentDialog(QWidget *parent = nullptr);
    ~AddStudentDialog();

private:
    Ui::AddStudentDialog *ui;

private slots:
    void onButtonBoxAccepted();
};

#endif // ADDSTUDENTDIALOG_H
