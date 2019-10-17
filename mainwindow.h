#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newReaderFileEdit_editingFinished();

    void on_showReaderEdit_editingFinished();

    void on_newBookEdit_editingFinished();

    void on_addBookEdit_editingFinished();

    void on_allBooksBtn_clicked();

    void on_allReadersBtn_clicked();

    void on_delBookEdit_editingFinished();

    void on_actionOpen_triggered();

    void on_actionSeve_triggered();

private:
    QString fileName;
    QMap<QString, QSet<QString>> ReadersMap;
    QSet<QString> Books;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
