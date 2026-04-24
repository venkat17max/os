#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    int fd;
    char write_buf[] = "Operating System Lab";
    char read_buf[50];

    struct stat st;
    struct flock fl;

    DIR *d;
    struct dirent *dir;

    // Open/Create file
    fd = open("oslab.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write to file
    write(fd, write_buf, strlen(write_buf));

    // Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read from file
    read(fd, read_buf, sizeof(read_buf));
    printf("File content: %s\n", read_buf);

    // File locking using fcntl
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;  // lock entire file

    fcntl(fd, F_SETLK, &fl);
    printf("File locked using fcntl()\n");

    // Get file stats
    stat("oslab.txt", &st);
    printf("File size: %ld bytes\n", st.st_size);

    // Close file
    close(fd);

    // Open directory
    printf("Directory contents:\n");
    d = opendir(".");

    if (d == NULL) {
        perror("opendir");
        return 1;
    }

    // Read directory contents
    while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }

    // Close directory
    closedir(d);

    return 0;
}