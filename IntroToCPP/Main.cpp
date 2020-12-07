#include <iostream>

bool BinarySearch()
{
	int min = 0;
	int max = num.length - 1;
	while (min <= max)
	{
		int guess = ((min + max) / 2);

		if (num[guess] == goal)
			return guess;

		else if (num[guess] < goal)
			min = guess + 1;

		else if (num[guess] > goal)
			max = guess - 1;
	}
	return false;
}

void FizzBuzz()
{
	int num = 0;
	std::cout << "Please type a number: ";
	std::cin >> num;

	for (int i = 0; i <= num; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			std::cout << i << " FizzBuzz" << std::endl;

		else if (i % 5 == 0)
			std::cout << i << " Buzz" << std::endl;

		else if (i % 3 == 0)
			std::cout << i << " Fizz" << std::endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	
	system("pause");
	return 0;

	/*bool gameOver = false;

	while (!gameOver)
	{

	}*/
}