#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>
#include<conio.h>
#include <windows.h>

#define MAX_LENGTH 100
#define FILE_NAME "user_data.txt"
#define ROWS 4
#define COLS 5
bool function_executed = false;
void waitForEnter();
void press();
void menu();
void waiting();
void getPassword(char *password, int maxLength);
int verify();
int loginsystem();
void complain();
void createAccount();
int login();
void displaySeats();
void bookSeat();
void commodity();
void traintiming();
void cancelSeat();
int print=0;
void setConsoleColor(int color) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
}

bool seats[ROWS][COLS] = {false};
int prices[ROWS][COLS] = {
    {250, 250, 250, 250, 250},
    {250, 250, 250, 250, 250},
    {175, 175, 175, 175, 175},
    {150, 150, 150, 150, 150}
};





int main() {

    while (1) {
        int app;
        printf("1:=\tPakistan Railways                  \t2:Sign In\n");
        printf(" \tUpdated on:22 Jan 2025 02:00Am");

        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\n\tSearch Trains\n ");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nFrom Station <> To Station\nTravel Date:");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\n\tSearch Trains\n");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("3: Train Timings\t4: Freight rates\t5: Become Member\n");

        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\nTicket Information\n");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("6: Pending Tickets\t7: Booked Tickets\t8: Cancelled Tickets\n");
        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\nOther Information\n");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("9:Notifications \t 10:Booking History");
        printf("\n\n\t\t\t 11:BOOK\n\t\t\tE-TICKET\n");
        printf("\n12: Re-sync    13: Train Canclled\t14: Helpline 15: Complain\n\n16: Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &app);
        printf("press enter to continue");
        system("cls");

        switch (app) {
        	case 1:
        		menu();
        		break;
        	case 2:
				verify();
				press();
				system("cls");
				break;
            case 3:
                traintiming();
                press();
                break;
            case 4:
                commodity();
                press();
                system("cls");
                break;
            case 5:
            	if(verify()==1){
            	printf("you have already become member by joining\n");
				}
				press();
				system("cls");
				break;
            case 6:
				if(verify()==1){
                displaySeats();}
                press();
                system("cls");
                break;
            case 7:
            	if(verify()==1){
            	displaySeats();
            	bookSeat();}
            	press();
            	system("cls");
                break;
            case 8:
            	if(verify()==1){
                cancelSeat();}
                press();
                system("cls");
                break;
            case 9:
            	if(verify()==1){
            	printf("no notifications..........\n\n");
				}
				press();
				system("cls");
				break;
            case 10:
			if(verify()==1){
			 displaySeats();}
			 press();
			 system("cls");
			 break;
			case 11:
			 verify();
			 displaySeats();
			 bookSeat();
			 break;
			 case 12:
            	setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			   printf("\nRe-synced.....\n");
			   setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			   press();
			   system("cls");
			   break;
			 case 13:
			 verify();
			 cancelSeat();
			 break;
			 case 14:
			 printf("=======General Queries PR Helpline#117=========\nFor E-Ticket issuance,SMS delivery or payment\ndeduction/refund related problems.Tap to call\n\thelplinenumbers below.");
			 printf("\n\nHelpline:03332482867\tSMS Delivery Problem:\n");
			 printf("car4umer@gmail.com\t+92 308 4440479\n");
			 printf("\n\nEasyPaisa Problem:\tJazzCash Problem:\n");
			 printf("3737                  \t4444");
			 printf("\n\nUBL Omni Problem:\tUBL Card Problem:\n");
			 printf("+92 21 111 825 777\t+92 21 111 825 888\n");
			 press();
			 system("cls");
			 break;
			 case 15:
			 	complain();
			 	press();
			 	system("cls");
			 	break;
			 case 16:
			 	printf("Exit");
				waiting();
				system("cls");
				printf("Exited");
				return 1;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void waiting() {
    int i;
    for (i = 0; i < 3; i++) {
        fflush(stdout);
        printf(".");
        Sleep(1000);
    }
    printf("\n");
}
int verify() {
    if (!function_executed) { // Check if the user is already logged in
        if (loginsystem() == 1) { // Login successful
            function_executed = true;
            return 1;
        }
    } else {

    	for(print;print<1;print++){
        printf("already signed in\n");}
        return 1;
    }
    return 0; // Login failed
}


int loginsystem() {
    int choice;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Welcome to Pakistan Railway App\n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    while (1) { // Loop to handle invalid choices
        printf("1. Create Account\n");
        printf("2. Login\n3. Back....\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                waiting();
                system("cls");
                printf("Created an Account...\n");
                break;
            case 2:
                if (login()) {
                    printf("Logging In");
                    waiting();
                    system("cls");
                    printf("Login successful!\n\n");
                    return 1;
                } else {
                    printf("Invalid CNIC or password. Try Again\n");
                }
                break;
            case 3:
                system("cls");
                printf("Backed....\n\n");
                return 0;
            default:
                printf("Invalid choice. Try Again...\n");
        }
    }
}

bool checkFunction(int num) {
    if (num > 0 && num < 10) {
        printf("Function ran successfully with number: %d\n", num);
        return true;
    }}
void displaySeats() {
    printf("\n=== Seat Booking System ===\n");
    printf("Legend: [X] Booked, [ ] Vacant\n");
    printf("Seat Map:\n");

    int i, j; // Declare variables outside the loop
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (seats[i][j]) {
                printf("[X] ");
            } else {
                printf("[%d] ", prices[i][j]);
            }
        }
        printf("\n");
    }
}


void bookSeat() {
    int row, col;

    printf("\nEnter the row and column of the seat you want to book (e.g., 0 1 for Row 0, Column 1): ");
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (!seats[row][col]) {
            printf("Seat booked successfully! Price: Rs. %d\n", prices[row][col]);
            seats[row][col] = true; // Mark seat as booked
        } else {
            printf("Sorry, this seat is already booked.\n");
        }
    } else {
        printf("Invalid seat selection. Please try again.\n");
    }
}


