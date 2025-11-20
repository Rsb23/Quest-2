#include "gate.h"

int Gate::getPointsValue()
{
	return pointsValue;
}
void Gate::setPointsValue(int newPointsValue)
{
	pointsValue = newPointsValue;
}
bool Gate::getCompleted()
{
	return completed;
}
void Gate::setCompleted(bool newCompleted)
{
	completed = newCompleted;
}
int Gate::makeRandomNum(int min, int max)
{
	srand(time(0)); // seed RNG
	return (min + (rand() % (max - min + 1)));
}
void Gate::loadPrompt(Player &_player, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
	while (true)
	{
		int person{makeRandomNum(0, 6)}; // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
		int questionChoice{makeRandomNum(0, 2)};

		if (person == 0)
		{
			std::cout << tylerQuestions[questionChoice] << "\n";
		}
		else if (person == 1)
		{
			std::cout << francisQuestions[questionChoice] << "\n";
		}
		else if (person == 2)
		{
			std::cout << gauravQuestions[questionChoice] << "\n";
		}
		else if (person == 3)
		{
			std::cout << nosaQuestions[questionChoice] << "\n";
		}
		else if (person == 4)
		{
			std::cout << liamQuestions[questionChoice] << "\n";
		}
		else if (person == 5)
		{
			std::cout << stefanQuestions[questionChoice] << "\n";
		}
		else if (person == 6)
		{
			std::cout << avneetQuestions[questionChoice] << "\n";
		}

		while (true)
		{
			int response{0};

			std::cout << "What person said this? (Tyler (0), Francis (1), Gaurav (2), Nosa (3), Liam (4), Stefan (5), or Avneet (6))?: ";
			std::cin >> response;

			if (response || response == 0)
			{
				if (response == person)
				{
					std::cout << "That's correct!\n";
					std::cout << "The old door swings open revealing another passage\n";

					std::cout << "Points Increase: +" << pointsValue << "pts\n";

					Map[PlayX][PlayY][4] = 0;
					setCompleted(true);
					_player.adjustPoints(pointsValue);
					break;
				}
				else
				{
					std::cout << "That's incorrect\n!";
					std::cout << "The sturdy door remains closed\n";

					std::cout << "Points Decrease: -1pt\n";
					_player.adjustPoints(-1);
				}
			}
			else
			{
				std::cout << "Please enter a response!\n";
				continue;
			}
		}
		break;
	}
}
void Gate::loadPrompt(Guardian &_guardian, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
	while (true)
	{
		int person{makeRandomNum(0, 6)}; // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
		int questionChoice{makeRandomNum(0, 2)};

		if (person == 0)
		{
			std::cout << tylerQuestions[questionChoice] << "\n";
		}
		else if (person == 1)
		{
			std::cout << francisQuestions[questionChoice] << "\n";
		}
		else if (person == 2)
		{
			std::cout << gauravQuestions[questionChoice] << "\n";
		}
		else if (person == 3)
		{
			std::cout << nosaQuestions[questionChoice] << "\n";
		}
		else if (person == 4)
		{
			std::cout << liamQuestions[questionChoice] << "\n";
		}
		else if (person == 5)
		{
			std::cout << stefanQuestions[questionChoice] << "\n";
		}
		else if (person == 6)
		{
			std::cout << avneetQuestions[questionChoice] << "\n";
		}

		while (true)
		{
			int response{0};

			std::cout << "What person said this? (Tyler (0), Francis (1), Gaurav (2), Nosa (3), Liam (4), Stefan (5), or Avneet (6))?: ";
			std::cin >> response;

			if (response || response == 0)
			{
				if (response == person)
				{
					std::cout << "That's correct!\n";
					std::cout << "The old door swings open revealing another passage\n";

					std::cout << "Points Increase: +" << pointsValue << "pts\n";

					Map[PlayX][PlayY][4] = 0;
					setCompleted(true);
					_guardian.adjustPoints(pointsValue);
					break;
				}
				else
				{
					std::cout << "That's incorrect\n!";
					std::cout << "The sturdy door remains closed\n";

					if (_guardian.getLives() > 0)
					{
						std::cout << "Bulwark The Guardian bravely provides a life\n";
						std::cout << "No Points Are Lost\n";

						_guardian.decrementLives();
					}
					else
					{
						std::cout << "You have no more lives!\n";
						std::cout << "Points Decrease: -1pt\n";
						_guardian.adjustPoints(-1);
					}
				}
			}
			else
			{
				std::cout << "Please enter a response!\n";
				continue;
			}
		}
		break;
	}
}
void Gate::loadPrompt(Ravager &_ravager, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
	while (true)
	{
		int person{makeRandomNum(0, 6)}; // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
		int questionChoice{makeRandomNum(0, 2)};

		if (person == 0)
		{
			std::cout << tylerQuestions[questionChoice] << "\n";
		}
		else if (person == 1)
		{
			std::cout << francisQuestions[questionChoice] << "\n";
		}
		else if (person == 2)
		{
			std::cout << gauravQuestions[questionChoice] << "\n";
		}
		else if (person == 3)
		{
			std::cout << nosaQuestions[questionChoice] << "\n";
		}
		else if (person == 4)
		{
			std::cout << liamQuestions[questionChoice] << "\n";
		}
		else if (person == 5)
		{
			std::cout << stefanQuestions[questionChoice] << "\n";
		}
		else if (person == 6)
		{
			std::cout << avneetQuestions[questionChoice] << "\n";
		}

		while (true)
		{
			int response{0};

			std::cout << "What person said this? (Tyler (0), Francis (1), Gaurav (2), Nosa (3), Liam (4), Stefan (5), or Avneet (6))?: ";
			std::cin >> response;

			if (response || response == 0)
			{
				if (response == person)
				{
					std::cout << "That's correct!\n";
					std::cout << "The old door swings open revealing another passage\n";

					std::cout << "Points Increase: +" << pointsValue << "pts\n";

					Map[PlayX][PlayY][4] = 0;
					setCompleted(true);
					_ravager.adjustPoints(pointsValue);
					break;
				}
				else
				{
					std::cout << "That's incorrect\n!";
					std::cout << "The sturdy door remains closed\n";

					std::cout << "Points Decrease: -1pt\n";
					_ravager.adjustPoints(-1);
				}
			}
			else
			{
				std::cout << "Please enter a response!\n";
				continue;
			}
		}
		break;
	}
}
void Gate::loadPrompt(Trickster &_trickster, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
	while (true)
	{
		int person{makeRandomNum(0, 6)}; // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
		int questionChoice{makeRandomNum(0, 2)};

		if (person == 0)
		{
			std::cout << tylerQuestions[questionChoice] << "\n";
		}
		else if (person == 1)
		{
			std::cout << francisQuestions[questionChoice] << "\n";
		}
		else if (person == 2)
		{
			std::cout << gauravQuestions[questionChoice] << "\n";
		}
		else if (person == 3)
		{
			std::cout << nosaQuestions[questionChoice] << "\n";
		}
		else if (person == 4)
		{
			std::cout << liamQuestions[questionChoice] << "\n";
		}
		else if (person == 5)
		{
			std::cout << stefanQuestions[questionChoice] << "\n";
		}
		else if (person == 6)
		{
			std::cout << avneetQuestions[questionChoice] << "\n";
		}

		while (true)
		{
			int response{0};

			std::cout << "What person said this? (Tyler (0), Francis (1), Gaurav (2), Nosa (3), Liam (4), Stefan (5), or Avneet (6))?: ";

			if (_trickster.getDefaultShadowShiftUses() > 0)
			{
				std::cout << "You have " << _trickster.getDefaultShadowShiftUses() << " shadow shifts\n";
				std::cout << "Do you want to sneak past this gate with a shadow shift (this does NOT unlock it) (y/n): ";

				char res{'n'};
				std::cin >> res;

				if (res == 'y')
				{
					_trickster.setDefaultShadowShiftUses(_trickster.getDefaultShadowShiftUses() - 1);
					// TODO: implement skipping the gate through the map
					break;
				}
				else
				{
					continue;
				}
			}

			std::cin >> response;

			if (response || response == 0)
			{
				if (response == person)
				{
					std::cout << "That's correct!\n";
					std::cout << "The old door swings open revealing another passage\n";

					std::cout << "Points Increase: +" << pointsValue << "pts\n";

					Map[PlayX][PlayY][4] = 0;
					setCompleted(true);
					_trickster.adjustPoints(pointsValue);
					break;
				}
				else
				{
					std::cout << "That's incorrect\n!";
					std::cout << "The sturdy door remains closed\n";
					std::cout << "Points Decrease: -1pt\n";
					_trickster.adjustPoints(-1);
				}
			}
			else
			{
				std::cout << "Please enter a response!\n";
				continue;
			}
		}
		break;
	}
}