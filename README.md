# ft_get_next_line

## Description

get_next_line is a function that reads a file line by line. It is a function that is part of the 42 curriculum and is used to teach students how to use static variables and memory allocation in C.

## Installation
To use the get_next_line function in your project, include the `get_next_line.h` header file in your source code:

```c
#include "get_next_line.h"
```

## Usage
The `get_next_line` function reads a file descriptor and returns a line ending with a newline character from a file descriptor. The function returns the line that was read with the newline character. The function returns `NULL` when the reading is finished or an error occurs.

```c
char* get_next_line(int fd);
```

## Example

### Mandatory
in order to read a file line by line, you can use the following code:
```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: Could not open file\n");
        return (1);
    }
    while (true)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

1. Compile your source code with the `get_next_line.c` file:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 example.c get_next_line.c -o example
```

2. Run the executable:
```bash
./example
```

3. The output will be the content of the file `example.txt` printed line by line.

### Note
The `BUFFER_SIZE` macro is used to define the size of the buffer used to read the file. The `BUFFER_SIZE` must be greater than 0 and less than or equal to `INT_MAX` (limits.h). The `BUFFER_SIZE` can be defined at compile time using the `-D` flag or in the source code using the `#define` directive.

### Bonus
The `get_next_line` function from the bonus version `get_next_line_bonus.c` can be used to read from multiple file descriptors. The function can be used to read from standard input, a file, or a network socket.

```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1;
    int fd2;
    char *line;

    fd1 = open("example1.txt", O_RDONLY);
    if (fd1 == -1)
    {
        printf("Error: Could not open file\n");
        return (1);
    }
    fd2 = open("example2.txt", O_RDONLY);
    if (fd2 == -1)
    {
        printf("Error: Could not open file\n");
        return (1);
    }
    while (true)
    {
        line = get_next_line(fd1);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
        line = get_next_line(fd2);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
    }
    close(fd1);
    close(fd2);
    return (0);
}
```

1. Compile your source code with the `get_next_line_bonus.c` file:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 example_bonus.c get_next_line_bonus.c -o example_bonus
```

2. Run the executable:
```bash
./example_bonus
```
3. The output will be the content of the files `example1.txt` and `example2.txt` printed line by line.

## Final Note
If you have any suggestions or improvements, feel free to open an issue or submit a pull request.