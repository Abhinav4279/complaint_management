//Term Project -- Complaint Management System

/*Submitted by:
Rishabh Verma - 194038
Utsav Kumar - 194037
Abhinav Sharma - 194052
*/

//admin login
//username - admin
//password - pass

//Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void customer_StoreComplaint();
void admin_menu();
void cancel_complaint();
void update_complaint();
void view_complaint();
void home();


//structure declared to store user details
struct node
{
    int complaint_number;
    char customerName[30];
    char date[10];
    char x[200];

    struct node *prev;
    struct node *next;
    struct node *link;

}*q, *temp;


struct node *start_ptr = NULL;
struct node *head = NULL;
struct node *last = NULL;

// Main function
int main()
{

    home();
}//end  main function


//It’s the home screen of the application where user get to make the choice to either enter complaint or login to administration. 
//Like adminmenu it uses switch statement to execute this funtionality.
void home() {
        int option;
    do
    {
        printf("\n");

        printf("Complaint Management System \n");
        printf("-------------------------------------------------\n\n");

        printf("SIGN IN \n \n");
        printf("1. Customer \n \n");

        printf("2. Administrator \n \n");



        printf("Select the user type: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            customer_StoreComplaint();
            break;
        case 2:
            admin_menu();
            break;
        }

    } while (1);
}

void topmargin()
{
    printf("\n");
    printf("\n");
    printf("\n");
    printf("            -------------------------------------------------------------\n");
    printf("            -------------------------------------------------------------");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}


/*This function authenticates admin by making use of strcmp(). If each character of username and password from user input matches with that specified inside code, 
then the permission is granted to enter administration, otherwise not.*/

int login()
{   int acces = 1;
    topmargin();
    char username[20];
    char pswd[20];
    char *u, *p;
    char *a = "admin\0";
    char *b = "pass\0";
    printf("                Username :");
    scanf("%s", username);
    u = username;
    printf("                Password :");
    scanf("%s", pswd);
    p = pswd;
    //printf("%d    %d", strcmp(a, u), strcmp(b, p));
    if (strcmp(a, u) == 0 && strcmp(b, p) == 0)
    {
        printf("                Logged in Successfully");
        return acces;
    }
    else
    {
        system("cls");
        login();
    }

}

/*This function takes input from user about complaint details and add those details in a node(struct).
This node is furthermore added at the beginning of linked list using temp pointer, storing pointer to node that is to be added and changing head node to this temp.*/

void customer_StoreComplaint()
{

    system("cls");
    printf("\n");
    printf("###################################################################################### \n \n");
    printf("\nAdd Your Complaint Details\n");

    struct node *temp;
    temp = (struct node*)malloc(1 * sizeof(struct node));
    printf("Type Complaint no: ");
    scanf("%d", &temp->complaint_number);
    fgets(temp->customerName, sizeof(temp->customerName), stdin);
    printf("Enter Name: ");
    fgets(temp->customerName, sizeof(temp->customerName), stdin);
    printf("Enter Date : ");
    fgets(temp->date, sizeof(temp->date), stdin);
    printf("Complaint Description:");
    printf("( 50 words maximum ) \n");
    fgets(temp->x, sizeof(temp->x), stdin);

    printf("\n");
    printf("Complaint added Successfully\n \n");
    printf("##################################################################################### \n \n");

    system ("PAUSE");

    temp->next = NULL;
    if (start_ptr != NULL)
    {
        temp->next = start_ptr;
    }
    start_ptr = temp;
    system("cls");
}


/*It uses simple switch case to take input from admin regarding the option he wants to enter. 
It is also provided with logout option, which takes the user back to home screen.*/
void admin_menu()
{
    if (login() == 1) {
        int menu;

        system("cls");
        printf("\n");
        printf("##################################################################################### \n\n");
        printf("Complaint Management System\n");
        printf("\t  Administrator     \n");
        printf("----------------------------------------------------\n");

        do
        {
            system("cls");
            printf("Administrator\n");
            printf("1. View Complaint\n");
            printf("2. Update Complaint Status\n");
            printf("3. Delete Complaint after being addressed\n");
            printf("4. Logout\n");
            printf("-------------------------------------------------\n");
            printf("Enter choice: ");

            scanf("%d", &menu);

            switch (menu)
            {

            case 1:
            {
                view_complaint();
                system("PAUSE");
                break;
            }

            case 2:
            {
                update_complaint();
                system("PAUSE");
                break;
            }

            case 3:
            {
                cancel_complaint();
                system("PAUSE");
                break;
            }
            case 4:
            {
                printf("You are Logged Out...!\n");
                system ("PAUSE");
                home();
                break;
            }

            }

        } while (menu != 4);
        printf("Thank you");
        system ("PAUSE");
    }

}


