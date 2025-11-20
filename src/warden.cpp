#include "warden.h"
#include "player.h"
#include "guardian.h"
#include "ravager.h"
#include "trickster.h"

Warden::Warden()
{
	pointsValue = 5; // per question, so three questions by default 5 pts * 3 questions = 15 pts total
	assignTruthfulness();
}

bool Warden::getIsTruthful()
{
	return isTruthful;
}

void Warden::setIsTruthful(bool inputIsTruthful)
{
	isTruthful = inputIsTruthful;
}

void Warden::assignTruthfulness()
{
	setIsTruthful(makeRandomNum(0, 1));
}

std::string Warden::getQuestion(int person, int q)
{
	switch (person)
	{
	case 0:
		return tylerQuestions[q];
	case 1:
		return francisQuestions[q];
	case 2:
		return gauravQuestions[q];
	case 3:
		return nosaQuestions[q];
	case 4:
		return liamQuestions[q];
	case 5:
		return stefanQuestions[q];
	case 6:
		return avneetQuestions[q];
	}

	return "";
}

std::string Warden::getAnswer(int person, int q)
{
	switch (person)
	{
	case 0:
		return isTruthful ? tylerAns[q] : tylerFalseAns[q];
	case 1:
		return isTruthful ? francisAns[q] : francisFalseAns[q];
	case 2:
		return isTruthful ? gauravAns[q] : gauravFalseAns[q];
	case 3:
		return isTruthful ? nosaAns[q] : nosaFalseAns[q];
	case 4:
		return isTruthful ? liamAns[q] : liamFalseAns[q];
	case 5:
		return isTruthful ? stefanAns[q] : stefanFalseAns[q];
	case 6:
		return isTruthful ? avneetAns[q] : avneetFalseAns[q];
	}

	return "";
}

bool Warden::questionUsedPrev(std::vector<std::vector<int>> usedQuestions, int newPerson, int newQ)
{
	for (int i{0}; i < usedQuestions.size(); i++)
	{
		if (usedQuestions[i][0] == newPerson && usedQuestions[i][1] == newQ)
		{
			return true;
		}
	}

	return false;
}

