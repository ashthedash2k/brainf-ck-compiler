/*SIMPLE compiler to translate brainfck*/
#include <stdio.h>
#define SIZE 1001
void brainfck(char *command_ptr, char *val) {
  int flag;
  char command = *command_ptr;
  char info[SIZE] = {0};
  char *ptr;  
  ptr = &info[SIZE/2]; 

  while ((command = *command_ptr++)){

    if (command == '<'){
        ptr--;
    }
    else if (command == '>'){
        ptr++;
    }
    else if (command == '+'){
        (*ptr)++;
    }
    else if (command == '-'){
        (*ptr)--;
    }
    else if (command == '.'){
        printf("%c", *ptr);
    }
    else if (command == ','){
        *ptr = *val ++;

    }
    else if (command == '['){
        if (!*ptr){
            flag = 1;
            while (flag) {
                if (*command_ptr == '['){
                    flag++;
                }
                else if (*command_ptr == ']'){
                    flag--;
                } 
                command_ptr++;
            }
        }
    }
    else if (command == ']'){
        if (*ptr){
            command_ptr -= 2;
            flag = 1;
            while(flag){
                if (*command_ptr == ']'){
                    flag++;
                }
                else if (*command_ptr == '['){
                    flag--;
                }
                command_ptr--;
            }
            command_ptr++; 
        }
    }
  }
  
}

int main() {
  char *message = "+[----->+++<]>+.---.+++++++..+++.------------------.";
  char *val = "";
  brainfck(message, val);
  return 0;
}
