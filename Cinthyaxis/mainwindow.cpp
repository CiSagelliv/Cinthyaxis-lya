#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

#ifndef SIMBOLOS
#define SIMBOLOS
    #define PROGRAM 0
    #define DECLARA_LIB 1
    #define DECLARA 2
    #define A 3
    #define AP 4 //AP -> A' 
    #define TIPO 5
    #define ESTATUTOS 6
    #define B 7
    #define EST_ASIG 8
    #define EXPR 9
    #define EXPRP 10 // EXPRP -> EXPR'
    #define EXPR2 11
    #define EXPR2P 12 // EXPR2P -> EXPR2'
    #define EXPR3 13
    #define EXPR4 14
    #define EXPR4P 15 // EXPR4P -> EXPR4'
    #define EXPR5 16
    #define EXPR5P 17 // EXPR5P -> EXPR5'
    #define TERM 18
    #define TERMP 19 // TERMP -> TERM'
    #define FACT 20
    #define OPREL 21
    #define EST_IF 22
    #define EST_IFP 23 // EST_IFP -> EST_IF'
    #define EST_WHILE 24
    #define EST_FOR 25
    #define EST_ENTER 26
    #define EST_WRITE 27
    #define D 28
    #define DP 29 // DP -> D'
    #define EST_READ 30
    #define E 31
    #define EP 32 // EP -> E'
        
    #define RESERVADA 100
    #define CLASS 200
    #define ID 201
    #define BEGIN 202
    #define END 203
    #define IMPORT 204
    #define DEF 205
    #define AS 206
    #define INTEGER 207
    #define FLOAT 208
    #define CHAR 209
    #define STRING 210
    #define BOOLEAN 211
    #define IF 212
    #define ELSE 213
    #define ENDIF 214
    #define WHILE 215
    #define ENDWHILE 216
    #define FOR 217
    #define ENDFOR 218
    #define ENTER 219
    #define WRITE 220
    #define READ 221
    //Aquí faltan las palabras reservadas de librería
    #define ENOF 550
#endif

