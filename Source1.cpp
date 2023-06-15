#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string UnderScore(40, '_');

class BranchFinances
{
private:
	const double Stavka = 50;
	const double Procent = 0.07;
	const double FixViryhka = 270;
	const double Zarplata = 35;
	const double Mrakobortsi = 15;
public:
	BranchFinances() {}

	double GrossProfit() 
	{
		srand(time(nullptr));
		return rand() % 251 + 250;
	}

	double MonthRent() 
	{
		if (GrossProfit() > FixViryhka)
			return Stavka + (GrossProfit() - FixViryhka) * Procent; 
		else return Stavka;
	}

	double TotalExpenses() 
	{
		return Zarplata + MonthRent() + Mrakobortsi;
	}

	void ShowMeMyExpences()
	{
		cout << endl << UnderScore << endl <<
			"Ежемесячные расходы:" << endl
			<< "Зарплаты: " << Zarplata << "*" << endl
			<< "Аренда помещения: " << MonthRent() << endl
			<< "Охрана Мракоборцами: " << Mrakobortsi
			<< endl << UnderScore << endl <<
			"Общие ежемесячные расходы филиала: " << TotalExpenses()
			<< endl << UnderScore << "\n\n" << "Прибыль чистая: ";
	}

	double NetProfit()
	{
		return GrossProfit() - TotalExpenses(); 
	}

	~BranchFinances() {}
};

class NewBranch :public BranchFinances
{
private:
	string BranchName;
public:
	NewBranch(string Name)
	{
		BranchName = Name;
		cout << "Добро пожаловать в " << BranchName << " филиал Оливандера!"
			<< endl << UnderScore << "\n\n"; 
	}
	~NewBranch()
	{
		cout << endl << "Приятного дня!";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите название вашей лавки!";
	string MyBranchName;
	cin >> MyBranchName;

	NewBranch MyBranch(MyBranchName);

	cout << "Прибыль: " << MyBranch.GrossProfit();
	MyBranch.TotalExpenses();
	MyBranch.ShowMeMyExpences();
	cout << MyBranch.NetProfit();
}
