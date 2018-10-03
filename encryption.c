#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 100//Tamanho máximo da mensagem
#define TRUE 1
#define FALSE 0


/*
Ler a messagem armazenada no arquivo binário e a armazena na varivel
passada por parâmetro.
*/
void openmessage(char* message, char *file_name)
{
	FILE * arquivo = fopen(file_name, "rb");

	if (arquivo == NULL){
		fprintf(stderr, "Error! Impossível criar arquivo\n");
	}else{
		int n = fread(message, sizeof(char), MAX, arquivo);
			printf("Foram lidos %d dados.\n", n);
	}
}


/*
	Armazena no arquivo binário a message passada por parâmetro.
*/
void savemessage(char* message, char *file_name)
{
	FILE * arquivo = fopen(file_name, "wb");

	if (arquivo == NULL){
		fprintf(stderr, "Error! Impossível criar arquivo\n");
	}else{
		if(fwrite(message, sizeof(char), MAX, arquivo) != MAX)
			fprintf(stderr, "Não foi possivel gravar todos os dados \n");
	}

}

/*
  Recebe como parâmetro a message que deseja aplicar o códido de 
  Augustus. Retorna a message criptografada.
*/
void encryption(char *message, char *encrypted_message)
{

	for(int i = 0; i< strlen(message); i++, encrypted_message[i] = '\0'){
		switch(message[i])
		{
			case ' ': encrypted_message[i] = ' '; break;
			case 'a': encrypted_message[i] = 'b'; break;
			case 'A': encrypted_message[i] = 'B'; break;
			case 'b': encrypted_message[i] = 'c'; break;
			case 'B': encrypted_message[i] = 'C'; break;
			case 'c': encrypted_message[i] = 'd'; break;
			case 'C': encrypted_message[i] = 'D'; break;
			case 'd': encrypted_message[i] = 'e'; break;
			case 'D': encrypted_message[i] = 'E'; break;
			case 'e': encrypted_message[i] = 'f'; break;
			case 'E': encrypted_message[i] = 'F'; break;
			case 'f': encrypted_message[i] = 'g'; break;
			case 'F': encrypted_message[i] = 'G'; break;
			case 'g': encrypted_message[i] = 'h'; break;
			case 'G': encrypted_message[i] = 'H'; break;
			case 'h': encrypted_message[i] = 'i'; break;
			case 'H': encrypted_message[i] = 'I'; break;
			case 'i': encrypted_message[i] = 'j'; break;
			case 'I': encrypted_message[i] = 'J'; break;
			case 'j': encrypted_message[i] = 'k'; break;
			case 'J': encrypted_message[i] = 'K'; break;
			case 'k': encrypted_message[i] = 'l'; break;
			case 'K': encrypted_message[i] = 'L'; break;
			case 'l': encrypted_message[i] = 'm'; break;
			case 'L': encrypted_message[i] = 'M'; break;
			case 'm': encrypted_message[i] = 'n'; break;
			case 'M': encrypted_message[i] = 'N'; break;
			case 'n': encrypted_message[i] = 'o'; break;
			case 'N': encrypted_message[i] = 'O'; break;
			case 'o': encrypted_message[i] = 'p'; break;
			case 'O': encrypted_message[i] = 'P'; break;
			case 'p': encrypted_message[i] = 'q'; break;
			case 'P': encrypted_message[i] = 'Q'; break;
			case 'q': encrypted_message[i] = 'r'; break;
			case 'Q': encrypted_message[i] = 'R'; break;
			case 'r': encrypted_message[i] = 's'; break;
			case 'R': encrypted_message[i] = 'S'; break;
			case 's': encrypted_message[i] = 't'; break;
			case 'S': encrypted_message[i] = 'T'; break; 
			case 't': encrypted_message[i] = 'u'; break;
			case 'T': encrypted_message[i] = 'U'; break;
			case 'u': encrypted_message[i] = 'v'; break;
			case 'U': encrypted_message[i] = 'V'; break;
			case 'v': encrypted_message[i] = 'w'; break;
			case 'V': encrypted_message[i] = 'W'; break;
			case 'w': encrypted_message[i] = 'x'; break;
			case 'W': encrypted_message[i] = 'X'; break;
			case 'x': encrypted_message[i] = 'y'; break;
			case 'X': encrypted_message[i] = 'Y'; break;
			case 'y': encrypted_message[i] = 'z'; break;
			case 'Y': encrypted_message[i] = 'Z'; break;
			case 'z': encrypted_message[i] = 'a'; break;
			case 'Z': encrypted_message[i] = 'A'; break;
			default:  break;
		}
	}
}



int main(int argc, const char* argv[], const char * envp[])
{
	char input_message[MAX];
	char output_message[MAX];
	char aux;
	pid_t child_pid;

    while(TRUE){
    	printf("%d\n", (int) getpid());

		printf("Digite a mensagem que deseja criptografar (Por favor, sem acentos): exit()- para sair\n");
		fgets(input_message, MAX, stdin);
		if(strcmp(input_message, "exit()\n")==0)
			break;
		printf("Criptografando...%s\n",input_message);
		
		encryption(input_message, output_message);
		printf("%s\n", output_message);
	}
	return 0;

}