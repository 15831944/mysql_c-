#pragma once
#include <iostream>

#include <windows.h>
#include <vector>
using namespace std;
#include "C:/Program Files/MySQL/MySQL Server 5.7/include/mysql.h"
#pragma comment(lib,"libmysql.lib")

class mysql_base {
public:
	MYSQL * con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	string dbuser;
	string dbpasswd;
	string dbip;
	string dbname;
	bool  connect();
	void  close();
	bool  Query(string Qs, vector<string> &fields, vector<vector<string>> &rows);
};