/*The purpose of this function is to search and output the details of complaint using complaint number. 
It uses a temp pointer to node and search for given complaint number by traversing the list.
And as soon as it finds the complaint, it breaks out of loop and outputs all details of the given complaint number.*/

void view_complaint()
{
    int num;          //variable to search
    system("cls");
    struct node *temp;

    temp = start_ptr;
    bool found = false;
    printf("\n");
    printf("#####################################################################################\n \n");
    printf("Complaint Management System\n");
    printf("Enter the Complaint Number To Look into The Complaint Details\n");
    scanf("%d", &num);
    printf("\n \n");

    printf("\t\tHere is the Complaint list\n \n");


    if (temp == NULL)
    {
        printf("\tThere is no Complaint to show\n\t\t\tSo The List is Empty\n\n\n");
    }
    while (temp != NULL && !found)
    {
        if (temp->complaint_number == num)
        {
            found = true;
        }
        else
        {
            temp = temp -> next;
        }
        if (found)
        {
            printf("Complaint Number : %d", temp->complaint_number);
            printf("\n");
            printf("Customer Name: %s", temp->customerName);

            printf("Complain Date : %s", temp->date);


            printf("Complaint description: \n");

            printf("%s", temp->x);

            printf("\n");

        }


    }
}


/*The function searches for the node to be deleted and upon reaching the node it modifies the pointers to skip that node.
Thereafter it releases the dynamically allocated memory using free().*/
void cancel_complaint()
{
    system("cls");
    int num, count;
    printf("\n");
    printf("#####################################################################################");
    printf("Complaint Management System\n");
    printf("Enter the Complaint number you want to delete \n");
    scanf("%d", &num);
    struct node *q;
    struct node *temp;
    bool found;

    if (start_ptr == NULL)
        printf("Can not cancel from an empty list.\n");
    else
    {
        if (start_ptr->complaint_number == num)
        {
            q = start_ptr;
            start_ptr = start_ptr->next;
            count--;
            if (start_ptr == NULL)
                last = NULL;
            free(q);
            printf("The Complaint is Cancelled Successfully");
        }
        else
        {
            found = false;
            temp = start_ptr;
            q = start_ptr->next;

            while ((!found) && (q != NULL))
            {
                if (q->complaint_number != num)
                {
                    temp = q;
                    q = q-> next;
                }
                else
                    found = true;
            }

            if (found)
            {
                temp->next = q->next;
                count--;

                if (last == q)
                    last = temp;
                free(q);
                printf("The Complaint is Cancelled Successfully");
            }
            else
                printf("Complaint to be Cancelled is not in the list.");
        }
    }
}    //End function


/*It has somewhat similar working to view function.
Like view function it traverses the list to find the node and breaks out of it. And then updates the values there.*/
void update_complaint()
{
    system("cls");
    int sid;
    bool found;
    found = false;
    temp = start_ptr;
    printf("\n");
    printf("#####################################################################################");
    printf("Complaint Management System\n");
    printf("Enter Complaint Number To Update: ");
    scanf("%d", &sid);
    if (temp == NULL && sid == 0)
    {
        printf("No Complaint To Update..!");
    }

    else
    {
        while (temp != NULL && !found)
        {
            if (temp->complaint_number == sid)
            {
                found = true;
            }
            else
            {
                temp = temp -> next;
            }
            if (found)
            {
                printf( "Change  Complaint Number: ");
                scanf("%d", &temp->complaint_number);
                fgets(temp->customerName, sizeof(temp->customerName), stdin);
                printf( "Change Customer Name: ");
                fgets(temp->customerName, sizeof(temp->customerName), stdin);
                printf("Change Date : ");
                fgets(temp->date, sizeof(temp->date), stdin);
                printf( "Complaint Description:");
                printf("( 1000 words maximum ) \n");
                printf( "  " );
                fgets(temp->x, sizeof(temp->x), stdin);

                system("PAUSE");
                temp = temp->next;


            }

            printf("COMPLAINT RECORD UPDATED....!\n\n");
        }

        if (temp != NULL && temp->complaint_number != sid)
        {
            printf("Invalid Complaint Number...!\n\n");
        }

    }

}


//The program uses Sublime Text Editor to format the indents.
////////////////////////////////END///////////////////////////////////////////////
