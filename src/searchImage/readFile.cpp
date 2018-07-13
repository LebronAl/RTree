#include "stdafx.h"
#include<string>
#include<fstream>
#include<sstream>
#include"readFile.h"
using namespace std;

void readFeature(string filename, vector<vector<double>>& Array)
{
	ifstream inFile(filename);
	if (!inFile.is_open())
	{
		fprintf(stderr, "%s not exist\n", filename.c_str());
		return;
	}
	string lineArray;
	vector<double> tempArray;
	getline(inFile, lineArray,'t');
	getline(inFile, lineArray, 't');
	inFile.ignore();
	//getline(inFile, lineArray);
	while (getline(inFile, lineArray,'r'))
	{
		stringstream numbersTemp;
		numbersTemp << lineArray;
		string str;
		int number = 0;
		while (getline(numbersTemp, str,' '))
		{
			stringstream numberTemp;
			numberTemp << str;
			numberTemp >> number;
			tempArray.push_back(number);
		}
		double max = 0;
		double min = 0;
		for (int i = 0; i < tempArray.size(); i++)                       //��һ��
		{
			if (tempArray[i] > max)
				max = tempArray[i];
			if (tempArray[i] < min)
				min = tempArray[i];
		}
		for (int i = 0; i < tempArray.size(); i++)
		{
			if(max != 0)
				tempArray[i] = (tempArray[i] - min) / (max - min);
		}
		Array.push_back(tempArray);
		tempArray.clear();
		inFile.ignore(5);
	}
	Array[Array.size() - 1].pop_back();
	Array[Array.size() - 1].pop_back();
	inFile.close();
}

void readImage(string filename, vector<string> &Array)
{
	ifstream inFile(filename);
	if (!inFile.is_open())
	{
		fprintf(stderr, "%s not exist\n", filename.c_str());
		return;
	}
	string str;
	while (getline(inFile, str))
	{
		Array.push_back(str);
	}
	inFile.close();
}