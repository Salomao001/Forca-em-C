#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

int main() {	

	escolhepalavra();

	abertura();

	do {

		desenhaforca();

		printf("\n");

		chuta();

		} while (!acertou() && !enforcou());

	if(acertou()) {
		printf("\nParabens, voce ganhou!\n\n");

		printf(
		"              .-=========-.					\n"
		"              \\'-=======-'/			\n"
		"              _|   .=.   |_			\n"
		"             ((|  {{1}}  |))			\n"
		"              \\|   /|\\   |/			\n"
		"               \\__ '`' __/			\n"
		"                 _`) (`_				\n"
		"               _/_______\\_			\n"
		"              /___________\\		\n\n");
	}
	else {
		printf("\nPuxa, voce foi enforcado!\n");
		printf("A palavra era **%s**\n\n", palavrasecreta);

		printf(
		"           ______						\n"
		"        .-'      '-.				\n"
		"       /            \\				\n"
		"      |              |				\n"
		"      |,  .-.  .-.  ,|				\n"
		"      | )(__/  \\__)( |			\n"
		"      |/     /\\     \\|			\n"
		"      (_     ^^     _)				\n"
		"       \\__|IIIIII|__/				\n"
		"        | \\IIIIII/ |				\n"
		"        \\          /				\n"
		"         `--------`			\n\n");
	}
	adicionarpalavra();
}