
//checking bangladeshi number 01........
const char* isValidNum(char num[]){

    if(!isDigits(num)){
        return "Enter a valid number.";
    }
    else if(strlen(num)<11){
        return "Number is short";
    }else if(strlen(num)>11){
        return "Number is long";
    }else if(num[0]!= '0'){
        return "Number should Start with 0";
    }else if(num[1]!= '1'){
        return "Number should Start with 01";
    }else {
        return num;
    }


}

//checking a string contains only digits
int isDigits(char num[]){
    for(int i = 0;num[i]!='\0';i++){
        //isdigit is a built in function , ctype.h
        if(!isdigit(num[i])){
            return 0;
        }
    }
    return 1;
}
