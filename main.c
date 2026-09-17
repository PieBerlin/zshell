/* main.c */
#include "my_shell.h"

// shell loop
// input parsing
// command execution 
// Built in commands : cd , pwd , echo ,env, setenv , unsetenv , which , exit 
//execute external command
// manage evn variables 
// manage path 
// error handling

// cd , pwd , echo, env, setenv , unsetenv , which , exit 
// Binary : ls
int shell_builts(char** args,char** env ,char* initial_dir){
    if(my_strcmp(args[0],"cd") == 0){
        return command_cd(args,initial_dir);

    }else if (my_strcmp(args[0],"pwd") == 0){
        command_pwd();

    }else if (my_strcmp(args[0],"echo") == 0){
       return command_echo(args,env);

    }else if (my_strcmp(args[0],"env") == 0){
        command_env(env);

    }else if (my_strcmp(args[0],"which") == 0){
        // command_which(args[0],env);

    }else if (my_strcmp(args[0],"exit") == 0 || my_strcmp(args[0],"quit") == 0){
        printf("Exiting the shell... \n");
        exit(EXIT_SUCCESS);

    }else{
        // Not a built in command 
        // executor();
    }

    return 0 ;

        
}
void shell_loop(char **env){
    char* input = NULL;
    size_t input_size = 0;
    char** args;
    char* initial_dir = getcwd(NULL,0);

    while(1){
        printf("[my_shell]> ");
        if(getline(&input,&input_size,stdin) == -1) // EOF , Ctrl + D
        {
            perror("getline");
            break;

        }
        // printf("Input: %s\n",input);
        args = parse_input(input);


        /*for(size_t i =0;args[i];i++){
            printf("Args: %s\n",args[i]);
            printf("\n");
        }*/

        if (args[0]){
            shell_builts(args,env,initial_dir);
        }
    }

    // free_tokens(args);

}

int main(int argc,char **argv,char **env){
    (void)argc;
    (void)argv;

    shell_loop(env);
    return 0;

}
