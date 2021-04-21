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
	int t; //Losowy czas pojawienia siê u¿ytkownika
	int users_data; //Iloœæ danych jak¹ mo¿e odebraæ 
	vector<int> propagation_conditions; // warunki propagacyjne bloków zasobów u¿ytkownika
	int user_ID;
	const int l = 5; //maksymalna liczba zasobów, jakie mo¿na nadaæ u¿ytkownikowi
	int prop_conditions;
public:
	User(int user_ID, int t, Network* network_);
	void Execute(Network* network) override;
	double sending_data_time();
	int get_user_ID() { return user_ID; };
};
 
 