void cancelSeat() {
    int row, col;

    displaySeats();

    printf("\nEnter the row and column of the seat you want to cancel (e.g., 0 1 for Row 0, Column 1): ");
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (seats[row][col]) {
            seats[row][col] = false; // Mark seat as vacant
            printf("Seat at Row %d, Column %d successfully cancelled.\n", row, col);
        } else {
            printf("The selected seat is not booked. Nothing to cancel.\n");
        }
    } else {
        printf("Invalid seat selection. Please try again.\n");
    }
}

void getPassword(char *password, int maxLength) {
    int i = 0;
    char ch;

    printf("Enter password: ");
    while (i < maxLength - 1) {
        ch = _getch(); // Read a single character

        if (ch == '\r') { // If Enter key is pressed
            break;
        } else if (ch == '\b') { // If Backspace key is pressed
            if (i > 0) {
                printf("\b \b"); // Remove the last '*'
                i--;
            }
        } else {
            if (i < maxLength - 1) {
                password[i++] = ch; // Add character to the password
                printf("*"); // Print '*' to mask the character
            }
        }
    }
    password[i] = '\0'; // Null-terminate the string
    printf("\n"); // Move to the next line after input
}


void createAccount() {
    char cnic[MAX_LENGTH], password[MAX_LENGTH], phone[MAX_LENGTH];

    printf("Enter your CNIC (without dashes): ");
    scanf("%s", cnic);

    getchar(); // Clear the newline character left in the input buffer

    getPassword(password, MAX_LENGTH);

    printf("Enter your phone number: ");
    scanf("%s", phone);

    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%s\n%s\n%s\n", cnic, password, phone); // Save credentials to file
    fclose(file);

    printf("Account created successfully.\n");
}

int login() {
    char storedCnic[MAX_LENGTH], storedPassword[MAX_LENGTH], storedPhone[MAX_LENGTH];
    char enteredCnic[MAX_LENGTH], enteredPassword[MAX_LENGTH];

    printf("Enter your CNIC(without dashes): ");
    scanf("%s", enteredCnic);

    getPassword(enteredPassword, MAX_LENGTH); // Use secure password input

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No account found. Please create an account first.\n");
        return 0;
    }

    fscanf(file, "%s\n%s\n%s\n", storedCnic, storedPassword, storedPhone);
    fclose(file);

    if (strcmp(enteredCnic, storedCnic) == 0 && strcmp(enteredPassword, storedPassword) == 0) {
        return 1;
    }

    return 0;
}





void commodity() {
    char commodity[MAX_LENGTH];
    char fromStation[MAX_LENGTH];
    char toStation[MAX_LENGTH];

    while (1) {
        printf("\nEnter Commodity (e.g., Fertilizer, Bauxite, Cement, Coal): ");
        scanf("%s", commodity);

        printf("Enter From Station: ");
        scanf("%s", fromStation);

        printf("Enter To Station: ");
        scanf("%s", toStation);

        float freightCost = 0;
        if (strcmp(commodity, "Fertilizer") == 0) {
            freightCost = 10.3;
        } else if (strcmp(commodity, "Bauxite") == 0) {
            freightCost = 20.1;
        } else if (strcmp(commodity, "Cement") == 0) {
            freightCost = 12.3;
        } else if (strcmp(commodity, "Coal") == 0) {
            freightCost = 30.4;
        } else {
            printf("Invalid commodity. Try again.\n");
            continue;
        }

        printf("Freight Cost: %.2f\n", freightCost);

        break;
    }
}


