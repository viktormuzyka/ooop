#pragma once
#include "Sorting.h"
#include "Factory.h"

namespace Sortings{

    template<
        typename Container,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class SortingProxy : public Sorting<Container>{
    public:

        SortingProxy(DefaultVisualizer<Container>* visualizer = nullptr):
            m_Sorting(new BubbleSort<Container>(visualizer)) {}

        void Sort(Sortings::SortingName sorting, typename Container::iterator begin, typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
             [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }){
            if(m_CurrentSortingName != sorting) {
                DefaultVisualizer<Container>* vis = nullptr;
                if(m_Sorting){
                    vis = m_Sorting->GetVisualizer();
                    delete m_Sorting;
                }
                m_Sorting = Factory<std::vector<uint32_t>>::CreateSorting(sorting);
                m_Sorting->SetVisualizer(vis);
                m_CurrentSortingName = sorting;
            }
            Sort(begin, end, cmp);
        }

        void Sort(typename Container::iterator begin, typename Container::iterator end,
                     std::function<bool (
                     typename std::iterator_traits<typename Container::iterator>::value_type,
                     typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) override{
            m_Sorting->Sort(begin, end, cmp);
        }

        void SetVisualizer(DefaultVisualizer<Container>* visualizer) override{
            m_Sorting->SetVisualizer(visualizer);
        }
    protected:
        Sorting<Container>* m_Sorting;
        Sortings::SortingName m_CurrentSortingName;
    };
}
