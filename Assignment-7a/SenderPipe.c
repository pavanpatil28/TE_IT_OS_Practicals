#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;

    // FIFO file path
    char *myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    mkfifo(myfifo, 0666);

    char sentence[100];//buffer to store the users input

    while (1) {//taking input till user wants 
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);

        // Take an input sentence from the user
        printf(" \n\n >> Enter a sentence (or exit to end this process): ");
        fgets(sentence, sizeof(sentence), stdin);//taking standard input from user

        // Check if the user wants to exit
        if (strcmp(sentence, "exit\n") == 0) {
            break; // Exit the loop
        }

        // Write the input sentence on the FIFO
        write(fd, sentence, strlen(sentence) + 1);
        close(fd);

        // Now open FIFO for read only to get the response
        fd = open(myfifo, O_RDONLY);

        // Read and display the response of the receiver in  sender(pipe1) terminal
        read(fd, sentence, sizeof(sentence));
        printf("\n --> Receiver's Response: \n\n %s \n", sentence);

        close(fd);//closing the file descripter
    }

    return 0;
}

