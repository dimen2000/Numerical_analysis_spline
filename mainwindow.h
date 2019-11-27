#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>
#include <QPainter>
#include <QWidget>
#include <QtGui>
#include <vector>

#include "spline.h"

#define SPLINE_POINT_NUMBER 8

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
        virtual void paintEvent(QPaintEvent *pe);

private slots:
    void on_random_button_clicked();

    void on_spline_input_x_1_valueChanged(double arg1);

    void on_spline_input_x_2_valueChanged(double arg1);

    void on_spline_input_x_8_valueChanged(double arg1);

    void on_spline_input_x_3_valueChanged(double arg1);

    void on_spline_input_x_4_valueChanged(double arg1);

    void on_spline_input_x_5_valueChanged(double arg1);

    void on_spline_input_x_6_valueChanged(double arg1);

    void on_spline_input_x_7_valueChanged(double arg1);

    void on_spline_input_1_valueChanged(double arg1);

    void on_spline_input_2_valueChanged(double arg1);

    void on_spline_input_3_valueChanged(double arg1);

    void on_spline_input_4_valueChanged(double arg1);

    void on_spline_input_5_valueChanged(double arg1);

    void on_spline_input_6_valueChanged(double arg1);

    void on_spline_input_7_valueChanged(double arg1);

    void on_spline_input_8_valueChanged(double arg1);

    void on_displayPointsButton_clicked();

    void on_interpolationButton_clicked();

    void on_widget_chart_customContextMenuRequested(const QPoint &pos);

private:
    std::vector<double> x, y;
    QChart *chart;
    QLineSeries *series;
    QScatterSeries *series0;
    QChartView *chartView;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
