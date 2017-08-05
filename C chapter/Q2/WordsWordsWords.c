#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_SIZE 10000
#define MAX_WORD_SIZE 256

char* get_word(char* str1, FILE* dict); //find another word in the vocabulary
char* convert_text_by_dict(char* txt, FILE* dict);

void main(int argc, char** argv){

	FILE* dict;
	FILE* target;

	// read the text from the text file
	int c;
	char txt_buff[MAX_TEXT_SIZE];
	target = fopen(argv[1], "r");
	for (int i = 0; i < MAX_TEXT_SIZE; i++){
		c = getc(target);
		if (c == EOF){
			break;
		}
		txt_buff[i] = c;
		txt_buff[i + 1] = 0;
	}
	fclose(target);

	char new_txt[MAX_TEXT_SIZE];
	dict = fopen(argv[2], "r");
	if (dict){
		strcpy(new_txt, convert_text_by_dict(txt_buff, dict));
		fclose(dict);
	}

	target = fopen(argv[1], "w");
	if (target){
		fputs(new_txt, target);
		fclose(target);
	}
}

char* get_word(char* str1, FILE* dict){
	int c;
	char buff[MAX_WORD_SIZE];
	int buff_cnt = 0;

	while (((c = getc(dict))) != EOF){
		if (c == ':'){
			buff[buff_cnt] = 0;
			buff_cnt = 0;
			if (strcmp(str1, buff) == 0){ //match has found
				c = getc(dict); // get the word after the ':'
				while (c != ':'){
					buff[buff_cnt] = c;
					buff_cnt++;
					c = getc(dict);
				}
				buff[buff_cnt] = 0;
				return buff;
			}
			while (c != '\n' && c != EOF){ //read till the end of line because the word isn't relevant
				c = getc(dict);
			}
			c = getc(dict);
		}
		buff[buff_cnt] = c;
		buff_cnt++;
	}
	return "\0"; // if word's not found return ""
}

char* convert_text_by_dict(char* txt, FILE* dict){
	char new_str[MAX_TEXT_SIZE] = "\0";

	char curr_word[MAX_WORD_SIZE];
	char tmp_word[MAX_WORD_SIZE];

	int curr_cnt = 0;
	int end_of_str_flag = 0;

	for (int i = 0; !end_of_str_flag; i++){
		if (txt[i] == ' ' || txt[i] == '\n' || txt[i] == '\0'){
			fseek(dict, 0, SEEK_SET); // point to the start of the file
			strcpy(tmp_word, get_word(curr_word, dict));
			if (strcmp(tmp_word, "") == 0){
				strcat(new_str, curr_word);
			}
			else{
				strcat(new_str, tmp_word);
			}
			if (txt[i] == ' '){
				strcat(new_str, " ");
				curr_cnt = 0;
			}
			if (txt[i] == '\n'){
				strcat(new_str, "\n");
			}
			if (txt[i] == '\0'){
				end_of_str_flag = 1;
			}
			curr_cnt = 0;
		}
		else{
			curr_word[curr_cnt] = txt[i];
			curr_word[curr_cnt + 1] = 0;

			curr_cnt++;
		}
	}

	return new_str;

}