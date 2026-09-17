#include "my_shell.h"

// Builtins function implementations
//
//
// cd , cd [path], cd - (previous dir),cd ..,cd ~ (home directory), handle non existing dir 
int command_cd(char** args,char* initial_dir){
   if(args[1] == NULL){
       printf("cd: expected argument\"cd [dir]\"\n");
   } else if(chdir(args[1]) == 0){
       // printf("CD worked!\n");
   }else{
       perror("Cd");
   }
   return 0;
}
int command_pwd(){
    char *cwd = NULL;

    // for dynamic allocation
    cwd = getcwd(NULL,0);
    if(cwd != NULL){
        printf("%s\n",cwd);
        free(cwd);
    }else{
        perror("getcwd");
    }
    return 0;
}

// echo hello world, echo -n Hello , echo $PATH,
int command_echo(char** args,char** env){
    int new_line =1; // default echo ends with newline 
    int i = 1;  // for skipping the -n
    
    if(args[1] != NULL && my_strcmp(args[1],"-n") == 0){
        new_line = 0;
        i++;
    }
    // processing remaining args
    for (;args[i];i++){
        if(args[i][0]== '$'){
            // handle env variables
            char* value = my_getenv(args[i]+1,env);
            if(value){
                printf("%s",value);
            }else{
                printf(" ");// print nothing 
            }

        }else{
            printf("%s",args[i]);
        }
        if(args[i+1] != NULL){
            new_line = 0;
            printf(" ");
        }
        if(new_line){
            printf("\n");
        }
        new_line = 1;
        
    }
   

    return 0;

}
int command_env(char** env){
    size_t index = 0;
    while(env[index]){
        printf("%s\n",env[index]);
        index++;
    }
    return 0;

}
int command_which(char**,char**);
