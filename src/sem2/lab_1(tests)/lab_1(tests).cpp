#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab_1(uml)\dice.h"
#include "..\lab_1(uml)\sparce_list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1tests
{
	TEST_CLASS(lab1tests)
	{
	public:
		
		TEST_METHOD(list_get_size)
		{	
			Sparse_list<int> list(10); 
			Assert::IsTrue(list.get_size()==10);
		}
		TEST_METHOD(list_add)
		{
			Sparse_list<int> list(10);
			list.add(12, 0);
			list.add(1, 1);
			list.add(3, 2);
			list.add(5, 3);
			list.add(13, 4);
			Assert::IsTrue(list[0] == 12);
			Assert::IsTrue(list[1] == 1);
			Assert::IsTrue(list[2] == 3);
			Assert::IsTrue(list[3] == 5);
			Assert::IsTrue(list[4] == 13);
		}
		//only random data on dice class

		TEST_METHOD(matrix)
		{
			Sparse_matrix<int> default_matrix;
			Assert::IsTrue(default_matrix.get_m() == 0);
			Assert::IsTrue(default_matrix.get_n() == 0);
			Assert::IsTrue(default_matrix.get_root() == nullptr);

			Sparse_matrix<int> matrix(4, 3);
			Assert::IsTrue(matrix.get_m() == 4);
			Assert::IsTrue(matrix.get_n() == 3);
			Assert::IsTrue(matrix.get_root() == nullptr);
			matrix.add_to_matrix(4, 0, 0);
			matrix.add_to_matrix(2, 0, 1);
			matrix.add_to_matrix(3, 1, 1);
			matrix.add_to_matrix(5, 1, 0);
			matrix.add_to_matrix(4, 2, 1);
			Assert::IsTrue(matrix.get(2, 0) == 0);
			Assert::IsTrue(matrix.get(1, 1) == 3);
		}
		TEST_METHOD(dice)
		{
			int n = 5;
			double* properties = new double[n];
			properties[0] = 0;
			properties[1] = 0.5;
			properties[2] = 0.2;
			properties[3] = 0.3;
			properties[4] = 0;

			Unfair_dice a(n, properties);
			Assert::IsTrue(a.get_number() == n && a.get_probability_for_side()[2] == 0.2);
			std::vector<Unfair_dice>set = { a,a };
			std::map <int, double> result = find_all_combination_sum(set);
			Assert::IsTrue(abs(result[4] - 0.25) < 0.0001 &
				abs(result[5] - 0.2) < 0.0001 & abs(result[6] - 0.34) < 0.0001 &
				abs(result[7] - 0.12) < 0.0001 & abs(result[8] - 0.09) < 0.0001);
		}
	};
}
