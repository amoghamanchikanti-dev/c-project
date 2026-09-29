#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient
{
    char name[50];
    int age;
    char problem[50];
    struct patient *next;
};

struct patient *front = NULL, *rear = NULL;

void addpatient()
{
    struct patient *newpatient;

    newpatient = (struct patient *)malloc(sizeof(struct patient));

    fflush(stdin);

    printf("\nEnter the patient name: ");
    scanf(" %[^\n]", newpatient->name);

    printf("Enter age: ");
    scanf("%d", &newpatient->age);

    fflush(stdin);

    printf("Enter problem: ");
    scanf(" %[^\n]", newpatient->problem);

    newpatient->next = NULL;

    if (front == NULL)
    {
        front = rear = newpatient;
    }
    else
    {
        rear->next = newpatient;
        rear = newpatient;
    }

    printf("Patient added successfully\n");
}

void displaypatient()
{
    struct patient *temp = front;

    if (front == NULL)
    {
        printf("No patient waiting.\n");
        return;
    }

    printf("\n--- Patient Details ---\n");

    while (temp != NULL)
    {
        printf("Name: %s Age: %d Problem: %s\n",
               temp->name, temp->age, temp->problem);

        temp = temp->next;
    }
}

void treatpatient()
{
    struct patient *temp;

    if (front == NULL)
    {
        printf("No patient to treat.\n");
        return;
    }

    temp = front;

    printf("Treating patient: %s Age: %d Problem: %s\n",
           temp->name, temp->age, temp->problem);

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Hospital Patient Management ---\n");
        printf("1. Add patient\n");
        printf("2. Display patient\n");
        printf("3. Treat next patient\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addpatient();
                break;

            case 2:
                displaypatient();
                break;

            case 3:
                treatpatient();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}