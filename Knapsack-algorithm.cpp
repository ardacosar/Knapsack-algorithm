
#include <iostream>
#include <string>

using namespace std;


struct Item
{
	string name;
	int weight;
	int value;
	int index;
};

void define(Item* it)
{
	for (int i = 0; i < 7; i++)
	{
		it[i].name = 'A' + i;
		it[i].index = i;
	}
	
	it[0].weight = 3;
	it[0].value = 25;
	
	it[1].weight = 8;
	it[1].value = 50;
	
	it[2].weight = 4;
	it[2].value = 10;
	
	it[3].weight = 7;
	it[3].value = 70;
	
	it[4].weight = 6;
	it[4].value = 20;
	
	it[5].weight = 5;
	it[5].value = 40;
	
	it[6].weight = 9;
	it[6].value = 100;
}
void solve(Item* it , int knapWeight)
{
	Item subSet[127]; //Subset array | 127 = 2^7-1
	int maxValue = 0, trueIndex; //trueIndex is Index that holds the maxValue in Subsets;

	for (int i = 0; i < 7; i++) // First members
	{ subSet[i] = it[i]; }	
	
	int s = 7; // Counter | 0 to 127

	for (int i = 0; i < 120; i++)  // i < (Subset Array's length)-(Item Array's length) | i < 127-7
	{

		for (int j = subSet[i].index + 1; j < 7; j++)   //Combination Phase
		{
			subSet[s].name = subSet[i].name + it[j].name;
			subSet[s].value = subSet[i].value + it[j].value;
			subSet[s].weight = subSet[i].weight + it[j].weight;
			subSet[s].index = it[j].index;

			if (subSet[s].value > maxValue && subSet[s].weight <= knapWeight)  
			{
				maxValue = subSet[s].value;
				trueIndex = s;
			}

			s++;
		}
	}
	cout << "Items: " << subSet[trueIndex].name << " - " << "Weight: " << subSet[trueIndex].weight << "Kg"  << " - " << "Value: " << subSet[trueIndex].value << "$" << endl;  
}
int main()
{
	int knapsackWeight;
	cout << "Knapsack Weight: ";
	cin >> knapsackWeight;
	
	Item it[7];

	define(it);

	solve(it, knapsackWeight);


}

