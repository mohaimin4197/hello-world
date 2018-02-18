#include <stdio.h>
#include <stdint.h>
#include <string.h>

void spellCheck(char article[], char dictionary[]);
int checkDictionary(char word[],char dictionary[]);
int validWord(char word[]);


int main() {
    char dictionary[] = "Beagle\nBulldog\nCollie\nPoodle\nretriever\n";
    char article[] = "";//"bulldog dalmation beagle Retriever poodles";

    //char dictionary[] = "apple\nbanana\norange\npear\n";
    //char article[] = "I ate an apple and a pear\n";

    //char dictionary[] = "but\ncan\ncan't\ndo\ndon't\nthink\n"; // the dictionary can contain punctuation
    //char article[] = "I think I can, but I can't. I think I do, but I don't";

    spellCheck(article,dictionary);

}

void spellCheck(char article[], char dictionary[]) {
    int charCount = 0;
    /*static */char word[30];
    int i = 0;
    while (article[charCount] != '\0'){
          i = 0;
         char temp = article[charCount];
       // while ((temp != ' ') && (temp != '.') && (temp != '?') && (temp != ':') && (temp != ';') && (temp!=0x0A) && (temp!='\0') && (temp!=',')) {
         while (1){
            //printf("%c\n",temp);
             if (((temp>=0x41) && (temp<=0x5A)) || ((temp>=0x61) && (temp<=0x7A)))
             {

                 word[i] = article[charCount];
                 //printf("%s\n",word);
                 i++;
             }

             charCount++;
             temp = article[charCount];
             if (!(((temp>='A') && (temp<='Z')) || ((temp>='a') && (temp<='z')))){
                 //printf("%c\n",temp);
                 break;
             }

        }
        word[i] = '\0';

        //printf("%s\n",word);
        if (article[charCount] != '\0') {
            charCount++;
        }

        //printf("getword:%s\n", word);
        //return word;
        int isValid = validWord(word);
        if (isValid == 0) {
            checkDictionary(word, dictionary);


        }

    }
}

int checkDictionary(char word[],char dictionary[]) {
    //char *word1 = word;
    //printf("%s\n",word);
    char dictWord[30];
    int k = 0;
    int letterCount = 0;
    int check = 1;
    while (check != 0) {
        if (dictionary[0] == '\0'){
            break;
        }
        while (dictionary[letterCount] != '\n') {
            dictWord[k] = dictionary[letterCount];
            letterCount++;
            k++;
            //printf("k: %d letterCount: %d\n",k,letterCount);
        }
        dictWord[k] = 0;
        //printf("%c\n",dictionary[letterCount]);
        letterCount++;
        if (dictionary[letterCount] == '\0'){
            break;
        }

        k = 0;
        check = strcasecmp(word, dictWord) ;
        //printf("%d\n",check);
        //printf("s\n",dictWord);
    }
    check = strcasecmp(word, dictWord) ;
    if (check == 0){
        //printf("word found\n");
        return 0;
    }else {
        //printf("word not found\n");
        printf("%s\n", word);
        return 1;
    }
    //printf("%s\n",dictWord);
}

int validWord(char word[]){

    int letterCount = 0;
    int flag = 0;
    while (word[letterCount] != '\0'){
    //    if (word[letterCount] == '\''){
    //        flag = 1;
    //    }
        letterCount++;
    }
    if (letterCount<2){
        flag = 1;
    }
    // printf("%d\n",flag);
    return flag;
}

