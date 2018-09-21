#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("usage: %s [file to open]\n", argv[0]);
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Couldn't open %s\n", argv[1]);
        return 1;
    }
    
    struct termios current_settings, hacker_settings;
    // save current settings
    tcgetattr(0, &current_settings);
    hacker_settings = current_settings;
    hacker_settings.c_lflag &= ~(ECHO | ICANON);
    hacker_settings.c_cc[VTIME] = 0;
    hacker_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &hacker_settings);
    
    // update hacker settings
    tcsetattr(0, TCSANOW, &hacker_settings);
    
    for (int c = fgetc(file); c != EOF; c = fgetc(file))
    {
        //pull a keystroke from stdin and throw it away
        fgetc(stdin);
        
        //print the next char from file to stdout
        //could also use printf("%c", c ) or putc(c, stdout)
        putchar(c);
    }
    
    fclose(file);
    
    // revert to current settings
    tcsetattr(0, TCSANOW, &current_settings);
    
    
}
