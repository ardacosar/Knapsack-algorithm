
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
void solve(Item* it)
{
	Item Ss[127]; //Subset array | 127 = 2^7-1
	int maxValue = 0, trueIndex; //trueIndex is Index that holds the maxValue in Subsets;

	for (int i = 0; i < 7; i++) // First members
	{ Ss[i] = it[i]; }	
	
	int s = 7; // Counter | 0 to 127

	for (int i = 0; i < 120; i++)  // i < (Subset Array's length)-(Item Array's length) | i < 127-7
	{

		for (int j = Ss[i].index + 1; j < 7; j++)   //Combination Phase
		{
			Ss[s].name = Ss[i].name + it[j].name;
			Ss[s].value = Ss[i].value + it[j].value;
			Ss[s].weight = Ss[i].weight + it[j].weight;
			Ss[s].index = it[j].index;

			if (Ss[s].value > maxValue && Ss[s].weight <= 25)  
			{
				maxValue = Ss[s].value;
				trueIndex = s;
			}

			s++;
		}
	}
	cout << "Items: " << Ss[trueIndex].name << " - " << "Weight: " << Ss[trueIndex].weight << "Kg"  << " - " << "Value: " << Ss[trueIndex].value << "$" << endl;  
}
int main()
{

	Item it[7];

	define(it);

	solve(it);


}

