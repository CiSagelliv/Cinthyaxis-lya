#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStack>
#include <QMainWindow>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void analiza();
    int estado, columna;
    int relacionaCaracteres(char);
    QString tokens(int);
    QString errores(int);
    char aCaracter;
    QString lexema;
    bool seAgrega(void);
    QList<QString> palabraR;
    void verificarReservada(QString lexema);
    int compara;
    bool esReservada;
    QChar palR;
    bool aCinthyaxis();
    QStack<int> pila;
    int produccion;
    void identificaReservada();
    QString errorSint(int);
    QString filename;
    QString cadena;
    QString gramema(int);
    int afinaToken(int);
    QString mensaje;


private slots:
    void on_actionAbrir_archivo_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
