#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include "qlineedit.h"
#include <QMainWindow>
#include "Calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorWindow; }
QT_END_NAMESPACE

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    void updateOnClick();
    void on_b0_clicked();
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_b9_clicked();
    void on_bNeg_clicked();
    void on_bDot_clicked();
    void on_bAdd_clicked();
    void on_bSub_clicked();
    void on_bMult_clicked();
    void on_bDiv_clicked();
    void on_bSqrt_clicked();
    void on_bPow_clicked();
    void on_bSin_clicked();
    void on_bCos_clicked();
    void on_bTan_clicked();
    void on_bEqual_clicked();
    void on_bBack_clicked();
    void on_bClear_clicked();
    void on_bMem_clicked();
    void on_bMemAdd_clicked();
    void on_bMemSub_clicked();
    void on_bLeftPar_clicked();
    void on_bRightPar_clicked();
    void on_bMemSet_clicked();
    void on_selectBasic_triggered();
    void on_b0_2_clicked();
    void on_selectScientific_triggered();
    void on_b1_2_clicked();
    void on_b2_2_clicked();
    void on_b3_2_clicked();
    void on_b4_2_clicked();
    void on_b5_2_clicked();
    void on_b6_2_clicked();
    void on_b7_2_clicked();
    void on_b8_2_clicked();
    void on_b9_2_clicked();
    void on_bNeg_2_clicked();
    void on_bDot_2_clicked();
    void on_bAdd_2_clicked();
    void on_bSub_2_clicked();
    void on_bMult_2_clicked();
    void on_bDiv_2_clicked();
    void on_bRightPar_2_clicked();
    void on_bLeftPar_2_clicked();
    void on_bClear_2_clicked();
    void on_bBack_2_clicked();
    void on_bEqual_2_clicked();

    void on_bPow_2_clicked();

    void on_bSqrt_2_clicked();

    void on_selectExit_triggered();

private:
    Ui::CalculatorWindow *ui;
    void addText(const QString & str);
    void addText(const char c);
    QLineEdit *output;
    QLineEdit *output2;
    QString inputString;
    Calculator *calculator = nullptr;
};
#endif // CALCULATORWINDOW_H
