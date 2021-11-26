﻿#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

void workMap()
{
	map <string, int> myMap; // Работа с Map
	string inputStr;
	string buff = "";
	getline(cin, inputStr);
	int i = 0;
	int buffNumber = 0;
	while (i < inputStr.length())
	{
		buffNumber = i;
		if (buffNumber >= inputStr.length())
		{
			if (i == 0)
			{
				std::cout << "Input string is empty" << endl;
			}
			else
			{
				std::cout << "Input string is over" << endl;
			}
			break;
		}
		while ((inputStr[buffNumber] != ' ') and (buffNumber != inputStr.length()))
		{
			buff.push_back(inputStr[buffNumber]);
			buffNumber++;
		}
		myMap[buff]++;
		buff.clear();
		i = buffNumber + 1;
	}
	map <string, int>::iterator it = myMap.begin();
	for (int j = 0; it != myMap.end(); it++, j++) {
		std::cout << j + 1 << ") Слово " << it->first << ", Количество " << it->second << endl;
	}
}


void workVector()
{
	try
	{
		int length1, length2;
		std::cout << "Введите размер первого вектора" << endl;
		cin >> length1;
		std::cout << "Введите размер второго вектора" << endl;
		cin >> length2;
		if (length1 < 1 || length2 < 1)
		{
			throw std::out_of_range("Один или оба вектора имеют недопустимую длину");
		}

		vector <int> vect1(length1);
		vector <int> vect2(length2);


		srand(time(NULL));
		float sum1(0), sum2(0);

		//Заполнение vect1 и вывод
		for (int i = 0; i < length1; i++)
		{
			vect1[i] = rand() % 201 - 100;
			std::cout << vect1[i] << " ";
		}
		std::cout << endl;

		//Заполнение vect2 и вывод
		for (int i = 0; i < length2; i++)
		{
			vect2[i] = rand() % 101 - 100;
			std::cout << vect2[i] << " ";
		}
		std::cout << endl;

		//Среднее арифметическое значений вектора 1
		for (int i = 0; i < length1; i++)
		{
			sum1 += vect1[i];
		}
		std::cout << "Среднее арифметическое вектора vect1 = " << sum1 / length1 << endl;

		//Среднее арифметическое значений вектора 2
		for (int i = 0; i < length2; i++)
		{
			sum2 += vect2[i];
		}
		std::cout << "Среднее арифметическое вектора vect2 = " << sum2 / length2 << endl;

		//Определение длин меньшей и большей строки
		int min, max;
		if (vect1.size() < vect2.size())
		{
			min = vect1.size();
			max = vect2.size();
		}
		else if (vect1.size() != vect2.size())
		{
			min = vect2.size();
			max = vect1.size();
		}
		else
		{
			min = vect1.size();
			max = min;
		}

		//Вывод пересекающихся элементов векторов
		if (min == vect1.size())
		{
			for (int i = 0; i < min; i++)
			{
				for (int j = i; j < max; j++)
				{
					if (vect1[i] == vect2[j])
					{
						std::cout << vect1[i] << " ";
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < min; i++)
			{
				for (int j = i; j < max; j++)
				{
					if (vect2[i] == vect1[j])
					{
						std::cout << vect2[i] << " ";
					}
				}
			}
			std::cout << endl;
		}

	}
	
	catch (std::out_of_range e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
}

void printStack(int i, vector<vector<int>>& matrix)
{
	vector<bool> used(matrix.size(), false);
	stack<int> st;

	while (i != -1)
	{
		if (used[i] == false)
		{
			used[i] = true;

			for (int j = 0; j < matrix.size(); j++)
				if (matrix[i][j] == 1 && used[j] == false) st.push(j);
		}

		if (!st.empty())
		{
			i = st.top();
			st.pop();
		}
		else i = -1;
	}

	for (bool a : used)
	{
		cout << a << ' ';
	}
	cout << endl;
}

void workStack()
{
	int count;
	cin >> count;
	const int vertexCount = count;
	vector<vector<int>> matrix(vertexCount, vector<int>(vertexCount,0));
	int x;
	for (int i = 0; i < vertexCount; i++)
	{
		matrix[i][i] = 1;
		do
		{
			cin >> x;
			if (x != 0)
			{
				matrix[i][x - 1] = 1;
			}
		} while (cin.peek() != '\n');
	}
	for (int i = 0; i < vertexCount; i++) printStack(i, matrix);
}


int main()
{
	setlocale(LC_ALL, "Russian");

	workMap();
	workVector();
	workStack();

	return 0;
}
