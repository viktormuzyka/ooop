#pragma once
#include "SortingProxy.h"
#include <QElapsedTimer>
#include <string>

namespace Sortings {
	template<
	typename Container,
	         typename std::enable_if<HaveRandomAccessIterator<Container>::value>::type* = nullptr>
	class SortingAndTiming {
		public:

			SortingAndTiming(SortingProxy<std::vector<uint32_t>>*sorting):
				m_Sorting(sorting) {}

			float Sort(SortingName name, typename Container::iterator begin, typename Container::iterator end,
			           std::function<bool (
			               typename std::iterator_traits<typename Container::iterator>::value_type,
			               typename std::iterator_traits<typename Container::iterator>::value_type)> cmp =
			               [](typename std::iterator_traits<typename Container::iterator>::value_type x,
			                  typename std::iterator_traits<typename Container::iterator>::value_type y) ->
			               bool { return x < y; }) {
				time.start();
				m_Sorting->Sort(name, begin, end, cmp);
				return (float)time.nsecsElapsed()/1000000;
			}

			std::vector<std::string> ComplexityCheck(Sortings::SortingName name) {
				std::vector<std::string> performance;
				if ((name == Sortings::SortingName::BUBBLESORT ) || (name == Sortings::SortingName::INSERTIONSORT) ||
				        (name == Sortings::SortingName::SELECTIONSORT )) {
					performance.push_back("Best-case performance: O(n)");
					performance.push_back("Average performance: O(n²)");
					performance.push_back("Worst-case performance: O(n²)");
				} else if ( (name == Sortings::SortingName::SELECTIONSORT) ) {
					performance.push_back("Best-case performance: O(n²)");
					performance.push_back("Average performance: O(n²)");
					performance.push_back("Worst-case performance: O(n²)");
				} else if (name == Sortings::SortingName::QUICKSORTPIVOTMIDDLE) {
					performance.push_back("Best-case performance: O(n log(n))");
					performance.push_back("Average performance: O(n log(n))");
					performance.push_back("Worst-case performance: O(n²)");
				} else if (name == Sortings::SortingName::MERGESORT) {
					performance.push_back("Best-case performance: O(n log(n))");
					performance.push_back("Average performance: O(n log(n))");
					performance.push_back("Worst-case performance: O(n log(n))");
				} else if(name == Sortings::SortingName::COUNTINGSORT) {
					performance.push_back("Best-case performance: O(n + Range)");
					performance.push_back("Average performance: O(n + Range)");
					performance.push_back("Worst-case performance: O(n + Range)");
				} else if (name == Sortings::SortingName::RADIXSORT) {
					performance.push_back("Best-case performance: O(n * Range)");
					performance.push_back("Average performance: O(n + Range)");
					performance.push_back("Worst-case performance: O(n + Range)");
				} else
					performance.push_back("Unrecognised");
				return performance;
			}

		private:
			QElapsedTimer time;
			SortingProxy<std::vector<uint32_t>>*m_Sorting;
	};
}
