//
//  main.c
//  microshell
//
//  Created by Achraf El khnissi on 1/3/23.
//  Copyright © 2023 Achraf El khnissi. All rights reserved.
//

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define FATAL error("error: fatal", "")
#define EQUAL 0

 int ft_strlen(char* str) {
     int i = 0;
     while (str[i])
         i++;
     return i;
 }

int error(char *msg, char* arg) {
    write(STDERR_FILENO, msg, ft_strlen(msg));
    write(STDERR_FILENO, arg, ft_strlen(arg));
    write(STDERR_FILENO, "\n", 1);
    return EXIT_FAILURE;
}

int handle_cd(char *path, int arg_count) {
    if (arg_count != 2)
         return error("error: cd: bad arguments", "");
    else if (chdir(path) != 0)
        return error("error: cd: cannot change directory to ", path);
    return EXIT_SUCCESS;
}

int count_args(char** cmd) {
    int num_args = 0;
    while(cmd[num_args] && strcmp(cmd[num_args], ";") && strcmp(cmd[num_args], "|"))
        num_args++;
    return num_args;
}

int execute(char **cmd, int cmd_size, int tmp_fd, char **env) {
    // Null-terminate the cmd array
    cmd[cmd_size] = NULL;

    // Redirect standard input to tmp file descriptor
    // and close tmp file descriptor
    if (dup2(tmp_fd, STDIN_FILENO) == -1 || close(tmp_fd) == -1)
        // If there was an error, return error message
        return FATAL;

    // Execute the command specified by cmd, with the
    // specified environment variables
    execve(cmd[0], cmd, env);

    // If execve returns, it means an error occurred
    // Print error message and return
    return error("error: cannot execute ", cmd[0]);
}

int execute_command(char** cmd, int cmd_size, int* tmp_fd, char** env) {
    // Create a child process
    int pid = fork();

    // If there was an error creating the child process, return error message
    if (pid < 0)
        return FATAL;

    // If this is the child process, Execute the command
    if (pid == 0) {
        if (execute(cmd, cmd_size, *tmp_fd, env) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    // If this is the parent process
    else {
        // Close tmp file descriptor
        if (close(*tmp_fd) == -1)
            return FATAL;

        // Wait for any child processes to complete
        while (waitpid(-1, NULL, WUNTRACED) != -1)
            ;

        // Redirect standard input to tmp file descriptor
        *tmp_fd = dup(STDIN_FILENO);
        // If there was an error, return error message
        if (*tmp_fd == -1)
            return FATAL;
    }
    return EXIT_SUCCESS;
}

int execute_piped_commands(char **cmd, int cmd_size, int *tmp_fd, char** env, int* fd) {
    // Create a pipe
    if (pipe(fd) == -1)
        return FATAL;

    // Create a child process
    int pid = fork();

    // If there was an error creating the child process,
    // return error message
    if (pid < 0)
        return FATAL;

    // If this is the child process
    if (pid == 0) {
      // Redirect standard output to the write end of the pipe
      // and close both ends of the pipe
      if (dup2(fd[1], STDOUT_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
          return FATAL;

      // Execute the command
      if (execute(cmd, cmd_size, *tmp_fd, env) == EXIT_FAILURE)
          return EXIT_FAILURE;
    }
    // If this is the parent process
    else {
        // Close the write end of the pipe and the tmp file descriptor
        if (close(fd[1]) == -1 || close(*tmp_fd) == -1)
            return FATAL;

        // Set tmp to the read end of the pipe
        *tmp_fd = fd[0];
    }
    return EXIT_SUCCESS;
}


int main(int ac, char **av, char **env){
    // Unused argument
    (void) ac;

    // Index of first command in av
    int cmd_start_index = 0;

    // Duplicate the standard input file descriptor
    int tmp_fd = dup(STDIN_FILENO);
    // If there was an error, return error message
    if (tmp_fd == -1)
        return FATAL;
    
    // File descriptor array for piped commands
    int pipe_fds[2];

    // While there are commands to execute
    while(av[cmd_start_index] && av[cmd_start_index + 1]){
        // Shift av to first command
        av = av + cmd_start_index + 1;

        // Count number of arguments in current command
        int cmd_size = count_args(av);

        // If the command is "cd" then handle the "cd command
        if (strcmp(av[0], "cd") == EQUAL){
            handle_cd(av[1], cmd_size);
        }
        // If the command is not empty and is followed by a semicolon or end of line then execute i
        else if (cmd_size != 0 && (av[cmd_size] == NULL || strcmp(av[cmd_size], ";") == EQUAL)){
            if (execute_command(av, cmd_size, &tmp_fd, env) != EXIT_SUCCESS)
                return EXIT_FAILURE;
        }
        // If the command is not empty and is followed by a pipe then execute the piped commands
        else if (cmd_size != 0 && strcmp(av[cmd_size], "|") == EQUAL){
            if (execute_piped_commands(av, cmd_size, &tmp_fd, env, pipe_fds) != EXIT_SUCCESS)
                return EXIT_FAILURE;
        }
        
        // Find index of next command
        cmd_start_index = cmd_size;
        
    }
    
    return EXIT_SUCCESS;
}
