#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#ifndef SIMBOLOS
#define SIMBOLOS
    //Aqui van las producciones
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

    //Palabras reservadas        
    #define CLASS 200
    #define BEGIN 201
    #define END 202
    #define IMPORT 203
    #define DEF 204
    #define AS 205
    #define INTEGER 206
    #define FLOTANTE 207
    #define CARACTER 208
    #define STRING 209
    #define BOOLEANO 210
    #define IF 211
    #define ELSE 212
    #define ENDIF 213
    #define WHILE 214
    #define ENDWHILE 215
    #define FOR 216
    #define ENDFOR 217
    #define ENTER 218
    #define WRITE 219
    #define READ 220
    #define LYE 221
    #define ENOF 550
    
        //tokens 
    #define RESERVADA 100
    #define IDENTIFICADOR 101
    #define CONST_ENTERA 102
    #define CONST_REAL 103
    #define CONST_NOTACION 104
    #define CONST_CARACTER 105
    #define CONST_STRING 106
    #define SUMA 107
    #define RESTA 108
    #define MULTIPLICACION 109
    #define DIVISION 110
    #define MODULO 111
    #define COMENTARIO 112
    #define AND 113
    #define OR 114
    #define NOT 115
    #define DIFERENTE 116
    #define IGUAL 117
    #define MAYOR 118
    #define MAYOR_IGUAL 119
    #define MENOR 120
    #define MENOR_IGUAL 121
    #define ASIGNACION 122
    #define DOS_PUNTOS 123
    #define PUNTO_COMA 124
    #define PUNTO 125
    #define PARENTESIS_ABRE 126
    #define PARENTESIS_CIERRA 127
    #define LLAVE_ABRE 128
    #define LLAVE_CIERRA 129
    #define ID_LIBRERIA 130
    #define COMA 131
#endif

