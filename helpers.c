#include "my_shell.h"
// 0: the strings are equal
// < 0 str < str2 
// > 0 str > str2 
int my_strcmp(const char* str1,const char* str2){
    if (str1 == NULL || str2 == NULL) return 1;
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return (*(unsigned char*)str1 - *(unsigned char*)str2);
}

int my_strlen(const char* str){
    if (str == NULL) return -1;
    size_t len  =0;
    while(*str){
        len++;
        str++;
    }
    return len;
}
// 0 if str1 == str2 in the first n characters
// < 0 if str1 < str2 in the first n characters
// > 0 if str1 > str2 in the first n characters

int my_strncmp(const char* str1,const char *str2, size_t n){
    if (str1 == NULL || str2 == NULL) return 1;
    size_t i =0;
    while(1 < n && str1[i] && str2[i]){
        if (str1[i] != str2[i]){
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
        i++;
    }
    if (i == n)return 0;
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}
// function to Get environment variables 
char* my_getenv(const char *name,char** env){
    if(name == NULL || env ==NULL){
        return NULL;
    }
    size_t name_len = my_strlen(name);

    for (size_t i = 0;env[i];i++){
        // check if the curr env starts with 'name='
        if (my_strncmp(env[i],name,name_len) == 0 && env[i][name_len] == '='){
            return &env[i][name_len+1];
        }

    }
    return NULL;

}

char* my_strcpy(char* dst,const char* src){
    if (src == NULL) return NULL;
    char* ret  = dst;
    while(*src){
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return ret;
}


char* my_strdup(const char* str){
    if (!str) return NULL;
    size_t len = my_strlen(str);

    char* duplicated = (char*)malloc((len+1) * sizeof(char));

    if (!duplicated) return NULL;

    my_strcpy(duplicated,str);

    return duplicated;

}

char* my_strchr(const char* str,char c){
    while(*str){
        if(*str == c){
            return (char*)str;
        }
        str++;
    }
    return NULL;
}


char* my_strtok(char* input_string,const char* del){
    static char* next_token = NULL;
    // If input string  is NULL 
    if (!input_string){
        input_string = next_token;
    }
    if (!input_string){
        return NULL;
    }
    while(*input_string && my_strchr(del ,*input_string)){
        input_string ++;
    }
    if (*input_string == '\0'){
        next_token = NULL;
        return NULL;
    }

    char* token = input_string;

    while(*input_string && !my_strchr(del,*input_string)){
        input_string++;
    }
    if (*input_string){
        *input_string = '\0';
        next_token = input_string+1;
    }else{
        next_token = NULL;
    }

    return token;


}
