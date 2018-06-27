// mysql_lib连接.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "C:/Program Files/MySQL/MySQL Server 5.7/include/mysql.h"
#pragma comment(lib,"libmysql.lib")


#include <iostream>
#include "mysql_handle.h"
using namespace std;



int main()
{
	mysql_base mb;
	mb.dbuser = "root";
	mb.dbpasswd = "123456";
	mb.dbip = "127.0.0.1";
	mb.dbname = "zt";
	mb.connect();
	vector<string> fields;
	vector<vector<string>> rows;
	mb.Query("select * from students", fields, rows);

	cout << rows.size() << endl;

	for (int i = 0; i < fields.size(); i++) {
		cout << fields[i].c_str() << endl;
	}
	for (int i = 0; i < rows.size(); i++) {
		for (int j = 0; j < rows[i].size(); j++) {
			cout << rows[i][j].c_str() << endl;
		}
	}
	mb.close();
	system("pause");
}


