#ifdef _WIN32
  #define PLATFORM_NAME "Windows"
#else
  #define PLATFORM_NAME "Linux"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
// local headers
#include "notes_builder.h"
#include "helpers.h"

/* Prints the musical scale */
void print_musical_scale(char *scale_t);

/* Prints the musical scale of the harmonic circle*/
void print_relative_note_harmonic_circle(ScalePatternType scale_pattern, char **harmonic_circle);

void clean_screen();

int main(void) {
	clean_screen();

	int option;
	char restart = 'y';

	while (restart != 'n') {
		printf("*************************************\n");
		printf("╔╦╗╦ ╦╔═╗╦╔═╗╔═╗╦    ╔═╗╔═╗╔═╗╦  ╔═╗ \n");
		printf("║║║║ ║╚═╗║║  ╠═╣║    ╚═╗║  ╠═╣║  ║╣  \n");
		printf("╩ ╩╚═╝╚═╝╩╚═╝╩ ╩╩═╝  ╚═╝╚═╝╩ ╩╩═╝╚═╝ \n");
		printf("   ╔═╗╔═╗╔╗╔╔═╗╦ ╦╦ ╔╦╗╔═╗╔╗╔╔╦╗     \n");
		printf("   ║  ║ ║║║║╚═╗║ ║║  ║ ╠═╣║║║ ║      \n");
		printf("   ╚═╝╚═╝╝╚╝╚═╝╚═╝╩═╝╩ ╩ ╩╝╚╝ ╩      \n");
		printf("*************************************\n");
		printf("[1] Major Scales\n");
		printf("[2] Minor Scales\n");
		printf("[3] Major Chords\n");
		printf("[4] Minor Chords\n");
		printf("[5] Harmonic Circles\n");
		printf("[0] Exit\n");
		printf("-------------------------------------\n");
		printf("[>]: ");
		scanf("%d", &option);
		printf("-------------------------------------\n");

		if (option == 0) {
			clean_screen();
			break;
		}

		switch (option) {
			case 1:
				print_musical_scale(scale_type.MAJOR_SCALE);
				break;
			case 2:
				print_musical_scale(scale_type.MINOR_SCALE);
				break;
			case 3:
				print_musical_scale(scale_type.MAJOR_CHORDS);
				break;
			case 4:
				print_musical_scale(scale_type.MINOR_CHORDS);
				break;
			case 5:
				print_musical_scale(scale_type.HARMONIC_CIRCLE);
				break;
			default:
				printf("[-] Invalid option selected.\n");
				break;
		}

		printf("\nRestart Menu (y/n): ");
		scanf(" %c", &restart);
		restart = tolower(restart);

		clean_screen();
  	}
  	return 0;
}

void print_musical_scale(char *scale_t) {
  
    char ***note_scales = build_scales(scale_t);
    ScalePatternType scale_pattern = get_scale_pattern(scale_t);

    if (note_scales == NULL) {
		printf("[!] Failed to create musical scale note.");
		return;
    }

    for (int index = 0; index < chromatic_scale_size; index++) {
		char **scale = note_scales[index];

		if (strcmp(scale_t, scale_type.MINOR_SCALE) == 0 || strcmp(scale_t, scale_type.MINOR_CHORDS) == 0) {
			printf("[%sm]: ", chromatic_scale[index]);
		} else {
			printf("[%s]: ", chromatic_scale[index]);
		}

		for (int ns_index = 0; ns_index < scale_pattern.size; ns_index++) {
			printf("%s ", scale[ns_index]);
		}

		// Relative scale (harmonic circle)
		if (strcmp(scale_t, scale_type.HARMONIC_CIRCLE) == 0) {
			print_relative_note_harmonic_circle(scale_pattern, scale);
		}

		printf("\n");
    }

    free(note_scales);
    note_scales = NULL;
}

/* Prints the musical scale of the harmonic circle */
void print_relative_note_harmonic_circle(ScalePatternType scale_pattern, char **harmonic_circle) {
    char **relative = create_relative_harmonic_circle(harmonic_circle);

    if (relative == NULL) {
        printf("[!] Failed to create relative harmonic scale");
        return;
    }

    printf("\n[R]: ");
    for (int ns_index = 0; ns_index < scale_pattern.size; ns_index++) {
        printf("%s ", relative[ns_index]);
    } 
    printf("\n");

}

void clean_screen() {
    PLATFORM_NAME == "Windows" ? system("cls") : system("clear");
}
