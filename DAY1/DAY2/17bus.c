// bus reservation system : book bus seats using seat array system
#include <stdio.h>
#define MAX_SEATS 40
int seats[MAX_SEATS] = {0}; // 0 means available, 1 means booked
void book_seat(int seat_number)
{
    if (seat_number < 1 || seat_number > MAX_SEATS)
    {
        printf("Invalid seat number. Please choose between 1 and %d.\n", MAX_SEATS);
        return;
    }
    if (seats[seat_number - 1] == 0)
    {
        seats[seat_number - 1] = 1; // Mark seat as booked
        printf("Seat %d booked successfully.\n", seat_number);
    }
    else
    {
        printf("Seat %d is already booked. Please choose another seat.\n", seat_number);
    }
}
void display_seats()
{
    printf("Seat availability:\n");
    for (int i = 0; i < MAX_SEATS; i++)
    {
        printf("Seat %2d: %s\n", i + 1, seats[i] == 0 ? "Available" : "Booked");
    }
}
int main()
{
    int choice, seat_number;
    while (1)
    {
        printf("\nBus Reservation System\n");
        printf("1. Book a seat\n");
        printf("2. Display seat availability\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter seat number to book (1-%d): ", MAX_SEATS);
            scanf("%d", &seat_number);
            book_seat(seat_number);
            break;
        case 2:
            display_seats();
            break;
        case 3:
            printf("Exiting the system. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}