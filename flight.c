#include <stdio.h>
#include <string.h>

struct Ticket {
    char name[50];
    char passportNumber[20];
    char mobileNumber[15];
    char destination[20];
    int numberOfTickets;
};

void displayMenu();
void bookTicket();
void displayDestinations();
void displayCoupons();
void displayBookings();

struct Ticket bookings[100];
int totalBookings = 0;
int availableTickets[] = {120, 100, 180, 115, 210};
float ticketPrices[] = {550, 40, 60, 80, 80};
char* destinations[] = {"India", "Malaysia", "Thailand", "South Korea", "Japan"};
char* coupons[] = {"ABC8765", "XYZ1234", "JKL5019"};
float discounts[] = {0.2, 0.4, 0.5};

int main() {
    int choice;
    
    do {
        printf("\n");
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("*\n");
        
        
        switch(choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                displayDestinations();
                break;
            case 3:
                displayBookings();
                break;
            case 4:
                break;
                
            default:
                printf("Invalid .. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\nReady to Travel? Book your ticket from us\n");
    printf("1. Book a tickets\n");
    printf("2. Available Ticket Details\n");
    printf("3. Print List of Ticket Bookings\n");
    printf("4. Exit\n");
}

void bookTicket() {
    printf("\nEnter passenger details:\n");
    struct Ticket newBooking;
    printf("Name: ");
    scanf("%s", newBooking.name);
    printf("Passport Number: ");
    scanf("%s", newBooking.passportNumber);
    printf("Mobile Number: ");
    scanf("%s", newBooking.mobileNumber);
    
    displayDestinations();
    printf("Enter destination number: ");
    int destinationChoice;
    scanf("%d", &destinationChoice);
    strcpy(newBooking.destination, destinations[destinationChoice - 1]);
    
    printf("Enter number of tickets: ");
    scanf("%d", &newBooking.numberOfTickets);
    
    availableTickets[destinationChoice - 1] -= newBooking.numberOfTickets;
    
    bookings[totalBookings++] = newBooking;
    
    printf("Ticket booked successfully!\n");
}

void displayDestinations() {
    printf("\nAvailable destinations:\n");
    printf("Destination\tTicket Price\tTickets Available\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t\t$%.2f\t\t%d\n", destinations[i], ticketPrices[i], availableTickets[i]);
    }
}

void displayCoupons() {
    printf("\nAvailable coupons:\n");
    printf("Coupon Number\tDiscount\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\t\t%.0f%%\n", coupons[i], discounts[i] * 100);
    }
}

void displayBookings() {
    if (totalBookings == 0) {
        printf("\nNo bookings yet.\n");
        return;
    }
    
    printf("\nTicket bookings:\n");
    printf("Name\tPassport\tDestination\tTickets\n");
    for (int i = 0; i < totalBookings; i++) {
        printf("%s\t%s\t%s\t%d\n", bookings[i].name, bookings[i].passportNumber, bookings[i].destination, bookings[i].numberOfTickets);
    }
}

void displayTotalBookings() {
    if (totalBookings == 0) {
        printf("\nNo bookings yet.\n");
        return;
    }
    
    printf("\nNumber of Ticket bookings: %d", totalBookings);
}