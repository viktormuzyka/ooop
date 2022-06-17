#pragma once

#include <type_traits>
#include <iterator>
#include <algorithm>
#include <functional>
#include <optional>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <random>
#include <set>

template<typename Container>
using IteratorCategoryOf =
    typename std::iterator_traits<typename Container::iterator>::iterator_category;

template<typename Container>
using HaveRandomAccessIterator =
    std::is_base_of<std::random_access_iterator_tag, IteratorCategoryOf<Container>>;

namespace Sortings{
    enum class Operation{
        COMPARISON = 0,
        ACCESS,
        CHANGE,
        END
    };

    enum class SortingName{
        BUBBLESORT,
        INSERTIONSORT,
        SELECTIONSORT,
        QUICKSORTPIVOTMIDDLE,
        MERGESORT,
        COUNTINGSORT,
        RADIXSORT
    };


    template <typename T>
    class DefaultVisualizer{
    public:
        virtual bool Visualize(Operation operation, typename T::iterator first, std::optional<typename T::iterator> second = std::nullopt){
            return true;
        }
    };
    template<
        typename Container,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class Sorting{
    public:
        Sorting(DefaultVisualizer<Container>* visualizer = nullptr):
            visualizer(visualizer) {}

        virtual void SetVisualizer(DefaultVisualizer<Container>* curVisualizer){
            visualizer = curVisualizer;
        }

        DefaultVisualizer<Container>* GetVisualizer(){
            return visualizer;
        }

        virtual void Sort(typename Container::iterator begin, typename Container::iterator end,
                     std::function<bool (
                     typename std::iterator_traits<typename Container::iterator>::value_type,
                     typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) = 0;
    protected:
        DefaultVisualizer<Container>* visualizer;   ///<pointer on current visualizer
    };

    template<
        typename Container,
        typename Visualizer = DefaultVisualizer<Container>,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class BubbleSort : public Sorting<Container>{
    public:  
        BubbleSort(DefaultVisualizer<Container>* visualizer = nullptr):
            Sorting<Container>(visualizer){}

        void Sort(typename Container::iterator begin, typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) override {
            using Iterator = typename Container::iterator;
            for (Iterator i = begin; i < end-1; i++){
                for (Iterator j = begin; j < end-i+begin-1; j++){
                    if(this->visualizer) this->visualizer->Visualize(Operation::COMPARISON, j, j+1);
                    if (cmp(*(j + 1), *j)){
                        std::swap(*j, *(j + 1));
                        if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, j, j+1);
                    }
                }
            }
        }
    };

