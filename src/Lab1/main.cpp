#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>   
#include <stdlib.h>   
#include <time.h>
#include "Sparse_structure.h"
#include "Unfair_Dice.h"

int main()
{
	Sparse_list<int> list(10);
	list.add(1, 0);
	list.add(3, 1);
	list.add(5, 2);
	list.add(23, 3);
	list.add(11, 4);
	list.print();
	
	
	
	srand(time(NULL));
	Unfair_dice a = make_random_dice();
	Unfair_dice b = make_random_dice();
	Unfair_dice c = make_random_dice();
	Unfair_dice d = make_random_dice();

	a.print();
	b.print();
	c.print();
	d.print();

	std::vector<Unfair_dice> first_set = { a,b };
	std::vector<Unfair_dice> second_set = { c,d };
	
	std::cout << "SUM " << std::endl;
	find_all_combination_sum(first_set, 1);
	find_all_combination_sum(second_set, 1);	
}
