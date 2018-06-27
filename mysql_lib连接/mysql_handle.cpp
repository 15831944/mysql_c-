#include "mysql_handle.h"


bool  mysql_base::connect() {
	con = mysql_init((MYSQL*)0);

	if (con != NULL && mysql_real_connect(con, dbip.c_str(), dbuser.c_str(), dbpasswd.c_str(), dbname.c_str(), 3306, NULL, 0)) {
		if (!mysql_select_db(con, dbname.c_str())) {
			printf("Select successfully the database!\n");
			con->reconnect = 1;
			string query = "set names \'GBK\'";
			int rt = mysql_real_query(con, query.c_str(), strlen(query.c_str()));
			if (rt) {
				printf("Error making query: %s !!!\n", mysql_error(con));
				return false;
			}
			else {
				printf("query %s succeed!\n", query);
				return false;
			}
		}
	}
	else {
		MessageBoxA(NULL, "Unable to connect the database,check your configuration!", "", NULL);
	}


}
void  mysql_base::close() {
	if (!res) {
		mysql_free_result(res);
		res = NULL;
	}
	if (!con) {
		mysql_close(con);
		con = NULL;
	}
	return;
}
bool  mysql_base::Query(string Qs, vector<string> &fields,vector<vector<string>> &rows) {
	int rt;
	fields.clear(); rows.clear();
	rt = mysql_real_query(con, Qs.c_str(), Qs.length());
	if (rt)
	{
		printf("Error making query: %s !!!\n", mysql_error(con));
		return false;
	}
	else
	{
		printf("%s executed!!!\n", Qs.c_str());
	}
	res = mysql_store_result(con);//将结果保存在res结构体中
	if (!res) {
		return true;
	}
	for (int t = 0; t<mysql_num_fields(res); t++) {
		string f = mysql_fetch_fields(res)[t].name ;
		fields.push_back(f);
	}

	while (row = mysql_fetch_row(res)) {
		vector<string> v_row;
		for (int t = 0; t<mysql_num_fields(res); t++) {
			string c = row[t];
			v_row.push_back(c);
		}
		rows.push_back(v_row);
	}
	mysql_free_result(res);
}