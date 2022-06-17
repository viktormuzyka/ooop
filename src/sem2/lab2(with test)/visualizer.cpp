#include "visualizer.h"

#include <iostream>
#include <optional>

Visualizer::Visualizer(std::vector<uint32_t>& data):
    m_Scene(new QGraphicsScene),
    m_Data(data),
    m_CurPos(0),
    m_Timer(new QTimer(this)){
    connect (m_Timer,&QTimer::timeout,this,&Visualizer::PlayItem);
    m_Changes = m_Accesses = m_Comparisons = nullptr;
    m_CanRun = false;
}

bool Visualizer::Visualize(Sortings::Operation operation, std::vector<uint32_t>::iterator first,
                           std::optional<std::vector<uint32_t>::iterator> second){
    double secondHeightCoef = second == std::nullopt ? 0 : double(**second)/m_MaxValue;
    size_t firstPos = first - m_Data.begin();
    size_t secondPos = second == std::nullopt ? UINT32_MAX : *second-m_Data.begin();
    m_VisualizeQueue.push_back({ operation, firstPos,
                                secondPos,
                                double(*first)/m_MaxValue,
                                secondHeightCoef});
    return true;
}

void Visualizer::Play(int speedOfVisualization){
    m_VisualizeQueue.push_back({Sortings::Operation::END, 0, 0, 0, 0});
    std::cout << "Visualization started, " << m_VisualizeQueue.size() << std::endl;
    m_CurPos = 0;
    m_Timer->start(speedOfVisualization);
    m_CanRun = true;
}

void Visualizer::PlayItem(){
    if(m_CurPos > 0){
        auto& lastItem = m_VisualizeQueue[m_CurPos-1];
        m_Rects[lastItem.first]->setBrush(QBrush(Qt::green));
        if(lastItem.second != UINT32_MAX){
            m_Rects[lastItem.second]->setBrush(QBrush(Qt::green));
        }
        if(m_CurPos == m_VisualizeQueue.size()){
            m_Timer->stop();
            m_Scene->update();
            m_CanRun = false;
            emit Sorted();
            return;
        }
    }
    auto& item = m_VisualizeQueue[m_CurPos++];
    if(item.operation == Sortings::Operation::COMPARISON){
        m_Rects[item.first]->setBrush(QBrush(Qt::red));
        long comp = m_Comparisons->text().toLong();
        m_Comparisons->setText(QString::number(++comp));
        if(item.second != UINT32_MAX){
            m_Rects[item.second]->setBrush(QBrush(Qt::red));
        }
    }
    else if(item.operation == Sortings::Operation::ACCESS){
        m_Rects[item.first]->setBrush(QBrush(Qt::yellow));
        long reads = m_Accesses->text().toLong();
        reads++;
        if(item.second != UINT32_MAX){
            m_Rects[item.second]->setBrush(QBrush(Qt::yellow));
            reads++;
        }
        m_Accesses->setText(QString::number(reads));
    }
    else if(item.operation == Sortings::Operation::CHANGE){
        m_Rects[item.first]->setBrush(QBrush(Qt::blue));
        long writes = m_Changes->text().toLong();
        writes++;

        m_Rects[item.first]->setRect(item.first*m_Width, 10,
                                     m_Width, item.firstHeightCoef*m_Scene->height()*0.9);

        if(item.second != UINT32_MAX){
            m_Rects[item.second]->setBrush(QBrush(Qt::blue));
            writes++;

            m_Rects[item.second]->setRect(item.second*m_Width, 10,
                                         m_Width, item.secondHeightCoef*m_Scene->height()*0.9);
        }
        m_Changes->setText(QString::number(writes));
    }
    m_Scene->update();
}

void Visualizer::PauseOrContinue(){
    if(m_CanRun && m_Timer->isActive()){
        m_Timer->stop();
    }
    else if(m_CanRun && !m_Timer->isActive()){
        m_Timer->start();
    }
}

void Visualizer::Clear(){
    m_Timer->stop();
    m_CanRun = false;
    m_VisualizeQueue.clear();

    for(auto i:m_Rects){
        delete i;
    }
    m_Rects.clear();
    m_Scene->update();
}

void Visualizer::ClearQueue(){
    m_VisualizeQueue.clear();
}

QGraphicsScene* Visualizer::GetScene(){
    return m_Scene;
}

QTimer* Visualizer::GetTimer(){
    return m_Timer;
}

void Visualizer::FormScene(const QSize& size){
    for(auto i:m_Rects){
        delete i;
    }
    m_Scene->setSceneRect(0,0,size.width()*0.95, size.height()*0.95);
    m_Width = double(m_Scene->width())/m_Data.size();
    m_Rects.clear();
    for(size_t i=0;i<m_Data.size();i++){
        double height = double(m_Data[i])/m_MaxValue*m_Scene->height()*0.9;
        QGraphicsRectItem* cur =
                new QGraphicsRectItem(m_Rects.size()*m_Width,10,
                                      m_Width, height);
        cur->setBrush(QBrush(Qt::white));
        m_Rects.push_back(cur);
        m_Scene->addItem(m_Rects.back());
    }
    m_Scene->update();
}

void Visualizer::UpdateScene(double widthCoef, double heightCoef){
    auto oldSceneRect = m_Scene->sceneRect();
    m_Scene->setSceneRect ( 0,0,widthCoef*oldSceneRect.width(), heightCoef*oldSceneRect.height());
    m_Width = double(m_Scene->width())/m_Rects.size();
    for(size_t i=0;i<m_Rects.size();i++){
        double height = m_Rects[i]->boundingRect().size().height() * heightCoef;
        m_Rects[i]->setRect(i*m_Width,10, m_Width, height);
    }
    m_Scene->update();
}

void Visualizer::SetMaxValue(uint32_t value){
    m_MaxValue = value;
}

void Visualizer::SetComparisonsItem(QLineEdit* item){
    m_Comparisons = item;
}
void Visualizer::SetChangesItem(QLineEdit* item){
    m_Changes = item;
}
void Visualizer::SetAccessesItem(QLineEdit* item){
    m_Accesses = item;
}
