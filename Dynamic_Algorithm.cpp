#include<iostream>
using namespace std;
#include<ctime>
#include<thread>
int comparing(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int dynamic(int number, int maximumweight,int itemsweight[],int value[],int count)
{
	int i, j;
	int sd[20][20];
	for (i = 0; i <= number; i++)
	{
		for (j = 0; j <= maximumweight; j++)
		{
			if (i == 0 || j == 0)
				sd[i][j] = 0; //first row and colum =0
			else if (itemsweight[i - 1] <= j) 
				sd[i][j] = comparing(value[i - 1] + sd[i - 1][j - itemsweight[i - 1]], sd[i - 1][j]);
			else
				sd[i][j] = sd[i - 1][j];
		    count++;
		}
	}
	cout << "counter = " << count << endl;
	return sd[number][maximumweight];
}

int main()
{
	clock_t start = clock(); //starting clock
	double duration; //ending point
	cout << "plz enter the number of weight:";
	int maximumweight,n = 4,count=0;
	cin >> maximumweight;

	int value[] = { 12, 10, 20, 15};
	int itemsweight[] = { 2, 1, 3, 2 };
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "the capacity is :" << dynamic(n, maximumweight, itemsweight, value, count) << endl;
	thread t1 = thread(dynamic,n, maximumweight, itemsweight, value, count);
	t1.join();
	cout << "the time is: " << duration << endl;
	return 0;
}