void Warden::loadPrompt(Player &_player, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
	int questionsCorrect{0};
	int questionsCount{3};
	std::vector<std::vector<int>> usedQuestions; // inner vector contains two int: person, questionChoice

	for (int i{0}; i < questionsCount; i++)
	{
		int person{0};
		int questionChoice{0};

		while (true)
		{
			person = makeRandomNum(0, 6); // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
			questionChoice = makeRandomNum(0, 2);

			// logic for making sure questions are not repeated
			if (!questionUsedPrev(usedQuestions, person, questionChoice))
			{
				usedQuestions.push_back({});
				usedQuestions[i].push_back(person);
				usedQuestions[i].push_back(questionChoice);
				break;
			}
		}

		std::cout << "You ask: " << getQuestion(person, questionChoice) << "\n";
		std::cout << "The Warden responds: " << getAnswer(person, questionChoice) << "\n";

		char res{'n'};

		std::cout << "Is the Warden telling the truth (y/n)?: ";
		std::cin >> res;

		bool correct = (isTruthful && res == 'y') || (!isTruthful && res == 'n');

		if (correct)
		{
			std::cout << "That's correct!\n";
			std::cout << "The Warden's decaying skin crumbles into a heap of dust, blown away in the passageway's breeze.\n";

			std::cout << "Points Increase: +" << pointsValue << "pts\n";

			Map[PlayX][PlayY][5] = 0;
			setCompleted(true);
			_player.adjustPoints(pointsValue);
			questionsCorrect++;
			continue;
		}
		else
		{
			std::cout << "That's incorrect\n!";
			std::cout << "The Warden lets out a bellowing scream as the smell of decaying flesh arises from his mouth.\n";
		}
	}
	if (questionsCorrect < 2)
	{ // if majority of questions asked were incorrect
		std::cout << "Unforunately, a majority of questions asked were incorrect (" << questionsCorrect << " / " << questionsCount << ")\n";
		std::cout << "Points Decrease: -25\% of current points = " << _player.getPoints() << "*" << "0.75 = " << std::floor(_player.getPoints() * 0.75f) << "\n";
		_player.setPoints(std::floor(_player.getPoints() * 0.75f));
	}
}
void Warden::loadPrompt(Guardian &_guardian, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
	int questionsCorrect{0};
	int questionsCount{3};
	std::vector<std::vector<int>> usedQuestions; // inner vector contains two int: person, questionChoice

	for (int i{0}; i < questionsCount; i++)
	{
		int person{0};
		int questionChoice{0};

		while (true)
		{
			person = makeRandomNum(0, 6); // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
			questionChoice = makeRandomNum(0, 2);

			// logic for making sure questions are not repeated
			if (!questionUsedPrev(usedQuestions, person, questionChoice))
			{
				usedQuestions.push_back({});
				usedQuestions[i].push_back(person);
				usedQuestions[i].push_back(questionChoice);
				break;
			}
		}

		std::cout << "You ask: " << getQuestion(person, questionChoice) << "\n";
		std::cout << "The Warden responds: " << getAnswer(person, questionChoice) << "\n";

		char res{'n'};

		std::cout << "Is the Warden telling the truth (y/n)?: ";
		std::cin >> res;

		bool correct = (isTruthful && res == 'y') || (!isTruthful && res == 'n');

		if (correct)
		{
			std::cout << "That's correct!\n";
			std::cout << "The Warden's decaying skin crumbles into a heap of dust, blown away in the passageway's breeze.\n";

			std::cout << "Points Increase: +" << pointsValue << "pts\n";

			Map[PlayX][PlayY][5] = 0;
			setCompleted(true);
			_guardian.adjustPoints(pointsValue);
			questionsCorrect++;
			continue;
		}
		else
		{
			std::cout << "That's incorrect\n!";
			std::cout << "The Warden lets out a bellowing scream as the smell of decaying flesh arises from his mouth.\n";
		}
	}
	if (questionsCorrect < 2)
	{ // if majority of questions asked were incorrect
		std::cout << "Unforunately, a majority of questions asked were incorrect (" << questionsCorrect << " / " << questionsCount << ")\n";

		if (_guardian.getLives() > 0)
		{
			std::cout << "Bulwark The Guardian bravely provides a life\n";
			std::cout << "No Points Are Lost\n";

			_guardian.decrementLives();
		}
		else
		{
			std::cout << "You have no more lives!\n";
			std::cout << "Points Decrease: -25\% of current points = " << _guardian.getPoints() << "*" << "0.75 = " << std::floor(_guardian.getPoints() * 0.75f) << "\n";
			_guardian.setPoints(std::floor(_guardian.getPoints() * 0.75f));
			_guardian.adjustPoints(-1);
		}
		// _player.setPoints(std::floor(_player.getPoints() * 0.75f));
	}
}
void Warden::loadPrompt(Ravager &_ravager, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
	int questionsCorrect{0};
	int questionsCount{3};
	std::vector<std::vector<int>> usedQuestions; // inner vector contains two int: person, questionChoice

	for (int i{0}; i < questionsCount; i++)
	{
		int person{0};
		int questionChoice{0};

		while (true)
		{
			person = makeRandomNum(0, 6); // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
			questionChoice = makeRandomNum(0, 2);

			// logic for making sure questions are not repeated
			if (!questionUsedPrev(usedQuestions, person, questionChoice))
			{
				usedQuestions.push_back({});
				usedQuestions[i].push_back(person);
				usedQuestions[i].push_back(questionChoice);
				break;
			}
		}

		std::cout << "You ask: " << getQuestion(person, questionChoice) << "\n";
		std::cout << "The Warden responds: " << getAnswer(person, questionChoice) << "\n";

		char res{'n'};

		std::cout << "Is the Warden telling the truth (y/n)?: ";
		std::cin >> res;

		bool correct = (isTruthful && res == 'y') || (!isTruthful && res == 'n');

		if (correct)
		{
			std::cout << "That's correct!\n";
			std::cout << "The Warden's decaying skin crumbles into a heap of dust, blown away in the passageway's breeze.\n";

			std::cout << "Points Increase: +" << pointsValue << "pts\n";

			Map[PlayX][PlayY][5] = 0;
			setCompleted(true);
			_ravager.adjustPoints(pointsValue);
			questionsCorrect++;
			continue;
		}
		else
		{
			std::cout << "That's incorrect\n!";
			std::cout << "The Warden lets out a bellowing scream as the smell of decaying flesh arises from his mouth.\n";
		}
	}
	if (questionsCorrect < 2)
	{ // if majority of questions asked were incorrect
		std::cout << "Unforunately, a majority of questions asked were incorrect (" << questionsCorrect << " / " << questionsCount << ")\n";
		std::cout << "Points Decrease: -25\% of current points = " << _ravager.getPoints() << "*" << "0.75 = " << std::floor(_ravager.getPoints() * 0.75f) << "\n";
		_ravager.setPoints(std::floor(_ravager.getPoints() * 0.75f));
	}
}
void Warden::loadPrompt(Trickster &_trickster, std::vector<std::vector<std::vector<bool>>> &Map, int PlayX, int PlayY)
{
	int questionsCorrect{0};
	int questionsCount{3};
	std::vector<std::vector<int>> usedQuestions; // inner vector contains two int: person, questionChoice

	for (int i{0}; i < questionsCount; i++)
	{
		int person{0};
		int questionChoice{0};

		while (true)
		{
			person = makeRandomNum(0, 6); // 0 - Tyler, 1 - Francis, 2 - Gaurav, 3 - Nosa, 4 - Liam, 5 - Stefan, 6 - Avneet
			questionChoice = makeRandomNum(0, 2);

			// logic for making sure questions are not repeated
			if (!questionUsedPrev(usedQuestions, person, questionChoice))
			{
				usedQuestions.push_back({});
				usedQuestions[i].push_back(person);
				usedQuestions[i].push_back(questionChoice);
				break;
			}
		}

		std::cout << "You ask: " << getQuestion(person, questionChoice) << "\n";
		std::cout << "The Warden responds: " << getAnswer(person, questionChoice) << "\n";

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

		char res{'n'};

		std::cout << "Is the Warden telling the truth (y/n)?: ";
		std::cin >> res;

		bool correct = (isTruthful && res == 'y') || (!isTruthful && res == 'n');

		if (correct)
		{
			std::cout << "That's correct!\n";
			std::cout << "The Warden's decaying skin crumbles into a heap of dust, blown away in the passageway's breeze.\n";

			std::cout << "Points Increase: +" << pointsValue << "pts\n";

			Map[PlayX][PlayY][5] = 0;
			setCompleted(true);
			_trickster.adjustPoints(pointsValue);
			questionsCorrect++;
			continue;
		}
		else
		{
			std::cout << "That's incorrect\n!";
			std::cout << "The Warden lets out a bellowing scream as the smell of decaying flesh arises from his mouth.\n";
		}
	}
	if (questionsCorrect < 2)
	{ // if majority of questions asked were incorrect
		std::cout << "Unforunately, a majority of questions asked were incorrect (" << questionsCorrect << " / " << questionsCount << ")\n";
		std::cout << "Points Decrease: -25\% of current points = " << _trickster.getPoints() << "*" << "0.75 = " << std::floor(_trickster.getPoints() * 0.75f) << "\n";
		_trickster.setPoints(std::floor(_trickster.getPoints() * 0.75f));
	}
}