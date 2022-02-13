#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>   
#include <stdlib.h>   
#include <time.h>
#include "sparce_list.h"
#include "dice.h"



int main()
{
	srand(time(NULL));
	/*Sparse_list<int> list(10);
	list.add(1, 0);
	list.add(3, 1);
	list.add(5, 1);
	list.add(23, 3);
	list.add(11, 3);
	std::cout << list[2] << std::endl;
	list.print();*/

	/*int n = 4;
	double* properties = new double[n];
	properties[0] = 0;
	properties[1] = 0.5;
	properties[2] = 0.2;
	properties[3] = 0.3;
	Unfair_dice a(n, properties);
	std::vector<Unfair_dice>set = { a,a };
	std::map <int, double> result = find_all_combination_sum(set, 1);*/
	/*Unfair_dice a = make_random_dice();
	Unfair_dice b = make_random_dice();
	Unfair_dice c = make_random_dice();
	Unfair_dice d = make_random_dice();
	a.print();
	b.print();
	c.print();
	d.print();
	std::vector<Unfair_dice> first_set = { a,b };
	std::vector<Unfair_dice> second_set = { c,d };
	find_all_combination_sum(first_set, 1);
	find_all_combination_sum(second_set, 1);
	Sparse_list<Unfair_dice>s(5);
	s.add(a, 3);*/


}