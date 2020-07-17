#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

#define fileName "WIFI.txt"

int main()
{
	system("netsh wlan show profiles > " fileName);

	ifstream file;
	char data[100][100];
	int index = 0;
	int wifiIndex = 0;
	int chosenWifiNum;
	char chosenWifiName[100] = {0};
	file.open(fileName);
	if (!file.is_open())
	{
		cout << fileName" couldn't be opened";
	}
	else
	{
		for (int i = 0; i < 100; i++)
		{
			file.getline(data[i], 100);
		}
		file.close();
		cout << "       WIFI LIST" << endl;
		for (int i = 9; data[i][0]!= 0; i++)
		{
			index++;
			cout << index << ". ";
			for (int j = 27; data[i][j] != 0;j++)
			{
				
				cout << data[i][j];
			}
			cout << endl;
		}

		cout <<endl<< "Which password do you wish to see, 1-" << index<<"?: ";
		cin >> chosenWifiNum;

		for (int j = 27; data[9+ chosenWifiNum -1][j] != 0; j++)
		{
			chosenWifiName[wifiIndex] = data[9 + chosenWifiNum - 1][j];
			wifiIndex++;
		}
		cout <<endl<< "YOU CHOSE: "<<chosenWifiName<<endl;

		string WifiName = chosenWifiName;
		WifiName = "netsh wlan show profile "+WifiName+" key=clear > " fileName;
		for (int i = 0; i < 100; i++)
		{
			chosenWifiName[i] = 0;
		}
		for (int i = 0; i < WifiName.length(); i++)
		{
			chosenWifiName[i] = WifiName[i];
		}
		system(chosenWifiName);

		
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				data[i][j] = 0;
			}
		}
		
		file.open(fileName);
		if (!file.is_open())
		{
			cout << fileName" couldn't be opened";
		}
		else
		{
			bool haspass = false;
			for (int i = 0; i < 100; i++)
			{
				file.getline(data[i], 100);
			}
			for (int i = 0; i<100;i++)
			{
				if (data[i][4] == 'K' && data[i][5] == 'e'&& data[i][6] == 'y'&& data[i][8] == 'C'&& data[i][9] == 'o'&& data[i][10] == 'n' && data[i][11] == 't')
				{
					haspass = true;
					cout << "PASSWORD: ";
					for (int j = 29; data[i][j] != 0;j++)
					{
						cout << data[i][j];
					}
					cout << endl;
				}
			}
			cout << endl;
			if (!haspass)
			{
				cout << "PASSWORD: NONE/COULDN'T FIND"<<endl;
			}
			remove(fileName);
			system("pause");
		}
	}
}