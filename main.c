#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * x)
#else
#include <unistd.h>
#endif

char repo[256] = "";

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void grub_screen() {
    printf("Welcome to GRUB!\n");
    sleep(2);
    clear();
    printf("eps:>\n");
}

void boot_logo() {
    clear();
    printf("███████╗██████╗ ███████╗\n");
    printf("██╔════╝██╔══██╗██╔════╝\n");
    printf("█████╗  ██████╔╝█████╗  \n");
    printf("██╔══╝  ██╔═══╝ ██╔══╝  \n");
    printf("███████╗██║     ███████╗\n");
    printf("Einux Booting...\n");

    sleep(5);
    clear();
}

void install_package(char *pkg) {
    if (strlen(repo) == 0) {
        printf("No repo set!\n");
        return;
    }

    char cmd[512];

    printf("Downloading %s from %s...\n", pkg, repo);

#ifdef _WIN32
    sprintf(cmd, "curl -o %s.eps %s/%s.eps", pkg, repo, pkg);
#else
    sprintf(cmd, "wget %s/%s.eps -O %s.eps", repo, pkg, pkg);
#endif
    system(cmd);

    printf("Extracting...\n");
    sprintf(cmd, "tar -xf %s.eps", pkg);
    system(cmd);

    printf("Compiling...\n");
#ifdef _WIN32
    sprintf(cmd, "gcc %s.c -o %s.exe", pkg, pkg);
#else
    sprintf(cmd, "gcc %s.c -o %s", pkg, pkg);
#endif
    system(cmd);

    printf("Running...\n");
#ifdef _WIN32
    sprintf(cmd, "%s.exe", pkg);
#else
    sprintf(cmd, "./%s", pkg);
#endif
    system(cmd);
}

void shell() {
    char input[256];

    while (1) {
        printf("eps@localhost> ");
        fgets(input, sizeof(input), stdin);

        // 개행 제거
        input[strcspn(input, "\n")] = 0;

        if (strncmp(input, "repo-", 5) == 0) {
            strcpy(repo, input + 5);
            printf("Repo set to: %s\n", repo);
        }

        else if (strncmp(input, "repo install-", 13) == 0) {
            char pkg[100];
            sscanf(input + 13, "%s", pkg);
            install_package(pkg);
        }

        else if (strcmp(input, "clear") == 0) {
            clear();
        }

        else if (strcmp(input, "exit") == 0) {
            break;
        }

        else {
            printf("Unknown command\n");
        }
    }
}

int main() {
    grub_screen();

    char cmd[256];

    while (1) {
        fgets(cmd, sizeof(cmd), stdin);

        cmd[strcspn(cmd, "\n")] = 0;

        if (strcmp(cmd, "select EPI-4090b") == 0) {
            printf("EPI 4090 address has been selected.\n");
        }

        else if (strcmp(cmd, "boot to 4090") == 0) {
            boot_logo();
            shell();
            break;
        }

        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
