#include <mysql/mysql.h>
#include <stdio.h>

int main()
{
    MYSQL *conn;

    /* Initialize MySQL connection */
    conn = mysql_init(NULL);

    /* Connect to database */
    if (!mysql_real_connect(conn,
                            "localhost",   // Host
                            "root",        // Username
                            "password",    // Password
                            "studentdb",   // Database name
                            3306,          // Port
                            NULL,
                            0))
    {
        printf("Connection Failed!\n");
        return 1;
    }

    printf("Database Connected Successfully.\n");

    /* Create table */
    char createTable[] =
        "CREATE TABLE IF NOT EXISTS STUDENT ("
        "ID INT PRIMARY KEY,"
        "NAME VARCHAR(50),"
        "MARKS INT)";

    if(mysql_query(conn, createTable))
    {
        printf("Table creation failed.\n");
    }
    else
    {
        printf("Table created successfully.\n");
    }

    /* Insert first record */
    char insert1[] =
        "INSERT INTO STUDENT VALUES(1, 'Aman', 90)";

    if(mysql_query(conn, insert1))
    {
        printf("Insert failed for first record.\n");
    }
    else
    {
        printf("First record inserted.\n");
    }

    /* Insert second record */
    char insert2[] =
        "INSERT INTO STUDENT VALUES(2, 'Riya', 85)";

    if(mysql_query(conn, insert2))
    {
        printf("Insert failed for second record.\n");
    }
    else
    {
        printf("Second record inserted.\n");
    }

    /* Display records */
    if(mysql_query(conn, "SELECT * FROM STUDENT"))
    {
        printf("Display failed.\n");
    }
    else
    {
        MYSQL_RES *result = mysql_store_result(conn);
        MYSQL_ROW row;

        printf("\nStudent Records:\n");

        while((row = mysql_fetch_row(result)))
        {
            printf("ID: %s\n", row[0]);
            printf("Name: %s\n", row[1]);
            printf("Marks: %s\n\n", row[2]);
        }

        mysql_free_result(result);
    }

    /* Close connection */
    mysql_close(conn);

    return 0;
}