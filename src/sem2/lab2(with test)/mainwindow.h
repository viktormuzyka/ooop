#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QShortcut>
#include <QResizeEvent>

#include <vector>
#include <random>

#include "Sorting.h"
#include "visualizer.h"
#include "Decorator.h"
#include "parsingwindow.h"
#include "Singleton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Singleton<MainWindow>
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent* event);

private slots:

    void on_SortButton_clicked();

    void on_InitiateButton_clicked();

    void on_ComplexityButton_clicked();

    void on_delay_sliderMoved(int position);

    void on_StopButton_clicked();

    void on_ClearButton_clicked();

    void on_delay_valueChanged(int value);

private:
    void FormNumbers();

    Ui::MainWindow *ui;
    ParsingWindow * window;
    QShortcut  *keyCtrl_D;

    std::vector<uint32_t>m_Numbers;

    Visualizer m_Visualizer;
    Sortings::DefaultVisualizer<std::vector<uint32_t>>m_DefaultVisualizer;

    Sortings::SortingProxy<std::vector<uint32_t>> m_Sorting;
    Sortings::SortingAndTiming<std::vector<uint32_t>> m_SortingAndTiming;

    bool m_IsInitiated;

    std::random_device rd;
    std::mt19937 mersenne;
};
