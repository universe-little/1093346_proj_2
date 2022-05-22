#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0;
string NT[8] = { "SN","SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" };
string NT1[8] = { "SN","SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" };
string NT2[8] = { "SN","SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" };
string NT3[8] = { "SN","SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" };
string NT4[8] = { "SN","SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" };
string NT5[8] = { "SN","SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" };
string NT6[8] = { "SN","SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" };
string NT7[8] = { "SN","SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" ,"SN" };
vector<int>mispredict;
vector<int>entry_num;
vector<string>branch;
vector<char>history;
vector<char>history1;
vector<char>history2;
vector<char>history3;
vector<char>history4;
vector<char>history5;
vector<char>history6;
vector<char>history7;
vector<char>history_test;
char iftaken = 'N';
int entry = 0;
int entry_n = 0;

void Li(string s)
{
	int branch_num = 0;
	int entry_n_tem = 0;
	if (branch.size() == 0)
	{
		branch.push_back(s);
		entry_num.push_back(entry_n);
		entry_n++;
	}
	for (int i = 0; i < branch.size(); i++)
	{
		string check = branch[i];
		if (s != check && i == branch.size() - 1)
		{
			branch.push_back(s);
			if (entry_n == entry)
			{
				entry_n = 0;
			}
			entry_num.push_back(entry_n);
			branch_num = branch.size() - 1;
			entry_n_tem = entry_n;
			entry_n++;
		}
		else if (s == check)
		{
			branch_num = i;
			entry_n_tem = entry_num[i];
			break;
		}
	}
	cout << "entry: " << entry_n_tem << "          " << branch[branch_num] << endl;

	int n = s.size() - 6;
	string s1 = s.substr(3, 2);
	int n1 = stoi(s.substr(6));
	if (s1 == "R2")
	{
		r2 = n1;
	}
	else if(s1=="R3")
	{
		r3 = n1;
	}
	else if (s1 == "R4")
	{
		r4 = n1;
	}
	else if (s1 == "R5")
	{
		r5 = n1;
	}
	else if (s1 == "R6")
	{
		r6 = n1;
	}

	string compare1;
	char compare;
	int temp;
	iftaken = 'N';
	if (entry_n_tem == 0)
	{
		if (history[0] == 'N')
		{
			if (history[1] == 'N')
			{
				if (history[2] == 'N')
				{
					temp = 0;
					compare1 = NT[0];
					cout << "(000";
				}
				else if (history[2] == 'T')
				{
					temp = 1;
					compare1 = NT[1];
					cout << "(001";
				}
			}
			else if (history[1] == 'T')
			{
				if (history[2] == 'N')
				{
					temp = 2;
					compare1 = NT[2];
					cout << "(010";
				}
				else if (history[2] == 'T')
				{
					temp = 3;
					compare1 = NT[3];
					cout << "(011";
				}
			}
		}
		else if (history[0] == 'T')
		{
			if (history[1] == 'N')
			{
				if (history[2] == 'N')
				{
					temp = 4;
					compare1 = NT[4];
					cout << "(100";
				}
				else if (history[2] == 'T')
				{
					temp = 5;
					compare1 = NT[5];
					cout << "(101";
				}
			}
			else if (history[1] == 'T')
			{
				if (history[2] == 'N')
				{
					temp = 6;
					compare1 = NT[6];
					cout << "(110";
				}
				else if (history[2] == 'T')
				{
					temp = 7;
					compare1 = NT[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 1)
	{
		if (history1[0] == 'N')
		{
			if (history1[1] == 'N')
			{
				if (history1[2] == 'N')
				{
					temp = 0;
					compare1 = NT1[0];
					cout << "(000";
				}
				else if (history1[2] == 'T')
				{
					temp = 1;
					compare1 = NT1[1];
					cout << "(001";
				}
			}
			else if (history1[1] == 'T')
			{
				if (history1[2] == 'N')
				{
					temp = 2;
					compare1 = NT1[2];
					cout << "(010";
				}
				else if (history1[2] == 'T')
				{
					temp = 3;
					compare1 = NT1[3];
					cout << "(011";
				}
			}
		}
		else if (history1[0] == 'T')
		{
			if (history1[1] == 'N')
			{
				if (history1[2] == 'N')
				{
					temp = 4;
					compare1 = NT1[4];
					cout << "(100";
				}
				else if (history1[2] == 'T')
				{
					temp = 5;
					compare1 = NT1[5];
					cout << "(101";
				}
			}
			else if (history1[1] == 'T')
			{
				if (history1[2] == 'N')
				{
					temp = 6;
					compare1 = NT1[6];
					cout << "(110";
				}
				else if (history1[2] == 'T')
				{
					temp = 7;
					compare1 = NT1[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 2)
	{
		if (history2[0] == 'N')
		{
			if (history2[1] == 'N')
			{
				if (history2[2] == 'N')
				{
					temp = 0;
					compare1 = NT2[0];
					cout << "(000";
				}
				else if (history2[2] == 'T')
				{
					temp = 1;
					compare1 = NT2[1];
					cout << "(001";
				}
			}
			else if (history2[1] == 'T')
			{
				if (history2[2] == 'N')
				{
					temp = 2;
					compare1 = NT2[2];
					cout << "(010";
				}
				else if (history2[2] == 'T')
				{
					temp = 3;
					compare1 = NT2[3];
					cout << "(011";
				}
			}
		}
		else if (history2[0] == 'T')
		{
			if (history2[1] == 'N')
			{
				if (history2[2] == 'N')
				{
					temp = 4;
					compare1 = NT2[4];
					cout << "(100";
				}
				else if (history2[2] == 'T')
				{
					temp = 5;
					compare1 = NT2[5];
					cout << "(101";
				}
			}
			else if (history2[1] == 'T')
			{
				if (history2[2] == 'N')
				{
					temp = 6;
					compare1 = NT2[6];
					cout << "(110";
				}
				else if (history2[2] == 'T')
				{
					temp = 7;
					compare1 = NT2[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 3)
	{
		if (history3[0] == 'N')
		{
			if (history3[1] == 'N')
			{
				if (history3[2] == 'N')
				{
					temp = 0;
					compare1 = NT3[0];
					cout << "(000";
				}
				else if (history3[2] == 'T')
				{
					temp = 1;
					compare1 = NT3[1];
					cout << "(001";
				}
			}
			else if (history3[1] == 'T')
			{
				if (history3[2] == 'N')
				{
					temp = 2;
					compare1 = NT3[2];
					cout << "(010";
				}
				else if (history3[2] == 'T')
				{
					temp = 3;
					compare1 = NT3[3];
					cout << "(011";
				}
			}
		}
		else if (history3[0] == 'T')
		{
			if (history3[1] == 'N')
			{
				if (history3[2] == 'N')
				{
					temp = 4;
					compare1 = NT3[4];
					cout << "(100";
				}
				else if (history3[2] == 'T')
				{
					temp = 5;
					compare1 = NT3[5];
					cout << "(101";
				}
			}
			else if (history3[1] == 'T')
			{
				if (history3[2] == 'N')
				{
					temp = 6;
					compare1 = NT3[6];
					cout << "(110";
				}
				else if (history3[2] == 'T')
				{
					temp = 7;
					compare1 = NT3[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 4)
	{
		if (history4[0] == 'N')
		{
			if (history4[1] == 'N')
			{
				if (history4[2] == 'N')
				{
					temp = 0;
					compare1 = NT4[0];
					cout << "(000";
				}
				else if (history4[2] == 'T')
				{
					temp = 1;
					compare1 = NT4[1];
					cout << "(001";
				}
			}
			else if (history4[1] == 'T')
			{
				if (history4[2] == 'N')
				{
					temp = 2;
					compare1 = NT4[2];
					cout << "(010";
				}
				else if (history4[2] == 'T')
				{
					temp = 3;
					compare1 = NT4[3];
					cout << "(011";
				}
			}
		}
		else if (history4[0] == 'T')
		{
			if (history4[1] == 'N')
			{
				if (history4[2] == 'N')
				{
					temp = 4;
					compare1 = NT4[4];
					cout << "(100";
				}
				else if (history4[2] == 'T')
				{
					temp = 5;
					compare1 = NT4[5];
					cout << "(101";
				}
			}
			else if (history4[1] == 'T')
			{
				if (history4[2] == 'N')
				{
					temp = 6;
					compare1 = NT4[6];
					cout << "(110";
				}
				else if (history4[2] == 'T')
				{
					temp = 7;
					compare1 = NT4[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 5)
	{
		if (history5[0] == 'N')
		{
			if (history5[1] == 'N')
			{
				if (history5[2] == 'N')
				{
					temp = 0;
					compare1 = NT5[0];
					cout << "(000";
				}
				else if (history5[2] == 'T')
				{
					temp = 1;
					compare1 = NT5[1];
					cout << "(001";
				}
			}
			else if (history5[1] == 'T')
			{
				if (history5[2] == 'N')
				{
					temp = 2;
					compare1 = NT5[2];
					cout << "(010";
				}
				else if (history5[2] == 'T')
				{
					temp = 3;
					compare1 = NT5[3];
					cout << "(011";
				}
			}
		}
		else if (history5[0] == 'T')
		{
			if (history5[1] == 'N')
			{
				if (history5[2] == 'N')
				{
					temp = 4;
					compare1 = NT5[4];
					cout << "(100";
				}
				else if (history5[2] == 'T')
				{
					temp = 5;
					compare1 = NT5[5];
					cout << "(101";
				}
			}
			else if (history5[1] == 'T')
			{
				if (history5[2] == 'N')
				{
					temp = 6;
					compare1 = NT5[6];
					cout << "(110";
				}
				else if (history5[2] == 'T')
				{
					temp = 7;
					compare1 = NT5[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 6)
	{
		if (history6[0] == 'N')
		{
			if (history6[1] == 'N')
			{
				if (history6[2] == 'N')
				{
					temp = 0;
					compare1 = NT6[0];
					cout << "(000";
				}
				else if (history6[2] == 'T')
				{
					temp = 1;
					compare1 = NT6[1];
					cout << "(001";
				}
			}
			else if (history6[1] == 'T')
			{
				if (history6[2] == 'N')
				{
					temp = 2;
					compare1 = NT6[2];
					cout << "(010";
				}
				else if (history6[2] == 'T')
				{
					temp = 3;
					compare1 = NT6[3];
					cout << "(011";
				}
			}
		}
		else if (history6[0] == 'T')
		{
			if (history6[1] == 'N')
			{
				if (history6[2] == 'N')
				{
					temp = 4;
					compare1 = NT6[4];
					cout << "(100";
				}
				else if (history6[2] == 'T')
				{
					temp = 5;
					compare1 = NT6[5];
					cout << "(101";
				}
			}
			else if (history6[1] == 'T')
			{
				if (history6[2] == 'N')
				{
					temp = 6;
					compare1 = NT6[6];
					cout << "(110";
				}
				else if (history6[2] == 'T')
				{
					temp = 7;
					compare1 = NT6[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 7)
	{
		if (history7[0] == 'N')
		{
			if (history7[1] == 'N')
			{
				if (history7[2] == 'N')
				{
					temp = 0;
					compare1 = NT7[0];
					cout << "(000";
				}
				else if (history7[2] == 'T')
				{
					temp = 1;
					compare1 = NT7[1];
					cout << "(001";
				}
			}
			else if (history7[1] == 'T')
			{
				if (history7[2] == 'N')
				{
					temp = 2;
					compare1 = NT7[2];
					cout << "(010";
				}
				else if (history7[2] == 'T')
				{
					temp = 3;
					compare1 = NT7[3];
					cout << "(011";
				}
			}
		}
		else if (history7[0] == 'T')
		{
			if (history7[1] == 'N')
			{
				if (history7[2] == 'N')
				{
					temp = 4;
					compare1 = NT7[4];
					cout << "(100";
				}
				else if (history7[2] == 'T')
				{
					temp = 5;
					compare1 = NT7[5];
					cout << "(101";
				}
			}
			else if (history7[1] == 'T')
			{
				if (history7[2] == 'N')
				{
					temp = 6;
					compare1 = NT7[6];
					cout << "(110";
				}
				else if (history7[2] == 'T')
				{
					temp = 7;
					compare1 = NT7[7];
					cout << "(111";
				}
			}
		}
	}
	if (compare1 == "SN")
	{
		compare = 'N';
	}
	else if (compare1 == "WN")
	{
		compare = 'N';
	}
	else if (compare1 == "ST")
	{
		compare = 'T';
	}
	else if (compare1 == "WT")
	{
		compare = 'T';
	}
	if (compare == iftaken)
	{
		if (entry_n_tem == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
			if (NT[temp] == "WN")
			{
				NT[temp] = "SN";
			}
		}
		else if (entry_n_tem == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT1[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
			if (NT1[temp] == "WN")
			{
				NT1[temp] = "SN";
			}
		}
		else if (entry_n_tem == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT2[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
			if (NT2[temp] == "WN")
			{
				NT2[temp] = "SN";
			}
		}
		else if (entry_n_tem == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT3[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
			if (NT3[temp] == "WN")
			{
				NT3[temp] = "SN";
			}
		}
		else if (entry_n_tem == 4)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT4[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
			if (NT4[temp] == "WN")
			{
				NT4[temp] = "SN";
			}
		}
		else if (entry_n_tem == 5)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT5[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
			if (NT5[temp] == "WN")
			{
				NT5[temp] = "SN";
			}
		}
		else if (entry_n_tem == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
			if (NT6[temp] == "WN")
			{
				NT6[temp] = "SN";
			}
		}
		else if (entry_n_tem == 7)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT7[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
			if (NT7[temp] == "WN")
			{
				NT7[temp] = "SN";
			}
		}
	}
	else
	{
		if (entry_n_tem == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT[i];
			}
			if (NT[temp] == "ST")
			{
				NT[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT[temp] == "WT")
			{
				NT[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
		}
		else if (entry_n_tem == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT1[i];
			}
			if (NT1[temp] == "ST")
			{
				NT1[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT1[temp] == "WT")
			{
				NT1[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
		}
		else if (entry_n_tem == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT2[i];
			}
			if (NT2[temp] == "ST")
			{
				NT2[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT2[temp] == "WT")
			{
				NT2[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
		}
		else if (entry_n_tem == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT3[i];
			}
			if (NT3[temp] == "ST")
			{
				NT3[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT3[temp] == "WT")
			{
				NT3[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
		}
		else if (entry_n_tem == 4)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT4[i];
			}
			if (NT4[temp] == "ST")
			{
				NT4[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT4[temp] == "WT")
			{
				NT4[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
		}
		else if (entry_n_tem == 5)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT5[i];
			}
			if (NT5[temp] == "ST")
			{
				NT5[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT5[temp] == "WT")
			{
				NT5[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
		}
		else if (entry_n_tem == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			if (NT6[temp] == "ST")
			{
				NT6[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT6[temp] == "WT")
			{
				NT6[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
		}
		else if (entry_n_tem == 7)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT7[i];
			}
			if (NT7[temp] == "ST")
			{
				NT7[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT7[temp] == "WT")
			{
				NT7[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
		}
	}
	if (entry_n_tem == 0)
	{
		history.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history.size(); i++)
		{
			history_test.push_back(history[i]);
		}
		history.clear();
		for (int i = 0; i < 3; i++)
		{
			history.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 1)
	{
		history1.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history1.size(); i++)
		{
			history_test.push_back(history1[i]);
		}
		history1.clear();
		for (int i = 0; i < 3; i++)
		{
			history1.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 2)
	{
		history2.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history2.size(); i++)
		{
			history_test.push_back(history2[i]);
		}
		history2.clear();
		for (int i = 0; i < 3; i++)
		{
			history2.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 3)
	{
		history3.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history3.size(); i++)
		{
			history_test.push_back(history3[i]);
		}
		history3.clear();
		for (int i = 0; i < 3; i++)
		{
			history3.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 4)
	{
		history4.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history4.size(); i++)
		{
			history_test.push_back(history4[i]);
		}
		history4.clear();
		for (int i = 0; i < 3; i++)
		{
			history4.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 5)
	{
		history5.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history5.size(); i++)
		{
			history_test.push_back(history5[i]);
		}
		history5.clear();
		for (int i = 0; i < 3; i++)
		{
			history5.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 6)
	{
		history6.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history6.size(); i++)
		{
			history_test.push_back(history6[i]);
		}
		history6.clear();
		for (int i = 0; i < 3; i++)
		{
			history6.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 7)
	{
		history7.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history7.size(); i++)
		{
			history_test.push_back(history7[i]);
		}
		history7.clear();
		for (int i = 0; i < 3; i++)
		{
			history7.push_back(history_test[i]);
		}
	}
}
void Add(string s)
{
	int branch_num = 0;
	int entry_n_tem = 0;
	if (branch.size() == 0)
	{
		branch.push_back(s);
		entry_num.push_back(entry_n);
		entry_n++;
	}
	for (int i = 0; i < branch.size(); i++)
	{
		string check = branch[i];
		if (s != check && i == branch.size() - 1)
		{
			branch.push_back(s);
			if (entry_n == entry)
			{
				entry_n = 0;
			}
			entry_num.push_back(entry_n);
			branch_num = branch.size() - 1;
			entry_n_tem = entry_n;
			entry_n++;
		}
		else if (s == check)
		{
			branch_num = i;
			entry_n_tem = entry_num[i];
			break;
		}
	}
	cout << "entry: " << entry_n_tem << "          " << branch[branch_num] << endl;

	string s1 = s.substr(4, 2);
	string s2 = s.substr(7, 2);
	string s3 = s.substr(10, 2);
	int a = 0, b = 0, c = 0;
	if (s2 == "R2")
	{
		b = r2;
	}
	else if (s2 == "R3")
	{
		b = r3;
	}
	else if (s2 == "R4")
	{
		b = r4;
	}
	else if (s2 == "R5")
	{
		b = r5;
	}
	else if (s2 == "R6")
	{
		b = r6;
	}
	if (s3 == "R2")
	{
		c = r2;
	}
	else if (s3 == "R3")
	{
		c = r3;
	}
	else if (s3 == "R4")
	{
		c = r4;
	}
	else if (s3 == "R5")
	{
		c = r5;
	}
	else if (s3 == "R6")
	{
		c = r6;
	}
	a = b + c;
	if (s1 == "R2")
	{
		r2 = a;
	}
	else if (s1 == "R3")
	{
		r3 = a;
	}
	else if (s1 == "R4")
	{
		r4 = a;
	}
	else if (s1 == "R5")
	{
		r5 = a;
	}
	else if (s1 == "R6")
	{
		r6 = a;
	}

	string compare1;
	char compare;
	int temp;
	iftaken = 'N';
	if (entry_n_tem == 0)
	{
		if (history[0] == 'N')
		{
			if (history[1] == 'N')
			{
				if (history[2] == 'N')
				{
					temp = 0;
					compare1 = NT[0];
					cout << "(000";
				}
				else if (history[2] == 'T')
				{
					temp = 1;
					compare1 = NT[1];
					cout << "(001";
				}
			}
			else if (history[1] == 'T')
			{
				if (history[2] == 'N')
				{
					temp = 2;
					compare1 = NT[2];
					cout << "(010";
				}
				else if (history[2] == 'T')
				{
					temp = 3;
					compare1 = NT[3];
					cout << "(011";
				}
			}
		}
		else if (history[0] == 'T')
		{
			if (history[1] == 'N')
			{
				if (history[2] == 'N')
				{
					temp = 4;
					compare1 = NT[4];
					cout << "(100";
				}
				else if (history[2] == 'T')
				{
					temp = 5;
					compare1 = NT[5];
					cout << "(101";
				}
			}
			else if (history[1] == 'T')
			{
				if (history[2] == 'N')
				{
					temp = 6;
					compare1 = NT[6];
					cout << "(110";
				}
				else if (history[2] == 'T')
				{
					temp = 7;
					compare1 = NT[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 1)
	{
		if (history1[0] == 'N')
		{
			if (history1[1] == 'N')
			{
				if (history1[2] == 'N')
				{
					temp = 0;
					compare1 = NT1[0];
					cout << "(000";
				}
				else if (history1[2] == 'T')
				{
					temp = 1;
					compare1 = NT1[1];
					cout << "(001";
				}
			}
			else if (history1[1] == 'T')
			{
				if (history1[2] == 'N')
				{
					temp = 2;
					compare1 = NT1[2];
					cout << "(010";
				}
				else if (history1[2] == 'T')
				{
					temp = 3;
					compare1 = NT1[3];
					cout << "(011";
				}
			}
		}
		else if (history1[0] == 'T')
		{
			if (history1[1] == 'N')
			{
				if (history1[2] == 'N')
				{
					temp = 4;
					compare1 = NT1[4];
					cout << "(100";
				}
				else if (history1[2] == 'T')
				{
					temp = 5;
					compare1 = NT1[5];
					cout << "(101";
				}
			}
			else if (history1[1] == 'T')
			{
				if (history1[2] == 'N')
				{
					temp = 6;
					compare1 = NT1[6];
					cout << "(110";
				}
				else if (history1[2] == 'T')
				{
					temp = 7;
					compare1 = NT1[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 2)
	{
		if (history2[0] == 'N')
		{
			if (history2[1] == 'N')
			{
				if (history2[2] == 'N')
				{
					temp = 0;
					compare1 = NT2[0];
					cout << "(000";
				}
				else if (history2[2] == 'T')
				{
					temp = 1;
					compare1 = NT2[1];
					cout << "(001";
				}
			}
			else if (history2[1] == 'T')
			{
				if (history2[2] == 'N')
				{
					temp = 2;
					compare1 = NT2[2];
					cout << "(010";
				}
				else if (history2[2] == 'T')
				{
					temp = 3;
					compare1 = NT2[3];
					cout << "(011";
				}
			}
		}
		else if (history2[0] == 'T')
		{
			if (history2[1] == 'N')
			{
				if (history2[2] == 'N')
				{
					temp = 4;
					compare1 = NT2[4];
					cout << "(100";
				}
				else if (history2[2] == 'T')
				{
					temp = 5;
					compare1 = NT2[5];
					cout << "(101";
				}
			}
			else if (history2[1] == 'T')
			{
				if (history2[2] == 'N')
				{
					temp = 6;
					compare1 = NT2[6];
					cout << "(110";
				}
				else if (history2[2] == 'T')
				{
					temp = 7;
					compare1 = NT2[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 3)
	{
		if (history3[0] == 'N')
		{
			if (history3[1] == 'N')
			{
				if (history3[2] == 'N')
				{
					temp = 0;
					compare1 = NT3[0];
					cout << "(000";
				}
				else if (history3[2] == 'T')
				{
					temp = 1;
					compare1 = NT3[1];
					cout << "(001";
				}
			}
			else if (history3[1] == 'T')
			{
				if (history3[2] == 'N')
				{
					temp = 2;
					compare1 = NT3[2];
					cout << "(010";
				}
				else if (history3[2] == 'T')
				{
					temp = 3;
					compare1 = NT3[3];
					cout << "(011";
				}
			}
		}
		else if (history3[0] == 'T')
		{
			if (history3[1] == 'N')
			{
				if (history3[2] == 'N')
				{
					temp = 4;
					compare1 = NT3[4];
					cout << "(100";
				}
				else if (history3[2] == 'T')
				{
					temp = 5;
					compare1 = NT3[5];
					cout << "(101";
				}
			}
			else if (history3[1] == 'T')
			{
				if (history3[2] == 'N')
				{
					temp = 6;
					compare1 = NT3[6];
					cout << "(110";
				}
				else if (history3[2] == 'T')
				{
					temp = 7;
					compare1 = NT3[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 4)
	{
		if (history4[0] == 'N')
		{
			if (history4[1] == 'N')
			{
				if (history4[2] == 'N')
				{
					temp = 0;
					compare1 = NT4[0];
					cout << "(000";
				}
				else if (history4[2] == 'T')
				{
					temp = 1;
					compare1 = NT4[1];
					cout << "(001";
				}
			}
			else if (history4[1] == 'T')
			{
				if (history4[2] == 'N')
				{
					temp = 2;
					compare1 = NT4[2];
					cout << "(010";
				}
				else if (history4[2] == 'T')
				{
					temp = 3;
					compare1 = NT4[3];
					cout << "(011";
				}
			}
		}
		else if (history4[0] == 'T')
		{
			if (history4[1] == 'N')
			{
				if (history4[2] == 'N')
				{
					temp = 4;
					compare1 = NT4[4];
					cout << "(100";
				}
				else if (history4[2] == 'T')
				{
					temp = 5;
					compare1 = NT4[5];
					cout << "(101";
				}
			}
			else if (history4[1] == 'T')
			{
				if (history4[2] == 'N')
				{
					temp = 6;
					compare1 = NT4[6];
					cout << "(110";
				}
				else if (history4[2] == 'T')
				{
					temp = 7;
					compare1 = NT4[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 5)
	{
		if (history5[0] == 'N')
		{
			if (history5[1] == 'N')
			{
				if (history5[2] == 'N')
				{
					temp = 0;
					compare1 = NT5[0];
					cout << "(000";
				}
				else if (history5[2] == 'T')
				{
					temp = 1;
					compare1 = NT5[1];
					cout << "(001";
				}
			}
			else if (history5[1] == 'T')
			{
				if (history5[2] == 'N')
				{
					temp = 2;
					compare1 = NT5[2];
					cout << "(010";
				}
				else if (history5[2] == 'T')
				{
					temp = 3;
					compare1 = NT5[3];
					cout << "(011";
				}
			}
		}
		else if (history5[0] == 'T')
		{
			if (history5[1] == 'N')
			{
				if (history5[2] == 'N')
				{
					temp = 4;
					compare1 = NT5[4];
					cout << "(100";
				}
				else if (history5[2] == 'T')
				{
					temp = 5;
					compare1 = NT5[5];
					cout << "(101";
				}
			}
			else if (history5[1] == 'T')
			{
				if (history5[2] == 'N')
				{
					temp = 6;
					compare1 = NT5[6];
					cout << "(110";
				}
				else if (history5[2] == 'T')
				{
					temp = 7;
					compare1 = NT5[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 6)
	{
		if (history6[0] == 'N')
		{
			if (history6[1] == 'N')
			{
				if (history6[2] == 'N')
				{
					temp = 0;
					compare1 = NT6[0];
					cout << "(000";
				}
				else if (history6[2] == 'T')
				{
					temp = 1;
					compare1 = NT6[1];
					cout << "(001";
				}
			}
			else if (history6[1] == 'T')
			{
				if (history6[2] == 'N')
				{
					temp = 2;
					compare1 = NT6[2];
					cout << "(010";
				}
				else if (history6[2] == 'T')
				{
					temp = 3;
					compare1 = NT6[3];
					cout << "(011";
				}
			}
		}
		else if (history6[0] == 'T')
		{
			if (history6[1] == 'N')
			{
				if (history6[2] == 'N')
				{
					temp = 4;
					compare1 = NT6[4];
					cout << "(100";
				}
				else if (history6[2] == 'T')
				{
					temp = 5;
					compare1 = NT6[5];
					cout << "(101";
				}
			}
			else if (history6[1] == 'T')
			{
				if (history6[2] == 'N')
				{
					temp = 6;
					compare1 = NT6[6];
					cout << "(110";
				}
				else if (history6[2] == 'T')
				{
					temp = 7;
					compare1 = NT6[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 7)
	{
		if (history7[0] == 'N')
		{
			if (history7[1] == 'N')
			{
				if (history7[2] == 'N')
				{
					temp = 0;
					compare1 = NT7[0];
					cout << "(000";
				}
				else if (history7[2] == 'T')
				{
					temp = 1;
					compare1 = NT7[1];
					cout << "(001";
				}
			}
			else if (history7[1] == 'T')
			{
				if (history7[2] == 'N')
				{
					temp = 2;
					compare1 = NT7[2];
					cout << "(010";
				}
				else if (history7[2] == 'T')
				{
					temp = 3;
					compare1 = NT7[3];
					cout << "(011";
				}
			}
		}
		else if (history7[0] == 'T')
		{
			if (history7[1] == 'N')
			{
				if (history7[2] == 'N')
				{
					temp = 4;
					compare1 = NT7[4];
					cout << "(100";
				}
				else if (history7[2] == 'T')
				{
					temp = 5;
					compare1 = NT7[5];
					cout << "(101";
				}
			}
			else if (history7[1] == 'T')
			{
				if (history7[2] == 'N')
				{
					temp = 6;
					compare1 = NT7[6];
					cout << "(110";
				}
				else if (history7[2] == 'T')
				{
					temp = 7;
					compare1 = NT7[7];
					cout << "(111";
				}
			}
		}
	}
	if (compare1 == "SN")
	{
		compare = 'N';
	}
	else if (compare1 == "WN")
	{
		compare = 'N';
	}
	else if (compare1 == "ST")
	{
		compare = 'T';
	}
	else if (compare1 == "WT")
	{
		compare = 'T';
	}
	if (compare == iftaken)
	{
		if (entry_n_tem == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
			if (NT[temp] == "WN")
			{
				NT[temp] = "SN";
			}
		}
		else if (entry_n_tem == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT1[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
			if (NT1[temp] == "WN")
			{
				NT1[temp] = "SN";
			}
		}
		else if (entry_n_tem == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT2[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
			if (NT2[temp] == "WN")
			{
				NT2[temp] = "SN";
			}
		}
		else if (entry_n_tem == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT3[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
			if (NT3[temp] == "WN")
			{
				NT3[temp] = "SN";
			}
		}
		else if (entry_n_tem == 4)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT4[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
			if (NT4[temp] == "WN")
			{
				NT4[temp] = "SN";
			}
		}
		else if (entry_n_tem == 5)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT5[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
			if (NT5[temp] == "WN")
			{
				NT5[temp] = "SN";
			}
		}
		else if (entry_n_tem == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
			if (NT6[temp] == "WN")
			{
				NT6[temp] = "SN";
			}
		}
		else if (entry_n_tem == 7)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT7[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
			if (NT7[temp] == "WN")
			{
				NT7[temp] = "SN";
			}
		}
	}
	else
	{
		if (entry_n_tem == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT[i];
			}
			if (NT[temp] == "ST")
			{
				NT[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT[temp] == "WT")
			{
				NT[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
		}
		else if (entry_n_tem == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT1[i];
			}
			if (NT1[temp] == "ST")
			{
				NT1[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT1[temp] == "WT")
			{
				NT1[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
		}
		else if (entry_n_tem == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT2[i];
			}
			if (NT2[temp] == "ST")
			{
				NT2[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT2[temp] == "WT")
			{
				NT2[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
		}
		else if (entry_n_tem == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT3[i];
			}
			if (NT3[temp] == "ST")
			{
				NT3[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT3[temp] == "WT")
			{
				NT3[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
		}
		else if (entry_n_tem == 4)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT4[i];
			}
			if (NT4[temp] == "ST")
			{
				NT4[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT4[temp] == "WT")
			{
				NT4[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
		}
		else if (entry_n_tem == 5)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT5[i];
			}
			if (NT5[temp] == "ST")
			{
				NT5[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT5[temp] == "WT")
			{
				NT5[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
		}
		else if (entry_n_tem == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			if (NT6[temp] == "ST")
			{
				NT6[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT6[temp] == "WT")
			{
				NT6[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
		}
		else if (entry_n_tem == 7)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT7[i];
			}
			if (NT7[temp] == "ST")
			{
				NT7[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT7[temp] == "WT")
			{
				NT7[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
		}
	}
	if (entry_n_tem == 0)
	{
		history.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history.size(); i++)
		{
			history_test.push_back(history[i]);
		}
		history.clear();
		for (int i = 0; i < 3; i++)
		{
			history.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 1)
	{
		history1.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history1.size(); i++)
		{
			history_test.push_back(history1[i]);
		}
		history1.clear();
		for (int i = 0; i < 3; i++)
		{
			history1.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 2)
	{
		history2.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history2.size(); i++)
		{
			history_test.push_back(history2[i]);
		}
		history2.clear();
		for (int i = 0; i < 3; i++)
		{
			history2.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 3)
	{
		history3.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history3.size(); i++)
		{
			history_test.push_back(history3[i]);
		}
		history3.clear();
		for (int i = 0; i < 3; i++)
		{
			history3.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 4)
	{
		history4.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history4.size(); i++)
		{
			history_test.push_back(history4[i]);
		}
		history4.clear();
		for (int i = 0; i < 3; i++)
		{
			history4.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 5)
	{
		history5.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history5.size(); i++)
		{
			history_test.push_back(history5[i]);
		}
		history5.clear();
		for (int i = 0; i < 3; i++)
		{
			history5.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 6)
	{
		history6.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history6.size(); i++)
		{
			history_test.push_back(history6[i]);
		}
		history6.clear();
		for (int i = 0; i < 3; i++)
		{
			history6.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 7)
	{
		history7.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history7.size(); i++)
		{
			history_test.push_back(history7[i]);
		}
		history7.clear();
		for (int i = 0; i < 3; i++)
		{
			history7.push_back(history_test[i]);
		}
	}
}
void Addi(string s)
{
	int branch_num = 0;
	int entry_n_tem = 0;
	if (branch.size() == 0)
	{
		branch.push_back(s);
		entry_num.push_back(entry_n);
		entry_n++;
	}
	for (int i = 0; i < branch.size(); i++)
	{
		string check = branch[i];
		if (s != check && i == branch.size() - 1)
		{
			branch.push_back(s);
			if (entry_n == entry)
			{
				entry_n = 0;
			}
			entry_num.push_back(entry_n);
			branch_num = branch.size() - 1;
			entry_n_tem = entry_n;
			entry_n++;
		}
		else if (s == check)
		{
			branch_num = i;
			entry_n_tem = entry_num[i];
			break;
		}
	}
	cout << "entry: " << entry_n_tem << "          " << branch[branch_num] << endl;

	string s1 = s.substr(5, 2);
	string s2 = s.substr(8, 2);
	int a = 0, b = 0;
	int c = stoi(s.substr(11));
	if (s2 == "R2")
	{
		b = r2;
	}
	else if (s2 == "R3")
	{
		b = r3;
	}
	else if (s2 == "R4")
	{
		b = r4;
	}
	else if (s2 == "R5")
	{
		b = r5;
	}
	else if (s2 == "R6")
	{
		b = r6;
	}
	a = b + c;
	if (s1 == "R2")
	{
		r2 = a;
	}
	else if (s1 == "R3")
	{
		r3 = a;
	}
	else if (s1 == "R4")
	{
		r4 = a;
	}
	else if (s1 == "R5")
	{
		r5 = a;
	}
	else if (s1 == "R6")
	{
		r6 = a;
	}

	string compare1;
	char compare;
	int temp;
	iftaken = 'N';
	if (entry_n_tem == 0)
	{
		if (history[0] == 'N')
		{
			if (history[1] == 'N')
			{
				if (history[2] == 'N')
				{
					temp = 0;
					compare1 = NT[0];
					cout << "(000";
				}
				else if (history[2] == 'T')
				{
					temp = 1;
					compare1 = NT[1];
					cout << "(001";
				}
			}
			else if (history[1] == 'T')
			{
				if (history[2] == 'N')
				{
					temp = 2;
					compare1 = NT[2];
					cout << "(010";
				}
				else if (history[2] == 'T')
				{
					temp = 3;
					compare1 = NT[3];
					cout << "(011";
				}
			}
		}
		else if (history[0] == 'T')
		{
			if (history[1] == 'N')
			{
				if (history[2] == 'N')
				{
					temp = 4;
					compare1 = NT[4];
					cout << "(100";
				}
				else if (history[2] == 'T')
				{
					temp = 5;
					compare1 = NT[5];
					cout << "(101";
				}
			}
			else if (history[1] == 'T')
			{
				if (history[2] == 'N')
				{
					temp = 6;
					compare1 = NT[6];
					cout << "(110";
				}
				else if (history[2] == 'T')
				{
					temp = 7;
					compare1 = NT[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 1)
	{
		if (history1[0] == 'N')
		{
			if (history1[1] == 'N')
			{
				if (history1[2] == 'N')
				{
					temp = 0;
					compare1 = NT1[0];
					cout << "(000";
				}
				else if (history1[2] == 'T')
				{
					temp = 1;
					compare1 = NT1[1];
					cout << "(001";
				}
			}
			else if (history1[1] == 'T')
			{
				if (history1[2] == 'N')
				{
					temp = 2;
					compare1 = NT1[2];
					cout << "(010";
				}
				else if (history1[2] == 'T')
				{
					temp = 3;
					compare1 = NT1[3];
					cout << "(011";
				}
			}
		}
		else if (history1[0] == 'T')
		{
			if (history1[1] == 'N')
			{
				if (history1[2] == 'N')
				{
					temp = 4;
					compare1 = NT1[4];
					cout << "(100";
				}
				else if (history1[2] == 'T')
				{
					temp = 5;
					compare1 = NT1[5];
					cout << "(101";
				}
			}
			else if (history1[1] == 'T')
			{
				if (history1[2] == 'N')
				{
					temp = 6;
					compare1 = NT1[6];
					cout << "(110";
				}
				else if (history1[2] == 'T')
				{
					temp = 7;
					compare1 = NT1[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 2)
	{
		if (history2[0] == 'N')
		{
			if (history2[1] == 'N')
			{
				if (history2[2] == 'N')
				{
					temp = 0;
					compare1 = NT2[0];
					cout << "(000";
				}
				else if (history2[2] == 'T')
				{
					temp = 1;
					compare1 = NT2[1];
					cout << "(001";
				}
			}
			else if (history2[1] == 'T')
			{
				if (history2[2] == 'N')
				{
					temp = 2;
					compare1 = NT2[2];
					cout << "(010";
				}
				else if (history2[2] == 'T')
				{
					temp = 3;
					compare1 = NT2[3];
					cout << "(011";
				}
			}
		}
		else if (history2[0] == 'T')
		{
			if (history2[1] == 'N')
			{
				if (history2[2] == 'N')
				{
					temp = 4;
					compare1 = NT2[4];
					cout << "(100";
				}
				else if (history2[2] == 'T')
				{
					temp = 5;
					compare1 = NT2[5];
					cout << "(101";
				}
			}
			else if (history2[1] == 'T')
			{
				if (history2[2] == 'N')
				{
					temp = 6;
					compare1 = NT2[6];
					cout << "(110";
				}
				else if (history2[2] == 'T')
				{
					temp = 7;
					compare1 = NT2[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 3)
	{
		if (history3[0] == 'N')
		{
			if (history3[1] == 'N')
			{
				if (history3[2] == 'N')
				{
					temp = 0;
					compare1 = NT3[0];
					cout << "(000";
				}
				else if (history3[2] == 'T')
				{
					temp = 1;
					compare1 = NT3[1];
					cout << "(001";
				}
			}
			else if (history3[1] == 'T')
			{
				if (history3[2] == 'N')
				{
					temp = 2;
					compare1 = NT3[2];
					cout << "(010";
				}
				else if (history3[2] == 'T')
				{
					temp = 3;
					compare1 = NT3[3];
					cout << "(011";
				}
			}
		}
		else if (history3[0] == 'T')
		{
			if (history3[1] == 'N')
			{
				if (history3[2] == 'N')
				{
					temp = 4;
					compare1 = NT3[4];
					cout << "(100";
				}
				else if (history3[2] == 'T')
				{
					temp = 5;
					compare1 = NT3[5];
					cout << "(101";
				}
			}
			else if (history3[1] == 'T')
			{
				if (history3[2] == 'N')
				{
					temp = 6;
					compare1 = NT3[6];
					cout << "(110";
				}
				else if (history3[2] == 'T')
				{
					temp = 7;
					compare1 = NT3[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 4)
	{
		if (history4[0] == 'N')
		{
			if (history4[1] == 'N')
			{
				if (history4[2] == 'N')
				{
					temp = 0;
					compare1 = NT4[0];
					cout << "(000";
				}
				else if (history4[2] == 'T')
				{
					temp = 1;
					compare1 = NT4[1];
					cout << "(001";
				}
			}
			else if (history4[1] == 'T')
			{
				if (history4[2] == 'N')
				{
					temp = 2;
					compare1 = NT4[2];
					cout << "(010";
				}
				else if (history4[2] == 'T')
				{
					temp = 3;
					compare1 = NT4[3];
					cout << "(011";
				}
			}
		}
		else if (history4[0] == 'T')
		{
			if (history4[1] == 'N')
			{
				if (history4[2] == 'N')
				{
					temp = 4;
					compare1 = NT4[4];
					cout << "(100";
				}
				else if (history4[2] == 'T')
				{
					temp = 5;
					compare1 = NT4[5];
					cout << "(101";
				}
			}
			else if (history4[1] == 'T')
			{
				if (history4[2] == 'N')
				{
					temp = 6;
					compare1 = NT4[6];
					cout << "(110";
				}
				else if (history4[2] == 'T')
				{
					temp = 7;
					compare1 = NT4[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 5)
	{
		if (history5[0] == 'N')
		{
			if (history5[1] == 'N')
			{
				if (history5[2] == 'N')
				{
					temp = 0;
					compare1 = NT5[0];
					cout << "(000";
				}
				else if (history5[2] == 'T')
				{
					temp = 1;
					compare1 = NT5[1];
					cout << "(001";
				}
			}
			else if (history5[1] == 'T')
			{
				if (history5[2] == 'N')
				{
					temp = 2;
					compare1 = NT5[2];
					cout << "(010";
				}
				else if (history5[2] == 'T')
				{
					temp = 3;
					compare1 = NT5[3];
					cout << "(011";
				}
			}
		}
		else if (history5[0] == 'T')
		{
			if (history5[1] == 'N')
			{
				if (history5[2] == 'N')
				{
					temp = 4;
					compare1 = NT5[4];
					cout << "(100";
				}
				else if (history5[2] == 'T')
				{
					temp = 5;
					compare1 = NT5[5];
					cout << "(101";
				}
			}
			else if (history5[1] == 'T')
			{
				if (history5[2] == 'N')
				{
					temp = 6;
					compare1 = NT5[6];
					cout << "(110";
				}
				else if (history5[2] == 'T')
				{
					temp = 7;
					compare1 = NT5[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 6)
	{
		if (history6[0] == 'N')
		{
			if (history6[1] == 'N')
			{
				if (history6[2] == 'N')
				{
					temp = 0;
					compare1 = NT6[0];
					cout << "(000";
				}
				else if (history6[2] == 'T')
				{
					temp = 1;
					compare1 = NT6[1];
					cout << "(001";
				}
			}
			else if (history6[1] == 'T')
			{
				if (history6[2] == 'N')
				{
					temp = 2;
					compare1 = NT6[2];
					cout << "(010";
				}
				else if (history6[2] == 'T')
				{
					temp = 3;
					compare1 = NT6[3];
					cout << "(011";
				}
			}
		}
		else if (history6[0] == 'T')
		{
			if (history6[1] == 'N')
			{
				if (history6[2] == 'N')
				{
					temp = 4;
					compare1 = NT6[4];
					cout << "(100";
				}
				else if (history6[2] == 'T')
				{
					temp = 5;
					compare1 = NT6[5];
					cout << "(101";
				}
			}
			else if (history6[1] == 'T')
			{
				if (history6[2] == 'N')
				{
					temp = 6;
					compare1 = NT6[6];
					cout << "(110";
				}
				else if (history6[2] == 'T')
				{
					temp = 7;
					compare1 = NT6[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 7)
	{
		if (history7[0] == 'N')
		{
			if (history7[1] == 'N')
			{
				if (history7[2] == 'N')
				{
					temp = 0;
					compare1 = NT7[0];
					cout << "(000";
				}
				else if (history7[2] == 'T')
				{
					temp = 1;
					compare1 = NT7[1];
					cout << "(001";
				}
			}
			else if (history7[1] == 'T')
			{
				if (history7[2] == 'N')
				{
					temp = 2;
					compare1 = NT7[2];
					cout << "(010";
				}
				else if (history7[2] == 'T')
				{
					temp = 3;
					compare1 = NT7[3];
					cout << "(011";
				}
			}
		}
		else if (history7[0] == 'T')
		{
			if (history7[1] == 'N')
			{
				if (history7[2] == 'N')
				{
					temp = 4;
					compare1 = NT7[4];
					cout << "(100";
				}
				else if (history7[2] == 'T')
				{
					temp = 5;
					compare1 = NT7[5];
					cout << "(101";
				}
			}
			else if (history7[1] == 'T')
			{
				if (history7[2] == 'N')
				{
					temp = 6;
					compare1 = NT7[6];
					cout << "(110";
				}
				else if (history7[2] == 'T')
				{
					temp = 7;
					compare1 = NT7[7];
					cout << "(111";
				}
			}
		}
	}
	if (compare1 == "SN")
	{
		compare = 'N';
	}
	else if (compare1 == "WN")
	{
		compare = 'N';
	}
	else if (compare1 == "ST")
	{
		compare = 'T';
	}
	else if (compare1 == "WT")
	{
		compare = 'T';
	}
	if (compare == iftaken)
	{
		if (entry_n_tem == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
			if (NT[temp] == "WN")
			{
				NT[temp] = "SN";
			}
		}
		else if (entry_n_tem == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT1[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
			if (NT1[temp] == "WN")
			{
				NT1[temp] = "SN";
			}
		}
		else if (entry_n_tem == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT2[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
			if (NT2[temp] == "WN")
			{
				NT2[temp] = "SN";
			}
		}
		else if (entry_n_tem == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT3[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
			if (NT3[temp] == "WN")
			{
				NT3[temp] = "SN";
			}
		}
		else if (entry_n_tem == 4)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT4[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
			if (NT4[temp] == "WN")
			{
				NT4[temp] = "SN";
			}
		}
		else if (entry_n_tem == 5)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT5[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
			if (NT5[temp] == "WN")
			{
				NT5[temp] = "SN";
			}
		}
		else if (entry_n_tem == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
			if (NT6[temp] == "WN")
			{
				NT6[temp] = "SN";
			}
		}
		else if (entry_n_tem == 7)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT7[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
			if (NT7[temp] == "WN")
			{
				NT7[temp] = "SN";
			}
		}
	}
	else
	{
		if (entry_n_tem == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT[i];
			}
			if (NT[temp] == "ST")
			{
				NT[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT[temp] == "WT")
			{
				NT[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
		}
		else if (entry_n_tem == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT1[i];
			}
			if (NT1[temp] == "ST")
			{
				NT1[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT1[temp] == "WT")
			{
				NT1[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
		}
		else if (entry_n_tem == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT2[i];
			}
			if (NT2[temp] == "ST")
			{
				NT2[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT2[temp] == "WT")
			{
				NT2[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
		}
		else if (entry_n_tem == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT3[i];
			}
			if (NT3[temp] == "ST")
			{
				NT3[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT3[temp] == "WT")
			{
				NT3[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
		}
		else if (entry_n_tem == 4)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT4[i];
			}
			if (NT4[temp] == "ST")
			{
				NT4[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT4[temp] == "WT")
			{
				NT4[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
		}
		else if (entry_n_tem == 5)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT5[i];
			}
			if (NT5[temp] == "ST")
			{
				NT5[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT5[temp] == "WT")
			{
				NT5[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
		}
		else if (entry_n_tem == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			if (NT6[temp] == "ST")
			{
				NT6[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT6[temp] == "WT")
			{
				NT6[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
		}
		else if (entry_n_tem == 7)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT7[i];
			}
			if (NT7[temp] == "ST")
			{
				NT7[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT7[temp] == "WT")
			{
				NT7[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
		}
	}
	if (entry_n_tem == 0)
	{
		history.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history.size(); i++)
		{
			history_test.push_back(history[i]);
		}
		history.clear();
		for (int i = 0; i < 3; i++)
		{
			history.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 1)
	{
		history1.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history1.size(); i++)
		{
			history_test.push_back(history1[i]);
		}
		history1.clear();
		for (int i = 0; i < 3; i++)
		{
			history1.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 2)
	{
		history2.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history2.size(); i++)
		{
			history_test.push_back(history2[i]);
		}
		history2.clear();
		for (int i = 0; i < 3; i++)
		{
			history2.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 3)
	{
		history3.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history3.size(); i++)
		{
			history_test.push_back(history3[i]);
		}
		history3.clear();
		for (int i = 0; i < 3; i++)
		{
			history3.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 4)
	{
		history4.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history4.size(); i++)
		{
			history_test.push_back(history4[i]);
		}
		history4.clear();
		for (int i = 0; i < 3; i++)
		{
			history4.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 5)
	{
		history5.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history5.size(); i++)
		{
			history_test.push_back(history5[i]);
		}
		history5.clear();
		for (int i = 0; i < 3; i++)
		{
			history5.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 6)
	{
		history6.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history6.size(); i++)
		{
			history_test.push_back(history6[i]);
		}
		history6.clear();
		for (int i = 0; i < 3; i++)
		{
			history6.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 7)
	{
		history7.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history7.size(); i++)
		{
			history_test.push_back(history7[i]);
		}
		history7.clear();
		for (int i = 0; i < 3; i++)
		{
			history7.push_back(history_test[i]);
		}
	}
}
void Andi(string s)
{
	int branch_num = 0;
	int entry_n_tem = 0;
	if (branch.size() == 0)
	{
		branch.push_back(s);
		entry_num.push_back(entry_n);
		entry_n++;
	}
	for (int i = 0; i < branch.size(); i++)
	{
		string check = branch[i];
		if (s != check && i == branch.size() - 1)
		{
			branch.push_back(s);
			if (entry_n == entry)
			{
				entry_n = 0;
			}
			entry_num.push_back(entry_n);
			branch_num = branch.size() - 1;
			entry_n_tem = entry_n;
			entry_n++;
		}
		else if (s == check)
		{
			branch_num = i;
			entry_n_tem = entry_num[i];
			break;
		}
	}
	cout << "entry: " << entry_n_tem << "          " << branch[branch_num] << endl;

	string s1 = s.substr(5, 2);
	string s2 = s.substr(8, 2);
	int a = 0, b = 0;
	int c = stoi(s.substr(11));
	c = c + 1;
	if (s2 == "R2")
	{
		b = r2;
	}
	else if (s2 == "R3")
	{
		b = r3;
	}
	else if (s2 == "R4")
	{
		b = r4;
	}
	else if (s2 == "R5")
	{
		b = r5;
	}
	else if (s2 == "R6")
	{
		b = r6;
	}
	a = b % c;
	if (s1 == "R2")
	{
		r2 = a;
	}
	else if (s1 == "R3")
	{
		r3 = a;
	}
	else if (s1 == "R4")
	{
		r4 = a;
	}
	else if (s1 == "R5")
	{
		r5 = a;
	}
	else if (s1 == "R6")
	{
		r6 = a;
	}

	string compare1;
	char compare;
	int temp;
	iftaken = 'N';
	if (entry_n_tem == 0)
	{
		if (history[0] == 'N')
		{
			if (history[1] == 'N')
			{
				if (history[2] == 'N')
				{
					temp = 0;
					compare1 = NT[0];
					cout << "(000";
				}
				else if (history[2] == 'T')
				{
					temp = 1;
					compare1 = NT[1];
					cout << "(001";
				}
			}
			else if (history[1] == 'T')
			{
				if (history[2] == 'N')
				{
					temp = 2;
					compare1 = NT[2];
					cout << "(010";
				}
				else if (history[2] == 'T')
				{
					temp = 3;
					compare1 = NT[3];
					cout << "(011";
				}
			}
		}
		else if (history[0] == 'T')
		{
			if (history[1] == 'N')
			{
				if (history[2] == 'N')
				{
					temp = 4;
					compare1 = NT[4];
					cout << "(100";
				}
				else if (history[2] == 'T')
				{
					temp = 5;
					compare1 = NT[5];
					cout << "(101";
				}
			}
			else if (history[1] == 'T')
			{
				if (history[2] == 'N')
				{
					temp = 6;
					compare1 = NT[6];
					cout << "(110";
				}
				else if (history[2] == 'T')
				{
					temp = 7;
					compare1 = NT[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 1)
	{
		if (history1[0] == 'N')
		{
			if (history1[1] == 'N')
			{
				if (history1[2] == 'N')
				{
					temp = 0;
					compare1 = NT1[0];
					cout << "(000";
				}
				else if (history1[2] == 'T')
				{
					temp = 1;
					compare1 = NT1[1];
					cout << "(001";
				}
			}
			else if (history1[1] == 'T')
			{
				if (history1[2] == 'N')
				{
					temp = 2;
					compare1 = NT1[2];
					cout << "(010";
				}
				else if (history1[2] == 'T')
				{
					temp = 3;
					compare1 = NT1[3];
					cout << "(011";
				}
			}
		}
		else if (history1[0] == 'T')
		{
			if (history1[1] == 'N')
			{
				if (history1[2] == 'N')
				{
					temp = 4;
					compare1 = NT1[4];
					cout << "(100";
				}
				else if (history1[2] == 'T')
				{
					temp = 5;
					compare1 = NT1[5];
					cout << "(101";
				}
			}
			else if (history1[1] == 'T')
			{
				if (history1[2] == 'N')
				{
					temp = 6;
					compare1 = NT1[6];
					cout << "(110";
				}
				else if (history1[2] == 'T')
				{
					temp = 7;
					compare1 = NT1[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 2)
	{
		if (history2[0] == 'N')
		{
			if (history2[1] == 'N')
			{
				if (history2[2] == 'N')
				{
					temp = 0;
					compare1 = NT2[0];
					cout << "(000";
				}
				else if (history2[2] == 'T')
				{
					temp = 1;
					compare1 = NT2[1];
					cout << "(001";
				}
			}
			else if (history2[1] == 'T')
			{
				if (history2[2] == 'N')
				{
					temp = 2;
					compare1 = NT2[2];
					cout << "(010";
				}
				else if (history2[2] == 'T')
				{
					temp = 3;
					compare1 = NT2[3];
					cout << "(011";
				}
			}
		}
		else if (history2[0] == 'T')
		{
			if (history2[1] == 'N')
			{
				if (history2[2] == 'N')
				{
					temp = 4;
					compare1 = NT2[4];
					cout << "(100";
				}
				else if (history2[2] == 'T')
				{
					temp = 5;
					compare1 = NT2[5];
					cout << "(101";
				}
			}
			else if (history2[1] == 'T')
			{
				if (history2[2] == 'N')
				{
					temp = 6;
					compare1 = NT2[6];
					cout << "(110";
				}
				else if (history2[2] == 'T')
				{
					temp = 7;
					compare1 = NT2[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 3)
	{
		if (history3[0] == 'N')
		{
			if (history3[1] == 'N')
			{
				if (history3[2] == 'N')
				{
					temp = 0;
					compare1 = NT3[0];
					cout << "(000";
				}
				else if (history3[2] == 'T')
				{
					temp = 1;
					compare1 = NT3[1];
					cout << "(001";
				}
			}
			else if (history3[1] == 'T')
			{
				if (history3[2] == 'N')
				{
					temp = 2;
					compare1 = NT3[2];
					cout << "(010";
				}
				else if (history3[2] == 'T')
				{
					temp = 3;
					compare1 = NT3[3];
					cout << "(011";
				}
			}
		}
		else if (history3[0] == 'T')
		{
			if (history3[1] == 'N')
			{
				if (history3[2] == 'N')
				{
					temp = 4;
					compare1 = NT3[4];
					cout << "(100";
				}
				else if (history3[2] == 'T')
				{
					temp = 5;
					compare1 = NT3[5];
					cout << "(101";
				}
			}
			else if (history3[1] == 'T')
			{
				if (history3[2] == 'N')
				{
					temp = 6;
					compare1 = NT3[6];
					cout << "(110";
				}
				else if (history3[2] == 'T')
				{
					temp = 7;
					compare1 = NT3[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 4)
	{
		if (history4[0] == 'N')
		{
			if (history4[1] == 'N')
			{
				if (history4[2] == 'N')
				{
					temp = 0;
					compare1 = NT4[0];
					cout << "(000";
				}
				else if (history4[2] == 'T')
				{
					temp = 1;
					compare1 = NT4[1];
					cout << "(001";
				}
			}
			else if (history4[1] == 'T')
			{
				if (history4[2] == 'N')
				{
					temp = 2;
					compare1 = NT4[2];
					cout << "(010";
				}
				else if (history4[2] == 'T')
				{
					temp = 3;
					compare1 = NT4[3];
					cout << "(011";
				}
			}
		}
		else if (history4[0] == 'T')
		{
			if (history4[1] == 'N')
			{
				if (history4[2] == 'N')
				{
					temp = 4;
					compare1 = NT4[4];
					cout << "(100";
				}
				else if (history4[2] == 'T')
				{
					temp = 5;
					compare1 = NT4[5];
					cout << "(101";
				}
			}
			else if (history4[1] == 'T')
			{
				if (history4[2] == 'N')
				{
					temp = 6;
					compare1 = NT4[6];
					cout << "(110";
				}
				else if (history4[2] == 'T')
				{
					temp = 7;
					compare1 = NT4[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 5)
	{
		if (history5[0] == 'N')
		{
			if (history5[1] == 'N')
			{
				if (history5[2] == 'N')
				{
					temp = 0;
					compare1 = NT5[0];
					cout << "(000";
				}
				else if (history5[2] == 'T')
				{
					temp = 1;
					compare1 = NT5[1];
					cout << "(001";
				}
			}
			else if (history5[1] == 'T')
			{
				if (history5[2] == 'N')
				{
					temp = 2;
					compare1 = NT5[2];
					cout << "(010";
				}
				else if (history5[2] == 'T')
				{
					temp = 3;
					compare1 = NT5[3];
					cout << "(011";
				}
			}
		}
		else if (history5[0] == 'T')
		{
			if (history5[1] == 'N')
			{
				if (history5[2] == 'N')
				{
					temp = 4;
					compare1 = NT5[4];
					cout << "(100";
				}
				else if (history5[2] == 'T')
				{
					temp = 5;
					compare1 = NT5[5];
					cout << "(101";
				}
			}
			else if (history5[1] == 'T')
			{
				if (history5[2] == 'N')
				{
					temp = 6;
					compare1 = NT5[6];
					cout << "(110";
				}
				else if (history5[2] == 'T')
				{
					temp = 7;
					compare1 = NT5[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 6)
	{
		if (history6[0] == 'N')
		{
			if (history6[1] == 'N')
			{
				if (history6[2] == 'N')
				{
					temp = 0;
					compare1 = NT6[0];
					cout << "(000";
				}
				else if (history6[2] == 'T')
				{
					temp = 1;
					compare1 = NT6[1];
					cout << "(001";
				}
			}
			else if (history6[1] == 'T')
			{
				if (history6[2] == 'N')
				{
					temp = 2;
					compare1 = NT6[2];
					cout << "(010";
				}
				else if (history6[2] == 'T')
				{
					temp = 3;
					compare1 = NT6[3];
					cout << "(011";
				}
			}
		}
		else if (history6[0] == 'T')
		{
			if (history6[1] == 'N')
			{
				if (history6[2] == 'N')
				{
					temp = 4;
					compare1 = NT6[4];
					cout << "(100";
				}
				else if (history6[2] == 'T')
				{
					temp = 5;
					compare1 = NT6[5];
					cout << "(101";
				}
			}
			else if (history6[1] == 'T')
			{
				if (history6[2] == 'N')
				{
					temp = 6;
					compare1 = NT6[6];
					cout << "(110";
				}
				else if (history6[2] == 'T')
				{
					temp = 7;
					compare1 = NT6[7];
					cout << "(111";
				}
			}
		}
	}
	else if (entry_n_tem == 7)
	{
		if (history7[0] == 'N')
		{
			if (history7[1] == 'N')
			{
				if (history7[2] == 'N')
				{
					temp = 0;
					compare1 = NT7[0];
					cout << "(000";
				}
				else if (history7[2] == 'T')
				{
					temp = 1;
					compare1 = NT7[1];
					cout << "(001";
				}
			}
			else if (history7[1] == 'T')
			{
				if (history7[2] == 'N')
				{
					temp = 2;
					compare1 = NT7[2];
					cout << "(010";
				}
				else if (history7[2] == 'T')
				{
					temp = 3;
					compare1 = NT7[3];
					cout << "(011";
				}
			}
		}
		else if (history7[0] == 'T')
		{
			if (history7[1] == 'N')
			{
				if (history7[2] == 'N')
				{
					temp = 4;
					compare1 = NT7[4];
					cout << "(100";
				}
				else if (history7[2] == 'T')
				{
					temp = 5;
					compare1 = NT7[5];
					cout << "(101";
				}
			}
			else if (history7[1] == 'T')
			{
				if (history7[2] == 'N')
				{
					temp = 6;
					compare1 = NT7[6];
					cout << "(110";
				}
				else if (history7[2] == 'T')
				{
					temp = 7;
					compare1 = NT7[7];
					cout << "(111";
				}
			}
		}
	}
	if (compare1 == "SN")
	{
		compare = 'N';
	}
	else if (compare1 == "WN")
	{
		compare = 'N';
	}
	else if (compare1 == "ST")
	{
		compare = 'T';
	}
	else if (compare1 == "WT")
	{
		compare = 'T';
	}
	if (compare == iftaken)
	{
		if (entry_n_tem == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
			if (NT[temp] == "WN")
			{
				NT[temp] = "SN";
			}
		}
		else if (entry_n_tem == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT1[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
			if (NT1[temp] == "WN")
			{
				NT1[temp] = "SN";
			}
		}
		else if (entry_n_tem == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT2[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
			if (NT2[temp] == "WN")
			{
				NT2[temp] = "SN";
			}
		}
		else if (entry_n_tem == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT3[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
			if (NT3[temp] == "WN")
			{
				NT3[temp] = "SN";
			}
		}
		else if (entry_n_tem == 4)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT4[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
			if (NT4[temp] == "WN")
			{
				NT4[temp] = "SN";
			}
		}
		else if (entry_n_tem == 5)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT5[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
			if (NT5[temp] == "WN")
			{
				NT5[temp] = "SN";
			}
		}
		else if (entry_n_tem == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
			if (NT6[temp] == "WN")
			{
				NT6[temp] = "SN";
			}
		}
		else if (entry_n_tem == 7)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT7[i];
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
			if (NT7[temp] == "WN")
			{
				NT7[temp] = "SN";
			}
		}
	}
	else
	{
		if (entry_n_tem == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT[i];
			}
			if (NT[temp] == "ST")
			{
				NT[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT[temp] == "WT")
			{
				NT[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
		}
		else if (entry_n_tem == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT1[i];
			}
			if (NT1[temp] == "ST")
			{
				NT1[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT1[temp] == "WT")
			{
				NT1[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
		}
		else if (entry_n_tem == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT2[i];
			}
			if (NT2[temp] == "ST")
			{
				NT2[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT2[temp] == "WT")
			{
				NT2[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
		}
		else if (entry_n_tem == 3)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT3[i];
			}
			if (NT3[temp] == "ST")
			{
				NT3[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT3[temp] == "WT")
			{
				NT3[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
		}
		else if (entry_n_tem == 4)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT4[i];
			}
			if (NT4[temp] == "ST")
			{
				NT4[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT4[temp] == "WT")
			{
				NT4[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
		}
		else if (entry_n_tem == 5)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT5[i];
			}
			if (NT5[temp] == "ST")
			{
				NT5[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT5[temp] == "WT")
			{
				NT5[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
		}
		else if (entry_n_tem == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			if (NT6[temp] == "ST")
			{
				NT6[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT6[temp] == "WT")
			{
				NT6[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
		}
		else if (entry_n_tem == 7)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT7[i];
			}
			if (NT7[temp] == "ST")
			{
				NT7[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT7[temp] == "WT")
			{
				NT7[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
		}
	}
	if (entry_n_tem == 0)
	{
		history.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history.size(); i++)
		{
			history_test.push_back(history[i]);
		}
		history.clear();
		for (int i = 0; i < 3; i++)
		{
			history.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 1)
	{
		history1.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history1.size(); i++)
		{
			history_test.push_back(history1[i]);
		}
		history1.clear();
		for (int i = 0; i < 3; i++)
		{
			history1.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 2)
	{
		history2.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history2.size(); i++)
		{
			history_test.push_back(history2[i]);
		}
		history2.clear();
		for (int i = 0; i < 3; i++)
		{
			history2.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 3)
	{
		history3.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history3.size(); i++)
		{
			history_test.push_back(history3[i]);
		}
		history3.clear();
		for (int i = 0; i < 3; i++)
		{
			history3.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 4)
	{
		history4.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history4.size(); i++)
		{
			history_test.push_back(history4[i]);
		}
		history4.clear();
		for (int i = 0; i < 3; i++)
		{
			history4.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 5)
	{
		history5.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history5.size(); i++)
		{
			history_test.push_back(history5[i]);
		}
		history5.clear();
		for (int i = 0; i < 3; i++)
		{
			history5.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 6)
	{
		history6.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history6.size(); i++)
		{
			history_test.push_back(history6[i]);
		}
		history6.clear();
		for (int i = 0; i < 3; i++)
		{
			history6.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 7)
	{
		history7.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history7.size(); i++)
		{
			history_test.push_back(history7[i]);
		}
		history7.clear();
		for (int i = 0; i < 3; i++)
		{
			history7.push_back(history_test[i]);
		}
	}
}
string Beq(string s)
{
	int branch_num = 0;
	int entry_n_tem = 0;
	if (branch.size() == 0)
	{
		branch.push_back(s);
		entry_num.push_back(entry_n);
		entry_n++;
	}
	for (int i = 0; i < branch.size(); i++)
	{
		string check = branch[i];
		if (s != check && i == branch.size() - 1)
		{
			branch.push_back(s);
			if (entry_n == entry)
			{
				entry_n = 0;
			}
			entry_num.push_back(entry_n);
			branch_num = branch.size() - 1;
			entry_n_tem = entry_n;
			entry_n++;
		}
		else if (s == check)
		{
			branch_num = i;
			entry_n_tem = entry_num[i];
			break;
		}
	}
	cout << "entry: " << entry_n_tem  << "          " << branch[branch_num] << endl;

	int a = 0, b = 0;
	string s1 = s.substr(4, 2);
	string s2 = s.substr(7, 2);
	string s3;
	if (s1 == "R2")
	{
		a = r2;
	}
	else if (s1 == "R3")
	{
		a = r3;
	}
	else if (s1 == "R4")
	{
		a = r4;
	}
	else if (s1 == "R5")
	{
		a = r5;
	}
	else if (s1 == "R6")
	{
		a = r6;
	}
	if (s2 == "R2")
	{
		b = r2;
	}
	else if (s2 == "R3")
	{
		b = r3;
	}
	else if (s2 == "R4")
	{
		b = r4;
	}
	else if (s2 == "R5")
	{
		b = r5;
	}
	else if (s2 == "R6")
	{
		b = r6;
	}
	if (a == b)
	{
		string tem1 = s.substr(10);
		for (int i = 0; i < tem1.size(); i++)
		{
			if (tem1[i] != 9 && tem1[i] != 32)
			{
				s3.push_back(tem1[i]);
			}
		}
		s3.push_back(':');
		//s3 = s.substr(10);
		string compare1;
		char compare;
		int temp;
		iftaken = 'T';
		if (entry_n_tem == 0)
		{
			if (history[0] == 'N')
			{
				if (history[1] == 'N')
				{
					if (history[2] == 'N')
					{
						temp = 0;
						compare1 = NT[0];
						cout << "(000";
					}
					else if (history[2] == 'T')
					{
						temp = 1;
						compare1 = NT[1];
						cout << "(001";
					}
				}
				else if (history[1] == 'T')
				{
					if (history[2] == 'N')
					{
						temp = 2;
						compare1 = NT[2];
						cout << "(010";
					}
					else if (history[2] == 'T')
					{
						temp = 3;
						compare1 = NT[3];
						cout << "(011";
					}
				}
			}
			else if (history[0] == 'T')
			{
				if (history[1] == 'N')
				{
					if (history[2] == 'N')
					{
						temp = 4;
						compare1 = NT[4];
						cout << "(100";
					}
					else if (history[2] == 'T')
					{
						temp = 5;
						compare1 = NT[5];
						cout << "(101";
					}
				}
				else if (history[1] == 'T')
				{
					if (history[2] == 'N')
					{
						temp = 6;
						compare1 = NT[6];
						cout << "(110";
					}
					else if (history[2] == 'T')
					{
						temp = 7;
						compare1 = NT[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 1)
		{
			if (history1[0] == 'N')
			{
				if (history1[1] == 'N')
				{
					if (history1[2] == 'N')
					{
						temp = 0;
						compare1 = NT1[0];
						cout << "(000";
					}
					else if (history1[2] == 'T')
					{
						temp = 1;
						compare1 = NT1[1];
						cout << "(001";
					}
				}
				else if (history1[1] == 'T')
				{
					if (history1[2] == 'N')
					{
						temp = 2;
						compare1 = NT1[2];
						cout << "(010";
					}
					else if (history1[2] == 'T')
					{
						temp = 3;
						compare1 = NT1[3];
						cout << "(011";
					}
				}
			}
			else if (history1[0] == 'T')
			{
				if (history1[1] == 'N')
				{
					if (history1[2] == 'N')
					{
						temp = 4;
						compare1 = NT1[4];
						cout << "(100";
					}
					else if (history1[2] == 'T')
					{
						temp = 5;
						compare1 = NT1[5];
						cout << "(101";
					}
				}
				else if (history1[1] == 'T')
				{
					if (history1[2] == 'N')
					{
						temp = 6;
						compare1 = NT1[6];
						cout << "(110";
					}
					else if (history1[2] == 'T')
					{
						temp = 7;
						compare1 = NT1[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 2)
		{
			if (history2[0] == 'N')
			{
				if (history2[1] == 'N')
				{
					if (history2[2] == 'N')
					{
						temp = 0;
						compare1 = NT2[0];
						cout << "(000";
					}
					else if (history2[2] == 'T')
					{
						temp = 1;
						compare1 = NT2[1];
						cout << "(001";
					}
				}
				else if (history2[1] == 'T')
				{
					if (history2[2] == 'N')
					{
						temp = 2;
						compare1 = NT2[2];
						cout << "(010";
					}
					else if (history2[2] == 'T')
					{
					temp = 3;
					compare1 = NT2[3];
					cout << "(011";
					}
				}
			}
			else if (history2[0] == 'T')
			{
				if (history2[1] == 'N')
				{
					if (history2[2] == 'N')
					{
						temp = 4;
						compare1 = NT2[4];
						cout << "(100";
					}
					else if (history2[2] == 'T')
					{
						temp = 5;
						compare1 = NT2[5];
						cout << "(101";
					}
				}
				else if (history2[1] == 'T')
				{
					if (history2[2] == 'N')
					{
						temp = 6;
						compare1 = NT2[6];
						cout << "(110";
					}
					else if (history2[2] == 'T')
					{
						temp = 7;
						compare1 = NT2[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 3)
		{
			if (history3[0] == 'N')
			{
				if (history3[1] == 'N')
				{
					if (history3[2] == 'N')
					{
						temp = 0;
						compare1 = NT3[0];
						cout << "(000";
					}
					else if (history3[2] == 'T')
					{
						temp = 1;
						compare1 = NT3[1];
						cout << "(001";
					}
				}
				else if (history3[1] == 'T')
				{
					if (history3[2] == 'N')
					{
						temp = 2;
						compare1 = NT3[2];
						cout << "(010";
					}
					else if (history3[2] == 'T')
					{
						temp = 3;
						compare1 = NT3[3];
						cout << "(011";
					}
				}
			}
			else if (history3[0] == 'T')
			{
				if (history3[1] == 'N')
				{
					if (history3[2] == 'N')
					{
						temp = 4;
						compare1 = NT3[4];
						cout << "(100";
					}
					else if (history3[2] == 'T')
					{
						temp = 5;
						compare1 = NT3[5];
						cout << "(101";
					}
				}
				else if (history3[1] == 'T')
				{
					if (history3[2] == 'N')
					{
						temp = 6;
						compare1 = NT3[6];
						cout << "(110";
					}
					else if (history3[2] == 'T')
					{
						temp = 7;
						compare1 = NT3[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 4)
		{
			if (history4[0] == 'N')
			{
				if (history4[1] == 'N')
				{
					if (history4[2] == 'N')
					{
						temp = 0;
						compare1 = NT4[0];
						cout << "(000";
					}
					else if (history4[2] == 'T')
					{
						temp = 1;
						compare1 = NT4[1];
						cout << "(001";
					}
				}
				else if (history4[1] == 'T')
				{
					if (history4[2] == 'N')
					{
						temp = 2;
						compare1 = NT4[2];
						cout << "(010";
					}
					else if (history4[2] == 'T')
					{
						temp = 3;
						compare1 = NT4[3];
						cout << "(011";
					}
				}
			}
			else if (history4[0] == 'T')
			{
				if (history4[1] == 'N')
				{
					if (history4[2] == 'N')
					{
						temp = 4;
						compare1 = NT4[4];
						cout << "(100";
					}
					else if (history4[2] == 'T')
					{
						temp = 5;
						compare1 = NT4[5];
						cout << "(101";
					}
				}
				else if (history4[1] == 'T')
				{
					if (history4[2] == 'N')
					{
						temp = 6;
						compare1 = NT4[6];
						cout << "(110";
					}
					else if (history4[2] == 'T')
					{
						temp = 7;
						compare1 = NT4[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 5)
		{
			if (history5[0] == 'N')
			{
				if (history5[1] == 'N')
				{
					if (history5[2] == 'N')
					{
						temp = 0;
						compare1 = NT5[0];
						cout << "(000";
					}
					else if (history5[2] == 'T')
					{
						temp = 1;
						compare1 = NT5[1];
						cout << "(001";
					}
				}
				else if (history5[1] == 'T')
				{
					if (history5[2] == 'N')
					{
						temp = 2;
						compare1 = NT5[2];
						cout << "(010";
					}
					else if (history5[2] == 'T')
					{
						temp = 3;
						compare1 = NT5[3];
						cout << "(011";
					}
				}
			}
			else if (history5[0] == 'T')
			{
				if (history5[1] == 'N')
				{
					if (history5[2] == 'N')
					{
						temp = 4;
						compare1 = NT5[4];
						cout << "(100";
					}
					else if (history5[2] == 'T')
					{
						temp = 5;
						compare1 = NT5[5];
						cout << "(101";
					}
				}
				else if (history5[1] == 'T')
				{
					if (history5[2] == 'N')
					{
						temp = 6;
						compare1 = NT5[6];
						cout << "(110";
					}
					else if (history5[2] == 'T')
					{
						temp = 7;
						compare1 = NT5[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 6)
		{
			if (history6[0] == 'N')
			{
				if (history6[1] == 'N')
				{
					if (history6[2] == 'N')
					{
						temp = 0;
						compare1 = NT6[0];
						cout << "(000";
					}
					else if (history6[2] == 'T')
					{
						temp = 1;
						compare1 = NT6[1];
						cout << "(001";
					}
				}
				else if (history6[1] == 'T')
				{
					if (history6[2] == 'N')
					{
						temp = 2;
						compare1 = NT6[2];
						cout << "(010";
					}
					else if (history6[2] == 'T')
					{
						temp = 3;
						compare1 = NT6[3];
						cout << "(011";
					}
				}
			}
			else if (history6[0] == 'T')
			{
				if (history6[1] == 'N')
				{
					if (history6[2] == 'N')
					{
						temp = 4;
						compare1 = NT6[4];
						cout << "(100";
					}
					else if (history6[2] == 'T')
					{
						temp = 5;
						compare1 = NT6[5];
						cout << "(101";
					}
				}
				else if (history6[1] == 'T')
				{
					if (history6[2] == 'N')
					{
						temp = 6;
						compare1 = NT6[6];
						cout << "(110";
					}
					else if (history6[2] == 'T')
					{
						temp = 7;
						compare1 = NT6[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 7)
		{
			if (history7[0] == 'N')
			{
				if (history7[1] == 'N')
				{
					if (history7[2] == 'N')
					{
						temp = 0;
						compare1 = NT7[0];
						cout << "(000";
					}
					else if (history7[2] == 'T')
					{
						temp = 1;
						compare1 = NT7[1];
						cout << "(001";
					}
				}
				else if (history7[1] == 'T')
				{
					if (history7[2] == 'N')
					{
						temp = 2;
						compare1 = NT7[2];
						cout << "(010";
					}
					else if (history7[2] == 'T')
					{
						temp = 3;
						compare1 = NT7[3];
						cout << "(011";
					}
				}
			}
			else if (history7[0] == 'T')
			{
				if (history7[1] == 'N')
				{
					if (history7[2] == 'N')
					{
						temp = 4;
						compare1 = NT7[4];
						cout << "(100";
					}
					else if (history7[2] == 'T')
					{
						temp = 5;
						compare1 = NT7[5];
						cout << "(101";
					}
				}
				else if (history7[1] == 'T')
				{
					if (history7[2] == 'N')
					{
						temp = 6;
						compare1 = NT7[6];
						cout << "(110";
					}
					else if (history7[2] == 'T')
					{
						temp = 7;
						compare1 = NT7[7];
						cout << "(111";
					}
				}
			}
		}
		if (compare1 == "SN")
		{
			compare = 'N';
		}
		else if (compare1 == "WN")
		{
			compare = 'N';
		}
		else if (compare1 == "ST")
		{
			compare = 'T';
		}
		else if (compare1 == "WT")
		{
			compare = 'T';
		}
		if (compare == iftaken)
		{
			if (entry_n_tem == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
				if (NT[temp] == "WT")
				{
					NT[temp] = "ST";
				}
			}
			else if (entry_n_tem == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT1[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
				if (NT1[temp] == "WT")
				{
					NT1[temp] = "ST";
				}
			}
			else if (entry_n_tem == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT2[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
				if (NT2[temp] == "WT")
				{
					NT2[temp] = "ST";
				}
			}
			else if (entry_n_tem == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT3[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
				if (NT3[temp] == "WT")
				{
					NT3[temp] = "ST";
				}
			}
			else if (entry_n_tem == 4)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT4[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
				if (NT4[temp] == "WT")
				{
					NT4[temp] = "ST";
				}
			}
			else if (entry_n_tem == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT5[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
				if (NT5[temp] == "WT")
				{
					NT5[temp] = "ST";
				}
			}
			else if (entry_n_tem == 6)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT6[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
				if (NT6[temp] == "WT")
				{
					NT6[temp] = "ST";
				}
			}
			else if (entry_n_tem == 7)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT7[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
				if (NT7[temp] == "WT")
				{
					NT7[temp] = "ST";
				}
			}
		}
		else
		{
			if (entry_n_tem == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT[i];
				}
				if (NT[temp] == "SN")
				{
					NT[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT[temp] == "WN")
				{
					NT[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
			}
			else if (entry_n_tem == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT1[i];
				}
				if (NT1[temp] == "SN")
				{
					NT1[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT1[temp] == "WN")
				{
					NT1[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
			}
			else if (entry_n_tem == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT2[i];
				}
				if (NT2[temp] == "SN")
				{
					NT2[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT2[temp] == "WN")
				{
					NT2[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
			}
			else if (entry_n_tem == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT3[i];
				}
				if (NT3[temp] == "SN")
				{
					NT3[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT3[temp] == "WN")
				{
					NT3[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
			}
			else if (entry_n_tem == 4)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT4[i];
				}
				if (NT4[temp] == "SN")
				{
					NT4[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT4[temp] == "WN")
				{
					NT4[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
			}
			else if (entry_n_tem == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT5[i];
				}
				if (NT5[temp] == "SN")
				{
					NT5[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT5[temp] == "WN")
				{
					NT5[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
			}
			else if (entry_n_tem == 6)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT6[i];
				}
				if (NT6[temp] == "SN")
				{
					NT6[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT6[temp] == "WN")
				{
					NT6[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
			}
			else if (entry_n_tem == 7)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT7[i];
				}
				if (NT7[temp] == "SN")
				{
					NT7[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT7[temp] == "WN")
				{
					NT7[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
			}
		}
	}
	else
	{
		string compare1;
		char compare;
		int temp;
		s3 = "No";
		iftaken = 'N';
		if (entry_n_tem == 0)
		{
			if (history[0] == 'N')
			{
				if (history[1] == 'N')
				{
					if (history[2] == 'N')
					{
						temp = 0;
						compare1 = NT[0];
						cout << "(000";
					}
					else if (history[2] == 'T')
					{
						temp = 1;
						compare1 = NT[1];
						cout << "(001";
					}
				}
				else if (history[1] == 'T')
				{
					if (history[2] == 'N')
					{
						temp = 2;
						compare1 = NT[2];
						cout << "(010";
					}
					else if (history[2] == 'T')
					{
						temp = 3;
						compare1 = NT[3];
						cout << "(011";
					}
				}
			}
			else if (history[0] == 'T')
			{
				if (history[1] == 'N')
				{
					if (history[2] == 'N')
					{
						temp = 4;
						compare1 = NT[4];
						cout << "(100";
					}
					else if (history[2] == 'T')
					{
						temp = 5;
						compare1 = NT[5];
						cout << "(101";
					}
				}
				else if (history[1] == 'T')
				{
					if (history[2] == 'N')
					{
						temp = 6;
						compare1 = NT[6];
						cout << "(110";
					}
					else if (history[2] == 'T')
					{
						temp = 7;
						compare1 = NT[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 1)
		{
			if (history1[0] == 'N')
			{
				if (history1[1] == 'N')
				{
					if (history1[2] == 'N')
					{
						temp = 0;
						compare1 = NT1[0];
						cout << "(000";
					}
					else if (history1[2] == 'T')
					{
						temp = 1;
						compare1 = NT1[1];
						cout << "(001";
					}
				}
				else if (history1[1] == 'T')
				{
					if (history1[2] == 'N')
					{
						temp = 2;
						compare1 = NT1[2];
						cout << "(010";
					}
					else if (history1[2] == 'T')
					{
						temp = 3;
						compare1 = NT1[3];
						cout << "(011";
					}
				}
			}
			else if (history1[0] == 'T')
			{
				if (history1[1] == 'N')
				{
					if (history1[2] == 'N')
					{
						temp = 4;
						compare1 = NT1[4];
						cout << "(100";
					}
					else if (history1[2] == 'T')
					{
						temp = 5;
						compare1 = NT1[5];
						cout << "(101";
					}
				}
				else if (history1[1] == 'T')
				{
					if (history1[2] == 'N')
					{
						temp = 6;
						compare1 = NT1[6];
						cout << "(110";
					}
					else if (history1[2] == 'T')
					{
						temp = 7;
						compare1 = NT1[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 2)
		{
			if (history2[0] == 'N')
			{
				if (history2[1] == 'N')
				{
					if (history2[2] == 'N')
					{
						temp = 0;
						compare1 = NT2[0];
						cout << "(000";
					}
					else if (history2[2] == 'T')
					{
						temp = 1;
						compare1 = NT2[1];
						cout << "(001";
					}
				}
				else if (history2[1] == 'T')
				{
					if (history2[2] == 'N')
					{
						temp = 2;
						compare1 = NT2[2];
						cout << "(010";
					}
					else if (history2[2] == 'T')
					{
						temp = 3;
						compare1 = NT2[3];
						cout << "(011";
					}
				}
			}
			else if (history2[0] == 'T')
			{
				if (history2[1] == 'N')
				{
					if (history2[2] == 'N')
					{
						temp = 4;
						compare1 = NT2[4];
						cout << "(100";
					}
					else if (history2[2] == 'T')
					{
						temp = 5;
						compare1 = NT2[5];
						cout << "(101";
					}
				}
				else if (history2[1] == 'T')
				{
					if (history2[2] == 'N')
					{
						temp = 6;
						compare1 = NT2[6];
						cout << "(110";
					}
					else if (history2[2] == 'T')
					{
						temp = 7;
						compare1 = NT2[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 3)
		{
			if (history3[0] == 'N')
			{
				if (history3[1] == 'N')
				{
					if (history3[2] == 'N')
					{
						temp = 0;
						compare1 = NT3[0];
						cout << "(000";
					}
					else if (history3[2] == 'T')
					{
						temp = 1;
						compare1 = NT3[1];
						cout << "(001";
					}
				}
				else if (history3[1] == 'T')
				{
					if (history3[2] == 'N')
					{
						temp = 2;
						compare1 = NT3[2];
						cout << "(010";
					}
					else if (history3[2] == 'T')
					{
						temp = 3;
						compare1 = NT3[3];
						cout << "(011";
					}
				}
			}
			else if (history3[0] == 'T')
			{
				if (history3[1] == 'N')
				{
					if (history3[2] == 'N')
					{
						temp = 4;
						compare1 = NT3[4];
						cout << "(100";
					}
					else if (history3[2] == 'T')
					{
						temp = 5;
						compare1 = NT3[5];
						cout << "(101";
					}
				}
				else if (history3[1] == 'T')
				{
					if (history3[2] == 'N')
					{
						temp = 6;
						compare1 = NT3[6];
						cout << "(110";
					}
					else if (history3[2] == 'T')
					{
						temp = 7;
						compare1 = NT3[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 4)
		{
			if (history4[0] == 'N')
			{
				if (history4[1] == 'N')
				{
					if (history4[2] == 'N')
					{
						temp = 0;
						compare1 = NT4[0];
						cout << "(000";
					}
					else if (history4[2] == 'T')
					{
						temp = 1;
						compare1 = NT4[1];
						cout << "(001";
					}
				}
				else if (history4[1] == 'T')
				{
					if (history4[2] == 'N')
					{
						temp = 2;
						compare1 = NT4[2];
						cout << "(010";
					}
					else if (history4[2] == 'T')
					{
						temp = 3;
						compare1 = NT4[3];
						cout << "(011";
					}
				}
			}
			else if (history4[0] == 'T')
			{
				if (history4[1] == 'N')
				{
					if (history4[2] == 'N')
					{
						temp = 4;
						compare1 = NT4[4];
						cout << "(100";
					}
					else if (history4[2] == 'T')
					{
						temp = 5;
						compare1 = NT4[5];
						cout << "(101";
					}
				}
				else if (history4[1] == 'T')
				{
					if (history4[2] == 'N')
					{
						temp = 6;
						compare1 = NT4[6];
						cout << "(110";
					}
					else if (history4[2] == 'T')
					{
						temp = 7;
						compare1 = NT4[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 5)
		{
			if (history5[0] == 'N')
			{
				if (history5[1] == 'N')
				{
					if (history5[2] == 'N')
					{
						temp = 0;
						compare1 = NT5[0];
						cout << "(000";
					}
					else if (history5[2] == 'T')
					{
						temp = 1;
						compare1 = NT5[1];
						cout << "(001";
					}
				}
				else if (history5[1] == 'T')
				{
					if (history5[2] == 'N')
					{
						temp = 2;
						compare1 = NT5[2];
						cout << "(010";
					}
					else if (history5[2] == 'T')
					{
						temp = 3;
						compare1 = NT5[3];
						cout << "(011";
					}
				}
			}
			else if (history5[0] == 'T')
			{
				if (history5[1] == 'N')
				{
					if (history5[2] == 'N')
					{
						temp = 4;
						compare1 = NT5[4];
						cout << "(100";
					}
					else if (history5[2] == 'T')
					{
						temp = 5;
						compare1 = NT5[5];
						cout << "(101";
					}
				}
				else if (history5[1] == 'T')
				{
					if (history5[2] == 'N')
					{
						temp = 6;
						compare1 = NT5[6];
						cout << "(110";
					}
					else if (history5[2] == 'T')
					{
						temp = 7;
						compare1 = NT5[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 6)
		{
			if (history6[0] == 'N')
			{
				if (history6[1] == 'N')
				{
					if (history6[2] == 'N')
					{
						temp = 0;
						compare1 = NT6[0];
						cout << "(000";
					}
					else if (history6[2] == 'T')
					{
						temp = 1;
						compare1 = NT6[1];
						cout << "(001";
					}
				}
				else if (history6[1] == 'T')
				{
					if (history6[2] == 'N')
					{
						temp = 2;
						compare1 = NT6[2];
						cout << "(010";
					}
					else if (history6[2] == 'T')
					{
						temp = 3;
						compare1 = NT6[3];
						cout << "(011";
					}
				}
			}
			else if (history6[0] == 'T')
			{
				if (history6[1] == 'N')
				{
					if (history6[2] == 'N')
					{
						temp = 4;
						compare1 = NT6[4];
						cout << "(100";
					}
					else if (history6[2] == 'T')
					{
						temp = 5;
						compare1 = NT6[5];
						cout << "(101";
					}
				}
				else if (history6[1] == 'T')
				{
					if (history6[2] == 'N')
					{
						temp = 6;
						compare1 = NT6[6];
						cout << "(110";
					}
					else if (history6[2] == 'T')
					{
						temp = 7;
						compare1 = NT6[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 7)
		{
			if (history7[0] == 'N')
			{
				if (history7[1] == 'N')
				{
					if (history7[2] == 'N')
					{
						temp = 0;
						compare1 = NT7[0];
						cout << "(000";
					}
					else if (history7[2] == 'T')
					{
						temp = 1;
						compare1 = NT7[1];
						cout << "(001";
					}
				}
				else if (history7[1] == 'T')
				{
					if (history7[2] == 'N')
					{
						temp = 2;
						compare1 = NT7[2];
						cout << "(010";
					}
					else if (history7[2] == 'T')
					{
						temp = 3;
						compare1 = NT7[3];
						cout << "(011";
					}
				}
			}
			else if (history7[0] == 'T')
			{
				if (history7[1] == 'N')
				{
					if (history7[2] == 'N')
					{
						temp = 4;
						compare1 = NT7[4];
						cout << "(100";
					}
					else if (history7[2] == 'T')
					{
						temp = 5;
						compare1 = NT7[5];
						cout << "(101";
					}
				}
				else if (history7[1] == 'T')
				{
					if (history7[2] == 'N')
					{
						temp = 6;
						compare1 = NT7[6];
						cout << "(110";
					}
					else if (history7[2] == 'T')
					{
						temp = 7;
						compare1 = NT7[7];
						cout << "(111";
					}
				}
			}
		}
		if (compare1 == "SN")
		{
			compare = 'N';
		}
		else if (compare1 == "WN")
		{
			compare = 'N';
		}
		else if (compare1 == "ST")
		{
			compare = 'T';
		}
		else if (compare1 == "WT")
		{
			compare = 'T';
		}
		if (compare == iftaken)
		{
			if (entry_n_tem == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
				if (NT[temp] == "WN")
				{
					NT[temp] = "SN";
				}
			}
			else if (entry_n_tem == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT1[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
				if (NT1[temp] == "WN")
				{
					NT1[temp] = "SN";
				}
			}
			else if (entry_n_tem == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT2[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
				if (NT2[temp] == "WN")
				{
					NT2[temp] = "SN";
				}
			}
			else if (entry_n_tem == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT3[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
				if (NT3[temp] == "WN")
				{
					NT3[temp] = "SN";
				}
			}
			else if (entry_n_tem == 4)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT4[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
				if (NT4[temp] == "WN")
				{
					NT4[temp] = "SN";
				}
			}
			else if (entry_n_tem == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT5[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
				if (NT5[temp] == "WN")
				{
					NT5[temp] = "SN";
				}
			}
			else if (entry_n_tem == 6)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT6[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
				if (NT6[temp] == "WN")
				{
					NT6[temp] = "SN";
				}
			}
			else if (entry_n_tem == 7)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT7[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
				if (NT7[temp] == "WN")
				{
					NT7[temp] = "SN";
				}
			}
		}
		else
		{
			if (entry_n_tem == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT[i];
				}
				if (NT[temp] == "ST")
				{
					NT[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT[temp] == "WT")
				{
					NT[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
			}
			else if (entry_n_tem == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT1[i];
				}
				if (NT1[temp] == "ST")
				{
					NT1[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT1[temp] == "WT")
				{
					NT1[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
			}
			else if (entry_n_tem == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT2[i];
				}
				if (NT2[temp] == "ST")
				{
					NT2[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT2[temp] == "WT")
				{
					NT2[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
			}
			else if (entry_n_tem == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT3[i];
				}
				if (NT3[temp] == "ST")
				{
					NT3[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT3[temp] == "WT")
				{
					NT3[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
			}
			else if (entry_n_tem == 4)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT4[i];
				}
				if (NT4[temp] == "ST")
				{
					NT4[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT4[temp] == "WT")
				{
					NT4[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
			}
			else if (entry_n_tem == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT5[i];
				}
				if (NT5[temp] == "ST")
				{
					NT5[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT5[temp] == "WT")
				{
					NT5[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
			}
			else if (entry_n_tem == 6)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT6[i];
				}
				if (NT6[temp] == "ST")
				{
					NT6[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT6[temp] == "WT")
				{
					NT6[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
			}
			else if (entry_n_tem == 7)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT7[i];
				}
				if (NT7[temp] == "ST")
				{
					NT7[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT7[temp] == "WT")
				{
					NT7[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
			}
		}
	}
	if (entry_n_tem == 0)
	{
		history.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history.size(); i++)
		{
			history_test.push_back(history[i]);
		}
		history.clear();
		for (int i = 0; i < 3; i++)
		{
			history.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 1)
	{
		history1.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history1.size(); i++)
		{
			history_test.push_back(history1[i]);
		}
		history1.clear();
		for (int i = 0; i < 3; i++)
		{
			history1.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 2)
	{
		history2.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history2.size(); i++)
		{
			history_test.push_back(history2[i]);
		}
		history2.clear();
		for (int i = 0; i < 3; i++)
		{
			history2.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 3)
	{
		history3.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history3.size(); i++)
		{
			history_test.push_back(history3[i]);
		}
		history3.clear();
		for (int i = 0; i < 3; i++)
		{
			history3.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 4)
	{
		history4.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history4.size(); i++)
		{
			history_test.push_back(history4[i]);
		}
		history4.clear();
		for (int i = 0; i < 3; i++)
		{
			history4.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 5)
	{
		history5.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history5.size(); i++)
		{
			history_test.push_back(history5[i]);
		}
		history5.clear();
		for (int i = 0; i < 3; i++)
		{
			history5.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 6)
	{
		history6.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history6.size(); i++)
		{
			history_test.push_back(history6[i]);
		}
		history6.clear();
		for (int i = 0; i < 3; i++)
		{
			history6.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 7)
	{
		history7.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history7.size(); i++)
		{
			history_test.push_back(history7[i]);
		}
		history7.clear();
		for (int i = 0; i < 3; i++)
		{
			history7.push_back(history_test[i]);
		}
	}
	return s3;
}
string Bne(string s)
{
	int branch_num = 0;
	int entry_n_tem = 0;
	if (branch.size() == 0)
	{
		branch.push_back(s);
		entry_num.push_back(entry_n);
		entry_n++;
	}
	for (int i = 0; i < branch.size(); i++)
	{
		string check = branch[i];
		if (s != check && i == branch.size() - 1)
		{
			branch.push_back(s);
			if (entry_n == entry)
			{
				entry_n = 0;
			}
			entry_num.push_back(entry_n);
			branch_num = branch.size() - 1;
			entry_n_tem = entry_n;
			entry_n++;
		}
		else if (s == check)
		{
			branch_num = i;
			entry_n_tem = entry_num[i];
			break;
		}
	}
	cout << "entry: " << entry_n_tem << "          " << branch[branch_num] << endl;

	int a = 0, b = 0;
	string s1 = s.substr(4, 2);
	string s2 = s.substr(7, 2);
	string s3;
	if (s1 == "R2")
	{
		a = r2;
	}
	else if (s1 == "R3")
	{
		a = r3;
	}
	else if (s1 == "R4")
	{
		a = r4;
	}
	else if (s1 == "R5")
	{
		a = r5;
	}
	else if (s1 == "R6")
	{
		a = r6;
	}
	if (s2 == "R2")
	{
		b = r2;
	}
	else if (s2 == "R3")
	{
		b = r3;
	}
	else if (s2 == "R4")
	{
		b = r4;
	}
	else if (s2 == "R5")
	{
		b = r5;
	}
	else if (s2 == "R6")
	{
		b = r6;
	}
	if (a != b)
	{
		string tem1 = s.substr(10);
		for (int i = 0; i < tem1.size(); i++)
		{
			if (tem1[i] != 9 && tem1[i] != 32)
			{
				s3.push_back(tem1[i]);
			}
		}
		s3.push_back(':');
		//s3 = s.substr(10);
		string compare1;
		char compare;
		int temp;
		iftaken = 'T';
		if (entry_n_tem == 0)
		{
			if (history[0] == 'N')
			{
				if (history[1] == 'N')
				{
					if (history[2] == 'N')
					{
						temp = 0;
						compare1 = NT[0];
						cout << "(000";
					}
					else if (history[2] == 'T')
					{
						temp = 1;
						compare1 = NT[1];
						cout << "(001";
					}
				}
				else if (history[1] == 'T')
				{
					if (history[2] == 'N')
					{
						temp = 2;
						compare1 = NT[2];
						cout << "(010";
					}
					else if (history[2] == 'T')
					{
						temp = 3;
						compare1 = NT[3];
						cout << "(011";
					}
				}
			}
			else if (history[0] == 'T')
			{
				if (history[1] == 'N')
				{
					if (history[2] == 'N')
					{
						temp = 4;
						compare1 = NT[4];
						cout << "(100";
					}
					else if (history[2] == 'T')
					{
						temp = 5;
						compare1 = NT[5];
						cout << "(101";
					}
				}
				else if (history[1] == 'T')
				{
					if (history[2] == 'N')
					{
						temp = 6;
						compare1 = NT[6];
						cout << "(110";
					}
					else if (history[2] == 'T')
					{
						temp = 7;
						compare1 = NT[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 1)
		{
			if (history1[0] == 'N')
			{
				if (history1[1] == 'N')
				{
					if (history1[2] == 'N')
					{
						temp = 0;
						compare1 = NT1[0];
						cout << "(000";
					}
					else if (history1[2] == 'T')
					{
						temp = 1;
						compare1 = NT1[1];
						cout << "(001";
					}
				}
				else if (history1[1] == 'T')
				{
					if (history1[2] == 'N')
					{
						temp = 2;
						compare1 = NT1[2];
						cout << "(010";
					}
					else if (history1[2] == 'T')
					{
						temp = 3;
						compare1 = NT1[3];
						cout << "(011";
					}
				}
			}
			else if (history1[0] == 'T')
			{
				if (history1[1] == 'N')
				{
					if (history1[2] == 'N')
					{
						temp = 4;
						compare1 = NT1[4];
						cout << "(100";
					}
					else if (history1[2] == 'T')
					{
						temp = 5;
						compare1 = NT1[5];
						cout << "(101";
					}
				}
				else if (history1[1] == 'T')
				{
					if (history1[2] == 'N')
					{
						temp = 6;
						compare1 = NT1[6];
						cout << "(110";
					}
					else if (history1[2] == 'T')
					{
						temp = 7;
						compare1 = NT1[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 2)
		{
			if (history2[0] == 'N')
			{
				if (history2[1] == 'N')
				{
					if (history2[2] == 'N')
					{
						temp = 0;
						compare1 = NT2[0];
						cout << "(000";
					}
					else if (history2[2] == 'T')
					{
						temp = 1;
						compare1 = NT2[1];
						cout << "(001";
					}
				}
				else if (history2[1] == 'T')
				{
					if (history2[2] == 'N')
					{
						temp = 2;
						compare1 = NT2[2];
						cout << "(010";
					}
					else if (history2[2] == 'T')
					{
						temp = 3;
						compare1 = NT2[3];
						cout << "(011";
					}
				}
			}
			else if (history2[0] == 'T')
			{
				if (history2[1] == 'N')
				{
					if (history2[2] == 'N')
					{
						temp = 4;
						compare1 = NT2[4];
						cout << "(100";
					}
					else if (history2[2] == 'T')
					{
						temp = 5;
						compare1 = NT2[5];
						cout << "(101";
					}
				}
				else if (history2[1] == 'T')
				{
					if (history2[2] == 'N')
					{
						temp = 6;
						compare1 = NT2[6];
						cout << "(110";
					}
					else if (history2[2] == 'T')
					{
						temp = 7;
						compare1 = NT2[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 3)
		{
			if (history3[0] == 'N')
			{
				if (history3[1] == 'N')
				{
					if (history3[2] == 'N')
					{
						temp = 0;
						compare1 = NT3[0];
						cout << "(000";
					}
					else if (history3[2] == 'T')
					{
						temp = 1;
						compare1 = NT3[1];
						cout << "(001";
					}
				}
				else if (history3[1] == 'T')
				{
					if (history3[2] == 'N')
					{
						temp = 2;
						compare1 = NT3[2];
						cout << "(010";
					}
					else if (history3[2] == 'T')
					{
						temp = 3;
						compare1 = NT3[3];
						cout << "(011";
					}
				}
			}
			else if (history3[0] == 'T')
			{
				if (history3[1] == 'N')
				{
					if (history3[2] == 'N')
					{
						temp = 4;
						compare1 = NT3[4];
						cout << "(100";
					}
					else if (history3[2] == 'T')
					{
						temp = 5;
						compare1 = NT3[5];
						cout << "(101";
					}
				}
				else if (history3[1] == 'T')
				{
					if (history3[2] == 'N')
					{
						temp = 6;
						compare1 = NT3[6];
						cout << "(110";
					}
					else if (history3[2] == 'T')
					{
						temp = 7;
						compare1 = NT3[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 4)
		{
			if (history4[0] == 'N')
			{
				if (history4[1] == 'N')
				{
					if (history4[2] == 'N')
					{
						temp = 0;
						compare1 = NT4[0];
						cout << "(000";
					}
					else if (history4[2] == 'T')
					{
						temp = 1;
						compare1 = NT4[1];
						cout << "(001";
					}
				}
				else if (history4[1] == 'T')
				{
					if (history4[2] == 'N')
					{
						temp = 2;
						compare1 = NT4[2];
						cout << "(010";
					}
					else if (history4[2] == 'T')
					{
						temp = 3;
						compare1 = NT4[3];
						cout << "(011";
					}
				}
			}
			else if (history4[0] == 'T')
			{
				if (history4[1] == 'N')
				{
					if (history4[2] == 'N')
					{
						temp = 4;
						compare1 = NT4[4];
						cout << "(100";
					}
					else if (history4[2] == 'T')
					{
						temp = 5;
						compare1 = NT4[5];
						cout << "(101";
					}
				}
				else if (history4[1] == 'T')
				{
					if (history4[2] == 'N')
					{
						temp = 6;
						compare1 = NT4[6];
						cout << "(110";
					}
					else if (history4[2] == 'T')
					{
						temp = 7;
						compare1 = NT4[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 5)
		{
			if (history5[0] == 'N')
			{
				if (history5[1] == 'N')
				{
					if (history5[2] == 'N')
					{
						temp = 0;
						compare1 = NT5[0];
						cout << "(000";
					}
					else if (history5[2] == 'T')
					{
						temp = 1;
						compare1 = NT5[1];
						cout << "(001";
					}
				}
				else if (history5[1] == 'T')
				{
					if (history5[2] == 'N')
					{
						temp = 2;
						compare1 = NT5[2];
						cout << "(010";
					}
					else if (history5[2] == 'T')
					{
						temp = 3;
						compare1 = NT5[3];
						cout << "(011";
					}
				}
			}
			else if (history5[0] == 'T')
			{
				if (history5[1] == 'N')
				{
					if (history5[2] == 'N')
					{
						temp = 4;
						compare1 = NT5[4];
						cout << "(100";
					}
					else if (history5[2] == 'T')
					{
						temp = 5;
						compare1 = NT5[5];
						cout << "(101";
					}
				}
				else if (history5[1] == 'T')
				{
					if (history5[2] == 'N')
					{
						temp = 6;
						compare1 = NT5[6];
						cout << "(110";
					}
					else if (history5[2] == 'T')
					{
						temp = 7;
						compare1 = NT5[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 6)
		{
			if (history6[0] == 'N')
			{
				if (history6[1] == 'N')
				{
					if (history6[2] == 'N')
					{
						temp = 0;
						compare1 = NT6[0];
						cout << "(000";
					}
					else if (history6[2] == 'T')
					{
						temp = 1;
						compare1 = NT6[1];
						cout << "(001";
					}
				}
				else if (history6[1] == 'T')
				{
					if (history6[2] == 'N')
					{
						temp = 2;
						compare1 = NT6[2];
						cout << "(010";
					}
					else if (history6[2] == 'T')
					{
						temp = 3;
						compare1 = NT6[3];
						cout << "(011";
					}
				}
			}
			else if (history6[0] == 'T')
			{
				if (history6[1] == 'N')
				{
					if (history6[2] == 'N')
					{
						temp = 4;
						compare1 = NT6[4];
						cout << "(100";
					}
					else if (history6[2] == 'T')
					{
						temp = 5;
						compare1 = NT6[5];
						cout << "(101";
					}
				}
				else if (history6[1] == 'T')
				{
					if (history6[2] == 'N')
					{
						temp = 6;
						compare1 = NT6[6];
						cout << "(110";
					}
					else if (history6[2] == 'T')
					{
						temp = 7;
						compare1 = NT6[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 7)
		{
			if (history7[0] == 'N')
			{
				if (history7[1] == 'N')
				{
					if (history7[2] == 'N')
					{
						temp = 0;
						compare1 = NT7[0];
						cout << "(000";
					}
					else if (history7[2] == 'T')
					{
						temp = 1;
						compare1 = NT7[1];
						cout << "(001";
					}
				}
				else if (history7[1] == 'T')
				{
					if (history7[2] == 'N')
					{
						temp = 2;
						compare1 = NT7[2];
						cout << "(010";
					}
					else if (history7[2] == 'T')
					{
						temp = 3;
						compare1 = NT7[3];
						cout << "(011";
					}
				}
			}
			else if (history7[0] == 'T')
			{
				if (history7[1] == 'N')
				{
					if (history7[2] == 'N')
					{
						temp = 4;
						compare1 = NT7[4];
						cout << "(100";
					}
					else if (history7[2] == 'T')
					{
						temp = 5;
						compare1 = NT7[5];
						cout << "(101";
					}
				}
				else if (history7[1] == 'T')
				{
					if (history7[2] == 'N')
					{
						temp = 6;
						compare1 = NT7[6];
						cout << "(110";
					}
					else if (history7[2] == 'T')
					{
						temp = 7;
						compare1 = NT7[7];
						cout << "(111";
					}
				}
			}
		}
		if (compare1 == "SN")
		{
			compare = 'N';
		}
		else if (compare1 == "WN")
		{
			compare = 'N';
		}
		else if (compare1 == "ST")
		{
			compare = 'T';
		}
		else if (compare1 == "WT")
		{
			compare = 'T';
		}
		if (compare == iftaken)
		{
			if (entry_n_tem == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
				if (NT[temp] == "WT")
				{
					NT[temp] = "ST";
				}
			}
			else if (entry_n_tem == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT1[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
				if (NT1[temp] == "WT")
				{
					NT1[temp] = "ST";
				}
			}
			else if (entry_n_tem == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT2[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
				if (NT2[temp] == "WT")
				{
					NT2[temp] = "ST";
				}
			}
			else if (entry_n_tem == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT3[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
				if (NT3[temp] == "WT")
				{
					NT3[temp] = "ST";
				}
			}
			else if (entry_n_tem == 4)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT4[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
				if (NT4[temp] == "WT")
				{
					NT4[temp] = "ST";
				}
			}
			else if (entry_n_tem == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT5[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
				if (NT5[temp] == "WT")
				{
					NT5[temp] = "ST";
				}
			}
			else if (entry_n_tem == 6)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT6[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
				if (NT6[temp] == "WT")
				{
					NT6[temp] = "ST";
				}
			}
			else if (entry_n_tem == 7)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT7[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
				if (NT7[temp] == "WT")
				{
					NT7[temp] = "ST";
				}
			}
		}
		else
		{
			if (entry_n_tem == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT[i];
				}
				if (NT[temp] == "SN")
				{
					NT[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT[temp] == "WN")
				{
					NT[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
			}
			else if (entry_n_tem == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT1[i];
				}
				if (NT1[temp] == "SN")
				{
					NT1[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT1[temp] == "WN")
				{
					NT1[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
			}
			else if (entry_n_tem == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT2[i];
				}
				if (NT2[temp] == "SN")
				{
					NT2[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT2[temp] == "WN")
				{
					NT2[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
			}
			else if (entry_n_tem == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT3[i];
				}
				if (NT3[temp] == "SN")
				{
					NT3[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT3[temp] == "WN")
				{
					NT3[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
			}
			else if (entry_n_tem == 4)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT4[i];
				}
				if (NT4[temp] == "SN")
				{
					NT4[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT4[temp] == "WN")
				{
					NT4[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
			}
			else if (entry_n_tem == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT5[i];
				}
				if (NT5[temp] == "SN")
				{
					NT5[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT5[temp] == "WN")
				{
					NT5[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
			}
			else if (entry_n_tem == 6)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT6[i];
				}
				if (NT6[temp] == "SN")
				{
					NT6[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT6[temp] == "WN")
				{
					NT6[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
			}
			else if (entry_n_tem == 7)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT7[i];
				}
				if (NT7[temp] == "SN")
				{
					NT7[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				else if (NT7[temp] == "WN")
				{
					NT7[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
			}
		}
	}
	else
	{
		string compare1;
		char compare;
		int temp;
		s3 = "No";
		iftaken = 'N';
		if (entry_n_tem == 0)
		{
			if (history[0] == 'N')
			{
				if (history[1] == 'N')
				{
					if (history[2] == 'N')
					{
						temp = 0;
						compare1 = NT[0];
						cout << "(000";
					}
					else if (history[2] == 'T')
					{
						temp = 1;
						compare1 = NT[1];
						cout << "(001";
					}
				}
				else if (history[1] == 'T')
				{
					if (history[2] == 'N')
					{
						temp = 2;
						compare1 = NT[2];
						cout << "(010";
					}
					else if (history[2] == 'T')
					{
						temp = 3;
						compare1 = NT[3];
						cout << "(011";
					}
				}
			}
			else if (history[0] == 'T')
			{
				if (history[1] == 'N')
				{
					if (history[2] == 'N')
					{
						temp = 4;
						compare1 = NT[4];
						cout << "(100";
					}
					else if (history[2] == 'T')
					{
						temp = 5;
						compare1 = NT[5];
						cout << "(101";
					}
				}
				else if (history[1] == 'T')
				{
					if (history[2] == 'N')
					{
						temp = 6;
						compare1 = NT[6];
						cout << "(110";
					}
					else if (history[2] == 'T')
					{
						temp = 7;
						compare1 = NT[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 1)
		{
			if (history1[0] == 'N')
			{
				if (history1[1] == 'N')
				{
					if (history1[2] == 'N')
					{
						temp = 0;
						compare1 = NT1[0];
						cout << "(000";
					}
					else if (history1[2] == 'T')
					{
						temp = 1;
						compare1 = NT1[1];
						cout << "(001";
					}
				}
				else if (history1[1] == 'T')
				{
					if (history1[2] == 'N')
					{
						temp = 2;
						compare1 = NT1[2];
						cout << "(010";
					}
					else if (history1[2] == 'T')
					{
						temp = 3;
						compare1 = NT1[3];
						cout << "(011";
					}
				}
			}
			else if (history1[0] == 'T')
			{
				if (history1[1] == 'N')
				{
					if (history1[2] == 'N')
					{
						temp = 4;
						compare1 = NT1[4];
						cout << "(100";
					}
					else if (history1[2] == 'T')
					{
						temp = 5;
						compare1 = NT1[5];
						cout << "(101";
					}
				}
				else if (history1[1] == 'T')
				{
					if (history1[2] == 'N')
					{
						temp = 6;
						compare1 = NT1[6];
						cout << "(110";
					}
					else if (history1[2] == 'T')
					{
						temp = 7;
						compare1 = NT1[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 2)
		{
			if (history2[0] == 'N')
			{
				if (history2[1] == 'N')
				{
					if (history2[2] == 'N')
					{
						temp = 0;
						compare1 = NT2[0];
						cout << "(000";
					}
					else if (history2[2] == 'T')
					{
						temp = 1;
						compare1 = NT2[1];
						cout << "(001";
					}
				}
				else if (history2[1] == 'T')
				{
					if (history2[2] == 'N')
					{
						temp = 2;
						compare1 = NT2[2];
						cout << "(010";
					}
					else if (history2[2] == 'T')
					{
						temp = 3;
						compare1 = NT2[3];
						cout << "(011";
					}
				}
			}
			else if (history2[0] == 'T')
			{
				if (history2[1] == 'N')
				{
					if (history2[2] == 'N')
					{
						temp = 4;
						compare1 = NT2[4];
						cout << "(100";
					}
					else if (history2[2] == 'T')
					{
						temp = 5;
						compare1 = NT2[5];
						cout << "(101";
					}
				}
				else if (history2[1] == 'T')
				{
					if (history2[2] == 'N')
					{
						temp = 6;
						compare1 = NT2[6];
						cout << "(110";
					}
					else if (history2[2] == 'T')
					{
						temp = 7;
						compare1 = NT2[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 3)
		{
			if (history3[0] == 'N')
			{
				if (history3[1] == 'N')
				{
					if (history3[2] == 'N')
					{
						temp = 0;
						compare1 = NT3[0];
						cout << "(000";
					}
					else if (history3[2] == 'T')
					{
						temp = 1;
						compare1 = NT3[1];
						cout << "(001";
					}
				}
				else if (history3[1] == 'T')
				{
					if (history3[2] == 'N')
					{
						temp = 2;
						compare1 = NT3[2];
						cout << "(010";
					}
					else if (history3[2] == 'T')
					{
						temp = 3;
						compare1 = NT3[3];
						cout << "(011";
					}
				}
			}
			else if (history3[0] == 'T')
			{
				if (history3[1] == 'N')
				{
					if (history3[2] == 'N')
					{
						temp = 4;
						compare1 = NT3[4];
						cout << "(100";
					}
					else if (history3[2] == 'T')
					{
						temp = 5;
						compare1 = NT3[5];
						cout << "(101";
					}
				}
				else if (history3[1] == 'T')
				{
					if (history3[2] == 'N')
					{
						temp = 6;
						compare1 = NT3[6];
						cout << "(110";
					}
					else if (history3[2] == 'T')
					{
						temp = 7;
						compare1 = NT3[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 4)
		{
			if (history4[0] == 'N')
			{
				if (history4[1] == 'N')
				{
					if (history4[2] == 'N')
					{
						temp = 0;
						compare1 = NT4[0];
						cout << "(000";
					}
					else if (history4[2] == 'T')
					{
						temp = 1;
						compare1 = NT4[1];
						cout << "(001";
					}
				}
				else if (history4[1] == 'T')
				{
					if (history4[2] == 'N')
					{
						temp = 2;
						compare1 = NT4[2];
						cout << "(010";
					}
					else if (history4[2] == 'T')
					{
						temp = 3;
						compare1 = NT4[3];
						cout << "(011";
					}
				}
			}
			else if (history4[0] == 'T')
			{
				if (history4[1] == 'N')
				{
					if (history4[2] == 'N')
					{
						temp = 4;
						compare1 = NT4[4];
						cout << "(100";
					}
					else if (history4[2] == 'T')
					{
						temp = 5;
						compare1 = NT4[5];
						cout << "(101";
					}
				}
				else if (history4[1] == 'T')
				{
					if (history4[2] == 'N')
					{
						temp = 6;
						compare1 = NT4[6];
						cout << "(110";
					}
					else if (history4[2] == 'T')
					{
						temp = 7;
						compare1 = NT4[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 5)
		{
			if (history5[0] == 'N')
			{
				if (history5[1] == 'N')
				{
					if (history5[2] == 'N')
					{
						temp = 0;
						compare1 = NT5[0];
						cout << "(000";
					}
					else if (history5[2] == 'T')
					{
						temp = 1;
						compare1 = NT5[1];
						cout << "(001";
					}
				}
				else if (history5[1] == 'T')
				{
					if (history5[2] == 'N')
					{
						temp = 2;
						compare1 = NT5[2];
						cout << "(010";
					}
					else if (history5[2] == 'T')
					{
						temp = 3;
						compare1 = NT5[3];
						cout << "(011";
					}
				}
			}
			else if (history5[0] == 'T')
			{
				if (history5[1] == 'N')
				{
					if (history5[2] == 'N')
					{
						temp = 4;
						compare1 = NT5[4];
						cout << "(100";
					}
					else if (history5[2] == 'T')
					{
						temp = 5;
						compare1 = NT5[5];
						cout << "(101";
					}
				}
				else if (history5[1] == 'T')
				{
					if (history5[2] == 'N')
					{
						temp = 6;
						compare1 = NT5[6];
						cout << "(110";
					}
					else if (history5[2] == 'T')
					{
						temp = 7;
						compare1 = NT5[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 6)
		{
			if (history6[0] == 'N')
			{
				if (history6[1] == 'N')
				{
					if (history6[2] == 'N')
					{
						temp = 0;
						compare1 = NT6[0];
						cout << "(000";
					}
					else if (history6[2] == 'T')
					{
						temp = 1;
						compare1 = NT6[1];
						cout << "(001";
					}
				}
				else if (history6[1] == 'T')
				{
					if (history6[2] == 'N')
					{
						temp = 2;
						compare1 = NT6[2];
						cout << "(010";
					}
					else if (history6[2] == 'T')
					{
						temp = 3;
						compare1 = NT6[3];
						cout << "(011";
					}
				}
			}
			else if (history6[0] == 'T')
			{
				if (history6[1] == 'N')
				{
					if (history6[2] == 'N')
					{
						temp = 4;
						compare1 = NT6[4];
						cout << "(100";
					}
					else if (history6[2] == 'T')
					{
						temp = 5;
						compare1 = NT6[5];
						cout << "(101";
					}
				}
				else if (history6[1] == 'T')
				{
					if (history6[2] == 'N')
					{
						temp = 6;
						compare1 = NT6[6];
						cout << "(110";
					}
					else if (history6[2] == 'T')
					{
						temp = 7;
						compare1 = NT6[7];
						cout << "(111";
					}
				}
			}
		}
		else if (entry_n_tem == 7)
		{
			if (history7[0] == 'N')
			{
				if (history7[1] == 'N')
				{
					if (history7[2] == 'N')
					{
						temp = 0;
						compare1 = NT7[0];
						cout << "(000";
					}
					else if (history7[2] == 'T')
					{
						temp = 1;
						compare1 = NT7[1];
						cout << "(001";
					}
				}
				else if (history7[1] == 'T')
				{
					if (history7[2] == 'N')
					{
						temp = 2;
						compare1 = NT7[2];
						cout << "(010";
					}
					else if (history7[2] == 'T')
					{
						temp = 3;
						compare1 = NT7[3];
						cout << "(011";
					}
				}
			}
			else if (history7[0] == 'T')
			{
				if (history7[1] == 'N')
				{
					if (history7[2] == 'N')
					{
						temp = 4;
						compare1 = NT7[4];
						cout << "(100";
					}
					else if (history7[2] == 'T')
					{
						temp = 5;
						compare1 = NT7[5];
						cout << "(101";
					}
				}
				else if (history7[1] == 'T')
				{
					if (history7[2] == 'N')
					{
						temp = 6;
						compare1 = NT7[6];
						cout << "(110";
					}
					else if (history7[2] == 'T')
					{
						temp = 7;
						compare1 = NT7[7];
						cout << "(111";
					}
				}
			}
		}
		if (compare1 == "SN")
		{
			compare = 'N';
		}
		else if (compare1 == "WN")
		{
			compare = 'N';
		}
		else if (compare1 == "ST")
		{
			compare = 'T';
		}
		else if (compare1 == "WT")
		{
			compare = 'T';
		}
		if (compare == iftaken)
		{
			if (entry_n_tem == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
				if (NT[temp] == "WN")
				{
					NT[temp] = "SN";
				}
			}
			else if (entry_n_tem == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT1[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
				if (NT1[temp] == "WN")
				{
					NT1[temp] = "SN";
				}
			}
			else if (entry_n_tem == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT2[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
				if (NT2[temp] == "WN")
				{
					NT2[temp] = "SN";
				}
			}
			else if (entry_n_tem == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT3[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
				if (NT3[temp] == "WN")
				{
					NT3[temp] = "SN";
				}
			}
			else if (entry_n_tem == 4)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT4[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
				if (NT4[temp] == "WN")
				{
					NT4[temp] = "SN";
				}
			}
			else if (entry_n_tem == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT5[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
				if (NT5[temp] == "WN")
				{
					NT5[temp] = "SN";
				}
			}
			else if (entry_n_tem == 6)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT6[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
				if (NT6[temp] == "WN")
				{
					NT6[temp] = "SN";
				}
			}
			else if (entry_n_tem == 7)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT7[i];
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
				if (NT7[temp] == "WN")
				{
					NT7[temp] = "SN";
				}
			}
		}
		else
		{
			if (entry_n_tem == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT[i];
				}
				if (NT[temp] == "ST")
				{
					NT[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT[temp] == "WT")
				{
					NT[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[0] << endl;
			}
			else if (entry_n_tem == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT1[i];
				}
				if (NT1[temp] == "ST")
				{
					NT1[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT1[temp] == "WT")
				{
					NT1[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[1] << endl;
			}
			else if (entry_n_tem == 2)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT2[i];
				}
				if (NT2[temp] == "ST")
				{
					NT2[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT2[temp] == "WT")
				{
					NT2[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[2] << endl;
			}
			else if (entry_n_tem == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT3[i];
				}
				if (NT3[temp] == "ST")
				{
					NT3[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT3[temp] == "WT")
				{
					NT3[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[3] << endl;
			}
			else if (entry_n_tem == 4)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT4[i];
				}
				if (NT4[temp] == "ST")
				{
					NT4[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT4[temp] == "WT")
				{
					NT4[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[4] << endl;
			}
			else if (entry_n_tem == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT5[i];
				}
				if (NT5[temp] == "ST")
				{
					NT5[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT5[temp] == "WT")
				{
					NT5[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[5] << endl;
			}
			else if (entry_n_tem == 6)
			{
			for (int i = 0; i < 8; i++)
			{
				cout << ", " << NT6[i];
			}
			if (NT6[temp] == "ST")
			{
				NT6[temp] = "WT";
				mispredict[entry_n_tem]++;
			}
			else if (NT6[temp] == "WT")
			{
				NT6[temp] = "WN";
				mispredict[entry_n_tem]++;
			}
			cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[6] << endl;
			}
			else if (entry_n_tem == 7)
			{
				for (int i = 0; i < 8; i++)
				{
					cout << ", " << NT7[i];
				}
				if (NT7[temp] == "ST")
				{
					NT7[temp] = "WT";
					mispredict[entry_n_tem]++;
				}
				else if (NT7[temp] == "WT")
				{
					NT7[temp] = "WN";
					mispredict[entry_n_tem]++;
				}
				cout << ")" << " " << compare << " " << iftaken << "  misprediction: " << mispredict[7] << endl;
			}
		}
	}
	if (entry_n_tem == 0)
	{
		history.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history.size(); i++)
		{
			history_test.push_back(history[i]);
		}
		history.clear();
		for (int i = 0; i < 3; i++)
		{
			history.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 1)
	{
		history1.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history1.size(); i++)
		{
			history_test.push_back(history1[i]);
		}
		history1.clear();
		for (int i = 0; i < 3; i++)
		{
			history1.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 2)
	{
		history2.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history2.size(); i++)
		{
			history_test.push_back(history2[i]);
		}
		history2.clear();
		for (int i = 0; i < 3; i++)
		{
			history2.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 3)
	{
		history3.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history3.size(); i++)
		{
			history_test.push_back(history3[i]);
		}
		history3.clear();
		for (int i = 0; i < 3; i++)
		{
			history3.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 4)
	{
		history4.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history4.size(); i++)
		{
			history_test.push_back(history4[i]);
		}
		history4.clear();
		for (int i = 0; i < 3; i++)
		{
			history4.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 5)
	{
		history5.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history5.size(); i++)
		{
			history_test.push_back(history5[i]);
		}
		history5.clear();
		for (int i = 0; i < 3; i++)
		{
			history5.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 6)
	{
		history6.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history6.size(); i++)
		{
			history_test.push_back(history6[i]);
		}
		history6.clear();
		for (int i = 0; i < 3; i++)
		{
			history6.push_back(history_test[i]);
		}
	}
	else if (entry_n_tem == 7)
	{
		history7.push_back(iftaken);
		history_test.clear();
		for (int i = 1; i < history7.size(); i++)
		{
			history_test.push_back(history7[i]);
		}
		history7.clear();
		for (int i = 0; i < 3; i++)
		{
			history7.push_back(history_test[i]);
		}
	}
	return s3;
}

int main()
{
	ifstream input;
	input.open("input1.txt");
	stringstream strStream;
	strStream << input.rdbuf();
	string instance = strStream.str();
	//cout << instance << endl;
	string s1;
	istringstream ss(instance);
	vector<string> test;
	vector<string> test1;
	vector<string> test2;
	string s2, s3;
	while (getline(ss, s1, '\n'))
	{
		test.push_back(s1);
	}
	for (int i = 0; i < test.size(); i++)
	{
		s2 = test[i];
		if (s2[0] == '0')
		{
			s3 = s2.substr(7);
			test1.push_back(s3);
		}
		else
		{
			s3 = s2.substr(1);
			test1.push_back(s3);
		}
	}
	for (int i = 0; i < test1.size(); i++)
	{
		s2 = test1[i];
		int n = s2.find(';');
		if (n > -1)
		{
			s3 = s2.erase(n, s2.size() - 1);
			test2.push_back(s3);
		}
		else
		{
			test2.push_back(s2);
		}
	}

	int mis_count = 0;
	cout << "Please input entry(entry>0):" << endl;
	cin >> entry;
	for (int i = 0; i < entry; i++)
	{
		mispredict.push_back(mis_count);
	}
	for (int i = 0; i < 3; i++)
	{
		history.push_back('N');
		history1.push_back('N');
		history2.push_back('N');
		history3.push_back('N');
		history4.push_back('N');
		history5.push_back('N');
		history6.push_back('N');
		history7.push_back('N');
	}
	string s_test;
	for (int i = 0; i < test2.size(); i++)
	{
		s_test = test2[i];
		if (s_test[0] == 'l')
		{
			Li(s_test);
		}
		else if (s_test[0] == 'a')
		{
			if (s_test[1] == 'n')
			{
				Andi(s_test);
			}
			else if (s_test[3] == 'i')
			{
				Addi(s_test);
			}
			else
			{
				Add(s_test);
			}
		}
		else if (s_test[0] == 'b')
		{
			if (s_test[1] == 'e')
			{
				string ret = Beq(s_test);
				if (ret != "No")
				{
					for (int k = 0; k < test2.size(); k++)
					{
						string s_test1 = test2[k];
						if (s_test1 == ret)
						{
							i = k;
							break;
						}
					}
				}
			}
			else
			{
				string ret = Bne(s_test);
				if (ret != "No")
				{
					for (int k = 0; k < test2.size(); k++)
					{
						string s_test1 = test2[k];
						if (s_test1 == ret)
						{
							i = k;
							break;
						}
					}
				}
			}
		}
	}
}