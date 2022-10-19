#include "calculatorwindow.h"
#include "./ui_calculatorwindow.h"
#include <QString>
#include "CalculatorEnums.h"


CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    QString inputString = "";
    output = ui->outDisplay;
    output2 = ui->outDisplay_2;
    inputString = "0";
    calculator = new Calculator();
    ui->stackedWidget->setCurrentIndex(1);
}

CalculatorWindow::~CalculatorWindow()
{
    delete calculator;
    delete ui;
}

void CalculatorWindow::updateOnClick()
{
    output->setText(inputString);
    output2->setText(inputString);
}

void CalculatorWindow::addText(const QString & str)
{
    inputString += str;
    updateOnClick();
}

void CalculatorWindow::addText(const char c)
{
    inputString += c;
    updateOnClick();
}


void CalculatorWindow::on_b0_clicked()
{
    addText("0");
}

void CalculatorWindow::on_b1_clicked()
{
    addText("1");
}


void CalculatorWindow::on_b2_clicked()
{
    addText("2");
}


void CalculatorWindow::on_b3_clicked()
{
    addText("3");
}


void CalculatorWindow::on_b4_clicked()
{
    addText("4");
}


void CalculatorWindow::on_b5_clicked()
{
    addText("5");
}


void CalculatorWindow::on_b6_clicked()
{
    addText("6");
}


void CalculatorWindow::on_b7_clicked()
{
    addText("7");
}


void CalculatorWindow::on_b8_clicked()
{
    addText("8");
}


void CalculatorWindow::on_b9_clicked()
{
    addText("9");
}


void CalculatorWindow::on_bNeg_clicked()
{
    addText("-");
}


void CalculatorWindow::on_bDot_clicked()
{
    addText(".");
}


void CalculatorWindow::on_bAdd_clicked()
{
    addText(ADD);
}


void CalculatorWindow::on_bSub_clicked()
{
    addText(SUB);
}


void CalculatorWindow::on_bMult_clicked()
{
    addText(MULT);
}


void CalculatorWindow::on_bDiv_clicked()
{
    addText(DIV);
}


void CalculatorWindow::on_bSqrt_clicked()
{
    addText(SQRT);
}


void CalculatorWindow::on_bPow_clicked()
{
    addText("^");
}


void CalculatorWindow::on_bSin_clicked()
{
    addText("s");
}


void CalculatorWindow::on_bCos_clicked()
{
    addText("c");
}


void CalculatorWindow::on_bTan_clicked()
{
    addText("t");
}


void CalculatorWindow::on_bEqual_clicked()
{
    inputString = QString::fromStdString(calculator->calculate(inputString.toStdString()));
    updateOnClick();
}


void CalculatorWindow::on_bBack_clicked()
{
    inputString.chop(1);
    updateOnClick();
}


void CalculatorWindow::on_bClear_clicked()
{
    inputString = "";
    updateOnClick();
}

void CalculatorWindow::on_bMemSet_clicked()
{
    calculator->setMemory(calculator->calculate(inputString.toStdString()));
}

void CalculatorWindow::on_bMem_clicked()
{
    inputString += QString::fromStdString(calculator->getMemory());
    updateOnClick();
}


void CalculatorWindow::on_bMemAdd_clicked()
{
    calculator->memoryAdd(calculator->calculate(inputString.toStdString()));
}


void CalculatorWindow::on_bMemSub_clicked()
{
    calculator->memorySub(calculator->calculate(inputString.toStdString()));
}


void CalculatorWindow::on_bLeftPar_clicked()
{
    addText("(");
}


void CalculatorWindow::on_bRightPar_clicked()
{
    addText(")");
}

void CalculatorWindow::on_selectBasic_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void CalculatorWindow::on_selectScientific_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Simple layout requires separate buttons. Call regular button
//functions here:


void CalculatorWindow::on_b0_2_clicked()
{
    addText("0");
}




void CalculatorWindow::on_b1_2_clicked()
{
    addText("1");
}


void CalculatorWindow::on_b2_2_clicked()
{
    addText("2");
}


void CalculatorWindow::on_b3_2_clicked()
{
    addText("3");
}


void CalculatorWindow::on_b4_2_clicked()
{
    addText("4");
}


void CalculatorWindow::on_b5_2_clicked()
{
    addText("5");
}


void CalculatorWindow::on_b6_2_clicked()
{
    addText("6");
}


void CalculatorWindow::on_b7_2_clicked()
{
    addText("7");
}


void CalculatorWindow::on_b8_2_clicked()
{
    addText("8");
}


void CalculatorWindow::on_b9_2_clicked()
{
    addText("9");
}


void CalculatorWindow::on_bNeg_2_clicked()
{
    addText("-");
}


void CalculatorWindow::on_bDot_2_clicked()
{
    addText(".");
}


void CalculatorWindow::on_bAdd_2_clicked()
{
    addText(ADD);
}


void CalculatorWindow::on_bSub_2_clicked()
{
    addText(SUB);
}


void CalculatorWindow::on_bMult_2_clicked()
{
    addText(MULT);
}


void CalculatorWindow::on_bDiv_2_clicked()
{
    addText(DIV);
}


void CalculatorWindow::on_bRightPar_2_clicked()
{
    addText(")");
}


void CalculatorWindow::on_bLeftPar_2_clicked()
{
    addText("(");
}


void CalculatorWindow::on_bClear_2_clicked()
{
    inputString = "";
    updateOnClick();
}


void CalculatorWindow::on_bBack_2_clicked()
{
    inputString.chop(1);
    updateOnClick();
}


void CalculatorWindow::on_bEqual_2_clicked()
{
    inputString = QString::fromStdString(calculator->calculate(inputString.toStdString()));
    updateOnClick();
}


void CalculatorWindow::on_bPow_2_clicked()
{
    addText("^");
    updateOnClick();
}


void CalculatorWindow::on_bSqrt_2_clicked()
{
    addText(SQRT);
    updateOnClick();
}


void CalculatorWindow::on_selectExit_triggered()
{
    exit(0);
}

