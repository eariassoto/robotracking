#include "sqlite3Manager.h"

sqlite3Manager::sqlite3Manager(char* dbLocation)
{
	int rc;
	rc = sqlite3_open(dbLocation, &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}
}

vector<vector<string>> sqlite3Manager::executeStatement(char* sql)
{
	vector<vector<string>> result;
	sqlite3_stmt *stmt;
	int rc;

	sqlite3_prepare(db, sql, -1, &stmt, NULL);

	if (rc != SQLITE_OK)
		cout << sqlite3_errmsg(db) << endl;

	rc = sqlite3_step(stmt);
	if (rc != SQLITE_ROW && rc != SQLITE_DONE) {
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
	}

	if (rc == SQLITE_DONE) {
		sqlite3_finalize(stmt);
		cout << "command end its execution" << endl;
	}

	int columns = sqlite3_column_count(stmt);

	while (sqlite3_column_text(stmt, 0))
	{
		vector<string> r; 
		for (int i = 0; i < columns; i++)
		{
			r.push_back(string((char *)sqlite3_column_text(stmt, i)));
		}
		result.push_back(r);
		sqlite3_step(stmt);
	}

	sqlite3_finalize(stmt);
	return result;

}

void sqlite3Manager::printTable(vector<vector<string>> table)
{
	for (vector<vector<string>>::iterator iter = table.begin(); iter != table.end(); ++iter)
	{
		for (vector<string>::iterator it = (*iter).begin(); it != (*iter).end(); ++it)
		{
			cout << *it << " ";
		}
		cout << "\n";
	}
}

sqlite3Manager::~sqlite3Manager() 
{
	sqlite3_close(db);
}