#include <stdio.h>
#include <sqlite3.h>

// Function prototype

// Main function
int main(void)
{
    sqlite3 *db;       // pointer to the database
    char *err_msg = 0; // pointer to the error message
    int rc;            // return code

    // Open the database
    rc = sqlite3_open("data/test.db", &db);
    // Check if the database was opened successfully
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    printf("Database opened successfully.\n");

    // Create a table
    const char *sql = "CREATE TABLE IF NOT EXISTS Contacts("
                      "ID INTEGER PRIMARY KEY, "
                      "Name TEXT NOT NULL, "
                      "Phone TEXT NOT NULL);";

    // Execute the SQL statement
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg); // Free the error message
        sqlite3_close(db);    // Close the database
        return 1;
    }
    printf("Table created successfully!\n");

    // Close the database
    sqlite3_close(db);
    printf("Database connection closed.\n");

    return 0;
}