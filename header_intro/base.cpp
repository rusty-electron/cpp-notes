int countchar(char c, const char* str_arg){
    int i = 0, count = 0;
    while (str_arg[i]!='\0'){
        if(str_arg[i] == c){
            count++;
        }
        i++;
    }
    return count;
}