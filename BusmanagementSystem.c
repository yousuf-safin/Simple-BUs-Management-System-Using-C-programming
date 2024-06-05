#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 100
#define MAX_ROUTES 100
#define MAX_TICKETS 100

typedef struct {
    int busID;
    char driverName[50];
    char busNumber[20];
    int capacity;
    int routeNumber;
} Bus;

typedef struct {
    int routeNumber;
    char startingPoint[50];
    char destination[50];
    char stops[100];
} Route;

typedef struct {
    int passengerID;
    char passengerName[50];
    int routeNumber;
    char dateOfTravel[20];
    int seatNumber;
} Ticket;

Bus buses[MAX_BUSES];
int busCount = 0;

Route routes[MAX_ROUTES];
int routeCount = 0;

Ticket tickets[MAX_TICKETS];
int ticketCount = 0;

void registerBus() {
    if (busCount < MAX_BUSES) {
        printf("Enter Bus ID: ");
        scanf("%d", &buses[busCount].busID);
        printf("Enter Driver Name: ");
        scanf("%s", buses[busCount].driverName);
        printf("Enter Bus Number: ");
        scanf("%s", buses[busCount].busNumber);
        printf("Enter Capacity: ");
        scanf("%d", &buses[busCount].capacity);
        printf("Enter Route Number: ");
        scanf("%d", &buses[busCount].routeNumber);
        busCount++;
        printf("Bus registered successfully!\n");
    } else {
        printf("Bus registration limit reached!\n");
    }
}

void displayBuses() {
    for (int i = 0; i < busCount; i++) {
        printf("Bus ID: %d\n", buses[i].busID);
        printf("Driver Name: %s\n", buses[i].driverName);
        printf("Bus Number: %s\n", buses[i].busNumber);
        printf("Capacity: %d\n", buses[i].capacity);
        printf("Route Number: %d\n\n", buses[i].routeNumber);
    }
}

void addRoute() {
    if (routeCount < MAX_ROUTES) {
        printf("Enter Route Number: ");
        scanf("%d", &routes[routeCount].routeNumber);
        printf("Enter Starting Point: ");
        scanf("%s", routes[routeCount].startingPoint);
        printf("Enter Destination: ");
        scanf("%s", routes[routeCount].destination);
        printf("Enter Stops: ");
        scanf("%s", routes[routeCount].stops);
        routeCount++;
        printf("Route added successfully!\n");
    } else {
        printf("Route addition limit reached!\n");
    }
}

void displayRoutes() {
    for (int i = 0; i < routeCount; i++) {
        printf("Route Number: %d\n", routes[i].routeNumber);
        printf("Starting Point: %s\n", routes[i].startingPoint);
        printf("Destination: %s\n", routes[i].destination);
        printf("Stops: %s\n\n", routes[i].stops);
    }
}

void bookTicket() {
    if (ticketCount < MAX_TICKETS) {
        printf("Enter Passenger ID: ");
        scanf("%d", &tickets[ticketCount].passengerID);
        printf("Enter Passenger Name: ");
        scanf("%s", tickets[ticketCount].passengerName);
        printf("Enter Route Number: ");
        scanf("%d", &tickets[ticketCount].routeNumber);
        printf("Enter Date of Travel (YYYY-MM-DD): ");
        scanf("%s", tickets[ticketCount].dateOfTravel);
        printf("Enter Seat Number: ");
        scanf("%d", &tickets[ticketCount].seatNumber);
        ticketCount++;
        printf("Ticket booked successfully!\n");
    } else {
        printf("Ticket booking limit reached!\n");
    }
}

void displayTickets() {
    for (int i = 0; i < ticketCount; i++) {
        printf("Passenger ID: %d\n", tickets[i].passengerID);
        printf("Passenger Name: %s\n", tickets[i].passengerName);
        printf("Route Number: %d\n", tickets[i].routeNumber);
        printf("Date of Travel: %s\n", tickets[i].dateOfTravel);
        printf("Seat Number: %d\n\n", tickets[i].seatNumber);
    }
}

void mainMenu() {
    int choice;
    while (1) {
        printf("Bus Management System\n");
        printf("1. Register Bus\n");
        printf("2. Display Buses\n");
        printf("3. Add Route\n");
        printf("4. Display Routes\n");
        printf("5. Book Ticket\n");
        printf("6. Display Tickets\n");
        printf("7. Logout\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerBus();
                break;
            case 2:
                displayBuses();
                break;
            case 3:
                addRoute();
                break;
            case 4:
                displayRoutes();
                break;
            case 5:
                bookTicket();
                break;
            case 6:
                displayTickets();
                break;
            case 7:
                printf("Logging out...\n");
                return;
            case 8:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}

