Pr 14:

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("Process creation failed.\n");
    }
    else if (pid == 0) {
        // Child process
        printf("This is the Child Process.\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else {
        // Parent process
        printf("This is the Parent Process.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}

Pr 15:

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n, i;
    pid_t pid;

    printf("Enter the number of child processes to create: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        pid = fork();

        if (pid < 0) {
            // Fork failed
            perror("Fork failed");
            exit(1);
        } 
        else if (pid == 0) {
            // Child process
            printf("Child %d: PID = %d, Parent PID = %d\n", 
                   i + 1, getpid(), getppid());
            exit(0);  // Child exits to prevent further forking
        }
        // Parent continues loop to create next child
    }

    // Parent waits for all children
    for (i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("All child processes created and terminated successfully.\n");

    return 0;
}



Pr 16:

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 1000000   // Large array size

int A[SIZE], B[SIZE];
int Sum[SIZE], Diff[SIZE];

// Thread function for addition
void* addition(void* arg) {
    for (int i = 0; i < SIZE; i++) {
        Sum[i] = A[i] + B[i];
    }
    pthread_exit(NULL);
}

// Thread function for subtraction
void* subtraction(void* arg) {
    for (int i = 0; i < SIZE; i++) {
        Diff[i] = A[i] - B[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Initialize arrays with sample values
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = SIZE - i;
    }

    // Create addition thread
    if (pthread_create(&thread1, NULL, addition, NULL) != 0) {
        perror("Failed to create addition thread");
        return 1;
    }

    // Create subtraction thread
    if (pthread_create(&thread2, NULL, subtraction, NULL) != 0) {
        perror("Failed to create subtraction thread");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Addition and Subtraction completed successfully.\n");

    // Print first 5 results as verification
    printf("\nFirst 5 Results:\n");
    for (int i = 0; i < 5; i++) {
        printf("A[%d]=%d, B[%d]=%d, Sum=%d, Diff=%d\n",
               i, A[i], i, B[i], Sum[i], Diff[i]);
    }

    return 0;
}


Pr 17:

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char *path;

    // If no directory is given, use current directory
    if (argc == 1) {
        path = ".";
    } else {
        path = argv[1];
    }

    // Open directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    // Read and print directory entries
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close directory
    closedir(dir);

    return 0;
}

Pr 18:

#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct utmp entry;
    int fd;

    // Open utmp file
    fd = open("/var/run/utmp", O_RDONLY);
    if (fd == -1) {
        perror("Unable to open utmp file");
        return 1;
    }

    printf("USER\t\tTTY\t\tLOGIN TIME\n");
    printf("-------------------------------------------------------------\n");

    // Read utmp entries
    while (read(fd, &entry, sizeof(entry)) == sizeof(entry)) {
        if (entry.ut_type == USER_PROCESS) {
            // Convert login time to readable format
            time_t login_time = entry.ut_tv.tv_sec;
            printf("%-15s %-15s %s",
                   entry.ut_user,
                   entry.ut_line,
                   ctime(&login_time));
        }
    }

    close(fd);
    return 0;
}


Pr 19:

# AWK is a powerful tool for text processing, reporting, and data extraction in Unix/Linux systems.
# AWK is a text-processing programming language used to:

# Scan files line by line
# Process and manipulate text
# Generate formatted output


# Variable            Meaning
# $1, $2, ...        Fields (words in a line)
# $0            Entire line
# NF            Number of fields
# NR            Line number

# awk '{ print }' file.txt -> prints entire file.
# awk '{ print $1 }' file.txt -> print first column.
# awk '/hello/ { print }' file.txt -> print line containinf word 'hello'.


#Save the program in a file, e.g., capital.awk and Run using:
# awk -f capital.awk input.txt
# here input.txt in an input file to be passed as command line argument


# File: to_upper.awk

# Function to convert a word to uppercase
function toCapital(word) {
    return toupper(word)
}

{
    for (i = 1; i <= NF; i++) {
        $i = toCapital($i)
    }
    print
}


Pr 20:

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_SIZE sizeof(int)

int main() {
    int shmid;
    int *shared_var;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    // Attach shared memory
    shared_var = (int *)shmat(shmid, NULL, 0);
    if (shared_var == (int *) -1) {
        perror("shmat failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        sleep(1);  // Wait for parent to write
        printf("Child: Value read from shared memory = %d\n", *shared_var);

        *shared_var += 10;
        printf("Child: Value after modification = %d\n", *shared_var);

        shmdt(shared_var); // Detach
        exit(0);
    } 
    else {
        // Parent process
        *shared_var = 100;
        printf("Parent: Value written to shared memory = %d\n", *shared_var);

        wait(NULL); // Wait for child

        printf("Parent: Final value in shared memory = %d\n", *shared_var);

        shmdt(shared_var);        // Detach
        shmctl(shmid, IPC_RMID, NULL); // Remove shared memory
    }

    return 0;
}
