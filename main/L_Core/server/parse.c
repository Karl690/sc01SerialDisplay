#include "parse.h"
#include <string.h>
#include "../devices/display.h"

// TOUCH=xxxx.xx,yyyy.xx,UP/DOWN
void process_touch_command(char* cmd)
{
	char * token = strtok(cmd, ",");
	// loop through the string to extract all other tokens
	int count = 0;
	
	while (token != NULL) {
		printf(" %s\n", token); //printing each token
		switch (count)
		{
		case 0:
			force_touchx = atof(token);
			break;
		case 1:
			force_touchy = atof(token);
			break;
		case 2:
			if (!strcmp(token, "DOWN")) force_touched = true;
			else force_touch = false;
			break;
			
		}
		token = strtok(NULL, ",");
		count++;
	}
	if (count == 3)
	{
		force_touch = true;
	}
}

void parse_command(char* cmd)
{
	if (strstr(cmd, PARSE_TOUCH_COMMAND))
	{
		process_touch_command(cmd + strlen(PARSE_TOUCH_COMMAND) + 1);
	}
}