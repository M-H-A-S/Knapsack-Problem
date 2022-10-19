#include <iostream>
#include <algorithm> // for using sort function already  made 
#include<ctime> // for calculate Run time execution 
#include<thread>
using namespace std; 
int counter = 0; 
struct Item{ double Value; double Weight; };  // This Struct contain the value and the weight of Items 

/*bool CompareItem(struct Item Array[]) // This function to Compare the result of (divideing the Value on Weight of each item in the array)
{
	for (int i = 0; i < sizeof(Array); i++)
	{
		double Ratio1 = Array[i].Value / Array[i].Weight;
		double Ratio2 = Array[i + 1].Value / Array[i + 1].Weight;
		return Ratio1 > Ratio2;  // return the highest Ratio of the item to sort it after calculate The Ratio of each item by sort function. 
	}
	  
}*/

bool CompareItem(struct Item a, struct Item b)
{
	double r1 = (double)a.Value / a.Weight; counter++;
	double r2 = (double)b.Value / b.Weight; counter++;
	counter++;
	return r1 > r2;
}
double Greedy(int Capacity, struct Item Array[], int NumberOfItem)
{
	//sort(Array, Array + NumberOfItem, CompareItem); // Sort the Item in the Array By Function Compare
	sort(Array, Array + NumberOfItem, CompareItem); counter++;
	cout << "the Ratio of each Item" << endl;
	cout << "-------------------" << endl;
	for (int i = 0; i < NumberOfItem; i++) // This for loop just for print the value and weight of each item and thier ration
	{
		cout << Array[i].Value << "   " << Array[i].Weight << " : " << ((double)Array[i].Value / Array[i].Weight) << endl;
		counter++;
	}
	cout << "----------------" << endl;

	int CurrentWeigth = 0;double ResultValue = 0.0;int i = 0;counter++;
	while ( i < NumberOfItem )
	{
		// If adding Item won't overflow, add it completely
		if (CurrentWeigth + Array[i].Weight <= Capacity)
		{
			CurrentWeigth += Array[i].Weight; counter++;
			ResultValue += Array[i].Value; counter++;
			counter++;
		}

		// If we can't add current Item, add fractional part of it
		else
		{
			int remain = Capacity - CurrentWeigth; counter++;
			ResultValue += Array[i].Value * ((double)remain / Array[i].Weight); counter++;
			counter++;
			break;
		}
		counter++;
		i++;
	}

	return ResultValue; counter++;
}

int main()
{
	clock_t start = clock(); //starting clock
	double duration; //valriable for ending point
	

	int capacity; Item Arr[100]; int NumberOfItem; counter++;
	cout << "Enter the Number Of Item for Knapsack : "; counter++;
	cin >> NumberOfItem; counter++;
	cout << endl; counter++;
	cout << "--------------------------------------------------------" << endl; counter++;

	cout << "Enter the Capacity Of Knapsack : "; counter++;
	cin >> capacity; counter++;
	cout << endl; counter++;
	cout << "--------------------------------------------------------" << endl; counter++;
	

	for (int i = 0; i < NumberOfItem; i++)
	{
		cout << "Enter the Value and Weight of Item  (" << i + 1 << ")  :"; counter++;
		cin >> Arr[i].Value; counter++;
		cout << " "; counter++;
		cin >> Arr[i].Weight; counter++;
		cout << endl; counter++;
		counter++;
	}

	cout << "--------------------------------------------------------" << endl; counter++;
	cout << "The maximum Value that Greedy Function can obtain is = " << Greedy(capacity, Arr, NumberOfItem) << endl; counter++;
	cout << "--------------------------------------------------------" << endl; counter++;
	cout << "Number of steps in Greedy algorithm is = " << counter << "  steps" << endl;
	cout << "--------------------------------------------------------" << endl; counter++;
	duration = (clock() - start) / (double)CLOCKS_PER_SEC; //Calculate time 
	cout << "the time is "<< duration<<endl;
	cout << "--------------------------------------------------------" << endl; counter++;
	//Thread
	thread t1 = thread(Greedy,capacity, Arr, NumberOfItem)
	thread t2 = thread(dynamic, n, maximumweight, itemsweight, value, count);
	t1.join();
	t2.join();

	return 0;
}