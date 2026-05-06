#include <stdio.h>
#include <sqlite3.h>

/* Callback function */
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main()
{
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    /* Open database */
    rc = sqlite3_open("student.db", &db);

    if(rc)
    {
        printf("Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    else
    {
        printf("Database connected successfully.\n");
    }

    /* Create table */
    char *createTable =
        "CREATE TABLE IF NOT EXISTS STUDENT("
        "ID INT PRIMARY KEY NOT NULL,"
        "NAME TEXT NOT NULL,"
        "MARKS INT NOT NULL);";

    rc = sqlite3_exec(db, createTable, callback, 0, &errMsg);

    if(rc != SQLITE_OK)
    {
        printf("SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Table created successfully.\n");
    }

    /* Insert records */
    char *insertData =
        "INSERT INTO STUDENT (ID, NAME, MARKS) "
        "VALUES (1, 'Aman', 90);"

        "INSERT INTO STUDENT (ID, NAME, MARKS) "
        "VALUES (2, 'Riya', 85);";

    rc = sqlite3_exec(db, insertData, callback, 0, &errMsg);

    if(rc != SQLITE_OK)
    {
        printf("SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Records inserted successfully.\n");
    }

    /* Display records */
    char *selectData = "SELECT * FROM STUDENT;";

    printf("\nStudent Records:\n");

    rc = sqlite3_exec(db, selectData, callback, 0, &errMsg);

    if(rc != SQLITE_OK)
    {
        printf("SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    /* Close database */
    sqlite3_close(db);

    return 0;
}