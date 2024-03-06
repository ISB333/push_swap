#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define FRAME_WIDTH 200
#define FRAME_HEIGHT 9
#define FRAME_DELAY 220000 // 0.5 seconds


int main() {
    // Define ASCII frames for the animation
    const char frames[][FRAME_HEIGHT][FRAME_WIDTH + 1] = {
        {
            "||       |      |     PPPP   U   U  SSSSS  H   H  SSSSS  W   W  AAAAA  PPPP            ||\n",
            "||       |  4   |     P   P  U   U  S      H   H  S      W W W  A   A  P   P           ||\n",
            "||       |  2   |     PPPP   U   U   SSSS  HHHHH   SSSS  W W W  AAAAA  PPPPP           ||\n",
            "||       |  3   |     P      U   U      S  H   H      S  W W W  A   A  P               ||\n",
            "||       |  1   |     P       UUU   SSSSS  H   H  SSSSS   W W   A   A  P               ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |      PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP           ||\n",
            "||       |  2   |      P   P  U   U  S      H   H  s      W W W  A   A  P   P          ||\n",
            "||       |  4   |      PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP          ||\n",
            "||       |  3   |      P      U   U      S  H   H      s  W W W  A   A  P              ||\n",
            "||       |  1   |      P       UUU   SSSSS  H   H  sssss   W W   A   A  P              ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |       PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP          ||\n",
            "||       |  1   |       P   P  U   U  S      H   H  s      W W W  A   A  P   P         ||\n",
            "||       |  2   |       PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP         ||\n",
            "||       |  4   |       P      U   U      S  H   H      s  W W W  A   A  P             ||\n",
            "||       |  3   |       P       UUU   SSSSS  H   H  sssss   W W   A   A  P             ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |        PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP         ||\n",
            "||       |  3   |        P   P  U   U  S      H   H  s      W W W  A   A  P   P        ||\n",
            "||       |  1   |        PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP        ||\n",
            "||       |  2   |        P      U   U      S  H   H      s  W W W  A   A  P            ||\n",
            "||       |  4   |        P       UUU   SSSSS  H   H  sssss   W W   A   A  P            ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |       PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP          ||\n",
            "||       |  4   |       P   P  U   U  S      H   H  s      W W W  A   A  P   P         ||\n",
            "||       |  3   |       PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP         ||\n",
            "||       |  1   |       P      U   U      S  H   H      s  W W W  A   A  P             ||\n",
            "||       |  2   |       P       UUU   SSSSS  H   H  sssss   W W   A   A  P             ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |      PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP           ||\n",
            "||       |  3   |      P   P  U   U  S      H   H  s      W W W  A   A  P   P          ||\n",
            "||       |  4   |      PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP          ||\n",
            "||       |  1   |      P      U   U      S  H   H      s  W W W  A   A  P              ||\n",
            "||       |  2   |      P       UUU   SSSSS  H   H  sssss   W W   A   A  P              ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |     PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP            ||\n",
            "||       |  4   |     P   P  U   U  S      H   H  s      W W W  A   A  P   P           ||\n",
            "||       |  1   |     PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP           ||\n",
            "||       |  2   |     P      U   U      S  H   H      s  W W W  A   A  P               ||\n",
            "||       |  3   |     P       UUU   SSSSS  H   H  sssss   W W   A   A  P               ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
            "||       |  1   |    P   P  U   U  S      H   H  s      W W W  A   A  P   P            ||\n",
            "||       |  2   |    PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP            ||\n",
            "||       |  3   |    P      U   U      S  H   H      s  W W W  A   A  P                ||\n",
            "||       |  4   |    P       UUU   SSSSS  H   H  sssss   W W   A   A  P                ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
            "||       |  1   |    P   P  U   U  S      H   H  s      W W W  A   A  P   P            ||\n",
            "||       |  2   |    PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP            ||\n",
            "||       |  3   |    P      U   U      S  H   H      s  W W W  A   A  P                ||\n",
            "||       |  4   |    P       UUU   SSSSS  H   H  sssss   W W   A   A  P                ||\n",
            "||       +------+                                                                      ||",
        },
        {
            "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
            "||       |  1   |    P   P  U   U  S      H   H  s      W W W  A   A  P   P            ||\n",
            "||       |  2   |    PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP            ||\n",
            "||       |  3   |    P      U   U      S  H   H      s  W W W  A   A  P                ||\n",
            "||       |  4   |    P       UUU   SSSSS  H   H  sssss   W W   A   A  P                ||\n",
            "||       +------+                                                                      ||",
        },
        // {
        //     "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
        //     "||       |  1   |    P   P  U   U  S      H   H  s      W W W  A   A  P   P            ||\n",
        //     "||       |  2   |    PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP            ||\n",
        //     "||       |  3   |    P      U   U      S  H   H      s  W W W  A   A  P                ||\n",
        //     "||       |  4   |    P       UUU   SSSSS  H   H  sssss   W W   A   A  P                ||\n",
        //     "||       +------+                                                                      ||",
        // },
        {
            "                                                                               \n",
            "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
            "||       |  1   |    P   P  U   U  S      H   H  s      W W W  A   A  P   P            ||\n",
            "||       |  2   |    PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP            ||\n",
            "||       |  3   |    P      U   U      S  H   H      s  W W W  A   A  P                ||\n",
            "||       |  4   |    P       UUU   SSSSS  H   H  sssss   W W   A   A  P                ||\n",
        },
        {
            "                                                                               \n",
            "                                                                               \n",
            "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
            "||       |  1   |    P   P  U   U  S      H   H  s      W W W  A   A  P   P            ||\n",
            "||       |  2   |    PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP            ||\n",
            "||       |  3   |    P      U   U      S  H   H      s  W W W  A   A  P                ||\n",
        },
        {
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
            "||       |  1   |    P   P  U   U  S      H   H  s      W W W  A   A  P   P            ||\n",
            "||       |  2   |    PPPP   U   U   SSSS  HHHHH   ssss  W W W  AAAAA  PPPPP            ||\n",
        },
        {
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
            "||       |  1   |    P   P  U   U  S      H   H  s      W W W  A   A  P   P            ||\n",
        },
        {
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "||       |      |    PPPP   U   U  SSSSS  H   H  sssss  W   W  AAAAA  PPPP             ||\n",
        },
        {
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
            "                                                                               \n",
        },
	};
    // // Determine the number of frames in the animation
    size_t num_frames = sizeof(frames) / sizeof(frames[0]);

    for (size_t i = 0; i < num_frames; i++) {
        // Clear the screen
        write(STDOUT_FILENO, "\033[H\033[J", 6);

        // Print the current frame
        for (size_t j = 0; j < FRAME_HEIGHT; j++) {
            write(STDOUT_FILENO, frames[i][j], strlen(frames[i][j]));
            write(STDOUT_FILENO, "\n", 1); // Move to next line
        }

        // Wait for a short delay before displaying the next frame
        usleep(FRAME_DELAY);
    }

    // Read the number entered by the user
	// char *str = NULL;
    int nbr;
	int series;
	int goal;
	printf("\033[0;33m");
    printf("Choose how many numbers you want to test: ");
    scanf("%d", &nbr);        // printf("You entered: %d\n", nbr);
	printf("\033[0;34m");
    printf("Choose how many series you want to execute: ");
    scanf("%d", &series);        // printf("You entered: %d\n", nbr);
	printf("\033[0;32m");
    printf("Choose how much moves you aim for: ");
    scanf("%d", &goal);        // printf("You entered: %d\n", nbr);
	printf("\033[0;37m");
        // Pass the number as an argument to the shell script
	char command[100];
	sprintf(command, "./push_swap_tester/complexity %d %d %d", nbr, series, goal);
	system(command);

    return 0;
}

