#pragma once

#include "Sorting.h"

template<
    typename Container, typename Sorting,
    typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
class SortingFactory{
public:

    static Sorting* CreateSorting(Sortings::DefaultVisualizer<Container>* visualizer = nullptr){
        return new Sorting(visualizer);
    }
};

template<
    typename Container,
    typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
class Factory{
public:
    static Sortings::Sorting<Container>* CreateSorting(Sortings::SortingName name,
                    Sortings::DefaultVisualizer<Container>* visualizer = nullptr){
        switch(name){
        case Sortings::SortingName::BUBBLESORT:{
            return SortingFactory<Container,Sortings::BubbleSort<Container>>::CreateSorting(visualizer);
        }
        case Sortings::SortingName::INSERTIONSORT:{
            return SortingFactory<Container,Sortings::InsertionSort<Container>>::CreateSorting(visualizer);
        }
        case Sortings::SortingName::SELECTIONSORT:{
            return SortingFactory<Container,Sortings::SelectionSort<Container>>::CreateSorting(visualizer);
        }
        case Sortings::SortingName::QUICKSORTPIVOTMIDDLE:{
            return SortingFactory<Container,Sortings::QuickSortPivotMiddle<Container>>::CreateSorting(visualizer);
        }
        case Sortings::SortingName::MERGESORT:{
            return SortingFactory<Container,Sortings::MergeSort<Container>>::CreateSorting(visualizer);
        }
        case Sortings::SortingName::COUNTINGSORT:{
            return SortingFactory<Container,Sortings::CountingSort<Container>>::CreateSorting(visualizer);
        }
        case Sortings::SortingName::RADIXSORT:{
            return SortingFactory<Container,Sortings::RadixSort<Container>>::CreateSorting(visualizer);
        }
        }
    }
};
