void abertura();
void chuta();
void desenhaforca();
void escolhepalavra();
int enforcou();
int acertou();
int jachutou(int letras);
void adicionarpalavra();
int chuteserrados();

#define TAMANHO_PALAVRA 20

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void abertura() {
	printf("\n\n***********************\n");
	printf("*    Jogo de Forca    *\n");
	printf("***********************\n\n");
}

void chuta() {
	char chute;
	printf("Chute uma letra: ");
	scanf(" %c", &chute);

	chutes[chutesdados] = chute;
	chutesdados++;
}

void desenhaforca() {

	int erros = chuteserrados();

    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' ' ), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

	for(int i = 0; i < strlen(palavrasecreta); i++) {
					
		int achou = jachutou(palavrasecreta[i]);

		if(achou) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}
	}
}

void adicionarpalavra() {
	char quer;
	printf("Voce deseja adcionar uma nova palavra no jogo? (S/N) ");
	scanf(" %c", &quer);

	if(quer == 'S') {
		char novapalavra[TAMANHO_PALAVRA];
		printf("Qual a nova palavra? ");
		scanf("%s", novapalavra);

		FILE* f;

		f = fopen("palavras.txt", "r+");
		if(f == 0){
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1);
		}
		
		int qntd;
		fscanf(f, "%d", &qntd);
		qntd++;

		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qntd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);

		fclose(f);
	}
}

void escolhepalavra() {
	FILE* f;

	f = fopen("palavras.txt", "r");
	if(f == 0){
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1);
	}

	int qntddepalavras;
	fscanf(f, "%d", &qntddepalavras);

	srand(time(0));
	int randomico = rand() % qntddepalavras;

	for(int i = 0; i <= randomico; i++) {
		fscanf(f, "%s", &palavrasecreta);
	}
	fclose(f);
}

int acertou() {
	for(int i = 0; i < strlen(palavrasecreta); i++) {
		if(!jachutou(palavrasecreta[i])) {
			return 0;
		}
	}
	return 1;
}

int chuteserrados() {
	int erros = 0;

	for(int i = 0; i < chutesdados; i++) {
		for(int j = 0; j < strlen(palavrasecreta); j++) {
			if(jachutou(palavrasecreta[i])) {
				break;
			}
		}
		if(!jachutou(palavrasecreta[i])) erros++;
	}
	return erros;
}

int enforcou() {

	return chuteserrados() >= 5;
}

int jachutou(int letras) {
	int achou = 0;

	for(int j = 0; j < chutesdados; j++) {
		if(chutes[j] == letras) {
			achou = 1;
			break;
		}
	}
	return achou;
}