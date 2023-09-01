#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Define a structure to hold user information
struct UserProfile {
	int user_id;
	char username[50];
	char email[100];
	char password[255];
	// Add more profile fields as needed
};

// Function to initialize the database connection
MYSQL *initializeDatabase() {
	MYSQL *conn = mysql_init(NULL);
	if (conn == NULL) {
		fprintf(stderr, "mysql_init() failed\n");
		exit(1);
	}

	if (mysql_real_connect(conn, "localhost", "app_user", "password", "savings_app", 0, NULL, 0) == NULL) {
		fprintf(stderr, "mysql_real_connect() failed\n");
		mysql_close(conn);
		exit(1);
	}

	return conn;
}

// Function to create a new user profile
void createUser(MYSQL *conn, struct UserProfile *user) {
	// Implement user registration logic here
	// Insert the user's profile information into the 'user_profiles' table
	char query[256];
	snprintf(query, sizeof(query), "INSERT INTO user_profiles (username, email, password) VALUES ('%s', '%s', '%s')",
			user->username, user->email, user->password);

	if (mysql_query(conn, query)) {
		fprintf(stderr, "Failed to insert user profile: %s\n", mysql_error(conn));
	} else {
		printf("User registration successful\n");
	}
}

// Function to authenticate a user
int authenticateUser(MYSQL *conn, const char *username, const char *password) {
	// Implement user login and authentication logic here
	// Check if the provided username and password match an entry in the 'user_profiles' table
	char query[256];
	snprintf(query, sizeof(query), "SELECT * FROM user_profiles WHERE username = '%s' AND password = '%s'",
			username, password);

	if (mysql_query(conn, query)) {
		fprintf(stderr, "Authentication failed: %s\n", mysql_error(conn));
		return 0; // Authentication failure
	}

	MYSQL_RES *result = mysql_store_result(conn);
	int num_rows = mysql_num_rows(result);

	if (num_rows == 1) {
		mysql_free_result(result);
		return 1; // Authentication successful
	} else {
		mysql_free_result(result);
		return 0; // Authentication failure
	}
}

int main() {
	// Initialize the database connection
	MYSQL *conn = initializeDatabase();

	int choice;
	int totalSaved = 0;
	int cumulativeTotal = 0;  // Initialize the cumulative total

	printf("Welcome to the Dollar Saving Program!\n");
	printf("How would you like to save?\n");
	printf("1. Increment by 1 dollar every day\n");
	printf("2. Custom savings\n");
	printf("Enter your choice (1 or 2) or press Ctrl+D to exit: ");

	while (scanf("%d", &choice) != EOF) {
		if (choice == 1) {
			int startingAmount;
			printf("Enter the starting amount: $");
			scanf("%d", &startingAmount);

			for (int day = 1; day <= 365; day++) {
				totalSaved += startingAmount;
				cumulativeTotal += startingAmount;  // Update the cumulative total
				printf("Day %d: Saved $%d, Cumulative Total: $%d\n", day, startingAmount, cumulativeTotal);
				startingAmount++;
			}
		} else if (choice == 2) {
			for (int day = 1; day <= 365; day++) {
				int customAmount;
				printf("Enter savings for day %d or press Ctrl+D to exit: $", day);

				if (scanf("%d", &customAmount) == EOF) {
					printf("\nExiting...\n");
					return 0;  // Exit gracefully
				}

				totalSaved += customAmount;
				cumulativeTotal += customAmount;  // Update the cumulative total
				printf("Day %d: Saved $%d, Cumulative Total: $%d\n", day, customAmount, cumulativeTotal);
			}
		} else {
			printf("Invalid choice. Please choose 1 or 2.\n");
		}

		printf("Enter your choice (1 or 2) or press Ctrl+D to exit: ");
	}

	printf("Total savings for the year: $%d\n", totalSaved);

	// Close the database connection
	mysql_close(conn);

	return 0;
}

