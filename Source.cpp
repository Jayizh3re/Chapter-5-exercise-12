#include <iostream>
#include <limits>
#include <random>

int main()
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(1, 100);

    const int randomNumber = distribution(generator);
    int guess;

    while (true)
    {
        std::cout << "Guess a number between 1 and 100: ";

        if (!(std::cin >> guess) || guess < 1 || guess > 100)
        {
            std::cout << "Invalid input. Please try again with a number between 1 and 100."
                << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (guess > randomNumber)
        {
            std::cout << "Too high. Try again." << std::endl;
        }
        else if (guess < randomNumber)
        {
            std::cout << "Too low. Try again." << std::endl;
        }
        else
        {
            std::cout << "Congratulations! You figured out my number!" << std::endl;
            break;
        }
    }

    return 0;
}