# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>

# define punkShBufferSize 1024
# define punkShTokenSize 64
# define punkShTokenDelim "\t\r\n\a"

int punkShCd(char **args);
// int punkShHelp(char **args);
int punkShExit(char **args);

char *builtinString[] = {
    "cd",
    //"help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &punkShCd,
    //&punkShHelp,
    &punkShExit
};

int punkShNumBuiltins() {
    return sizeof(builtinString) / sizeof(char *);
}

int punkShCd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "punksh: command flatlined, expected argument to \"cd\"\n");
    } 
    else {
        if (chdir(args[1]) != 0) {
            perror("punksh");
        }
    }
    return 1;
}

int punkShExit(char **args) {
    return 0;
}

int punkShLaunch(char **args) {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("punksh");
        }
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0) {
    // Error forking
        perror("punksh");
    } 
    else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } 
        while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

int punkShExec(char **args) {
    int i;
    if (args[0] == NULL) {
    // An empty command was entered.
        return 1;
    }
    for (i = 0; i < punkShNumBuiltins(); i++) {
        if (strcmp(args[0], builtinString[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }
    return punkShLaunch(args);
}

char *punkShReadLine(void) {
    int bufferSize = punkShBufferSize;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufferSize);
    int c;
    if (!buffer) {
        fprintf(stderr, "punksh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    while (1) {
    // Read a character
    c = getchar();
        // If we hit EOF, replace it with a null character and return.
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;
        // If we have exceeded the buffer, reallocate.
        if (position >= bufferSize) {
            bufferSize += punkShBufferSize;
            buffer = realloc(buffer, bufferSize);
            if (!buffer) {
                fprintf(stderr, "punksh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **punkShSplitLine(char *line) {
    int bufferSize = punkShBufferSize, position = 0;
    char **tokens = malloc(bufferSize * sizeof(char*));
    char *token;
    if (!tokens) {
        fprintf(stderr, "punksh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, punkShTokenDelim);
    while (token != NULL) {
        tokens[position] = token;
        position++;
        if (position >= bufferSize) {
            bufferSize += punkShTokenSize;
            tokens = realloc(tokens, bufferSize * sizeof(char*));
            if (!tokens) {
            fprintf(stderr, "punksh: allocation error\n");
            exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, punkShTokenDelim);
    }
    tokens[position] = NULL;
    return tokens;
}

void punkShell(void) {
    char *line;
    char **args;
    int status;
    do {
        printf("€$ ");
        line = punkShReadLine();
        args = punkShSplitLine(line);
        status = punkShExec(args);
        free(line);
        free(args);
    } 
    while (status);
}

int main(int argc, char **argv) {
    printf("Bout time you chromed tf up.\n");
    punkShell();
    return EXIT_SUCCESS;
}

