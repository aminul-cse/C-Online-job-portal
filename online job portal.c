#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for job postings
struct Job
{
    char title[50];
    char company[50];
    char location[50];
    double salaryMin;
    double salaryMax;
};

// Define a structure for accounts
struct Account
{
    char username[50];
    char password[50];
    char email[50];
    char type[50];
    char name[50];
    char gender[50];
    char mobile[50];
    char company[50];
    char companyAddress[50];
    int companySize;
    char contactPersonName[50];
    char contactPersonDesignation[50];
    char contactNumber[50];
    int jobCount;
    struct Job jobs[10];
};

// Global variable for account list
struct Account accountList[200];
int accountCount = 0;

// Function prototypes
void createAccount();
void postJob(int accountIndex);
void findJob(int accountIndex);
void viewJob(int accountIndex);
void applyJob(int accountIndex, int jobIndex);
void logout();
void mainMenu();

int main()
{
    mainMenu();
    return 0;
}

void mainMenu()
{
    int choice;
    printf("==================== Welcome to Online Job Portal ====================\n\n");

    do
    {
        printf("******* Online Job Portal *******\n");
        printf("=====================\n");
        printf("1. Create Account\n");
        printf("2. Exit\n");
        printf("=====================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    while (1);
}

void createAccount()
{
    // Create an account
    // Implement account creation logic here
    printf("Enter account type (company/employee): ");
    scanf("%s", accountList[accountCount].type);

    if (strcmp(accountList[accountCount].type, "employee") == 0)
    {
        printf("Enter name: ");
        scanf("%s", accountList[accountCount].name);
        printf("Enter gender: ");
        scanf("%s", accountList[accountCount].gender);
        printf("Enter mobile number: ");
        scanf("%s", accountList[accountCount].mobile);
        printf("Enter email: ");
        scanf("%s", accountList[accountCount].email);
        printf("Enter password: ");
        scanf("%s", accountList[accountCount].password);
        printf("Retype password: ");
        char confirmPassword[50];
        scanf("%s", confirmPassword);
        if (strcmp(accountList[accountCount].password, confirmPassword) != 0)
        {
            printf("Passwords do not match. Please try again.\n");
            return;
        }
        printf("Account created successfully as an employee!\n");
        printf("===========================================\n");
        // Show employee options
        viewJob(accountCount);
    }
    else if (strcmp(accountList[accountCount].type, "company") == 0)
    {
        printf("Enter company name: ");
        scanf("%s", accountList[accountCount].company);
        printf("Enter company address: ");
        scanf("%s", accountList[accountCount].companyAddress);
        printf("Enter company size (number of employees): ");
        scanf("%d", &accountList[accountCount].companySize);
        printf("Enter contact person name: ");
        scanf("%s", accountList[accountCount].contactPersonName);
        printf("Enter contact person designation: ");
        scanf("%s", accountList[accountCount].contactPersonDesignation);
        printf("Enter contact number: ");
        scanf("%s", accountList[accountCount].contactNumber);
        printf("Account created successfully as a company!\n");
        printf("===========================================\n");
        // Show company options
        postJob(accountCount);
    }

    strcpy(accountList[accountCount].username, accountList[accountCount].email);
    accountCount++;
}

void postJob(int accountIndex)
{
    // Post a job
    // Implement job posting logic here
    int choice;
    printf("1. Post a job\n");
    printf("2. Logout\n");
    printf("3. Exit\n");
    printf("=====================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            // Post a job
            printf("Enter job title: ");
            scanf("%s", accountList[accountIndex].jobs[accountList[accountIndex].jobCount].title);
            printf("Enter job company: ");
            scanf("%s", accountList[accountIndex].jobs[accountList[accountIndex].jobCount].company);
            printf("Enter job location: ");
            scanf("%s", accountList[accountIndex].jobs[accountList[accountIndex].jobCount].location);
            printf("Enter salary range (min/max): ");
            scanf("%lf %lf", &accountList[accountIndex].jobs[accountList[accountIndex].jobCount].salaryMin, &accountList[accountIndex].jobs[accountList[accountIndex].jobCount].salaryMax);
            accountList[accountIndex].jobCount++;
            printf("Job posted successfully!\n");
            postJob(accountIndex); // Continue showing options
            break;
        }
        case 2:
            // Logout
            logout();
            break;
        case 3:
            // Exit
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            postJob(accountIndex); // Show options again
    }
}

void findJob(int accountIndex)
{
    // Find a job
    if (accountList[accountIndex].jobCount == 0)
    {
        printf("No job available.\n");
        viewJob(accountIndex);
    }

    printf("Job Listings:\n");
    for (int i = 0; i < accountList[accountIndex].jobCount; i++)
    {
        printf("Job %d:\n", i + 1);
        printf("Title: %s\n", accountList[accountIndex].jobs[i].title);
        printf("Company: %s\n", accountList[accountIndex].jobs[i].company);
        printf("Location: %s\n", accountList[accountIndex].jobs[i].location);
        printf("Salary: $%.2f - $%.2f\n", accountList[accountIndex].jobs[i].salaryMin, accountList[accountIndex].jobs[i].salaryMax);
        printf("\n");
    }

    int choice;
    printf("1. Apply for a job\n");
    printf("2. Logout\n");
    printf("3. Exit\n");
    printf("=====================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            // Apply for a job
            // Implement job application logic here
            int jobChoice;
            printf("Enter the number of the job you would like to apply for: ");
            scanf("%d", &jobChoice);
            if (jobChoice >= 1 && jobChoice <= accountList[accountIndex].jobCount)
            {
                // Apply for the selected job

                printf("************* Applied successfully! *************\n");
            }
            else
            {
                printf("############# Invalid job number. #############\n");
            }
            findJob(accountIndex); // Continue showing options
            break;
        }
        case 2:
            // Logout
            logout();
            break;
        case 3:
            // Exit
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            findJob(accountIndex); // Show options again
    }
}

void viewJob(int accountIndex)
{
    // View job postings
    int choice;
    printf("1. View job postings\n");
    printf("2. Logout\n");
    printf("3. Exit\n");
    printf("=====================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            // Show job postings
            findJob(accountIndex);
            break;
        case 2:
            // Logout
            logout();
            break;
        case 3:
            // Exit
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            viewJob(accountIndex); // Show options again
    }
}

void logout()
{
    // Logout
    printf("Logging out...\n");
    mainMenu(); // Go back to the main menu
}
