<p align="center">
  This project is about programming a function that returns a line read from a file descriptor.
</p>

# Project

This is the secound project of the common core at 42 São Paulo. The project wants that you code a function that read from a file descriptor and returns an allocated line. The returned line has a _newline character_ at the end of the string followed by a _null character_.

The **get_next_line** works with all file descriptors, so it's also possible to read from the _Standard Input_, _Standard Output_ and _Standard Error_.

# Documentation

#### NAME

get_next_line - read a line from a file descriptor

#### SYNOPSIS

```c
// MANDATORY: Supports only one file descriptor
#include  "get_next_line.h"
```

#### PROTOTYPE

```c
char    *get_next_line(int fd);
```

#### DESCRIPTION

**get_next_line** will read a line from a file descriptor and return an allocated string. If file descriptor is empty or EOF, a NULL will be returned. The line returned is allocated with malloc; the caller must free it when finished. The line returned has the final newline.

#### RETURN VALUE

**get_next_line** returns the text of the first line read from a file descriptor. A blank line returns a empty string. If **EOF** is encontered while reading a line, and the line is empty, **NULL** is returned.

# How to test it?

Clone this repository:

```shell
git clone https://github.com/victorcploureiro/get_next_line_project.git get_next_line
```

Then compile the files as following:

> [!NOTE]
> The `get_next_line.c` is limited just to one file descriptor at time.

#### Mandatory:

Reads from just one file descriptor.

```shell
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o get_next_line
```

#### Execution:

Reads from the standart output.

```shell
./get_next_line
```

Reads from a file.

```shell
./get_next_line example.txt
```

> [!IMPORTANT]
> The **get_next_line** function has a buffer size of 42 bits, but is possible to redefine it.<br>
> Use the flag `-D BUFFER_SIZE=<value>` (eg. `-D BUFFER_SIZE=2048`) to redefine the buffer size.
