#include <stdio.h>
#include <string.h>

struct UserProfile {
    char username[50];
    char email[100];
    char password[50];
    // Add more profile fields as needed
};

int main() {
    struct UserProfile user;
    
    // Registration
    printf("Registration\n");
    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter email: ");
    scanf("%s", user.email);
    printf("Enter password: ");
    scanf("%s", user.password);

    // Simulate saving the user profile to a database
    // In practice, you'd use a database library to interact with a database.
    // Here, we'll just print the entered data.
    printf("\nRegistration Successful\n");
    printf("Username: %s\n", user.username);
    printf("Email: %s\n", user.email);

    // Login
    char loginUsername[50];
    char loginPassword[50];

    printf("\nLogin\n");
    printf("Enter username: ");
    scanf("%s", loginUsername);
    printf("Enter password: ");
    scanf("%s", loginPassword);

    // Check if the login credentials match the user's stored information
    if (strcmp(loginUsername, user.username) == 0 && strcmp(loginPassword, user.password) == 0) {
        printf("\nLogin Successful\n");
        // Implement user dashboard and other app functionality here
    } else {
        printf("\nLogin Failed. Invalid credentials.\n");
    }

    return 0;
}
