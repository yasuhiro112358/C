#include <stdio.h>
#include <sqlite3.h>

// Function prototype

// Main function
int main(void)
{
    sqlite3 *db; // pointer to the database
    char *err_msg = 0; // pointer to the error message
    int rc; // return code

    // Open the database
    rc = sqlite3_open("data/test.db", &db); 
    // Check if the database was opened successfully
    if (rc != SQLITE_OK) 
    {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    printf("Database opened successfully.\n");

    // Close the database
    sqlite3_close(db);
    printf("Database connection closed.\n");

    return 0;
}