    template<
        typename Container,
        typename Visualizer = DefaultVisualizer<Container>,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class InsertionSort : public Sorting<Container>{
    public:
        InsertionSort(DefaultVisualizer<Container>* visualizer = nullptr):
            Sorting<Container>(visualizer){}

        void Sort(typename Container::iterator begin, typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) override {
            using Iterator = typename Container::iterator;
            using ValueType = typename std::iterator_traits<typename Container::iterator>::value_type;
            for ( Iterator i = begin+1; i < end; i++) {
                Iterator j= i;
                this->visualizer->Visualize(Operation::ACCESS, i);
                ValueType key = *i;
                while (j > begin && (this->visualizer != nullptr ?
                       this->visualizer->Visualize(Operation::COMPARISON, j-1) :true) &&
                       cmp(key,*(j-1))) {
                    *j = *(j-1);
                    if(this->visualizer) {
                        this->visualizer->Visualize(Operation::CHANGE, j);
                        this->visualizer->Visualize(Operation::ACCESS, j-1);
                    }
                    j--;
                }
                *j = key;
                if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, j);
            }
        }
    };

    template<
        typename Container,
        typename Visualizer = DefaultVisualizer<Container>,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class SelectionSort : public Sorting<Container>{
    public:
        SelectionSort(Visualizer* visualizer = nullptr):
            Sorting<Container>(visualizer){}

        void Sort(typename Container::iterator begin, typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) override {
            using Iterator = typename Container::iterator;
            for (Iterator i = begin; i < end-1; i++) {
                Iterator min = i;
                for (Iterator j = i + 1; j < end; j++)
                {
                    if(this->visualizer) this->visualizer->Visualize(Operation::COMPARISON, j, min);
                    if (cmp(*j, *min))
                    {
                        min = j;
                        if(this->visualizer){
                            this->visualizer->Visualize(Operation::ACCESS, j);
                            this->visualizer->Visualize(Operation::CHANGE, min);
                        }
                    }
                }
                if(this->visualizer) this->visualizer->Visualize(Operation::COMPARISON, i, min);
                if (min != i)
                {
                    std::swap(*i, *min);
                    if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, i, min);
                }
            }
        }
    };

    template<
            typename Container,
            typename Visualizer = DefaultVisualizer<Container>,
            typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class AbstractQuickSort : public Sorting<Container>{
    public:
        AbstractQuickSort(Visualizer* visualizer = nullptr):
            Sorting<Container>(visualizer) {}

        void Sort(typename Container::iterator begin, typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) override {
            if (end - begin > 1){
                auto pivot = ChoosePivot(begin, end);
                auto p = Partition(begin, end, pivot, cmp);
                Sort(begin, p, cmp);
                Sort(p+1, end, cmp);
            }
        }

        virtual typename  Container::iterator ChoosePivot(typename Container::iterator begin, typename Container::iterator end) = 0;

        virtual typename Container::iterator Partition(typename Container::iterator begin, typename Container::iterator end,
                          typename Container::iterator pivot,
                          std::function<bool (
                          typename std::iterator_traits<typename Container::iterator>::value_type,
                          typename std::iterator_traits<typename Container::iterator>::value_type)> cmp){
            using Iterator = typename Container::iterator;
            Iterator left = begin, right = end;
            std::swap(*pivot, *begin);
            if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, begin, pivot);
            while(true){
                while(cmp(*(++left), *begin)){
                  if ( left == end-1) break;
                  if(this->visualizer) this->visualizer->Visualize(Operation::COMPARISON, left, begin);
                }
                while (cmp(*begin, *(--right))){
                  if ( right == begin ) break;
                  if(this->visualizer) this->visualizer->Visualize(Operation::COMPARISON, right, begin);
                }
                if (left >= right) break;
                std::swap(*left,*right);
                if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, left, right);
            }
            std::swap(*begin,*right);
            if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, pivot, right);
            return right;
        }
    };
    template<
            typename Container,
            typename Visualizer = DefaultVisualizer<Container>,
            typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class QuickSortPivotMiddle : public AbstractQuickSort<Container, Visualizer>{
    public:
        QuickSortPivotMiddle(Visualizer* visualizer = nullptr):
            AbstractQuickSort<Container, Visualizer>(visualizer) {}

        virtual typename Container::iterator ChoosePivot(typename Container::iterator begin, typename Container::iterator end) override {
            if(this->visualizer) this->visualizer->Visualize(Operation::ACCESS, begin + (end-begin)/2);
            return begin + (end-begin)/2;
        }
    };

    template<
        typename Container,
        typename Visualizer = DefaultVisualizer<Container>,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class AbstractMergeSort : public Sorting<Container>{
    public:
        AbstractMergeSort(Visualizer* visualizer = nullptr):
            Sorting<Container>(visualizer) {}

        void Sort(typename Container::iterator begin, typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) override {
            using Iterator = typename Container::iterator;
            if (begin < end-1) {
                Iterator middle = begin + (end - begin) / 2;
                Sort(begin , middle, cmp);
                Sort(middle, end, cmp);
                Merge(begin, middle, end, cmp);
            }
        }
        virtual void Merge(typename Container::iterator begin, typename Container::iterator middle,
                   typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp) = 0;
    };

    template<
        typename Container,
        typename Visualizer = DefaultVisualizer<Container>,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class MergeSort : public AbstractMergeSort<Container, Visualizer>{
    public:
        MergeSort(Visualizer* visualizer = nullptr):
            AbstractMergeSort<Container, Visualizer>(visualizer) {}
        void Merge(typename Container::iterator begin, typename Container::iterator middle,
                   typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp) override {
            using Iterator = typename Container::iterator;
            Container left(middle - begin);
            Container right(end - middle);
            for(Iterator i = begin, k=left.begin(); i<middle; i++, k++){
                if(this->visualizer) this->visualizer->Visualize(Operation::ACCESS, i);
                *k = *i;
            }
            for(Iterator i = middle, k=right.begin(); i<end; i++, k++){
                if(this->visualizer) this->visualizer->Visualize(Operation::ACCESS, i);
                *k = *i;
            }
            Iterator i = left.begin();
            Iterator j = right.begin();
            Iterator current = begin;
            while (i < left.end() && j < right.end()) {
                if (cmp(*i, *j)) {
                    *current = *i;
                    i++;
                } else {
                    *current = *j;
                    j++;
                }
                if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, current);
                current++;
            }
            for(; i<left.end(); i++, current++){
                *current = *i;
                if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, current);
            }
            for(; j<right.end(); j++, current++){
                *current = *j;
                if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, current);
            }
        }
    };

    template<
        typename Container,
        typename Visualizer = DefaultVisualizer<Container>,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class CountingSort : public Sorting<Container>{
    public:
        CountingSort(Visualizer* visualizer = nullptr):
            Sorting<Container>(visualizer){}

        void Sort(typename Container::iterator begin, typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) override {
            using Iterator = typename Container::iterator;

            Iterator max = begin;
            for (Iterator i = begin+1; i < end; i++) {
                if(this->visualizer) this->visualizer->Visualize(Operation::COMPARISON, i, max);
                if (*max < *i) max = i;
            }

            std::vector<int>count(*max + 1, 0);

            for (Iterator i = begin; i < end; i++){
                if(this->visualizer) this->visualizer->Visualize(Operation::ACCESS, i);
                count[*i]++;
            }

            for (size_t i = 1; i < count.size(); i++){
                count[i] += count[i - 1];
            }

            Container answer(end-begin);

            for (Iterator i = begin; i < end; i++) {
                if(this->visualizer) this->visualizer->Visualize(Operation::ACCESS, i);
                answer[count[*i] - 1] = *i;
                count[*i]--;
            }

            for(Iterator cur = begin, a = answer.begin(); cur < end; cur++, a++){
                *cur = *a;
                if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, cur);
            }
        }
    };

    template<
        typename Container,
        typename Visualizer = DefaultVisualizer<Container>,
        typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
    class RadixSort : public Sorting<Container>{
    public:
        RadixSort(Visualizer* visualizer = nullptr):
            Sorting<Container>(visualizer){}

        void Sort(typename Container::iterator begin, typename Container::iterator end,
                  std::function<bool (
                  typename std::iterator_traits<typename Container::iterator>::value_type,
                  typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
                [](typename std::iterator_traits<typename Container::iterator>::value_type x,
                   typename std::iterator_traits<typename Container::iterator>::value_type y) ->
                bool { return x < y; }) override {
            if(begin > end-2){
                return;
            }
            using Iterator = typename Container::iterator;
            using ValueType = typename std::iterator_traits<typename Container::iterator>::value_type;
            int m, p = 1;
            ValueType max = *begin;
            if(this->visualizer) this->visualizer->Visualize(Operation::ACCESS, begin);
            for(Iterator i = begin+1; i < end; i++){
                if(this->visualizer) this->visualizer->Visualize(Operation::COMPARISON, i);
                if(this->visualizer) this->visualizer->Visualize(Operation::ACCESS, i);
                if(max < *i){
                    max = *i;
                }
            }

            int maxDigit = 0;
            while(max > 0){
                max/=10;
                maxDigit++;
            }

            std::list<ValueType> pocket[10];
            for(size_t i = 0; i < maxDigit; i++) {
               m = std::pow(10, i+1);
               p = pow(10, i);
               for(Iterator j = begin; j<end; j++) {
                   if(this->visualizer) this->visualizer->Visualize(Operation::ACCESS, j);
                   ValueType temp = *j%m;
                   size_t index = temp/p;
                   pocket[index].push_back(*j);
               }
               Iterator current = begin;
               for(size_t j = 0; j<10; j++) {
                  while(!pocket[j].empty()) {
                      *current = *(pocket[j].begin());
                      if(this->visualizer) this->visualizer->Visualize(Operation::CHANGE, current);
                      pocket[j].erase(pocket[j].begin());
                      current++;
                  }
               }
            }
        }
    };
}
