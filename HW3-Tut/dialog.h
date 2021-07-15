#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <iostream>
#include <QString>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void mousePressEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

    void on_clearPushButton_clicked();

    void on_vertexModeRad_clicked();

    void on_translateModeRad_clicked();

    void on_xAxisRad_clicked();

    void on_yAxisRad_clicked();

    void on_zAxisRad_clicked();

    void on_currAxisLabel_textChanged(const QString &arg1);

    void on_currAxisLabel_selectionChanged();

private:
    Ui::Dialog *ui;

    int radial = 0;
    //radial is used to track which radial button
    //was clicked so we can utilize the
    //proper tool.
    int axisRad = 0;
    QString axis = "";
    QString mode = "";

    int triCount = 0;
    //triCount is to make sure we have a complete triangle

    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int x3 = 0;
    int y3 = 0;

};
#endif // DIALOG_H
