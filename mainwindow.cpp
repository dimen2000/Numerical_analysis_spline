#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    x.resize(SPLINE_POINT_NUMBER);
    y.resize(SPLINE_POINT_NUMBER);
    for(unsigned int i = 0; i < SPLINE_POINT_NUMBER; ++i)
    {
        x[i] = static_cast<double>(i);
        y[i] = static_cast<double>(i);
    }
    srand(time(nullptr));

    ui->setupUi(this);
    chart = new QChart();
    series = new QLineSeries();
    series0 = new QScatterSeries();
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(10.0);
    series0->setColor(QRgb(0x6495ed));
    for (unsigned int i=0; i < SPLINE_POINT_NUMBER; i++)
    {
        series->append(x[i], y[i]);
        series0->append(x[i], y[i]);
    }
//    series->setPointsVisible(true);
    chart->addSeries(series);
    chart->addSeries(series0);
    chart->legend()->hide();
    chart->createDefaultAxes();
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::HighQualityAntialiasing);
//    ui->widget_chart->setLayout(new QGridLayout);
//    ui->widget_chart->layout()->addWidget(chartView);
    ui->graphicsView->setLayout(new QGridLayout);
    ui->graphicsView->layout()->addWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete series;
    delete chart;
}


void MainWindow::on_random_button_clicked()
{
    x[0] =rand()%10;
    y[0] = rand()%10;
    for(unsigned int i = 1; i < SPLINE_POINT_NUMBER; ++i)
    {
        x[i] = x[i -1] + 1 + rand()%9;
        y[i] = rand()%10;
    }
    ui->spline_input_1->setValue(y[0]);
    ui->spline_input_2->setValue(y[1]);
    ui->spline_input_3->setValue(y[2]);
    ui->spline_input_4->setValue(y[3]);
    ui->spline_input_5->setValue(y[4]);
    ui->spline_input_6->setValue(y[5]);
    ui->spline_input_7->setValue(y[6]);
    ui->spline_input_8->setValue(y[7]);
    ui->spline_input_x_1->setValue(x[0]);
    ui->spline_input_x_2->setValue(x[1]);
    ui->spline_input_x_3->setValue(x[2]);
    ui->spline_input_x_4->setValue(x[3]);
    ui->spline_input_x_5->setValue(x[4]);
    ui->spline_input_x_6->setValue(x[5]);
    ui->spline_input_x_7->setValue(x[6]);
    ui->spline_input_x_8->setValue(x[7]);
}

void MainWindow::on_spline_input_x_1_valueChanged(double arg1)
{
    x[0] = arg1;
}

void MainWindow::on_spline_input_x_2_valueChanged(double arg1)
{
    x[1] = arg1;
}


void MainWindow::on_spline_input_x_3_valueChanged(double arg1)
{
    x[2] = arg1;
}

void MainWindow::on_spline_input_x_4_valueChanged(double arg1)
{
    x[3] = arg1;
}

void MainWindow::on_spline_input_x_5_valueChanged(double arg1)
{
    x[4] = arg1;
}

void MainWindow::on_spline_input_x_6_valueChanged(double arg1)
{
    x[5] = arg1;
}

void MainWindow::on_spline_input_x_7_valueChanged(double arg1)
{
    x[6] = arg1;
}

void MainWindow::on_spline_input_x_8_valueChanged(double arg1)
{
    x[7] = arg1;
}

void MainWindow::on_spline_input_1_valueChanged(double arg1)
{
    y[0] = arg1;
}

void MainWindow::on_spline_input_2_valueChanged(double arg1)
{
    y[1] = arg1;
}

void MainWindow::on_spline_input_3_valueChanged(double arg1)
{
    y[2] = arg1;
}

void MainWindow::on_spline_input_4_valueChanged(double arg1)
{
    y[3] = arg1;
}

void MainWindow::on_spline_input_5_valueChanged(double arg1)
{
    y[4] = arg1;
}

void MainWindow::on_spline_input_6_valueChanged(double arg1)
{
    y[5] = arg1;
}

void MainWindow::on_spline_input_7_valueChanged(double arg1)
{
    y[6] = arg1;
}

void MainWindow::on_spline_input_8_valueChanged(double arg1)
{
    y[7] = arg1;
}

void MainWindow::on_displayPointsButton_clicked()
{
    series->clear();
    series0->clear();
    for (unsigned int i=0; i < SPLINE_POINT_NUMBER; ++i)
    {
        series->append(x[i], y[i]);
        series0->append(x[i], y[i]);
    }
    chart->axisX()->setRange(0, *std::max_element(x.begin(), x.end()));
    chart->axisY()->setRange(*std::min_element(y.begin(), y.end()), *std::max_element(y.begin(), y.end()));
}

void MainWindow::on_interpolationButton_clicked()
{
    series->setPointsVisible(false);
    series->clear();
    spline spl;
    spl.create_spline(SPLINE_POINT_NUMBER, x, y);
    double min = *std::min_element(x.begin(), x.end());
    double max = *std::max_element(x.begin(), x.end());
    for(double i = min; i < max; i = i + 0.1)
    {
        series->append(i, spl.get(i));
    }
}

void MainWindow::paintEvent(QPaintEvent *pe)
{
}
