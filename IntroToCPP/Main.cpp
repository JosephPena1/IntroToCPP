#include <iostream>

bool GuessingGame()
{
	int num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int min = 0;
	int max = sizeof(num)/sizeof(*num);
	while (min <= max)
	{
		int guess = ((min + max) / 2);

		//Computer's guess
		system("cls");
		std::cout << "Is this your number?: " << guess << std::endl;
		//Was it correct?
		int answer = 0;
		std::cout << "[1] Yes" << std::endl;
		std::cout << "[2] No" << std::endl;
		std::cout << "> ";
		std::cin >> answer;

		//if yes end game. if no, Higher or lower
		switch (answer)
		{
		case 1:
			std::cout << "(^*.*^) ";
			return true;
			break;
		
		case 2:
			system("cls");
			int highLow = 0;
			std::cout << "Is it Higher or Lower?" << std::endl;
			std::cout << "[1] Higher" << std::endl;
			std::cout << "[2] Lower" << std::endl;
			std::cout << "> ";
			std::cin >> highLow;

			switch (highLow)
			{
			case 1:
				min = guess + 1;
				break;

			case 2:
				max = guess - 1;
				break;
			}
			break;
		}
	}
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
	std::cout << "Think of a number from 1-10, then ";
	system("pause");
	system("cls");

	GuessingGame();

	system("pause");
	system("cls");

	return 0;

	/*bool gameOver = false;

	while (!gameOver)
	{
	std::cout << "Think of a number from 1-10, then ";

	system("pause");
	system("cls");

	GuessingGame();

	system("pause");
	system("cls");
	}*/
}