static int matriz[25][32]= {
    {2,   1,   4,   500, 125, 2,   1,   1,   1,   107, 108, 0,   0,   0,   10,  12,  109, 13,  16,  17,  18,  19,  21,  20,  123, 124, 126, 127, 128, 129, 111, 131},   
    {2,   1,   2,   3,   22,  2,   1,   1,   1,   100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
    {2,   2,   2,   3,   101, 2,   2,   2,   2,   101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101},
    {2,   2,   2,   501, 501, 2,   2,   2,   2,   501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501},
    {102, 102, 4,   102, 5,   102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102},
    {502, 502, 6,   502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502},
    {103, 103, 6,   103, 103, 7,   7,   103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103},
    {503, 503, 9,   503, 503, 503, 503, 503, 503, 8,   8,   503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503},
    {504, 504, 9,   504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504},
    {104, 104, 9,   104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104},
    {11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  505, 11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11, 11},
    {506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 105, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506, 506},
    {12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  106, 12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12,  12, 12},
    {110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 14,  110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110},
    {14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  15,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14, 14},
    {14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  15,  112, 14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14,  14, 14},
    {507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 113, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507},
    {508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 114, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508, 508},
    {115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 116, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115},
    {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 117, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
    {118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 119, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118},
    {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 121, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120},
    {510, 131, 510, 510, 510, 510, 510, 23,  510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510},
    {510, 510, 510, 510, 510, 510, 510, 510, 24,  510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510},
    {510, 510, 510, 510, 510, 510, 130, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510, 510}
    };

static int matrizSint[33][48] = {
    {1,   600, 600, 600, 1,   600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600},
    {3,   601, 601, 601, 2,   601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601, 601},
    {602, 4,   602, 5,   602, 602, 602, 602, 4,   602, 4,   602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 602, 5,   5,   5,   5,   5,   5,   5,   5,   5,   5},
    {603, 6,   603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603, 603},
    {604, 604, 604, 604, 604, 604, 604, 604, 604, 8,   7,   604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604},
    {605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 9,   10,  11,  12,  13,  605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605, 605},
    {606, 14,  606, 15,  606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 606, 14,  15,  15,  14,  15,  14,  15,  14,  14,  14},
    {607, 16,  607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 607, 17,  607, 607, 18,  607, 19,  607, 22,  21,  20},
    {608, 23,  608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608, 608},
    {609, 24,  609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 24,  24,  24,  24,  24,  24,  609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609, 609},
    {610, 610, 610, 610, 610, 610, 26,  26,  610, 610, 26, 610, 610, 610, 610, 610, 610, 25,  610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 26,  610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610, 610},
    {611, 27,  611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 27,  27,  27,  27,  27,  27,  611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611, 611},
    {612, 612, 612, 612, 612, 612, 29,  29,  612, 612, 29, 612, 612, 612, 612, 612, 612, 29,  28,  612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 29,  612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 612, 612},
    {613, 31,  613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 30,  613, 613, 613, 613, 613, 31,  31,  31,  31,  31,  31,  613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613, 613},
    {614, 32,  614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 32,  32,  32,  32,  32,  32,  614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614},
    {615, 615, 615, 615, 615, 615, 34,  34,  615, 615, 34, 615, 615, 615, 615, 615, 615, 34,  34,  615, 615, 615, 615, 615, 615, 615, 615, 615, 615, 615, 615, 34,  33,  33,  33,  33,  33,  33,  615, 615, 615, 615, 615, 615, 615, 615, 615, 615},
    {616, 35,  616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 35,  35,  35,  35,  35,  35,  616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616, 616},
    {617, 617, 617, 617, 617, 617, 38,  38,  617, 617, 38, 617, 617, 617, 617, 617, 617, 38,  38,  617, 36,  37,  617, 617, 617, 617, 617, 617, 617, 617, 617, 38,  38,  38,  38,  38,  38,  38,  617, 617, 617, 617, 617, 617, 617, 617, 617, 617},
    {618, 39,  618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 39,  39,  39,  39,  39,  39,  618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618, 618},
    {619, 619, 619, 619, 619, 619, 43,  43,  619, 619, 43, 619, 619, 619, 619, 619, 619, 43,  43,  619, 43,  43,  40,  41,  42,  619, 619, 619, 619, 619, 619, 43,  43,  43,  43,  43,  43,  43,  619, 619, 619, 619, 619, 619, 619, 619, 619, 619},
    {620, 44,  620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 45,  46,  47,  48,  49,  50,  620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620, 620},
    {621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 621, 51,  52,  53,  54,  55,  56,  621, 621, 621, 621, 621, 621, 621, 621, 621, 621},
    {622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 622, 57,  622, 622, 622, 622, 622, 622, 622, 622, 622},
    {623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 623, 58,  59,  623, 623, 623, 623, 623, 623, 623},
    {624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 624, 60,  624, 624, 624, 624, 624, 624},
    {625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 625, 61,  625, 625, 625, 625},
    {626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 626, 62,  626, 626},
    {627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 627, 63,  627},
    {628, 64,  628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 64,  64,  64,  64,  64,  64,  628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628, 628},
    {629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 65,  629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 66,  629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629, 629},
    {630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 630, 67},
    {631, 68,  631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631, 631},
    {632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 69,  632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 70,  632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632, 632}
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
            std::cout << std::to_string(estado) << std::endl;
        if (estado >= 100 && estado <= 199){
            if (seAgrega()){
                lexema += QString(aCaracter);
            } else {
                i--;
            }
            verificarReservada(lexema);
            std::cout << lexema.toStdString() << std::endl;
            ui->AreaTokens->appendPlainText(tokens(estado));
            bool valido = aCinthyaxis();
            std::cout << "Fue valido?: " + std::to_string(valido) << std::endl;
            if (!valido) return;
            estado=0;
            lexema = "";

        } else if (estado >= 500 && estado <= 550) {
            if (seAgrega()){
                lexema += QString(aCaracter);
            } else {
                i--;
            }
            ui->AreaErrores->appendPlainText(errores(estado));
            estado=0;
            lexema = "";
            return;
        } else if (estado > 0 && estado < 100) {
            lexema += QString(aCaracter);
        }
    }
    if (pila.first() == ENOF){
        QMessageBox jalo;
        jalo.setText("Se llego al final de la pila, end of file encontrado");
        jalo.exec();
        std::cout << "Si jalo" << std::endl;
    }else {
        QMessageBox Nojalo;
        Nojalo.setText("No se llego al final de la pila, end of file no encontrado");
        Nojalo.exec();
        std::cout << "Algo falto" << std::endl;
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
    case 'l': return 7;
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
    case 'y': return 8;
    case 'z': return 1;
//Signos de puntuación
    case '.': return 4;
    case ',': return 31; //Aquí agregué la coma 
    case ';': return 25;
    case ':': return 24;
//Signos de agrupación
    case '(': return 26;
    case')': return 27;
    case '[': return 28;
    case']': return 29;
//Operadores
    case '+': return 9;
    case'-': return 10;
    case '*': return 16;
    case'/': return 15;
    case '%': return 30;
//Operadores relacionales
    case'<': return 22;
    case '>': return 23;
    case'=': return 21;
//Operadores lógicos
    case'&': return 18;
    case '|': return 19;
    case'!': return 20;
//guión bajo, comillas simples y dobles
    case'_': return 3;
    case '\'': return 17;
    case'\"': return 15;
//Notación científica
    case 'E': return 5;
    case 'e': return 6;
//tabulador, espacio en blanco y salto de línea
    case'\n': return 12;
    case'\t': return 13;
    case' ': return 11;
  }
  return 32;

}

QString MainWindow::tokens(int t){
    switch(t){
        case RESERVADA:
        return lexema + ":Palabra reservada";
        case IDENTIFICADOR:
        return lexema + ":Identificador";
        case CONST_ENTERA:
        return lexema + ":Constante entera";
        case CONST_REAL:
        return lexema + ":Constante real";
        case CONST_NOTACION:
        return lexema + ":Constante con notación cientifica";
        case CONST_CARACTER:
        return lexema + ":Constante caracter";
        case CONST_STRING:
        return lexema + ":Constante string";
        case SUMA:
        return lexema + ":Suma";
        case RESTA:
        return lexema + ":Resta";
        case MULTIPLICACION:
        return lexema + ":Multiplicación";
        case DIVISION:
        return lexema + ":División";
        case MODULO:
        return lexema + ":Módulo";
        case COMENTARIO:
        return lexema + ":Comentario";
        case AND:
        return lexema + ":AND";
        case OR:
        return lexema + ":OR";
        case NOT:
        return lexema + ":NOT";
        case DIFERENTE:
        return lexema + ":Diferente";
        case IGUAL:
        return lexema + ":Igual";
        case MAYOR:
        return lexema + ":Mayor";
        case MAYOR_IGUAL:
        return lexema + ":Mayor o igual";
        case MENOR:
        return lexema + ":Menor";
        case MENOR_IGUAL:
        return lexema + ":Menor o igual";
        case ASIGNACION:
        return lexema + ":Asignación";
        case DOS_PUNTOS:
        return lexema + ":Dos puntos";
        case PUNTO_COMA:
        return lexema + ":Punto y coma";
        case PUNTO:
        return lexema + ":Punto";
        case COMA:
        return lexema + ":Coma";
        case PARENTESIS_ABRE:
        return lexema + ":Paréntesis que abre";
        case PARENTESIS_CIERRA:
        return lexema + ":Paréntesis que cierra";
        case LLAVE_ABRE:
        return lexema + ":Llave que abre";
        case LLAVE_CIERRA:
        return lexema + ":Llave que cierra";
        case ID_LIBRERIA:
        return lexema + ":Identificador de librería";
        default: return "Error";
    }
}

QString MainWindow::errores(int e){
    switch(e){
        case 500:
        return lexema + " Error 500: no es una constante numérica";
        case 501:
        return lexema + " Error 501: esperaba caracter después de _ ";
        case 502:
        return lexema + " Error 502: esperaba digito después de .";
        case 503:
        return lexema + " Error 503: esperaba digito +, - ";
        case 504:
        return lexema + " Error 504: esperaba digito después de signo +,- ";
        case 505:
        return lexema + " Error 505: esperaba digito diferente a comilla simple ";
        case 506:
        return lexema + " Error 506: esperaba comilla después de caracter ";
        case 507:
        return lexema + " Error 507: esperaba signo de & después de & ";
        case 508:
        return lexema + " Error 508: esperaba signo de | después de | ";
        case 510:
        return lexema + " Error 510: !.lye";
        default: return "Error";
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
        case 130:
          return true;
        case 131:
            return true;
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
        case 510:
          return false;
        default: return true;
    }
}

void MainWindow::verificarReservada(QString ac){
    if (estado == 100){
        if ((ac=="begin")||(ac=="end")||(ac=="def")
            ||(ac=="as")||(ac=="integer")||(ac=="float")
            ||(ac=="char")||(ac=="string")||(ac=="boolean")
            ||(ac=="if")||(ac=="else")||(ac=="elseif")
            ||(ac=="endif")||(ac=="for")||(ac=="do")
            ||(ac=="endfor")||(ac=="while")||(ac=="endwhile")
            ||(ac=="function")||(ac=="endfunction")||(ac=="import")
            ||(ac=="null")||(ac=="read")||(ac=="write")
            ||(ac=="enter")||(ac=="principal")||(ac=="class")){
                estado = 100;
            } else {
                estado = 101;
            }
       }
}

bool MainWindow::aCinthyaxis(){
    while(true){
        int simbolo = pila.pop();
        std::cout << std::to_string(simbolo) + "  Imprimo simbolo de pila (linea 571)" << std::endl;
        mensaje = " | ";
        for (int i=0; i<=pila.size()-1;i++){
          //std::cout << gramema(i).toStdString() + "  Imprimo gramema desde aCinthyaxis" << std::endl;
            mensaje+= QVariant(gramema(pila.at(i))).toString() + " | ";
       }
        ui->AreaEjecucion->appendPlainText(mensaje);

        if (estado == RESERVADA) identificaReservada();
            std::cout << std::to_string(RESERVADA) + "  Imprimo estado recibido (linea 577) " << std::endl;
            std::cout << std::to_string(estado) + "  Imprimo estado (linea 578)" << std::endl;


        if (simbolo == estado){
        std::cout << std::to_string(simbolo) + "  Imprimo simbolo de pila sacado (linea 580)" << std::endl;
        std::cout << std::to_string(estado) + "  Imprimo estado recibido (linea 581)" << std::endl;
        std::cout << "Son iguales simbolo de pila y estado (linea 582)" << std::endl;
        /*mensaje = "| ";
        for (int i=0;i<=pila.size()-1;i++) {
            mensaje+= QVariant(gramema(pila.at(i))).toString() + " | ";
        }
        std::cout << mensaje.toStdString() << std::endl;*/
        return true;


        } else if (simbolo > 100) {
        std::cout << "No coincidio el estado con el simbolo (linea 585)" << std::endl;
        ui->AreaErroresPila->setPlainText(errorSint(669));
        return false;


        } else {
        //simbolo = pila.pop();
        columna = afinaToken(estado);
        std::cout << std::to_string(columna) + "  Muestro la columna de la matriz (linea 590) " << std::endl;
        produccion = matrizSint[simbolo][columna];
        std::cout <<  "Produccion recibida: (linea 592)  " + std::to_string(produccion) << std::endl;
        std::cout << std::to_string(simbolo) + "  Imprimo simbolo de matriz (linea 593)" << std::endl;
        std::cout << std::to_string(columna) + "  Imprimo columna de matrz (linea 594)" << std::endl;
        }


        if (produccion > 600){
            ui->AreaErroresPila->setPlainText(errorSint(produccion));
            return false;
        } else {
            std::cout <<  "Produccion encontrada: (linea 599)" + std::to_string(produccion) << std::endl;
            switch (produccion) {
                case 1: //Program
                    pila.push(END);
                    pila.push(ESTATUTOS);
                    pila.push(DECLARA);
                    pila.push(BEGIN);
                    pila.push(IDENTIFICADOR);
                    pila.push(CLASS);
                    pila.push(DECLARA_LIB);
                break;
                case 2: //Declara_lib
                    pila.push(DECLARA_LIB);
                    pila.push(PUNTO_COMA);
                    pila.push(ID_LIBRERIA);
                    pila.push(IMPORT);
                break;
                case 3:
                    //Declara_lib -> vacío 
                break;
                case 4: //Declara
                    pila.push(DECLARA);
                    pila.push(PUNTO_COMA);
                    pila.push(TIPO);
                    pila.push(AS);
                    pila.push(A);
                    pila.push(DEF);
                break;
                case 5:
                    //Declara -> vacío
                break;
                case 6: //A
                    pila.push(AP);
                    pila.push(IDENTIFICADOR);
                break;
                case 7: //A'
                    pila.push(A);
                    pila.push(COMA);
                break;
                case 8:
                    //A' -> vacío
                break;
                case 9: //Tipo
                    pila.push(INTEGER);
                break;
                case 10: //Tipo
                    pila.push(FLOTANTE);
                break;
                case 11: //Tipo
                    pila.push(CARACTER);
                break;
                case 12: //Tipo
                    pila.push(STRING);
                break;
                case 13: //Tipo
                    pila.push(BOOLEANO);
                break;
                case 14: //Estatutos
                    pila.push(ESTATUTOS);
                    pila.push(PUNTO_COMA);
                    pila.push(B);
                break;
                case 15:
                    //Estatutos -> vacío
                break;
                case 16: //B
                    pila.push(EST_ASIG);
                break;
                case 17: //B
                    pila.push(EST_IF);
                break;
                case 18: //B
                    pila.push(EST_WHILE);
                break;
                case 19: //B
                    pila.push(EST_FOR);
                break;
                case 20: //B
                    pila.push(EST_READ);
                break;
                case 21: //B
                    pila.push(EST_WRITE);
                break;
                case 22: //B
                    pila.push(EST_ENTER);
                break;
                case 23: //Est_Asig
                    pila.push(EXPR);
                    pila.push(ASIGNACION);
                    pila.push(IDENTIFICADOR);
                break;
                case 24: // Expr
                    pila.push(EXPRP);
                    pila.push(EXPR2);
                break;
                case 25: //Expr'
                    pila.push(EXPR);
                    pila.push(OR);
                break;
                case 26:
                    //Expr' -> vacío
                break;
                case 27: //Expr2
                    pila.push(EXPR2P);
                    pila.push(EXPR3);
                break;
                case 28: //Expr2'
                    pila.push(EXPR2);
                    pila.push(AND);
                break;
                case 29:
                    //Expr2' -> vacío
                break;
                case 30: //Expr3
                    pila.push(EXPR4);
                    pila.push(NOT);
                break;
                case 31: //Expr3
                    pila.push(EXPR4);
                break;
                case 32: //Expr4
                    pila.push(EXPR4P);
                    pila.push(EXPR5);
                break;
                case 33: //Expr4'
                    pila.push(EXPR5);
                    pila.push(OPREL);
                break;
                case 34:
                    //Expr4' -> vacío
                break;
                case 35: //Expr5
                    pila.push(EXPR5P);
                    pila.push(TERM);
                break;
                case 36: //Expr5'
                    pila.push(EXPR5);
                    pila.push(SUMA);
                break;
                case 37: //Expr5'
                    pila.push(EXPR5);
                    pila.push(RESTA);
                break;
                case 38:
                    // Expr5' -> vacío
                break;
                case 39: //Term
                    pila.push(TERMP);
                    pila.push(FACT);
                break;
                case 40: //Term'
                    pila.push(TERM);
                    pila.push(MULTIPLICACION);
                break;
                case 41: //Term'
                    pila.push(TERM);
                    pila.push(DIVISION);
                break;
                case 42: //Term'
                    pila.push(TERM);
                    pila.push(MODULO);
                break;
                case 43:
                    // Term' -> vacío
                break;
                case 44: //Fact
                    pila.push(IDENTIFICADOR);
                break;
                case 45: //Fact
                    pila.push(CONST_ENTERA);
                break;
                case 46: //Fact
                    pila.push(CONST_REAL);
                break;
                case 47: //Fact
                    pila.push(CONST_NOTACION);
                break;
                case 48: //Fact
                    pila.push(CONST_CARACTER);
                break;
                case 49: //Fact
                    pila.push(CONST_STRING);
                break;
                case 50: //Fact
                    pila.push(PARENTESIS_CIERRA);
                    pila.push(EXPR);
                    pila.push(PARENTESIS_ABRE);
                break;
                case 51: //oprel
                    pila.push(IGUAL);
                break;
                case 52: //oprel
                    pila.push(DIFERENTE);
                break;
                case 53: //oprel
                    pila.push(MENOR);
                break;
                case 54: //oprel
                    pila.push(MENOR_IGUAL);
                break;
                case 55: //oprel
                    pila.push(MAYOR);
                break;
                case 56: //oprel
                    pila.push(MAYOR_IGUAL);
                break;
                case 57: //Est_if
                    pila.push(EST_IFP);
                    pila.push(ESTATUTOS);
                    pila.push(PARENTESIS_CIERRA);
                    pila.push(EXPR);
                    pila.push(PARENTESIS_ABRE);
                    pila.push(IF);
                break;
                case 58: //Est_if'
                    pila.push(ENDIF);
                    pila.push(ESTATUTOS);
                    pila.push(ELSE);
                break;
                case 59: //Est_if'
                    pila.push(ENDIF);
                break;
                case 60: //Est_while
                    pila.push(ENDWHILE);
                    pila.push(ESTATUTOS);
                    pila.push(PARENTESIS_CIERRA);
                    pila.push(EXPR);
                    pila.push(PARENTESIS_ABRE);
                    pila.push(WHILE);
                break;
                case 61: //Est_for
                    pila.push(ENDFOR);
                    pila.push(ESTATUTOS);
                    pila.push(PARENTESIS_CIERRA);
                    pila.push(EXPR);
                    pila.push(DOS_PUNTOS);
                    pila.push(EST_ASIG);
                    pila.push(PARENTESIS_ABRE);
                    pila.push(FOR);
                break;
                case 62: //Est_enter
                    pila.push(ENTER);
                break;
                case 63: //Est_write
                    pila.push(PARENTESIS_CIERRA);
                    pila.push(D);
                    pila.push(PARENTESIS_ABRE);
                    pila.push(WRITE);
                break;
                case 64: //D
                    pila.push(DP);
                    pila.push(EXPR);
                break;
                case 65: //D'
                    pila.push(D);
                    pila.push(COMA);
                break;
                case 66:
                    //D' -> vacío
                break;
                case 67: //Est_read
                    pila.push(PARENTESIS_CIERRA);
                    pila.push(E);
                    pila.push(PARENTESIS_ABRE);
                    pila.push(READ);
                break;
                case 68: //E
                    pila.push(EP);
                    pila.push(IDENTIFICADOR);
                break;
                case 69: //E'
                    pila.push(E);
                    pila.push(COMA);
                break;
                case 70:
                    //E' -> vacío
                break;
                default: return produccion;
            }
        }
        mensaje = "| ";
        for (int i=0;i<=pila.size()-1;i++) {
            mensaje+= QVariant(gramema(pila.at(i))).toString() + " | ";
        }
        std::cout << mensaje.toStdString() << std::endl;
    }

  }




void MainWindow::identificaReservada() {
    std::cout << "Entro identifica reservada" << std::endl;
    if(lexema == "class"){
        estado = CLASS;
        std::cout << std::to_string(CLASS) + "class" << std::endl;
    } else if(lexema == "begin"){
        estado = BEGIN;
        std::cout << std::to_string(BEGIN) + "begin" << std::endl;
    } else if (lexema == "end"){
        estado = END;
        std::cout << std::to_string(END) + "end" << std::endl;
    }else if (lexema == "import"){
        estado = IMPORT;
        std::cout << std::to_string(IMPORT) + "import" << std::endl;
    }else if (lexema == "def"){
        estado = DEF;
    }else if (lexema == "as"){
        estado = AS;
    }else if (lexema == "integer"){
        estado = INTEGER;
    }else if (lexema == "float"){
        estado = FLOTANTE;
    }else if (lexema == "char"){
        estado = CARACTER;
    }else if (lexema == "string"){
        estado = STRING;
    }else if (lexema == "boolean"){
        estado = BOOLEANO;
    }else if (lexema == "if"){
        estado = IF;
    }else if (lexema == "else"){
        estado = ELSE;
    }else if (lexema == "endif"){
        estado = ENDIF;
    }else if (lexema == "lye"){
        estado = LYE;
    }else if (lexema == "while"){
        estado = WHILE;
    }else if (lexema == "endwhile"){
        estado = ENDWHILE;
    }else if (lexema == "for"){
        estado = FOR;
    }else if (lexema == "endfor"){
        estado = ENDFOR;
    }else if (lexema == "enter"){
        estado = ENTER;
    }else if (lexema == "write"){
        estado = WRITE;
    }else if (lexema == "read"){
        estado = READ;
    }else {
        std::cout << "No hizo nada nadita" << std::endl;
    }
}

//función pura
int MainWindow::afinaToken(int estado){ //columna
    switch(estado){
        case CLASS:
            return 0;
        case IDENTIFICADOR:
            return 1;
        case BEGIN:
            return 2;
        case END:
            return 3;
        case IMPORT:
            return 4;
        case ID_LIBRERIA:
            return 5;
        case DOS_PUNTOS:
            return 6;
        case PUNTO_COMA:
            return 7;
        case DEF:
            return 8;
        case AS:
            return 9;
        case COMA:
            return 10;
        case INTEGER:
            return 11;
        case FLOTANTE:
            return 12;
        case CARACTER:
            return 13;
        case STRING:
            return 14;
        case BOOLEANO:
            return 15;
        case ASIGNACION:
            return 16;
        case OR:
            return 17;
        case AND:
            return 18;
        case NOT:
            return 19;
        case SUMA:
            return 20;
        case RESTA:
            return 21;
        case MULTIPLICACION:
            return 22;
        case DIVISION:
            return 23;
        case MODULO:
            return 24;
        case CONST_ENTERA:
            return 25;
        case CONST_REAL:
            return 26;
        case CONST_NOTACION:
            return 27;
        case CONST_CARACTER:
            return 28;
        case CONST_STRING:
            return 29;
        case PARENTESIS_ABRE:
            return 30;
        case PARENTESIS_CIERRA:
            return 31;
        case IGUAL:
            return 32;
        case DIFERENTE:
            return 33;
        case MENOR:
            return 34;
        case MENOR_IGUAL:
            return 35;
        case MAYOR:
            return 36;
        case MAYOR_IGUAL:
            return 37;
        case IF:
            return 38;
        case ELSE:
            return 39;
        case ENDIF:
            return 40;
        case WHILE:
            return 41;
        case ENDWHILE:
            return 42;
        case FOR:
            return 43;
        case ENDFOR:
            return 44;
        case ENTER:
            return 45;
        case WRITE:
            return 46;
        case READ:
            return 47;
    default: return estado;
    }
}

QString MainWindow::gramema (int gram){
    switch(gram){
        case PROGRAM:
            return "Producción: Program";
        case DECLARA_LIB:
            return "Producción: Declara_lib";
        case DECLARA:
            return "Producción: Declara";
        case A:
            return "Producción: Program";
        case AP:
            return "Producción: A";
        case TIPO:
            return "Producción: Tipo";
        case ESTATUTOS:
            return "Producción: Estatutos";
        case B:
            return "Producción: B";
        case EST_ASIG:
            return "Producción: Est_Asig";
        case EXPR:
            return "Producción: Expr";
        case EXPRP:
            return "Producción: Expr'";
        case EXPR2:
            return "Producción: Expr2";
        case EXPR2P:
            return "Producción: Expr2'";
        case EXPR3:
            return "Producción: Expr3";
        case EXPR4:
            return "Producción: Expr4";
        case EXPR4P:
            return "Producción: Expr4'";
        case EXPR5:
            return "Producción: Expr5";
        case EXPR5P:
            return "Producción: Expr5'";
        case TERM:
            return "Producción: Term";
        case TERMP:
            return "Producción: Term'";
        case FACT:
            return "Producción: Fact";
        case OPREL:
            return "Producción: Oprel";
        case EST_IF:
            return "Producción: Est_if";
        case EST_IFP:
            return "Producción: Est_if'";
        case EST_WHILE:
            return "Producción: Est_while";
        case EST_FOR:
            return "Producción: Est_for";
        case EST_ENTER:
            return "Producción: Est_enter";
        case EST_WRITE:
            return "Producción: Est_write";
        case D:
            return "Producción: D";
        case DP:
            return "Producción: D'";
        case EST_READ:
            return "Producción: Est_read";
        case E:
            return "Producción: E";
        case EP:
            return "Producción: E'";
        case CLASS:
            return "Palabra reservada: class"; 
        case BEGIN:
            return "Palabra reservada:  begin"; 
        case END:
            return "Palabra reservada: end "; 
        case IMPORT:
            return "Palabra reservada: import ";
        case DEF:
            return "Palabra reservada:  def"; 
        case AS:
            return "Palabra reservada: as "; 
        case INTEGER:
            return "Palabra reservada: integer"; 
        case FLOTANTE:
            return "Palabra reservada: float"; 
        case CARACTER:
            return "Palabra reservada: char"; 
        case STRING:
            return "Palabra reservada: String"; 
        case BOOLEANO:
            return "Palabra reservada: boolean"; 
        case IF:
            return "Palabra reservada: if "; 
        case ELSE:
            return "Palabra reservada: else "; 
        case ENDIF:
            return "Palabra reservada: endif"; 
        case WHILE:
            return "Palabra reservada: while"; 
        case ENDWHILE:
            return "Palabra reservada: endwhile"; 
        case FOR:
            return "Palabra reservada: for "; 
        case ENDFOR:
            return "Palabra reservada: endfor"; 
        case ENTER:
            return "Palabra reservada: enter"; 
        case WRITE:
            return "Palabra reservada:  write"; 
        case READ:
            return "Palabra reservada: read"; 
        case LYE:
            return "Palabra reservada: lye";
        case ENOF:
            return "Final de archivo";
        case RESERVADA: 
            return "Palabra reservada";
        case IDENTIFICADOR: 
            return "Identificador";
        case CONST_ENTERA: 
            return "Constante entera";
        case CONST_REAL: 
            return "Constante real";
        case CONST_NOTACION: 
            return "Constante notacion";
        case CONST_CARACTER: 
            return "Constante caracter";
        case CONST_STRING: 
            return "Constante String";
        case SUMA: 
            return "Suma";
        case RESTA: 
            return "Resta";
        case MULTIPLICACION: 
            return "Multiplicacion";
        case DIVISION: 
            return "Dvision";
        case MODULO: 
            return "Modulo";
        case COMENTARIO: 
            return "Comentario";
        case AND: 
            return "And";
        case OR: 
            return "Or";
        case NOT: 
            return "Not";
        case DIFERENTE: 
            return "Diferente";
        case IGUAL: 
            return "Igual";
        case MAYOR: 
            return "Mayor";
        case MAYOR_IGUAL: 
            return "Mayor igual";
        case MENOR: 
            return "Menor";
        case MENOR_IGUAL: 
            return "Menor igual";
        case ASIGNACION: 
            return "Asignacion";
        case DOS_PUNTOS: 
            return "Dos puntos";
        case PUNTO_COMA: 
            return "Punto y coma";
        case PUNTO: 
            return "Punto";
        case PARENTESIS_ABRE: 
            return "Parentesis que abre";
        case PARENTESIS_CIERRA: 
            return "Parentesis que cierra";
        case LLAVE_ABRE: 
            return "Llave que abre";
        case LLAVE_CIERRA: 
            return "Llave que cierra";
        case ID_LIBRERIA: 
            return "Identificador de libreria";
        case COMA: 
            return "Coma";
        default: return "Error";
    }
};

QString MainWindow::errorSint(int er){
    switch (er) {
        case 600:
        return lexema + "" +  "Error 600: El programa debe empezar declaracion de libreria o de clase";
        case 601:
        return lexema + "" +  "Error 601: 404 not found ";
        case 602:
        return lexema + "" +  "Error 602: 404 not found ";
        case 603:
        return lexema + "" +  "Error 603: 404 not found ";
        case 604:
        return lexema + "" +  "Error 604: 404 not found ";
        case 605:
        return lexema + "" +  "Error 605: 404 not found ";
        case 606:
        return lexema + "" +  "Error 606: 404 not found ";
        case 607:
        return lexema + "" +  "Error 607: 404 not found ";
        case 608:
        return lexema + "" +  "Error 608: 404 not found ";
        case 609:
        return lexema + "" +  "Error 609: 404 not found ";
        case 610:
        return lexema + "" +  "Error 610: 404 not found ";
        case 611:
        return lexema + "" +  "Error 611: 404 not found ";
        case 612:
        return lexema + "" +  "Error 612: 404 not found ";
        case 613:
        return lexema + "" +  "Error 613: 404 not found ";
        case 614:
        return lexema + "" +  "Error 614: 404 not found ";
        case 615:
        return lexema + "" +  "Error 615: 404 not found ";
        case 616:
        return lexema + "" +  "Error 616: 404 not found ";
        case 617:
        return lexema + "" +  "Error 617: 404 not found ";
        case 618:
        return lexema + "" +  "Error 618: 404 not found ";
        case 619:
        return lexema + "" +  "Error 619: 404 not found ";
        case 620:
        return lexema + "" +  "Error 620: 404 not found ";
        case 621:
        return lexema + "" +  "Error 621: 404 not found ";
        case 622:
        return lexema + "" +  "Error 622: 404 not found ";
        case 623:
        return lexema + "" +  "Error 623: 404 not found ";
        case 624:
        return lexema + "" +  "Error 624: 404 not found ";
        case 625:
        return lexema + "" +  "Error 625: 404 not found ";
        case 626:
        return lexema + "" +  "Error 626: 404 not found ";
        case 627:
        return lexema + "" +  "Error 627: 404 not found ";
        case 628:
        return lexema + "" +  "Error 628: 404 not found ";
        case 629:
        return lexema + "" +  "Error 629: 404 not found ";
        case 630:
        return lexema + "" +  "Error 630: 404 not found ";
        case 631:
        return lexema + "" +  "Error 631: 404 not found ";
        case 632:
        return lexema + "" +  "Error 632: 404 not found ";
        case 669:
        return lexema + "" +  "Error 669: No coincidieron ";
        default: return lexema;
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

void MainWindow::on_pushButton_clicked()
{
    cadena = ui->AreaArchivo->toPlainText() + " ";
    analiza();
}
