typedef struct
{
	char nome[50];
	char numero[12]; // 84912345678 + '\0'
} Contato;

typedef struct
{
	Contato *dados;
	int tamanho;
} ListaContatos;

ListaContatos *criarLista();

void adicionarContato(ListaContatos *lista, char nome[], char numero[]);
void removerContato(ListaContatos *lista, char nome[]);
int buscarContato(ListaContatos *lista, char nome[]);
void contatoExiste(ListaContatos *lista, char nome[]);
void listarContatos(ListaContatos *lista);
void atualizarContato(ListaContatos *lista, char nome[], char novoNumero[]);
void totalContatos(ListaContatos *lista);
void destruirLista(ListaContatos *lista);