static int matriz[22][30]= {
    {2,1,4,500,125,2,1,107,108,0,0,0,10,12,109,13,16,17,18,19,21,20,123,124,126,127,128,129,111,509},
    {2,1,2,3,100,2,1,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100},
    {2,2,2,3,101,2,2,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
    {2,2,2,501,2,2,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501},
    {102,102,4,102,5,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102},
    {502,502,6,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502},
    {103,103,6,103,103,7,7,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103},
    {503,503,9,503,503,503,503,8,8,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503},
    {504,504,9,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504},
    {104,104,9,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104},
    {11,11,11,11,11,11,11,11,11,11,11,11,505,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
    {506,506,506,506,506,506,506,506,506,506,506,506,105,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506},
    {12,12,12,12,12,12,12,12,12,12,12,12,12,106,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},
    {110,110,110,110,110,110,110,110,110,110,110,110,110,110,14,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110},
    {14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14},
    {14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,112,14,14,14,14,14,14,14,14,14,14,14,14,14,14},
    {507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,113,507,507,507,507,507,507,507,507,507,507,507,507,507},
    {508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,114,508,508,508,508,508,508,508,508,508,508,508,508},
    {115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,116,115,115,115,115,115,115,115,115,115,115},
    {122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,117,122,122,122,122,122,122,122,122,122,122},
    {118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,119,118,118,118,118,118,118,118,118,118,118},
    {120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,121,120,120,120,120,120,120,120,120,120,120}
    };

static int matrizSint[33][48] = {
    {1,600,600,600,1,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600},
    {3,601,601,601,2,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601},
    {602,5,602,5,602,602,602,602,4,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,5,5,5,5,5,5,5,5,5,5},
    {603,6,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603},
    {604,604,604,604,604,604,604,604,604,8,7,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604},
    {605,605,605,605,605,605,605,605,605,605,605,9,10,11,12,13,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605},
    {606,14,606,15,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,14,15,15,14,15,14,15,14,14,14},
    {607,16,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,17,607,607,18,607,19,607,22,20,20},
    {608,23,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608},
    {609,24,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,24,24,24,24,24,24,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609},
    {610,610,610,610,610,610,26,26,610,610,610,610,610,610,610,610,610,25,610,610,610,610,610,610,610,610,610,610,610,610,610,26,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
    {611,27,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,27,27,27,27,27,27,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611},
    {612,612,612,612,612,612,29,29,612,612,612,612,612,612,612,612,612,29,28,612,612,612,612,612,612,612,612,612,612,612,612,29,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612},
    {613,31,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,30,613,613,613,613,613,31,31,31,31,31,31,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613},
    {614,32,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,32,32,32,32,32,32,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614},
    {615,615,615,615,615,615,34,34,615,615,615,615,615,615,615,615,615,34,34,615,615,615,615,615,615,615,615,615,615,615,615,34,33,33,33,33,33,33,615,615,615,615,615,615,615,615,615,615},
    {616,35,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,35,35,35,35,35,35,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616},
    {617,617,617,617,617,617,38,38,617,617,617,617,617,617,617,617,617,38,38,617,36,37,617,617,617,617,617,617,617,617,617,38,38,38,38,38,38,38,617,617,617,617,617,617,617,617,617,617},
    {618,39,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,39,39,39,39,39,39,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618},
    {619,619,619,619,619,619,43,43,619,619,619,619,619,619,619,619,619,43,43,619,43,43,40,41,42,619,619,619,619,619,619,43,43,43,43,43,43,43,619,619,619,619,619,619,619,619,619,619},
    {620,44,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,45,46,47,48,49,50,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620},
    {621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,621,51,52,53,54,55,56,621,621,621,621,621,621,621,621,621,621},
    {622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,622,57,622,622,622,622,622,622,622,622,622},
    {623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,623,58,59,623,623,623,623,623,623,623},
    {624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,624,60,624,624,624,624,624,624},
    {625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,625,61,625,625,625,625},
    {626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,626,62,626,626},
    {627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,627,63,627},
    {628,64,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,64,64,64,64,64,64,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628,628},
    {629,629,629,629,629,629,629,629,629,629,65,629,629,629,629,629,629,629,629,629,629,629,629,629,629,629,629,629,629,629,629,66,629,629,629,629,629,629,629,629,629,629,629,629,629,629,629,629},
    {630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,630,67},
    {631,68,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631,631},
    {632,632,632,632,632,632,632,632,632,632,69,632,632,632,632,632,632,632,632,632,632,632,632,632,632,632,632,632,632,632,632,70,632,632,632,632,632,632,632,632,632,632,632,632,632,632,632,632}
};

int afinaToken(int);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    estado = 0;
    columna = 0;
    compara = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::analiza(){
    pila.push(ENOF);
    pila.push(PROGRAM);
    for(int i=0;i<cadena.length();i++){
            aCaracter = cadena[i].toLatin1();
            columna = relacionaCaracteres(aCaracter);
            estado = matriz[estado][columna];
        if (estado >= 100 && estado <= 199){
            if (seAgrega()){
                acumulador += QString(aCaracter);
            } else {
                i--;
            }
            verificarReservada(acumulador);
            if (!aCinthyaxis()) return;
            ui->AreaTokens->appendPlainText(tokens(estado));
            estado=0;
            acumulador = "";

        } else if (estado >= 500 && estado <= 550) {
            if (seAgrega()){
                acumulador += QString(aCaracter);
            } else {
                i--;
            }
            ui->AreaErrores->appendPlainText(errores(estado));
            estado=0;
            acumulador = "";
            return;
        } else if (estado > 0 && estado < 100) {
            acumulador += QString(aCaracter);
        }
    }
}

int MainWindow::relacionaCaracteres(char c){
if (c >= '0' && c<= '9'){
    return 2;
}
  switch(c){
//Letras mayusculas
    case 'A': return 0;
    case 'B': return 0;
    case 'C': return 0;
    case 'D': return 0;
    case 'F': return 0;
    case 'G': return 0;
    case 'H': return 0;
    case 'I': return 0;
    case 'J': return 0;
    case 'K': return 0;
    case 'L': return 0;
    case 'M': return 0;
    case 'N': return 0;
    case 'O': return 0;
    case 'P': return 0;
    case 'Q': return 0;
    case 'R': return 0;
    case 'S': return 0;
    case 'T': return 0;
    case 'U': return 0;
    case 'V': return 0;
    case 'W': return 0;
    case 'X': return 0;
    case 'Y': return 0;
    case 'Z': return 0;
//Letras minúsculas
    case 'a': return 1;
    case 'b': return 1;
    case 'c': return 1;
    case 'd': return 1;
    case 'f': return 1;
    case 'g': return 1;
    case 'h': return 1;
    case 'i': return 1;
    case 'j': return 1;
    case 'k': return 1;
    case 'l': return 1;
    case 'm': return 1;
    case 'n': return 1;
    case 'o': return 1;
    case 'p': return 1;
    case 'q': return 1;
    case 'r': return 1;
    case 's': return 1;
    case 't': return 1;
    case 'u': return 1;
    case 'v': return 1;
    case 'w': return 1;
    case 'x': return 1;
    case 'y': return 1;
    case 'z': return 1;
//Signos de puntuación
    case '.': return 4;
    case ';': return 23;
    case ':': return 22;
//Signos de agrupación
    case '(': return 24;
    case')': return 25;
    case '[': return 26;
    case']': return 27;
//Operadores
    case '+': return 7;
    case'-': return 8;
    case '*': return 14;
    case'/': return 15;
    case '%': return 28;
//Operadores relacionales
    case'<': return 20;
    case '>': return 21;
    case'=': return 19;
//Operadores lógicos
    case'&': return 16;
    case '|': return 17;
    case'!': return 18;
//guión bajo, comillas simples y dobles
    case'_': return 3;
    case '\'': return 12;
    case'\"': return 13;
//Notación científica
    case 'E': return 5;
    case 'e': return 6;
//tabulador, espacio en blanco y salto de línea
    case'\n': return 10;
    case'\t': return 11;
    case' ': return 9;
  }
  return 29;

}

QString MainWindow::tokens(int t){
    switch(t){
        case 100:
        return acumulador + ":Palabra reservada";
        case 101:
        return acumulador + ":Identificador";
        case 102:
        return acumulador + ":Constante entera";
        case 103:
        return acumulador + ":Constante real";
        case 104:
        return acumulador + ":Constante con notación cientifica";
        case 105:
        return acumulador + ":Constante caracter";
        case 106:
        return acumulador + ":Constante string";
        case 107:
        return acumulador + ":Suma";
        case 108:
        return acumulador + ":Resta";
        case 109:
        return acumulador + ":Multiplicación";
        case 110:
        return acumulador + ":División";
        case 111:
        return acumulador + ":Módulo";
        case 112:
        return acumulador + ":Comentario";
        case 113:
        return acumulador + ":AND";
        case 114:
        return acumulador + ":OR";
        case 115:
        return acumulador + ":NOT";
        case 116:
        return acumulador + ":Diferente";
        case 117:
        return acumulador + ":Igual";
        case 118:
        return acumulador + ":Mayor";
        case 119:
        return acumulador + ":Mayor o igual";
        case 120:
        return acumulador + ":Menor";
        case 121:
        return acumulador + ":Menor o igual";
        case 122:
        return acumulador + ":Asignación";
        case 123:
        return acumulador + ":Dos puntos";
        case 124:
        return acumulador + ":Punto y coma";
        case 125:
        return acumulador + ":Punto";
        case 126:
        return acumulador + ":Paréntesis que abre";
        case 127:
        return acumulador + ":Paréntesis que cierra";
        case 128:
        return acumulador + ":Llave que abre";
        case 129:
        return acumulador + ":Llave que cierra";
    }
}

QString MainWindow::errores(int e){
    switch(e){
        case 500:
        return acumulador + "" +  "Error 500: no es una constante numérica";
        case 501:
        return acumulador + "" +  "Error 501: esperaba caracter después de _ ";
        case 502:
        return acumulador + "" +  "Error 502: esperaba digito después de .";
        case 503:
        return acumulador + "" +  "Error 503: esperaba digito +, - ";
        case 504:
        return acumulador + "" +  "Error 504: esperaba digito después de signo +,- ";
        case 505:
        return acumulador + "" +  "Error 505: esperaba digito diferente a comilla simple ";
        case 506:
        return acumulador + "" +  "Error 506: esperaba comilla después de caracter ";
        case 507:
        return acumulador + "" +  "Error 507: esperaba signo de & después de & ";
        case 508:
        return acumulador + "" +  "Error 508: esperaba signo de | después de | ";
        case 509:
        return acumulador + "" +  "Error 509: 404 not found ";
    }
}

bool MainWindow::seAgrega(){
    switch(estado){
        case 100: 
          return false;
      //"caracter : Palabra reservada";
        case 101: 
          return false;
      //"caracter: Identificador";
        case 102: 
          return false;
      //"caracter: Constante entera";
        case 103: 
          return false;
      //"caracter: Constante real";
        case 104: 
          return false;
      //"caracter: Constante con notación cientifica";
        case 105: 
          return true;
      //"caracter: Constante caracter";
        case 106: 
          return true;
      //"caracter: Constante string";
        case 107: 
          return true;
      //"caracter: Suma";
        case 108: 
          return true;
      //"caracter: Resta";
        case 109: 
          return true;
      //"caracter: Multiplicación";
        case 110: 
          return false;
      //"caracter: División";
        case 111: 
          return true;
      //"caracter: Módulo";
        case 112: 
          return true;
      //"caracter: Comentario";
        case 113: 
          return true;
      //"caracter: AND";
        case 114: 
          return true;
      //"caracter: OR";
        case 115: 
          return false;
      //"caracter: NOT";
        case 116: 
          return true;
      //"caracter: Diferente";
        case 117: 
          return true;
      //"caracter: Igual";
        case 118: 
          return true;
      //"caracter: Mayor";
        case 119: 
          return true;
      //"caracter: Mayor o igual";
        case 120: 
          return true;
      //"caracter: Menor";
        case 121: 
          return true;
      //"caracter: Menor o igual";
        case 122: 
          return true;
      //"caracter: Asignación";
        case 123: 
          return true;
      //"caracter: Dos puntos";
        case 124: 
          return true;
      //"caracter: Punto y coma";
        case 125: 
          return true;
      //"caracter: Punto";
        case 126: 
          return true;
      //"caracter: Paréntesis que abre";
        case 127: 
          return true;
      //"caracter: Paréntesis que cierra";
        case 128: 
          return true;
      //"caracter: Llave que abre";
        case 129: 
          return true;
      //"caracter: Llave que cierra";
  //aquí empiezan los errores 
        case 500:
          return true; 
      //"Error 500: no es una constante numérica";
        case 501:
          return false;  
      //"Error 501: esperaba caracter después de _ ";
        case 502:
          return false;   
      //"Error 502: esperaba digito después de .";
        case 503:
          return true;   
      //"Error 503: esperaba digito +, - ";
        case 504:
          return false;   
      //"Error 504: esperaba digito después de signo +,- ";
        case 505:
          return false;   
      //"Error 505: esperaba digito diferente a comilla simple ";
        case 506:
          return false;   
      //"Error 506: esperaba comilla después de caracter ";
        case 507:
          return false; 
      //"Error 507: esperaba signo de & después de & ";
        case 508:
          return false;  
      //"Error 508: esperaba signo de | después de | ";
        case 509:
          return true;
      //"Error 509: 404 not found ";
    }
}

bool MainWindow::verificarReservada(QString ac){
    if (estado == 100){
        if ((ac=="begin")||(ac=="end")||(ac=="def")
            ||(ac=="as")||(ac=="integer")||(ac=="float")
            ||(ac=="char")||(ac=="string")||(ac=="boolean")
            ||(ac=="if")||(ac=="else")||(ac=="elseif")
            ||(ac=="endif")||(ac=="for")||(ac=="do")
            ||(ac=="endfor")||(ac=="while")||(ac=="endwhile")
            ||(ac=="function")||(ac=="endfunction")||(ac=="import")
            ||(ac=="null")||(ac=="read")||(ac=="write")
            ||(ac=="enter")||(ac=="principal")||(ac=="lye")||(ac=="io")
            ||(ac=="class")){
                estado = 100;
            } else {
                estado= 101;
            }
       }
}

bool MainWindow::aCinthyaxis(){
    int simbolo = pila.pop();
    if (estado == RESERVADA) identificaReservada();

    while(true){
    if (simbolo == estado){
        return true;
    } else if (simbolo > 100) {
        errorSint(669);
        return false;
    } else {
        columna = afinaToken(estado);
        produccion = matrizSint[simbolo][columna];
        if (produccion > 600){
            errorSint(produccion);
            return false;
        } else {
            //si jala
            // si es un terminal pushear el token y si es un no terminal
            // pushear la fila
            //aquí van cada una de las producciones
            switch (produccion) {
                case 0:
                    pila.push(END);
                break;
                case 50:
                    pila.push(107); //token
                    pila.push(/*aqui va el número de fila*/); //fila

            }
        }
    }
  }

}


int MainWindow::identificaReservada() {
        if(cadena == "class"){
            estado = CLASS;
        }else if /*siguele con los demás*/ {
    }
}

//función pura
int afinaToken(int estado){ //columna
    switch(estado){
        case CLASS:
            return 0;
           break;
            //sigue con los demás
    }
}

QString MainWindow::errorSint(int er){
    switch (er) {
        case 600:
        return acumulador + "" +  "Error 600: 404 not found ";
        case 601:
        return acumulador + "" +  "Error 601: 404 not found ";
        case 602:
        return acumulador + "" +  "Error 602: 404 not found ";
        case 603:
        return acumulador + "" +  "Error 603: 404 not found ";
        case 604:
        return acumulador + "" +  "Error 604: 404 not found ";
        case 605:
        return acumulador + "" +  "Error 605: 404 not found ";
        case 606:
        return acumulador + "" +  "Error 606: 404 not found ";
        case 607:
        return acumulador + "" +  "Error 607: 404 not found ";
        case 608:
        return acumulador + "" +  "Error 608: 404 not found ";
        case 609:
        return acumulador + "" +  "Error 609: 404 not found ";
        case 610:
        return acumulador + "" +  "Error 610: 404 not found ";
        case 611:
        return acumulador + "" +  "Error 611: 404 not found ";
        case 612:
        return acumulador + "" +  "Error 612: 404 not found ";
        case 613:
        return acumulador + "" +  "Error 613: 404 not found ";
        case 614:
        return acumulador + "" +  "Error 614: 404 not found ";
        case 615:
        return acumulador + "" +  "Error 615: 404 not found ";
        case 616:
        return acumulador + "" +  "Error 616: 404 not found ";
        case 617:
        return acumulador + "" +  "Error 617: 404 not found ";
        case 618:
        return acumulador + "" +  "Error 618: 404 not found ";
        case 619:
        return acumulador + "" +  "Error 619: 404 not found ";
        case 620:
        return acumulador + "" +  "Error 620: 404 not found ";
        case 621:
        return acumulador + "" +  "Error 621: 404 not found ";
        case 622:
        return acumulador + "" +  "Error 622: 404 not found ";
        case 623:
        return acumulador + "" +  "Error 623: 404 not found ";
        case 624:
        return acumulador + "" +  "Error 624: 404 not found ";
        case 625:
        return acumulador + "" +  "Error 625: 404 not found ";
        case 626:
        return acumulador + "" +  "Error 626: 404 not found ";
        case 627:
        return acumulador + "" +  "Error 627: 404 not found ";
        case 628:
        return acumulador + "" +  "Error 628: 404 not found ";
        case 629:
        return acumulador + "" +  "Error 629: 404 not found ";
        case 630:
        return acumulador + "" +  "Error 630: 404 not found ";
        case 631:
        return acumulador + "" +  "Error 631: 404 not found ";
        case 632:
        return acumulador + "" +  "Error 632: 404 not found ";
        case 669:
        return acumulador + "" +  "Error 669: No coincidieron ";
    }
}

void MainWindow::on_actionAbrir_archivo_triggered()
{
    filename = QFileDialog::getOpenFileName(
                this,
                "Prueba2 - Abrir archivo",
                "C:/Users/cinth/Documents/Tecnológico/Sexto Semestre/Lenguajes y autómatas/AL/wALson",
                "Text Files (*.eye)");
    if (!filename.isEmpty()){
        QFile file(filename);
        if (file.open(QFile::ReadOnly)){
            cadena = file.readAll()+ " ";
            ui->AreaArchivo->setPlainText(cadena);
        }else {
            QMessageBox::warning(this,
                                 "Advertencia",
                                 tr("No se puede leer el archivo"));
      }
    }
}
