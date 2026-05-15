#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[50];
    char artist[50];
    struct Song *next;
};

struct Song *head = NULL;

void createPlaylist() {
    head = NULL;
    printf("Playlist Created Successfully\n");
}

void addSong(char title[], char artist[]) {
    struct Song *newNode;
    newNode = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        newNode->next = head; // Point to itself to make it circular
    }
    else {
        struct Song *temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Point back to head to maintain circular structure
    }
    printf("Song Added Successfully\n");
}

void viewPlaylist() {
    struct Song *temp = head;
    if(head == NULL) {
        printf("\nNo Songs in Playlist\n");
        return;
    }
    do {
        printf("Title  : %s\n", temp->title);
        printf("Artist : %s\n", temp->artist);
        temp = temp->next;
    } while(temp != head);
}

void searchSong(char title[]) {
    struct Song *temp = head;
    int found = 0;
    if(head == NULL) {
        printf("\nNo Songs in Playlist\n");
        return;
    }
    do {
        if(strcmp(temp->title, title) == 0) {
            printf("\nSong Found\n");
            printf("Title  : %s\n", temp->title);
            printf("Artist : %s\n", temp->artist);
            found = 1;
            break;
        }
        temp = temp->next;
    } while(temp != head);
    if(!found) {
        printf("\nSong Not Found in Playlist\n");
    }
}

int main() {
    createPlaylist();
    addSong("Main hoon ghatotkach", "Sudesh Bhosle");
    addSong("Mere buddy", "various artists");
    addSong("Bhoot Uncle", "various artists");

    printf("\nViewing Playlist:\n");
    viewPlaylist();

    printf("\nSearching for 'Bhoot Uncle':\n");
    searchSong("Bhoot Uncle");

    printf("\nSearching for 'Mere buddy':\n");
    searchSong("Mere buddy");

    return 0;
}