#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QScrollBar>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fileButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QString loadedFilePath;

    void closeEvent(QCloseEvent *event) override;
    void setUp();
    void requestFile();
    void simulate();
};
#endif // MAINWINDOW_H
