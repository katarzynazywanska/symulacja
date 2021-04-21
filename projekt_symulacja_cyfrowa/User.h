#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "Network.h"
using namespace std;

 
class User : public Process
{
private:
	int t; //Losowy czas pojawienia si� u�ytkownika
	int users_data; //Ilo�� danych jak� mo�e odebra� 
	vector<int> propagation_conditions; // warunki propagacyjne blok�w zasob�w u�ytkownika
	int user_ID;
	const int l = 5; //maksymalna liczba zasob�w, jakie mo�na nada� u�ytkownikowi
	int prop_conditions;
public:
	User(int user_ID, int t, Network* network_);
	void Execute(Network* network) override;
	double sending_data_time();
	int get_user_ID() { return user_ID; };
};
 
 