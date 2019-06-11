#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStack>
#include <QMainWindow>

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
    QString acumulador;
    bool seAgrega(void);
    QList<QString> palabraR;
    bool verificarReservada(QString acumulador);
    int compara;
    bool esReservada;
    QChar palR;
    bool aCinthyaxis();
    QStack<int> pila;
    int produccion;
    int identificaReservada();
    QString errorSint(int);
    QString filename;
    QString cadena;

private slots:
    void on_actionAbrir_archivo_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
