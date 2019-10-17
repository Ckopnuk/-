#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->showReaderEdit->hide();

    connect(ui->showEditBtn, &QPushButton::clicked, ui->showReaderEdit, &QLineEdit::clear);
    connect(ui->showEditBtn, &QPushButton::clicked, ui->showReaderEdit, &QLineEdit::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newReaderFileEdit_editingFinished()
{
    QString name = ui->newReaderFileEdit->text();
    QSet<QString> readerBook;
    ReadersMap.insert(name, readerBook);
    ui->newReaderFileEdit->clear();
}

void MainWindow::on_showReaderEdit_editingFinished()
{
    fileName = ui->showReaderEdit->text();
    //ui->showReaderEdit->clear();
    ui->showReaderEdit->hide();
    if (ReadersMap.find(fileName) != ReadersMap.end())
    {
        ui->textEdit->setText("Reader File: " + fileName);
        QList<QString> list = ReadersMap.value(fileName).values();
        ui->textEdit->append("he has books: ");
        for (int i = 0; i < ReadersMap.value(fileName).size(); i++) {
            ui->textEdit->append(list.takeLast());
        }
    }
}

void MainWindow::on_newBookEdit_editingFinished()
{
    QString nameTmp = ui->newBookEdit->text();
    ui->newBookEdit->clear();
    Books.insert(nameTmp);
}

void MainWindow::on_addBookEdit_editingFinished()
{
    QString nameTmp = ui->addBookEdit->text();
    ui->addBookEdit->clear();
    if (Books.find(nameTmp) != Books.end())
    {
        ReadersMap.find(fileName).value().insert(nameTmp);
    }
}

void MainWindow::on_allBooksBtn_clicked()
{
    ui->textEdit->setText("We have books: ");
    auto list = Books.values();
    for (int i = 0; i < Books.size(); i++) {
        ui->textEdit->append(list.takeLast());
    }
}

void MainWindow::on_allReadersBtn_clicked()
{
    ui->textEdit->setText("This is all readers:");
    QList<QString> listn = ReadersMap.keys();
    for (int i = 0; i < ReadersMap.size(); i++) {
        ui->textEdit->append(listn.takeLast());
    }
}

void MainWindow::on_delBookEdit_editingFinished()
{
    QString nameTmp = ui->delBookEdit->text();
    ui->delBookEdit->clear();
    if (ReadersMap.find(fileName).value().find(nameTmp) != ReadersMap.find(fileName).value().end()) {
        ReadersMap.find(fileName).value().remove(nameTmp);
    }

}

void MainWindow::on_actionOpen_triggered()
{
    QString fileOpenName = QFileDialog::getOpenFileName();
    if (fileOpenName.isEmpty()) return;
    QFile file(fileOpenName);
    if (!file.open(QFile::ReadOnly)) return;
   // ui->textEdit->setText(file.readAll();
}

void MainWindow::on_actionSeve_triggered()
{
    QString fileSaveName = QFileDialog::getSaveFileName();
    if (fileSaveName.isEmpty()) return;
    QFile file(fileSaveName);
    if (!file.open(QFile::WriteOnly)) return;
   // file.write(this);
}
