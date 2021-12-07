#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class dice {
	public:
		dice() {
			number_of_sides = 0;
			probability_for_side = new double[0];
		}
		dice(int number_of_sides, double* probability_for_side) {
			assert( (number_of_sides>0) && "Negative number of sides");
			this->number_of_sides = number_of_sides;

			this->probability_for_side = new double[number_of_sides];
			double sum_for_checking = 0;//check probabilities input(sum have to be equal to 1)
			for (int i = 0; i < number_of_sides; i++) {
				assert(probability_for_side[i] >= 0 && "Negative probability");
				this->probability_for_side[i] = probability_for_side[i];
				sum_for_checking += probability_for_side[i];
			}
			assert(abs(sum_for_checking - 1) < 0.0001 &&  "False sum");
		};

		dice(const dice& other) {
			this->number_of_sides = other.number_of_sides;
			this->probability_for_side = new double[other.number_of_sides];
			for (int i = 0; i < this->number_of_sides; i++) {
				this->probability_for_side[i] = other.probability_for_side[i];
			}
		}

		dice operator = (const dice& other) {
			this->number_of_sides = other.number_of_sides;
			this->probability_for_side = new double[other.number_of_sides];
			for (int i = 0; i < this->number_of_sides; i++) {
				this->probability_for_side[i] = other.probability_for_side[i];
			}
			return *this;
		}
		dice ( dice& other) {
			this->number_of_sides = other.number_of_sides;
			this->probability_for_side = new double[other.number_of_sides];
			for (int i = 0; i < this->number_of_sides; i++) {
				this->probability_for_side[i] = other.probability_for_side[i];
			}

		}


		~dice() {
			delete[] probability_for_side;
		};
		int get_number() {
			return number_of_sides;
		}
		double* get_probability_for_side() {
			return probability_for_side;
		}
		void print() {
			std::cout << " n = " << this->number_of_sides << ", probability = {";
			for (int i = 0; i < this->number_of_sides - 1; i++) {
				std::cout << " p_" << i << " = " << this->probability_for_side[i] << ",";
			}
			std::cout << " p_" << (this->number_of_sides - 1) << " = " << this->probability_for_side[this->number_of_sides - 1] << "}" << std::endl;
		}
	private:
		int number_of_sides;
		double* probability_for_side;

};

dice make_random() {
	int possible_numbers[] = { 2,4,6,8,10,12,20 };
	int n = possible_numbers[rand() % 7];
	double* probabilities = new double[n];
	double sum = 0;
	for (int i = 0; i < n; i++) {
		probabilities[i] = (rand() % 555);
		sum += probabilities[i];
	}
	if (sum == 0) {
		probabilities[0] = 1;
		sum = 1;
	}
	for (int i = 0; i < n; i++) {
		probabilities[i] = probabilities[i] / sum;
	}
	dice answ(n, probabilities);
	delete[]probabilities;

	return answ;
}
void find_all_sum(std::map<int, double>& result, std::vector <dice>& dices, int sum = 0, double properties = 1, int current_index = 0) {
	if (current_index == dices.size()) {
		if (properties != 0) {
			if (result.count(sum)) {
				result[sum] += properties;
			} else {
				result.insert(std::make_pair(sum, properties));
			}
		}
		return;
	} else {

		for (int i = 0; i < dices[current_index].get_number(); i++) {
			if (dices[current_index].get_probability_for_side()[i] == 0) {
				continue;
			}
			find_all_sum(result, dices, sum + (i + 1), properties * (dices[current_index].get_probability_for_side()[i]), current_index + 1);

		}
	}
}
std::map <int, double> find_all_combination_sum(std::vector <dice>& dices, bool print = 0) {
	std::map <int, double> result;
	find_all_sum(result, dices);
	if (print) {
		std::map <int, double> ::iterator it = result.begin();
		for (int i = 0; it != result.end(); it++, i++) {  // выводим их
			std::cout << i << ") sum " << it->first << ", probability " << it->second << std::endl;
		}
	}
	return result;
}
void compare_two_sets_of_dices(std::vector <dice>& dices_1, std::vector <dice>& dices_2) {
	std::map<int, double> sums_1 = find_all_combination_sum(dices_1);
	std::map<int, double> sums_2 = find_all_combination_sum(dices_2);
	std::map<int, double>::iterator iterator_1 = sums_1.begin(), iterator_2 = sums_2.begin();
	int e = 0;
	while ((iterator_1 != sums_1.end()) || (iterator_2 != sums_2.end())) {
		if ((iterator_1 == sums_1.end())) {
			std::cout << "sum = " << iterator_2->first << " has higer on " << iterator_2->second << " probability in second set" << std::endl;
			iterator_2++;
			continue;
		}
		if (iterator_2 == sums_2.end()) {
			std::cout << "sum = " << iterator_1->first << " has higer on " << iterator_1->second << " probability in first set" << std::endl;
			iterator_1++;
			continue;
		}
		if (iterator_1->first > iterator_2->first) {
			std::cout << "sum = " << iterator_2->first << " has higer on " << iterator_2->second << " probability in second set" << std::endl;
			iterator_2++;
			continue;
		}
		if (iterator_1->first < iterator_2->first) {
			std::cout << "sum = " << iterator_1->first << " has higer on " << iterator_1->second << " probability in first set" << std::endl;
			iterator_1++;
			continue;
		}
		if (iterator_1->first == iterator_2->first) {
			if (iterator_1->second == iterator_2->second) {
				std::cout << "sum = " << iterator_1->first << " has same probability in two sets" << std::endl;
			} else {
				std::cout << "sum = " << iterator_1->first << " has higer on " << abs(iterator_1->second - iterator_2->second) << " probability in ";
				if (iterator_1->second > iterator_2->second) {
					std::cout << "first set" << std::endl;
				} else {
					std::cout << "second set" << std::endl;
				}
			}
			iterator_1++;
			iterator_2++;
		}
	}
}

