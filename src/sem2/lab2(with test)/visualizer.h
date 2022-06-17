#pragma once

#include <QGraphicsScene>
//#include <QApplication>
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QLineEdit>

#include <vector>
#include <optional>

#include "Sorting.h"

class Visualizer : public QObject, public Sortings::DefaultVisualizer<std::vector<uint32_t>>
{
    Q_OBJECT

public:

    Visualizer(std::vector<uint32_t>& data);

    bool Visualize(Sortings::Operation operation, std::vector<uint32_t>::iterator first, std::optional<std::vector<uint32_t>::iterator> second = std::nullopt) override;

    void FormScene(const QSize& size);

    void UpdateScene(double widthCoef, double heightCoef);

    void SetMaxValue(uint32_t value);

    void SetComparisonsItem(QLineEdit* item);

    void SetChangesItem(QLineEdit* item);

    void SetAccessesItem(QLineEdit* item);

    void Play(int speedOfVisualization);

    void PlayItem();

    void ClearQueue();

    void PauseOrContinue();

    void Clear();

    QGraphicsScene* GetScene();

    QTimer* GetTimer();

signals:
    void Sorted();
private:
    struct VisualizeItem{
        Sortings::Operation operation;
        size_t first;
        size_t second;
        double firstHeightCoef;
        double secondHeightCoef;
    };

    QGraphicsScene* m_Scene;
    std::vector<QGraphicsRectItem*>m_Rects;
    std::vector<uint32_t>&m_Data;
    uint32_t m_MaxValue;
    double m_Width;
    size_t m_CurPos;

    bool m_CanRun;

    std::vector<VisualizeItem>m_VisualizeQueue;
    QTimer *m_Timer;

    QLineEdit* m_Comparisons;
    QLineEdit* m_Changes;
    QLineEdit* m_Accesses;
};
