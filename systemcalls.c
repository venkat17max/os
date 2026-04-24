#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];
    int n;

    // Open file (read only)
    fd = open("test.txt", O_RDONLY);

    if(fd < 0) {
        write(1, "Error opening file\n", 20);
        return 1;
    }

    // Read from file
    n = read(fd, buffer, 100);

    // Write to screen (1 = stdout)
    write(1, buffer, n);

    // Close file
    close(fd);

    return 0;
}
------------
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d;
    struct dirent *dir;

    // Open current directory
    d = opendir(".");

    if (d == NULL) {
        printf("Cannot open directory\n");
        return 1;
    }

    printf("Files in directory:\n");

    // Read directory entries
    while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }

    // Close directory
    closedir(d);

    return 0;
}