void traintiming() {
    char trains[][50] = {
        "101UP - Subak Raftar D:00:30 AM",
        "102DN - Subak Raftar D:07:30 AM",
        "103UP - Subak Kharam D:09:00 AM",
        "104DN - Subak Kharam D:06:45 AM",
        "105UP - Rawal Express D:08:15 AM",
    };

    int numTrains = sizeof(trains) / sizeof(trains[0]);

    printf("Train Timings:\n");

    int i; // Declare the loop variable outside the loop
    for (i = 0; i < numTrains; i++) {
        printf("%s\n", trains[i]);
    }

    char searchQuery[50];
    printf("\nSearch Here: ");
    scanf("%s", searchQuery);

    int found = 0;
    for (i = 0; i < numTrains; i++) { // Reuse the same loop variable
        if (strstr(trains[i], searchQuery) != NULL) {
            printf("%s\n", trains[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Train not found.\n");
    }
}
void complain(){
	int feed;
	char name[MAX_LENGTH], contact[MAX_LENGTH], email[MAX_LENGTH], location[MAX_LENGTH], feedback[500],other[MAX_LENGTH];
	while(1){
        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("\t\tFeedBack\n\n");
	printf("\nPlease Fill the details below:\n");
	setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("Select the issue\n1:E-Ticket Booking Issue \n2:E-Ticket Refund Not Recevied \n3:E-Ticket SMS/Email Not Delivered \n4:E-Ticket General Query \n5:Account Registration Issue \n6:Other\n");
	printf("Enter Your choice: ");
	scanf("%d",&feed);
	system("cls");
	switch(feed){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("selected the issue");
			goto feedback;
		case 6:
			printf("please enter the other issue: ");
			scanf("%s",&other);
			goto feedback;
		default:
		 	printf("wrong selection\n");
		 	break;
		}}
	feedback:
	system("cls");
	printf("Enter Full Name: ");
    scanf(" %[^\n]", name);


    printf("Contact no.: ");
    scanf("%s", contact);


    printf("Email: ");
    scanf("%s", email);


    printf("Location: ");
    scanf(" %[^\n]", location);


    printf("Feedback (1-100 words):\n");
    scanf(" %[^\n]", feedback);


    printf("\nFeedback submitted successfully!\n");
    printf("We will contact you within 5 business days.\n");


    printf("\n--- Submitted Details ---\n");
    printf("Full Name: %s\n", name);
    printf("Contact No.: %s\n", contact);
    printf("Email: %s\n", email);
    printf("Location: %s\n", location);
    printf("Feedback: %s\n", feedback);

}
void menu(){
	int choice;
	printf("Pakistan Railways\n\nMobile Number:\n_______________________\nEmail Address:\n_______________________\n1:view Booked Seats\n\n2:See Train Timings\n\n3:Faq's\n\n4:Share App\n\n5:Rate Us\n\n6:About Us\n\n7:Sign Out\n\nEnter Choice: ");
	scanf("%d",&choice);
	system("cls");
	while (getchar() != '\n');
	switch(choice){
		case 1:
			    verify();
            	displaySeats();
            	bookSeat();
            break;
		case 2:
			traintiming();
			while (getchar() != '\n');
			while (getchar() != '\n');
			break;
		case 3:
			printf("\t==========FAQ's==========\n");
		 printf("Pakistan Railways provides a comprehensive FAQ section on their official website, addressing common inquiries. Here are some key points:\n\nBooking Tickets:\n You can reserve seats or berths up to 90 days in advance through Railway Reservation Offices, PRACS Reservation Offices, and online e-ticketing platforms.\nReservation Status:\nTo check your ticket's reservation status, contact Reservation Offices via telephone, visit in person, or check your account dashboard before the train's departure.\nComputerized Reservation Facilities:\n These are available through online e-ticketing and all main Railway reservation offices, including options for return journey tickets.");
		 printf("Boarding Without a Reserved Ticket:\n If you don't have a reserved ticket, you may contact the Conductor Guard to inquire about available accommodation.\n");
		 printf("Press Enter to Continue");
		 while (getchar() != '\n');
		 break;
		case 4:
		printf("====Share Apps====\n\nWhatsapp\nInstagram\nGmail\n\nPress Enter to Continue");
		while (getchar() != '\n');
		break;
	case 5:{


			int rate;
		printf("========Rate US=========\n");
		printf("from 1-5: ");
		scanf("%d",&rate);
		while (getchar() != '\n');
		printf("thank you for your kind rating :)\n");
		printf("Enter to continue");
		while (getchar() != '\n');
		system("cls");
		break;
	}
		case 6:
			printf("========About Us========\n");
			printf("\tPakistan Railways\n    \t6.4.2(p)\n\nPress Enter to Continue");
			while (getchar() != '\n');
			break;
		break;
		case 7:
			if(function_executed==true){
			function_executed = false;
			printf("signed out......\n");}
			else{
				printf("You are not signed In...\n");
			}
			printf("enter to continue....");
			while (getchar() != '\n');
			break;
		default:
		printf("Invalid choice. Try Again...\n");
		break;

	}
	system("cls");
}
void press() {
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');
    getchar();
}


