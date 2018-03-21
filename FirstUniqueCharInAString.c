#define NO_OF_CHARS 256


int* get_char_count(char* str){
    int *count = (int*)calloc(sizeof(int), NO_OF_CHARS);
    for(int i =0; *(str+i); i++){
        count[*(str+i)]++;
    }
    return count;
}

int first_non_repeat_char(char* str){
    int *count = get_char_count(str);
    int index = -1, i;
    for(i=0; *(str+i);i++){
        if(count[*(str+i)] == 1){
            index = i;
            break;
        }
    }
    free(count);
    return index;
}
int firstUniqChar(char* s) {
    return(first_non_repeat_char(s));
}
