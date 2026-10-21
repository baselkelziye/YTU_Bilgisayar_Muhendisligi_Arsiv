#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "crc.h"

int sceneWidth;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUp();

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 300, 100000);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    sceneWidth = scene->width();
    //this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUp() {
    ui->senderTable->setColumnCount(3);
    ui->senderTable->setHorizontalHeaderLabels(QStringList() << "Frame No" << "Data" << "CRC");
    ui->senderTable->setRowCount(0);
    ui->senderTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->receiverTable->setColumnCount(3);
    ui->receiverTable->setHorizontalHeaderLabels(QStringList() << "Frame No" << "Data" << "CRC");
    ui->receiverTable->setRowCount(0);
    ui->receiverTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_fileButton_clicked()
{
    loadedFilePath = QFileDialog::getOpenFileName(this, "Select .dat file", "", "DAT Files (*.dat)");
    if (loadedFilePath.isEmpty()) {
        QMessageBox::warning(this, "No File", "No .dat file selected. Please select a file!");
        //close();
        return;
    }

    simulate();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    exit(0);
}

void delay(int milliseconds) {
    QTime dieTime = QTime::currentTime().addMSecs(milliseconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

void MainWindow::simulate() {
    QFile file(loadedFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open selected file.");
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    if (data.size() == 0) {
        QMessageBox::warning(this, "File Empty", "File is empty!");
        return;
    }

    ui->senderTable->setRowCount(0);
    ui->receiverTable->setRowCount(0);

    ui->senderChecksumLabel->setText("");
    ui->receiverChecksumLabel->setText("");

    scene->clear();
    ui->graphicsView->verticalScrollBar()->setValue(0);
    ui->graphicsView->setSceneRect(scene->itemsBoundingRect());

    uint16_t senderChecksum = 0;
    uint16_t receiverChecksum = 0;
    uint8_t carry = 0;

    const int frameSize = 13;
    int i = 0;
    int frame = 0;
    int transmissionCount = 0;

    int y = 20;
    int delayTime = data.size() / 20;

    for (; i < data.size() + 1;) {
        int startPos = i;
        int bytesRead = 0;
        uint16_t senderCRC = 0x0000;
        uint16_t receiverCRC = 0x0000;
        QString senderDataHex = "0x";
        QString receiverDataHex = "0x";
        QByteArray frameData;

        delay((delayTime / (transmissionCount + 1)) + 1);

        // Gönderici CRC hesaplaması
        if (frame % 2 == 1) {
            senderDataHex += QString::number(carry, 16).toUpper();
            senderCRC = Compute_CRC16(carry, senderCRC, 8);
        }

        while (bytesRead < 12 && i < data.size()) {
            uint8_t byte = static_cast<uint8_t>(data[i++]);
            senderDataHex += QString("%1").arg(byte, 2, 16, QLatin1Char('0')).toUpper();
            frameData.append(byte);
            senderCRC = Compute_CRC16(byte, senderCRC, 8);
            bytesRead++;
        }

        if (frame % 2 == 0 && i < data.size()) {
            uint8_t byte = static_cast<uint8_t>(data[i++]);
            carry = byte & 0x0F;
            uint8_t high = byte >> 4;
            frameData.append(high);
            senderDataHex += QString::number(high, 16).toUpper();
            senderCRC = Compute_CRC16(high, senderCRC, 4);
            bytesRead++;
        }


        // Gönderici tablosuna ilgili değerleri ekle
        QString senderCRCStr = QString("0x") + QString("%1").arg(senderCRC, 4, 16, QLatin1Char('0')).toUpper();

        ui->senderTable->insertRow(transmissionCount);
        ui->senderTable->setItem(transmissionCount, 0, new QTableWidgetItem(QString("Frame %1").arg(frame + 1)));
        ui->senderTable->setItem(transmissionCount, 1, new QTableWidgetItem(senderDataHex));
        ui->senderTable->setItem(transmissionCount, 2, new QTableWidgetItem(senderCRCStr));
        ui->senderTable->scrollToBottom();

        // Alıcı, göndericinin dosyadan okuduğu değerlerin kopyasını alır.
        QByteArray receivedFrame = frameData;

        QString senderStr;
        QString receiverStr;
        QString infoStr;

        int rate = QRandomGenerator::global()->bounded(100);
        if (rate < 10) { // Data Lost
            ui->receiverTable->insertRow(transmissionCount);
            ui->receiverTable->setItem(transmissionCount, 0, new QTableWidgetItem(QString("Frame %1").arg(frame + 1)));
            ui->receiverTable->setItem(transmissionCount, 1, new QTableWidgetItem(QString("0x??????????????????????????????")));
            ui->receiverTable->setItem(transmissionCount, 2, new QTableWidgetItem(QString("0x????")));
            ui->receiverTable->scrollToBottom();

            senderStr = QString("------------ Frame %1 ------------> X").arg(frame+1);
            QGraphicsTextItem* frameText = scene->addText(senderStr);
            frameText->setDefaultTextColor(Qt::red);
            frameText->setPos((sceneWidth - frameText->boundingRect().width()) / 2.0, y);

            receiverStr = QString("<------------ ACK %1 ------------").arg(frame+1);
            QGraphicsTextItem* ackText = scene->addText(receiverStr);
            ackText->setDefaultTextColor(Qt::yellow);
            ackText->setPos((sceneWidth - ackText->boundingRect().width()) / 2.0, y + 15);

            infoStr = QString("(Data Lost)");
            QGraphicsTextItem* infoText = scene->addText(infoStr);
            infoText->setPos((sceneWidth - infoText->boundingRect().width()) / 2.0, y + 30);

            y += 65;
            transmissionCount++;
            i = startPos;
            continue;
        } else if (rate < 30 && receivedFrame.size() > 0) { // Data Changed
            int index = QRandomGenerator::global()->bounded(receivedFrame.size());
            uint8_t random = (uint8_t) QRandomGenerator::global()->bounded(256);
            receivedFrame[index] ^= random;

            senderStr = QString("------------ Frame %1 ------------>").arg(frame+1);
            QGraphicsTextItem* frameText = scene->addText(senderStr);
            frameText->setPos((sceneWidth - frameText->boundingRect().width()) / 2.0, y);

            receiverStr = QString("<------------ ACK %1 ------------").arg(frame+1);
            QGraphicsTextItem* ackText = scene->addText(receiverStr);
            ackText->setDefaultTextColor(Qt::yellow);
            ackText->setPos((sceneWidth - ackText->boundingRect().width()) / 2.0, y + 15);

            infoStr = QString("(Data Corrupted)");
            QGraphicsTextItem* infoText = scene->addText(infoStr);
            infoText->setPos((sceneWidth - infoText->boundingRect().width()) / 2.0, y + 30);

            y += 65;
        } else if (rate < 45) { // ACK Lost
            senderStr = QString("------------ Frame %1 ------------>").arg(frame+1);
            QGraphicsTextItem* frameText = scene->addText(senderStr);
            frameText->setPos((sceneWidth - frameText->boundingRect().width()) / 2.0, y);

            receiverStr = QString("X <------------ ACK %1 ------------").arg(frame+2);
            QGraphicsTextItem* ackText = scene->addText(receiverStr);
            ackText->setDefaultTextColor(Qt::red);
            ackText->setPos((sceneWidth - ackText->boundingRect().width()) / 2.0, y + 15);

            infoStr = QString("(ACK Lost)");
            QGraphicsTextItem* infoText = scene->addText(infoStr);
            infoText->setPos((sceneWidth - infoText->boundingRect().width()) / 2.0, y + 30);

            y += 65;
        } else {
            senderStr = QString("------------ Frame %1 ------------>").arg(frame+1);
            QGraphicsTextItem* frameText = scene->addText(senderStr);
            frameText->setPos((sceneWidth - frameText->boundingRect().width()) / 2.0, y);

            receiverStr = QString("<------------ ACK %1 ------------").arg(frame+2);
            QGraphicsTextItem* ackText = scene->addText(receiverStr);
            ackText->setDefaultTextColor(Qt::green);
            ackText->setPos((sceneWidth - ackText->boundingRect().width()) / 2.0, y + 15);
            y += 50;
        }


        // Alıcı CRC hesaplaması
        if (frame % 2 == 1) {
            receiverDataHex += QString::number(carry, 16).toUpper();
            receiverCRC = Compute_CRC16(carry, receiverCRC, 8);
        }

        for (int j = 0; j < receivedFrame.size() - 1; ++j) {
            uint8_t byte = static_cast<uint8_t>(receivedFrame[j]);
            receiverDataHex += QString("%1").arg(byte, 2, 16, QLatin1Char('0')).toUpper();
            receiverCRC = Compute_CRC16(byte, receiverCRC, 8);
        }

        if (frame % 2 == 0 && receivedFrame.size() == frameSize) { //frame tamsa
            uint8_t byte = static_cast<uint8_t>(receivedFrame[receivedFrame.size() - 1]);
            receiverDataHex += QString::number(byte, 16).toUpper();
            receiverCRC = Compute_CRC16(byte, receiverCRC, 4);
        } else if (receivedFrame.size() > 0){
            uint8_t byte = static_cast<uint8_t>(receivedFrame[receivedFrame.size() - 1]);
            receiverDataHex += QString("%1").arg(byte, 2, 16, QLatin1Char('0')).toUpper();
            receiverCRC = Compute_CRC16(byte, receiverCRC, 8);
        }

        //if (senderDataHex.size() != receiverDataHex.size()) {qDebug() << frame+1 << senderDataHex.size() << receiverDataHex.size();}
        //qDebug() << "receivedFrame.size():" << receivedFrame.size() << "received crc:" << receiverCRC << "sender crc:" << senderCRC;


        QString receiverCRCStr = QString("0x") + QString("%1").arg(receiverCRC, 4, 16, QLatin1Char('0')).toUpper();

        // Alıcı tablosuna ilgili değerleri ekle
        ui->receiverTable->insertRow(transmissionCount);
        ui->receiverTable->setItem(transmissionCount, 0, new QTableWidgetItem(QString("Frame %1").arg(frame + 1)));
        ui->receiverTable->setItem(transmissionCount, 1, new QTableWidgetItem(receiverDataHex));
        ui->receiverTable->setItem(transmissionCount, 2, new QTableWidgetItem(receiverCRCStr));
        ui->receiverTable->scrollToBottom();

        // CRC uyuşmuyorsa frame'i tekrar gönder
        if (senderCRC == receiverCRC && rate >= 45) {
            frame++;
            senderChecksum += senderCRC;
            receiverChecksum += receiverCRC;

            // Dosya sonuna gelindiyse ve carry yoksa ++i ile i < data.size() + 1'in sağlanması engellenir.
            // Carry varsa ++i yapılmaz ve bir tur daha döngü çalışarak carry'nin CRC kodu hesaplanır.
            if (i >= data.size() && bytesRead < frameSize) {
                ++i;
            }
        } else {
            i = startPos;
        }

        ui->graphicsView->ensureVisible(scene->itemsBoundingRect());
        transmissionCount++;
    }

    QGraphicsTextItem* text = scene->addText(QString("--------------- Checksum --------------->"));
    text->setPos((sceneWidth - text->boundingRect().width()) / 2.0, y);

    QString senderSum = QString("Sent Checksum: 0x") + QString("%1").arg((~senderChecksum + 1) & 0xFFFF, 4, 16, QLatin1Char('0')).toUpper();
    ui->senderChecksumLabel->setText(senderSum);

    int rate = QRandomGenerator::global()->bounded(100);
    if (rate < 5) {
        uint16_t random = (uint16_t) QRandomGenerator::global()->bounded(65536);
        senderChecksum ^= random;

        QString receiverSum =  QString("Received Checksum: 0x") + QString("%1").arg((~senderChecksum + 1) & 0xFFFF, 4, 16, QLatin1Char('0')).toUpper();
        ui->receiverChecksumLabel->setText(receiverSum);

        text->setDefaultTextColor(Qt::red);
        QGraphicsTextItem* checksumText = scene->addText(QString("(Checksum Corrupted)"));
        checksumText->setPos((sceneWidth - checksumText->boundingRect().width()) / 2.0, y + 15);
        delay(5); // Last one cannot show
        ui->graphicsView->ensureVisible(scene->itemsBoundingRect());
        QMessageBox::warning(this, "Checksum Error", QString("Checksums did not match. Data transmission has failed.\n\nReceived: 0x%1\nCalculated: 0x%2")
                .arg(QString::number((~senderChecksum + 1) & 0xFFFF, 16).toUpper(),
                     QString::number((~receiverChecksum + 1) & 0xFFFF, 16).toUpper())
            );
    } else {
        text->setDefaultTextColor(Qt::green);

        QString receiverSum =  QString("Received Checksum: 0x") + QString("%1").arg((~senderChecksum + 1) & 0xFFFF, 4, 16, QLatin1Char('0')).toUpper();
        ui->receiverChecksumLabel->setText(receiverSum);

        delay(5);
        ui->graphicsView->ensureVisible(scene->itemsBoundingRect());
        QMessageBox::information(this, "Transmission Successfull", "Checksums verified. Data transmission completed successfully.");
    }
}
