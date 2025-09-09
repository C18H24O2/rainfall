#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int language = 0;

void greetuser(char* user) {
    char str[64] = {0};
    
    if (language == 1) {
        strcpy(str, "Hyvää päivää ");
    }
    else if (language == 2) {
        strcpy(str, "Goedemiddag! ");
    }
    else {
        strcpy(str, "Hello ");
    }
    
    strcat(str, user);
    puts(str);
}

int main(int argc, char* argv[]) {
    char user[40] = {0};
    char pass[32] = {0};
    char* lang_env;
    
	if (argc == 3) {
		strncpy(user, argv[1], 40);
		strncpy(pass, argv[2], 32);
		
		lang_env = getenv("LANG");
		if (lang_env != NULL) {
			if (memcmp(lang_env, "fi", 2) == 0) {
				language = 1;
			}
			else if (memcmp(lang_env, "nl", 2) == 0) {
				language = 2;
			}
		}
		
		greetuser(user);
		return 0;
	} else {
		return 1;
	}
}
